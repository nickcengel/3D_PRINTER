#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QModelIndex>
#include <QSerialPortInfo>
#include <QStandardItemModel>

#include "gcode_tools.h"
#include "settings_model.h"
#include "hardware_drivers.h"
#include "menu_model.h"

using namespace HARDWARE_NS;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:




    void on_settings_button_resetToDefault_clicked();

    void on_settings_button_openFile_clicked();

    void on_settings_buttons_saveFile_clicked();

    void on_settings_button_refreshPorts_clicked();

    void on_settings_button_apply_clicked();


    void on_MenuTree_clicked(const QModelIndex &index);

    void on_settings_button_openFile_2_clicked();

private:
    Ui::Widget *ui;
    Settings_Model *settingsModel;
    QString m_currentCustomSettingsFile;
    Settings_Model *portModel;
    QList<QSerialPortInfo> portList;
    machine_settings_t machineSettings;
    QStandardItemModel *menuModel;
    QStandardItemModel *PartInfoLabelModel;
    QStandardItemModel *PartInfoDataModel;
    GCODE_BLOCK_NS::Part *myPart;

};

#endif // WIDGET_H
