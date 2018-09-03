#include "partobject.h"
#include <QFile>
#include <QRegExp>
#include <QtDebug>
#include <QTextStream>

PartObject::PartObject(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<PartObject>("PartObject");
    this->setParent(parent);
}

PartObject::PartObject(const PartObject &otherPart)
{
    this->setParent(otherPart.parent());
    m_blockCount = otherPart.blockCount();
    m_layerCount = otherPart.layerCount();
    m_layerFlags = otherPart.layerFlags();
    m_blocks = otherPart.blocks();
    m_partFilePath = otherPart.partFilePath();
    m_partStatus = otherPart.partStatus();


}


PartObject::PartObject(const QString &filePath, SettingsObject *config, QObject *parent){

    this->setParent(parent);

    this->setPartFilePath(filePath);
    this->setPartStatus(PART_IS_EMPTY);
    m_parserStatus = PARSER_INIT;
    QVector<BlockObject*> myblocks;
    QStringList lineList;

    BlockObject::PositionMode prevailPosMode = BlockObject::PositionMode::Position_Absolute;

    QFile partFile(this->partFilePath());
    if(partFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream partFileStream(&partFile);
        while(!partFileStream.atEnd()){
            lineList<< partFileStream.readLine();
        }
        if(partFile.isOpen())
            partFile.close();
    }
    else
    {
        if(partFile.isOpen())
            partFile.close();
        m_parserStatus= PARSER_FAILED_INVALID_PART;
        m_errorStr += "\nCould Not Open File!";
    }

    if(!lineList.isEmpty()){
        uint32_t blockNum = 0;
        uint32_t layerNum = 0;
        QStringList::iterator line_iterator = lineList.begin();

        while(line_iterator != lineList.end()){
            BlockObject *block = new BlockObject();
            block->setParent(this);
            block->setBlockNumber(blockNum);
            block->setLayerNumber(layerNum);
            block->setG_code_line(*line_iterator);
            block->setBlockTask(BlockObject::BlockTask::BLOCK_EMPTY);
            QString g_subLine = *line_iterator;

            g_subLine = g_subLine.simplified();

            if(g_subLine.contains(QRegExp("NEW[-_\\s]?LAYER",Qt::CaseInsensitive))){
                m_layerFlags.append(blockNum);
                layerNum++;
            }

            if(g_subLine.indexOf("(") > 1){
                g_subLine = g_subLine.left(g_subLine.indexOf("("));
                g_subLine.append("Q");
            }
            else if(g_subLine.indexOf("(") == 0){
                g_subLine = g_subLine.right(g_subLine.length() - g_subLine.indexOf(")")-1);
            }
            else if(g_subLine.indexOf(";") >= 0){
                g_subLine = g_subLine.left(g_subLine.indexOf(";"));
                g_subLine.append("Q");
            }
            else if (g_subLine.contains("/"))
            {
                g_subLine.clear();
            }

            if(!g_subLine.isEmpty()){
                const QString regEx_uInt = "{1,1}\\s{0,1}\\d{1,3}";
                const QString regEx_float = "[+-]?\\d{0,8}\\.{0,1}\\d{0,8}";
                g_subLine = g_subLine.replace(QRegExp("\\s+(?=([+-]?\\d))"),"");
                QStringList gData = g_subLine.split(QRegExp("(\\s{1,8})(?=([A-Z]{1,1}))"));
                QStringList::iterator data_iterator = gData.begin();

                while(data_iterator != gData.end()){

                    if(QRegExp("[Gg]"+regEx_uInt).exactMatch(*data_iterator)){
                        (*data_iterator).remove(0,1);
                        const uint8_t val = (*data_iterator).toUInt();

                        if(val == 90){
                            block->setPositionMode(BlockObject::PositionMode::Position_Absolute);
                            if(prevailPosMode != BlockObject::PositionMode::Position_Absolute)
                                block->setBlockTask(BlockObject::BlockTask::SET_POSITION_MODE);
                        }
                        else if(val == 91){
                            block->setPositionMode(BlockObject::PositionMode::Position_Relative);
                            if(prevailPosMode != BlockObject::PositionMode::Position_Relative)
                                block->setBlockTask(BlockObject::BlockTask::SET_POSITION_MODE);
                        }
                        else if(val == 28){
                            block->setBlockTask(BlockObject::BlockTask::SET_HOME_AXIS);
                        }

                    }

                    else if(QRegExp("[Mm]"+regEx_uInt).exactMatch(*data_iterator)){
                        (*data_iterator).remove(0,1);
                        const uint8_t val = (*data_iterator).toUInt();
                        if(val == 3){
                            block->setLaser_enabled(true);
                        }
                        else if (val == 5){
                            block->setLaser_enabled(false);
                        }
                    }

                    else if(QRegExp("[Ss]"+regEx_uInt).exactMatch(*data_iterator)){
                        (*data_iterator).remove(0,1);
                        bool valid;
                        const uint8_t value = (*data_iterator).toUInt(&valid);

                        if(valid && (value < config->laser_power_max()) && (value > config->laser_power_min())){
                            block->setLaser_power(value);
                        }
                        else
                        {
                            m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
                                           + ", Layer: " + QString::number(layerNum,10)
                                           + " Error: Invalid Laser Power!");                            this->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                            block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);
                            m_parserStatus= PARSER_FAILED_INVALID_PART;
                        }

                    }

                    else if(QRegExp("[Pp]"+regEx_float).exactMatch(*data_iterator)){
                        (*data_iterator).remove(0,1);
                        bool valid;
                        const float value = (*data_iterator).toFloat(&valid);
                        if(valid){
                            block->setDwellTime(value);
                        }
                        else
                        {
                            m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
                                           + ", Layer: " + QString::number(layerNum,10)
                                           + " Error: Invalid Dwell Time!");
                            this->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                            block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);
                            m_parserStatus= PARSER_FAILED_INVALID_PART;
                        }
                    }

                    else if(QRegExp("[Ff]"+regEx_float).exactMatch(*data_iterator)){
                        bool axis_active = false;
                        if((block->blockTask()|BlockObject::BlockTask::SET_X_POSITION)
                                ||(block->blockTask()|BlockObject::BlockTask::SET_Y_POSITION)){
                            (*data_iterator).remove(0,1);
                            bool valid;
                            const float value = (*data_iterator).toFloat(&valid);
                            if(valid && (value < config->xy_speed_max()) && (value > config->xy_speed_min())){
                                block->setXY_speed(value);
                                axis_active = true;
                            }
                            else
                            {
                                m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
                                               + ", Layer: " + QString::number(layerNum,10)
                                               + " Error: Invalid Galvanometer Speed!");                                this->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                                block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);
                                m_parserStatus= PARSER_FAILED_INVALID_PART;
                            }
                        }

                        if(block->blockTask()|BlockObject::BlockTask::SET_Z_POSITION){
                            (*data_iterator).remove(0,1);
                            bool valid;
                            const float value = (*data_iterator).toFloat(&valid);
                            if(valid && (value < config->xy_speed_max()) && (value > config->xy_speed_min())){
                                block->setZ_speed(value);
                                axis_active = true;
                            }
                            else
                            {
                                m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
                                               + ", Layer: " + QString::number(layerNum,10)
                                               + " Error: Invalid Z Speed!");                                this->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                                block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);
                                m_parserStatus= PARSER_FAILED_INVALID_PART;                                this->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                                block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);
                                m_parserStatus= PARSER_FAILED_INVALID_PART;
                            }
                        }

                        if(block->blockTask()|BlockObject::BlockTask::SET_HOPPER_POSITION){
                            (*data_iterator).remove(0,1);
                            bool valid;
                            const float value = (*data_iterator).toFloat(&valid);
                            if(valid && (value < config->xy_speed_max()) && (value > config->xy_speed_min())){
                                block->setHopper_speed(value);
                                axis_active = true;
                            }
                            else
                            {
                                m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
                                               + ", Layer: " + QString::number(layerNum,10)
                                               + " Error: Invalid Hopper Speed!");
                                this->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                                block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);
                                m_parserStatus= PARSER_FAILED_INVALID_PART;
                            }
                        }

                        if(block->blockTask()|BlockObject::BlockTask::SET_SPREADER_POSITION){
                            (*data_iterator).remove(0,1);
                            bool valid;
                            const float value = (*data_iterator).toFloat(&valid);
                            if(valid && (value < config->xy_speed_max()) && (value > config->xy_speed_min())){
                                block->setSpreader_speed(value);
                                axis_active = true;
                            }
                            else
                            {
                                m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
                                               + ", Layer: " + QString::number(layerNum,10)
                                               + " Error: Invalid Spreader Speed!");
                                this->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                                block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);
                                m_parserStatus= PARSER_FAILED_INVALID_PART;
                            }
                        }
                    }

                    else if(QRegExp("[Xx]"+regEx_float).exactMatch(*data_iterator)){
                        (*data_iterator).remove(0,1);
                        bool valid;
                        const float val = (*data_iterator).toFloat(&valid);
                        if(valid && (val < config->x_position_max()) && (val > config->x_position_min())){
                            block->setX_position(val);
                        }
                        else{
                            m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
                                           + ", Layer: " + QString::number(layerNum,10)
                                           + " Error: Invalid X Position!");
                            this->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                            block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);
                            m_parserStatus= PARSER_FAILED_INVALID_PART;
                        }
                    }

                    else if(QRegExp("[Yy]"+regEx_float).exactMatch(*data_iterator)){
                        (*data_iterator).remove(0,1);
                        bool valid;
                        const float val = (*data_iterator).toFloat(&valid);
                        if(valid && (val < config->y_position_max()) && (val > config->y_position_min())){
                            block->setY_position(val);
                        }
                        else{
                            m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
                                           + ", Layer: " + QString::number(layerNum,10)
                                           + " Error: Invalid Y Position!");
                            this->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                            block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);
                            m_parserStatus= PARSER_FAILED_INVALID_PART;
                        }
                    }

                    else if(QRegExp("[Zz]"+regEx_float).exactMatch(*data_iterator)){
                        (*data_iterator).remove(0,1);
                        bool valid;
                        const float val = (*data_iterator).toFloat(&valid);
                        if(valid && (val < config->z_position_max()) && (val > config->z_position_min())){
                            block->setZ_position(val);
                        }
                        else{
                            m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
                                           + ", Layer: " + QString::number(layerNum,10)
                                           + " Error: Invalid Z Position!");
                            this->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                            block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);
                            m_parserStatus= PARSER_FAILED_INVALID_PART;
                        }
                    }

                    else if(QRegExp("[Aa]"+regEx_float).exactMatch(*data_iterator)){
                        (*data_iterator).remove(0,1);
                        bool valid;
                        const float val = (*data_iterator).toFloat(&valid);
                        if(valid && (val < config->hopper_position_max()) && (val > config->hopper_position_min())){
                            block->setHopper_position(val);
                        }
                        else{
                            m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
                                           + ", Layer: " + QString::number(layerNum,10)
                                           + " Error: Invalid Hopper Position!");
                            this->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                            block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);
                            m_parserStatus= PARSER_FAILED_INVALID_PART;
                        }
                    }

                    else if(QRegExp("[Bb]"+regEx_float).exactMatch(*data_iterator)){
                        (*data_iterator).remove(0,1);
                        bool valid;
                        const float val = (*data_iterator).toFloat(&valid);
                        if(valid && (val < config->spreader_position_max()) && (val > config->spreader_position_min())){
                            block->setSpreader_position(val);
                        }
                        else{
                            m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
                                           + ", Layer: " + QString::number(layerNum,10)
                                           + " Error: Invalid Spreader Position!");
                            this->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                            block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);
                            m_parserStatus= PARSER_FAILED_INVALID_PART;
                        }
                    }
                    ++data_iterator;
                }
            }
            myblocks.append(block);
            blockNum++;
            ++line_iterator;
        }
        m_blocks = &myblocks;
    }
    else{
        m_parserStatus= PARSER_FAILED_INVALID_PART;
        m_errorStr += "File is Empty";
    }
}

