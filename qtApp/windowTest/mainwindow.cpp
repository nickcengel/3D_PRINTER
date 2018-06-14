#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->xDisplay->enableControls(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_testBut_clicked()
{
    QString d = "hwody";
    ui->testLabel->setText(d);
}
