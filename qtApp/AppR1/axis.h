#ifndef AXIS_H
#define AXIS_H

#include <QObject>

class Axis : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int portNumber READ getPortNumber WRITE setPortNumber NOTIFY portNumberChanged)
    Q_PROPERTY(int deviceNumber READ getDeviceNumber WRITE setDeviceNumber NOTIFY deviceNumberChanged)
    Q_PROPERTY(bool enabled READ getEnabled WRITE setEnabled NOTIFY enabledChanged)
    Q_PROPERTY(AxisTitle axisTitle READ getAxisTitle WRITE setAxisTitle NOTIFY axisTitleChanged)
    Q_PROPERTY(AxisStatus status READ getStatus WRITE setStatus NOTIFY statusChanged)
    Q_PROPERTY(QString error READ getError WRITE setError NOTIFY errorChanged)
    Q_PROPERTY(float positionMin READ getPositionMin WRITE setPositionMin NOTIFY positionMinChanged)
    Q_PROPERTY(float positionMax READ getPositionMax WRITE setPositionMax NOTIFY positionMaxChanged)
    Q_PROPERTY(float speedMin READ getSpeedMin WRITE setSpeedMin NOTIFY speedMinChanged)
    Q_PROPERTY(float speedMax READ getSpeedMax WRITE setSpeedMax NOTIFY speedMaxChanged)
    Q_PROPERTY(float homeOffset READ getHomeOffset WRITE setHomeOffset NOTIFY homeOffsetChanged)
    Q_PROPERTY(float currentSpeed READ getCurrentSpeed WRITE setCurrentSpeed NOTIFY currentSpeedChanged)
    Q_PROPERTY(float currentAcceleration READ getCurrentAcceleration WRITE setCurrentAcceleration NOTIFY currentAccelerationChanged)
    Q_PROPERTY(float currentPosition READ getCurrentPosition WRITE setCurrentPosition NOTIFY currentPositionChanged)
    Q_PROPERTY(bool connected READ getConnected WRITE setConnected NOTIFY connectedChanged())

public:
    explicit Axis(QObject *parent = nullptr);
    ~Axis();

    enum AxisTitle{X,Y,Z,A,B};
    Q_ENUM(AxisTitle);
    enum AxisStatus{a,b,c};
    Q_ENUM(AxisStatus);

    int getPortNumber() const;
    void setPortNumber(int portNumber);

    int getDeviceNumber() const;
    void setDeviceNumber(int deviceNumber);

    bool getEnabled() const;
    void setEnabled(bool enabled);

    bool getConnected() const;
    void setConnected(bool connected);

    AxisTitle getAxisTitle() const;
    void setAxisTitle(const AxisTitle axisTitle);

    AxisStatus getStatus() const;
    void setStatus(AxisStatus status);

    float getPositionMin() const;
    void setPositionMin(float positionMin);

    float getPositionMax() const;
    void setPositionMax(float positionMax);

    float getSpeedMin() const;
    void setSpeedMin(float speedMin);

    float getSpeedMax() const;
    void setSpeedMax(float speedMax);

    float getHomeOffset() const;
    void setHomeOffset(float homeOffset);

    float getCurrentSpeed() const;
    void setCurrentSpeed(float currentSpeed);

    float getCurrentAcceleration() const;
    void setCurrentAcceleration(float currentAcceleration);

    float getCurrentPosition() const;
    void setCurrentPosition(float currentPosition);

    QString getError() const;
    void setError(const QString &error);

signals:
    void portNumberChanged();
    void deviceNumberChanged();
    void enabledChanged();
    void connectedChanged();
    void axisTitleChanged();
    void statusChanged();
    void errorChanged();

    void positionMinChanged();
    void positionMaxChanged();
    void speedMinChanged();
    void speedMaxChanged();
    void homeOffsetChanged();

    void currentSpeedChanged();
    void currentAccelerationChanged();
    void currentPositionChanged();

public slots:

private:
    int m_portNumber;
    int m_deviceNumber;
    bool m_connected;
    bool m_enabled;
    AxisTitle m_axisTitle;
    AxisStatus m_status;
    QString m_error;

    float m_positionMin;
    float m_positionMax;
    float m_speedMin;
    float m_speedMax;
    float m_homeOffset;

    float m_currentSpeed;
    float m_currentAcceleration;
    float m_currentPosition;
};

#endif // AXIS_H
