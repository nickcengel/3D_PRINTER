#ifndef DEVICEMODELS_H
#define DEVICEMODELS_H

#include <QObject>
#include "blockio.h"

using BlockIO::AxisTitle;
using BlockIO::Tasks;
using BlockIO::message_t;
using BlockIO::lg_message;
using BlockIO::md_message;
using BlockIO::MD_Map;
using BlockIO::LG_Map;
using BlockIO::Block;
using BlockIO::Layer;
using BlockIO::Part;


class Axis
{
public:
    Axis();
    Axis(int portNumber, int deviceNumber, AxisTitle axisTitle);
    //enum Status{a,b,c};

    int portNumber() const;
    void setPortNumber(int portNumber);

    int deviceNumber() const;
    void setDeviceNumber(int deviceNumber);

    AxisTitle axisTitle() const;
    void setAxisTitle(const AxisTitle &axisTitle);

    void requestHome();
    bool isHomePending() const;
    void setHomed(bool isHomed);
    bool isHomed() const;

    //void requestStatus();
    //bool isStatusPending() const;
    //void setCurrentStatus(const Status currentStatus);
    //Status currentStatus() const;

    void setDesiredPosition(float desiredPosition);
    float desiredPosition() const;
    bool isPositionPending() const;
    void setCurrentPosition(float currentPosition);
    float currentPosition() const;

    void setDesiredSpeed(float desiredSpeed);
    float desiredSpeed() const;
    bool isSpeedPending() const;
    void setCurrentSpeed(float currentSpeed);
    float currentSpeed() const;

    void setDesiredMode(Tasks m);
    Tasks desiredMode() const;
    bool isModePending() const;
    void setCurrentMode(Tasks m);

    Tasks axisTask() const;
    void setAxisTask(const Tasks axisTask);

    void addMessage(message_t aMessage);
    void clearPending();

private:
    int m_portNumber;
    int m_deviceNumber;
    AxisTitle m_axisTitle;

    Tasks m_axisTask;

    Tasks m_currentMode;
    Tasks m_desiredMode;
    bool m_modePending;

    bool m_homed;
    bool m_homePending;

    //Status m_currentStatus;`
    //bool m_statusPending;

    float m_currentPosition;
    float m_desiredPosition;
    bool m_positionPending;

    float m_currentSpeed;
    float m_desiredSpeed;
    bool m_speedPending;
};

class Laser
{
public:
    Laser();

    void setDesiredMode(Tasks m);
    Tasks desiredMode() const;
    bool isModePending() const;
    void setCurrentMode(Tasks m);

    void setDesiredPower(const float power);
    float desiredPower() const;
    bool isPowerPending() const;
    void setCurrentPower(const float power);
    float currentPower() const;

    int getPortNumber() const;
    void setPortNumber(int value);

    int getDeviceNumber() const;
    void setDeviceNumber(int value);

    void setLaserTask(const BlockIO::Tasks laserTask);
    Tasks laserTask() const;

    void addMessage(message_t aMessage);
    void clearPending();



private:
    int portNumber;
    int deviceNumber;

    Tasks m_laserTask;

    Tasks m_currentMode;
    Tasks m_desiredMode;
    bool m_modePending;

    float m_currentPower;
    float m_desiredPower;
    bool m_powerPending;
};

class SystemController : public QObject
{
    Q_OBJECT
public:
    explicit SystemController(QObject *parent = nullptr);

    Axis x_axis_model;
    Axis y_axis_model;
    Laser laser_model;
    LG_Map laserGalvoMap;
    void updateLaserGalvo_model(lg_message laserGalvoMessage);

    Axis buildPlate_model;
    Axis hopperPlate_model;
    Axis spreadBlade_model;
    MD_Map materialDeliveryMap;
    void updateMaterialDelivery_model(md_message MaterialDeliveryMessage);

    void sendBlock(Block block);

    signals:
    void laserGalvoSignal(lg_message lgsOut);
    void MaterialDeliverySignal(md_message mdsOut);

    public slots:
    void laserGalvoReply(LG_Map reply);
    void MaterialDeliveryReply(MD_Map reply);


private:

};


#endif // DEVICEMODELS_H

