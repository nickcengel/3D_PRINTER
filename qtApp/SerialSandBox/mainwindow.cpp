#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "messagemanager.h"
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


//    m_manager.sendCommand("Repeat after me if this works:"); // it worked
}

MainWindow::~MainWindow()
{
    delete ui;
}

/// slot connecting manager's command to the thread
void MainWindow::handleCommand(const QString &c)
{
    s_thread.transaction("portName", 1000, c);
}

/// slot connecting the thread's reply to the manager (and user)
void MainWindow::handleReply(const QString &r)
{
    m_manager.receiveReply(r); // store a copy of the reply
    qDebug()<<("Reply: " + r);    // show it to user
}

void MainWindow::handleError(const QString &e)
{
    qDebug()<<("Error: " + e);
}

void MainWindow::handleTimeout(const QString &t)
{
    qDebug()<<("Timeout: " + t);
}
