#ifndef POWDER_APP_H
#define POWDER_APP_H

#include <QWidget>
#include <QMainWindow>
#include <QModelIndex>
#include <QSerialPortInfo>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QSharedPointer>
#include <QtSerialPort>
#include <QSettings>

#include "powder_objects/powder_part.h"
#include "powder_objects/powder_settings.h"
#include "model_item_frameworks/settings_model.h"
#include "model_item_frameworks/menu_model.h"
#include "3d_framework/powder_block3d.h"
#include "powder_transport.h"

Q_DECLARE_LOGGING_CATEGORY(powder_app)


namespace Ui {
class PowderApp;
}

/* The PowderApp class implements the applications primary UI
 * PowderApp communicates with the hardware devices through
 * a single instance of PowderTransport.
 *
 * PowderApp launches PowderView3D by sending a QVector<PowderBlock3D*>
 * containing a 3D representation of the open G-Code File
 */

class PowderApp : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QVector<PowderBlock3D*> *block3d READ block3d WRITE setBlock3d)

public:
    explicit PowderApp(QWidget *parent = nullptr);
    ~PowderApp();

    // 3D representation used by viewer
    QVector<PowderBlock3D*>  *block3d() const;
    void setBlock3d(QVector<PowderBlock3D*> *block3d);

    // Shared Part object within powderApp
    QSharedPointer<PowderPart> myPart() const;
    void setMyPart(const QSharedPointer<PowderPart> &myPart);

    // Shared Settings object within powderApp
    QSharedPointer<PowderSettings> getMyConfiguration() const;
    void setMyConfiguration(const QSharedPointer<PowderSettings> &value);

    // displays the default settings file to the UI
    void viewDefaultSettings();
    // displays the imported settings file to the UI
    void viewUserSettings();

    // updates the default settings file
    void saveDefaultSettings();
    // writes to a user selected config file
    void saveUserSettings();

    // update the current settings to those set by user in UI
    void applySettings();

    // rescan computer for available ports
    void refreshSerialPorts();

private slots:
    // Respond to user actions in settings page
    void on_settings_button_saveAsDefault_released();
    void on_settings_button_resetToDefault_clicked();
    void on_settings_button_openFile_clicked();
    void on_settings_buttons_saveFile_clicked();
    void on_settings_button_refreshPorts_clicked();
    void on_settings_button_apply_clicked();

    // Change current page based on menu selection
    void on_MenuTree_clicked(const QModelIndex &index);

    // Open/Clear G-Code File -> sets part
    void on_gcode_tool_button_openFile_clicked();
    void on_gcode_tool_button_clearPart_clicked();

    // Change current page based on main page selection
    void on_Main_Button_ConfigurationPage_clicked();
    void on_Main_Button_PortPage_clicked();
    void on_Main_Button_GCodePage_clicked();
    void on_Main_Button_ControllerPage_clicked();
    void on_Main_Button_HelpPage_clicked();

    // Handle user port selections/connections
    void on_PortManager_options_box_activated(const QString &arg1);
    void on_lg_port_connectionChanged(bool open);
    void on_md_port_connectionChanged(bool open);

    // Handle device replies and port/transport errors
    void on_lg_portError(const QString &Error);
    void on_lg_portReply(const QString &reply);
    void on_md_portError(const QString &Error);
    void on_md_portReply(const QString &reply);
    void on_transportError(const QString &Error);

    // Handle print routine user actions
    void on_PrintManagerEnable_button_toggled(bool checked);
    void on_printManager_reset_button_clicked();

    // Select the manual controller
    void on_ManualControlEnable_button_toggled(bool checked);

    // Handle user enable/disable devices
    void on_galvoDisplayEnable_button_toggled(bool checked);
    void on_buildPlateEnable_button_toggled(bool checked);
    void on_materialDeliveryDisplayEnable_button_toggled(bool checked);

    // Update device display interfaces
    void on_buildPlateBusy();
    void on_galvoBusy();
    void on_hop_spread_busy();

signals:
    void newPartAvailable(QSharedPointer<PowderPart> part);

    void newConfigAvailable(QSharedPointer<PowderSettings> config);

    void lgPort_name_changed(const QString &name);
    void mdPort_name_changed(const QString &name);

    void lgPort_connectionRequested(bool open);
    void mdPort_connectionRequested(bool open);

    void reset_printManger();

    void cleaDeviceErrors();

    void view3D_open(QVector<PowderBlock3D*> *block3d);

    void view3D_close();

private:
    Ui::PowderApp *ui;

    QString m_userSettingsPath;
    QSharedPointer<PowderSettings> m_myConfiguration;
    QList<QSerialPortInfo> m_portList;
    QStringList m_serialPortNames;
    PowderTransport *deviceTransport;


    Settings_Model *portModel;
    QStandardItemModel *menuModel;
    QStandardItemModel *PartInfoLabelModel;
    QStandardItemModel *PartInfoDataModel;

    bool m_partFile_open;
    QSharedPointer<PowderPart> m_myPart;
    QVector<PowderBlock3D*> *m_block3d;
};

#endif // POWDER_APP_H
