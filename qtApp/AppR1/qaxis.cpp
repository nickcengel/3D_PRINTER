#include "qaxis.h"
#include "blockio.h"
using BlockIO::axis_settings_t;

QAxis::QAxis(const axis_settings_t &initialSettings, QObject *parent) : QObject(parent)
{
    m_settings = initialSettings;

}

axis_settings_t QAxis::settings() const
{
    return m_settings;
}

void QAxis::setSettings(const axis_settings_t &settings)
{
    m_settings = settings;
}

float QAxis::currentPosition() const
{
    return m_currentPosition;
}

void QAxis::setCurrentPosition(float currentPosition)
{
    m_currentPosition = currentPosition;
    emit currentPositionChanged(m_currentPosition);

}

float QAxis::currentSpeed() const
{
    return m_currentSpeed;
}

void QAxis::setCurrentSpeed(float currentSpeed)
{


    m_currentSpeed = currentSpeed;
    emit currentSpeedChanged(m_currentSpeed);

}

float QAxis::currentAcceleration() const
{
    return m_currentAcceleration;
}

void QAxis::setCurrentAcceleration(float currentAcceleration)
{
    m_currentAcceleration = currentAcceleration;
    emit currentAccelerationChanged(m_currentAcceleration);
}

