#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "messagemanager.h"
#include <QSerialPort>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /// manager sends newMessage to mainWindow::handleCommand
    /// ex m_manager.sendCommand("myCommandData");
    /// handleCommand begins serial communication by calling s_thread::transaction(...)
    connect(&m_manager, &MessageManager::newMessage, this, &MainWindow::handleCommand);

    /// when the thread has finished collecting serial data, it emits the data as a string.
    /// The data string is sent to MainWindow::handleReply which stores it in the manager
    /// using manager::receiveReply()
    connect(&s_thread, &SerialThread::response, this, &MainWindow::handleReply);

    /// pipe diagnostic info/errors from thread to mainWindow
    connect(&s_thread, &SerialThread::error, this, &MainWindow::handleError);
    connect(&s_thread, &SerialThread::timeout, this, &MainWindow::handleTimeout);
    ui->PortList_ComboBox->setEnabled(false);
    QList<qint32> bauds = QSerialPortInfo::standardBaudRates();
    for (int i = 0; i < bauds.size(); i++)
        ui->BaudRate_ComboBox->addItem(QString::number((qint32)bauds[i]));
    myMessage<<"/"<<"~ "<<"~ "<<"~ "<<"~ "<<"~ "<<"~"<<";";
    QString myString;
    for(int i = 0; i < myMessage.length(); i++)
        myString += myMessage[i];
    ui->CommandInput_LineEdit->setText(myString);
    ui->Xaxis_CheckBox->setEnabled(false);
    ui->Xaxis_LineEdit->setEnabled(false);
    ui->Yaxis_CheckBox->setEnabled(false);
    ui->Yaxis_LineEdit->setEnabled(false);
    ui->GalvoSpeed_CheckBox->setEnabled(false);
    ui->GalvoSpeed_LineEdit->setEnabled(false);
    ui->LaserPower_CheckBox->setEnabled(false);
    ui->LaserPower_LineEdit->setEnabled(false);


    /// gtask // xpos // ypos // speed// ltask // laser power
}

MainWindow::~MainWindow()
{
    delete ui;
}

/// slot connecting manager's command to the thread
void MainWindow::handleCommand(const QString &c)
{
    s_thread.transaction(m_selectedPortName, m_selectedBaudRate, m_selectedTimeOut, c);
}

/// slot connecting the thread's reply to the manager (and user)
void MainWindow::handleReply(const QString &r)
{
    ui->Reply_textBrowser->append(r);
    m_manager.receiveReply(r); // store a copy of the reply with the manager
    //    qDebug()<<("Reply: " + r);    // show it to user
}

void MainWindow::handleError(const QString &e)
{
    ui->Error_textBrowser->setTextColor(Qt::red);
    ui->Error_textBrowser->append(e);
}

void MainWindow::handleTimeout(const QString &t)
{
    ui->Error_textBrowser->setTextColor(Qt::red);
    ui->Error_textBrowser->append(t);
}



void MainWindow::on_RefreshPortList_Button_clicked()
{   ui->PortList_ComboBox->clear();
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        ui->PortList_ComboBox->addItem(info.portName());
    ui->PortList_ComboBox->setEnabled(true);
    ui->PortList_ComboBox->repaint();
}



void MainWindow::on_PortList_ComboBox_currentIndexChanged(const QString &arg1)
{
    m_selectedPortName = arg1;
}

void MainWindow::on_SendCommand_Button_clicked()
{
    const QString newCommand = ui->CommandInput_LineEdit->text();
    m_manager.sendCommand(newCommand);
}

void MainWindow::on_BaudRate_ComboBox_currentIndexChanged(const QString &arg1)
{
    bool ok;
    m_selectedBaudRate = arg1.toInt(&ok,10);

}

void MainWindow::on_TimeOut_spinBox_valueChanged(int arg1)
{
    m_selectedTimeOut = arg1;
}

void MainWindow::on_ClearTerminal_Button_clicked()
{
    ui->Reply_textBrowser->clear();
    ui->Reply_textBrowser->repaint();
    ui->Error_textBrowser->clear();
    ui->Error_textBrowser->repaint();

}



void MainWindow::on_GalvoTask_ComboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        myMessage[1] = "0 ";
        ui->Xaxis_CheckBox->setEnabled(false);
        ui->Xaxis_LineEdit->setEnabled(false);
        ui->Yaxis_CheckBox->setEnabled(false);
        ui->Yaxis_LineEdit->setEnabled(false);
        ui->GalvoSpeed_CheckBox->setEnabled(false);
        ui->GalvoSpeed_LineEdit->setEnabled(false);
        break;
    case 1:
        myMessage[1] = "1 ";
        ui->Xaxis_CheckBox->setEnabled(true);
        ui->Yaxis_CheckBox->setEnabled(true);
        ui->GalvoSpeed_CheckBox->setEnabled(true);
        break;
    case 2:
        myMessage[1] = "A ";
        ui->Xaxis_CheckBox->setEnabled(true);
        ui->Yaxis_CheckBox->setEnabled(true);
        ui->GalvoSpeed_CheckBox->setEnabled(true);
        break;
    case 3:
        myMessage[1] = "R ";
        ui->Xaxis_CheckBox->setEnabled(true);
        ui->Yaxis_CheckBox->setEnabled(true);
        ui->GalvoSpeed_CheckBox->setEnabled(true);

        break;
    default:
        myMessage[1] = "~ ";

        break;
    }
    QString myString;
    for(int i = 0; i < myMessage.length(); i++)
        myString += myMessage[i];
    ui->CommandInput_LineEdit->setText(myString);
    ui->CommandInput_LineEdit->repaint();
}

