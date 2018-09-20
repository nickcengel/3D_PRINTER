#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QModelIndex>
#include <QSerialPortInfo>

#include "settings_model.h"
#include "hardware_drivers.h"

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
    void on_menu_button_settings_clicked();


    void on_menu_button_about_clicked();

    void on_menu_button_help_clicked();

    void on_menu_button_printTools_clicked();

    void on_menu_button_dashboard_clicked();



    void on_settings_button_resetToDefault_clicked();

    void on_settings_button_openFile_clicked();

    void on_settings_buttons_saveFile_clicked();

    void on_settings_button_refreshPorts_clicked();

    void on_settings_button_apply_clicked();

private:
    Ui::Widget *ui;
    Settings_Model *settingsModel;
    QString m_currentCustomSettingsFile;
    Settings_Model *portModel;
    QList<QSerialPortInfo> portList;
    machine_settings_t machineSettings;


};

#endif // WIDGET_H
