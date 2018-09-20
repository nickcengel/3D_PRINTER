#include "powder_part.h"
#include <QFile>
#include <QRegExp>
#include <QtDebug>
#include <QTextStream>
#include "hardware_tools/lasergalvo_utility.h"
#include "hardware_tools/zaber_utility.h"

PowderPart::PowderPart()
{
    qRegisterMetaType<PowderPart>("PowderPart");
}

PowderPart::PowderPart(const PowderPart &otherPart)
{
    m_partFilePath = otherPart.partFilePath();
    m_errorStr = otherPart.errorStr();
    m_gcode = otherPart.gcode();
    m_blocks = otherPart.getBlocks();
    m_blockCount = otherPart.blockCount();
    m_layerCount = otherPart.layerCount();
    m_layerFlags = otherPart.layerFlags();
    m_partStatus = otherPart.partStatus();
    m_parserStatus = otherPart.parserStatus();
}


// This is the only constructor for PowderPart that is explicitly used.
// Calling PowderPart with a file path and configuration will generate a new PowderPart
// containing PowderBlocks.

PowderPart::PowderPart(const QString &filePath, QSharedPointer<PowderSettings> config){

    // Set initial state values
    this->setPartFilePath(filePath);
    this->setPartStatus(PART_IS_EMPTY);
    m_parserStatus = PARSER_INIT;
    // used to track changes between absolute and relative modes between blocks
    static PowderBlock::PositionMode prevailPosMode = PowderBlock::PositionMode::Position_Absolute;

    // Open file and read each line into the gcode variable.
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
        // set up variables prior to looping through all g-code lines
        int blockNum = 0;
        int layerNum = 0;
        QStringList::iterator line_iterator = m_gcode.begin();
        m_parserStatus = PARSER_READY;
        m_blocks = QSharedPointer<QVector<PowderBlock>>(new QVector<PowderBlock>);

        // Loop through the list of g-code lines
        while(line_iterator != m_gcode.end()){

            // Create a new block for this line
            PowderBlock *block = new PowderBlock(blockNum, layerNum);
            block->clearTask();

            // create a copy of the g-code line. Non command tokens will be removed
            // from this string.
            QString g_subLine = *line_iterator;
            g_subLine = g_subLine.simplified();

            // Check if a new layer is flagged
            if(g_subLine.contains(QRegExp("NEW[-_\\s]?LAYER",Qt::CaseInsensitive))){
                m_layerFlags.append(blockNum);
                layerNum++;
            }

            // Handle G-Code comments
            // Handle ( comments ) that appear to the right of a command
            if(g_subLine.indexOf("(") > 1){
                g_subLine = g_subLine.left(g_subLine.indexOf("("));
                g_subLine.append("Q");
            }
            // Handle ( comments ) that appear to the left of a command
            else if(g_subLine.indexOf("(") == 0){
                g_subLine = g_subLine.right(g_subLine.length() - g_subLine.indexOf(")")-1);
            }
            // Handle ;comments
            else if(g_subLine.indexOf(";") >= 0){
                g_subLine = g_subLine.left(g_subLine.indexOf(";"));
                g_subLine.append("Q"); // used as a junk char to aid further string splitting
            }
            // remove commented out lines
            else if (g_subLine.contains("/"))
            {
                g_subLine.clear();
            }

            // if g_subline is not empty, it contains some commands that we need to parse and interpret.
            if(!g_subLine.isEmpty()){
                // regexs to find integer and float strings
                const QString regEx_uInt = "{1,1}\\s{0,1}\\d{1,3}";
                const QString regEx_float = "[+-]?\\d{0,8}\\.{0,1}\\d{0,8}";

                // remove spaces between command and value
                g_subLine = g_subLine.replace(QRegExp("\\s+(?=([+-]?\\d))"),"");

                // split the g-code line into gData, a list of individual command value pairs.
                QStringList gData = g_subLine.split(QRegExp("(\\s{1,8})(?=(([A-Z])|([\n])))"));
                QStringList::iterator data_iterator = gData.begin();

                // iterate through the list command strings
                while(data_iterator != gData.end()){

                    // Find G- commands
                    if(QRegExp("[Gg]"+regEx_uInt).exactMatch(*data_iterator)){
                        block->clearTask();
                        (*data_iterator).remove(0,1);
                        const int val = (*data_iterator).toInt();

                        switch (val) {
                        case 28: // G28 = Home
                        {
                            block->setBlockTask(PowderBlock::BlockTask::SET_HOME_AXIS);
                            break;
                        }
                        case 90: // G90 = Absolute Move
                        {
                            prevailPosMode =  PowderBlock::PositionMode::Position_Absolute;
                            break;
                        }
                        case 91:  // G91 = Relative Move
                        {
                            prevailPosMode =  PowderBlock::PositionMode::Position_Relative;
                            break;
                        }
                        default:
                            break;
                        }

                    }

                    // Find M- commands
                    else if(QRegExp("[Mm]"+regEx_uInt).exactMatch(*data_iterator)){
                        (*data_iterator).remove(0,1);
                        const int val = (*data_iterator).toInt();
                        switch (val) {
                        case 3: // M3 = Laser On
                        {
                            block->setLaser_enabled(true);
                            break;
                        }
                        case 5: // M5 = Laser Off
                        {
                            block->setLaser_enabled(false);
                            break;
                        }
                        default:
                            break;
                        }
                    }

                    // Find S- commands (set laser power)
                    else if(QRegExp("[Ss]"+regEx_uInt).exactMatch(*data_iterator)){
                        (*data_iterator).remove(0,1);
                        bool valid;
                        const int value = (*data_iterator).toInt(&valid);

                        if(valid && (value < config->laser_power_max()) && (value > config->laser_power_min())){
                            block->setLaser_power(value);
                        }
                        else
                        {
                            m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
                                           + ", Layer: " + QString::number(layerNum,10)
                                           + " Error: Invalid Laser Power!");                            this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
                            block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
                            m_parserStatus= PARSER_FAILED_INVALID_PART;
                        }

                    }

                    // Find P- commands (set a dwell time)
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
                            this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
                            block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
                            m_parserStatus= PARSER_FAILED_INVALID_PART;
                        }
                    }

                    // Find F- commands (for feed rates)
                    else if(QRegExp("[Ff]"+regEx_float).exactMatch(*data_iterator)){
                        (*data_iterator).remove(0,1);

                        // Set XY Speed if x or y move was found
                        if(((block->blockTask())&(PowderBlock::BlockTask::SET_X_POSITION))
                                ||((block->blockTask())&(PowderBlock::BlockTask::SET_Y_POSITION))){
                            bool valid;
                            const float value = (*data_iterator).toFloat(&valid);
                            if(valid && (value < config->xy_speed_max()) && (value > config->xy_speed_min())){
                                block->setXY_speed(value);
                            }
                            else
                            {
                                m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
                                               + ", Layer: " + QString::number(layerNum,10)
                                               + " Error: Invalid Galvanometer Speed!");                                this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
                                block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
                                m_parserStatus= PARSER_FAILED_INVALID_PART;
                            }
                        }

                        // Set Z Speed if Z move was found
                        if((block->blockTask())&(PowderBlock::BlockTask::SET_Z_POSITION)){
                            bool valid;
                            const float value = (*data_iterator).toFloat(&valid);
                            if(valid && (value < config->z_speed_max()) && (value > config->z_speed_min())){
                                block->setZ_speed(value);
                            }
                            else
                            {
                                m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
                                               + ", Layer: " + QString::number(layerNum,10)
                                               + " Error: Invalid Z Speed!");
                                this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
                                block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
                                m_parserStatus= PARSER_FAILED_INVALID_PART;
                                this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
                                block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
                                m_parserStatus= PARSER_FAILED_INVALID_PART;
                            }
                        }

                        // Set Hopper Speed if Hopper move was found
                        if((block->blockTask())&(PowderBlock::BlockTask::SET_HOPPER_POSITION)){
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
                                this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
                                block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
                                m_parserStatus= PARSER_FAILED_INVALID_PART;
                            }
                        }

                        // Set Spreader Speed if Spreader move was found
                        if((block->blockTask())&(PowderBlock::BlockTask::SET_SPREADER_POSITION)){
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
                                this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
                                block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
                                m_parserStatus= PARSER_FAILED_INVALID_PART;
                            }
                        }
                    }

                    // Find X Moves
                    else if(QRegExp("[Xx]"+regEx_float).exactMatch(*data_iterator)){
                        if(!(block->blockTask() & PowderBlock::BlockTask::SET_HOME_AXIS)){
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
                                this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
                                block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
                                m_parserStatus= PARSER_FAILED_INVALID_PART;
                            }
                        }
                        else
                        {
                            block->setX_position(0);
                        }
                    }

                    // Find Y Moves
                    else if(QRegExp("[Yy]"+regEx_float).exactMatch(*data_iterator)){
                        if(!(block->blockTask() & PowderBlock::BlockTask::SET_HOME_AXIS)){
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
                                this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
                                block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
                                m_parserStatus= PARSER_FAILED_INVALID_PART;
                            }
                        }
                        else{ // home
                            block->setY_position(0);
                        }
                    }

                    // Find Z Moves
                    else if(QRegExp("[Zz]"+regEx_float).exactMatch(*data_iterator)){
                        if(!(block->blockTask() & PowderBlock::BlockTask::SET_HOME_AXIS)){
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
                                this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
                                block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
                                m_parserStatus= PARSER_FAILED_INVALID_PART;
                            }
                        }
                        else{ // home
                            block->setZ_position(0);
                        }

                    }

                    // Find A Moves. (The A axis maps to the hopper)
                    else if(QRegExp("[Aa]"+regEx_float).exactMatch(*data_iterator)){
                        if(!(block->blockTask() & PowderBlock::BlockTask::SET_HOME_AXIS)){
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
                                this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
                                block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
                                m_parserStatus= PARSER_FAILED_INVALID_PART;
                            }
                        }
                        else{ // home
                            block->setHopper_position(0);
                        }
                    }

                    // Find B Moves. (The B axis maps to the spreader)
                    else if(QRegExp("[Bb]"+regEx_float).exactMatch(*data_iterator)){
                        if(!(block->blockTask() & PowderBlock::BlockTask::SET_HOME_AXIS)){
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
                                this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
                                block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
                                m_parserStatus= PARSER_FAILED_INVALID_PART;
                            }
                        }
                        else { // home
                            block->setSpreader_position(0);
                        }
                    }

                    // Use the extrusion data to signal moves where the laser is to be enabled
                    else if(QRegExp("[Ee]" + regEx_float).exactMatch(*data_iterator)){
                        block->setLaser_enabled(true);
                    }

                    ++data_iterator;
                }
            } // end parsing line.

            // generate command strings
            block->setLg_string(LaserGalvo_Utility::composeCommandString(block, config.get()));
            const QStringList md = ZaberUtility::composeCommandString(block, config.get());
            block->setMd_string(md);
            // add block to the part
            m_blocks->append(*block);

            // prepare for next block
            delete  block;
            blockNum++;
            ++line_iterator;
        }   // end processing line
        m_blockCount = blockNum;
        m_layerCount = layerNum;
    } // end processing file
    else{
        m_parserStatus= PARSER_FAILED_INVALID_PART;
        m_errorStr += "File is Empty";
    }
    // if parserStatus was not set to failed, the process succeeded/
    if(m_parserStatus == PARSER_READY)
        m_parserStatus = PARSER_SUCCESS;
}

