#ifndef ZABER_UTILITY_H
#define ZABER_UTILITY_H
#include <QString>
#include <QSharedPointer>
#include "powder_objects/blockobject.h"
#include "powder_objects/settingsobject.h"

class ZaberUtility
{
public:
    ZaberUtility();

    static QStringList composeCommandString(BlockObject *block, SettingsObject *config);
    static QString composeJogCommandString(BlockObject::BlockTask axisTask, int32_t distance);

};

#endif // ZABER_UTILITY_H
