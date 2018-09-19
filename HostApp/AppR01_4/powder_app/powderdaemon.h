#ifndef POWDERDAEMON_H
#define POWDERDAEMON_H

#include <QObject>
#include <QtSerialPort>
#include <QTimer>
#include <QSharedPointer>
#include "powder_objects/partobject.h"
#include "powder_objects/settingsobject.h"

#include "hardware_tools/lasergalvo_utility.h"


Q_DECLARE_LOGGING_CATEGORY(powder_daemon_log)
Q_DECLARE_LOGGING_CATEGORY(port_laser_galvo_log)
Q_DECLARE_LOGGING_CATEGORY(port_material_delivery_log)

Q_DECLARE_LOGGING_CATEGORY(device_laser_log)
Q_DECLARE_LOGGING_CATEGORY(device_galvanometer_log)
Q_DECLARE_LOGGING_CATEGORY(device_buildPlate_log)
Q_DECLARE_LOGGING_CATEGORY(device_hopperPlate_log)
Q_DECLARE_LOGGING_CATEGORY(device_spreaderBlade_log)


class PowderDaemon : public QObject
{
    Q_OBJECT
public:
    explicit PowderDaemon(QObject *parent = nullptr);

    ~PowderDaemon();

    QSerialPort *m_lg_port;
    QSerialPort *m_md_port;
    QStateMachine *printRoutine;


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

    int laserPower() const;
    void setLaserPower(int laserPower);

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

    void write_to_lg_port(const QString &txString);
    void write_to_md_port(const QString &txString);

    float xySpeed() const;
    void setXYSpeed(float xySpeed);

signals:
    void xPosition_changed(double position);
    void yPosition_changed(double position);
    void xySpeed_changed(double speed);

    void zPosition_changed(double position);
    void hPosition_changed(double position);
    void sPosition_changed(double position);
    void laserPower_changed(int power);

    void laserEnableState_changed(const QString &laserState);
    void laserArmState_changed(bool armed);

    void currentBlockNumber_changed(int blockNum);
    void currentLayerNumber_changed(int layerNumber);

    void md_port_txFinished();
    void md_port_rxFinished();
    void md_port_deviceReply(const QString &reply);

    void lg_port_txFinished();
    void lg_port_rxFinished();
    void lg_port_deviceReply(const QString &reply);

    void lg_port_error(const QString &error);
    void md_port_error(const QString &error);
    void printRoutine_error(const QString &error);

    void lg_port_connectionChanged(bool open);
    void md_port_connectionChanged(bool open);


    void startPrint();
    void stopPrint();

    void printFinished();
    void tasksRemaining();
    void blocksRemaining();
    void blockComplete();

    void jogComplete();

    void lg_commandPending();
    void md_commandPending();

    void buildPlateBusy();
    void galvoBusy();
    void hopperBusy();
    void spreaderBusy();

    void resetDaemon();

public slots:

    void on_printManager_enabled( bool enabled);
    void on_manualControl_enabled( bool enabled);

    void on_lgPortName_changed(const QString &name);
    void on_mdPortName_changed(const QString &name);

    void on_lg_port_connectionRequested(bool open);
    void on_md_port_connectionRequested(bool open);

    void on_config_available(QSharedPointer<SettingsObject> config);
    void on_partFile_available(QSharedPointer<PartObject> part);

    void on_startPrint_request();
    void on_stopPrint_request();

    void on_reset_request();

    void on_lg_port_bytesWritten(qint64 bytes);
    void on_lg_port_bytesRead();

    void on_md_port_bytesWritten(qint64 bytes);
    void on_md_port_bytesRead();


    void on_lg_portTimeout();
    void on_md_portTimeout();

    void on_lg_port_error(QSerialPort::SerialPortError portError);
    void on_md_port_error(QSerialPort::SerialPortError portError);

    void on_printRoutine_init();
    void on_generateProcessQueueFromBlock();
    void on_selectProcessFromQueue();
    void on_send_lgCommand();
    void on_receive_lgReply();
    void on_lg_transactionFinished();
    void on_send_mdCommand();
    void on_receive_mdReply();
    void on_md_transactionFinished();
    void on_selectNextBlockToProcess();
    void on_printRoutine_finished();
    void on_printRoutine_error();



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

//    void on_zPosition_request();

    void ping_laserGalvo();

    void ping_materialDelivery(int devNum, int axisNum);

    void on_clearError_request();

    void poll_mdPort();

private:
    QTimer *lg_port_timer;
    QTimer *md_port_timer;
    QTimer *md_transaction_timer;

    QSharedPointer<PartObject> m_part;
    QSharedPointer<SettingsObject> m_config;

    bool m_manualModeEnabled;
    bool m_printModeEnabled;

    float m_xPosition;
    float m_yPosition;
    float m_zPosition;
    float m_sPosition;
    float m_hPosition;
    float m_xySpeed;
    int m_laserPower;
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

    uint16_t m_pendingTasks;
    uint16_t m_activeTask;

    QString m_lg_commandStr;
    QStringList m_md_commandStr;


    QByteArray lg_port_rxBytes;
    QByteArray md_port_rxBytes;

    qint64 lg_port_TxBytesRemaining;
    qint64 md_port_TxBytesRemaining;

};

#endif // POWDERDAEMON_H
