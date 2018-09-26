#ifndef POWDER_TRANSPORT_H
#define POWDER_TRANSPORT_H

#include <QObject>
#include <QtSerialPort>
#include <QTimer>
#include <QSharedPointer>

#include "powder_objects/powder_part.h"
#include "powder_objects/powder_settings.h"
#include "hardware_tools/galvo_utility.h"

Q_DECLARE_LOGGING_CATEGORY(powder_transport_log)
Q_DECLARE_LOGGING_CATEGORY(laser_port_log)
Q_DECLARE_LOGGING_CATEGORY(galvo_port_log)
Q_DECLARE_LOGGING_CATEGORY(material_delivery_port_log)

Q_DECLARE_LOGGING_CATEGORY(laser_device_log)
Q_DECLARE_LOGGING_CATEGORY(galvanometer_device_log)
Q_DECLARE_LOGGING_CATEGORY(buildPlate_device_log)
Q_DECLARE_LOGGING_CATEGORY(hopperPlate_device_log)
Q_DECLARE_LOGGING_CATEGORY(spreaderBlade_device_log)


/* The PowderTransport class provides an interface between the
 * main application functions/UI and the device serial ports.
 *
 * PowderTransport also maintains a representation of each
 * devices current state.This state is updated when the PowderTransport receives
 * a reply from a hardware device.
 *
 * PowderTransport contains powderDaemon, a statemachine that selects functionality
 * and implements transitions in response to requests from the UI and messages
 * received by the serial ports.
 *
 * PowderTransport implements both manual-jog control of the devices and the
 * execution of print routine sequences based on PowderParts.
 */

class PowderTransport : public QObject
{
    Q_OBJECT
public:
    explicit PowderTransport(QObject *parent = nullptr);

    ~PowderTransport();

    QSerialPort *m_laser_port;
    QSerialPort *m_galvo_port;
    QSerialPort *m_md_port;

    QStateMachine *powderDaemon;

    // set__ functions emit a __changed signal to UI
    float xPosition() const;
    void setXPosition(float xPosition);

    float yPosition() const;
    void setYPosition(float yPosition);

    float zPosition() const;
    void setZPosition(float zPosition);

    float sPosition() const;
    void setSPosition(float sPosition);

    float hPosition() const;
    void setHPosition(float hPosition);


    float laserIntensity() const;
    void setLaserIntensity(float laserIntensity);

    bool laserEnableState() const;
    void setLaserEnableState(bool laserEnableState);

    bool laserArmState() const;
    void setLaserArmState(bool laserArmState);

    float jogIncrement() const;
    void setJogIncrement(float jogIncrement);

    bool xHomed() const;
    void setXHomed(bool xHomed);

    bool yHomed() const;
    void setYHomed(bool yHomed);

    bool zHomed() const;
    void setZHomed(bool zHomed);

    bool hHomed() const;
    void setHHomed(bool hHomed);

    bool sHomed() const;
    void setSHomed(bool sHomed);

    void write_to_laser_port(const QString &txString);
    void write_to_galvo_port(const QString &txString);
    void write_to_md_port(const QString &txString);

    float xySpeed() const;
    void setXYSpeed(float xySpeed);




    float zSpeed() const;
    void setZSpeed(float zSpeed);

    float hSpeed() const;
    void setHSpeed(float hSpeed);

    float sSpeed() const;
    void setSSpeed(float sSpeed);

    int laserPulseFreq() const;
    void setLaserPulseFreq(int laserPulseFreq);

    PowderBlock::LaserMode laserMode() const;
    void setLaserMode(const PowderBlock::LaserMode &laserMode);

signals:
    // received by UI to update displays
    void xPosition_changed(double position);
    void yPosition_changed(double position);
    void xySpeed_changed(double speed);
    void zPosition_changed(double position);
    void zSpeed_changed(double speed);
    void hPosition_changed(double position);
    void hSpeed_changed(double speed);
    void sPosition_changed(double position);
    void sSpeed_changed(double speed);


    void laserIntensity_changed(double intensity);
    void laserEnableState_changed(const QString &laserState);
    void laserArmState_changed(bool armed);
//    void laserPulseFreq_changed(int pulseFreq);
//    void laserMode_changed(const PowderBlock::LaserMode &laserMode);

    void currentBlockNumber_changed(int blockNum);
    void currentLayerNumber_changed(int layerNumber);

    void laserBusy();
    void buildPlateBusy();
    void galvoBusy();
    void hopperBusy();
    void spreaderBusy();

    // internal control signals
    void laser_port_txFinished();
    void laser_port_rxFinished();
    void md_port_txFinished();
    void md_port_rxFinished();
    void galvo_port_txFinished();
    void galvo_port_rxFinished();

    void startPrint();
    void stopPrint();

    void printFinished();
    void tasksRemaining();
    void blocksRemaining();
    void blockComplete();
    void jogComplete();

