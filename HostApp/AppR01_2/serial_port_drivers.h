//#ifndef SERIAL_PORT_DRIVERS_H
//#define SERIAL_PORT_DRIVERS_H

//#include <QMutex>
//#include <QThread>
//#include <QWaitCondition>




//class SerialThread : public QThread
//{
//    Q_OBJECT
//public:
//    explicit SerialThread(QObject *parent = nullptr);

//    void transaction(const QString &portName, int waitTimeout, const QString &request_str);



//signals:
//    void response(const QString &responseMessage);
//    void error(const QString &s);
//    void timeout(const QString &s);

//private:
//    void run() override;
//    QString m_portName;
//    QString m_request;
//    int m_waitTimeout = 0;
//    QMutex m_mutex;
//    QWaitCondition m_cond;
//    bool m_quit = false;

//};

//#endif // SERIAL_PORT_DRIVERS_H
