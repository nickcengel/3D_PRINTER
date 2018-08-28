#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <qfiledialog.h>
#include <QString>
#include "gcode_tools.h"
#include "serial_port_drivers.h"
#include "hardware_drivers.h"

using namespace GCODE_BLOCK_NS;

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




    //Axis myAxis;


private slots:

    void on_pushButton_clicked();

    void transaction(const QString &s);
    void showResponse(const QString &s);

private:
    Ui::MainWindow *ui;
    QString m_fileName;
    machine_settings_t m_settings;

    Part * myPart;

  //  SerialThread s_thread;
    //SystemController s_controller;

};

#endif // MAINWINDOW_H
