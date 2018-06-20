#include "devicedrivers.h"
#include <QSerialPort>
#include <QTime>

#include "blockio.h"
using BlockIO::Message;
using BlockIO::LG_Package;
using BlockIO::Tasks;
using BlockIO::LG_Map;

//enum LG_Map{LG_NONE, X_ONLY, Y_ONLY, X_Y, LASER_ONLY, X_LASER, Y_LASER, LG_ALL,LG_FAILED};
//enum Tasks{NONE = 0, DISABLE, POSITION, POSITION_SPEED, HOME, RELATIVE, ABSOLUTE, ENABLE, ENABLE_POWER, POWER, DWELL, FAILED};


QString messageToString(Message myMessage)
{
 QString myString;

 const Tasks myTask = myMessage.task();
 if(myTask == Tasks::POSITION)
 {
    myString = "/1 move abs"+ QString::number(myMessage.D0());
 }
 else if(myTask == Tasks::POSITION_SPEED)
 {
     myBytes = QByteArray::number((int)myTask);
     const int myPosition = MMtoMicrostep(myMessage.D0(),1000);
     myBytes += QByteArray::number(myPosition);
     const int mySpeed = (int)myMessage.D1();
     myBytes += mySpeed;
 }
 else if(myTask == Tasks::ENABLE_POWER)
 {
     myBytes = QByteArray::number((int)myTask);
     myBytes += QByteArray::number(1);
     const int myPower = (int)myMessage.D1();
     myBytes += myPower;
 }
 else if(myTask == Tasks::POWER)
 {
     myBytes = QByteArray::number((int)myTask);
     myBytes += QByteArray::number(0);
     const int myPower = (int)myMessage.D1();
     myBytes += myPower;
 }
 else if(myTask == Tasks::DWELL)
 {
     myBytes = QByteArray::number((int)myTask);
     const int myTime = (int)myMessage.D0();
     myBytes += myTime;
 }
 else if((myTask >= Tasks::NONE) && (myTask < Tasks::FAILED))
 {   // handle simple tasks
     myBytes = QByteArray::number((int)myTask);
 }
 else
 {
     myBytes = QByteArray::number((int)Tasks::FAILED);
 }



 return myString;
}



int SerialThread::MMtoMicrostep(const float mm, const int stepPerMillimeter)
{
    return (int)(mm*stepPerMillimeter);
}


QByteArray SerialThread::messageToBytes(BlockIO::Message myMessage)
{   // handle messages that contain values
    const Tasks myTask = myMessage.task();
    QByteArray myBytes;
    if(myTask == Tasks::POSITION)
    {
        myBytes = QByteArray::number((int)myTask);
        const int myPosition = MMtoMicrostep(myMessage.D0(),1000);
        myBytes += QByteArray::number(myPosition);
    }
    else if(myTask == Tasks::POSITION_SPEED)
    {
        myBytes = QByteArray::number((int)myTask);
        const int myPosition = MMtoMicrostep(myMessage.D0(),1000);
        myBytes += QByteArray::number(myPosition);
        const int mySpeed = (int)myMessage.D1();
        myBytes += mySpeed;
    }
    else if(myTask == Tasks::ENABLE_POWER)
    {
        myBytes = QByteArray::number((int)myTask);
        myBytes += QByteArray::number(1);
        const int myPower = (int)myMessage.D1();
        myBytes += myPower;
    }
    else if(myTask == Tasks::POWER)
    {
        myBytes = QByteArray::number((int)myTask);
        myBytes += QByteArray::number(0);
        const int myPower = (int)myMessage.D1();
        myBytes += myPower;
    }
    else if(myTask == Tasks::DWELL)
    {
        myBytes = QByteArray::number((int)myTask);
        const int myTime = (int)myMessage.D0();
        myBytes += myTime;
    }
    else if((myTask >= Tasks::NONE) && (myTask < Tasks::FAILED))
    {   // handle simple tasks
        myBytes = QByteArray::number((int)myTask);
    }
    else
    {
        myBytes = QByteArray::number((int)Tasks::FAILED);
    }

    return myBytes;
}

