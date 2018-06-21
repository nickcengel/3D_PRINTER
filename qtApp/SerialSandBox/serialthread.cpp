#include "serialthread.h"
#include <QSerialPort>
#include <QTime>

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

void SerialThread::transaction(const QString &portName, int waitTimeout, const QString &request_str)
{
    const QMutexLocker locker(&m_mutex);
    m_portName = portName;
    m_waitTimeout = waitTimeout;
    m_request = request_str;

    if (!isRunning())
        start();
    else
        m_cond.wakeOne();
}

void SerialThread::run()
{
    emit response(m_request);
//    bool currentPortNameChanged = false;

//    m_mutex.lock();
//    QString currentPortName;
//    if (currentPortName != m_portName) {
//        currentPortName = m_portName;
//        currentPortNameChanged = true;
//    }
//    int currentWaitTimeout = m_waitTimeout;
//    QString currentRequest = m_request;
//    m_mutex.unlock();

//    QSerialPort serial;
//    serial.setPortName(m_portName);

//    if (m_portName.isEmpty()) {
//        emit error(tr("No port name specified"));
//        return;
//    }

//    while (!m_quit) {

//        if (!serial.open(QIODevice::ReadWrite)) {
//            emit error(tr("Can't open %1, error code %2")
//                       .arg(m_portName).arg(serial.error()));
//            return;
//        }

//        if((serial.bytesAvailable() > 0) || (serial.bytesToWrite() > 0))
//            serial.clear();
//        // write request
//        const QByteArray requestData = currentRequest.toUtf8();
//        serial.write(requestData);
//        if (serial.waitForBytesWritten(m_waitTimeout)) {
//            // read response
//            if (serial.waitForReadyRead(m_waitTimeout)) {
//                // found data before timing out
//                QByteArray responseData = serial.readAll();

//                // get up to 32 bytes
//                while ((responseData.size() < 32))
//                {
//                    if(!serial.waitForReadyRead(m_waitTimeout))
//                        break;  // if we timeout while waiting for bytes, give up
//                    else
//                        responseData += serial.readAll();   // otherwise, add the new data
//                }

//                const QString response_str = QString::fromUtf8(responseData);
////                const Message responseMessage(response_str);
//                emit this->response(response_str);


//            } else {
//                emit timeout(tr("Wait read response timeout %1")
//                             .arg(QTime::currentTime().toString()));
//            }

//        } else {
//            emit timeout(tr("Wait write request timeout %1")
//                         .arg(QTime::currentTime().toString()));
//        }

//        //serial.close();

//        m_mutex.lock();
//        m_cond.wait(&m_mutex);
//        if (currentPortName != m_portName) {
//            currentPortName = m_portName;
//            currentPortNameChanged = true;
//        } else {
//            currentPortNameChanged = false;
//        }
//        currentWaitTimeout = m_waitTimeout;
//        currentRequest = m_request;
//        m_mutex.unlock();
//    }
}
