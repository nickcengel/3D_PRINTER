#include "laser_utility.h"

LaserUtility::LaserUtility()
{

}

QStringList LaserUtility::composeCommandString(PowderBlock *block)
{
    QStringList outputList;

    uint32_t task = block->blockTask();

    /// EGM -enable gate/pulse mode, DGM - disable
    /// EMOD -enable modulation control input, DMOD - disable
    /// RMEC - read error, return 0 if normal
    /// SBAUD - set baud rate 2-8 : 1200-57600
    /// SDC - set diode current 0-100 percent
    /// SPRR - set pulse freq (in gate mode) 0-50000

    /// LaserSettings:
    /// armLaser -> EMOD
    /// disarmlaser -> DMOD
    /// setIntensity -> SDC
    /// setPulseFreq -> SPRR

    /// LaserModes:
    /// LASER_PULSED ->EGM
    /// LASER_CONTINUOUS ->DGM




    if(task & PowderBlock::BlockTask::SET_LASER_ARM_STATE){
        if(block->laser_armed()){
            outputList.append("EMOD\r");
        }
        else {
            outputList.append("DMOD\r");
        }
    }
    else
        outputList.append("EMPTY");

    if(task & PowderBlock::BlockTask::SET_LASER_INTENSITY){
        const float intensity = block->laser_intensity();
        QString intenseStr = "SDC " + QString::number(static_cast<double>(intensity)) + "\r";
        outputList.append(intenseStr);
    }
    else
        outputList.append("EMPTY");

    if(task & PowderBlock::BlockTask::SET_LASER_MODE){
        if(block->laserMode() == PowderBlock::LaserMode::LASER_CONTINUOUS){
            outputList.append("DGM\r");
        }
        else if(block->laserMode() == PowderBlock::LaserMode::LASER_PULSED){
            outputList.append("EGM\r");
        }
    }
    else
        outputList.append("EMPTY");

    if(task & PowderBlock::BlockTask::SET_LASER_PULSE_FREQ){
        const int freq = block->laser_pulseFreq();
        QString freqStr = "SPRR " + QString::number(freq) + "\r";
        outputList.append(freqStr);
    }
    else
        outputList.append("EMPTY");

    return outputList;
}
