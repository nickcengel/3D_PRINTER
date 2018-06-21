
#include "blockio.h"

namespace BlockIO {

Message::Message()
{
    setMessageType(NO_TYPE);
    setDeviceNumber(NO_DEVICE);
    setAxisNumber(NO_AXIS);
    setTask(NO_TASK);
    setMode(NO_MODE);
    setStatus(NO_STATUS);
    setReplyFlag(NO_FLAG);
    setRepyFlagData(NO_FLAG_DATA);
    setReplyWarningFlag(NO_WARNING_FLAG);
}

Message::Message(const QString &replyMessage)
{
    setMessageType(NO_TYPE);
    setDeviceNumber(NO_DEVICE);
    setAxisNumber(NO_AXIS);
    setTask(NO_TASK);
    setMode(NO_MODE);
    setStatus(NO_STATUS);
    setReplyFlag(NO_FLAG);
    setRepyFlagData(NO_FLAG_DATA);
    setReplyWarningFlag(NO_WARNING_FLAG);
    decomposeReplyStr(replyMessage);
}

Message::Message(const Message_Type type, const Device_Number dn, const Axis_Number an)
{
    setMessageType(type);
    setDeviceNumber(dn);
    setAxisNumber(an);
    setTask(NO_TASK);
    setMode(NO_MODE);
    setStatus(NO_STATUS);
    setReplyFlag(NO_FLAG);
    setRepyFlagData(NO_FLAG_DATA);
    setReplyWarningFlag(NO_WARNING_FLAG);
}

Message::Message(const Device_Number dn,  const Axis_Number an)
{
    setDeviceNumber(dn);
    setAxisNumber(an);
    setTask(NO_TASK);
    setMode(NO_MODE);
    setStatus(NO_STATUS);
    setReplyFlag(NO_FLAG);
    setRepyFlagData(NO_FLAG_DATA);
    setReplyWarningFlag(NO_WARNING_FLAG);
}

Device_Number Message::getDeviceNumber() const
{
    return m_deviceNumber;
}

void Message::setDeviceNumber(const Device_Number deviceNumber)
{
    m_deviceNumber = deviceNumber;
}

Axis_Number Message::getAxisNumber() const
{
    return m_axisNumber;
}

void Message::setAxisNumber(const Axis_Number axisNumber)
{
    m_axisNumber = axisNumber;
}

Message_Mode Message::getMode() const
{
    return m_mode;
}

void Message::setMode(const Message_Mode mode)
{
    m_mode = mode;
}

Message_Task Message::getTask() const
{
    return m_task;
}

void Message::setTask(const Message_Task task)
{
    m_task = task;
}

Message_Status Message::getStatus() const
{
    return m_status;
}

void Message::setStatus(const Message_Status status)
{
    m_status = status;
}

float Message::getPosition_mm() const
{
    return m_position_mm;
}

void Message::setPosition_mm(const float position_mm)
{
    m_position_mm = position_mm;
    setPosition_ms(position_mm);
}

int Message::getPosition_ms() const
{
    return m_position_ms;
}

void Message::setPosition_ms(const float mm)
{
    const int myMicroSteps = (int)(getUStepPerMM()*mm);
    m_position_ms = myMicroSteps;
}

int Message::getSpeed() const
{
    return m_speed;
}

void Message::setSpeed(const int speed)
{
    m_speed = speed;
}

int Message::getPower() const
{
    return m_power;
}

void Message::setPower(const int power)
{
    m_power = power;
}

QString Message::getCommandStr() const
{
    return m_commandString;
}

void Message::composeCommandStr()
{
    setMessageType(Message_Type::M_COMMAND);
    const Message_Task myTask = getTask();
    if((myTask > TASK_ERROR) && (myTask < NO_TASK))
    {
        // Commands begin with /device# axis#
        QString myString = ("/"
                            + QString::number((int)getDeviceNumber())
                            + " " + QString::number((int)getAxisNumber()));

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

void Message::setUStepPerMM(const float uStepPerMM)
{
    m_uStepPerMM = uStepPerMM;
}

Message_Type Message::getMessageType() const
{
    return m_messageType;
}

void Message::setMessageType(const Message_Type type)
{
    m_messageType = type;
}

Message_Reply_Flag Message::getReplyFlag() const
{
    return m_replyFlag;
}

void Message::setReplyFlag(const Message_Reply_Flag replyFlag)
{
    m_replyFlag = replyFlag;
}

Message_Reply_Flag_Data Message::getRepyFlagData() const
{
    return m_repyFlagData;
}

void Message::setRepyFlagData(const Message_Reply_Flag_Data repyFlagData)
{
    m_repyFlagData = repyFlagData;
}

Message_Reply_Warning_Flag Message::getReplyWarningFlag() const
{
    return m_replyWarningFlag;
}

void Message::setReplyWarningFlag(const Message_Reply_Warning_Flag replyWarningFlag)
{
    m_replyWarningFlag = replyWarningFlag;
}

QString Message::getReplyStr() const
{
    return m_replyString;
}

Message_Reply_Flag Message::decomposeReplyStr(const QString &rplystr)
{
    /// SEQUENCE: {Type, DeviceNumber,  , AxisNumber,  , ReplyFlag,  ,ReplyStatus,  ,WarningFlag, , Data, \n}
    ///           {T, NN, , A, , FF, , SSSS, , WW, , X to XXXX XXXX, r}
    ///             {Name[startIndex, length]}
    ///           {T[n,1], N[n+1,2], A[n+4,1], F[n+6,2], S[n+9, 4], W[n+14,2], X[n+17,1 to 8],r[n+18 to n+26, 1}
    enum reply_Index{Type_index = 0, DeviceNum_index = 1,
                     AxisNum_index = 4, ReplyFlag_index = 6,
                     ReplyStatus_index = 9, WarningFlag_index = 14,
                     ReplyData_index = 17};
    Message_Reply_Flag myReplyFlag = getReplyFlag();
    int messageStart = -1;
    int messageEnd = -1;

    // FIND THE START OF THE MESSAGE AND DETERMINE THE REPLY TYPE
    if((messageStart = rplystr.indexOf('@',0)) != -1)
    {
        setMessageType(Message_Type::M_REPLY);
    }
    else if((messageStart = rplystr.indexOf('!',0)) != -1)
    {
        setMessageType(Message_Type::M_ALERT);
    }
    else if((messageStart = rplystr.indexOf('#',0)) != -1)
    {
        setMessageType(Message_Type::M_INFO);
    }
    else
    {
        setMessageType(Message_Type::TYPE_ERROR);
        myReplyFlag = Message_Reply_Flag::FLAG_ERROR;
        setReplyFlag(myReplyFlag);
        return myReplyFlag;
    }

    // FIND THE END OF THE MESSAGE
    if((messageEnd = getReplyStr().indexOf("\r", messageStart)) != -1)
    {
        setReplyFlag(Message_Reply_Flag::NO_FLAG);
    }
    else if((messageEnd = getReplyStr().indexOf("\n", messageStart)) != -1)
    {
        setReplyFlag(Message_Reply_Flag::NO_FLAG);
    }
    else if((messageEnd = getReplyStr().indexOf("\r\n", messageStart)) != -1)
    {
        setReplyFlag(Message_Reply_Flag::NO_FLAG);
    }
    else
    {
        setMessageType(Message_Type::TYPE_ERROR);
        myReplyFlag = Message_Reply_Flag::DID_NOT_FIND_END;
        setReplyFlag(myReplyFlag);
        return myReplyFlag;
    }

    // IF THE MESSAGE HAS A VALID STRUCTURE, PROCESS IT
    if((messageStart > -1)&&(messageEnd > messageStart)
            &&(rplystr.at(messageStart+3) == ' ')
            &&(rplystr.at(messageStart+5) == ' ')
            &&(rplystr.at(messageStart+8) == ' ')
            &&(rplystr.at(messageStart+13) == ' '))
    {
        const QString myString = rplystr.mid(messageStart,messageEnd-messageStart+1);
        m_replyString = myString;

        bool goodNum = false;

        const int myDeviceNumber = myString.mid(DeviceNum_index, 2).toInt(&goodNum,10);
        if(goodNum)
            setDeviceNumber((Device_Number)myDeviceNumber);

        const int myAxisNumber = myString.mid(AxisNum_index, 1).toInt(&goodNum,10);
        if(goodNum)
            setAxisNumber((Axis_Number)myAxisNumber);

        const int myRF = myString.mid(ReplyFlag_index, 2).toInt(&goodNum,10);
        if(goodNum)
            setReplyFlag((Message_Reply_Flag)myRF);

        const QString myStatus = myString.mid(ReplyStatus_index, 4);
        if(myStatus == "BUSY")
            setStatus(Message_Status::BUSY);
        else if(myStatus == "IDLE")
            setStatus(Message_Status::IDLE);

        const QString myWarningFlag = myString.mid(WarningFlag_index, 2);
        if(myWarningFlag == "--")
           setReplyWarningFlag(Message_Reply_Warning_Flag::NO_WARNING_FLAG);
        else if(myWarningFlag == "FD")
           setReplyWarningFlag(Message_Reply_Warning_Flag::DRIVER_DISABLED);
        else if(myWarningFlag == "FQ")
           setReplyWarningFlag(Message_Reply_Warning_Flag::ENCODER_ERROR);
        else if(myWarningFlag == "FS")
           setReplyWarningFlag(Message_Reply_Warning_Flag::STALLED);
        else if(myWarningFlag == "FE")
           setReplyWarningFlag(Message_Reply_Warning_Flag::LIMIT_ERROR);
        else if(myWarningFlag == "WH")
           setReplyWarningFlag(Message_Reply_Warning_Flag::NOT_HOMED);
        else if(myWarningFlag == "WL")
           setReplyWarningFlag(Message_Reply_Warning_Flag::UNEXPECTED_LIMIT_TRIG);
        else if(myWarningFlag == "WP")
           setReplyWarningFlag(Message_Reply_Warning_Flag::INVALID_CALIBRATION);
        else if(myWarningFlag == "WV")
           setReplyWarningFlag(Message_Reply_Warning_Flag::VOLTAGE_ERROR);
        else if(myWarningFlag == "WT")
           setReplyWarningFlag(Message_Reply_Warning_Flag::TEMPERATURE_ERROR);
        else if(myWarningFlag == "WM")
           setReplyWarningFlag(Message_Reply_Warning_Flag::UNEXPECTED_DISPLACEMENT);
        else if(myWarningFlag == "WR")
           setReplyWarningFlag(Message_Reply_Warning_Flag::NO_REFERENCE_POSITION);
        else if(myWarningFlag == "NC")
           setReplyWarningFlag(Message_Reply_Warning_Flag::BUSY_WITH_MANUAL_CONTRL);
        else if(myWarningFlag == "NI")
           setReplyWarningFlag(Message_Reply_Warning_Flag::COMMAND_INTERRUPTED);
        else if(myWarningFlag == "NU")
           setReplyWarningFlag(Message_Reply_Warning_Flag::UPDATE_OR_RESET_PENDING);
        else
            setReplyWarningFlag(Message_Reply_Warning_Flag::WARNING_FLAG_ERROR);

        if((messageEnd-messageStart) > 18)
        {
            //handle reply data
        }

    }
    else
    {
        m_replyString = "did not understand reply\n";
    }

    return myReplyFlag;
}



////////////////////////////////////////// BEGIN BLOCK CLASS //////////////////////////////////////////
Block::Block(){
    setBlockValid(false);
    setCode(NO_CODE);
}

Block::Block(const QString &toParse, const Message_Mode previousMode, machine_settings_t *settings)
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

void Block::setDwell(const float dwell)
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

Message_Mode Block::getPreviousMode() const
{
    return m_previousMode;
}

void Block::setPreviousMode(const Message_Mode previousMode)
{
    m_previousMode = previousMode;
}

// the juicy bit...
void Block::makeBlock(const QString &toParse, const Message_Mode previousMode, machine_settings_t *settings)
{
    setPreviousMode(previousMode);
    L_Axis()->setDeviceNumber((Device_Number)settings->l_settings.deviceNumber);
    L_Axis()->setAxisNumber((Axis_Number)settings->l_settings.axisNumber);

    X_Axis()->setDeviceNumber((Device_Number)settings->x_settings.deviceNumber);
    X_Axis()->setAxisNumber((Axis_Number)settings->x_settings.axisNumber);
    X_Axis()->setUStepPerMM(settings->x_settings.uStepPerMM);

    Y_Axis()->setDeviceNumber((Device_Number)settings->y_settings.deviceNumber);
    Y_Axis()->setAxisNumber((Axis_Number)settings->y_settings.axisNumber);
    Y_Axis()->setUStepPerMM(settings->y_settings.uStepPerMM);

    Z_Axis()->setDeviceNumber((Device_Number)settings->z_settings.deviceNumber);
    Z_Axis()->setAxisNumber((Axis_Number)settings->z_settings.axisNumber);
    X_Axis()->setUStepPerMM(settings->z_settings.uStepPerMM);

    A_Axis()->setDeviceNumber((Device_Number)settings->a_settings.deviceNumber);
    A_Axis()->setAxisNumber((Axis_Number)settings->a_settings.axisNumber);
    X_Axis()->setUStepPerMM(settings->a_settings.uStepPerMM);

    B_Axis()->setDeviceNumber((Device_Number)settings->b_settings.deviceNumber);
    B_Axis()->setAxisNumber((Axis_Number)settings->b_settings.axisNumber);
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
                        X_Axis()->setMode(ABSOLUTE_MODE);
                        Y_Axis()->setMode(ABSOLUTE_MODE);
                        Z_Axis()->setMode(ABSOLUTE_MODE);
                        A_Axis()->setMode(ABSOLUTE_MODE);
                        B_Axis()->setMode(ABSOLUTE_MODE);
                        setPreviousMode(ABSOLUTE_MODE);
                    }
                    else if(token == "G91") // RELATIVE POSITION
                    {
                        setCode(G91);
                        X_Axis()->setMode(RELATIVE_MODE);
                        Y_Axis()->setMode(RELATIVE_MODE);
                        Z_Axis()->setMode(RELATIVE_MODE);
                        A_Axis()->setMode(RELATIVE_MODE);
                        B_Axis()->setMode(RELATIVE_MODE);
                        setPreviousMode(RELATIVE_MODE);
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
                        if(X_Axis()->getMode() == Message_Mode::RELATIVE_MODE)
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
                        if(Y_Axis()->getMode() == Message_Mode::RELATIVE_MODE)
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
                        if(Z_Axis()->getMode() == Message_Mode::RELATIVE_MODE)
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
                        if(A_Axis()->getMode() == Message_Mode::RELATIVE_MODE)
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
                        if(B_Axis()->getMode() == Message_Mode::RELATIVE_MODE)
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
                            if(X_Axis()->getMode() == ABSOLUTE_MODE)
                            {
                                X_Axis()->setTask(MOVE_ABS_AT_SPEED);
                                X_Axis()->setSpeed(value);
                            }
                            else if(X_Axis()->getMode() == RELATIVE_MODE)
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
                            if(Y_Axis()->getMode() == ABSOLUTE_MODE)
                            {
                                Y_Axis()->setTask(MOVE_ABS_AT_SPEED);
                                Y_Axis()->setSpeed(value);
                            }
                            else if(Y_Axis()->getMode() == RELATIVE_MODE)
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
                            if(Z_Axis()->getMode() == ABSOLUTE_MODE)
                            {
                                Z_Axis()->setTask(MOVE_ABS_AT_SPEED);
                                Z_Axis()->setSpeed(value);
                            }
                            else if(Z_Axis()->getMode() == RELATIVE_MODE)
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
                            if(A_Axis()->getMode() == ABSOLUTE_MODE)
                            {
                                A_Axis()->setTask(MOVE_ABS_AT_SPEED);
                                A_Axis()->setSpeed(value);
                            }
                            else if(A_Axis()->getMode() == RELATIVE_MODE)
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
                            if(B_Axis()->getMode() == ABSOLUTE_MODE)
                            {
                                B_Axis()->setTask(MOVE_ABS_AT_SPEED);
                                B_Axis()->setSpeed(value);
                            }
                            else if(B_Axis()->getMode() == RELATIVE_MODE)
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
        L_Axis()->composeCommandStr();
        X_Axis()->composeCommandStr();
        Y_Axis()->composeCommandStr();
        Z_Axis()->composeCommandStr();
        A_Axis()->composeCommandStr();
        B_Axis()->composeCommandStr();

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

QString Part::displayAxis(const QChar axis_number, const Message axis)
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
        if(axis.getMode() == ABSOLUTE_MODE)
            axisString += "  Absolutie motion instructions to follow\n";
        else if(axis.getMode() == RELATIVE_MODE)
            axisString += "  Relative motion instructions to follow.\n";
        break;
    default:
        axisString += "  Did not recognize Axis task.\n";
        break;
    }
    if(axis.getCommandStr().size() > 1)
        axisString += ("  Command String: " + axis.getCommandStr());
    return axisString;
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

void Part::addLayer(const Layer &aLayer)
{
    m_part.append(aLayer);
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

////////////////////////////////////////// END PART CLASS //////////////////////////////////////////
}


