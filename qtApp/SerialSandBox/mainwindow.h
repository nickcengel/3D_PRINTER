#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "messagemanager.h"
#include "serialthread.h"
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void handleCommand(const QString &c);
    void handleReply(const QString &r);
    void handleError(const QString &e);
    void handleTimeout(const QString &t);

private:
    Ui::MainWindow *ui;
    SerialThread s_thread;
    MessageManager m_manager;
};

#endif // MAINWINDOW_H
