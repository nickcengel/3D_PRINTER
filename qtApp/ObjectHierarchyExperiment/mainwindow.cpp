#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "organizer.h"
#include <QDebug>
using machineSpace::message;
using machineSpace::TaskMap;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    message * m = new message(TaskMap::a,1.1);

    float g = *m->task();
    qDebug()<<g;
    delete m;
}

MainWindow::~MainWindow()
{
    delete ui;
}