PartObject::~PartObject()
{

}

uint32_t PartObject::blockCount() const
{
    return m_blockCount;
}

void PartObject::setBlockCount(const uint32_t &blockCount)
{
    m_blockCount = blockCount;
}

uint32_t PartObject::layerCount() const
{
    return m_layerCount;
}

void PartObject::setLayerCount(const uint32_t &layerCount)
{
    m_layerCount = layerCount;
}



PartObject::PartStatus PartObject::partStatus() const
{
    return m_partStatus;
}

void PartObject::setPartStatus(const PartStatus &partStatus)
{
    m_partStatus = partStatus;
}

QString PartObject::partFilePath() const
{
    return m_partFilePath;
}

void PartObject::setPartFilePath(const QString &partFilePath)
{
    m_partFilePath = partFilePath;
}


QVector<uint32_t> PartObject::layerFlags() const
{
    return m_layerFlags;
}

void PartObject::setLayerFlags(const QVector<uint32_t> &layerFlags)
{
    m_layerFlags = layerFlags;
}




void PartObject::addBlock(BlockObject *block){
    m_blocks->append(block);
}

QVector<BlockObject *> *PartObject::blocks() const
{
    return m_blocks;
}

void PartObject::setBlocks(QVector<BlockObject *> *blocks)
{
    m_blocks = blocks;
}

PartObject::ParserStatus PartObject::parserStatus() const
{
    return m_parserStatus;
}

void PartObject::setParserStatus(const ParserStatus &parserStatus)
{
    m_parserStatus = parserStatus;
}

QString PartObject::errorStr() const
{
    return m_errorStr;
}

void PartObject::setErrorStr(const QString &errorStr)
{
    m_errorStr = errorStr;
}


