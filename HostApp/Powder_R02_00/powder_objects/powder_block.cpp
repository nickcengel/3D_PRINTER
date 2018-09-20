#include "powder_block.h"
#include "QtDebug"

PowderBlock::PowderBlock(){
    qRegisterMetaType<PowderBlock>("PowderBlock");
    m_laser_enabled = false;
}

PowderBlock::PowderBlock(const int block_number, const int layer_Number)
{
    qRegisterMetaType<PowderBlock>("PowderBlock");
   m_blockNumber = block_number;
   m_layerNumber = layer_Number;
   m_laser_enabled = false;

}

PowderBlock::PowderBlock(const PowderBlock &otherBlock){
    m_blockNumber = otherBlock.blockNumber();
    m_layerNumber = otherBlock.layerNumber();
    m_blockTask = otherBlock.blockTask();
    m_laser_enabled = otherBlock.laser_enabled();
    m_laser_armed = otherBlock.laser_armed();
    m_laser_power = otherBlock.laser_power();
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
    m_lg_string = otherBlock.lg_string();
    m_md_string = otherBlock.md_string();
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
void PowderBlock::setBlockTask(uint16_t task){
    m_blockTask |= task;
}


uint16_t PowderBlock::blockTask() const {
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

int PowderBlock::laser_power() const
{
    return m_laser_power;
}

void PowderBlock::setLaser_power(const int &l_power)
{
    m_laser_power = l_power;
    setBlockTask(BlockTask::SET_LASER_POWER);

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

QString PowderBlock::lg_string() const
{
    return m_lg_string;
}

void PowderBlock::setLg_string(const QString &lg_string)
{
    m_lg_string = lg_string;
}

QStringList PowderBlock::md_string() const
{
    return m_md_string;
}

void PowderBlock::setMd_string(const QStringList &md_string)
{
    m_md_string.append(md_string.at(0));
    m_md_string.append(md_string.at(1));
    m_md_string.append(md_string.at(2));
}





