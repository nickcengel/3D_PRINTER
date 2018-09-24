/*
 * Author: Nick Engel
 * The Colorado School of Mines
 * Department of Electrical Engineering
 * 1500 Illinois St, Golden, CO 80401
 * https://github.com/nickcengel/3D_PRINTER
 * nengel@mines.edu
 */

/*
 * VERSION: 02_00
 *
 * OVERVIEW:
 *  POWDER is a open source student software project created in order to
 *  facilitate exploration of 3D printing technology and associated toolchains
 *  at The Colorado School of Mines.
 *
 * REQUIREMENTS:
 *      # POWDER is designed for powder bed fusion 3D printing.
 *      # The current implementation is designed for serial communication
 *        with 'X'-series Zaber motion controllers and a custom embedded
 *        galvanometer controller via USB.
 *
 * FEATURES:
 *      # Translation of G-Code files into device command codes.
 *      # Generation of a 3D representation of the associated tool path.
 *      # Ability to list and connect to multiple USB<->USART (serial) devices.
 *      # Integration of the Zaber ASCII command interface to control two
 *        X series stepper motor drivers (3 Axis).
 *      # Integration of a custom command interface for the embedded
 *        galvanometer (2 Axis)
 *      # Configuration of the devies and application via a standard .ini file.
 *      # Excecution and monitoring of a G-Code based print routine.
 *      # Ability to manually control and monitor motion devices through the ui.
 *
 * DEPENDENCIES:
 *      # POWDER is developed using the Qt framework with Qt Creator and built using qMake.
 *      # No additional resources or tools should be required to build POWDER.
 *      # POWDER has been developed on Mac OS, but should be able to be built for other OS's.
 *
 * SOFTWARE ORGANIZATION:
 *      # POWDER is composed of 2 programs:
 *          - PowderApp: The main UI, configuration, and device control implementation.
 *          - PowderView3D: - The OPENGL 3D viewing window, which is launched by PowderApp.
 *
 *      # The /powder_objects directory contains the following classes used to implement PowderApp
 *          - PowderBlock: Represents a single line of G-Code.
 *          - PowderPart: Represents a G-Code part file, and contains the hardware command strings
 *                        used during executing a print.
 *          - PowderSettings: Holds the configuration parameters for the application and hardware devices.
 *
 *      # The /hardware_tools directory contains the classes required to genreate the the hardware
 *        command strings.
 *          - GalvoUtility: Generates command strings for the embedded device controlling the
 *             Galvanometer.
 *          - ZaberUtility: Generates commands strings using the Zaber Ascii protocol for the motion
 *            controllers connecting the following material delivery devices:
 *                  * Build plate
 *                  * Hopper plate
 *                  * Spreader blade
 *

 */

#include <QApplication>
#include <QGuiApplication>
#include <QObject>
#include <QIcon>
#include <QMetaType>

#include "powder_app/powder_app.h"
#include "3d_framework/powder_view3d.h"
#include "3d_framework/powder_block3d.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType<PowderSettings>("PowderSettings");
    qRegisterMetaType<PowderBlock>("PowderBlock");
    qRegisterMetaType<PowderPart>("PowderPart");
    qRegisterMetaType<PowderBlock3D>("PowderBlock3D");

    QApplication powder_coreApp(argc, argv);
    powder_coreApp.setOrganizationName("The Colorado School of Mines");
    powder_coreApp.setOrganizationDomain("mines.edu");
    powder_coreApp.setApplicationName("Powder");
    powder_coreApp.setWindowIcon(QIcon(":/icons/MenuIcons/cube.png"));

    PowderApp powder_window;
    powder_window.setWindowTitle("Powder");
    powder_window.show();

    PowderView3D powder_3dViewer;

    QObject::connect(&powder_window, SIGNAL(view3D_open(QVector<PowderBlock3D*>*)),
                     &powder_3dViewer, SLOT(on_3dView_open(QVector<PowderBlock3D*>*)));

    QObject::connect(&powder_window, SIGNAL(view3D_close()),
                     &powder_3dViewer, SLOT(on_3dView_close()));

    return powder_coreApp.exec();
}