PowderPart::~PowderPart()
{
    m_blocks.clear();

}

int PowderPart::blockCount() const
{
    return m_blockCount;
}

void PowderPart::setBlockCount(const int &blockCount)
{
    m_blockCount = blockCount;
}

int PowderPart::layerCount() const
{
    return m_layerCount;
}

void PowderPart::setLayerCount(const int &layerCount)
{
    m_layerCount = layerCount;
}



PowderPart::PartStatus PowderPart::partStatus() const
{
    return m_partStatus;
}

void PowderPart::setPartStatus(const PartStatus &partStatus)
{
    m_partStatus = partStatus;
}

QString PowderPart::partFilePath() const
{
    return m_partFilePath;
}

void PowderPart::setPartFilePath(const QString &partFilePath)
{
    m_partFilePath = partFilePath;
}


QVector<int> PowderPart::layerFlags() const
{
    return m_layerFlags;
}

void PowderPart::setLayerFlags(const QVector<int> &layerFlags)
{
    m_layerFlags = layerFlags;
}




void PowderPart::addBlock(const PowderBlock &block){
    m_blocks.get()->append(block);
}

PowderPart::ParserStatus PowderPart::parserStatus() const
{
    return m_parserStatus;
}

void PowderPart::setParserStatus(const ParserStatus &parserStatus)
{
    m_parserStatus = parserStatus;
}

QString PowderPart::errorStr() const
{
    return m_errorStr;
}

void PowderPart::setErrorStr(const QString &errorStr)
{
    m_errorStr = errorStr;
}

QStringList PowderPart::gcode() const
{
    return m_gcode;
}

void PowderPart::setGcode(const QStringList &gcode)
{
    m_gcode = gcode;
}


PowderBlock PowderPart::getBlock(const int blockNum) const
{
    return m_blocks.get()->at(static_cast<int>(blockNum));
}

void PowderPart::clearPart()
{

    m_blocks->clear();
    m_partFilePath = "";
    m_errorStr = "";
    m_gcode.clear();
    m_blockCount = 0;
    m_layerCount = 0;
    m_partStatus = PART_IS_EMPTY;
    m_layerFlags.clear();
    m_parserStatus = PARSER_INIT;
}

QSharedPointer<QVector<PowderBlock> > PowderPart::getBlocks() const
{
    return m_blocks;
}

void PowderPart::setBlocks(const QSharedPointer<QVector<PowderBlock> > &blocks)
{
    m_blocks = blocks;
}


