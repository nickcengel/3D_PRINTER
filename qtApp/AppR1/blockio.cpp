
#include "blockio.h"

namespace BlockIO {

Message::Message()
{
    setDeviceNumber(NO_DEVICE);
    setAxisNumber(NO_AXIS);
    setTask(NO_TASK);
    setMode(NO_MODE);
    setStatus(NO_STATUS);
}

Message::Message(DeviceNumber dn, AxisNumber an)
{
    setDeviceNumber(dn);
    setAxisNumber(an);
    setTask(NO_TASK);
    setMode(NO_MODE);
    setStatus(NO_STATUS);
}

DeviceNumber Message::getDeviceNumber() const
{
    return m_deviceNumber;
}

void Message::setDeviceNumber(const DeviceNumber &deviceNumber)
{
    m_deviceNumber = deviceNumber;
}

AxisNumber Message::getAxisNumber() const
{
    return m_axisNumber;
}

void Message::setAxisNumber(const AxisNumber &axisNumber)
{
    m_axisNumber = axisNumber;
}

Message_Mode Message::getMode() const
{
    return m_mode;
}

void Message::setMode(const Message_Mode &mode)
{
    m_mode = mode;
}

Message_Task Message::getTask() const
{
    return m_task;
}

void Message::setTask(const Message_Task &task)
{
    m_task = task;
}

Messge_Status Message::getStatus() const
{
    return m_status;
}

void Message::setStatus(const Messge_Status &status)
{
    m_status = status;
}

float Message::getPosition_mm() const
{
    return m_position_mm;
}

void Message::setPosition_mm(float position_mm)
{
    m_position_mm = position_mm;
    setPosition_ms(position_mm);
}

int Message::getPosition_ms() const
{
    return m_position_ms;
}

void Message::setPosition_ms(float mm)
{
    const int myMicroSteps = (int)(getUStepPerMM()*mm);
    m_position_ms = myMicroSteps;
}

int Message::getSpeed() const
{
    return m_speed;
}

void Message::setSpeed(int speed)
{
    m_speed = speed;
}

int Message::getPower() const
{
    return m_power;
}

void Message::setPower(int power)
{
    m_power = power;
}

QString Message::getCommandString() const
{
    return m_commandString;
}

void Message::composeCommandString()
{

    const Message_Task myTask = getTask();
    if((myTask > TASK_ERROR) && (myTask < NO_TASK))
    {
        // Commands begin with /device# axis#
        QString myString = ("/" + QString::number((int)getDeviceNumber()) + " " + QString::number((int)getAxisNumber()));
        if((myTask == ENABLE) || (myTask == DISABLE))
        {
            if(myTask == ENABLE)
                myString += " on\r\n";
            else
                myString += " off\r\n";
        }
        else if((myTask == ENABLE_AT_POWER) || (myTask == SET_POWER))
        {
            if(myTask == ENABLE_AT_POWER)
                myString += (" on s " +  QString::number((int)getPower()) + "\r\n");
            else
                myString += (" off s " +  QString::number((int)getPower()) + "\r\n");
        }
        else if((myTask == MOVE_ABS) || (myTask == MOVE_REL))
        {

            if(myTask == MOVE_ABS)
                myString += (" move abs " +  QString::number(getPosition_ms()) + "\r\n");
            else
                myString += (" move rel " +  QString::number(getPosition_ms()) + "\r\n");
        }
        else if((myTask == MOVE_ABS_AT_SPEED) || (myTask == MOVE_REL_AT_SPEED))
        {
            if(myTask == MOVE_ABS_AT_SPEED)
            {
                myString += (" move abs " + QString::number(getPosition_ms()));
                myString += (" f " + QString::number(getSpeed()) + "\r\n");
            }
            else
            {
                myString += (" move rel " + QString::number(getPosition_ms()));
                myString += (" f " + QString::number(getSpeed()) + "\r\n");
            }
        }
        else if(myTask == STOP)
        {
            myString += " stop\r\n";
        }
        else if(myTask == GO_HOME)
        {
            myString += " home\r\n";
        }
        else if(myTask == GET_STATUS)
        {
            myString += " status\r\n";
        }

        m_commandString = myString;
    }

}

float Message::getUStepPerMM() const
{
    return m_uStepPerMM;
}

void Message::setUStepPerMM(float uStepPerMM)
{
    m_uStepPerMM = uStepPerMM;
}





////////////////////////////////////////// BEGIN BLOCK CLASS //////////////////////////////////////////
Block::Block(){
    setBlockValid(false);
    setCode(NO_CODE);
}

Block::Block(QString toParse, Message_Mode previousMode, machine_settings_t *settings)
{
    setCode(NO_CODE);
    setBlockValid(true);
    makeBlock(toParse, previousMode, settings);
}

Message *Block::L_Axis()
{
    return &m_L_Axis;
}

Message *Block::X_Axis()
{
    return &m_X_Axis;
}

Message *Block::Y_Axis()
{
    return &m_Y_Axis;
}

Message *Block::Z_Axis()
{
    return &m_Z_Axis;
}

Message *Block::A_Axis()
{
    return &m_A_Axis;
}

Message *Block::B_Axis()
{
    return &m_B_Axis;
}

float Block::getDwell() const
{
    return m_dwell;
}

void Block::setDwell(float dwell)
{
    m_dwell = dwell;
}

Code Block::getCode() const
{
    return m_code;
}

void Block::setCode(const Code code)
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

void Block::setNewLayer(bool newLayer)
{
    m_newLayer = newLayer;
}

bool Block::isBlockValid() const
{
    return m_blockValid;
}

void Block::setBlockValid(bool blockValid)
{
    m_blockValid = blockValid;
}

Message_Mode Block::getPreviousMode() const
{
    return m_previousMode;
}

void Block::setPreviousMode(const Message_Mode previousMode)
{
    m_previousMode = previousMode;
}

// the juicy bit...
void Block::makeBlock(const QString toParse, Message_Mode previousMode, machine_settings_t *settings)
{
    setPreviousMode(previousMode);
    L_Axis()->setDeviceNumber((DeviceNumber)settings->l_settings.deviceNumber);
    L_Axis()->setAxisNumber((AxisNumber)settings->l_settings.axisNumber);

    X_Axis()->setDeviceNumber((DeviceNumber)settings->x_settings.deviceNumber);
    X_Axis()->setAxisNumber((AxisNumber)settings->x_settings.axisNumber);
    X_Axis()->setUStepPerMM(settings->x_settings.uStepPerMM);

    Y_Axis()->setDeviceNumber((DeviceNumber)settings->y_settings.deviceNumber);
    Y_Axis()->setAxisNumber((AxisNumber)settings->y_settings.axisNumber);
    Y_Axis()->setUStepPerMM(settings->y_settings.uStepPerMM);

    Z_Axis()->setDeviceNumber((DeviceNumber)settings->z_settings.deviceNumber);
    Z_Axis()->setAxisNumber((AxisNumber)settings->z_settings.axisNumber);
    X_Axis()->setUStepPerMM(settings->z_settings.uStepPerMM);

    A_Axis()->setDeviceNumber((DeviceNumber)settings->a_settings.deviceNumber);
    A_Axis()->setAxisNumber((AxisNumber)settings->a_settings.axisNumber);
    X_Axis()->setUStepPerMM(settings->a_settings.uStepPerMM);

    B_Axis()->setDeviceNumber((DeviceNumber)settings->b_settings.deviceNumber);
    B_Axis()->setAxisNumber((AxisNumber)settings->b_settings.axisNumber);
    X_Axis()->setUStepPerMM(settings->b_settings.uStepPerMM);

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
                    X_Axis()->setMode(previousMode);
                    Y_Axis()->setMode(previousMode);
                    Z_Axis()->setMode(previousMode);
                    A_Axis()->setMode(previousMode);
                    B_Axis()->setMode(previousMode);
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
                        X_Axis()->setMode(ABSOLUTE);
                        Y_Axis()->setMode(ABSOLUTE);
                        Z_Axis()->setMode(ABSOLUTE);
                        A_Axis()->setMode(ABSOLUTE);
                        B_Axis()->setMode(ABSOLUTE);
                        setPreviousMode(ABSOLUTE);
                    }
                    else if(token == "G91") // RELATIVE POSITION
                    {
                        setCode(G91);
                        X_Axis()->setMode(RELATIVE);
                        Y_Axis()->setMode(RELATIVE);
                        Z_Axis()->setMode(RELATIVE);
                        A_Axis()->setMode(RELATIVE);
                        B_Axis()->setMode(RELATIVE);
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
                    L_Axis()->setTask(ENABLE);
                }
                else if(token == "M5")
                {  // LASER OFF
                    setCode(M5);
                    L_Axis()->setTask(DISABLE);                }
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
                        X_Axis()->setPosition_mm(value);
                        if(X_Axis()->getMode() == Message_Mode::RELATIVE)
                            X_Axis()->setTask(MOVE_REL);
                        else
                            X_Axis()->setTask(MOVE_ABS);
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
                else if((token.size() == 1) && (getCode() == G28))
                    X_Axis()->setTask(Message_Task::GO_HOME);
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
                        Y_Axis()->setPosition_mm(value);
                        if(Y_Axis()->getMode() == Message_Mode::RELATIVE)
                            Y_Axis()->setTask(MOVE_REL);
                        else
                            Y_Axis()->setTask(MOVE_ABS);
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
                else if((token.size() == 1) && (getCode() == G28))
                    Y_Axis()->setTask(GO_HOME);
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
                        Z_Axis()->setPosition_mm(value);
                        if(Z_Axis()->getMode() == Message_Mode::RELATIVE)
                            Z_Axis()->setTask(MOVE_REL);
                        else
                            Z_Axis()->setTask(MOVE_ABS);
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
                else if((token.size() == 1) && (getCode() == G28))
                    Z_Axis()->setTask(GO_HOME);
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
                        A_Axis()->setPosition_mm(value);
                        if(A_Axis()->getMode() == Message_Mode::RELATIVE)
                            A_Axis()->setTask(MOVE_REL);
                        else
                            A_Axis()->setTask(MOVE_ABS);
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
                else if((token.size() == 1) && (getCode() == G28))
                    A_Axis()->setTask(GO_HOME);
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
                        B_Axis()->setPosition_mm(value);
                        if(B_Axis()->getMode() == Message_Mode::RELATIVE)
                            B_Axis()->setTask(MOVE_REL);
                        else
                            B_Axis()->setTask(MOVE_ABS);
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
                else if((token.size() == 1) && (getCode() == G28))
                    B_Axis()->setTask(GO_HOME);
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
                if(isBlockValid() && (getCode() == G1)
                        && ((((X_Axis()->getTask() == MOVE_ABS) || (X_Axis()->getTask() == MOVE_ABS_AT_SPEED))
                             || ((X_Axis()->getTask() == MOVE_REL) || (X_Axis()->getTask() == MOVE_REL_AT_SPEED)))
                            || (((Y_Axis()->getTask() == MOVE_ABS) || (Y_Axis()->getTask() == MOVE_ABS_AT_SPEED))
                                || ((Y_Axis()->getTask() == MOVE_REL) || (Y_Axis()->getTask() == MOVE_REL_AT_SPEED)))))
                {
                    L_Axis()->setTask(ENABLE);
                }
                else if(getCode() != G1)
                {
                    e_line += "Laser can only be enabled during linear movement. Use G1 not G0\n";
                    setBlockValid(false);
                }
                else if(!((((X_Axis()->getTask() == MOVE_ABS) || (X_Axis()->getTask() == MOVE_ABS_AT_SPEED))
                           || ((X_Axis()->getTask() == MOVE_REL) || (X_Axis()->getTask() == MOVE_REL_AT_SPEED)))
                          || (((Y_Axis()->getTask() == MOVE_ABS) || (Y_Axis()->getTask() == MOVE_ABS_AT_SPEED))
                              || ((Y_Axis()->getTask() == MOVE_REL) || (Y_Axis()->getTask() == MOVE_REL_AT_SPEED)))))
                {
                    e_line += "Laser can only be enbabled in tandem with a move in the X or Y axis.\n";
                    setBlockValid(false);
                }
                else
                {
                    e_line += "Laser could not be enabled\n";
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
                    if((X_Axis()->getTask() == MOVE_ABS)||(X_Axis()->getTask() == MOVE_ABS_AT_SPEED)
                            ||(X_Axis()->getTask() == MOVE_REL)||(X_Axis()->getTask() == MOVE_REL_AT_SPEED))
                    {
                        if((value < settings->x_settings.speedMax) && (value > settings->x_settings.speedMin))
                        {
                            if(X_Axis()->getMode() == ABSOLUTE)
                            {
                                X_Axis()->setTask(MOVE_ABS_AT_SPEED);
                                X_Axis()->setSpeed(value);
                            }
                            else if(X_Axis()->getMode() == RELATIVE)
                            {
                                X_Axis()->setTask(MOVE_REL_AT_SPEED);
                                X_Axis()->setSpeed(value);
                            }
                        }
                        else
                        {
                            e_line += "X speed out of range.\n";
                            setBlockValid(false);
                        }
                    }

                    if((Y_Axis()->getTask() == MOVE_ABS)||(Y_Axis()->getTask() == MOVE_ABS_AT_SPEED)
                            ||(Y_Axis()->getTask() == MOVE_REL)||(Y_Axis()->getTask() == MOVE_REL_AT_SPEED))
                    {
                        if((value < settings->y_settings.speedMax) && (value > settings->y_settings.speedMin))
                        {
                            if(Y_Axis()->getMode() == ABSOLUTE)
                            {
                                Y_Axis()->setTask(MOVE_ABS_AT_SPEED);
                                Y_Axis()->setSpeed(value);
                            }
                            else if(Y_Axis()->getMode() == RELATIVE)
                            {
                                Y_Axis()->setTask(MOVE_REL_AT_SPEED);
                                Y_Axis()->setSpeed(value);
                            }
                        }
                        else
                        {
                            e_line += "Y speed out of range.\n";
                            setBlockValid(false);
                        }
                    }

                    if((Z_Axis()->getTask() == MOVE_ABS)||(Z_Axis()->getTask() == MOVE_ABS_AT_SPEED)
                            ||(Z_Axis()->getTask() == MOVE_REL)||(Z_Axis()->getTask() == MOVE_REL_AT_SPEED))
                    {
                        if((value < settings->z_settings.speedMax) && (value > settings->z_settings.speedMin))
                        {
                            if(Z_Axis()->getMode() == ABSOLUTE)
                            {
                                Z_Axis()->setTask(MOVE_ABS_AT_SPEED);
                                Z_Axis()->setSpeed(value);
                            }
                            else if(Z_Axis()->getMode() == RELATIVE)
                            {
                                Z_Axis()->setTask(MOVE_REL_AT_SPEED);
                                Z_Axis()->setSpeed(value);
                            }
                        }
                        else
                        {
                            e_line += "Z speed out of range.\n";
                            setBlockValid(false);
                        }
                    }

                    if((A_Axis()->getTask() == MOVE_ABS)||(A_Axis()->getTask() == MOVE_ABS_AT_SPEED)
                            ||(A_Axis()->getTask() == MOVE_REL)||(A_Axis()->getTask() == MOVE_REL_AT_SPEED))
                    {
                        if((value < settings->a_settings.speedMax) && (value > settings->a_settings.speedMin))
                        {
                            if(A_Axis()->getMode() == ABSOLUTE)
                            {
                                A_Axis()->setTask(MOVE_ABS_AT_SPEED);
                                A_Axis()->setSpeed(value);
                            }
                            else if(A_Axis()->getMode() == RELATIVE)
                            {
                                A_Axis()->setTask(MOVE_REL_AT_SPEED);
                                A_Axis()->setSpeed(value);
                            }
                        }
                        else
                        {
                            e_line += "A speed out of range.\n";
                            setBlockValid(false);
                        }
                    }

                    if((B_Axis()->getTask() == MOVE_ABS)||(B_Axis()->getTask() == MOVE_ABS_AT_SPEED)
                            ||(B_Axis()->getTask() == MOVE_REL)||(B_Axis()->getTask() == MOVE_REL_AT_SPEED))
                    {
                        if((value < settings->b_settings.speedMax) && (value > settings->b_settings.speedMin))
                        {
                            if(B_Axis()->getMode() == ABSOLUTE)
                            {
                                B_Axis()->setTask(MOVE_ABS_AT_SPEED);
                                B_Axis()->setSpeed(value);
                            }
                            else if(B_Axis()->getMode() == RELATIVE)
                            {
                                B_Axis()->setTask(MOVE_REL_AT_SPEED);
                                B_Axis()->setSpeed(value);
                            }
                        }
                        else
                        {
                            e_line += "B speed out of range.\n";
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
                    if(L_Axis()->getTask() == ENABLE)
                    {
                        L_Axis()->setTask(ENABLE_AT_POWER);
                        L_Axis()->setPower(value);
                    }
                    else
                    {
                        L_Axis()->setTask(SET_POWER);
                        L_Axis()->setPower(value);
                    }
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
        L_Axis()->composeCommandString();
        X_Axis()->composeCommandString();
        Y_Axis()->composeCommandString();
        Z_Axis()->composeCommandString();
        A_Axis()->composeCommandString();
        B_Axis()->composeCommandString();

    }
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

QString Part::displayAxis(QChar axis_number, Message axis)
{
    QString axisString = "---------- ";
    if(axis_number == 'L')
        axisString += "LASER ----------\n";
    else
    {
    axisString += (QString)axis_number;
    axisString += " AXIS ----------\n";
    }
    switch (axis.getTask()) {
    case MOVE_ABS:
        axisString += ("  Move to: " + QString::number(axis.getPosition_mm()) + "\n");
        break;
    case MOVE_ABS_AT_SPEED:
        axisString += ("  Move to: " + QString::number(axis.getPosition_mm()) + "\n");
        axisString += ("  Speed: " + QString::number(axis.getSpeed()) + "\n");
        break;
    case MOVE_REL:
        axisString += ("  Relative Move by: " + QString::number(axis.getPosition_mm()) + "\n");
        break;
    case MOVE_REL_AT_SPEED:
        axisString += ("  Relative Move by: " + QString::number(axis.getPosition_mm()) + "\n");
        axisString += ("  Speed: " + QString::number(axis.getSpeed()) + "\n");
        break;
    case GO_HOME:
        axisString += "  Axis executes HOME command.\n";
        break;
    case ENABLE:
        axisString += "  Axis enabled.\n";
        break;
    case DISABLE:
        axisString += "  Axis disabled.\n";
        break;
    case NO_TASK:
        axisString += "  No task assigned.\n";
        if(axis.getMode() == ABSOLUTE)
            axisString += "  Absolutie motion instructions to follow\n";
        else if(axis.getMode() == RELATIVE)
            axisString += "  Relative motion instructions to follow.\n";
        break;
    default:
        axisString += "  Did not recognize Axis task.\n";
        break;
    }
    if(axis.getCommandString().size() > 1)
        axisString += ("  Command String: " + axis.getCommandString());
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
        if(!displayAxis('L',*aBlock.L_Axis()).contains("No task assigned"))
            blockString += "\n"+ displayAxis('L',*aBlock.L_Axis());
        if(!displayAxis('X',*aBlock.X_Axis()).contains("No task assigned"))
            blockString += "\n"+ displayAxis('X',*aBlock.X_Axis());
        if(!displayAxis('Y',*aBlock.Y_Axis()).contains("No task assigned"))
            blockString += "\n"+ displayAxis('Y',*aBlock.Y_Axis());
        if(!displayAxis('Z',*aBlock.Z_Axis()).contains("No task assigned"))
            blockString += "\n"+ displayAxis('Z',*aBlock.Z_Axis());
        if(!displayAxis('A',*aBlock.A_Axis()).contains("No task assigned"))
            blockString += "\n"+ displayAxis('A',*aBlock.A_Axis());
        if(!displayAxis('B',*aBlock.B_Axis()).contains("No task assigned"))
            blockString += "\n"+ displayAxis('B',*aBlock.B_Axis());


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
    {   Message_Mode lastMode = NO_MODE;
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


