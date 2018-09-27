#include "powder_part.h"
#include <QFile>
#include <QRegExp>
#include <QtDebug>
#include <QTextStream>
#include "hardware_tools/galvo_utility.h"
#include "hardware_tools/zaber_utility.h"
#include "hardware_tools/laser_utility.h"



/* GCODE PARSING & INTERPRETATION
 * ---------------------------------------------------------------------------------------------------
 * ---------------------------------------------------------------------------------------------------
 * The parser and intrepreter implemented in PowderPart and implied throughout PowderApp
 * recognizes a subset of the RepRap Firmware's G-code command language.
 * For an overview, consult: https://reprap.org/wiki/G-code .
 *
 * A. Axis Overview:
 ** --------------------------------------------------------------------------------------------------
 *  "Axis" | "Description"                    | "Notes"
 * ---------------------------------------------------------------------------------------------------
 *  "X"     | "Galvanometer X Axis"           | " Range: Xmin to Xmax, Home: 0 "
 *  "Y"     | "Galvanometer Y Axis"           | " Range: Ymin to Ymax, Home: 0 "
 *  "Z"     | "Build Plate Axis"              | " Range: Zmin to Zmax, Home: 0 "
 *  "A"     | "Hopper Axis"                   | " Range: Amin to Amax, Home: 0 "
 *  "B"     | "Spreader Axis"                 | " Range: Bmin to Bmax, Home: 0 "
 *
 * B. Supported Commands:
 * --------------------------------------------------------------------------------------------------
 *  "G-code" | "Function"                    | "Usage"
 * ---------------------------------------------------------------------------------------------------
 *  "G1"     | "Linear Move"                 | " G1 Xnnn Ynnn Znnn Annn Bnnn Ennn Fnnn Snnn "
 *  "G0"     | "Rapid linear Move"           | " G0 Xnnn Ynnn Znnn Annn Bnnn Ennn Fnnn Snnn "
 * ---------------------------------------------------------------------------------------------------
 *  "G4"**   | "Dwell"                       | " G4 Pnnn " (where nnn is wait time in milliseconds)
 * ---------------------------------------------------------------------------------------------------
 *  "G28"    | "Move to Origin (Home)"       | " G28 " (Home all) or " G28 [Axis] " (Home 1 or more)
 * ---------------------------------------------------------------------------------------------------
 *  "G90"    | "Set to Absolute Positioning" | " G90 " (following commands are absolute coordinate)
 * ---------------------------------------------------------------------------------------------------
 *  "G91"    | "Set to Relative Positioning" | " G91 " (following commands are relative translations)
 * ---------------------------------------------------------------------------------------------------
 *  "F"      | "Set feedrate (speed)"        | " G1 [Axis]mmm... Fnnn " ([Axis] speed set to nnn mm/s)
 * ---------------------------------------------------------------------------------------------------
 *
 * //// TO DO: **Implement dwell timer
 *
 * C. Extensions:
 * ---------------------------------------------------------------------------------------------------
 * 1. Control of the laser is implemented using the OpenSLS extension to RepRap
 *  as summarized in Table A of the appendix to "Open-source Selective Laser
 *  Sintering (OpenSLS) of Nylon and Biocompatible Polycaprolactone."
 *      Ian S. Kinstlinger, Andreas Bastian, Samantha J. Paulsen, Daniel H. Hwang,
 *      Anderson Ta, David R. Yalacki, Tim Schmidt, and Jordan S. Miller.
 *      Department of Bioengineering, Rice University, Houston, Texas, USA.
 *
 *  Table A appears as follows:
 * ---------------------------------------------------------------------------------------------------
 *  "G-code" | "Function"                | "Notes"
 * ---------------------------------------------------------------------------------------------------
 *  "G1"     | "Move while laser firing" | "In unmodified Marlin, G0 and G1 refer
 *  "G0"     | "Move while laer off"     |  to the same action."
 * ---------------------------------------------------------------------------------------------------
 *  "M3"     | "Laser On"                | "A G1 command will fire the laser on its own
 *  "M5"     | "Laser Off"               | and doesnot need to be preceded by an M3 command."
 * ---------------------------------------------------------------------------------------------------
 *  "M649"** | "Modify laser settings"   | "This command takes the format “M649 S# L# P# D# B#”
 *           |                           | S: Intensity of laser firing (0-100.0%)
 *           |                           | L: Duration of firing (in microseconds)
 *           |                           | P: Pulse per mm (in pulse mode)
 *           |                           | D: Diagnostic mode (0 = off; 1 = on)
 *           |                           | B: Laser firing mode (0 = continuous, 1 = pulsed, 2 =raster)
 *           |                           |    "This command can be used to set laser settings before
 *           |                           |    starting to sinter, or to adjust settings during sintering."
 * ---------------------------------------------------------------------------------------------------
 *
 *  ///// TO DO: **-Implement laser controls
 *
 * 2. The Parser can represent a division of the part file into layers by responding to comments
 *    containing a 'new_layer' keyword. Currently this keyword is hard coded to: "NEW_LAYER"
 *
 *  ///// TO DO: -Custom keyword. -Insert custom material delivery routine?
 *
 * D. Options & Configuration
 * ---------------------------------------------------------------------------------------------------
 * The application wide configuration file stored as a PowderSettings object is used by the parser
 * to flag inputs that are out of range. The helper functions used to compose the motion control
 * command strings are also passed a PowderSettings object in order to correctly convert units
 * and route signals using a root/port/deviece/axis hierarchy where each port and device can have
 * multiple devices and ports respectively.
 *
 * E. File Comments
 * ---------------------------------------------------------------------------------------------------
 * The parser recognizes the following comment syntax for the string myComments:
 *  - "(myComments)", "(myComments) Gnn .... ", "Gnn .... (myComments) "
 *  - " ;myComments ", " Gnn ... ; myComments "
 *
 *  Comments are stored along with the full line they occured in a string list m_gcode. They can be
 *  accessed from a PowderPart object using the same index used to access the corresponding block
 *  in the part.
 *
 * F. Rules:
 * ---------------------------------------------------------------------------------------------------
 *  1. LASER CAN BE ENABLED IFF (X OR Y IS MOVING) AND (Z AND A AND B ARE NOT MOVING).**
 *
 *  2. ALL AXIS MOVES MUST FALL WITHIN THE ABSOLUTE COORDINATE SET IN THE CONFIGURATION FILE.
 *
 *  3. ALL SPEEDS MUST FALL WITHIN THE RANGE SET IN THE CONFIGURATION FILE.
 *
 *  Soft Rules and General Limitations:
 *      i. Units:
 *
 *          - Metric units only.
 *
 *      ii. Coordinate Systems
 *
 *          - Single coordinate system.
 *
 *      iii. Axis Groups and Coordinated Motion:
 *
 *        - Easiest illustrated by examples:
 *          " G0 Xnnn Ynnn Znnn Annn Bnnn "
 *          // This is fine.
 *          // XY move executes first, followed by Z, A, and B.
 *          // XY movement is coordinated, and executes together,
 *          // while Z, A, and B are executed sequentially.
 *
 *          " G0 Xnnn Ynnn Fnnn "
 *          // Also fine.
 *          // same as before, but X and Y move at at nnn.
 *
 *          " G0 [Z|A|B]nnn Fnnn "
 *          // Setting a position and speed for SINGLE axis Z OR A OR B is valid.
 *
 *          // However... any combination like this
 *          " G0 Znnn Annn Bnnn Fnnn
 *          // is NO GOOD.
 *
 *        - To generalize:
 *          * The X and Y axis form a "coordinated axis group". When a coordinated axis group
 *            executes a move at a specified speed it is the motion controller, rather than
 *            the application itself that decomposes the speed for each axis in
 *            the group such that the motion between the given coordinates is executed as expected.
 *
 *          * The Z, A, and B axis form a "non-coordinated axis group," and any command addressing
 *            more than one in a single line will be broken up into sequential moves.
 *            (You can also think of the XY group defined above as a single member of this second group)
 *
 *        - The result:
 *          * Commands that specify a single speed for multiple axis in a non-coordinated
 *           group are considered INVALID.
 *
 *        - To justify:
 *          * This greatly simplifies integration with the zaber command syntax.
 *
 *          * For the current implementation, commands that attempt this are not particularly
 *            meaningful, useful, or common. The routines that control the material axis A and B
 *            are expected to be hand written... So break them up into multiple lines please!
 *
 *
 * G. Part Validity and Error Handling:
 * ---------------------------------------------------------------------------------------------------
 *  If the parser encounters any line that breaks any of the above rules, the constructor for
 *  PowderPart will set a flag indicating the issue and continue. A error string can be
 *  accessed after the parser finished. Invalid parts cannot be used to execute a print.
 *
 * E. Example Usage:
 * ---------------------------------------------------------------------------------------------------
 * //// TO DO: Everything!
 *
 * ---------------------------------------------------------------------------------------------------
 * ---------------------------------------------------------------------------------------------------
 */

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


