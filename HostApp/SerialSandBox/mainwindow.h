#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "messagemanager.h"
#include "serialthread.h"
#include <QSerialPortInfo>
#include <QDebug>
#include <QPushButton>
#include <QLabel>
#include <QList>
#include <QComboBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
private slots:
    void handleCommand(const QString &c);
    void handleReply(const QString &r);
    void handleError(const QString &e);
    void handleTimeout(const QString &t);




    void on_RefreshPortList_Button_clicked();

    void on_PortList_ComboBox_currentIndexChanged(const QString &arg1);

    void on_SendCommand_Button_clicked();

    void on_BaudRate_ComboBox_currentIndexChanged(const QString &arg1);

    void on_TimeOut_spinBox_valueChanged(int arg1);

    void on_ClearTerminal_Button_clicked();




    void on_GalvoTask_ComboBox_currentIndexChanged(int index);

    void on_Xaxis_CheckBox_clicked(bool checked);

    void on_Xaxis_LineEdit_textEdited(const QString &arg1);


    void on_Yaxis_CheckBox_clicked(bool checked);

    void on_Yaxis_LineEdit_textEdited(const QString &arg1);

    void on_GalvoSpeed_CheckBox_clicked(bool checked);

    void on_GalvoSpeed_LineEdit_textEdited(const QString &arg1);

    void on_LaserTask_ComboBox_currentIndexChanged(int index);

    void on_LaserPower_CheckBox_clicked(bool checked);

    void on_LaserPower_LineEdit_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
    SerialThread s_thread;
    MessageManager m_manager;
    bool m_connected = false;
    QString m_selectedPortName;
    qint32 m_selectedBaudRate = 115200;
    int m_selectedTimeOut = 500;
    QStringList myMessage;

};

#endif // MAINWINDOW_H
