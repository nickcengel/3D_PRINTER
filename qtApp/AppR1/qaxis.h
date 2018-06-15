#ifndef QAXIS_H
#define QAXIS_H
#include "blockio.h"
#include <QObject>

using BlockIO::AxisTitle;
using BlockIO::axis_settings_t;
using BlockIO::axis_t;
using BlockIO::AxisStatus;
using BlockIO::move_t;





class QAxis : public QObject
{
    Q_OBJECT


public:
    explicit QAxis(const axis_settings_t &initialSettings, QObject *parent = nullptr);
    axis_settings_t settings() const;
    void setSettings(const axis_settings_t &settings);

    float currentPosition() const;
    float currentSpeed() const;
    float currentAcceleration() const;






    axis_t desiredMove() const;
    void setDesiredMove(const axis_t &desiredMove);

signals:
    void currentPositionChanged(float currentPosition);
    void currentSpeedChanged(float currentSpeed);
    void currentAccelerationChanged(float currentAcceleration);



public slots:



private slots:
    void setCurrentPosition(float currentPosition);
    void setCurrentSpeed(float currentSpeed);
    void setCurrentAcceleration(float currentAcceleration);


private:
    axis_settings_t m_settings;

    float m_currentPosition;
    float m_currentSpeed;
    float m_currentAcceleration;

    axis_t m_desiredMove;

signals:








};

#endif // QAXIS_H
