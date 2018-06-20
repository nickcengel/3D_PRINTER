#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myclasses.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    Block b;
//    float f = b.A_Axis()->getPosition_mm();
//    b.A_Axis()->setPosition_mm(44);
}

MainWindow::~MainWindow()
{
    delete ui;
}
