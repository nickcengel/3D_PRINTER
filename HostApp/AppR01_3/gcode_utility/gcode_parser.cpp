#include "gcode_parser.h"
#include "system_objects/partobject.h"
#include "system_objects/settingsobject.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QtDebug>
#include <QDebug>


GCode_Parser::GCode_Parser(PartObject &part, const QString &filePath, SettingsObject &configuration, QObject *parent) : QObject(parent)
{
    m_status = PARSER_INIT;
    m_part = &part;
    if(filePath.isEmpty()){
        m_status = PARSER_FAILED_INVALID_PART;
        m_part->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
    }
    else
    {
        m_part->setPartFilePath(filePath);
    }

    if(configuration.status() != SettingsObject::SettingsStatus::SETTINGS_VALID)
    {
        m_status = PARSER_FAILED_INVALID_CONFIGURATION;
        m_part->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
    }
    else
    {
        m_configuration =  &configuration;
    }

    if(m_status == PARSER_INIT){
        m_status = PARSER_READY;
    }
}


GCode_Parser::ParserStatus GCode_Parser::status() const {
    return m_status;
}

void GCode_Parser::setStatus(const ParserStatus &status) {
    m_status = status;
}

BlockObject GCode_Parser::parse_line(const QString &gline,
                                      BlockObject::PositionMode *positionMode,
                                      uint32_t blockN, uint32_t layerN) {
    BlockObject *block = new BlockObject(m_part);
    block->setBlockNumber(blockN);
    block->setLayerNumber(layerN);
    block->setG_code_line(gline);
    block->setPositionMode(*positionMode);
    block->setBlockTask(BlockObject::BlockTask::BLOCK_EMPTY);
    QString g_subLine;
    if(gline.contains(QRegExp("[;\\(\\)\\\\]")))
    {
        int commentStart = gline.indexOf('(');
        int commentEnd = gline.indexOf(')');
        if((commentStart >= 0)&&(commentEnd > commentStart)){
            if(commentStart <= 1){
                g_subLine = gline.right(gline.size( )- commentEnd);
            }
            else{
                g_subLine = gline.left(gline.size() - (commentEnd - commentStart));
            }
        }
        else if(gline.indexOf(';') != -1){
            if(gline.indexOf(';') >= 2){
                g_subLine = gline.left(gline.size() - gline.indexOf(';'));
            }
        }
    }
    else{
        g_subLine = gline;
    }

    if(g_subLine.size() >= 1){
        QStringList gData = g_subLine.split(QRegExp("\\s+(?=(\\D)"));
        QStringList::iterator it = gData.begin();
        QRegExp g_expr("[Gg]{1,1}\\s{0,1}\\d{1,3}"); // gcodes
        QRegExp m_expr("[Mm]{1,1}\\s{0,1}\\d{1,3}"); // mcodes
        QRegExp s_expr("[Ss]\\s{0,1}\\d{1,8}\\.{0,1}\\d{0,8}"); // S for laser power
        QRegExp e_expr("[Ee]\\s{0,1}([+-]?)\\d{0,8}\\.{0,1}\\d{0,8}"); // E for laser/extruder enable
        QRegExp p_expr("[Pp]\\s{0,1}\\d{1,8}\\.{0,1}\\d{0,8}"); // P for dwell
        QRegExp f_expr("[Ff]\\s{0,1}\\d{1,8}\\.{0,1}\\d{0,8}"); // F for speed
        QRegExp x_expr("[Xx]\\s{0,1}([+-]?)\\d{0,8}\\.{0,1}\\d{0,8}"); // X
        QRegExp y_expr("[Yy]\\s{0,1}([+-]?)\\d{0,8}\\.{0,1}\\d{0,8}"); // Y
        QRegExp z_expr("[Zz]\\s{0,1}([+-]?)\\d{0,8}\\.{0,1}\\d{0,8}"); // Z
        QRegExp a_expr("[Aa]\\s{0,1}([+-]?)\\d{0,8}\\.{0,1}\\d{0,8}"); // A
        QRegExp b_expr("[Bb]\\s{0,1}([+-]?)\\d{0,8}\\.{0,1}\\d{0,8}"); // B

        while(it != gData.end()){

            if(it->contains(g_expr)){
                if(it->contains(QRegExp("G{1,1}\\s{0,1}2{1,1}8{1,1}"))){
                    block->setBlockTask(BlockObject::BlockTask::SET_HOME_AXIS);
                }
                else if(it->contains(QRegExp("G{1,1}\\s{0,1}9{1,1}0{1,1}"))){
                    block->setPositionMode(BlockObject::PositionMode::Position_Absolute);
                    if(*positionMode != BlockObject::PositionMode::Position_Absolute){
                        block->setBlockTask(BlockObject::BlockTask::SET_POSITION_MODE);
                        *positionMode = BlockObject::PositionMode::Position_Absolute;
                    }
                }
                else if(it->contains(QRegExp("G{1,1}\\s{0,1}9{1,1}1{1,1}"))){
                    block->setPositionMode(BlockObject::PositionMode::Position_Relative);
                    if(*positionMode != BlockObject::PositionMode::Position_Relative){
                        block->setBlockTask(BlockObject::BlockTask::SET_POSITION_MODE);
                        *positionMode = BlockObject::PositionMode::Position_Relative;
                    }
                }

            }

            else if(it->contains(m_expr)){
                if(it->contains(QRegExp("M{1,1}\\s{0,1}3{1,1}"))){
                    block->setLaser_enabled(true);
                }
                else if(it->contains(QRegExp("M{1,1}\\s{0,1}5{1,1}"))){
                    block->setLaser_enabled(false);
                }
            }

            else if(it->contains(s_expr)){
                int numStart = it->indexOf(QRegExp("[+-]?\\d"));
                bool valid = true;
                const QString numString = it->right(it->length() - numStart);
                const uint8_t value = numString.toUInt(&valid);

                if(valid && (numStart >= 0) && (value < m_configuration->laser_power_max())&&(value > m_configuration->laser_power_min())){
                    block->setLaser_power(value);
                }
                else
                {
                    qDebug()<<"Error: Invalid Laser Power";
                    m_part->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                    block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);
                }

            }

            else if(it->contains(p_expr)){
                int numStart = it->indexOf(QRegExp("[+-]?\\d"));
                bool valid = true;
                const QString numString = it->right(it->length() - numStart);
                const float value = numString.toFloat(&valid);

                if(valid && (numStart >= 0)){
                    block->setDwellTime(value);
                }
                else
                {
                    qDebug()<<"Error: Invalid Dwell Time";
                    m_part->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                    block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);

                }
            }

            else if(it->contains(f_expr)){
                bool axis_active = false;

                if((block->blockTask()|BlockObject::BlockTask::SET_X_POSITION)
                        ||(block->blockTask()|BlockObject::BlockTask::SET_Y_POSITION)){

                    int numStart = it->indexOf(QRegExp("[+-]?\\d"));
                    bool valid = true;
                    const QString numString = it->right(it->length() - numStart);
                    const float value = numString.toFloat(&valid);

                    if(valid && (numStart >= 0) && (value < m_configuration->xy_speed_max()) && (value > m_configuration->xy_speed_min())){
                        block->setXY_speed(value);
                        axis_active = true;
                    }
                    else
                    {
                        qDebug()<<"Error: Invalid Galvanometer Speed";
                        m_part->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                        block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);

                    }
                }

                if(block->blockTask()|BlockObject::BlockTask::SET_Z_POSITION){
                    int numStart = it->indexOf(QRegExp("[+-]?\\d"));
                    bool valid = true;
                    const QString numString = it->right(it->length() - numStart);
                    const float value = numString.toFloat(&valid);

                    if(valid && (numStart >= 0) && (value < m_configuration->z_speed_max()) && (value > m_configuration->z_speed_min())){
                        block->setZ_speed(value);
                        axis_active = true;
                    }
                    else
                    {
                        qDebug()<<"Error: Invalid Speed";
                        m_part->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                        block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);

                    }
                }

                if(block->blockTask()|BlockObject::BlockTask::SET_HOPPER_POSITION){

                    int numStart = it->indexOf(QRegExp("[+-]?\\d"));
                    bool valid = true;
                    const QString numString = it->right(it->length() - numStart);
                    const float value = numString.toFloat(&valid);

                    if(valid && (numStart >= 0) && (value < m_configuration->hopper_speed_max()) && (value > m_configuration->hopper_speed_min())){
                        block->setHopper_speed(value);
                        axis_active = true;
                    }
                    else
                    {
                        qDebug()<<"Error: Invalid Speed";
                        m_part->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                        block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);

                    }
                }

                if(block->blockTask()|BlockObject::BlockTask::SET_SPREADER_POSITION){

                    int numStart = it->indexOf(QRegExp("[+-]?\\d"));
                    bool valid = true;
                    const QString numString = it->right(it->length() - numStart);
                    const float value = numString.toFloat(&valid);

                    if(valid && (numStart >= 0) &&  (value < m_configuration->spreader_speed_max()) && (value > m_configuration->spreader_speed_min())){
                        block->setSpreader_speed(value);
                        axis_active = true;
                    }
                    else
                    {
                        qDebug()<<"Error: Invalid Speed";
                        m_part->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                        block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);

                    }
                }

                if(!axis_active){
                    int numStart = it->indexOf(QRegExp("[+-]?\\d"));
                    bool valid = true;
                    const QString numString = it->right(it->length() - numStart);
                    const float value = numString.toFloat(&valid);

                    if(valid && (numStart >= 0)){
                        if((value < m_configuration->xy_speed_max()) && (value > m_configuration->xy_speed_min())){
                            block->setXY_speed(value);
                        }
                        if((value < m_configuration->z_speed_max()) && (value > m_configuration->z_speed_min())){
                            block->setHopper_speed(value);
                        }
                        if((value < m_configuration->hopper_speed_max()) && (value > m_configuration->hopper_speed_min())){
                            block->setHopper_speed(value);
                        }
                        if((value < m_configuration->spreader_speed_max()) && (value > m_configuration->spreader_speed_min())){
                            block->setSpreader_speed(value);
                        }
                    }
                    else
                    {
                        qDebug()<<"Error: Invalid Speed";
                        m_part->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                        block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);

                    }
                }


            }

            else if(it->contains(x_expr)){
                int numStart = it->indexOf(QRegExp("[+-]?\\d"));
                if((numStart == -1) && (block->blockTask()|BlockObject::BlockTask::SET_HOME_AXIS)){
                    block->setX_position(0);
                }
                else if (numStart != -1){
                    const QString numString = it->right(it->length() - numStart);
                    bool valid = true;
                    const float value = numString.toFloat(&valid);
                    if(valid && (value < m_configuration->x_position_max()) && (value > m_configuration->x_position_min())){
                        block->setX_position(value);
                    }
                    else
                    {
                        qDebug()<<"Error: Invalid X Position";
                        m_part->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                        block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);

                    }
                }
                else
                {
                    qDebug()<<"Error: Invalid X Position";
                    m_part->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                    block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);

                }
            }

            else if(it->contains(y_expr)){
                int numStart = it->indexOf(QRegExp("[+-]?\\d"));
                if((numStart == -1) && (block->blockTask()|BlockObject::BlockTask::SET_HOME_AXIS)){
                    block->setY_position(0);
                }
                else if (numStart != -1){
                    const QString numString = it->right(it->length() - numStart);
                    bool valid = true;
                    const float value = numString.toFloat(&valid);
                    if(valid && (value < m_configuration->y_position_max()) && (value > m_configuration->y_position_min())){
                        block->setY_position(value);
                    }
                    else
                    {
                        qDebug()<<"Error: Invalid Y Position";
                        m_part->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                        block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);

                    }
                }
                else
                {
                    qDebug()<<"Error: Invalid Y Position";
                    m_part->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                    block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);

                }
            }

            else if(it->contains(z_expr)){
                int numStart = it->indexOf(QRegExp("[+-]?\\d"));
                if((numStart == -1) && (block->blockTask()|BlockObject::BlockTask::SET_HOME_AXIS)){
                    block->setZ_position(0);
                }
                else if (numStart != -1){
                    const QString numString = it->right(it->length() - numStart);
                    bool valid = true;
                    const float value = numString.toFloat(&valid);
                    if(valid && (value < m_configuration->z_position_max()) && (value > m_configuration->z_position_min())){
                        block->setZ_position(value);
                    }
                    else
                    {
                        qDebug()<<"Error: Invalid Z Position";
                        m_part->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                        block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);

                    }
                }
                else{
                    qDebug()<<"Error: Invalid Z Position";
                    m_part->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                    block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);

                }
            }

            else if(it->contains(a_expr)){
                int numStart = it->indexOf(QRegExp("[+-]?\\d"));
                if((numStart == -1) && (block->blockTask()|BlockObject::BlockTask::SET_HOME_AXIS)){
                    block->setHopper_position(0);
                }
                else if(numStart != -1){
                    const QString numString = it->right(it->length() - numStart);
                    bool valid = true;
                    const float value = numString.toFloat(&valid);
                    if(valid && (value < m_configuration->hopper_position_max()) && (value > m_configuration->hopper_position_min())){
                        block->setHopper_position(value);
                    }
                    else
                    {
                        qDebug()<<"Error: Invalid Hopper Position";
                        m_part->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                        block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);

                    }
                }
                else{
                    qDebug()<<"Error: Invalid Hopper Position";

                    m_part->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                    block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);

                }
            }

            else if(it->contains(b_expr)){
                int numStart = it->indexOf(QRegExp("[+-]?\\d"));
                if((numStart == -1) && (block->blockTask()|BlockObject::BlockTask::SET_HOME_AXIS)){
                    block->setSpreader_position(0);
                }
                else if(numStart != -1){
                    const QString numString = it->right(it->length() - numStart);
                    bool valid = true;
                    const float value = numString.toFloat(&valid);
                    if(valid && (value < m_configuration->spreader_position_max()) && (value > m_configuration->spreader_position_min())){
                        block->setSpreader_position(value);
                    }
                    else
                    {
                        qDebug()<<"Error: Invalid Spreader Position";
                        m_part->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                        block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);

                    }
                }
                else{
                    qDebug()<<"Error: Invalid Spreader Position";
                    m_part->setPartStatus(PartObject::PartStatus::PART_IS_INVALID);
                    block->setBlockTask(BlockObject::BlockTask::BLOCK_ERROR);

                }
            }

            else if(it->contains(e_expr)){
                block->setLaser_enabled(true);
            }

            ++it;
        }
    }
    return  *block;
}


void GCode_Parser::process_partFile() {
    BlockObject::PositionMode *previous_positionMode = nullptr;
    *previous_positionMode = BlockObject::PositionMode::Position_Absolute;
    uint32_t blockNum = 0;
    uint32_t layerNum = 0;
    QVector<uint32_t> layerFlags;

    QFile partFile(m_part->partFilePath());
    if(partFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream partFileStream(&partFile);
        while(!partFileStream.atEnd()){
            QString part_gLine = partFileStream.readLine();
            if(part_gLine.contains("NEW_LAYER")){
                layerFlags.append(blockNum);
                layerNum++;
            }
            m_blocks->push_back(parse_line(part_gLine, previous_positionMode, blockNum, layerNum));
            blockNum++;
        }
        m_part->setBlocks(*m_blocks);
        m_part->setBlockCount(blockNum);
        m_part->setLayerCount(layerNum);
        m_part->setLayerFlags(layerFlags);
        if((m_status != PARSER_FAILED_INVALID_PART)
                && (m_status != PARSER_FAILED_INVALID_CONFIGURATION)){
            m_status = PARSER_SUCCESS;
        }
    }
    else{
        m_status = PARSER_FAILED_INVALID_PART;
    }

}



