#include "mainwindow.h"
#include "ui_mainwindow.h"

using BlockIO::machine_settings_t;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setDirectory("Users/nickengel/Documents/github/3D_PRINTER/qtApp/AppR1/");
    if (dialog.exec())
        m_fileName = dialog.selectedFiles()[0];
        //m_layerStack = BlockIO::convertGcode(m_fileName, &m_settings);

}

