/****************************************************************************
** Meta object code from reading C++ file 'powderapp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AppR01_3/powderapp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
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
    QByteArrayData data[19];
    char stringdata0[491];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PowderApp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PowderApp_t qt_meta_stringdata_PowderApp = {
    {
QT_MOC_LITERAL(0, 0, 9), // "PowderApp"
QT_MOC_LITERAL(1, 10, 14), // "view3d_pressed"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 15), // "NewPartFilePath"
QT_MOC_LITERAL(4, 42, 8), // "filePath"
QT_MOC_LITERAL(5, 51, 41), // "on_settings_button_resetToDef..."
QT_MOC_LITERAL(6, 93, 35), // "on_settings_button_openFile_c..."
QT_MOC_LITERAL(7, 129, 36), // "on_settings_buttons_saveFile_..."
QT_MOC_LITERAL(8, 166, 39), // "on_settings_button_refreshPor..."
QT_MOC_LITERAL(9, 206, 32), // "on_settings_button_apply_clicked"
QT_MOC_LITERAL(10, 239, 19), // "on_MenuTree_clicked"
QT_MOC_LITERAL(11, 259, 11), // "QModelIndex"
QT_MOC_LITERAL(12, 271, 5), // "index"
QT_MOC_LITERAL(13, 277, 37), // "on_gcode_tool_button_openFile..."
QT_MOC_LITERAL(14, 315, 40), // "on_Main_Button_ConfigurationP..."
QT_MOC_LITERAL(15, 356, 31), // "on_Main_Button_PortPage_clicked"
QT_MOC_LITERAL(16, 388, 32), // "on_Main_Button_GCodePage_clicked"
QT_MOC_LITERAL(17, 421, 37), // "on_Main_Button_ControllerPage..."
QT_MOC_LITERAL(18, 459, 31) // "on_Main_Button_HelpPage_clicked"

    },
    "PowderApp\0view3d_pressed\0\0NewPartFilePath\0"
    "filePath\0on_settings_button_resetToDefault_clicked\0"
    "on_settings_button_openFile_clicked\0"
    "on_settings_buttons_saveFile_clicked\0"
    "on_settings_button_refreshPorts_clicked\0"
    "on_settings_button_apply_clicked\0"
    "on_MenuTree_clicked\0QModelIndex\0index\0"
    "on_gcode_tool_button_openFile_clicked\0"
    "on_Main_Button_ConfigurationPage_clicked\0"
    "on_Main_Button_PortPage_clicked\0"
    "on_Main_Button_GCodePage_clicked\0"
    "on_Main_Button_ControllerPage_clicked\0"
    "on_Main_Button_HelpPage_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PowderApp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    1,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   88,    2, 0x08 /* Private */,
       6,    0,   89,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    1,   93,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    0,   97,    2, 0x08 /* Private */,
      15,    0,   98,    2, 0x08 /* Private */,
      16,    0,   99,    2, 0x08 /* Private */,
      17,    0,  100,    2, 0x08 /* Private */,
      18,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PowderApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PowderApp *_t = static_cast<PowderApp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->view3d_pressed(); break;
        case 1: _t->NewPartFilePath((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_settings_button_resetToDefault_clicked(); break;
        case 3: _t->on_settings_button_openFile_clicked(); break;
        case 4: _t->on_settings_buttons_saveFile_clicked(); break;
        case 5: _t->on_settings_button_refreshPorts_clicked(); break;
        case 6: _t->on_settings_button_apply_clicked(); break;
        case 7: _t->on_MenuTree_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_gcode_tool_button_openFile_clicked(); break;
        case 9: _t->on_Main_Button_ConfigurationPage_clicked(); break;
        case 10: _t->on_Main_Button_PortPage_clicked(); break;
        case 11: _t->on_Main_Button_GCodePage_clicked(); break;
        case 12: _t->on_Main_Button_ControllerPage_clicked(); break;
        case 13: _t->on_Main_Button_HelpPage_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PowderApp::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::view3d_pressed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PowderApp::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderApp::NewPartFilePath)) {
                *result = 1;
                return;
            }
        }
    }
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void PowderApp::view3d_pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PowderApp::NewPartFilePath(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
