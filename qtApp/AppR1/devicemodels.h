#ifndef DEVICEMODELS_H
#define DEVICEMODELS_H

#include <QObject>
#include "blockio.h"

using BlockIO::AxisTitle;
using BlockIO::Tasks;
using BlockIO::MD_Map;
using BlockIO::LG_Map;
using BlockIO::Message;
using BlockIO::LG_Package;
using BlockIO::MD_Package;

using BlockIO::Block;

//////////////////////////////////// *Device Models* ////////////////////////////////////
/// The Axis class and Laser class provide a means to represent the dynamic state of the
/// components of our machine.
///
/// When a new block is processed, these objects are updated by passing them a message
/// using the addMessage() method. The object then sets the relevant desired parameters,
/// and sets a related pending flag high to signal it is waiting for confirmation
/// that the most recent message has been handled by the hardware.
///
/// When a response from the hardware is processed, the clearPending() method should be called.
/// If the response indicates the transaction was sucesful, the objects current parameters
/// are updated to their desired values.

////////////////////////////////////////// BEGIN Axis CLASS //////////////////////////////////////////
/// The Axis class represents the current and desired state of each of the five axis of the system.
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

    void addMessage(Message aMessage);
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

    float m_currentPosition;
    float m_desiredPosition;
    bool m_positionPending;

    float m_currentSpeed;
    float m_desiredSpeed;
    bool m_speedPending;
};
////////////////////////////////////////// END Axis CLASS //////////////////////////////////////////

////////////////////////////////////////// BEGIN Laser CLASS //////////////////////////////////////////
/// The Laser class represents the current and desired state of each of the laser system.
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

    void addMessage(Message aMessage);
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
////////////////////////////////////////// END Laser CLASS //////////////////////////////////////////


////    Q_PROPERTY([type] -name- READ -funct- WRITE -funct- NOTIFY -funct-)

//////////////////////////////////// BEGIN SystemController CLASS ////////////////////////////////////
/// The SystemController class uses five Axis objects and a Laser object to represent the current
/// state of the machine. SystemController is a "QOBject," and inherits the signal/slot paradigm from Qt.
///
///  Methods:
///     void sendBlock(Block block) -
///         Updates current models by calling updateLaserGalvo_model()/updateMaterialDeliver_model.
///         Emits an unaltered copy of the incoming messages in block to the hardware level drivers.
///
///  Signals: (outgoing)
///     void laserGalvoSignal(LG_Package lgsOut) - to hardware drivers
///     void MaterialDeliverySignal(MD_Package mdsOut) - to hardware drivers
///
///  Slots: (incoming)
///         void laserGalvoReply(LG_Map reply) - deal with reply and clear pending parameters if succesful
///         void MaterialDeliveryReply(MD_Map reply)  - deal with reply and clear pending parameters if succesful
///
class SystemController : public QObject
{
    Q_OBJECT
public:
    explicit SystemController(QObject *parent = nullptr);

    Axis x_axis_model;
    Axis y_axis_model;
    Laser laser_model;
    LG_Map laserGalvoMap;
    void updateLaserGalvo_model(LG_Package laserGalvoMessage);

    Axis buildPlate_model;
    Axis hopperPlate_model;
    Axis spreadBlade_model;
    MD_Map materialDeliveryMap;
    void updateMaterialDelivery_model(MD_Package MaterialDeliveryMessage);

    void sendBlock(Block block);

    signals:
    void laserGalvoSignal(LG_Package lgsOut);
    void MaterialDeliverySignal(MD_Package mdsOut);

    public slots:
    void laserGalvoReply(LG_Map reply);
    void MaterialDeliveryReply(MD_Map reply);


private:

};
//////////////////////////////////// END SystemController CLASS ////////////////////////////////////


#endif // DEVICEMODELS_H

