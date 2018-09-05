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
    Q_PROPERTY(QSharedPointer<PartObject> myPart READ myPart WRITE setMyPart)
    Q_PROPERTY(QSharedPointer<SettingsObject> myConfig READ myConfig WRITE setMyConfig)

public:
    explicit PartAnnex(QObject *parent = nullptr);
    PartAnnex(const PartAnnex &otherAnnex);
    ~PartAnnex();

    QSharedPointer<PartObject> myPart() const;
    void setMyPart(const QSharedPointer<PartObject> &myPart);

    QSharedPointer<SettingsObject> myConfig() const;
    void setMyConfig(const QSharedPointer<SettingsObject> &myConfig);

signals:
    void loadPartComplete();

public slots:
    void loadNewPart(const QString &filePath);


private:
    QSharedPointer<PartObject> m_myPart;
    QSharedPointer<SettingsObject> m_myConfig;
};

Q_DECLARE_METATYPE(PartAnnex);
#endif // PARTANNEX_H