// This is the only constructor for PowderPart that is explicitly called.
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

            // feedrate set by current line

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
            // ignore commented out lines
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

                    // Find G commands
                    if(QRegExp("[Gg]"+regEx_uInt).exactMatch(*data_iterator)){
                        block->clearTask();
                        (*data_iterator).remove(0,1);
                        const int val = (*data_iterator).toInt();

                        switch (val)
                        {
                        case 0:
                        {
                            block->setCommandType(PowderBlock::CommandType::G0_RAPID_MOVE);
                            break;
                        }
                        case 1:
                        {
                            block->setCommandType(PowderBlock::CommandType::G1_LINEAR_MOVE);
                            break;
                        }
                        case 4:
                        {
                            block->setCommandType(PowderBlock::CommandType::G4_DWELL);
                            break;
                        }
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


                    // Find M commands
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
                        case 649: // M649 = MODIFY LASER SETTINGS
                        {
                            block->setCommandType(PowderBlock::CommandType::M649_MODIFY_LASER);
                            break;
                        }
                        default:
                            break;
                        }
                    }


                    // Find S commands (set laser intensity)
                    else if((block->commandType() == PowderBlock::CommandType::M649_MODIFY_LASER)
                            && QRegExp("[S]"+regEx_uInt).exactMatch(*data_iterator)){

                        (*data_iterator).remove(0,1);
                        bool valid;
                        const int value = (*data_iterator).toInt(&valid);

                        if(valid && (value < config->laser_intensity_max()) && (value > config->laser_intensity_min())){
                            block->setLaser_intensity(value);
                        }
                        else
                        {
                            m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
                                           + ", Layer: " + QString::number(layerNum,10)
                                           + " Error: Invalid Laser intensity!");
                            this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
                            block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
                            m_parserStatus= PARSER_FAILED_INVALID_PART;
                        }
                    }


                    // Set Laser Pulse frequency
                    else if((block->commandType() == PowderBlock::CommandType::M649_MODIFY_LASER)
                            && QRegExp("[P]"+regEx_uInt).exactMatch(*data_iterator)){

                        (*data_iterator).remove(0,1);
                        bool valid;
                        const int value = (*data_iterator).toInt(&valid);

                        if(valid && (value < config->laser_pulseFreq_max()) && (value > config->laser_pulseFreq_min())){
                            block->setLaser_pulseFreq(value);
                        }
                        else
                        {
                            m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
                                           + ", Layer: " + QString::number(layerNum,10)
                                           + " Error: Invalid Laser Pulse Frequency!");
                            this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
                            block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
                            m_parserStatus= PARSER_FAILED_INVALID_PART;
                        }
                    }
                    // Set Laser  Mode
                    else if((block->commandType() == PowderBlock::CommandType::M649_MODIFY_LASER)
                            && QRegExp("[B]"+regEx_uInt).exactMatch(*data_iterator)){

                        (*data_iterator).remove(0,1);
                        bool valid;
                        const int value = (*data_iterator).toInt(&valid);

                        if(valid){
                            switch (value) {
                            case 0:
                            {
                                block->setLaserMode(PowderBlock::LaserMode::LASER_PULSED);
                                break;
                            }
                            case 1:
                            {
                                block->setLaserMode(PowderBlock::LaserMode::LASER_CONTINUOUS);
                                break;
                            }
                            default:
                                break;
                            }
                        }
                        else
                        {
                            m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
                                           + ", Layer: " + QString::number(layerNum,10)
                                           + " Error: Invalid Laser Mode!");
                            this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
                            block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
                            m_parserStatus= PARSER_FAILED_INVALID_PART;
                        }
                    }
                    // Find P commands (set a dwell time)
                    else if(block->commandType() == PowderBlock::CommandType::G4_DWELL
                            && QRegExp("[Pp]"+regEx_float).exactMatch(*data_iterator)){
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


//                    // Find F commands (for feed rates)
//                    else if(QRegExp("[Ff]"+regEx_float).exactMatch(*data_iterator)){
//                        (*data_iterator).remove(0,1);

//                        // Set XY Speed iff x and y
//                        if((block->blockTask() == PowderBlock::BlockTask::SET_X_POSITION)
//                                ||(block->blockTask() == PowderBlock::BlockTask::SET_Y_POSITION)
//                                ||(block->blockTask() == (PowderBlock::BlockTask::SET_X_POSITION
//                                                          |PowderBlock::BlockTask::SET_Y_POSITION))){
//                            bool valid;
//                            const float value = (*data_iterator).toFloat(&valid);
//                            if(valid && (value < config->xy_speed_max()) && (value > config->xy_speed_min())){
//                                block->setXY_speed(value);
//                            }
//                            else
//                            {
//                                m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
//                                               + ", Layer: " + QString::number(layerNum,10)
//                                               + " Error: Invalid Galvanometer Speed!");
//                                this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
//                                block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
//                                m_parserStatus= PARSER_FAILED_INVALID_PART;
//                            }
//                        }
//                        // Set Z Speed iff h&s&x&y are NOT moving
//                        else if(block->blockTask() == PowderBlock::BlockTask::SET_Z_POSITION){
//                            bool valid;
//                            const float value = (*data_iterator).toFloat(&valid);
//                            if(valid && (value < config->z_speed_max()) && (value > config->z_speed_min())){
//                                block->setZ_speed(value);
//                            }
//                            else
//                            {
//                                m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
//                                               + ", Layer: " + QString::number(layerNum,10)
//                                               + " Error: Invalid Z Speed!");
//                                this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
//                                block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
//                                m_parserStatus= PARSER_FAILED_INVALID_PART;
//                            }
//                        }
//                        // Set H Speed iff Z&S&X&Y are NOT moving
//                        else if(block->blockTask() == PowderBlock::BlockTask::SET_HOPPER_POSITION){
//                            bool valid;
//                            const float value = (*data_iterator).toFloat(&valid);
//                            if(valid && (value < config->hopper_speed_max()) && (value > config->hopper_speed_min())){
//                                block->setHopper_speed(value);
//                            }
//                            else
//                            {
//                                m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
//                                               + ", Layer: " + QString::number(layerNum,10)
//                                               + " Error: Invalid Hopper Speed!");
//                                this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
//                                block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
//                                m_parserStatus= PARSER_FAILED_INVALID_PART;
//                            }
//                        }
//                        // Set S Speed iff H&S&X&Y are NOT moving
//                        else if(block->blockTask() == PowderBlock::BlockTask::SET_SPREADER_POSITION){
//                            bool valid;
//                            const float value = (*data_iterator).toFloat(&valid);
//                            if(valid && (value < config->spreader_speed_max()) && (value > config->spreader_speed_min())){
//                                block->setSpreader_speed(value);
//                            }
//                            else
//                            {
//                                m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
//                                               + ", Layer: " + QString::number(layerNum,10)
//                                               + " Error: Invalid Spreader Speed!");
//                                this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
//                                block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
//                                m_parserStatus= PARSER_FAILED_INVALID_PART;
//                            }
//                        }
//                        else {
//                            m_errorStr += ("\nBlock: " + QString::number(blockNum,10)
//                                           + ", Layer: " + QString::number(layerNum,10)
//                                           + " Error: Cannot set speed for active axis group");
//                            this->setPartStatus(PowderPart::PartStatus::PART_IS_INVALID);
//                            block->setBlockTask(PowderBlock::BlockTask::BLOCK_ERROR);
//                            m_parserStatus= PARSER_FAILED_INVALID_PART;
//                        }
//                    }

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
                        // only allows the laser to be enabled when the x or y move
                        if(!(block->blockTask()&PowderBlock::BlockTask::SET_Z_POSITION)
                                &&!(block->blockTask()&PowderBlock::BlockTask::SET_HOPPER_POSITION)
                                &&!(block->blockTask()&PowderBlock::BlockTask::SET_SPREADER_POSITION)){
                            QString extruderStr = *data_iterator;
                            // ignore (negative) filament retraction and rapid moves
                            if(!extruderStr.contains("-")
                                    && (block->commandType() == PowderBlock::CommandType::G1_LINEAR_MOVE))
                                block->setLaser_enabled(true);
                        }
                    }
                    ++data_iterator;
                }
            } // end parsing line.

            // generate command strings
            const QStringList laser_strings = LaserUtility::composeCommandString(block);
            block->setLaser_string(laser_strings);
            block->setGalvo_string(GalvoUtility::composeCommandString(block, config.get()));
            const QStringList materialDelivery_strings = ZaberUtility::composeCommandString(block, config.get());
            block->setMaterialDelivery_string(materialDelivery_strings);

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


