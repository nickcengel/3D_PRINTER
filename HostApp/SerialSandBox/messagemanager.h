#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H

#include <QObject>

class MessageManager : public QObject
{
    Q_OBJECT
public:
    explicit MessageManager(QObject *parent = nullptr);

    void sendCommand(const QString &command);
    void receiveReply(const QString &reply);

signals:
    void newMessage(const QString &request); ///connected to

public slots:


private:
    QString m_pendingCommand;
    QString m_lastReply;
    QString m_error;
};

#endif // MESSAGEMANAGER_H
