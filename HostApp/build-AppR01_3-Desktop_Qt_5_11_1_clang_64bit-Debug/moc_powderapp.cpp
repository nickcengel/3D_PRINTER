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
    QByteArrayData data[45];
    char stringdata0[1236];
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
QT_MOC_LITERAL(3, 28, 14), // "view3d_pressed"
QT_MOC_LITERAL(4, 43, 18), // "QVector<Block3D*>*"
QT_MOC_LITERAL(5, 62, 7), // "block3d"
QT_MOC_LITERAL(6, 70, 12), // "close_view3d"
QT_MOC_LITERAL(7, 83, 21), // "laserGalvoPort_opened"
QT_MOC_LITERAL(8, 105, 17), // "QSerialPort*const"
QT_MOC_LITERAL(9, 123, 4), // "port"
QT_MOC_LITERAL(10, 128, 27), // "materialDeliveryPort_opened"
QT_MOC_LITERAL(11, 156, 34), // "laserGalvoPort_connectionRequ..."
QT_MOC_LITERAL(12, 191, 4), // "open"
QT_MOC_LITERAL(13, 196, 40), // "materialDeliveryPort_connecti..."
QT_MOC_LITERAL(14, 237, 30), // "laserGalvoPort_connectionError"
QT_MOC_LITERAL(15, 268, 15), // "connectionError"
QT_MOC_LITERAL(16, 284, 36), // "materialDeliveryPort_connecti..."
QT_MOC_LITERAL(17, 321, 32), // "laserGalvoPort_connectionChanged"
QT_MOC_LITERAL(18, 354, 38), // "materialDeliveryPort_connecti..."
QT_MOC_LITERAL(19, 393, 41), // "on_settings_button_resetToDef..."
QT_MOC_LITERAL(20, 435, 35), // "on_settings_button_openFile_c..."
QT_MOC_LITERAL(21, 471, 36), // "on_settings_buttons_saveFile_..."
QT_MOC_LITERAL(22, 508, 39), // "on_settings_button_refreshPor..."
QT_MOC_LITERAL(23, 548, 32), // "on_settings_button_apply_clicked"
QT_MOC_LITERAL(24, 581, 19), // "on_MenuTree_clicked"
QT_MOC_LITERAL(25, 601, 11), // "QModelIndex"
QT_MOC_LITERAL(26, 613, 5), // "index"
QT_MOC_LITERAL(27, 619, 37), // "on_gcode_tool_button_openFile..."
QT_MOC_LITERAL(28, 657, 38), // "on_gcode_tool_button_clearPar..."
QT_MOC_LITERAL(29, 696, 40), // "on_Main_Button_ConfigurationP..."
QT_MOC_LITERAL(30, 737, 31), // "on_Main_Button_PortPage_clicked"
QT_MOC_LITERAL(31, 769, 32), // "on_Main_Button_GCodePage_clicked"
QT_MOC_LITERAL(32, 802, 37), // "on_Main_Button_ControllerPage..."
QT_MOC_LITERAL(33, 840, 31), // "on_Main_Button_HelpPage_clicked"
QT_MOC_LITERAL(34, 872, 36), // "on_printManager_start_button_..."
QT_MOC_LITERAL(35, 909, 36), // "on_PortManager_options_box_ac..."
QT_MOC_LITERAL(36, 946, 4), // "arg1"
QT_MOC_LITERAL(37, 951, 37), // "on_laserGalvoPort_connectionR..."
QT_MOC_LITERAL(38, 989, 43), // "on_materialDeliveryPort_conne..."
QT_MOC_LITERAL(39, 1033, 37), // "on_ManualControlEnable_button..."
QT_MOC_LITERAL(40, 1071, 7), // "checked"
QT_MOC_LITERAL(41, 1079, 36), // "on_galvoDisplayEnable_button_..."
QT_MOC_LITERAL(42, 1116, 34), // "on_buildPlateEnable_button_to..."
QT_MOC_LITERAL(43, 1151, 47), // "on_materialDeliveryDisplayEna..."
QT_MOC_LITERAL(44, 1199, 36) // "on_PrintManagerEnable_button_..."

    },
    "PowderApp\0newPartAvailable\0\0view3d_pressed\0"
    "QVector<Block3D*>*\0block3d\0close_view3d\0"
    "laserGalvoPort_opened\0QSerialPort*const\0"
    "port\0materialDeliveryPort_opened\0"
    "laserGalvoPort_connectionRequested\0"
    "open\0materialDeliveryPort_connectionRequested\0"
    "laserGalvoPort_connectionError\0"
    "connectionError\0materialDeliveryPort_connectionError\0"
    "laserGalvoPort_connectionChanged\0"
    "materialDeliveryPort_connectionChanged\0"
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
    "on_printManager_start_button_pressed\0"
    "on_PortManager_options_box_activated\0"
    "arg1\0on_laserGalvoPort_connectionRequested\0"
    "on_materialDeliveryPort_connectionRequested\0"
    "on_ManualControlEnable_button_toggled\0"
    "checked\0on_galvoDisplayEnable_button_toggled\0"
    "on_buildPlateEnable_button_toggled\0"
    "on_materialDeliveryDisplayEnable_button_toggled\0"
    "on_PrintManagerEnable_button_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PowderApp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       1,  256, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  184,    2, 0x06 /* Public */,
       3,    1,  185,    2, 0x06 /* Public */,
       6,    0,  188,    2, 0x06 /* Public */,
       7,    1,  189,    2, 0x06 /* Public */,
      10,    1,  192,    2, 0x06 /* Public */,
      11,    1,  195,    2, 0x06 /* Public */,
      13,    1,  198,    2, 0x06 /* Public */,
      14,    1,  201,    2, 0x06 /* Public */,
      16,    1,  204,    2, 0x06 /* Public */,
      17,    1,  207,    2, 0x06 /* Public */,
      18,    1,  210,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    0,  213,    2, 0x08 /* Private */,
      20,    0,  214,    2, 0x08 /* Private */,
      21,    0,  215,    2, 0x08 /* Private */,
      22,    0,  216,    2, 0x08 /* Private */,
      23,    0,  217,    2, 0x08 /* Private */,
      24,    1,  218,    2, 0x08 /* Private */,
      27,    0,  221,    2, 0x08 /* Private */,
      28,    0,  222,    2, 0x08 /* Private */,
      29,    0,  223,    2, 0x08 /* Private */,
      30,    0,  224,    2, 0x08 /* Private */,
      31,    0,  225,    2, 0x08 /* Private */,
      32,    0,  226,    2, 0x08 /* Private */,
      33,    0,  227,    2, 0x08 /* Private */,
      34,    0,  228,    2, 0x08 /* Private */,
      35,    1,  229,    2, 0x08 /* Private */,
      35,    1,  232,    2, 0x08 /* Private */,
      37,    1,  235,    2, 0x08 /* Private */,
      38,    1,  238,    2, 0x08 /* Private */,
      39,    1,  241,    2, 0x08 /* Private */,
      41,    1,  244,    2, 0x08 /* Private */,
      42,    1,  247,    2, 0x08 /* Private */,
      43,    1,  250,    2, 0x08 /* Private */,
      44,    1,  253,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::QString,   36,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   40,
    QMetaType::Void, QMetaType::Bool,   40,
    QMetaType::Void, QMetaType::Bool,   40,
    QMetaType::Void, QMetaType::Bool,   40,
    QMetaType::Void, QMetaType::Bool,   40,

 // properties: name, type, flags
       5, 0x80000000 | 4, 0x0009510b,

       0        // eod
};

void PowderApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PowderApp *_t = static_cast<PowderApp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newPartAvailable(); break;
        case 1: _t->view3d_pressed((*reinterpret_cast< QVector<Block3D*>*(*)>(_a[1]))); break;
        case 2: _t->close_view3d(); break;
        case 3: _t->laserGalvoPort_opened((*reinterpret_cast< QSerialPort*const(*)>(_a[1]))); break;
        case 4: _t->materialDeliveryPort_opened((*reinterpret_cast< QSerialPort*const(*)>(_a[1]))); break;
        case 5: _t->laserGalvoPort_connectionRequested((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 6: _t->materialDeliveryPort_connectionRequested((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 7: _t->laserGalvoPort_connectionError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->materialDeliveryPort_connectionError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->laserGalvoPort_connectionChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 10: _t->materialDeliveryPort_connectionChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
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
        case 24: _t->on_printManager_start_button_pressed(); break;
        case 25: _t->on_PortManager_options_box_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_PortManager_options_box_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 27: _t->on_laserGalvoPort_connectionRequested((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 28: _t->on_materialDeliveryPort_connectionRequested((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 29: _t->on_ManualControlEnable_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->on_galvoDisplayEnable_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->on_buildPlateEnable_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->on_materialDeliveryDisplayEnable_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->on_PrintManagerEnable_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PowderApp::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::newPartAvailable)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(QVector<Block3D*> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::view3d_pressed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::close_view3d)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(QSerialPort * const );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::laserGalvoPort_opened)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(QSerialPort * const );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::materialDeliveryPort_opened)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(const bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::laserGalvoPort_connectionRequested)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(const bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::materialDeliveryPort_connectionRequested)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::laserGalvoPort_connectionError)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::materialDeliveryPort_connectionError)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(const bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::laserGalvoPort_connectionChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(const bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::materialDeliveryPort_connectionChanged)) {
                *result = 10;
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
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 34)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 34;
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
void PowderApp::newPartAvailable()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PowderApp::view3d_pressed(QVector<Block3D*> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PowderApp::close_view3d()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PowderApp::laserGalvoPort_opened(QSerialPort * const _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PowderApp::materialDeliveryPort_opened(QSerialPort * const _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PowderApp::laserGalvoPort_connectionRequested(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PowderApp::materialDeliveryPort_connectionRequested(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PowderApp::laserGalvoPort_connectionError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PowderApp::materialDeliveryPort_connectionError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void PowderApp::laserGalvoPort_connectionChanged(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void PowderApp::materialDeliveryPort_connectionChanged(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
