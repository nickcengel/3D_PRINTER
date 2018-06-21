#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "axis.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <qfiledialog.h>
#include <QString>
#include "blockio.h"
#include "devicedrivers.h"
#include "devicemodels.h"

using BlockIO::axis_settings_t;
using BlockIO::machine_settings_t;
using BlockIO::Part;



namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
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

    SerialThread s_thread;
    //SystemController s_controller;

};

#endif // MAINWINDOW_H
