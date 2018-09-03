#include "partannex.h"
#include <QtDebug>
PartAnnex::PartAnnex(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<PartAnnex>("PartAnnex");
    this->setParent(parent);
    myPart = nullptr;
    myConfig = nullptr;
}

PartAnnex::PartAnnex(const PartAnnex &otherAnnex)
{
    myPart = otherAnnex.getMyPart();
    myConfig = otherAnnex.getMyConfig();
}

PartAnnex::~PartAnnex()
{
    if(myPart != nullptr)
        delete myPart;
}

PartObject *PartAnnex::getMyPart() const
{
    return myPart;
}

void PartAnnex::setMyPart(PartObject *value)
{
    myPart = value;
}

void PartAnnex::loadNewPart(const QString &filePath)
{
    myPart = new PartObject(filePath, myConfig, this);
    emit loadPartComplete();
}



SettingsObject *PartAnnex::getMyConfig() const
{
    return myConfig;
}

void PartAnnex::setMyConfig(SettingsObject *value)
{
    myConfig = value;
}

