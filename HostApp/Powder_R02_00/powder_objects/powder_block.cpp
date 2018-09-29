#include "powder_block.h"
#include "QtDebug"

PowderBlock::PowderBlock(){
    qRegisterMetaType<PowderBlock>("PowderBlock");
    m_laser_enabled = false;
    m_commandType = NO_COMMAND_TYPE;

}

PowderBlock::PowderBlock(const int block_number, const int layer_Number)
{
    qRegisterMetaType<PowderBlock>("PowderBlock");
   m_blockNumber = block_number;
   m_layerNumber = layer_Number;
   m_laser_enabled = false;
   m_commandType = NO_COMMAND_TYPE;

}

PowderBlock::PowderBlock(const PowderBlock &otherBlock){
    m_commandType = otherBlock.commandType();
    m_laserMode = otherBlock.laserMode();
    m_laser_pulseFreq = otherBlock.laser_pulseFreq();
    m_blockNumber = otherBlock.blockNumber();
    m_layerNumber = otherBlock.layerNumber();
    m_blockTask = otherBlock.blockTask();
    m_laser_enabled = otherBlock.laser_enabled();
    m_laser_armed = otherBlock.laser_armed();
    m_laser_intensity = otherBlock.laser_intensity();
    m_positionMode = otherBlock.positionMode();
    m_x_position = otherBlock.x_position();
    m_y_position = otherBlock.y_position();
    m_xy_speed = otherBlock.xy_speed();
    m_z_position = otherBlock.z_position();
    m_z_speed = otherBlock.z_speed();
    m_hopper_position = otherBlock.hopper_position();
    m_hopper_speed = otherBlock.hopper_speed();
    m_spreader_position = otherBlock.spreader_position();
    m_spreader_speed = otherBlock.spreader_speed();
    m_laser_string = otherBlock.laser_string();
    m_galvo_string = otherBlock.galvo_string();
    m_materialDeliveryPosition_string = otherBlock.materialDeliveryPosition_string();
}

PowderBlock::~PowderBlock()
{

}

int PowderBlock::blockNumber() const
{
    return m_blockNumber;
}

void PowderBlock::setBlockNumber(const int &blockNumber)
{
    m_blockNumber = blockNumber;
}

int PowderBlock::layerNumber() const
{
    return m_layerNumber;
}

void PowderBlock::setLayerNumber(const int &layerNumber)
{
    m_layerNumber = layerNumber;
}

// modify m_blockTask by setting the blockTask bit
void PowderBlock::setBlockTask(uint32_t task){
    m_blockTask |= task;
}


uint32_t PowderBlock::blockTask() const {
    return m_blockTask;
}


bool PowderBlock::laser_enabled() const
{
    return m_laser_enabled;
}


void PowderBlock::setLaser_enabled(bool l_enabled)
{
    m_laser_enabled = l_enabled;
    setBlockTask(BlockTask::SET_LASER_ENABLE_STATE);
}


bool PowderBlock::laser_armed() const
{
    return m_laser_armed;
}


void PowderBlock::setLaser_armed(bool l_armed)
{
    m_laser_armed = l_armed;
    setBlockTask(BlockTask::SET_LASER_ARM_STATE);
}

float PowderBlock::laser_intensity() const
{
    return m_laser_intensity;
}

void PowderBlock::setLaser_intensity(const float &laser_intensity)
{
    m_laser_intensity = laser_intensity;
    setBlockTask(BlockTask::SET_LASER_INTENSITY);

}

PowderBlock::PositionMode PowderBlock::positionMode() const
{
    return m_positionMode;
}


void PowderBlock::setPositionMode(const PositionMode &positionMode)
{
    m_positionMode = positionMode;
    m_blockTask |= PowderBlock::BlockTask::SET_POSITION_MODE;
}



float PowderBlock::x_position() const
{
    return m_x_position;
}

void PowderBlock::setX_position(float x_position)
{
    m_x_position = x_position;
    setBlockTask(BlockTask::SET_X_POSITION);

}

float PowderBlock::y_position() const
{
    return m_y_position;
}

void PowderBlock::setY_position(float y_position)
{
    m_y_position = y_position;
    setBlockTask(BlockTask::SET_Y_POSITION);

}

