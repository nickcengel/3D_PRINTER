#ifndef LASER_UTILITY_H
#define LASER_UTILITY_H

#include <QString>
#include <QSharedPointer>
#include "powder_objects/powder_block.h"
#include "powder_objects/powder_settings.h"

// translates the input into a list of command strings, or sets to "EMPTY"
class LaserUtility
{
public:
    LaserUtility();

    static QStringList composeCommandString(PowderBlock *block);

};

#endif // LASER_UTILITY_H