    void laser_commandPending();
    void galvo_commandPending();
    void md_commandPending();

    void laser_port_connectionChanged(bool open);
    void galvo_port_connectionChanged(bool open);
    void md_port_connectionChanged(bool open);

    void resetDaemon();

    // messaging signals
    void laser_deviceReply(const QString &reply);
    void laser_error(const QString &error);

    void buildPlate_deviceReply(const QString &reply);
    void hopper_deviceReply(const QString &reply);
    void spreader_deviceReply(const QString &reply);

    void md_port_error(const QString &error);

    void galvo_deviceReply(const QString &reply);
    void galvo_error(const QString &error);


    void transport_error(const QString &error);


public slots:
    // receive control events from UI
    void on_printManager_enabled( bool enabled);
    void on_manualControl_enabled( bool enabled);

    void on_laserPortName_changed(const QString &name);
    void on_galvoPortName_changed(const QString &name);
    void on_mdPortName_changed(const QString &name);

    void on_laser_port_connectionRequested(bool open);
    void on_galvo_port_connectionRequested(bool open);
    void on_md_port_connectionRequested(bool open);

    void on_config_available(QSharedPointer<PowderSettings> config);
    void on_partFile_available(QSharedPointer<PowderPart> part);

    void on_startPrint_request();
    void on_stopPrint_request();
    void on_reset_request();
    void on_emergency_stop_request();

    void on_jogIncrement_changed(double jogIncrement);
    void on_homeOption_change(int homeOption);
    void on_home_request();
    void on_increment_xPosition_request();
    void on_decrement_xPosition_request();
    void on_increment_yPosition_request();
    void on_decrement_yPosition_request();
    void on_increment_zPosition_request();
    void on_decrement_zPosition_request();
    void on_increment_hPosition_request();
    void on_decrement_hPosition_request();
    void on_increment_sPosition_request();
    void on_decrement_sPosition_request();
    void on_clearError_request();

    void on_reset_galvo_request();


    // on enabled device from UI
    void ping_galvo();
    void ping_materialDelivery(int devNum, int axisNum);

private slots:
    // port event callbacks
    void on_laser_port_bytesWritten(qint64 bytes);
    void on_laser_port_bytesRead();
    void on_laser_portTimeout();
    void on_laser_port_error(QSerialPort::SerialPortError portError);

    void on_galvo_port_bytesWritten(qint64 bytes);
    void on_galvo_port_bytesRead();
    void on_galvo_portTimeout();
    void on_galvo_port_error(QSerialPort::SerialPortError portError);

    void on_md_port_bytesWritten(qint64 bytes);
    void on_md_port_bytesRead();
    void on_md_portTimeout();
    void on_md_port_error(QSerialPort::SerialPortError portError);
    void poll_mdPort();

    // daemon state processes
    void on_printRoutine_init();
    void on_generateProcessQueueFromBlock();
    void on_selectProcessFromQueue();

    void on_send_laserCommand();
    void on_receive_laserReply();
    void on_laser_transactionFinished();

    void on_send_galvoCommand();
    void on_receive_galvoReply();
    void on_galvo_transactionFinished();
    void on_send_mdCommand();
    void on_receive_mdReply();
    void on_md_transactionFinished();
    void on_selectNextBlockToProcess();
    void on_printRoutine_finished();
    void on_printRoutine_error();


private:
    QTimer *laserPort_timer;
    QTimer *galvoPort_timer;
    QTimer *materialDeliveryPort_timer;
    QTimer *materialDeliveryPoll_timer;

    QSharedPointer<PowderPart> m_part;
    QSharedPointer<PowderSettings> m_config;

    bool m_manualModeEnabled;
    bool m_printModeEnabled;

    float m_xPosition;
    float m_yPosition;
    float m_zPosition;
    float m_sPosition;
    float m_hPosition;
    float m_xySpeed;
    float m_zSpeed;
    float m_hSpeed;
    float m_sSpeed;
    float m_laserIntensity;
    int m_laserPulseFreq;
    PowderBlock::LaserMode m_laserMode;
    bool m_laserEnableState;
    bool m_laserArmState;

    float m_jogIncrement;
    float m_jogSign;
    int m_homeOption;

    bool m_xHomed;
    bool m_yHomed;
    bool m_zHomed;
    bool m_hHomed;
    bool m_sHomed;

    int m_currentBlockNumber;
    int m_currentLayerNumber;

    uint32_t m_pendingTasks;
    uint32_t m_activeTask;

    QStringList m_laser_commandStr;
    QString m_galvo_commandStr;
    QStringList m_md_commandStr;

    QByteArray laser_port_rxBytes;
    QByteArray galvo_port_rxBytes;
    QByteArray md_port_rxBytes;

    qint64 laser_port_TxBytesRemaining;
    qint64 galvo_port_TxBytesRemaining;
    qint64 md_port_TxBytesRemaining;

};

#endif // POWDER_TRANSPORT_H
