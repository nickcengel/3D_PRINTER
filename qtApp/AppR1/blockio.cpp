
#include "blockio.h"


namespace BlockIO {

Block::Block(){
   setBlockValid(false);
}

Block::Block(const QString toParse, machine_settings_t *settings)
{
    setBlockValid(true);
    makeBlock(toParse, settings);
    if(this->isBlockValid())
        m_com_err.clear();
}

message_t Block::x_axis() const
{
    return m_x_axis;
}

void Block::set_x_axis(const message_t &x_axis){
    m_x_axis = x_axis;
}

void Block::set_x_axis(const TaskMap m, const float data0)
{
    m_x_axis.map = m;
    m_x_axis.data[0] = data0;
}

void Block::set_x_axis(const TaskMap m, const float data0, const float data1)
{
    m_x_axis.map = m;
    m_x_axis.data[0] = data0;
    m_x_axis.data[1] = data1;
}

message_t Block::y_axis() const
{
    return m_y_axis;
}

void Block::set_y_axis(const message_t &y_axis){
    m_y_axis = y_axis;
}

void Block::set_y_axis(const TaskMap m, const float data0)
{
    m_y_axis.map = m;
    m_y_axis.data[0] = data0;
}

void Block::set_y_axis(const TaskMap m, const float data0, const float data1)
{
    m_y_axis.map = m;
    m_y_axis.data[0] = data0;
    m_y_axis.data[1] = data1;
}

message_t Block::z_axis() const
{
    return m_z_axis;
}

void Block::set_z_axis(const message_t &z_axis){
    m_z_axis = z_axis;
}

void Block::set_z_axis(const TaskMap m, const float data0)
{
    m_z_axis.map = m;
    m_z_axis.data[0] = data0;
}

void Block::set_z_axis(const TaskMap m, const float data0, const float data1)
{
    m_z_axis.map = m;
    m_z_axis.data[0] = data0;
    m_z_axis.data[1] = data1;
}

message_t Block::a_axis() const
{
    return m_a_axis;
}

void Block::set_a_axis(const message_t &a_axis){
    m_a_axis = a_axis;
}

void Block::set_a_axis(const TaskMap m, const float data0)
{
    m_a_axis.map = m;
    m_a_axis.data[0] = data0;
}

void Block::set_a_axis(const TaskMap m, const float data0, const float data1)
{
    m_a_axis.map = m;
    m_a_axis.data[0] = data0;
    m_a_axis.data[1] = data1;
}

message_t Block::b_axis() const
{
    return m_b_axis;
}

void Block::set_b_axis(const message_t &b_axis){
    m_b_axis = b_axis;
}

void Block::set_b_axis(const TaskMap m, const float data0)
{
    m_b_axis.map = m;
    m_b_axis.data[0] = data0;
}

void Block::set_b_axis(const TaskMap m, const float data0, const float data1)
{
    m_b_axis.map = m;
    m_b_axis.data[0] = data0;
    m_b_axis.data[1] = data1;
}

message_t Block::laser() const
{
    return m_laser;
}

void Block::set_laser(const message_t &laser){
    m_laser = laser;
}

void Block::set_laser(const TaskMap m, const float data0)
{
    m_laser.map = m;
    m_laser.data[0] = data0;
}

void Block::set_laser(const TaskMap m, const float data0, const float data1)
{
    m_laser.map = m;
    m_laser.data[0] = data0;
    m_laser.data[1] = data1;
}

message_t Block::dwell() const
{
    return m_dwell;
}

void Block::set_dwell(const message_t &dwell){
    m_dwell = dwell;
}

void Block::set_dwell(const TaskMap m, const float data0)
{
    m_dwell.map = m;
    m_dwell.data[0] = data0;
}

void Block::set_dwell(const TaskMap m, const float data0, const float data1)
{
    m_dwell.map = m;
    m_dwell.data[0] = data0;
    m_dwell.data[1] = data1;
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
    if(isBlockValid())
    {
        return "No errors!\n";
    }
    else
        return m_com_err;
}

void Block::set_com_err(const QString &value)
{
    m_com_err = value;
}

void Block::makeBlock(const QString toParse, machine_settings_t *settings)
{
    //    // BEGIN splitting up comments and commands ///
    QString c_line; // comments and errors go here
    QString g_line; // commands go here
    int startComment;
    int endComment;
    int commentSize;
    // For safety, always start by setting the laser off flag
    set_laser(EN,0);

    if((toParse.indexOf('/') == 0)||(toParse.size()<2))  // Ignore empty lines or ones that begin with '/'
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

    // END splitting up comments and commands //

    if(g_line.size() > 1){
        // Split command into its tokens, seperated by single whitespace
        QStringList tokens = g_line.split(' ', QString::SkipEmptyParts);
        int numTokens = tokens.length();
        for(int i = 0; i < numTokens; i++){

            QString token = tokens[i];

            int firstLetter = token[0].unicode();
            //  First we look at the first character in the word.
            switch (firstLetter) {
            // If we find G or M, we have a code command
            case 'G':
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
                    set_x_axis(REL,0);
                    set_y_axis(REL,0);
                    set_z_axis(REL,0);
                    set_a_axis(REL,0);
                    set_b_axis(REL,0);
                }
                else if(token == "G91") // RELATIVE POSITION
                {
                    setCode(G91);
                    set_x_axis(REL,1);
                    set_y_axis(REL,1);
                    set_z_axis(REL,1);
                    set_a_axis(REL,1);
                    set_b_axis(REL,1);
                }
                else
                {
                    c_line += "Did not recognize command: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;
            case 'M':
                // So setCode with matching enumerated code
                if(token == "M0")   // PAUSE
                    setCode(M0);
                else if(token == "M2")  //  END PROGRAM
                    setCode(M2);
                else if(token == "M3")
                {  // LASER ON
                    setCode(M3);
                    set_laser(EN,1);
                }
                else if(token == "M5")
                {  // LASER OFF
                    setCode(M5);
                    set_laser(EN,0);
                }
                else
                {
                    c_line += "Did not recognize instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;

                // If the first character is X,Y,Z,A,or B, we are talking about an axis
            case 'X':
                //  Check that a relevant command is requested and set new position
                //  Check if the position is a valid number
                if((code() == G0)||(code() == G1))
                {
                    bool valueValid = false;
                    float value = token.right(token.size()-1).toFloat(&valueValid);
                    if(valueValid && (value < settings->x_settings.positionMax) && (value > settings->x_settings.positionMin))
                        set_x_axis(POS,value);
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
                    set_x_axis(HOME,1);
                else
                {
                    c_line += "Did not recognize X instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;

            case 'Y':
                //  Check that a relevant command is requested and set new position
                //  Check if the position is a valid number
                if((code() == G0)||(code() == G1))
                {
                    bool valueValid = false;
                    float value = token.right(token.size()-1).toFloat(&valueValid);
                    if(valueValid && (value < settings->y_settings.positionMax) && (value > settings->y_settings.positionMin))
                        set_y_axis(POS,value);
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
                    set_y_axis(HOME,1);
                else
                {
                    c_line += "Did not recognize Y instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;

            case 'Z':
                //  Check that a relevant command is requested and set new position
                //  Check if the position is a valid number
                if((code() == G0)||(code() == G1))
                {
                    bool valueValid = false;
                    float value = token.right(token.size()-1).toFloat(&valueValid);
                    if(valueValid && (value < settings->z_settings.positionMax) && (value > settings->z_settings.positionMin))
                        set_z_axis(POS,value);
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
                    set_z_axis(HOME,1);
                else
                {
                    c_line += "Did not recognize Z instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;

            case 'A':
                //  Check that a relevant command is requested and set new position
                //  Check if the position is a valid number
                if((code() == G0)||(code() == G1))
                {
                    bool valueValid = false;
                    float value = token.right(token.size()-1).toFloat(&valueValid);
                    if(valueValid && (value < settings->a_settings.positionMax) && (value > settings->a_settings.positionMin))
                        set_a_axis(POS,value);
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
                    set_a_axis(HOME,1);
                else
                {
                    c_line += "Did not recognize A instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;

            case 'B':
                //  Check that a relevant command is requested and set new position
                //  Check if the position is a valid number
                if((code() == G0)||(code() == G1))
                {
                    bool valueValid = false;
                    float value = token.right(token.size()-1).toFloat(&valueValid);
                    if(valueValid && (value < settings->b_settings.positionMax) && (value > settings->b_settings.positionMin))
                        set_b_axis(POS,value);
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
                    set_b_axis(HOME,1);
                else
                {
                    c_line += "Did not recognize B instruction: \""+token+"\"\n";
                    setBlockValid(false);
                }
                break;

                // E used to indicate the current movement corresponds to an active print command.
                // This follows from the extrusion printer convention. Where E is used to control
                // the amount of material extruded. In our cases, we simpply check if a line contains
                // 'E'. This means we should turn the laser on.
            case 'E':
                // check that there is an XY move
                if(isBlockValid() && (code() == G1)
                        && ((m_x_axis.map == POS) || (m_x_axis.map == POS_SP))
                        && ((m_y_axis.map == POS) || (m_y_axis.map == POS_SP))
                        && ((m_z_axis.map != POS) || (m_z_axis.map != POS_SP))
                        && ((m_a_axis.map != POS) || (m_b_axis.map != POS_SP))
                        && ((m_b_axis.map != POS) || (m_b_axis.map != POS_SP)))
                {
                    set_laser(EN,1);
                }
                else if(code() != G1){
                    c_line += "Laser can only be enabled during linear movement. Use G1 not G0\n";
                    setBlockValid(false);
                }
                else if((m_x_axis.map != POS) || (m_x_axis.map != POS_SP)||(m_y_axis.map != POS) || (m_y_axis.map != POS_SP)){
                    c_line += "Laser can only be enbabled in connection with a move in the X or Y axis.\n";
                    setBlockValid(false);
                }
                else{
                    c_line += "Laser could not be enabled\n";
                    setBlockValid(false);
                }
                break;

                // F used to modify speed. We only want to set the speed for an axis we intend
                // to move with this block, so check to see if each axis has a pending move.
            case 'F':
            {
                bool valueValid = false;
                float value = token.right(token.size()-1).toFloat(&valueValid);
                if(valueValid){
                    if((m_x_axis.map == POS) && (value < settings->x_settings.speedMax) && (value > settings->x_settings.speedMin))
                    {
                        m_x_axis.map = POS_SP;
                        m_x_axis.data[1] = value;
                    }
                    else
                    {
                        c_line += "X speed out of range.\n";
                        setBlockValid(false);
                    }
                    if((m_y_axis.map == POS) && (value < settings->y_settings.speedMax) && (value > settings->y_settings.speedMin))
                    {
                        m_y_axis.map = POS_SP;
                        m_y_axis.data[1] = value;
                    }
                    else
                    {
                        c_line += "Y speed out of range.\n";
                        setBlockValid(false);
                    }
                    if((m_z_axis.map == POS) && (value < settings->z_settings.speedMax) && (value > settings->z_settings.speedMin))
                    {
                        m_z_axis.map = POS_SP;
                        m_z_axis.data[1] = value;
                    }
                    else
                    {
                        c_line += "Z speed out of range.\n";
                        setBlockValid(false);
                    }
                    if((m_a_axis.map == POS) && (value < settings->a_settings.speedMax) && (value > settings->a_settings.speedMin))
                    {
                        m_a_axis.map = POS_SP;
                        m_a_axis.data[1] = value;
                    }
                    else
                    {
                        c_line += "A speed out of range.\n";
                        setBlockValid(false);
                    }
                    if((m_b_axis.map == POS) && (value < settings->b_settings.speedMax) && (value > settings->b_settings.speedMin))
                    {
                        m_b_axis.map = POS_SP;
                        m_b_axis.data[1] = value;
                    }
                    else
                    {
                        c_line += "B speed out of range.\n";
                        setBlockValid(false);
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
                    set_dwell(DWELL,value);
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
                    if(m_laser.map == EN)
                    {
                        m_laser.map = EN_POW;
                        m_laser.data[1] = value;
                    }
                    else
                        set_laser(POW,0,value);
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
    }//end if
    set_com_err(c_line);
}



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
    for(int i = 0; i < m_layer.size(); i++)
    {
        if(m_layer[i].isBlockValid() == false)
            setLayerValid(false);
    }
    return isLayerValid();
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



Part::Part(QString fileName, machine_settings_t settings){
    m_fileName = fileName;
    m_settings = settings;
    makePart();
}

bool Part::isPartValid() const
{
    return m_groupValid;
}

void Part::validatePart()
{
    for(int i = 0; i < m_layerGroup.size(); i++)
    {
        if(m_layerGroup[i].isLayerValid() == false)
            m_groupValid = false;
    }
}

void Part::makePart()
{
    QFile file(m_fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        bool layerFlag = false;
        while (!in.atEnd())
        {
            layerFlag = false;
            Layer tempLayer;
            while(!layerFlag && !in.atEnd())
            {
                QString line = in.readLine();
                if(line.size() > 1)
                {
                    Block tempBlock(line, &m_settings);
                    layerFlag = tempBlock.newLayerFlag();
                    if(!layerFlag){
                        tempLayer.addBlock(tempBlock);
                    }
                }
            }
            m_layerGroup.append(tempLayer);
        }
        file.close();
        validatePart();
    }
    else
        qDebug()<<"Could not open file";
}

QVector<Layer> Part::get() const
{
    return m_layerGroup;
}

Layer Part::getLayer(int layerNumber) const
{
    return m_layerGroup[layerNumber];
}

Block Part::getBlock(int LayerNumber, int blockNumber)
{
    return m_layerGroup[LayerNumber].getBlock(blockNumber);
}


}
