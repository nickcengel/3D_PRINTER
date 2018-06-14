
#include "blockio.h"


namespace BlockIO {


Block::Block(){
    initializeBlock(-1,-1);
}

Block::Block(const QString toParse, const int lineNumber, const int layerNumber){

    initializeBlock(lineNumber, layerNumber);
    makeBlock(toParse);
}

void Block::setCode(const Code code){
    m_command.code = code;
    m_command.pending = 1;
}

void Block::setDwell(const float time){
    m_dwell.value = time;
    m_dwell.pending = 1;
}

void Block::setLaserState(const bool enable){
    m_laser.enabled.state = enable;
    m_laser.enabled.pending = 1;
}

void Block::setLaserPower(const float power){
    m_laser.power.value = power;
    m_laser.power.pending = 1;
}


void Block::setState_x(const bool enable){
    m_x_axis.enabled.state = enable;
    m_x_axis.enabled.pending = 1;
}

void Block::setState_y(const bool enable){
    m_y_axis.enabled.state = enable;
    m_y_axis.enabled.pending = 1;
}

void Block::setState_z(const bool enable){
    m_z_axis.enabled.state = enable;
    m_z_axis.enabled.pending = 1;
}

void Block::setState_a(const bool enable){
    m_a_axis.enabled.state = enable;
    m_a_axis.enabled.pending = 1;
}

void Block::setState_b(const bool enable){
    m_b_axis.enabled.state = enable;
    m_b_axis.enabled.pending = 1;
}

void Block::setPosition_x(const float x){
    m_x_axis.position.value = x;
    m_x_axis.position.pending = 1;
}
void Block::setPosition_y(const float y){
    m_y_axis.position.value = y;
    m_y_axis.position.pending = 1;
}
void Block::setPosition_z(const float z){
    m_z_axis.position.value = z;
    m_z_axis.position.pending = 1;
}
void Block::setPosition_a(const float a){
    m_a_axis.position.value = a;
    m_a_axis.position.pending = 1;
}
void Block::setPosition_b(const float b){
    m_b_axis.position.value = b;
    m_b_axis.position.pending = 1;
}

void Block::setSpeed_x(const float sx){
    m_x_axis.speed.value = sx;
    m_x_axis.speed.pending = 1;
}
void Block::setSpeed_y(const float sy){
    m_y_axis.speed.value = sy;
    m_y_axis.speed.pending = 1;
}
void Block::setSpeed_z(const float sz){
    m_z_axis.speed.value = sz;
    m_z_axis.speed.pending = 1;
}
void Block::setSpeed_a(const float sa){
    m_a_axis.speed.value = sa;
    m_a_axis.speed.pending = 1;
}
void Block::setSpeed_b(const float sb){
    m_b_axis.speed.value = sb;
    m_b_axis.speed.pending = 1;
}

void Block::setGoHome_x(){
    m_x_axis.goHome.state = 1;
    m_x_axis.goHome.pending = 1;
}
void Block::setGoHome_y(){
    m_y_axis.goHome.state = 1;
    m_y_axis.goHome.pending = 1;
}
void Block::setGoHome_z(){
    m_z_axis.goHome.state = 1;
    m_z_axis.goHome.pending = 1;
}
void Block::setGoHome_a(){
    m_a_axis.goHome.state = 1;
    m_a_axis.goHome.pending = 1;
}
void Block::setGoHome_b(){
    m_b_axis.goHome.state = 1;
    m_b_axis.goHome.pending = 1;
}

bool Block::newLayerFlag(){
    return m_newLayerFlag;
}


void Block::initializeBlock(int lineNumber, int layerNumber){
    m_lineNumber = lineNumber;
    m_layerNumber = layerNumber;
    m_newLayerFlag = false;
    m_command.pending = 0;

    m_x_axis.axis = X;
    m_x_axis.enabled.pending = 0;
    m_x_axis.position.pending = 0;
    m_x_axis.speed.pending = 0;
    m_x_axis.goHome.pending = 0;

    m_y_axis.axis = Y;
    m_y_axis.enabled.pending = 0;
    m_y_axis.position.pending = 0;
    m_y_axis.speed.pending = 0;
    m_y_axis.goHome.pending = 0;


    m_z_axis.axis = Z;
    m_z_axis.enabled.pending = 0;
    m_z_axis.position.pending = 0;
    m_z_axis.speed.pending = 0;
    m_z_axis.goHome.pending = 0;


    m_a_axis.axis = A;
    m_a_axis.enabled.pending = 0;
    m_a_axis.position.pending = 0;
    m_a_axis.speed.pending = 0;
    m_a_axis.goHome.pending = 0;


    m_b_axis.axis = B;
    m_b_axis.enabled.pending = 0;
    m_b_axis.position.pending = 0;
    m_b_axis.speed.pending = 0;
    m_b_axis.goHome.pending = 0;


    m_laser.enabled.pending = 0;
    m_laser.power.pending = 0;

    m_dwell.pending = 0;
}

QString Block::printAxis(axis_t a)
{
    QString axisString;
    if(a.goHome.pending||a.position.pending){
        switch (a.axis) {
        case X:
            axisString = "X Axis ";
            break;
        case Y:
            axisString = "Y Axis";
            break;
        case Z:
            axisString = "Z Axis";
            break;
        case A:
            axisString = "A Axis";
            break;
        case B:
            axisString = "B Axis";
            break;
        default:
            break;
        }
        if(a.goHome.pending)
            axisString += " goes home";
        else if(a.position.pending){
            axisString += " moves to ";
            axisString += a.position.value;
            if(a.speed.pending){
                axisString += " at a speed of ";
                axisString += a.speed.value;
            }
        }

    }
    return axisString;
}


QStringList Block::printBlock(){
    QStringList blockStrings;
    blockStrings<<"Comment: " +m_comment;
    if(m_command.pending){
        QString commandString = "Command: ";
        switch (m_command.code) {
        case M0:
            commandString += "M0 - PAUSE";
            break;
        case M2:
            commandString += "M2 - END";
            break;
        case M3:
            commandString += "M3 - LASER ON";
            break;
        case M5:
            commandString += "M5 - LASER OFF";
            break;
        case G0:
            commandString += "G0 - RAPID MOVE";
            break;
        case G1:
            commandString += "G1 - LINEAR MOVE";
            break;
        case G4:
            commandString += "G4 - DWELL";
            break;
        case G28:
            commandString += "G28 - HOME";
            break;
        case G90:
            commandString += "G90 - ABSOLUTE POSITIONING";
            break;
        case G91:
            commandString += "G91 - RELATIVE POSITIONING";
            break;
        default:
            commandString += "unknown";
            break;
        }
        blockStrings<<commandString;
    }

    blockStrings<<"X: " + printAxis(m_x_axis);
    blockStrings<<"Y: " + printAxis(m_y_axis);
    blockStrings<<"Z: " + printAxis(m_z_axis);
    blockStrings<<"A: " + printAxis(m_a_axis);
    blockStrings<<"B: " + printAxis(m_b_axis);

    if (m_laser.enabled.pending)
    {
        QString laserString = "Laser is ";
        if (m_laser.enabled.state)
        {
            laserString += "on. ";
            if (m_laser.power.pending)
                laserString += "Laser power = "+ QString::number(m_laser.power.value);
        }
        else
            laserString += "off.";
        blockStrings<<laserString;
    }

    if(m_dwell.pending)
    {
        QString dwellString = "Delay for "+ QString::number(m_dwell.value);
        blockStrings<<dwellString;
    }

    if(m_errors.size() > 0)
    {
        blockStrings<<m_errors;
    }
    return blockStrings;
}




//  The makeBlock method is the heart of the GCODE Parser. It fills a Block with the data from a single line
//  * NOTE: We require spaces between items, but not between the item and the value itself.
//      GOOD: G0 X1 Y1.42 Z4.0 (comments look like this)
//      BAD: G0X1Y1.42Z4.0 comments all over the place
//      ALSO BAD: G0 X 1 Y 1.42 Z 4.0 *//
void Block::makeBlock(const QString toParse){

    // BEGIN splitting up comments and commands ///
    QString c_line; // comments go here
    QString g_line; // commands go here
    int startComment;
    int endComment;
    int commentSize;

    if((toParse.indexOf('/') == 0)||(toParse.size()<2)){  // Ignore empty lines or ones that begin with '/'
        m_comment = "Ignored: " + toParse;
        return;
    }
    // deal with (this style) of comment
    else if(toParse.contains('('))
    {
        startComment = toParse.indexOf('(');
        endComment = toParse.indexOf(')');
        if(endComment == -1)
        {
            endComment = toParse.size();
            m_errors << "Could not find comment's closing ')'";
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
    else if(toParse.contains(';')){
        startComment = toParse.indexOf(';');
        if(startComment == 0){  // if line starts with ; the rest is a comment
            c_line = toParse.right(toParse.size()-1);
            g_line.clear();
        }
        else{   // pick up a comment after a command
            commentSize = toParse.size() - startComment - 1;
            c_line = toParse.right(commentSize);
            g_line = toParse.left(toParse.size() - commentSize - 2);
        }
    }
    else
        g_line = toParse;

    if(c_line.contains("NEW_LAYER"))
        m_newLayerFlag = true;

    m_comment = c_line;

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
                    setCode(G90);
                else if(token == "G91") // RELATIVE POSITION
                    setCode(G91);
                else
                    m_errors<<"Did not recognize instruction: \""+token+"\"";
                break;
            case 'M':
                // So setCode with matching enumerated code
                if(token == "M0")   // PAUSE
                    setCode(M0);
                else if(token == "M2")  //  END PROGRAM
                    setCode(M2);
                else if(token == "M3"){  // LASER ON
                    setCode(M3);
                    setLaserState(true);
                }
                else if(token == "M5"){  // LASER OFF
                    setCode(M5);
                    setLaserState(false);
                }
                else
                    m_errors<<"Did not recognize instruction: \""+token+"\"";
                break;

                // If the first character is X,Y,Z,A,or B, we are talking about an axis
            case 'X':
                //  Check that a relevant command is requested and set new position
                //  Check if the position is a valid number
                if((m_command.code == G0)||(m_command.code == G1))
                {
                    bool valueValid = false;
                    float value = token.right(1-token.size()).toFloat(&valueValid);
                    if(valueValid)
                        setPosition_x(value);
                    else
                        m_errors<<"Invalid number!";
                }
                // No position data means we want to return axis to home
                // check for homing code
                else if((token.size() == 1) && (m_command.code == G28))
                    setGoHome_x();
                else
                    m_errors<<"Did not recognize instruction: \""+token+"\"";
                break;

            case 'Y':
                if((m_command.code == G0)||(m_command.code == G1))
                {
                    bool valueValid = false;
                    float value = token.right(1-token.size()).toFloat(&valueValid);
                    if(valueValid)
                        setPosition_y(value);
                    else
                        m_errors<<"Invalid number!";
                }
                else if((token.size() == 1) && (m_command.code == G28))
                    setGoHome_y();
                else
                    m_errors<<"Did not recognize instruction: \""+token+"\"";
                break;


            case 'Z':
                if((m_command.code == G0)||(m_command.code == G1))
                {
                    bool valueValid = false;
                    float value = token.right(1-token.size()).toFloat(&valueValid);
                    if(valueValid)
                        setPosition_z(value);
                    else
                        m_errors<<"Invalid number!";
                }
                else if((token.size() == 1) && (m_command.code == G28))
                    setGoHome_z();
                else
                    m_errors<<"Did not recognize instruction: \""+token+"\"";
                break;


            case 'A':
                if((m_command.code == G0)||(m_command.code == G1))
                {
                    bool valueValid = false;
                    float value = token.right(1-token.size()).toFloat(&valueValid);
                    if(valueValid)
                        setPosition_a(value);
                    else
                        m_errors<<"Invalid number!";
                }
                else if((token.size() == 1) && (m_command.code == G28))
                    setGoHome_a();
                else
                    m_errors<<"Did not recognize instruction: \""+token+"\"";
                break;


            case 'B':
                if((m_command.code == G0)||(m_command.code == G1))
                {
                    bool valueValid = false;
                    float value = token.right(1-token.size()).toFloat(&valueValid);
                    if(valueValid)
                        setPosition_b(value);
                    else
                        m_errors<<"Invalid number!";
                }
                else if((token.size() == 1) && (m_command.code == G28))
                    setGoHome_b();
                else
                    m_errors<<"Did not recognize instruction: \""+token+"\"";
                break;


                // E used to indicate the current movement corresponds to an active print command.
                // This follows from the extrusion printer convention. Where E is used to control
                // the amount of material extruded. In our cases, we simpply check if a line contains
                // 'E'. This means we should turn the laser on.
            case 'E':
                // But first, check that this line will in fact move the x/y axes.
                if((m_command.code == G1)&&(m_x_axis.position.pending || m_y_axis.position.pending))
                    setLaserState(true);    // This is equivalent to prefaicing a move with M3/M5
                break;

                // F used to modify speed. We only want to set the speed for an axis we intend
                // to move with this block, so check to see if each axis has a pending move.
            case 'F':
            {
                bool valueValid = false;
                float value = token.right(1-token.size()).toFloat(&valueValid);
                if(valueValid){
                    if(m_x_axis.position.pending)
                        setSpeed_x(value);
                    if(m_y_axis.position.pending)
                        setSpeed_y(value);
                    if(m_z_axis.position.pending)
                        setSpeed_z(value);
                    if(m_a_axis.position.pending)
                        setSpeed_a(value);
                    if(m_b_axis.position.pending)
                        setSpeed_b(value);
                }
                else
                    m_errors<<"Did not recognize instruction: \""+token+"\"";
                break;
            }
                // P signals a dwell time is to be set and observed.
            case 'P':
            {
                bool valueValid = false;
                float value = token.right(1-token.size()).toFloat(&valueValid);
                if(valueValid)
                    setDwell(value);
                else
                    m_errors<<"Did not recognize instruction: \""+token+"\"";

                break;
            }

                // S used to modify laser power.
            case 'S':
            {
                bool valueValid = false;
                float value = token.right(1-token.size()).toFloat(&valueValid);
                if(valueValid)
                    setLaserPower(value);
                else
                    m_errors<<"Did not recognize instruction: \""+token+"\"";

                break;
            }

            default:
                m_errors<<"Did not recognize instruction: \""+token+"\"";
                break;
            } //end switch
        }//end token
    }//end if
}//end makeblock

QVector<layer_t> convertGcode(QString fileName){
    QVector<layer_t> layerStack;
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);

        int lineNumber = 0;
        int layerNumber = 0;
        bool layerFlag = false;

        while (!in.atEnd())
        {
//            layer_t *tempLayer = new layer_t;
//            newLayerFlag = false;

            while(!layerFlag && !in.atEnd()){
                QString line = in.readLine();
 //                qDebug()<<line;
                 Block a(line, lineNumber, 0);
                 lineNumber++;
                // qDebug()<<a.printBlock();
                 layerFlag = a.newLayerFlag()

                 }


//                tempLayer->append(BlockIO::Block(line, lineNumber, layerNumber));

//                newLayerFlag = tempLayer->last().newLayerFlag();
            }
//            layerStack.append(*tempLayer);
//            delete tempLayer;
//            layerNumber++;
        }
        file.close();
    }
    else
        qDebug()<<"Could not open file";

    return layerStack;
}



}






