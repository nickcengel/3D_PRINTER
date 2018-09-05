#include "partobject.h"
#include <QFile>
#include <QRegExp>
#include <QtDebug>
#include <QTextStream>
#include "hardware_tools/lasergalvo_utility.h"
#include "hardware_tools/zaber_utility.h"

PartObject::PartObject()
{
    qRegisterMetaType<PartObject>("PartObject");
}

PartObject::PartObject(const PartObject &otherPart)
{
    m_blockCount = otherPart.blockCount();
    m_layerCount = otherPart.layerCount();
    m_layerFlags = otherPart.layerFlags();
    m_blocks = otherPart.blocks();
    m_partFilePath = otherPart.partFilePath();
    m_partStatus = otherPart.partStatus();
    m_gcode = otherPart.gcode();
    m_errorStr = otherPart.errorStr();
    //    m_laserGalvo_commands = otherPart.laserGalvo_commands();
    //    m_materialDelivery_commands = otherPart.materialDelivery_commands();
}


PartObject::PartObject(const QString &filePath, SettingsObject *config){


    this->setPartFilePath(filePath);
    this->setPartStatus(PART_IS_EMPTY);
    m_parserStatus = PARSER_INIT;
    static BlockObject::PositionMode prevailPosMode = BlockObject::PositionMode::Position_Absolute;

    QFile partFile(this->partFilePath());
    if(partFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream partFileStream(&partFile);
        while(!partFileStream.atEnd()){
            m_gcode<< partFileStream.readLine();
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

    if(!m_gcode.isEmpty()){
        uint32_t blockNum = 0;
        uint32_t layerNum = 0;
        QStringList::iterator line_iterator = m_gcode.begin();
        m_parserStatus = PARSER_READY;
        while(line_iterator != m_gcode.end()){
            BlockObject *block = new BlockObject(blockNum, layerNum);
            block->clearTask();
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
                QStringList gData = g_subLine.split(QRegExp("(\\s{1,8})(?=(([A-Z])|([\n])))"));
                QStringList::iterator data_iterator = gData.begin();

                while(data_iterator != gData.end()){

                    if(QRegExp("[Gg]"+regEx_uInt).exactMatch(*data_iterator)){
                        block->clearTask();
                        (*data_iterator).remove(0,1);
                        const uint8_t val = (*data_iterator).toUInt();

                        if(val == 90){
                            prevailPosMode =  BlockObject::PositionMode::Position_Absolute;
                        }
                        else if(val == 91){
                            prevailPosMode =  BlockObject::PositionMode::Position_Relative;
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
                        (*data_iterator).remove(0,1);
                        if(((block->blockTask())&(BlockObject::BlockTask::SET_X_POSITION))
                                ||((block->blockTask())&(BlockObject::BlockTask::SET_Y_POSITION))){
                            bool valid;
                            const float value = (*data_iterator).toFloat(&valid);
                            if(valid && (value < config->xy_speed_max()) && (value > config->xy_speed_min())){
                                block->setXY_speed(value);
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

                        if((block->blockTask())&(BlockObject::BlockTask::SET_Z_POSITION)){
                            bool valid;
                            const float value = (*data_iterator).toFloat(&valid);
                            if(valid && (value < config->z_speed_max()) && (value > config->z_speed_min())){
                                block->setZ_speed(value);
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

                        if((block->blockTask())&(BlockObject::BlockTask::SET_HOPPER_POSITION)){
                            bool valid;
                            const float value = (*data_iterator).toFloat(&valid);
                            if(valid && (value < config->hopper_speed_max()) && (value > config->hopper_speed_min())){
                                block->setHopper_speed(value);
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

                        if((block->blockTask())&(BlockObject::BlockTask::SET_SPREADER_POSITION)){
                            bool valid;
                            const float value = (*data_iterator).toFloat(&valid);
                            if(valid && (value < config->spreader_speed_max()) && (value > config->spreader_speed_min())){
                                block->setSpreader_speed(value);
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
                        if(!(block->blockTask() & BlockObject::BlockTask::SET_HOME_AXIS)){
                            (*data_iterator).remove(0,1);
                            bool valid;
                            const float val = (*data_iterator).toFloat(&valid);
                            if(valid && (val < config->x_position_max()) && (val > config->x_position_min())){
                                block->setX_position(val);
                                block->setPositionMode(prevailPosMode);
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
                        else
                        {
                            block->setX_position(0);
                        }
                    }

                    else if(QRegExp("[Yy]"+regEx_float).exactMatch(*data_iterator)){
                        if(!(block->blockTask() & BlockObject::BlockTask::SET_HOME_AXIS)){
                            (*data_iterator).remove(0,1);
                            bool valid;
                            const float val = (*data_iterator).toFloat(&valid);
                            if(valid && (val < config->y_position_max()) && (val > config->y_position_min())){
                                block->setY_position(val);
                                block->setPositionMode(prevailPosMode);
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
                        else
                        {
                            block->setY_position(0);
                        }
                    }

                    else if(QRegExp("[Zz]"+regEx_float).exactMatch(*data_iterator)){
                        if(!(block->blockTask() & BlockObject::BlockTask::SET_HOME_AXIS)){
                            (*data_iterator).remove(0,1);
                            bool valid;
                            const float val = (*data_iterator).toFloat(&valid);
                            if(valid && (val < config->z_position_max()) && (val > config->z_position_min())){
                                block->setZ_position(val);
                                block->setPositionMode(prevailPosMode);
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
                        else{
                            block->setZ_position(0);
                        }

                    }

                    else if(QRegExp("[Aa]"+regEx_float).exactMatch(*data_iterator)){
                        if(!(block->blockTask() & BlockObject::BlockTask::SET_HOME_AXIS)){
                            (*data_iterator).remove(0,1);
                            bool valid;
                            const float val = (*data_iterator).toFloat(&valid);
                            if(valid && (val < config->hopper_position_max()) && (val > config->hopper_position_min())){
                                block->setHopper_position(val);
                                block->setPositionMode(prevailPosMode);
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
                        else
                        {
                            block->setHopper_position(0);
                        }
                    }

                    else if(QRegExp("[Bb]"+regEx_float).exactMatch(*data_iterator)){
                        if(!(block->blockTask() & BlockObject::BlockTask::SET_HOME_AXIS)){
                            (*data_iterator).remove(0,1);
                            bool valid;
                            const float val = (*data_iterator).toFloat(&valid);
                            if(valid && (val < config->spreader_position_max()) && (val > config->spreader_position_min())){
                                block->setSpreader_position(val);
                                block->setPositionMode(prevailPosMode);
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
                        else {
                            block->setSpreader_position(0);
                        }
                    }
                    else if(QRegExp("[Ee]" + regEx_float).exactMatch(*data_iterator)){
                        block->setLaser_enabled(true);
                    }

                    ++data_iterator;
                }
            }

            block->setLg_string(LaserGalvo_Utility::composeCommandString(block, config));
            block->setMd_string(ZaberUtility::composeCommandString(block, config));
            m_blocks.append(block);
            blockNum++;
            ++line_iterator;
        }
        m_blockCount = blockNum;
        m_layerCount = layerNum;
    }
    else{
        m_parserStatus= PARSER_FAILED_INVALID_PART;
        m_errorStr += "File is Empty";
    }

    if(m_parserStatus == PARSER_READY)
        m_parserStatus = PARSER_SUCCESS;
}

PartObject::~PartObject()
{
    for(int i = 0; i < m_blocks.size(); i++){
        delete m_blocks.takeAt(i);
    }

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
    m_blocks.append(block);
}

QVector<BlockObject *> PartObject::blocks() const
{
    return m_blocks;
}

void PartObject::setBlocks(QVector<BlockObject *> blocks)
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

QStringList PartObject::gcode() const
{
    return m_gcode;
}

void PartObject::setGcode(const QStringList &gcode)
{
    m_gcode = gcode;
}

//QStringList PartObject::laserGalvo_commands() const
//{
//    return m_laserGalvo_commands;
//}

//void PartObject::setLaserGalvo_commands(const QStringList &laserGalvo_commands)
//{
//    m_laserGalvo_commands = laserGalvo_commands;
//}

//QStringList PartObject::materialDelivery_commands() const
//{
//    return m_materialDelivery_commands;
//}

//void PartObject::setMaterialDelivery_commands(const QStringList &materialDelivery_commands)
//{
//    m_materialDelivery_commands = materialDelivery_commands;
//}

BlockObject *PartObject::getBlock(int blockNum)
{
    return m_blocks.at(blockNum);
}

void PartObject::clearPart()
{
    for(int i = 0; i < m_blocks.size(); i++){
        delete m_blocks.takeAt(i);
    }
    m_blocks.clear();
    m_partFilePath = "";
    m_errorStr = "";
    m_gcode.clear();
    m_blockCount = 0;
    m_layerCount = 0;
    m_partStatus = PART_IS_EMPTY;
    m_layerFlags.clear();
    m_parserStatus = PARSER_INIT;
}


