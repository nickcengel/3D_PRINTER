
/* POWDER is a student open source software project created in order to
 * facilitate exploration of 3D printing technology and associated toolchains.
 *
 * The initial release is intended for use with the 2018 3D printer Team's
 * Powder Bed Fusion 3D printer.
 *
 * POWDER currently provides the following functionality:
 *      * Translation of G-Code files into device command codes.
 *      * Generation of a 3D representation of the associated tool path.
 *      * Ability to list and connect to multiple USB<->USART (serial) devices.
 *      * Integration of the Zaber ASCII command interface to control to
 *        X series stepper motor drivers.
 *      * Integration of a custom command interface for the embedded
 *        galvanometer/laser controller.
 *      * Configuration of the devies and application via a standard .ini file.
 *      * Excecution and monitoring of a G-Code based print routine.
 *      * Ability to manually control and monitor motion devices through the ui.
 *
 */

#include "powder_app/powderapp.h"
#include "3d_framework/view3dapp.h"

#include <QApplication>
#include <QIcon>

#include <QGuiApplication>

#include <QObject>

#include <QMetaType>
#include "3d_framework/block3d.h"

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{


    qRegisterMetaType<SettingsObject>("SettingsObject");
    qRegisterMetaType<BlockObject>("BlockObject");
    qRegisterMetaType<PartObject>("PartObject");
    qRegisterMetaType<Block3D>("Block3D");

    QApplication powder(argc, argv);
    powder.setOrganizationName("The Colorado School of Mines");
    powder.setOrganizationDomain("mines.edu");
    powder.setApplicationName("Powder");
    powder.setWindowIcon(QIcon(":/icons/MenuIcons/cube.png"));
    PowderApp powder_window;
    powder_window.setWindowTitle("Powder");
    powder_window.show();

    View3DApp view3d_app;


    QObject::connect(&powder_window, SIGNAL(view3d_pressed(QVector<Block3D*>*)), &view3d_app, SLOT(open_3dView(QVector<Block3D*>*)));

    QObject::connect(&powder_window, SIGNAL(close_view3d()), &view3d_app, SLOT(close_3dView()));


    return powder.exec();
}

