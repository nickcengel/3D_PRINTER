#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "blockio.h"
using BlockIO::AxisTitle;

using BlockIO::axis_settings_t;
using BlockIO::machine_settings_t;
using BlockIO::Part;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete myPart;
}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setDirectory("Users/nickengel/Documents/github/3D_PRINTER/qtApp/AppR1/");
    if (dialog.exec())
        m_fileName = dialog.selectedFiles()[0];

    axis_settings_t X_Axis(1,1,AxisTitle::X,-500,500,0,500,0);
    axis_settings_t Y_Axis(1,1,AxisTitle::Y,-500,500,0,500,0);
    axis_settings_t Z_Axis(1,1,AxisTitle::Z,-500,500,0,500,0);
    axis_settings_t A_Axis(1,1,AxisTitle::A,-500,500,0,500,0);
    axis_settings_t B_Axis(1,1,AxisTitle::B,-500,500,0,500,0);

    machine_settings_t MySettings(X_Axis, Y_Axis, Z_Axis, A_Axis, B_Axis);

    myPart = new Part(m_fileName, MySettings);
    QString g = myPart->getLayer(0).getBlock(0).com_err();
    qDebug()<<g;
//    if(myPart->isPartValid())
//        qDebug()<<"myPart is valid";
//    else
//        qDebug()<<"myPart is not valid";

}

