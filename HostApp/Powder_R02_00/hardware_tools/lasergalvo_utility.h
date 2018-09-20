#ifndef LASERGALVO_UTILITY_H
#define LASERGALVO_UTILITY_H
#include <QSharedPointer>
#include "powder_objects/powder_block.h"
#include "powder_objects/powder_settings.h"


// translates the input into a command string, or sets to "EMPTY"
class LaserGalvo_Utility
{
public:
    LaserGalvo_Utility();
    static QString composeCommandString(PowderBlock *block, PowderSettings *config);
    static QString composeJogCommandString(PowderBlock::BlockTask axisTask, int32_t steps);

};

#endif // LASERGALVO_UTILITY_H
