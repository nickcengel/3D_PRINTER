#include "powderapp.h"
#include "view3dapp.h"

#include <QApplication>
#include <QIcon>

#include <QGuiApplication>

#include <QObject>

#include "gcode_tools.h"
#include <QMetaType>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icons/MenuIcons/cube.png"));


    PowderApp w;

    w.setWindowTitle("PowderRoom");
    w.show();


    View3DApp v;


    QObject::connect(&w, SIGNAL(view3d_pressed()), &v, SLOT(open_3dView()));


    return a.exec();
}
