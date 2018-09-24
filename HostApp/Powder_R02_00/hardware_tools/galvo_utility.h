#ifndef GALVO_UTILITY_H
#define GALVO_UTILITY_H
#include <QSharedPointer>
#include "powder_objects/powder_block.h"
#include "powder_objects/powder_settings.h"


// translates the input into a command string, or sets to "EMPTY"
class GalvoUtility
{
public:
    GalvoUtility();
    static QString composeCommandString(PowderBlock *block, PowderSettings *config);
    static QString composeJogCommandString(PowderBlock::BlockTask axisTask, int32_t steps);

};

#endif // GALVO_UTILITY_H
