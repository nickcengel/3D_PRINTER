#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "blockio.h"
using BlockIO::AxisNumber;

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
    \
    axis_settings_t L_Axis(1,1,AxisNumber::L,-500,500,0,5000,0,0);
    axis_settings_t X_Axis(1,1,AxisNumber::X,-500,500,0,5000,0,1000);
    axis_settings_t Y_Axis(1,1,AxisNumber::Y,-500,500,0,5000,0,1000);
    axis_settings_t Z_Axis(1,1,AxisNumber::Z,-500,500,0,5000,0,1000);
    axis_settings_t A_Axis(1,1,AxisNumber::A,-500,500,0,5000,0,1000);
    axis_settings_t B_Axis(1,1,AxisNumber::B,-500,500,0,5000,0,1000);

    machine_settings_t MySettings(L_Axis, X_Axis, Y_Axis, Z_Axis, A_Axis, B_Axis);

    myPart = new Part(m_fileName, &MySettings);
    qDebug().noquote()<<myPart->debugPart(0);
}

