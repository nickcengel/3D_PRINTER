#include "partannex.h"
#include <QtDebug>
PartAnnex::PartAnnex(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<PartAnnex>("PartAnnex");
    this->setParent(parent);
}

PartAnnex::PartAnnex(const PartAnnex &otherAnnex)
{
    m_myPart = otherAnnex.myPart();
    m_myConfig = otherAnnex.myConfig();
}

PartAnnex::~PartAnnex()
{
    m_myPart.clear();
    m_myConfig.clear();
}


void PartAnnex::loadNewPart(const QString &filePath)
{

    m_myPart = QSharedPointer<PartObject>(new PartObject(filePath, m_myConfig, this));
    emit loadPartComplete();
}

QSharedPointer<SettingsObject> PartAnnex::myConfig() const
{
    return m_myConfig;
}

void PartAnnex::setMyConfig(const QSharedPointer<SettingsObject> &myConfig)
{
    m_myConfig = myConfig;
}

QSharedPointer<PartObject> PartAnnex::myPart() const
{
    return m_myPart;
}

void PartAnnex::setMyPart(const QSharedPointer<PartObject> &myPart)
{
    m_myPart = myPart;
}



