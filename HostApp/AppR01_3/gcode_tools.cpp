
#include "gcode_tools.h"


using namespace HARDWARE_NS;


namespace GCODE_BLOCK_NS {


////////////////////////////////////////// BEGIN BLOCK CLASS //////////////////////////////////////////
Block::Block(){
    setBlockValid(false);
    setCode(NO_CODE);
    Hopper()->deactivate_device();
    Spreader()->task = 0x0;
    Spreader()->deactivate_device();
}

Block::Block(const QString &toParse, const POSITION_MODE previousMode, machine_settings_t *settings)
{
    setCode(NO_CODE);
    Laser_Galvo()->task = 0x0;
    Laser_Galvo()->deactivate_device();
    Plate()->task = 0x0;
    Plate()->deactivate_device();
    Hopper()->task = 0x0;
    Hopper()->deactivate_device();
    Spreader()->task = 0x0;
    Spreader()->deactivate_device();
    setBlockValid(true);
    makeBlock(toParse, previousMode, settings);

}

Laser_Galvo_Device *Block::Laser_Galvo(){
    return &m_laser_galvo;
}

Material_Delivery_Device *Block::Plate(){
    return &m_plate;
}

Material_Delivery_Device *Block::Hopper(){
    return &m_hopper;
}

Material_Delivery_Device *Block::Spreader(){
    return &m_spreader;
}


float Block::getDwell() const
{
    return m_dwell;
}

void Block::setDwell(const float dwell)
{
    m_dwell = dwell;
}

CODE Block::getCode() const
{
    return m_code;
}

void Block::setCode(const CODE code)
{
    m_code = code;
}

QString Block::getComments() const
{
    return m_comments;
}

void Block::setComments(const QString &comments)
{
    m_comments = comments;
}

QString Block::getErrors() const
{
    return m_errors;
}

void Block::setErrors(const QString &errors)
{
    m_errors = errors;
}

bool Block::isNewLayer() const
{
    return m_newLayer;
}

void Block::setNewLayer(const bool newLayer)
{
    m_newLayer = newLayer;
}

bool Block::isBlockValid() const
{
    return m_blockValid;
}

void Block::setBlockValid(const bool blockValid)
{
    m_blockValid = blockValid;
}

POSITION_MODE Block::getPreviousMode() const
{
    return m_previousMode;
}

void Block::setPreviousMode(const POSITION_MODE previousMode)
{
    m_previousMode = previousMode;
}

// the juicy bit...
void Block::makeBlock(const QString &toParse, const POSITION_MODE previousMode, machine_settings_t *settings)
{
    setPreviousMode(previousMode);
    Laser_Galvo()->task = 0x0;
    Laser_Galvo()->deactivate_device();
    Laser_Galvo()->set_deviceNumber(settings->l_settings.deviceNumber);
    Laser_Galvo()->laser.set_axisNumber(settings->l_settings.axisNumber);
    Laser_Galvo()->x_axis.set_axisNumber(settings->x_settings.axisNumber);
    Laser_Galvo()->x_axis.set_uStepPerMM(settings->x_settings.uStepPerMM);
    Laser_Galvo()->y_axis.set_axisNumber(settings->y_settings.axisNumber);
    Laser_Galvo()->y_axis.set_uStepPerMM(settings->y_settings.uStepPerMM);


    Plate()->task = 0x0;
    Plate()->deactivate_device();
    Plate()->set_deviceNumber(settings->z_settings.deviceNumber);
    Plate()->set_axisNumber(settings->z_settings.axisNumber);
    Plate()->set_uStepPerMM(settings->z_settings.uStepPerMM);

    Hopper()->task = 0x0;
    Hopper()->deactivate_device();
    Hopper()->set_deviceNumber(settings->a_settings.deviceNumber);
    Hopper()->set_axisNumber(settings->a_settings.axisNumber);
    Hopper()->set_uStepPerMM(settings->a_settings.uStepPerMM);

    Spreader()->task = 0x0;
    Spreader()->deactivate_device();
    Spreader()->set_deviceNumber(settings->b_settings.deviceNumber);
    Spreader()->set_axisNumber(settings->b_settings.axisNumber);
    Spreader()->set_uStepPerMM(settings->b_settings.uStepPerMM);

    setBlockValid(true);
    // BEGIN splitting up comments and commands ///
    QString c_line; // comments
    QString e_line; // errors go here
    QString g_line; // commands go here
    int startComment;
    int endComment;
    int commentSize;
    setNewLayer(false);
    // For safety, always start by setting the laser off flag
    //    L_Axis()->setTask(DISABLE);
    // Ignore empty lines or ones that begin with '/'
    if((toParse.indexOf('/') == 0)||(toParse.size()<2))
    {
        c_line = "Ignored: " + toParse +"\n";
    }
    // deal with (this style) of comment
    else if(toParse.contains('('))
    {
        startComment = toParse.indexOf('(');
        endComment = toParse.indexOf(')');
        if(endComment == -1)
        {
            endComment = toParse.size();
            e_line += "Could not find comment's closing ')'\n";
            setBlockValid(false);
        }
        commentSize = endComment - startComment - 1;
        c_line = toParse.mid(startComment+1,commentSize);
        // check if there is anything else on the line
        if(commentSize == toParse.size()-2)
        {
            g_line.clear();
        }
        else if(startComment == 0)  // someone put a comment before the command
            g_line = toParse.right(toParse.size() - commentSize - 2);   // so pick off the command data
        else    // comment is after the command
            g_line = toParse.left(toParse.size() - commentSize - 2);  // ...
    }
    //  ;Deal with this style of comment.
    else if(toParse.contains(';'))
    {
        startComment = toParse.indexOf(';');
        if(startComment == 0)
        {  // if line starts with ; the rest is a comment
            c_line = toParse.right(toParse.size()-1);
            g_line.clear();
        }
        else
        {   // pick up a comment after a command
            commentSize = toParse.size() - startComment - 1;
            c_line = toParse.right(commentSize);
            g_line = toParse.left(toParse.size() - commentSize - 2);
        }
    }
    else
        g_line = toParse;

    if(c_line.contains("NEW_LAYER"))
        setNewLayer(true);

    c_line += "\n";
    setComments(c_line);
    setErrors(e_line);
    // END splitting up comments and commands //

    if(g_line.size() > 1)
    {
        // Split command into its tokens, seperated by single whitespace
        QStringList tokens = g_line.split(' ', QString::SkipEmptyParts);
        int numTokens = tokens.length();
        for(int i = 0; i < numTokens; i++){

            QString token = tokens[i];

            int firstLetter = token[0].unicode();
            //  First we look at the first character in the word.
            switch (firstLetter)
            {
            // If we find G or M, we have a code command
            case 'G':
            {
                // So setCode with matching enumerated code
                if((token != "G90")||(token != "G91"))
                {
                    Laser_Galvo()->set_positionMode(previousMode);
                    Plate()->set_positionMode(previousMode);
                    Hopper()->set_positionMode(previousMode);
                    Spreader()->set_positionMode(previousMode);
                }
                if(token == "G0") // RAPID MOVE
                    setCode(G0);
                else if(token == "G1")  // LINEAR MOVE
                    setCode(G1);
                else if(token == "G4")  // DWELL (not currently implemented. Use P)
                    setCode(G4);
                else if(token == "G28") // HOME AXIS
                    setCode(G28);
                else if((token == "G90")||(token == "G91"))
                {
                    if(token == "G90")  // ABSOLUTE POSITION
                    {
                        setCode(G90);
                        Laser_Galvo()->set_positionMode(ABSOLUTE);
                        Plate()->set_positionMode(ABSOLUTE);
                        Hopper()->set_positionMode(ABSOLUTE);
                        Spreader()->set_positionMode(ABSOLUTE);
                        setPreviousMode(ABSOLUTE);
                    }
                    else if(token == "G91") // RELATIVE POSITION
                    {
                        setCode(G91);
                        Laser_Galvo()->set_positionMode(RELATIVE);
                        Plate()->set_positionMode(RELATIVE);
                        Hopper()->set_positionMode(RELATIVE);
                        Spreader()->set_positionMode(RELATIVE);
                        setPreviousMode(RELATIVE);
                    }
                }
                else
                {
                    e_line += "Did not recognize command: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;
            }
            case 'M':
            {
                // So setCode with matching enumerated code
                if(token == "M0")   // PAUSE
                    setCode(M0);
                else if(token == "M2")  //  END PROGRAM
                    setCode(M2);
                else if(token == "M3")
                {  // LASER ON
                    setCode(M3);
                    Laser_Galvo()->set_enable_disable(true);
                }
                else if(token == "M5")
                {  // LASER OFF
                    setCode(M5);
                    Laser_Galvo()->set_enable_disable(false);             }
                else
                {
                    e_line += "Did not recognize instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;
            }

                // If the first character is X,Y,Z,A,or B, we are talking about an axis
            case 'X':
            {
                //  Check that a relevant command is requested and set new position
                //  Check if the position is a valid number
                if((getCode() == G0)||(getCode() == G1))
                {
                    bool valueValid = false;
                    float value = token.right(token.size()-1).toFloat(&valueValid);
                    if(valueValid && (value < settings->x_settings.positionMax) && (value > settings->x_settings.positionMin))
                    {
                        Laser_Galvo()->set_x_position(value);
                    }
                    else if(!(value < settings->x_settings.positionMax) || !(value > settings->x_settings.positionMin))
                    {
                        e_line += "X position out of range!\n";
                        setBlockValid(false);

                    }
                    else
                    {
                        e_line += "Invalid number for X position!\n";
                        setBlockValid(false);
                    }
                }
                // No position data means we want to return axis to home
                // check for homing code
                else if((token.size() == 1) && (getCode() == G28)){
                    Laser_Galvo()->x_go_home();
                }
                else
                {
                    e_line += "Did not recognize X instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;
            }

            case 'Y':
            {
                //  Check that a relevant command is requested and set new position
                //  Check if the position is a valid number
                if((getCode() == G0)||(getCode() == G1))
                {
                    bool valueValid = false;
                    float value = token.right(token.size()-1).toFloat(&valueValid);
                    if(valueValid && (value < settings->y_settings.positionMax) && (value > settings->y_settings.positionMin))
                    {
                        Laser_Galvo()->set_y_position(value);
                    }
                    else if(!(value < settings->y_settings.positionMax) || !(value > settings->y_settings.positionMin))
                    {
                        e_line += "Y position out of range!\n";
                        setBlockValid(false);
                    }
                    else
                    {
                        e_line += "Invalid number for Y position!\n";
                        setBlockValid(false);
                    }
                }
                // No position data means we want to return axis to home
                // check for homing code
                else if((token.size() == 1) && (getCode() == G28)){
                    Laser_Galvo()->y_go_home();
                }
                else
                {
                    e_line += "Did not recognize Y instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;
            }

            case 'Z':
            {
                //  Check that a relevant command is requested and set new position
                //  Check if the position is a valid number
                if((getCode() == G0)||(getCode() == G1))
                {
                    bool valueValid = false;
                    float value = token.right(token.size()-1).toFloat(&valueValid);
                    if(valueValid && (value < settings->z_settings.positionMax) && (value > settings->z_settings.positionMin))
                    {
                        Plate()->set_position(value);
                    }
                    else if(!(value < settings->z_settings.positionMax) || !(value > settings->z_settings.positionMin))
                    {
                        e_line += "Z position out of range!\n";
                        setBlockValid(false);

                    }
                    else
                    {
                        e_line += "Invalid number for Z position!\n";
                        setBlockValid(false);
                    }
                }
                // No position data means we want to return axis to home
                // check for homing code
                else if((token.size() == 1) && (getCode() == G28)){
                    Plate()->go_home();
                }
                else
                {
                    e_line += "Did not recognize Z instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;
            }

            case 'A':
            {
                //  Check that a relevant command is requested and set new position
                //  Check if the position is a valid number
                if((getCode() == G0)||(getCode() == G1))
                {
                    bool valueValid = false;
                    float value = token.right(token.size()-1).toFloat(&valueValid);
                    if(valueValid && (value < settings->a_settings.positionMax) && (value > settings->a_settings.positionMin))
                    {
                        Hopper()->set_position(value);
                    }
                    else if(!(value < settings->a_settings.positionMax) || !(value > settings->a_settings.positionMin))
                    {
                        e_line += "A position out of range!\n";
                        setBlockValid(false);
                    }
                    else
                    {
                        e_line += "Invalid number for A position!\n";
                        setBlockValid(false);
                    }
                }
                // No position data means we want to return axis to home
                // check for homing code
                else if((token.size() == 1) && (getCode() == G28)){
                    Hopper()->go_home();
                }
                else
                {
                    e_line += "Did not recognize A instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;
            }

            case 'B':
            {
                //  Check that a relevant command is requested and set new position
                //  Check if the position is a valid number
                if((getCode() == G0)||(getCode() == G1))
                {
                    bool valueValid = false;
                    float value = token.right(token.size()-1).toFloat(&valueValid);
                    if(valueValid && (value < settings->b_settings.positionMax) && (value > settings->b_settings.positionMin))
                    {
                        Spreader()->set_position(value);
                    }
                    else if(!(value < settings->b_settings.positionMax) || !(value > settings->b_settings.positionMin))
                    {
                        e_line += "B position out of range!\n";
                        setBlockValid(false);

                    }
                    else
                    {
                        e_line += "Invalid number for B position!\n";
                        setBlockValid(false);
                    }
                }
                // No position data means we want to return axis to home
                // check for homing code
                else if((token.size() == 1) && (getCode() == G28)){
                    Spreader()->go_home();
                }
                else
                {
                    e_line += "Did not recognize B instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;
            }

                // E used to indicate the current movement corresponds to an active print command.
                // This follows from the extrusion printer convention. Where E is used to control
                // the amount of material extruded. In our cases, we simpply check if a line contains
                // 'E'. This means we should turn the laser on.
            case 'E':
            {
                // check that there is an XY move
                if(getCode() == G1)
                {
                    Laser_Galvo()->set_enable_disable(true);
                }
                else if(getCode() != G1)
                {
                    e_line += "Laser can only be enabled during linear movement. Use G1 not G0\n";
                    setBlockValid(false);
                }
                else
                {
                    e_line += "Laser could not be enabled\n";
                    setBlockValid(false);
                }
                break;
            }

                // F used to modify speed. We only want to set the speed for an axis we intend
                // to move with this block, so check to see if each axis has a pending move.
            case 'F':
            {
                bool valueValid = false;
                float value = token.right(token.size()-1).toFloat(&valueValid);
                if(valueValid)
                {
                    // Find the correct axis to modify
                    if(((Laser_Galvo()->task) & (static_cast<uint8_t>(CHANGE_LG_X_POSITION)))||((Laser_Galvo()->task) & (static_cast<uint8_t>(CHANGE_LG_Y_POSITION))))
                    {
                        if((value < settings->x_settings.speedMax) && (value > settings->x_settings.speedMin))
                        {
                            Laser_Galvo()->set_speed(value);
                        }
                        else
                        {
                            e_line += "Galvo speed out of range.\n";
                            setBlockValid(false);
                        }
                    }

                    if((Plate()->task) & (static_cast<uint8_t>(CHANGE_MD_POSITION)))
                    {
                        if((value < settings->z_settings.speedMax) && (value > settings->z_settings.speedMin))
                        {
                            Plate()->set_speed(value);
                        }
                        else
                        {
                            e_line += "Z speed out of range.\n";
                            setBlockValid(false);
                        }
                    }

                    if((Hopper()->task) & (static_cast<uint8_t>(CHANGE_MD_POSITION)))
                    {
                        if((value < settings->a_settings.speedMax) && (value > settings->a_settings.speedMin))
                        {
                            Plate()->set_speed(value);
                        }
                        else
                        {
                            e_line += "Z speed out of range.\n";
                            setBlockValid(false);
                        }
                    }

                    if((Spreader()->task) & (static_cast<uint8_t>(CHANGE_MD_POSITION)))
                    {
                        if((value < settings->b_settings.speedMax) && (value > settings->b_settings.speedMin))
                        {
                            Plate()->set_speed(value);
                        }
                        else
                        {
                            e_line += "Z speed out of range.\n";
                            setBlockValid(false);
                        }
                    }

                }
                else
                {
                    e_line += "Did not recognize speed instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;
            }

                // P signals a dwell time is to be set and observed.
            case 'P':
            {
                bool valueValid = false;
                float value = token.right(token.size()-1).toFloat(&valueValid);
                if(valueValid)
                    setDwell(value);
                else
                {
                    e_line += "Did not recognize dwell instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }

                break;
            }

                // S used to modify laser power.
            case 'S':
            {
                bool valueValid = false;
                float value = token.right(token.size()-1).toFloat(&valueValid);
                if(valueValid)
                {
                    Laser_Galvo()->set_power(value);
                }
                else
                {
                    e_line += "Did not recognize laser power instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;
            }

            default:
            {
                e_line += "Did not recognize instruction: \""+token+"\"\n";
                setBlockValid(false);
            }
                break;
            } //end switch
        }//end token
    }//end if
    setErrors(e_line);

    if(isBlockValid())
    {
        Laser_Galvo()->make_commandString();
        Plate()->make_commandString();
        Hopper()->make_commandString();
        Spreader()->make_commandString();
    }
}
////////////////////////////////////////// END BLOCK CLASS //////////////////////////////////////////


////////////////////////////////////////// BEGIN LAYER CLASS //////////////////////////////////////////
Layer::Layer(){
    setLayerValid(false);
}

Layer::Layer(const QVector<Block> &someBlocks){
    setLayerValid(true);
    m_layer = someBlocks;
}

QVector<Block> Layer::get() const
{
    return m_layer;
}

void Layer::setLayerValid(const bool layerValid){
    m_layerValid = layerValid;
}

bool Layer::validateLayer()
{
    setLayerValid(true);
    for(int i = 0; i < m_layer.size(); i++)
    {
        if(m_layer[i].isBlockValid() == false)
            setLayerValid(false);
    }
    return isLayerValid();
}

void Layer::clearLayer()
{
    m_layer.clear();
}

Block Layer::getBlock(const int blockNumber) const
{
    return m_layer.at(blockNumber);
}

void Layer::addBlock(const Block &aBlock)
{
    if(aBlock.isBlockValid() == false)
        setLayerValid(false);
    m_layer.append(aBlock);
}

bool Layer::isLayerValid() const
{
    return m_layerValid;
}
////////////////////////////////////////// END LAYER CLASS //////////////////////////////////////////


////////////////////////////////////////// BEGIN PART CLASS //////////////////////////////////////////
Part::Part(QString &fileName, machine_settings_t *settings){
    m_fileName = fileName;
    m_settings = settings;
    makePart();
}

bool Part::isPartValid() const
{
    return m_partValid;
}

void Part::validatePart()
{
    m_partValid = true;
    for(int i = 0; i < m_part.size(); i++)
    {
        if(m_part[i].validateLayer() == false)
            m_partValid = false;
    }
}



QString Part::displayBlock(Block &aBlock, const bool errorOnly)
{
    QString blockString;
    if(aBlock.isBlockValid() == true)
        blockString = "Valid Block\n";
    if(aBlock.isBlockValid() == false)
        blockString = "Error: invalid Block\n";

    if(!errorOnly)
    {
        if(aBlock.getCode() != NO_CODE)
        {
            blockString += "  Gcode Command: ";
            switch (aBlock.getCode()) {
            case M0:
                blockString += "M0 - PROGRAM PAUSE\n";
                break;
            case M2:
                blockString += "M2- END PROGRAM\n";
                break;
            case M3:
                blockString += "M3 - LASER ON\n";
                break;
            case M5:
                blockString += "M3 - LASER OFF\n";
                break;
            case G0:
                blockString += "G0 - RAPID MOVE\n";
                break;
            case G1:
                blockString += "G1 - LINEAR MOVE\n";
                break;
            case G4:
                blockString += ("G4 - DWELL: " + QString::number(aBlock.getDwell()) + "\n");
                break;
            case G28:
                blockString += "G28 - HOME AXIS\n";
                break;
            case G90:
                blockString += "G90 - ABSOLUTE MODE\n";
                break;
            case G91:
                blockString += "G91 - RELATIVE MODE\n";
                break;
            default:
                blockString += "  Unrecognized Gcode.\n";

                break;
            }
        }

        if(aBlock.Laser_Galvo()->is_deviceActive())
            blockString += "\n Laser & Galvo: " + aBlock.Laser_Galvo()->get_deviceString();

        if(aBlock.Plate()->is_deviceActive())
            blockString += "\n Build Plate: " + aBlock.Plate()->get_deviceString();

        if(aBlock.Hopper()->is_deviceActive())
            blockString += "\n Hopper: " + aBlock.Hopper()->get_deviceString();

        if(aBlock.Spreader()->is_deviceActive())
            blockString += "\n Spreader: " + aBlock.Spreader()->get_deviceString();

        if(aBlock.getComments().size() > 1)
            blockString += ("Comments: " + aBlock.getComments() + "\n");
        if(aBlock.getErrors().size() > 1)
            blockString += ("Errors: " + aBlock.getErrors() + "\n");
    }
    else
    {
        if(aBlock.getErrors().size() > 1)
            blockString += ("Errors: " + aBlock.getErrors() + "\n");
    }
    return (blockString +"\n");
}

QStringList Part::debugPart(const bool errorOnly)
{
    QStringList debugOut;
    int numLayer = m_part.size();
    int numLines = 0;
    for(int i = 0; i < numLayer; i++) //
    {
        QString layerString = "\n*//////////* Begin Layer " + QString::number(i) +" *//////////*\n";
        for(int j = 0; j < m_part[i].get().size(); j++)
        {
            layerString += "\n************ Layer " + QString::number(i) + ", Block " + QString::number(numLines + j) + " ************\n";
            Block tempBlock = m_part[i].getBlock(j);
            QString blockStringDisplay = displayBlock(tempBlock, errorOnly);
            layerString += displayBlock(tempBlock, errorOnly);

        }
        numLines += m_part[i].get().size();
        layerString += "*//////////* End Layer " + QString::number(i) +" *//////////*\n\n";
        debugOut<<layerString;
    }
    if(isPartValid()==true)
        debugOut.prepend("Valid");
    else
        debugOut.prepend("Part contains errors!");

    debugOut.prepend(QString::number(numLayer));
    debugOut.prepend(QString::number(numLines));
    debugOut.prepend(m_fileName + "\n");

    return debugOut;
}


void Part::makePart()
{
    blockCount = 0;
    layerCount = 0;

    QFile file(m_fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        POSITION_MODE lastMode = ABSOLUTE;
        Layer tempLayer;
        QTextStream in(&file);
        while (!in.atEnd())
        {
            bool layerFlag = false;
            QString line = in.readLine();

            Block tempBlock(line, lastMode, m_settings);
            layerFlag = tempBlock.isNewLayer();
            lastMode = tempBlock.getPreviousMode();

            if(layerFlag == false){
                tempLayer.addBlock(tempBlock);
                blockCount++;
            }
            else if(layerFlag == true)
            {
                addLayer(tempLayer);
                tempLayer.clearLayer();
            }
        }

        file.close();
        validatePart();
    }
    else
        qDebug()<<"Could not open file";
}

void Part::addLayer(const Layer &aLayer)
{
    m_part.append(aLayer);
    layerCount++;
}

QVector<Layer> Part::get() const
{
    return m_part;
}

Layer Part::getLayer(const int layerNumber) const
{
    return m_part[layerNumber];
}

Block Part::getBlock(const int LayerNumber, const int blockNumber)
{
    return m_part[LayerNumber].getBlock(blockNumber);
}

int Part::get_BlockCount(){
    return blockCount;
}

int Part::get_LayerCount(){
    return blockCount;
}
////////////////////////////////////////// END PART CLASS //////////////////////////////////////////
}


