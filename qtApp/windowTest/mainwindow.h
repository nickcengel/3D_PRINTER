#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "axisdisplay.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    public
        slots:


        signals:




private slots:


    void on_testBut_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
