#ifndef DEVICEDRIVERS_H
#define DEVICEDRIVERS_H

#include <QMutex>
#include <QThread>
#include <QWaitCondition>

#include "blockio.h"
using BlockIO::Message;
using BlockIO::Message_Type;
using BlockIO::Message_Mode;
using BlockIO::Message_Status;
using BlockIO::Message_Reply_Flag;
using BlockIO::Message_Reply_Flag_Data;
using BlockIO::Message_Reply_Warning_Flag;









class SerialThread : public QThread
{
    Q_OBJECT
public:
    explicit SerialThread(QObject *parent = nullptr);
    ~SerialThread();

    void transaction(const QString &portName, int waitTimeout, const QString &request_str);



signals:
    void response(const QString &responseMessage);
    void error(const QString &s);
    void timeout(const QString &s);

private:
    void run() override;
    QString m_portName;
    QString m_request;
    int m_waitTimeout = 0;
    QMutex m_mutex;
    QWaitCondition m_cond;
    bool m_quit = false;

};

#endif // DEVICEDRIVERS_H
