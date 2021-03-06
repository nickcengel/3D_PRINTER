#include "blockobject.h"

BlockObject::BlockObject(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<BlockObject>("BlockObject");
    this->setParent(parent);
}

BlockObject::BlockObject(const BlockObject &otherBlock){
    this->setParent(otherBlock.parent());
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
}

BlockObject::~BlockObject()
{

}

uint32_t BlockObject::blockNumber() const
{
    return m_blockNumber;
}

void BlockObject::setBlockNumber(const uint32_t &blockNumber)
{
    m_blockNumber = blockNumber;
}

uint32_t BlockObject::layerNumber() const
{
    return m_layerNumber;
}

void BlockObject::setLayerNumber(const uint32_t &layerNumber)
{
    m_layerNumber = layerNumber;
}


void BlockObject::setBlockTask(uint16_t blockTask){
    m_blockTask |= blockTask;
}


uint16_t BlockObject::blockTask() const {
    return m_blockTask;
}


bool BlockObject::laser_enabled() const
{
    return m_laser_enabled;
}


void BlockObject::setLaser_enabled(bool l_enabled)
{
    m_laser_enabled = l_enabled;
    setBlockTask(BlockTask::SET_LASER_ENABLE_STATE);
}


bool BlockObject::laser_armed() const
{
    return m_laser_armed;
}


void BlockObject::setLaser_armed(bool l_armed)
{
    m_laser_armed = l_armed;
    setBlockTask(BlockTask::SET_LASER_ARM_STATE);
}

uint8_t BlockObject::laser_power() const
{
    return m_laser_power;
}

void BlockObject::setLaser_power(const uint8_t &l_power)
{
    m_laser_power = l_power;
    setBlockTask(BlockTask::SET_LASER_POWER);

}

BlockObject::PositionMode BlockObject::positionMode() const
{
    return m_positionMode;
}


void BlockObject::setPositionMode(const PositionMode &positionMode)
{
    m_positionMode = positionMode;
}



float BlockObject::x_position() const
{
    return m_x_position;
}

void BlockObject::setX_position(float x_position)
{
    m_x_position = x_position;
    setBlockTask(BlockTask::SET_X_POSITION);

}

float BlockObject::y_position() const
{
    return m_y_position;
}

void BlockObject::setY_position(float y_position)
{
    m_y_position = y_position;
    setBlockTask(BlockTask::SET_Y_POSITION);

}

float BlockObject::z_position() const
{
    return m_z_position;
}

void BlockObject::setZ_position(float z_position)
{
    m_z_position = z_position;
    setBlockTask(BlockTask::SET_Z_POSITION);

}

float BlockObject::hopper_position() const
{
    return m_hopper_position;
}

void BlockObject::setHopper_position(float h_position)
{
    m_hopper_position = h_position;
    setBlockTask(BlockTask::SET_HOPPER_POSITION);

}

float BlockObject::spreader_position() const
{
    return m_spreader_position;
}

void BlockObject::setSpreader_position(float s_position)
{
    m_spreader_position = s_position;
    setBlockTask(BlockTask::SET_SPREADER_POSITION);

}

float BlockObject::xy_speed() const
{
    return m_xy_speed;
}

void BlockObject::setXY_speed(float xy_speed)
{
    m_xy_speed = xy_speed;
    setBlockTask(BlockTask::SET_XY_SPEED);

}

float BlockObject::z_speed() const
{
    return m_z_speed;
}

void BlockObject::setZ_speed(float z_speed)
{
    m_z_speed = z_speed;
    setBlockTask(BlockTask::SET_Z_SPEED);

}

float BlockObject::hopper_speed() const
{
    return m_hopper_speed;
}

void BlockObject::setHopper_speed(float hopper_speed)
{
    m_hopper_speed = hopper_speed;
    setBlockTask(BlockTask::SET_HOPPER_SPEED);

}

float BlockObject::spreader_speed() const
{
    return m_spreader_speed;
}

void BlockObject::setSpreader_speed(float spreader_speed)
{
    m_spreader_speed = spreader_speed;
    setBlockTask(BlockTask::SET_SPREADER_SPEED);

}

float BlockObject::dwellTime() const
{
    return m_dwellTime;
}

void BlockObject::setDwellTime(float dwellTime)
{
    m_dwellTime = dwellTime;
    setBlockTask(BlockTask::SET_DWELL_TIME);

}

QString BlockObject::g_code_line() const
{
    return m_g_code_line;
}

void BlockObject::setG_code_line(const QString &g_code_line)
{
    m_g_code_line = g_code_line;
}

QString BlockObject::laser_galvo_command() const
{
    return m_laser_galvo_command;
}

void BlockObject::setLaser_galvo_command(const QString &laser_galvo_command)
{
    m_laser_galvo_command = laser_galvo_command;
}

QString BlockObject::z_command() const
{
    return m_z_command;
}

void BlockObject::setZ_command(const QString &z_command)
{
    m_z_command = z_command;
}

QString BlockObject::hopper_command() const
{
    return m_hopper_command;
}

void BlockObject::setHopper_command(const QString &hopper_command)
{
    m_hopper_command = hopper_command;
}

QString BlockObject::spreader_command() const
{
    return m_spreader_command;
}

void BlockObject::setSpreader_command(const QString &spreader_command)
{
    m_spreader_command = spreader_command;
}






