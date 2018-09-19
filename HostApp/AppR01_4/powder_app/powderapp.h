


#ifndef POWDERAPP_H
#define POWDERAPP_H

#include <QWidget>
#include <QMainWindow>
#include <QModelIndex>
#include <QSerialPortInfo>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QSharedPointer>
#include <QtSerialPort>
#include <QSettings>

#include "powder_objects/partobject.h"
#include "powder_objects/settingsobject.h"
#include "model_item_frameworks/settings_model.h"
#include "model_item_frameworks/menu_model.h"
#include "3d_framework/block3d.h"
#include "powderdaemon.h"

Q_DECLARE_LOGGING_CATEGORY(powder_app)


namespace Ui {
class PowderApp;
}

class PowderApp : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QVector<Block3D*> *block3d READ block3d WRITE setBlock3d)

public:
    explicit PowderApp(QWidget *parent = nullptr);
    ~PowderApp();

    QVector<Block3D*>  *block3d() const;
    void setBlock3d(QVector<Block3D*> *block3d);

    QSharedPointer<PartObject> myPart() const;
    void setMyPart(const QSharedPointer<PartObject> &myPart);

    QSharedPointer<SettingsObject> getMyConfiguration() const;
    void setMyConfiguration(const QSharedPointer<SettingsObject> &value);

    void viewDefaultSettings();
    void viewUserSettings();

    void saveDefaultSettings();
    void saveUserSettings();

    void applySettings();

    void refreshSerialPorts();

private slots:
    void on_settings_button_saveAsDefault_released();
    void on_settings_button_resetToDefault_clicked();
    void on_settings_button_openFile_clicked();
    void on_settings_buttons_saveFile_clicked();
    void on_settings_button_refreshPorts_clicked();
    void on_settings_button_apply_clicked();
    void on_MenuTree_clicked(const QModelIndex &index);

    void on_gcode_tool_button_openFile_clicked();
    void on_gcode_tool_button_clearPart_clicked();

    void on_Main_Button_ConfigurationPage_clicked();
    void on_Main_Button_PortPage_clicked();
    void on_Main_Button_GCodePage_clicked();
    void on_Main_Button_ControllerPage_clicked();
    void on_Main_Button_HelpPage_clicked();


    void on_PortManager_options_box_activated(const QString &arg1);
    void on_lg_port_connectionChanged(bool open);
    void on_md_port_connectionChanged(bool open);
    void on_lg_portError(const QString &Error);
    void on_lg_portReply(const QString &reply);
    void on_md_portError(const QString &Error);
    void on_md_portReply(const QString &reply);
    void on_transportError(const QString &Error);

    void on_PrintManagerEnable_button_toggled(bool checked);
    void on_printManager_start_button_pressed();
    void on_printManager_reset_button_clicked();

    void on_ManualControlEnable_button_toggled(bool checked);

    void on_galvoDisplayEnable_button_toggled(bool checked);

    void on_buildPlateEnable_button_toggled(bool checked);

    void on_materialDeliveryDisplayEnable_button_toggled(bool checked);

    void on_buildPlateBusy();

    void on_galvoBusy();

    void on_hop_spread_busy();

signals:
    void newPartAvailable(QSharedPointer<PartObject> part);

    void newConfigAvailable(QSharedPointer<SettingsObject> config);

    void lgPort_name_changed(const QString &name);

    void mdPort_name_changed(const QString &name);

    void lgPort_connectionRequested(bool open);

    void mdPort_connectionRequested(bool open);

    void reset_printManger();

    void cleaDeviceErrors();


    void view3d_pressed(QVector<Block3D*> *block3d);

    void close_view3d();

private:
    Ui::PowderApp *ui;

    QString m_userSettingsPath;
    QSharedPointer<SettingsObject> myConfiguration;
    QList<QSerialPortInfo> portList;
    QStringList serialPortNames;
    PowderDaemon *deviceTransport;


    Settings_Model *portModel;
    QStandardItemModel *menuModel;
    QStandardItemModel *PartInfoLabelModel;
    QStandardItemModel *PartInfoDataModel;

    bool m_partFile_open;
    QSharedPointer<PartObject> m_myPart;
    QVector<Block3D*> *m_block3d;
};

#endif // POWDERAPP_H