float PowderBlock::z_position() const
{
    return m_z_position;
}

void PowderBlock::setZ_position(float z_position)
{
    m_z_position = z_position;
    setBlockTask(BlockTask::SET_Z_POSITION);

}

float PowderBlock::hopper_position() const
{
    return m_hopper_position;
}

void PowderBlock::setHopper_position(float h_position)
{
    m_hopper_position = h_position;
    setBlockTask(BlockTask::SET_HOPPER_POSITION);

}

float PowderBlock::spreader_position() const
{
    return m_spreader_position;
}

void PowderBlock::setSpreader_position(float s_position)
{
    m_spreader_position = s_position;
    setBlockTask(BlockTask::SET_SPREADER_POSITION);

}

float PowderBlock::xy_speed() const
{
    return m_xy_speed;
}

void PowderBlock::setXY_speed(float xy_speed)
{
    m_xy_speed = xy_speed;
    setBlockTask(BlockTask::SET_XY_SPEED);
}

float PowderBlock::z_speed() const
{
    return m_z_speed;
}

void PowderBlock::setZ_speed(float z_speed)
{
    m_z_speed = z_speed;
    setBlockTask(BlockTask::SET_Z_SPEED);

}

float PowderBlock::hopper_speed() const
{
    return m_hopper_speed;
}

void PowderBlock::setHopper_speed(float hopper_speed)
{
    m_hopper_speed = hopper_speed;
    setBlockTask(BlockTask::SET_HOPPER_SPEED);

}

float PowderBlock::spreader_speed() const
{
    return m_spreader_speed;
}

void PowderBlock::setSpreader_speed(float spreader_speed)
{
    m_spreader_speed = spreader_speed;
    setBlockTask(BlockTask::SET_SPREADER_SPEED);

}

float PowderBlock::dwellTime() const
{
    return m_dwellTime;
}

void PowderBlock::setDwellTime(float dwellTime)
{
    m_dwellTime = dwellTime;
    setBlockTask(BlockTask::SET_DWELL_TIME);

}


void PowderBlock::clearTask()
{
    m_blockTask = 0;
}

QString PowderBlock::galvo_string() const
{
    return m_galvo_string;
}

void PowderBlock::setGalvo_string(const QString &lg_string)
{
    m_galvo_string = lg_string;
}

QStringList PowderBlock::materialDeliveryPosition_string() const
{
    return m_materialDeliveryPosition_string;
}

void PowderBlock::setmaterialDeliveryPosition_string(const QStringList &md_string)
{
    m_materialDeliveryPosition_string.append(md_string.at(0));
    m_materialDeliveryPosition_string.append(md_string.at(1));
    m_materialDeliveryPosition_string.append(md_string.at(2));
}

PowderBlock::CommandType PowderBlock::commandType() const
{
    return m_commandType;
}

void PowderBlock::setCommandType(const CommandType &moveType)
{
    m_commandType = moveType;
}

int PowderBlock::laser_pulseFreq() const
{
    return m_laser_pulseFreq;
}

void PowderBlock::setLaser_pulseFreq(int laser_pulseFreq)
{
    m_laser_pulseFreq = laser_pulseFreq;
    setBlockTask(BlockTask::SET_LASER_PULSE_FREQ);
}

PowderBlock::LaserMode PowderBlock::laserMode() const
{
    return m_laserMode;
}

void PowderBlock::setLaserMode(const LaserMode &laserMode)
{
    m_laserMode = laserMode;
    setBlockTask(BlockTask::SET_LASER_MODE);

}

QStringList PowderBlock::laser_string() const
{
    return m_laser_string;
}

void PowderBlock::setLaser_string(const QStringList &laser_string)
{
    m_laser_string = laser_string;
}

QStringList PowderBlock::materialDeliverySpeed_string() const
{
    return m_materialDeliverySpeed_string;
}

void PowderBlock::setMaterialDeliverySpeed_string(const QStringList &materialDeliverySpeed_string)
{
    m_materialDeliverySpeed_string.append(materialDeliverySpeed_string.at(0));
    m_materialDeliverySpeed_string.append(materialDeliverySpeed_string.at(1));
    m_materialDeliverySpeed_string.append(materialDeliverySpeed_string.at(2));
}




