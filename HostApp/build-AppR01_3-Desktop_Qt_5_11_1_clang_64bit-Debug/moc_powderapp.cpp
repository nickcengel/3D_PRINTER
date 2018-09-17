/****************************************************************************
** Meta object code from reading C++ file 'powderapp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AppR01_4/powder_app/powderapp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSharedPointer>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'powderapp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PowderApp_t {
    QByteArrayData data[58];
    char stringdata0[1353];
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
QT_MOC_LITERAL(3, 28, 26), // "QSharedPointer<PartObject>"
QT_MOC_LITERAL(4, 55, 4), // "part"
QT_MOC_LITERAL(5, 60, 18), // "newConfigAvailable"
QT_MOC_LITERAL(6, 79, 30), // "QSharedPointer<SettingsObject>"
QT_MOC_LITERAL(7, 110, 6), // "config"
QT_MOC_LITERAL(8, 117, 19), // "lgPort_name_changed"
QT_MOC_LITERAL(9, 137, 4), // "name"
QT_MOC_LITERAL(10, 142, 19), // "mdPort_name_changed"
QT_MOC_LITERAL(11, 162, 26), // "lgPort_connectionRequested"
QT_MOC_LITERAL(12, 189, 4), // "open"
QT_MOC_LITERAL(13, 194, 26), // "mdPort_connectionRequested"
QT_MOC_LITERAL(14, 221, 17), // "reset_printManger"
QT_MOC_LITERAL(15, 239, 16), // "cleaDeviceErrors"
QT_MOC_LITERAL(16, 256, 14), // "view3d_pressed"
QT_MOC_LITERAL(17, 271, 18), // "QVector<Block3D*>*"
QT_MOC_LITERAL(18, 290, 7), // "block3d"
QT_MOC_LITERAL(19, 298, 12), // "close_view3d"
QT_MOC_LITERAL(20, 311, 41), // "on_settings_button_saveAsDefa..."
QT_MOC_LITERAL(21, 353, 41), // "on_settings_button_resetToDef..."
QT_MOC_LITERAL(22, 395, 35), // "on_settings_button_openFile_c..."
QT_MOC_LITERAL(23, 431, 36), // "on_settings_buttons_saveFile_..."
QT_MOC_LITERAL(24, 468, 39), // "on_settings_button_refreshPor..."
QT_MOC_LITERAL(25, 508, 32), // "on_settings_button_apply_clicked"
QT_MOC_LITERAL(26, 541, 19), // "on_MenuTree_clicked"
QT_MOC_LITERAL(27, 561, 11), // "QModelIndex"
QT_MOC_LITERAL(28, 573, 5), // "index"
QT_MOC_LITERAL(29, 579, 37), // "on_gcode_tool_button_openFile..."
QT_MOC_LITERAL(30, 617, 38), // "on_gcode_tool_button_clearPar..."
QT_MOC_LITERAL(31, 656, 40), // "on_Main_Button_ConfigurationP..."
QT_MOC_LITERAL(32, 697, 31), // "on_Main_Button_PortPage_clicked"
QT_MOC_LITERAL(33, 729, 32), // "on_Main_Button_GCodePage_clicked"
QT_MOC_LITERAL(34, 762, 37), // "on_Main_Button_ControllerPage..."
QT_MOC_LITERAL(35, 800, 31), // "on_Main_Button_HelpPage_clicked"
QT_MOC_LITERAL(36, 832, 36), // "on_PortManager_options_box_ac..."
QT_MOC_LITERAL(37, 869, 4), // "arg1"
QT_MOC_LITERAL(38, 874, 28), // "on_lg_port_connectionChanged"
QT_MOC_LITERAL(39, 903, 28), // "on_md_port_connectionChanged"
QT_MOC_LITERAL(40, 932, 15), // "on_lg_portError"
QT_MOC_LITERAL(41, 948, 5), // "Error"
QT_MOC_LITERAL(42, 954, 15), // "on_lg_portReply"
QT_MOC_LITERAL(43, 970, 5), // "reply"
QT_MOC_LITERAL(44, 976, 15), // "on_md_portError"
QT_MOC_LITERAL(45, 992, 15), // "on_md_portReply"
QT_MOC_LITERAL(46, 1008, 17), // "on_transportError"
QT_MOC_LITERAL(47, 1026, 36), // "on_PrintManagerEnable_button_..."
QT_MOC_LITERAL(48, 1063, 7), // "checked"
QT_MOC_LITERAL(49, 1071, 36), // "on_printManager_start_button_..."
QT_MOC_LITERAL(50, 1108, 36), // "on_printManager_reset_button_..."
QT_MOC_LITERAL(51, 1145, 37), // "on_ManualControlEnable_button..."
QT_MOC_LITERAL(52, 1183, 36), // "on_galvoDisplayEnable_button_..."
QT_MOC_LITERAL(53, 1220, 34), // "on_buildPlateEnable_button_to..."
QT_MOC_LITERAL(54, 1255, 47), // "on_materialDeliveryDisplayEna..."
QT_MOC_LITERAL(55, 1303, 17), // "on_buildPlateBusy"
QT_MOC_LITERAL(56, 1321, 12), // "on_galvoBusy"
QT_MOC_LITERAL(57, 1334, 18) // "on_hop_spread_busy"

    },
    "PowderApp\0newPartAvailable\0\0"
    "QSharedPointer<PartObject>\0part\0"
    "newConfigAvailable\0QSharedPointer<SettingsObject>\0"
    "config\0lgPort_name_changed\0name\0"
    "mdPort_name_changed\0lgPort_connectionRequested\0"
    "open\0mdPort_connectionRequested\0"
    "reset_printManger\0cleaDeviceErrors\0"
    "view3d_pressed\0QVector<Block3D*>*\0"
    "block3d\0close_view3d\0"
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
    "arg1\0on_lg_port_connectionChanged\0"
    "on_md_port_connectionChanged\0"
    "on_lg_portError\0Error\0on_lg_portReply\0"
    "reply\0on_md_portError\0on_md_portReply\0"
    "on_transportError\0"
    "on_PrintManagerEnable_button_toggled\0"
    "checked\0on_printManager_start_button_pressed\0"
    "on_printManager_reset_button_clicked\0"
    "on_ManualControlEnable_button_toggled\0"
    "on_galvoDisplayEnable_button_toggled\0"
    "on_buildPlateEnable_button_toggled\0"
    "on_materialDeliveryDisplayEnable_button_toggled\0"
    "on_buildPlateBusy\0on_galvoBusy\0"
    "on_hop_spread_busy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PowderApp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
       1,  308, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  224,    2, 0x06 /* Public */,
       5,    1,  227,    2, 0x06 /* Public */,
       8,    1,  230,    2, 0x06 /* Public */,
      10,    1,  233,    2, 0x06 /* Public */,
      11,    1,  236,    2, 0x06 /* Public */,
      13,    1,  239,    2, 0x06 /* Public */,
      14,    0,  242,    2, 0x06 /* Public */,
      15,    0,  243,    2, 0x06 /* Public */,
      16,    1,  244,    2, 0x06 /* Public */,
      19,    0,  247,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    0,  248,    2, 0x08 /* Private */,
      21,    0,  249,    2, 0x08 /* Private */,
      22,    0,  250,    2, 0x08 /* Private */,
      23,    0,  251,    2, 0x08 /* Private */,
      24,    0,  252,    2, 0x08 /* Private */,
      25,    0,  253,    2, 0x08 /* Private */,
      26,    1,  254,    2, 0x08 /* Private */,
      29,    0,  257,    2, 0x08 /* Private */,
      30,    0,  258,    2, 0x08 /* Private */,
      31,    0,  259,    2, 0x08 /* Private */,
      32,    0,  260,    2, 0x08 /* Private */,
      33,    0,  261,    2, 0x08 /* Private */,
      34,    0,  262,    2, 0x08 /* Private */,
      35,    0,  263,    2, 0x08 /* Private */,
      36,    1,  264,    2, 0x08 /* Private */,
      38,    1,  267,    2, 0x08 /* Private */,
      39,    1,  270,    2, 0x08 /* Private */,
      40,    1,  273,    2, 0x08 /* Private */,
      42,    1,  276,    2, 0x08 /* Private */,
      44,    1,  279,    2, 0x08 /* Private */,
      45,    1,  282,    2, 0x08 /* Private */,
      46,    1,  285,    2, 0x08 /* Private */,
      47,    1,  288,    2, 0x08 /* Private */,
      49,    0,  291,    2, 0x08 /* Private */,
      50,    0,  292,    2, 0x08 /* Private */,
      51,    1,  293,    2, 0x08 /* Private */,
      52,    1,  296,    2, 0x08 /* Private */,
      53,    1,  299,    2, 0x08 /* Private */,
      54,    1,  302,    2, 0x08 /* Private */,
      55,    0,  305,    2, 0x08 /* Private */,
      56,    0,  306,    2, 0x08 /* Private */,
      57,    0,  307,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 27,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   43,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   43,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::Bool,   48,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   48,
    QMetaType::Void, QMetaType::Bool,   48,
    QMetaType::Void, QMetaType::Bool,   48,
    QMetaType::Void, QMetaType::Bool,   48,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      18, 0x80000000 | 17, 0x0009510b,

       0        // eod
};

void PowderApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PowderApp *_t = static_cast<PowderApp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newPartAvailable((*reinterpret_cast< QSharedPointer<PartObject>(*)>(_a[1]))); break;
        case 1: _t->newConfigAvailable((*reinterpret_cast< QSharedPointer<SettingsObject>(*)>(_a[1]))); break;
        case 2: _t->lgPort_name_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->mdPort_name_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->lgPort_connectionRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->mdPort_connectionRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->reset_printManger(); break;
        case 7: _t->cleaDeviceErrors(); break;
        case 8: _t->view3d_pressed((*reinterpret_cast< QVector<Block3D*>*(*)>(_a[1]))); break;
        case 9: _t->close_view3d(); break;
        case 10: _t->on_settings_button_saveAsDefault_released(); break;
        case 11: _t->on_settings_button_resetToDefault_clicked(); break;
        case 12: _t->on_settings_button_openFile_clicked(); break;
        case 13: _t->on_settings_buttons_saveFile_clicked(); break;
        case 14: _t->on_settings_button_refreshPorts_clicked(); break;
        case 15: _t->on_settings_button_apply_clicked(); break;
        case 16: _t->on_MenuTree_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 17: _t->on_gcode_tool_button_openFile_clicked(); break;
        case 18: _t->on_gcode_tool_button_clearPart_clicked(); break;
        case 19: _t->on_Main_Button_ConfigurationPage_clicked(); break;
        case 20: _t->on_Main_Button_PortPage_clicked(); break;
        case 21: _t->on_Main_Button_GCodePage_clicked(); break;
        case 22: _t->on_Main_Button_ControllerPage_clicked(); break;
        case 23: _t->on_Main_Button_HelpPage_clicked(); break;
        case 24: _t->on_PortManager_options_box_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 25: _t->on_lg_port_connectionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->on_md_port_connectionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->on_lg_portError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 28: _t->on_lg_portReply((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 29: _t->on_md_portError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 30: _t->on_md_portReply((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: _t->on_transportError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 32: _t->on_PrintManagerEnable_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->on_printManager_start_button_pressed(); break;
        case 34: _t->on_printManager_reset_button_clicked(); break;
        case 35: _t->on_ManualControlEnable_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->on_galvoDisplayEnable_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 37: _t->on_buildPlateEnable_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->on_materialDeliveryDisplayEnable_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: _t->on_buildPlateBusy(); break;
        case 40: _t->on_galvoBusy(); break;
        case 41: _t->on_hop_spread_busy(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PowderApp::*)(QSharedPointer<PartObject> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::newPartAvailable)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(QSharedPointer<SettingsObject> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::newConfigAvailable)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::lgPort_name_changed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::mdPort_name_changed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::lgPort_connectionRequested)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::mdPort_connectionRequested)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::reset_printManger)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::cleaDeviceErrors)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(QVector<Block3D*> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::view3d_pressed)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::close_view3d)) {
                *result = 9;
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
        case 0: *reinterpret_cast< QVector<Block3D*>**>(_v) = _t->block3d(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        PowderApp *_t = static_cast<PowderApp *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBlock3d(*reinterpret_cast< QVector<Block3D*>**>(_v)); break;
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
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 42)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 42;
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
void PowderApp::newPartAvailable(QSharedPointer<PartObject> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PowderApp::newConfigAvailable(QSharedPointer<SettingsObject> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PowderApp::lgPort_name_changed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PowderApp::mdPort_name_changed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PowderApp::lgPort_connectionRequested(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PowderApp::mdPort_connectionRequested(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PowderApp::reset_printManger()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void PowderApp::cleaDeviceErrors()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void PowderApp::view3d_pressed(QVector<Block3D*> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void PowderApp::close_view3d()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
