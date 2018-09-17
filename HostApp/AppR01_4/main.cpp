#include "powder_app/powderapp.h"
#include "3d_framework/view3dapp.h"

#include <QApplication>
#include <QIcon>

#include <QGuiApplication>

#include <QObject>

#include <QMetaType>
#include "3d_framework/block3d.h"


int main(int argc, char *argv[])
{


    qRegisterMetaType<SettingsObject>("SettingsObject");
    qRegisterMetaType<BlockObject>("BlockObject");
    qRegisterMetaType<PartObject>("PartObject");
    qRegisterMetaType<Block3D>("Block3D");




    QApplication powder(argc, argv);
    powder.setOrganizationName("The Colorado School of Mines");
    powder.setOrganizationDomain("mines");
    powder.setApplicationName("Powder");



    powder.setWindowIcon(QIcon(":/icons/MenuIcons/cube.png"));
    PowderApp w;



    w.setWindowTitle("Powder");
    w.show();


    View3DApp v;


    QObject::connect(&w, SIGNAL(view3d_pressed(QVector<Block3D*>*)), &v, SLOT(open_3dView(QVector<Block3D*>*)));

    QObject::connect(&w, SIGNAL(close_view3d()),
                     &v, SLOT(close_3dView()));





    return powder.exec();
}

