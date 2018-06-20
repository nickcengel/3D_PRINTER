#include "myclasses.h"
#include <QVector>

Message::Message()
{
}

Message::Message(DeviceNumber dn, AxisNumber an)
{
    setDeviceNumber(dn);
    setAxisNumber(an);
}

DeviceNumber Message::getDeviceNumber() const
{
    return m_deviceNumber;
}

void Message::setDeviceNumber(const DeviceNumber &deviceNumber)
{
    m_deviceNumber = deviceNumber;
}

AxisNumber Message::axisNumber() const
{
    return m_axisNumber;
}

void Message::setAxisNumber(const AxisNumber &axisNumber)
{
    m_axisNumber = axisNumber;
}

Mode Message::getMode() const
{
    return m_mode;
}

void Message::setMode(const Mode &mode)
{
    m_mode = mode;
}

Message_Task Message::getTask() const
{
    return m_task;
}

void Message::setTask(const Message_Task &task)
{
    m_task = task;
}

Status Message::getStatus() const
{
    return m_status;
}

void Message::setStatus(const Status &status)
{
    m_status = status;
}

float Message::getPosition_mm() const
{
    return m_position_mm;
}

void Message::setPosition_mm(float position_mm)
{
    m_position_mm = position_mm;
}

int Message::getPosition_ms() const
{
    return m_position_ms;
}

void Message::setPosition_ms(int position_ms)
{
    m_position_ms = position_ms;
}

int Message::getSpeed() const
{
    return m_speed;
}

void Message::setSpeed(int speed)
{
    m_speed = speed;
}

int Message::getPower() const
{
    return m_power;
}

void Message::setPower(int power)
{
    m_power = power;
}

QString Message::getMessage_string() const
{
    return m_message_string;
}

void Message::setMessage_string(const QString &message_string)
{
    m_message_string = message_string;
}

Block::Block()
{
}

Message *Block::L_Axis()
{
    return &m_L_Axis;
}

Message *Block::X_Axis()
{
    return &m_X_Axis;
}

Message *Block::Y_Axis()
{
    return &m_Y_Axis;
}

Message *Block::Z_Axis()
{
    return &m_Z_Axis;
}

Message *Block::A_Axis()
{
    return &m_A_Axis;
}

Message *Block::B_Axis()
{
    return &m_B_Axis;
}



float Block::getDwell() const
{
    return m_dwell;
}

void Block::setDwell(float dwell)
{
    m_dwell = dwell;
}

Code Block::getCode() const
{
    return m_code;
}

void Block::setCode(const Code &code)
{
    m_code = code;
}

QString Block::getComments() const
{
    return m_comments;
}

void Block::setComments(const QString &comments)
{
    m_comments = comments;
}

QString Block::getErrors() const
{
    return m_errors;
}

void Block::setErrors(const QString &errors)
{
    m_errors = errors;
}

bool Block::isNewLayer() const
{
    return m_newLayer;
}

void Block::setNewLayer(bool newLayer)
{
    m_newLayer = newLayer;
}

bool Block::isBlockValid() const
{
    return m_blockValid;
}

void Block::setBlockValid(bool blockValid)
{
    m_blockValid = blockValid;
}

Mode Block::getPreviousMode() const
{
    return m_previousMode;
}

void Block::setPreviousMode(const Mode &previousMode)
{
    m_previousMode = previousMode;
}


Layer::Layer(){
    setLayerValid(false);
}

Layer::Layer(QVector<Block> someBlocks){
    setLayerValid(true);
    m_layer = someBlocks;
}

QVector<Block> Layer::get() const
{
    return m_layer;
}

void Layer::setLayerValid(bool layerValid){
    m_layerValid = layerValid;
}

bool Layer::validateLayer()
{
    setLayerValid(true);
    for(int i = 0; i < m_layer.size(); i++)
    {
        if(m_layer[i].isBlockValid() == false)
            setLayerValid(false);
    }
    return isLayerValid();
}

void Layer::clearLayer()
{
    m_layer.clear();
}

Block Layer::getBlock(int blockNumber) const
{
    return m_layer.at(blockNumber);
}

void Layer::addBlock(Block aBlock)
{
    if(aBlock.isBlockValid() == false)
        setLayerValid(false);
    m_layer.append(aBlock);
}

bool Layer::isLayerValid() const
{
    return m_layerValid;
}













