#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "axis.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <qfiledialog.h>
#include <QString>
#include "blockio.h"


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QVector<BlockIO::layer_t> m_layerStack;




    //Axis myAxis;


private slots:

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString m_fileName;

};

#endif // MAINWINDOW_H
