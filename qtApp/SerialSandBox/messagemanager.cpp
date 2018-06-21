#include "messagemanager.h"

MessageManager::MessageManager(QObject *parent) : QObject(parent)
{

}

void MessageManager::sendCommand(const QString &command)
{
    m_pendingCommand = command;
    emit newMessage(m_pendingCommand);
}

void MessageManager::receiveReply(const QString &reply)
{
    m_lastReply = reply;
}