void MainWindow::on_Xaxis_CheckBox_clicked(bool checked)
{

    if(checked)
    {
        ui->Xaxis_LineEdit->setEnabled(true);
        myMessage[2] = ui->Xaxis_LineEdit->text() +" ";
    }
    else
        myMessage[2] = "~ ";

    QString myString;
    for(int i = 0; i < myMessage.length(); i++)
        myString += myMessage[i];
    ui->CommandInput_LineEdit->setText(myString);
    ui->CommandInput_LineEdit->repaint();
}

void MainWindow::on_Xaxis_LineEdit_textEdited(const QString &arg1)
{
    if(ui->Xaxis_CheckBox->isChecked())
    {
        myMessage[2] = arg1 + " ";
        QString myString;
        for(int i = 0; i < myMessage.length(); i++)
            myString += myMessage[i];
        ui->CommandInput_LineEdit->setText(myString);
        ui->CommandInput_LineEdit->repaint();

    }
}

void MainWindow::on_Yaxis_CheckBox_clicked(bool checked)
{
    if(checked)
    {
        ui->Yaxis_LineEdit->setEnabled(true);
        myMessage[3] = ui->Yaxis_LineEdit->text() +" ";
    }
    else
        myMessage[3] = "~ ";

    QString myString;
    for(int i = 0; i < myMessage.length(); i++)
        myString += myMessage[i];
    ui->CommandInput_LineEdit->setText(myString);
    ui->CommandInput_LineEdit->repaint();
}

void MainWindow::on_Yaxis_LineEdit_textEdited(const QString &arg1)
{
    if(ui->Yaxis_CheckBox->isChecked())
    {
        myMessage[3] = arg1 + " ";
        QString myString;
        for(int i = 0; i < myMessage.length(); i++)
            myString += myMessage[i];
        ui->CommandInput_LineEdit->setText(myString);
        ui->CommandInput_LineEdit->repaint();

    }
}

void MainWindow::on_GalvoSpeed_CheckBox_clicked(bool checked)
{
    if(checked)
    {
        ui->GalvoSpeed_LineEdit->setEnabled(true);
        myMessage[4] = ui->GalvoSpeed_LineEdit->text() +" ";
    }
    else
        myMessage[4] = "~ ";

    QString myString;
    for(int i = 0; i < myMessage.length(); i++)
        myString += myMessage[i];
    ui->CommandInput_LineEdit->setText(myString);
    ui->CommandInput_LineEdit->repaint();
}

void MainWindow::on_GalvoSpeed_LineEdit_textEdited(const QString &arg1)
{
    if(ui->GalvoSpeed_CheckBox->isChecked())
    {
        myMessage[4] = arg1 + " ";
        QString myString;
        for(int i = 0; i < myMessage.length(); i++)
            myString += myMessage[i];
        ui->CommandInput_LineEdit->setText(myString);
        ui->CommandInput_LineEdit->repaint();

    }
}
`

void MainWindow::on_LaserTask_ComboBox_currentIndexChanged(int index)
{
    if(index == 0)
    {
        ui->LaserPower_CheckBox->setEnabled(false);
        ui->LaserPower_LineEdit->setEnabled(false);
        myMessage[5] = "0 ";
    }
    else
    {
        myMessage[5] = "1 ";

        ui->LaserPower_CheckBox->setEnabled(true);
    }
    QString myString;
    for(int i = 0; i < myMessage.length(); i++)
        myString += myMessage[i];
    ui->CommandInput_LineEdit->setText(myString);
    ui->CommandInput_LineEdit->repaint();
}



void MainWindow::on_LaserPower_CheckBox_clicked(bool checked)
{
    if(checked)
    {
        ui->LaserPower_LineEdit->setEnabled(true);
        myMessage[6] = ui->GalvoSpeed_LineEdit->text() +" ";
    }
    else
        myMessage[6] = "~ ";


    QString myString;
    for(int i = 0; i < myMessage.length(); i++)
        myString += myMessage[i];
    ui->CommandInput_LineEdit->setText(myString);
    ui->CommandInput_LineEdit->repaint();
}

void MainWindow::on_LaserPower_LineEdit_textEdited(const QString &arg1)
{
    if(ui->LaserPower_CheckBox->isChecked())
    {
        myMessage[6] = arg1 + " ";
        QString myString;
        for(int i = 0; i < myMessage.length(); i++)
            myString += myMessage[i];
        ui->CommandInput_LineEdit->setText(myString);
        ui->CommandInput_LineEdit->repaint();

    }
}
