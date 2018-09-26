/****************************************************************************
** Meta object code from reading C++ file 'powder_app.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Powder_R02_00/powder_app/powder_app.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSharedPointer>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'powder_app.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PowderApp_t {
    QByteArrayData data[69];
    char stringdata0[1654];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PowderApp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PowderApp_t qt_meta_stringdata_PowderApp = {
    {
QT_MOC_LITERAL(0, 0, 9), // "PowderApp"
QT_MOC_LITERAL(1, 10, 16), // "newPartAvailable"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 26), // "QSharedPointer<PowderPart>"
QT_MOC_LITERAL(4, 55, 4), // "part"
QT_MOC_LITERAL(5, 60, 18), // "newConfigAvailable"
QT_MOC_LITERAL(6, 79, 30), // "QSharedPointer<PowderSettings>"
QT_MOC_LITERAL(7, 110, 6), // "config"
QT_MOC_LITERAL(8, 117, 22), // "laserPort_name_changed"
QT_MOC_LITERAL(9, 140, 4), // "name"
QT_MOC_LITERAL(10, 145, 22), // "galvoPort_name_changed"
QT_MOC_LITERAL(11, 168, 19), // "mdPort_name_changed"
QT_MOC_LITERAL(12, 188, 29), // "laserPort_connectionRequested"
QT_MOC_LITERAL(13, 218, 4), // "open"
QT_MOC_LITERAL(14, 223, 29), // "galvoPort_connectionRequested"
QT_MOC_LITERAL(15, 253, 26), // "mdPort_connectionRequested"
QT_MOC_LITERAL(16, 280, 17), // "reset_printManger"
QT_MOC_LITERAL(17, 298, 17), // "reset_galvoDevice"
QT_MOC_LITERAL(18, 316, 16), // "cleaDeviceErrors"
QT_MOC_LITERAL(19, 333, 11), // "view3D_open"
QT_MOC_LITERAL(20, 345, 24), // "QVector<PowderBlock3D*>*"
QT_MOC_LITERAL(21, 370, 7), // "block3d"
QT_MOC_LITERAL(22, 378, 12), // "view3D_close"
QT_MOC_LITERAL(23, 391, 41), // "on_settings_button_saveAsDefa..."
QT_MOC_LITERAL(24, 433, 41), // "on_settings_button_resetToDef..."
QT_MOC_LITERAL(25, 475, 35), // "on_settings_button_openFile_c..."
QT_MOC_LITERAL(26, 511, 36), // "on_settings_buttons_saveFile_..."
QT_MOC_LITERAL(27, 548, 39), // "on_settings_button_refreshPor..."
QT_MOC_LITERAL(28, 588, 32), // "on_settings_button_apply_clicked"
QT_MOC_LITERAL(29, 621, 19), // "on_MenuTree_clicked"
QT_MOC_LITERAL(30, 641, 11), // "QModelIndex"
QT_MOC_LITERAL(31, 653, 5), // "index"
QT_MOC_LITERAL(32, 659, 37), // "on_gcode_tool_button_openFile..."
QT_MOC_LITERAL(33, 697, 38), // "on_gcode_tool_button_clearPar..."
QT_MOC_LITERAL(34, 736, 40), // "on_Main_Button_ConfigurationP..."
QT_MOC_LITERAL(35, 777, 31), // "on_Main_Button_PortPage_clicked"
QT_MOC_LITERAL(36, 809, 32), // "on_Main_Button_GCodePage_clicked"
QT_MOC_LITERAL(37, 842, 37), // "on_Main_Button_ControllerPage..."
QT_MOC_LITERAL(38, 880, 31), // "on_Main_Button_HelpPage_clicked"
QT_MOC_LITERAL(39, 912, 36), // "on_PortManager_options_box_ac..."
QT_MOC_LITERAL(40, 949, 4), // "arg1"
QT_MOC_LITERAL(41, 954, 31), // "on_laser_port_connectionChanged"
QT_MOC_LITERAL(42, 986, 31), // "on_galvo_port_connectionChanged"
QT_MOC_LITERAL(43, 1018, 28), // "on_md_port_connectionChanged"
QT_MOC_LITERAL(44, 1047, 18), // "on_laser_portError"
QT_MOC_LITERAL(45, 1066, 5), // "Error"
QT_MOC_LITERAL(46, 1072, 18), // "on_laser_portReply"
QT_MOC_LITERAL(47, 1091, 5), // "reply"
QT_MOC_LITERAL(48, 1097, 18), // "on_galvo_portError"
QT_MOC_LITERAL(49, 1116, 18), // "on_galvo_portReply"
QT_MOC_LITERAL(50, 1135, 15), // "on_md_portError"
QT_MOC_LITERAL(51, 1151, 25), // "on_buildPlate_deviceReply"
QT_MOC_LITERAL(52, 1177, 21), // "on_hopper_deviceReply"
QT_MOC_LITERAL(53, 1199, 23), // "on_spreader_deviceReply"
QT_MOC_LITERAL(54, 1223, 17), // "on_transportError"
QT_MOC_LITERAL(55, 1241, 36), // "on_PrintManagerEnable_button_..."
QT_MOC_LITERAL(56, 1278, 7), // "checked"
QT_MOC_LITERAL(57, 1286, 36), // "on_printManager_reset_button_..."
QT_MOC_LITERAL(58, 1323, 37), // "on_ManualControlEnable_button..."
QT_MOC_LITERAL(59, 1361, 36), // "on_laserDisplayEnable_button_..."
QT_MOC_LITERAL(60, 1398, 36), // "on_galvoDisplayEnable_button_..."
QT_MOC_LITERAL(61, 1435, 34), // "on_buildPlateEnable_button_to..."
QT_MOC_LITERAL(62, 1470, 47), // "on_materialDeliveryDisplayEna..."
QT_MOC_LITERAL(63, 1518, 12), // "on_laserBusy"
QT_MOC_LITERAL(64, 1531, 17), // "on_buildPlateBusy"
QT_MOC_LITERAL(65, 1549, 12), // "on_galvoBusy"
QT_MOC_LITERAL(66, 1562, 18), // "on_hop_spread_busy"
QT_MOC_LITERAL(67, 1581, 32), // "on_emergency_stop_button_clicked"
QT_MOC_LITERAL(68, 1614, 39) // "on_galvoOptions_box_currentIn..."

    },
    "PowderApp\0newPartAvailable\0\0"
    "QSharedPointer<PowderPart>\0part\0"
    "newConfigAvailable\0QSharedPointer<PowderSettings>\0"
    "config\0laserPort_name_changed\0name\0"
    "galvoPort_name_changed\0mdPort_name_changed\0"
    "laserPort_connectionRequested\0open\0"
    "galvoPort_connectionRequested\0"
    "mdPort_connectionRequested\0reset_printManger\0"
    "reset_galvoDevice\0cleaDeviceErrors\0"
    "view3D_open\0QVector<PowderBlock3D*>*\0"
    "block3d\0view3D_close\0"
    "on_settings_button_saveAsDefault_released\0"
    "on_settings_button_resetToDefault_clicked\0"
    "on_settings_button_openFile_clicked\0"
    "on_settings_buttons_saveFile_clicked\0"
    "on_settings_button_refreshPorts_clicked\0"
    "on_settings_button_apply_clicked\0"
    "on_MenuTree_clicked\0QModelIndex\0index\0"
    "on_gcode_tool_button_openFile_clicked\0"
    "on_gcode_tool_button_clearPart_clicked\0"
    "on_Main_Button_ConfigurationPage_clicked\0"
    "on_Main_Button_PortPage_clicked\0"
    "on_Main_Button_GCodePage_clicked\0"
    "on_Main_Button_ControllerPage_clicked\0"
    "on_Main_Button_HelpPage_clicked\0"
    "on_PortManager_options_box_activated\0"
    "arg1\0on_laser_port_connectionChanged\0"
    "on_galvo_port_connectionChanged\0"
    "on_md_port_connectionChanged\0"
    "on_laser_portError\0Error\0on_laser_portReply\0"
    "reply\0on_galvo_portError\0on_galvo_portReply\0"
    "on_md_portError\0on_buildPlate_deviceReply\0"
    "on_hopper_deviceReply\0on_spreader_deviceReply\0"
    "on_transportError\0"
    "on_PrintManagerEnable_button_toggled\0"
    "checked\0on_printManager_reset_button_clicked\0"
    "on_ManualControlEnable_button_toggled\0"
    "on_laserDisplayEnable_button_toggled\0"
    "on_galvoDisplayEnable_button_toggled\0"
    "on_buildPlateEnable_button_toggled\0"
    "on_materialDeliveryDisplayEnable_button_toggled\0"
    "on_laserBusy\0on_buildPlateBusy\0"
    "on_galvoBusy\0on_hop_spread_busy\0"
    "on_emergency_stop_button_clicked\0"
    "on_galvoOptions_box_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PowderApp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      53,   14, // methods
       1,  392, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  279,    2, 0x06 /* Public */,
       5,    1,  282,    2, 0x06 /* Public */,
       8,    1,  285,    2, 0x06 /* Public */,
      10,    1,  288,    2, 0x06 /* Public */,
      11,    1,  291,    2, 0x06 /* Public */,
      12,    1,  294,    2, 0x06 /* Public */,
      14,    1,  297,    2, 0x06 /* Public */,
      15,    1,  300,    2, 0x06 /* Public */,
      16,    0,  303,    2, 0x06 /* Public */,
      17,    0,  304,    2, 0x06 /* Public */,
      18,    0,  305,    2, 0x06 /* Public */,
      19,    1,  306,    2, 0x06 /* Public */,
      22,    0,  309,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    0,  310,    2, 0x08 /* Private */,
      24,    0,  311,    2, 0x08 /* Private */,
      25,    0,  312,    2, 0x08 /* Private */,
      26,    0,  313,    2, 0x08 /* Private */,
      27,    0,  314,    2, 0x08 /* Private */,
      28,    0,  315,    2, 0x08 /* Private */,
      29,    1,  316,    2, 0x08 /* Private */,
      32,    0,  319,    2, 0x08 /* Private */,
      33,    0,  320,    2, 0x08 /* Private */,
      34,    0,  321,    2, 0x08 /* Private */,
      35,    0,  322,    2, 0x08 /* Private */,
      36,    0,  323,    2, 0x08 /* Private */,
      37,    0,  324,    2, 0x08 /* Private */,
      38,    0,  325,    2, 0x08 /* Private */,
      39,    1,  326,    2, 0x08 /* Private */,
      41,    1,  329,    2, 0x08 /* Private */,
      42,    1,  332,    2, 0x08 /* Private */,
      43,    1,  335,    2, 0x08 /* Private */,
      44,    1,  338,    2, 0x08 /* Private */,
      46,    1,  341,    2, 0x08 /* Private */,
      48,    1,  344,    2, 0x08 /* Private */,
      49,    1,  347,    2, 0x08 /* Private */,
      50,    1,  350,    2, 0x08 /* Private */,
      51,    1,  353,    2, 0x08 /* Private */,
      52,    1,  356,    2, 0x08 /* Private */,
      53,    1,  359,    2, 0x08 /* Private */,
      54,    1,  362,    2, 0x08 /* Private */,
      55,    1,  365,    2, 0x08 /* Private */,
      57,    0,  368,    2, 0x08 /* Private */,
      58,    1,  369,    2, 0x08 /* Private */,
      59,    1,  372,    2, 0x08 /* Private */,
      60,    1,  375,    2, 0x08 /* Private */,
      61,    1,  378,    2, 0x08 /* Private */,
      62,    1,  381,    2, 0x08 /* Private */,
      63,    0,  384,    2, 0x08 /* Private */,
      64,    0,  385,    2, 0x08 /* Private */,
      65,    0,  386,    2, 0x08 /* Private */,
      66,    0,  387,    2, 0x08 /* Private */,
      67,    0,  388,    2, 0x08 /* Private */,
      68,    1,  389,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   40,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::QString,   45,
    QMetaType::Void, QMetaType::QString,   47,
    QMetaType::Void, QMetaType::QString,   45,
    QMetaType::Void, QMetaType::QString,   47,
    QMetaType::Void, QMetaType::QString,   45,
    QMetaType::Void, QMetaType::QString,   47,
    QMetaType::Void, QMetaType::QString,   47,
    QMetaType::Void, QMetaType::QString,   47,
    QMetaType::Void, QMetaType::QString,   45,
    QMetaType::Void, QMetaType::Bool,   56,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   56,
    QMetaType::Void, QMetaType::Bool,   56,
    QMetaType::Void, QMetaType::Bool,   56,
    QMetaType::Void, QMetaType::Bool,   56,
    QMetaType::Void, QMetaType::Bool,   56,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   40,

 // properties: name, type, flags
      21, 0x80000000 | 20, 0x0009510b,

       0        // eod
};

void PowderApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PowderApp *_t = static_cast<PowderApp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newPartAvailable((*reinterpret_cast< QSharedPointer<PowderPart>(*)>(_a[1]))); break;
        case 1: _t->newConfigAvailable((*reinterpret_cast< QSharedPointer<PowderSettings>(*)>(_a[1]))); break;
        case 2: _t->laserPort_name_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->galvoPort_name_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->mdPort_name_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->laserPort_connectionRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->galvoPort_connectionRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->mdPort_connectionRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->reset_printManger(); break;
        case 9: _t->reset_galvoDevice(); break;
        case 10: _t->cleaDeviceErrors(); break;
        case 11: _t->view3D_open((*reinterpret_cast< QVector<PowderBlock3D*>*(*)>(_a[1]))); break;
        case 12: _t->view3D_close(); break;
        case 13: _t->on_settings_button_saveAsDefault_released(); break;
        case 14: _t->on_settings_button_resetToDefault_clicked(); break;
        case 15: _t->on_settings_button_openFile_clicked(); break;
        case 16: _t->on_settings_buttons_saveFile_clicked(); break;
        case 17: _t->on_settings_button_refreshPorts_clicked(); break;
        case 18: _t->on_settings_button_apply_clicked(); break;
        case 19: _t->on_MenuTree_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 20: _t->on_gcode_tool_button_openFile_clicked(); break;
        case 21: _t->on_gcode_tool_button_clearPart_clicked(); break;
        case 22: _t->on_Main_Button_ConfigurationPage_clicked(); break;
        case 23: _t->on_Main_Button_PortPage_clicked(); break;
        case 24: _t->on_Main_Button_GCodePage_clicked(); break;
        case 25: _t->on_Main_Button_ControllerPage_clicked(); break;
        case 26: _t->on_Main_Button_HelpPage_clicked(); break;
        case 27: _t->on_PortManager_options_box_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 28: _t->on_laser_port_connectionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->on_galvo_port_connectionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->on_md_port_connectionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->on_laser_portError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 32: _t->on_laser_portReply((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 33: _t->on_galvo_portError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 34: _t->on_galvo_portReply((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 35: _t->on_md_portError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 36: _t->on_buildPlate_deviceReply((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 37: _t->on_hopper_deviceReply((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 38: _t->on_spreader_deviceReply((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 39: _t->on_transportError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 40: _t->on_PrintManagerEnable_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 41: _t->on_printManager_reset_button_clicked(); break;
        case 42: _t->on_ManualControlEnable_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 43: _t->on_laserDisplayEnable_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 44: _t->on_galvoDisplayEnable_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 45: _t->on_buildPlateEnable_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 46: _t->on_materialDeliveryDisplayEnable_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 47: _t->on_laserBusy(); break;
        case 48: _t->on_buildPlateBusy(); break;
        case 49: _t->on_galvoBusy(); break;
        case 50: _t->on_hop_spread_busy(); break;
        case 51: _t->on_emergency_stop_button_clicked(); break;
        case 52: _t->on_galvoOptions_box_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PowderApp::*)(QSharedPointer<PowderPart> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::newPartAvailable)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(QSharedPointer<PowderSettings> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::newConfigAvailable)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::laserPort_name_changed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::galvoPort_name_changed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::mdPort_name_changed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::laserPort_connectionRequested)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::galvoPort_connectionRequested)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::mdPort_connectionRequested)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::reset_printManger)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::reset_galvoDevice)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::cleaDeviceErrors)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(QVector<PowderBlock3D*> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::view3D_open)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::view3D_close)) {
                *result = 12;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        PowderApp *_t = static_cast<PowderApp *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVector<PowderBlock3D*>**>(_v) = _t->block3d(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        PowderApp *_t = static_cast<PowderApp *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBlock3d(*reinterpret_cast< QVector<PowderBlock3D*>**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject PowderApp::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PowderApp.data,
      qt_meta_data_PowderApp,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PowderApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PowderApp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PowderApp.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PowderApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 53)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 53;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 53)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 53;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void PowderApp::newPartAvailable(QSharedPointer<PowderPart> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PowderApp::newConfigAvailable(QSharedPointer<PowderSettings> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PowderApp::laserPort_name_changed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PowderApp::galvoPort_name_changed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PowderApp::mdPort_name_changed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PowderApp::laserPort_connectionRequested(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PowderApp::galvoPort_connectionRequested(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PowderApp::mdPort_connectionRequested(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PowderApp::reset_printManger()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void PowderApp::reset_galvoDevice()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void PowderApp::cleaDeviceErrors()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void PowderApp::view3D_open(QVector<PowderBlock3D*> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void PowderApp::view3D_close()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
