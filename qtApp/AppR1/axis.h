//#ifndef AXIS_H
//#define AXIS_H

//#include <QObject>

//class Axis : public QObject
//{
//    Q_OBJECT

//    Q_PROPERTY(int portNumber READ getPortNumber WRITE setPortNumber NOTIFY portNumberChanged)
//    Q_PROPERTY(int deviceNumber READ getDeviceNumber WRITE setDeviceNumber NOTIFY deviceNumberChanged)
//    Q_PROPERTY(bool connected READ isConnected WRITE setConnected NOTIFY connectedChanged)
//    Q_PROPERTY(bool replyPending READ isReplyPending WRITE setReplyPending NOTIFY replyPendingChanged)
//    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY enabledChanged)
//    Q_PROPERTY(AxisTitle axisTitle READ getAxisTitle WRITE setAxisTitle NOTIFY axisTitleChanged)
//    //Q_PROPERTY(AxisStatus status READ getStatus NOTIFY statusChanged)
//    Q_PROPERTY(QString error READ getError WRITE setError NOTIFY errorChanged)

//    Q_PROPERTY(float positionMin READ getPositionMin WRITE setPositionMin NOTIFY positionMinChanged)
//    Q_PROPERTY(float positionMax READ getPositionMax WRITE setPositionMax NOTIFY positionMaxChanged)
//    Q_PROPERTY(float speedMin READ getSpeedMin WRITE setSpeedMin NOTIFY speedMinChanged)
//    Q_PROPERTY(float speedMax READ getSpeedMax WRITE setSpeedMax NOTIFY speedMaxChanged)
////    Q_PROPERTY(float homeOffset READ getHomeOffset WRITE setHomeOffset NOTIFY homeOffsetChanged)
////    Q_PROPERTY(bool homed READ isHomed WRITE setHomed NOTIFY homedChanged)

//    Q_PROPERTY(float currentSpeed READ getCurrentSpeed WRITE setCurrentSpeed NOTIFY currentSpeedChanged)
//    Q_PROPERTY(float currentAcceleration READ getCurrentAcceleration WRITE setCurrentAcceleration NOTIFY currentAccelerationChanged)
//    Q_PROPERTY(float currentPosition READ getCurrentPosition WRITE setCurrentPosition NOTIFY currentPositionChanged)

////    Q_PROPERTY(bool requestedHomed  READ getRequestedHomed WRITE setRequestedHomed NOTIFY requestedHomedChanged)
//    Q_PROPERTY(bool requestedSpeed  READ getRequestedSpeed WRITE setRequestedSpeed NOTIFY requestedSpeedChanged)
//    Q_PROPERTY(bool requestedAcceleration  READ getRequestedAcceleration WRITE setRequestedAcceleration NOTIFY requestedAccelerationChanged)
//    Q_PROPERTY(float requestedPosition READ getRequestedPosition WRITE setRequestedPosition NOTIFY requestedPositionChanged)



//public:
//    explicit Axis(QObject *parent = nullptr);
//    ~Axis();

//    enum AxisTitle{X,Y,Z,A,B};
//    Q_ENUM(AxisTitle);
//    enum AxisStatus{a,b,c};
//    Q_ENUM(AxisStatus);

//    int getPortNumber() const;
//    int getDeviceNumber() const;
//    bool isEnabled() const;
//    bool isConnected() const;
//    bool isReplyPending() const;
//    AxisTitle getAxisTitle() const;
//    AxisStatus getStatus() const;
//    QString getError() const;

//    float getPositionMin() const;
//    float getPositionMax() const;
//    float getSpeedMin() const;
//    float getSpeedMax() const;
//    float getHomeOffset() const;
//    bool isHomed() const;

//    float getCurrentSpeed() const;
//    float getCurrentAcceleration() const;
//    float getCurrentPosition() const;

//    float getRequestedPosition() const;
//    float getRequestedSpeed() const;
//    float getRequestedAcceleration() const;

//signals:
//    //  unlikely to use thsese
//    void portNumberChanged(int portNumber);
//    void deviceNumberChanged(int deviceNumber);
//    void axisTitleChanged(AxisTitle axis);
//    void positionMinChanged(float positionMin);
//    void positionMaxChanged(float positionMax);
//    void speedMinChanged(float speedMin);
//    void speedMaxChanged(float speedMax);
//    void homeOffsetChanged(float homeOffset);
//    // but we'll keep them around

//    // send these to system model / UI
//    void homedChanged(bool homed);
//    void currentSpeedChanged(float currentSpeed);
//    void currentAccelerationChanged(float currentAcceleration);
//    void currentPositionChanged(float currentPosition);
//    void connectedChanged(bool connected);
//    void enabledChanged(bool enabled);
//    void statusChanged(AxisStatus status);
//    void newError(QString error);

//    // send these to the serial/motor interface
//    void enableRequest(bool enabled);
//    void statusRequest();
//    void homingRequest(bool requestedHomed);
//    void speedChangeRequest(float requestedSpeed);
//    void accelerationChangeRequest(float requestedAcceleration);
//    void positionChangeRequest(float requestedPosition);

//    // might be better as a private signal?
//    void replyPendingChanged(bool replyPending);

//public slots:
//    // used by serial/motor interface/(constructor?)
//    void setPortNumber(int portNumber);
//    void setDeviceNumber(int deviceNumber);
//    void setEnabled(bool enabled);
//    void setConnected(bool connected);
//    void setAxisTitle(const AxisTitle axisTitle);
//    void setPositionMin(float positionMin);
//    void setPositionMax(float positionMax);
//    void setSpeedMin(float speedMin);
//    void setSpeedMax(float speedMax);
//    void setHomeOffset(float homeOffset);
//    void updateAxis(int reply);//

//    // used by block handler
//    void requestStatus();
//    void setHomingRequest(bool requestHome);
//    void setRequestedSpeed(float requestedSpeed);
//    void setRequestedAcceleration(float requestedAcceleration);
//    void setRequestedPosition(float requestedPosition);

//private slots:
//    void setReplyPending(bool replyPending);
//    void setError(const QString &error);
//    void setHomed(bool homed);
//    void setCurrentSpeed(float currentSpeed);
//    void setCurrentAcceleration(float currentAcceleration);
//    void setCurrentPosition(float currentPosition);

//private:
//    int m_portNumber;
//    int m_deviceNumber;
//    bool m_connected;
//    bool m_replyPending;
//    bool m_enabled;
//    AxisTitle m_axisTitle;
//    AxisStatus m_status;
//    QString m_error;

//    float m_positionMin;
//    float m_positionMax;
//    float m_speedMin;
//    float m_speedMax;
//    float m_homeOffset;

//    bool m_homed;
//    float m_currentSpeed;
//    float m_currentAcceleration;
//    float m_currentPosition;

//    bool m_requestedHomed;
//    float m_requestedSpeed;
//    float m_requestedAcceleration;
//    float m_requestedPosition;
//};

//#endif // AXIS_H
