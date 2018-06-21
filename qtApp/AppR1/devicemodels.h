#ifndef DEVICEMODELS_H
#define DEVICEMODELS_H

#include <QObject>
#include "blockio.h"

using BlockIO::Axis_Number;
using BlockIO::Device_Number;

using BlockIO::Message_Task;
using BlockIO::Message_Mode;
using BlockIO::Message_Status;
using BlockIO::machine_settings_t;


using BlockIO::Message;


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
    Axis(int portNumber, Device_Number deviceNumber, Axis_Number axisNumber);

    int getPortNumber() const;
    void setPortNumber(const int portNumber);

    int getDeviceNumber() const;
    void setDeviceNumber(const Device_Number deviceNumber);

    Axis_Number getAxisNumber() const;
    void setAxisNumber(const Axis_Number axisNumber);

    void setHomed(const bool isHomed);
    bool isHomed() const;

    void setDesiredPosition(const float position);
    float getDesiredPosition() const;
    bool isPositionPending() const;
    void setCurrentPosition(const float position);
    float getCurrentPosition() const;

    void setDesiredSpeed(const float speed);
    float getDesiredSpeed() const;
    bool isSpeedPending() const;
    void setCurrentSpeed(const float speed);
    float getCurrentSpeed() const;

    void setDesiredMode(const Message_Mode m);
    Message_Mode getDesiredMode() const;
    bool isModePending() const;
    void setCurrentMode(const Message_Mode m);
    Message_Mode getCurrentMode() const;

    Message_Task getCurrentTask() const;
    void setCurrentTask(const Message_Task task);
    Message_Task getDesiredTask() const;
    void setDesiredTask(const Message_Task task);
    bool isTaskPending() const;

    Message_Status getCurrentStatus() const;
    void setCurrentStatus(const Message_Status &currentStatus);



private:
    int m_portNumber;
    int m_deviceNumber;
    Axis_Number m_axisNumber;

    Message_Task m_currentTask;
    Message_Task m_desiredTask;
    bool m_taskPending;

    Message_Mode m_currentMode;
    Message_Mode m_desiredMode;
    bool m_modePending;

    Message_Status m_currentStatus;


    bool m_homed;

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
    Laser(int portNumber, Device_Number deviceNumber, Axis_Number axisNumber);

    int getPortNumber() const;
    void setPortNumber(const int portNumber);

    int getDeviceNumber() const;
    void setDeviceNumber(const Device_Number deviceNumber);

    Axis_Number getAxisNumber() const;
    void setAxisNumber(const Axis_Number axisNumber);


    void setDesiredPower(const float power);
    float getDesiredPower() const;
    bool isPowerPending() const;
    void setCurrentPower(const float power);
    float getCurrentPower() const;

    void setDesiredMode(const Message_Mode m);
    Message_Mode getDesiredMode() const;
    bool isModePending() const;
    void setCurrentMode(const Message_Mode m);
    Message_Mode getCurrentMode() const;
    void setModePending(const bool pending);

    Message_Task getCurrentTask() const;
    void setCurrentTask(const Message_Task task);
    Message_Task getDesiredTask() const;
    void setDesiredTask(const Message_Task task);
    bool isTaskPending() const;
    void setTaskPending(bool pending);

    Message_Status getCurrentStatus() const;
    void setCurrentStatus(const Message_Status &currentStatus);

private:
    int m_portNumber;
    int m_deviceNumber;
    Axis_Number m_axisNumber;

    Message_Task m_currentTask;
    Message_Task m_desiredTask;
    bool m_taskPending;

    Message_Status m_currentStatus;
    Message_Mode m_currentMode;
    Message_Mode m_desiredMode;
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
    explicit SystemController(machine_settings_t *settings, QObject *parent = nullptr);

    Laser laser_model;
    Axis x_axis_model;
    Axis y_axis_model;


    Axis buildPlate_model;
    Axis hopperPlate_model;
    Axis spreadBlade_model;

    void sendMessage(Message aMessage);
    BlockIO::Message_Status setModelToDesired(BlockIO::Message aMessage) ;
    BlockIO::Message_Status updateModelWithReply(BlockIO::Message aMessage);
signals:
    void LaserGalvoCommand_sig(QString current_lg_command_str);
    void MaterialDeliveryCommand_sig(QString current_md_command_str);

    public slots:
    void LaserGalvoReply_slot(Message lg_reply);
    void MaterialDeliveryReply_slot(Message md_reply);


private:
    QString m_current_lg_command_str;
    QString m_current_md_command_str;

    Message m_current_lg_reply;
    Message m_current_md_reply;

};
//////////////////////////////////// END SystemController CLASS ////////////////////////////////////


#endif // DEVICEMODELS_H