QByteArrayList SerialThread::packageToByteList(LG_Package myPackage)
{
    QByteArrayList myList;
    BlockIO::LG_Map myMap = myPackage.getMap();
    myList.append(QByteArray::number((int)myMap));
    if(myMap ==  BlockIO::LG_Map::X_ONLY)
    {
        const QByteArray bytes = messageToBytes(*myPackage.x_message());
        myList.append(bytes);
    }
    else if (myMap ==  BlockIO::LG_Map::Y_ONLY)
    {
        const QByteArray bytes = messageToBytes(*myPackage.y_message());
        myList.append(bytes);
    }
    else if (myMap ==  BlockIO::LG_Map::LASER_ONLY)
    {
        const QByteArray bytes = messageToBytes(*myPackage.laser_message());
        myList.append(bytes);
    }
    else if (myMap ==  BlockIO::LG_Map::X_Y)
    {
        const QByteArray bytes = messageToBytes(*myPackage.x_message());
        myList.append(bytes);
        const QByteArray moreBytes = messageToBytes(*myPackage.y_message());
        myList.append(moreBytes);
    }
    else if (myMap ==  BlockIO::LG_Map::X_LASER)
    {
        const QByteArray bytes = messageToBytes(*myPackage.x_message());
        myList.append(bytes);
        const QByteArray moreBytes = messageToBytes(*myPackage.laser_message());
        myList.append(moreBytes);
    }
    else if (myMap ==  BlockIO::LG_Map::Y_LASER)
    {
        const QByteArray bytes = messageToBytes(*myPackage.y_message());
        myList.append(bytes);
        const QByteArray moreBytes = messageToBytes(*myPackage.laser_message());
        myList.append(moreBytes);
    }
    else if (myMap ==  BlockIO::LG_Map::LG_ALL)
    {
        const QByteArray bytes = messageToBytes(*myPackage.x_message());
        myList.append(bytes);
        const QByteArray moreBytes = messageToBytes(*myPackage.y_message());
        myList.append(moreBytes);
        const QByteArray bitMoreBytes = messageToBytes(*myPackage.laser_message());
        myList.append(bitMoreBytes);
    }
    else
    {
        myList[0] = QByteArray::number((int)BlockIO::LG_Map::LG_FAILED);
    }
    return myList;
}
//enum Tasks{NONE = 0, DISABLE, POSITION, POSITION_SPEED, HOME, RELATIVE, ABSOLUTE, ENABLE, ENABLE_POWER, POWER, DWELL,FAILED};

BlockIO::Message SerialThread::bytesToMessage(QByteArray myBytes)
{
    BlockIO::Message myMessage;
    // is the task valid
    bool taskNumberValid;
    // first byte
    const BlockIO::Tasks myTask = (Tasks) myBytes.left(1).toInt(&taskNumberValid,10);
    if(taskNumberValid) // we got back a number
    {
        if(myTask == Tasks::POSITION)
        {
            myMessage.setTask(myTask);
            bool positionValid = false;
            // second value
            const int myPosition = myBytes.mid(1,2).toInt(&positionValid,10);
            if(positionValid)
                myMessage.setD0((float)myPosition);
        }
        else if(myTask == Tasks::POSITION_SPEED)
        {
            myMessage.setTask(myTask);
            bool positionValid = false;
            // second value
            const int myPosition = myBytes.mid(1,2).toInt(&positionValid,10);
            if(positionValid)
                myMessage.setD0((float)myPosition);
            // third value
            bool speedValid = false;
            const int mySpeed = myBytes.mid(3,2).toInt(&speedValid,10);
            if(speedValid)
                myMessage.setD1(mySpeed);
        }
        else if(myTask == Tasks::ENABLE_POWER)
        {
            myMessage.setTask(myTask);
            bool stateValid;
            // second value
            const int myState = myBytes.mid(1,2).toInt(&stateValid,10);
            if(stateValid)
                myMessage.setD0((float)myState);
            // third value
            bool powerValid = false;
            const int myPower = myBytes.mid(3,2).toInt(&powerValid,10);
            if(powerValid)
                myMessage.setD1(myPower);
        }
        else if(myTask == Tasks::POWER)
        {
            myMessage.setTask(myTask);
            bool stateValid;
            // second value
            const int myState = myBytes.mid(1,2).toInt(&stateValid,10);
            if(stateValid)
                myMessage.setD0((float)myState);
            // third value
            bool powerValid = false;
            const int myPower = myBytes.mid(3,2).toInt(&powerValid,10);
            if(powerValid)
                myMessage.setD1(myPower);
        }
        else if(myTask == Tasks::DWELL)
        {
            myMessage.setTask(myTask);
            bool dwellValid;
            // second value
            const int myDwell = myBytes.mid(1,2).toInt(&dwellValid,10);
            if(dwellValid)
                myMessage.setD0((float)myDwell);
        }
        else if((myTask >= Tasks::NONE) && (myTask < Tasks::FAILED))
        {   // handle simple tasks
            myMessage.setTask(myTask);
        }
        else
        { // handle error
            myMessage.setTask(BlockIO::Tasks::FAILED);
        }

    }
    else
    {
        //handle error
        myMessage.setTask(BlockIO::Tasks::FAILED);
    }
    return myMessage;
}


