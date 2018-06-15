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
        emit portNumberChanged(m_portNumber);
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
        emit deviceNumberChanged(m_deviceNumber);
    }

}

bool Axis::isEnabled() const
{
    return m_enabled;
}

void Axis::setEnabled(bool enabled)
{
    if(m_enabled != enabled)
    {
        m_enabled = enabled;
        emit enabledChanged(m_enabled);
    }
}

bool Axis::isConnected() const
{
    return m_connected;
}

void Axis::setConnected(bool connected)
{
    if(m_connected != connected){
        m_connected = connected;
        emit connectedChanged(m_connected);
    }
}

bool Axis::isReplyPending() const
{
    return m_replyPending;
}

void Axis::setReplyPending(bool replyPending)
{
    if(replyPending != m_replyPending){
        m_replyPending = replyPending;
        emit replyPendingChanged(m_replyPending);
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
        emit axisTitleChanged(m_axisTitle);
    }
}

Axis::AxisStatus Axis::getStatus() const
{
    return m_status;
}

void Axis::requestStatus()
{
    setReplyPending(true);
    emit statusRequest();
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
        emit positionMinChanged(m_positionMin);
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
        emit positionMaxChanged(m_positionMax);
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
        emit speedMinChanged(m_speedMin);
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
        emit speedMaxChanged(m_speedMax);
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
        emit homeOffsetChanged(m_homeOffset);
    }
}

bool Axis::isHomed() const
{
    return m_homed;
}

void Axis::setHomed(bool homed)
{
    if(m_homed != homed)
    {
        m_homed = homed;
        emit homedChanged(m_homed);
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
            emit currentSpeedChanged(m_currentSpeed);
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
    if(!m_replyPending && m_currentAcceleration != currentAcceleration && m_requestedAcceleration == currentAcceleration)
    {
        m_currentAcceleration = currentAcceleration;
        emit currentAccelerationChanged(m_currentAcceleration);
    }
}

float Axis::getCurrentPosition() const
{
    return m_currentPosition;
}

void Axis::setCurrentPosition(float currentPosition)
{
    if(!m_replyPending && m_currentPosition != currentPosition && m_requestedPosition == currentPosition)
    {
        m_currentPosition = currentPosition;
        emit currentPositionChanged(m_currentPosition);
    }
}

float Axis::getRequestedAcceleration() const
{
    return m_requestedAcceleration;
}

void Axis::setRequestedAcceleration(float requestedAcceleration)
{
    if(requestedAcceleration != m_requestedAcceleration)
    {
        m_requestedAcceleration = requestedAcceleration;
        setReplyPending(true);
        emit requestedAccelerationChanged(m_requestedAcceleration);
    }
}

float Axis::getRequestedSpeed() const
{
    return m_requestedSpeed;
}

void Axis::setRequestedSpeed(float requestedSpeed)
{
    if(requestedSpeed != m_currentSpeed)
    {
        if(requestedSpeed<m_speedMax && requestedSpeed>m_speedMin)
        {
            m_requestedSpeed = requestedSpeed;
            setReplyPending(true);
            emit requestedSpeedChanged(m_requestedSpeed);
        }
        else
            m_error += " Requested speed out of range";
    }
}

bool Axis::getRequestedHomed() const
{
    return m_requestedHomed;
}

void Axis::setHomingRequest(bool requestHome)
{
    if(!m_homed && requestHome){
        m_requestedHomed = requestHome;
        setReplyPending(true);
        emit homingRequest(m_requestedHomed);
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
        m_error = error;
        emit errorChanged(m_error);
    }
}

void Axis::updateAxis(int reply)
{
    if(reply == 1 && m_replyPending == true){
        m_homed = m_requestedHomed;
        m_currentAcceleration = m_requestedAcceleration;
        m_currentSpeed = m_requestedSpeed;
        m_currentPosition = m_requestedPosition;
    }
        setReplyPending(false);
}

float Axis::getRequestedPosition() const
{
    return m_requestedPosition;
}

void Axis::setRequestedPosition(float requestedPosition)
{
        if( (requestedPosition < m_positionMax) && (requestedPosition > m_positionMin))
        {
            m_requestedPosition = requestedPosition;
            setReplyPending(true);
            emit requestedPositionChanged(m_requestedPosition);
        }
        else{
            setError("Requested position is out of range.\n");
        }
}

