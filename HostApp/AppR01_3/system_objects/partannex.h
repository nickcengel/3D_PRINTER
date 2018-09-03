#ifndef PARTANNEX_H
#define PARTANNEX_H

#include <QObject>

#include "partobject.h"
#include "settingsobject.h"
#include <QMetaType>
#include <QSharedPointer>

class PartAnnex : public QObject
{
    Q_OBJECT
    Q_PROPERTY(PartObject *myPart READ getMyPart WRITE setMyPart)
    Q_PROPERTY(SettingsObject *myConfig READ getMyConfig WRITE setMyConfig)

public:
    explicit PartAnnex(QObject *parent = nullptr);
    PartAnnex(const PartAnnex &otherAnnex);
    ~PartAnnex();


    PartObject *getMyPart() const;
    void setMyPart(PartObject *value);

    SettingsObject *getMyConfig() const;
    void setMyConfig(SettingsObject *value);

signals:
    void loadPartComplete();

public slots:
    void loadNewPart(const QString &filePath);


private:
    PartObject *myPart;
    SettingsObject *myConfig;

};

Q_DECLARE_METATYPE(PartAnnex);
#endif // PARTANNEX_H
