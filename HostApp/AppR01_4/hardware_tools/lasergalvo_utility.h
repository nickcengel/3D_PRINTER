#ifndef LASERGALVO_UTILITY_H
#define LASERGALVO_UTILITY_H
#include <QSharedPointer>
#include "powder_objects/blockobject.h"
#include "powder_objects/settingsobject.h"

class LaserGalvo_Utility
{
public:
    LaserGalvo_Utility();
    static QString composeCommandString(BlockObject *block, SettingsObject *config);

};

#endif // LASERGALVO_UTILITY_H