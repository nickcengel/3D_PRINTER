#include "axis.h"

Axis::Axis(QObject *parent) : QObject(parent)
{

}

Axis::~Axis(){

}

int Axis::getPortNumber() const
{
    return m_portNumber;
}

void Axis::setPortNumber(int portNumber)
{
    if(m_portNumber != portNumber)
    {
        m_portNumber = portNumber;
        emit portNumberChanged();
    }
}

int Axis::getDeviceNumber() const
{
    return m_deviceNumber;
}

void Axis::setDeviceNumber(int deviceNumber)
{
    if(m_deviceNumber!= deviceNumber)
    {
        m_deviceNumber = deviceNumber;
        emit deviceNumberChanged();
    }

}

bool Axis::getEnabled() const
{
    return m_enabled;
}

void Axis::setEnabled(bool enabled)
{
    if(m_enabled != enabled)
    {
        m_enabled = enabled;
        emit enabledChanged();
    }
}

Axis::AxisTitle Axis::getAxisTitle() const
{
    return m_axisTitle;
}

void Axis::setAxisTitle(const AxisTitle axisTitle)
{
    if(m_axisTitle != axisTitle)
    {
        m_axisTitle = axisTitle;
        emit axisTitleChanged();
    }
}

Axis::AxisStatus Axis::getStatus() const
{
    return m_status;
}

void Axis::setStatus(AxisStatus status)
{
    if(m_status != status)
    {
        m_status = status;
        emit statusChanged();
    }

}

float Axis::getPositionMin() const
{
    return m_positionMin;
}

void Axis::setPositionMin(float positionMin)
{
    if( m_positionMin != positionMin)
    {
        m_positionMin = positionMin;
        emit positionMinChanged();
    }
}

float Axis::getPositionMax() const
{
    return m_positionMax;
}

void Axis::setPositionMax(float positionMax)
{
    if( m_positionMax != positionMax)
    {
        m_positionMax = positionMax;
        emit positionMaxChanged();
    }
}

float Axis::getSpeedMin() const
{
    return m_speedMin;
}

void Axis::setSpeedMin(float speedMin)
{
    if( m_speedMin != speedMin)
    {
        m_speedMin = speedMin;
        emit speedMinChanged();
    }
}

float Axis::getSpeedMax() const
{
    return m_speedMax;
}

void Axis::setSpeedMax(float speedMax)
{
    if( m_speedMax != speedMax)
    {
        m_speedMax =speedMax;
        emit speedMaxChanged();
    }
}

float Axis::getHomeOffset() const
{
    return m_homeOffset;
}

void Axis::setHomeOffset(float homeOffset)
{
    if( m_homeOffset != homeOffset)
    {
        m_homeOffset = homeOffset;
        emit homeOffsetChanged();
    }
}

float Axis::getCurrentSpeed() const
{
    return m_currentSpeed;
}

void Axis::setCurrentSpeed(float currentSpeed)
{
    if( (m_currentSpeed != currentSpeed))
    {
        if(currentSpeed < m_speedMax){
            m_currentSpeed = currentSpeed;
            emit currentSpeedChanged();
        }
        else{
            setError("Requested speed is out of range\n");
        }
    }
}

float Axis::getCurrentAcceleration() const
{
    return m_currentAcceleration;
}

void Axis::setCurrentAcceleration(float currentAcceleration)
{
    if( m_currentAcceleration != currentAcceleration)
    {
        m_currentAcceleration = currentAcceleration;
        emit currentAccelerationChanged();
    }
}

float Axis::getCurrentPosition() const
{
    return m_currentPosition;
}

void Axis::setCurrentPosition(float currentPosition)
{
    if((m_currentPosition != currentPosition))
    {
        if( (currentPosition < m_positionMax) && (currentPosition > m_positionMin))
        {
            m_currentPosition = currentPosition;
            emit currentPositionChanged();
        }
        else{
            setError("Requested position is out of range.\n");
        }

    }
}

QString Axis::getError() const
{
    return m_error;
}

void Axis::setError(const QString &error)
{
    if( m_error != error)
    {
        m_error += error;
        emit errorChanged();
    }
}

bool Axis::getConnected() const
{
    return m_connected;
}

void Axis::setConnected(bool connected)
{
    if(m_connected != connected){
        m_connected = connected;
        emit connectedChanged();
    }
}





