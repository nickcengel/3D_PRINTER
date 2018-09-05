#ifndef POWDERAPP_H
#define POWDERAPP_H

#include <QWidget>
#include <QMainWindow>
#include <QModelIndex>
#include <QSerialPortInfo>
#include <QStandardItemModel>
#include <QItemSelectionModel>

#include "powder_objects/partobject.h"
#include "powder_objects/settingsobject.h"

#include "model_item_frameworks/settings_model.h"
#include "model_item_frameworks/menu_model.h"

#include "3d_framework/block3d.h"

namespace Ui {
class PowderApp;
}

class PowderApp : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(PartObject *myPart READ myPart WRITE setMyPart)
    Q_PROPERTY(QVector<Block3D> *block3d READ block3d WRITE setBlock3d)


public:
    explicit PowderApp(QWidget *parent = nullptr);
    ~PowderApp();


    PartObject *myPart() const;
    void setMyPart(PartObject *myPart);

    QVector<Block3D > *block3d() const;
    void setBlock3d(QVector<Block3D > *block3d);

public slots:

private slots:

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

signals:
//    void view3d_pressed();
    void view3d_pressed(QVector<Block3D> *block3d);

    void close_view3d();

private:
    Ui::PowderApp *ui;
    Settings_Model *settingsModel;
    QString m_currentCustomSettingsFile;
    Settings_Model *portModel;
    QList<QSerialPortInfo> portList;

    QStandardItemModel *menuModel;
    QStandardItemModel *PartInfoLabelModel;
    QStandardItemModel *PartInfoDataModel;
    QItemSelectionModel menuSelectionModel;
    SettingsObject *myConfiguration;
    bool m_file_open;

    PartObject *m_myPart;
    QVector<Block3D> *m_block3d;

    void applySettings();

};

#endif // POWDERAPP_H
