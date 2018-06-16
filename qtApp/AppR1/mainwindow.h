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

private:
    Ui::MainWindow *ui;
    QString m_fileName;
    machine_settings_t m_settings;

    Part * myPart;

};

#endif // MAINWINDOW_H