SerialThread::SerialThread(QObject *parent) :
    QThread(parent)
{
}


SerialThread::~SerialThread()
{
    m_mutex.lock();
    m_quit = true;
    m_cond.wakeOne();
    m_mutex.unlock();
    wait();
}

void SerialThread::transaction(const QString &portName, int waitTimeout, const BlockIO::LG_Package &request)
{
    const QMutexLocker locker(&m_mutex);
    m_portName = portName;
    m_waitTimeout = waitTimeout;
    m_request = request;

    if (!isRunning())
        start();
    else
        m_cond.wakeOne();
}

void SerialThread::run()
{
    bool currentPortNameChanged = false;

    m_mutex.lock();
    QString currentPortName;
    if (currentPortName != m_portName) {
        currentPortName = m_portName;
        currentPortNameChanged = true;
    }
    int currentWaitTimeout = m_waitTimeout;
    LG_Package currentRequest = m_request;
    m_mutex.unlock();


    QSerialPort serial;

    if (currentPortName.isEmpty()) {
        emit error(tr("No port name specified"));
        return;
    }

    // open port
    while (!m_quit) {
        if (currentPortNameChanged) {
            serial.close();
            serial.setPortName(currentPortName);

            if (!serial.open(QIODevice::ReadWrite)) {
                emit error(tr("Can't open %1, error code %2")
                           .arg(m_portName).arg(serial.error()));
                return;
            }
        }



        const QByteArrayList requestData = packageToByteList(currentRequest);
        int packageSize = requestData.size();

        LG_Package responsePackage;
        responsePackage.setMap(BlockIO::LG_Map::LG_NONE);

        for(int i = 0; i < packageSize; i++)
        {   // write out a Message
            const QByteArray data = requestData[i];
            serial.write(data);


            // wait for the bytes to be written to port
            if(serial.waitForBytesWritten(m_waitTimeout))
            {
                if(serial.waitForReadyRead(currentWaitTimeout))
                {   // we didn't time out, so grab what is there

                 QByteArray responseData = serial.readAll();
                if(i == 0)
                {

                }
                Message newMessage = bytesToMessage(responseData);


                }
                else // did  not get a reply
                {

                }
            }
            else // did not write bytes to port
            {
                emit timeout(tr("Wait write request timeout %1")
                             .arg(QTime::currentTime().toString()));
            }
        }

        // write request
        //        const QByteArray requestData = packageToBytes(currentRequest);
        //        serial.write(requestData); //*******
        //        if (serial.waitForBytesWritten(m_waitTimeout)) {

        //            // read response
        //            if (serial.waitForReadyRead(currentWaitTimeout)) {
        //                // we havent timed out, see what we get
        //                QByteArray responseData = serial.readAll();
        //                if(responseData.size() == 6)
        //                    {
        ////                    const LG_Package responsePackage = bytesToPackage(responseData);
        ////                    emit this->response(responsePackage);
        //                    }

        //            } else {
        //                emit timeout(tr("Wait read response timeout %1")
        //                             .arg(QTime::currentTime().toString()));
        //            }
        //        } else {
        //            emit timeout(tr("Wait write request timeout %1")
        //                         .arg(QTime::currentTime().toString()));
        //        }
        // update thread/port info
        m_mutex.lock();
        m_cond.wait(&m_mutex);
        if (currentPortName != m_portName) {
            currentPortName = m_portName;
            currentPortNameChanged = true;
        } else {
            currentPortNameChanged = false;
        }
        currentWaitTimeout = m_waitTimeout;
        currentRequest = m_request;
        m_mutex.unlock();
    }
}
