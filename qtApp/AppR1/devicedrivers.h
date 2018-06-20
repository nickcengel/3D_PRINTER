#ifndef DEVICEDRIVERS_H
#define DEVICEDRIVERS_H

#include <QMutex>
#include <QThread>
#include <QWaitCondition>

#include "blockio.h"
using BlockIO::Message;
using BlockIO::LG_Package;
using BlockIO::MD_Package;
using BlockIO::Tasks;
using BlockIO::LG_Map;
using BlockIO::MD_Map;

QString messageToString(Message myMessage);

class SerialThread : public QThread
{
    Q_OBJECT
public:
    explicit SerialThread(QObject *parent = nullptr);
    ~SerialThread();

    void transaction(const QString &portName, int waitTimeout, const LG_Package &request);

    QByteArray messageToBytes(BlockIO::Message myMessage);
    QByteArrayList packageToByteList(BlockIO::LG_Package myPackage);

    BlockIO::Message bytesToMessage(QByteArray myBytes);

    int MMtoMicrostep(const float mm, const int stepPerMillimeter);


signals:
    void response(const LG_Package responsePackage);
    void error(const QString &s);
    void timeout(const QString &s);

private:
    void run() override;
    QString m_portName;
    LG_Package m_request;
    int m_waitTimeout = 0;
    QMutex m_mutex;
    QWaitCondition m_cond;
    bool m_quit = false;

};

#endif // DEVICEDRIVERS_H
