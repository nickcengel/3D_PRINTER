
#include "blockio.h"

namespace BlockIO {

Message::Message()
{
    map = NONE;
    float data0 = 0;
    float data1 = 0;
}

Message::Message(const Tasks aMap)
{
    map = aMap;
    data0 = 0;
    data1 = 0;
}

Message::Message(const Tasks aMap, const float d0)
{
    map = aMap;
    data0 = d0;
    data1 = 0;

}

Message::Message(const Tasks aMap, const float d0, const float d1)
{
    map = aMap;
    data0 = d0;
    data1 = d1;
}

Tasks Message::task() const
{
    return map;
}

float Message::D0() const
{
    return data0;
}

float Message::D1() const
{
    return data1;
}

void Message::set(const Tasks aMap)
{
    map = aMap;
}

void Message::set(const Tasks aMap, const float d0)
{
    map = aMap;
    data0 = d0;
}

void Message::set(const Tasks aMap, const float d0, const float d1)
{
    map = aMap;
    data0 = d0;
    data1 = d1;
}

void Message::setTask(const Tasks aMap)
{
    map = aMap;
}

void Message::setD0(const float d0)
{
    data0 = d0;
}

void Message::setD1(const float d1)
{
    data1 = d1;
}


MD_Package::MD_Package()
{
    m_map = MD_NONE;
    m_buildPlate_message.setTask(NONE);
    m_hopperPlate_message.setTask(NONE);
    m_spreadBlade_message.setTask(NONE);
}


MD_Package::MD_Package(MD_Map channel, Message message0)
{
    m_map = channel;
    switch (m_map) {
    case MD_Map::BUILD_PLATE:
        m_buildPlate_message = message0;
        break;
    case MD_Map::HOPPPER_PLATE:
        m_hopperPlate_message = message0;
        break;
    case MD_Map::SPREAD_BLADE:
        m_spreadBlade_message = message0;
        break;
    default:
        break;
    }
}

MD_Package::MD_Package(MD_Map channel, Message message0, Message message1)
{
    m_map = channel;
    switch (m_map) {
    case MD_Map::BUILD_HOPPER:
        m_buildPlate_message = message0;
        m_hopperPlate_message = message1;
        break;
    case MD_Map::BUILD_SPREAD:
        m_buildPlate_message = message0;
        m_spreadBlade_message = message1;
        break;
    case MD_Map::HOPPER_SPREAD:
        m_hopperPlate_message = message0;
        m_spreadBlade_message = message1;
        break;
    default:
        break;
    }
}

MD_Package::MD_Package(Message buildPlate_msg, Message hopperPlate_msg, Message spreadBlade_msg)
{
    m_buildPlate_message = buildPlate_msg;
    m_hopperPlate_message = hopperPlate_msg;
    m_spreadBlade_message = spreadBlade_msg;
    if(m_buildPlate_message.task() != NONE)
    {
        m_map = BUILD_PLATE;
    }
    if(m_hopperPlate_message.task() != NONE)
    {
        if(m_map == BUILD_PLATE)
            m_map = BUILD_HOPPER;
        else
            m_map = HOPPPER_PLATE;
    }
    if(m_spreadBlade_message.task() != NONE)
    {
        if(m_map == BUILD_PLATE)
            m_map = BUILD_SPREAD;
        else if(m_map == HOPPPER_PLATE)
            m_map = HOPPER_SPREAD;
        else if(m_map == BUILD_HOPPER)
            m_map = MD_ALL;
        else
            m_map = SPREAD_BLADE;
    }
}

Message *MD_Package::buildPlate_message()
{
    return &m_buildPlate_message;
}

Message *MD_Package::hopperPlate_message()
{
    return &m_hopperPlate_message;
}

Message *MD_Package::spreadBlade_message()
{
    return &m_spreadBlade_message;
}

void MD_Package::setMap()
{
    m_map = MD_NONE;
    if(m_buildPlate_message.task() != NONE)
    {
        m_map = BUILD_PLATE;
    }
    if(m_hopperPlate_message.task() != NONE)
    {
        if(m_map == BUILD_PLATE)
            m_map = BUILD_HOPPER;
        else
            m_map = HOPPPER_PLATE;
    }
    if(m_spreadBlade_message.task() != NONE)
    {
        if(m_map == BUILD_PLATE)
            m_map = BUILD_SPREAD;
        else if(m_map == HOPPPER_PLATE)
            m_map = HOPPER_SPREAD;
        else if(m_map == BUILD_HOPPER)
            m_map = MD_ALL;
        else
            m_map = SPREAD_BLADE;
    }
}

MD_Map MD_Package::getMap()
{
    if(m_map == MD_NONE)
        setMap();
    return m_map;
}


LG_Package::LG_Package()
{
    m_map = LG_NONE;
    m_x_message.setTask(NONE);
    m_y_message.setTask(NONE);
    m_laser_message.setTask(NONE);
}

LG_Package::LG_Package(LG_Map channel, Message message0)
{
    m_map = channel;
    switch (m_map) {
    case LG_Map::X_ONLY:
        m_x_message = message0;
        break;
    case LG_Map::Y_ONLY:
        m_y_message = message0;
        break;
    case LG_Map::LASER_ONLY:
        m_laser_message = message0;
        break;
    default:
        break;
    }
}

LG_Package::LG_Package(LG_Map channel, Message message0, Message message1)
{
    m_map = channel;
    switch (m_map) {
    case LG_Map::X_Y:
        m_x_message = message0;
        m_y_message = message1;
        break;
    case LG_Map::X_LASER:
        m_x_message = message0;
        m_laser_message = message1;
        break;
    case LG_Map::Y_LASER:
        m_y_message = message0;
        m_laser_message = message1;
        break;
    default:
        break;
    }
}

LG_Package::LG_Package(Message x_msg, Message y_msg, Message laser_msg)
{
    m_x_message = x_msg;
    m_y_message = y_msg;
    m_laser_message = laser_msg;
    if(m_x_message.task() != NONE)
    {
        m_map = X_ONLY;
    }
    if(m_y_message.task() != NONE)
    {
        if(m_map == X_ONLY)
            m_map = X_Y;
        else
            m_map = Y_ONLY;
    }
    if(m_laser_message.task() != NONE)
    {
        if(m_map == X_ONLY)
            m_map = X_LASER;
        else if(m_map == Y_ONLY)
            m_map = Y_LASER;
        else if(m_map == X_Y)
            m_map = LG_ALL;
        else
            m_map = LASER_ONLY;
    }
}

Message *LG_Package::x_message()
{
    return &m_x_message;
}

Message *LG_Package::y_message()
{
    return &m_y_message;
}

Message *LG_Package::laser_message()
{
    return &m_laser_message;
}

void LG_Package::setMap()
{
    m_map = LG_NONE;

    if(m_x_message.task() != NONE)
    {
        m_map = X_ONLY;
    }
    if(m_y_message.task() != NONE)
    {
        if(m_map == X_ONLY)
            m_map = X_Y;
        else
            m_map = Y_ONLY;
    }
    if(m_laser_message.task() != NONE)
    {
        if(m_map == X_ONLY)
            m_map = X_LASER;
        else if(m_map == Y_ONLY)
            m_map = Y_LASER;
        else if(m_map == X_Y)
            m_map = LG_ALL;
        else
            m_map = LASER_ONLY;
    }
}

LG_Map LG_Package::getMap()
{
    if(m_map == LG_NONE)
        setMap();
    return m_map;
}


////////////////////////////////////////// BEGIN BLOCK CLASS //////////////////////////////////////////
Block::Block(){
   setBlockValid(false);
   setCode(NO_CODE);
}

Block::Block(const QString toParse, machine_settings_t *settings)
{
    setCode(NO_CODE);
    setBlockValid(true);
    makeBlock(toParse, settings);
}

float Block::dwell() const
{
    return m_dwell;
}

void Block::setDwell(const float d)
{
    m_dwell = d;
}

bool Block::newLayerFlag() const
{
    return m_newLayer;
}

void Block::setNewLayer(bool flag)
{
    m_newLayer = flag;
}

bool Block::isBlockValid() const
{
    return m_blockValid;
}

void Block::setBlockValid(bool valid)
{
    m_blockValid = valid;
}

Code Block::code() const
{
    return m_code;
}

void Block::setCode(const Code &code)
{
    m_code = code;
}

QString Block::com_err() const
{
    return m_com_err;
}

void Block::set_com_err(const QString &value)
{
    m_com_err = value;
}

MD_Package *Block::materialDelivery()
{
    return &m_materialDelivery;
}

LG_Package *Block::laserGalvo()
{
    return &m_laserGalvo;
}


// the juicy bit...
void Block::makeBlock(const QString toParse, machine_settings_t *settings)
{
    setBlockValid(true);
    // BEGIN splitting up comments and commands ///
    QString c_line; // comments and errors go here
    QString g_line; // commands go here
    int startComment;
    int endComment;
    int commentSize;
    setNewLayer(false);
    // For safety, always start by setting the laser off flag
    laserGalvo()->laser_message()->set(DISABLE);
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
            c_line += "Could not find comment's closing ')'\n";
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
    set_com_err(c_line);
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
                if(token == "G0") // RAPID MOVE
                    setCode(G0);
                else if(token == "G1")  // LINEAR MOVE
                    setCode(G1);
                else if(token == "G4")  // DWELL (not currently implemented. Use P)
                    setCode(G4);
                else if(token == "G28") // HOME AXIS
                    setCode(G28);
                else if(token == "G90")  // ABSOLUTE POSITION
                {
                    setCode(G90);
                    laserGalvo()->x_message()->set(RELATIVE,0);
                    laserGalvo()->y_message()->set(RELATIVE,0);

                    materialDelivery()->buildPlate_message()->set(RELATIVE,0);
                    materialDelivery()->hopperPlate_message()->set(RELATIVE,0);
                    materialDelivery()->spreadBlade_message()->set(RELATIVE,0);
                }
                else if(token == "G91") // RELATIVE POSITION
                {
                    setCode(G91);
                    laserGalvo()->x_message()->set(RELATIVE,1);
                    laserGalvo()->y_message()->set(RELATIVE,1);

                    materialDelivery()->buildPlate_message()->set(RELATIVE,1);
                    materialDelivery()->hopperPlate_message()->set(RELATIVE,1);
                    materialDelivery()->spreadBlade_message()->set(RELATIVE,1);
                }
                else
                {
                    c_line += "Did not recognize command: \""+token+"\"\n";
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
                    laserGalvo()->laser_message()->set(ENABLE,1);
                }
                else if(token == "M5")
                {  // LASER OFF
                    setCode(M5);
                    laserGalvo()->laser_message()->set(ENABLE,0);                }
                else
                {
                    c_line += "Did not recognize instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;
            }

                // If the first character is X,Y,Z,A,or B, we are talking about an axis
            case 'X':
            {
                //  Check that a relevant command is requested and set new position
                //  Check if the position is a valid number
                if((code() == G0)||(code() == G1))
                {
                    bool valueValid = false;
                    float value = token.right(token.size()-1).toFloat(&valueValid);
                    if(valueValid && (value < settings->x_settings.positionMax) && (value > settings->x_settings.positionMin))
                        laserGalvo()->x_message()->set(POSITION,value);
                    else if(!(value < settings->x_settings.positionMax) || !(value > settings->x_settings.positionMin))
                    {
                        c_line += "X position out of range!\n";
                        setBlockValid(false);

                    }
                    else
                    {
                        c_line += "Invalid number for X position!\n";
                        setBlockValid(false);
                    }
                }
                // No position data means we want to return axis to home
                // check for homing code
                else if((token.size() == 1) && (code() == G28))
                    laserGalvo()->x_message()->set(HOME,1);
                else
                {
                    c_line += "Did not recognize X instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;
            }

            case 'Y':
            {
                //  Check that a relevant command is requested and set new position
                //  Check if the position is a valid number
                if((code() == G0)||(code() == G1))
                {
                    bool valueValid = false;
                    float value = token.right(token.size()-1).toFloat(&valueValid);
                    if(valueValid && (value < settings->y_settings.positionMax) && (value > settings->y_settings.positionMin))
                        laserGalvo()->y_message()->set(POSITION,value);
                    else if(!(value < settings->y_settings.positionMax) || !(value > settings->y_settings.positionMin))
                    {
                        c_line += "Y position out of range!\n";
                        setBlockValid(false);
                    }
                    else
                    {
                        c_line += "Invalid number for Y position!\n";
                        setBlockValid(false);
                    }
                }
                // No position data means we want to return axis to home
                // check for homing code
                else if((token.size() == 1) && (code() == G28))
                    laserGalvo()->y_message()->set(HOME,1);
                else
                {
                    c_line += "Did not recognize Y instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;
            }

            case 'Z':
            {
                //  Check that a relevant command is requested and set new position
                //  Check if the position is a valid number
                if((code() == G0)||(code() == G1))
                {
                    bool valueValid = false;
                    float value = token.right(token.size()-1).toFloat(&valueValid);
                    if(valueValid && (value < settings->z_settings.positionMax) && (value > settings->z_settings.positionMin))
                        materialDelivery()->buildPlate_message()->set(POSITION,value);
                    else if(!(value < settings->z_settings.positionMax) || !(value > settings->z_settings.positionMin))
                    {
                        c_line += "Z position out of range!\n";
                        setBlockValid(false);

                    }
                    else
                    {
                        c_line += "Invalid number for Z position!\n";
                        setBlockValid(false);
                    }
                }
                // No position data means we want to return axis to home
                // check for homing code
                else if((token.size() == 1) && (code() == G28))
                     materialDelivery()->buildPlate_message()->set(HOME,1);
                else
                {
                    c_line += "Did not recognize Z instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;
            }

            case 'A':
            {
                //  Check that a relevant command is requested and set new position
                //  Check if the position is a valid number
                if((code() == G0)||(code() == G1))
                {
                    bool valueValid = false;
                    float value = token.right(token.size()-1).toFloat(&valueValid);
                    if(valueValid && (value < settings->a_settings.positionMax) && (value > settings->a_settings.positionMin))
                        materialDelivery()->hopperPlate_message()->set(POSITION,value);
                    else if(!(value < settings->a_settings.positionMax) || !(value > settings->a_settings.positionMin))
                    {
                        c_line += "A position out of range!\n";
                        setBlockValid(false);
                    }
                    else
                    {
                        c_line += "Invalid number for A position!\n";
                        setBlockValid(false);
                    }
                }
                // No position data means we want to return axis to home
                // check for homing code
                else if((token.size() == 1) && (code() == G28))
                     materialDelivery()->hopperPlate_message()->set(HOME,1);
                else
                {
                    c_line += "Did not recognize A instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;
            }

            case 'B':
            {
                //  Check that a relevant command is requested and set new position
                //  Check if the position is a valid number
                if((code() == G0)||(code() == G1))
                {
                    bool valueValid = false;
                    float value = token.right(token.size()-1).toFloat(&valueValid);
                    if(valueValid && (value < settings->b_settings.positionMax) && (value > settings->b_settings.positionMin))
                        materialDelivery()->spreadBlade_message()->set(POSITION,value);
                    else if(!(value < settings->b_settings.positionMax) || !(value > settings->b_settings.positionMin))
                    {
                        c_line += "B position out of range!\n";
                        setBlockValid(false);

                    }
                    else
                    {
                        c_line += "Invalid number for B position!\n";
                        setBlockValid(false);
                    }
                }
                // No position data means we want to return axis to home
                // check for homing code
                else if((token.size() == 1) && (code() == G28))
                    materialDelivery()->spreadBlade_message()->set(HOME,1);
                else
                {
                    c_line += "Did not recognize B instruction: \""+token+"\"\n";
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
                if(isBlockValid() && (code() == G1)
                        && ((laserGalvo()->x_message()->task() == POSITION) || (laserGalvo()->x_message()->task() == POSITION_SPEED))
                        && ((laserGalvo()->y_message()->task() == POSITION) || (laserGalvo()->y_message()->task() == POSITION_SPEED))
                        && ((materialDelivery()->buildPlate_message()->task() != POSITION) && (materialDelivery()->buildPlate_message()->task() != POSITION_SPEED))
                        && ((materialDelivery()->hopperPlate_message()->task() != POSITION) && (materialDelivery()->hopperPlate_message()->task() != POSITION_SPEED))
                        && ((materialDelivery()->spreadBlade_message()->task() != POSITION) && (materialDelivery()->spreadBlade_message()->task() != POSITION_SPEED)))
                {
                    laserGalvo()->laser_message()->set(ENABLE,1);
                }
                else if(code() != G1)
                {
                    c_line += "Laser can only be enabled during linear movement. Use G1 not G0\n";
                    setBlockValid(false);
                }
                else if((laserGalvo()->x_message()->task() != POSITION) || (laserGalvo()->x_message()->task() != POSITION_SPEED)
                      ||(laserGalvo()->y_message()->task() != POSITION) || (laserGalvo()->y_message()->task() != POSITION_SPEED))
                {
                    c_line += "Laser can only be enbabled in connection with a move in the X or Y axis.\n";
                    setBlockValid(false);
                }
                else
                {
                    c_line += "Laser could not be enabled\n";
                    // setBlockValid(false);
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
                // Find the correct axis to modify. change its task and add d1 to represent speed
                    if(laserGalvo()->x_message()->task() == POSITION)
                    {
                        if((value < settings->x_settings.speedMax) && (value > settings->x_settings.speedMin))
                        {

                            laserGalvo()->x_message()->setTask(POSITION_SPEED);
                            laserGalvo()->x_message()->setD1(value);
                        }
                        else
                        {
                            c_line += "X speed out of range.\n";
                            setBlockValid(false);
                        }
                    }

                    if(laserGalvo()->y_message()->task() == POSITION)
                    {
                        if((value < settings->y_settings.speedMax) && (value > settings->y_settings.speedMin))
                        {
                            laserGalvo()->y_message()->setTask(POSITION_SPEED);
                            laserGalvo()->y_message()->setD1(value);
                        }
                        else
                        {
                            c_line += "Y speed out of range.\n";
                            setBlockValid(false);
                        }
                    }

                    if(materialDelivery()->buildPlate_message()->task() == POSITION)
                    {
                        if((value < settings->z_settings.speedMax) && (value > settings->z_settings.speedMin))
                        {
                            materialDelivery()->buildPlate_message()->setTask(POSITION_SPEED);
                            materialDelivery()->buildPlate_message()->setD1(value);
                        }
                        else
                        {
                            c_line += "Z speed out of range.\n";
                            setBlockValid(false);
                        }
                    }

                    if(materialDelivery()->hopperPlate_message()->task() == POSITION)
                    {
                        if((value < settings->a_settings.speedMax) && (value > settings->a_settings.speedMin))
                        {
                            materialDelivery()->hopperPlate_message()->setTask(POSITION_SPEED);
                            materialDelivery()->hopperPlate_message()->setD1(value);
                        }
                        else
                        {
                            c_line += "A speed out of range.\n";
                            setBlockValid(false);
                        }
                    }

                    if(materialDelivery()->spreadBlade_message()->task() == POSITION)
                    {
                        if((value < settings->b_settings.speedMax) && (value > settings->b_settings.speedMin))
                        {
                            materialDelivery()->spreadBlade_message()->setTask(POSITION_SPEED);
                            materialDelivery()->spreadBlade_message()->setD1(value);
                        }
                        else
                        {
                            c_line += "B speed out of range.\n";
                            setBlockValid(false);
                        }
                    }

                }
                else
                {
                    c_line += "Did not recognize speed instruction: \""+token+"\"\n";
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
                    c_line += "Did not recognize dwell instruction: \""+token+"\"\n";
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
                    if(laserGalvo()->laser_message()->task() == ENABLE)
                        laserGalvo()->laser_message()->set(POWER,1,value);
                    else
                        laserGalvo()->laser_message()->set(POWER,0,value);
                }
                else
                {
                    c_line += "Did not recognize laser power instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;
            }

            default:
            {
                c_line += "Did not recognize instruction: \""+token+"\"\n";
                setBlockValid(false);
            }
                break;
            } //end switch
        }//end token
        set_com_err(c_line);
    }//end if
    set_com_err(c_line);
    laserGalvo()->setMap();
    materialDelivery()->setMap();
}
////////////////////////////////////////// END BLOCK CLASS //////////////////////////////////////////


////////////////////////////////////////// BEGIN LAYER CLASS //////////////////////////////////////////
Layer::Layer(){
    setLayerValid(false);
}

Layer::Layer(QVector<Block> someBlocks){
    setLayerValid(true);
    m_layer = someBlocks;
}

QVector<Block> Layer::get() const
{
    return m_layer;
}

void Layer::setLayerValid(bool layerValid){
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

Block Layer::getBlock(int blockNumber) const
{
    return m_layer.at(blockNumber);
}

void Layer::addBlock(Block aBlock)
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
Part::Part(QString fileName, machine_settings_t *settings){
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

QString Part::displayAxis(QChar axisTitle, Message axis)
{
    QString axisString = "---------- ";
            axisString += (QString)axisTitle;
            axisString += " AXIS ----------\n";
    switch (axis.task()) {
    case POSITION:
        axisString += ("  Position: " + QString::number(axis.D0()) + "\n");
        break;
    case POSITION_SPEED:
        axisString += ("  Position: " + QString::number(axis.D0()) + "\n");
        axisString += ("  Speed: " + QString::number(axis.D0()) + "\n");
        break;
    case HOME:
        if(axis.D0() != 0)
            axisString += "  Axis executes HOME command.\n";
        break;
    case RELATIVE:
        axisString += "  Relative motion instructions to follow.\n";
        break;
    case ABSOLUTE:
        axisString += "  Absolutie motion instructions to follow\n";
        break;
    case ENABLE:
        axisString += "Axis enabled.\n";
        break;
    case DISABLE:
        axisString += "Axis disabled.\n";
        break;
    case NONE:
        axisString += "  No task assigned.\n";
        break;
    default:
        axisString += "  Did not recognize Axis task.\n";
        break;
    }
    return axisString;
}

QString Part::displayBlock(Block aBlock, bool errorOnly)
{
    QString blockString;
    if(aBlock.isBlockValid() == true)
        blockString = "Valid Block\n";
    if(aBlock.isBlockValid() == false)
        blockString = "Error: invalid Block\n";

    if(!errorOnly)
    {
        if(aBlock.code() != NO_CODE)
        {
            blockString += "  Gcode Command: ";
            switch (aBlock.code()) {
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
                blockString += ("G4 - DWELL: " + QString::number(aBlock.dwell()) + "\n");
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
        blockString += "---------- LASER ----------\n";
        switch (aBlock.laserGalvo()->laser_message()->task()) {
        case ENABLE:
                blockString += "  State: Enabled\n";
            break;
        case DISABLE:
            blockString += "  State: Disabled\n";
            break;
        case ENABLE_POWER:
                blockString += "  State: Enabled\n";
                blockString += "  Power: " + QString::number(aBlock.laserGalvo()->laser_message()->D1())+ "\n";
            break;
        case POWER:
            if(aBlock.laserGalvo()->laser_message()->D0() != 0)
            {
                blockString += "  State: Enabled\n";
                blockString += "  Power: " + QString::number(aBlock.laserGalvo()->laser_message()->D1())+ "\n";
            }
            else
            {
                blockString += "  State: Disabled\n";
                blockString += "  Power: " + QString::number(aBlock.laserGalvo()->laser_message()->D1())+ "\n";
            }
            break;
        default:
            blockString += "  Did not recognize laser task.\n";
            break;
        }

        if(!displayAxis('X',*aBlock.laserGalvo()->x_message()).contains("No task assigned"))
            blockString += "\n"+ displayAxis('X',*aBlock.laserGalvo()->x_message());
        if(!displayAxis('Y',*aBlock.laserGalvo()->y_message()).contains("No task assigned"))
            blockString += "\n"+ displayAxis('Y',*aBlock.laserGalvo()->y_message());
        if(!displayAxis('Z',*aBlock.materialDelivery()->buildPlate_message()).contains("No task assigned"))
            blockString += "\n"+ displayAxis('Z',*aBlock.materialDelivery()->buildPlate_message());
        if(!displayAxis('A',*aBlock.materialDelivery()->hopperPlate_message()).contains("No task assigned"))
            blockString += "\n"+ displayAxis('A',*aBlock.materialDelivery()->hopperPlate_message());
        if(!displayAxis('B',*aBlock.materialDelivery()->spreadBlade_message()).contains("No task assigned"))
            blockString += "\n"+ displayAxis('B',*aBlock.materialDelivery()->spreadBlade_message());

        if(aBlock.com_err().size() > 1)
            blockString += ("Comment/Error: " + aBlock.com_err() + "\n");
    }
    else
    {
        if(aBlock.com_err().size() > 1)
            blockString += ("Comment/Error: " + aBlock.com_err() + "\n");
    }
    return blockString;
}

QStringList Part::debugPart(bool errorOnly)
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
            if(blockStringDisplay.size() > 1)
                layerString += displayBlock(tempBlock, errorOnly);

        }
       numLines += m_part[i].get().size();
       layerString += "*//////////* End Layer " + QString::number(i) +" *//////////*\n\n";
       debugOut<<layerString;
    }
    if(isPartValid()==true)
        debugOut.prepend("\nPart has been processed successfully!\n");
    else
        debugOut.prepend("\nPart contains errors!\n");

    debugOut.prepend("\nLayers: " + QString::number(numLayer) +"\nBlocks: " + QString::number(numLines) + "\n\n");
    debugOut.prepend("\n\n\nFile: " + m_fileName + "\n");

    return debugOut;
}

void Part::makePart()
{

    QFile file(m_fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        Layer tempLayer;
        QTextStream in(&file);
        while (!in.atEnd())
        {
            bool layerFlag = false;
            QString line = in.readLine();

            Block tempBlock(line, m_settings);
            layerFlag = tempBlock.newLayerFlag();
            if(layerFlag == false){
                tempLayer.addBlock(tempBlock);
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

void Part::addLayer(Layer aLayer)
{
    m_part.append(aLayer);
}

QVector<Layer> Part::get() const
{
    return m_part;
}

Layer Part::getLayer(int layerNumber) const
{
    return m_part[layerNumber];
}

Block Part::getBlock(int LayerNumber, int blockNumber)
{
    return m_part[LayerNumber].getBlock(blockNumber);
}

////////////////////////////////////////// END PART CLASS //////////////////////////////////////////
}


