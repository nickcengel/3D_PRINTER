#ifndef POWDERAPP_H
#define POWDERAPP_H

#include <QWidget>
#include <QMainWindow>
#include <QModelIndex>
#include <QSerialPortInfo>
#include <QStandardItemModel>
#include <QItemSelectionModel>

#include "system_objects/partobject.h"
#include "system_objects/settingsobject.h"
#include "system_objects/partannex.h"

//#include "gcode_tools.h"
#include "settings_model.h"
//#include "hardware_drivers.h"
#include "menu_model.h"


namespace Ui {
class PowderApp;
}

class PowderApp : public QWidget
{
    Q_OBJECT
public:
    explicit PowderApp(QWidget *parent = nullptr);
    ~PowderApp();

public slots:


private slots:

    void on_settings_button_resetToDefault_clicked();
    void on_settings_button_openFile_clicked();
    void on_settings_buttons_saveFile_clicked();
    void on_settings_button_refreshPorts_clicked();
    void on_settings_button_apply_clicked();
    void on_MenuTree_clicked(const QModelIndex &index);
    void on_gcode_tool_button_openFile_clicked();
    void on_Main_Button_ConfigurationPage_clicked();
    void on_Main_Button_PortPage_clicked();
    void on_Main_Button_GCodePage_clicked();
    void on_Main_Button_ControllerPage_clicked();
    void on_Main_Button_HelpPage_clicked();



signals:
    void view3d_pressed();
    void NewPartFilePath(const QString &filePath);

private:
    Ui::PowderApp *ui;
    Settings_Model *settingsModel;
    QString m_currentCustomSettingsFile;
    Settings_Model *portModel;
    QList<QSerialPortInfo> portList;

//    machine_settings_t machineSettings;
    QStandardItemModel *menuModel;
    QStandardItemModel *PartInfoLabelModel;
    QStandardItemModel *PartInfoDataModel;
//    GCODE_BLOCK_NS::Part *myPart;
    QItemSelectionModel menuSelectionModel;

     SettingsObject *myConfiguration;
     PartAnnex *partAnnex;

};

#endif // POWDERAPP_H
