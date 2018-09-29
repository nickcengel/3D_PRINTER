#ifndef ZABER_UTILITY_H
#define ZABER_UTILITY_H
#include <QString>
#include <QSharedPointer>
#include "powder_objects/powder_block.h"
#include "powder_objects/powder_settings.h"

// translates the input into a list of command strings, or sets to "EMPTY"
class ZaberUtility
{
public:
    ZaberUtility();

    static QStringList composePositionCommand_String(PowderBlock *block, PowderSettings *config);
    static QStringList composeSpeedCommand_String(PowderBlock *block, PowderSettings *config);

};

#endif // ZABER_UTILITY_H
