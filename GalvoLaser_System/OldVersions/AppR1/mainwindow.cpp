#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hardware_drivers.h"
#include "gcode_tools.h"
#include "serial_port_drivers.h"


//using namespace HARDWARE_NS;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



//    connect(&s_controller, &s_controller::simpleSend, this, &MainWindow::transaction);
//    ///  Use mainWindow:: transaction method to direct Bob's command to s_thread
//    ///  SENDER  : BOB,             SIGNAL: (str) command
//    ///  RECEIVER: this mainWindow, SLOT  : (void) transaction
//    //connect( &BOB , &BOB::command, this, &MainWindow::transaction);

//    ///  SENDER  : s_thread,        SIGNAL: (str) response
//    ///  RECEIVER: this mainWindow, SLOT  : (void) showResponse
//    connect(&s_thread, &SerialThread::response, this, &MainWindow::showResponse);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog dialog(this);
    //dialog.setDirectory("Users/nickengel/Documents/github/3D_PRINTER/qtApp/AppR1/");
    if (dialog.exec())
        m_fileName = dialog.selectedFiles()[0];



    axis_settings_t L_Axis(1,LASER_GALVO,L,-500,500,0,50000,0,0);
    axis_settings_t X_Axis(1,LASER_GALVO,X,-500,500,0,50000,0,1000);
    axis_settings_t Y_Axis(1,LASER_GALVO,Y,-500,500,0,50000,0,1000);
    axis_settings_t Z_Axis(2,BUILD_PLATE,Z,-500,500,0,50000,0,1000);
    axis_settings_t A_Axis(2,HOP_SPRD,A,-500,500,0,50000,0,1000);
    axis_settings_t B_Axis(2,HOP_SPRD,B,-500,500,0,50000,0,1000);

    machine_settings_t MySettings(L_Axis, X_Axis, Y_Axis, Z_Axis, A_Axis, B_Axis);

    myPart = new Part(m_fileName, &MySettings);
    qDebug().noquote()<<myPart->debugPart(0);
    delete myPart;

}


void MainWindow::transaction(const QString &s)
{
/// use our thread's transaction method to send it a stringcommand...
//    s_thread.transaction(portName,
//                         timeout,
//                         stringcommand)
}

void MainWindow::showResponse(const QString &s)
{
 /// when the thread emits a string its captured and decoded from the serial port...

}
