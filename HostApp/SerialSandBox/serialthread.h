#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QMutex>
#include <QThread>
#include <QWaitCondition>

class SerialThread : public QThread
{
    Q_OBJECT
public:
    explicit SerialThread(QObject *parent = nullptr);
    ~SerialThread();

    void transaction(const QString &portName, qint32 baudRate ,int waitTimeout, const QString &request_str);



signals:
    void response(const QString &response_str);
    void error(const QString &s);
    void timeout(const QString &s);

private:
    void run() override;
    QString m_portName;
    QString m_request;
    int m_waitTimeout = 0;
    qint32 m_baudRate;
    QMutex m_mutex;
    QWaitCondition m_cond;
    bool m_quit = false;

};

#endif // SERIALTHREAD_H
