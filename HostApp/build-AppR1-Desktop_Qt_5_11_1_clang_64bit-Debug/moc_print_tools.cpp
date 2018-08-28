/****************************************************************************
** Meta object code from reading C++ file 'print_tools.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AppR1/print_tools.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'print_tools.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PRINT_CONTROL_NS__Print_System_Controller_t {
    QByteArrayData data[12];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PRINT_CONTROL_NS__Print_System_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PRINT_CONTROL_NS__Print_System_Controller_t qt_meta_stringdata_PRINT_CONTROL_NS__Print_System_Controller = {
    {
QT_MOC_LITERAL(0, 0, 41), // "PRINT_CONTROL_NS::Print_Syste..."
QT_MOC_LITERAL(1, 42, 19), // "Laser_Galvo_Command"
QT_MOC_LITERAL(2, 62, 0), // ""
QT_MOC_LITERAL(3, 63, 2), // "cs"
QT_MOC_LITERAL(4, 66, 25), // "Material_Delivery_Command"
QT_MOC_LITERAL(5, 92, 18), // "Laser_Galvo_Socket"
QT_MOC_LITERAL(6, 111, 2), // "rs"
QT_MOC_LITERAL(7, 114, 24), // "Material_Delivery_Socket"
QT_MOC_LITERAL(8, 139, 25), // "Controller_Load_Part_Slot"
QT_MOC_LITERAL(9, 165, 5), // "Part&"
QT_MOC_LITERAL(10, 171, 1), // "p"
QT_MOC_LITERAL(11, 173, 21) // "Controller_Start_Slot"

    },
    "PRINT_CONTROL_NS::Print_System_Controller\0"
    "Laser_Galvo_Command\0\0cs\0"
    "Material_Delivery_Command\0Laser_Galvo_Socket\0"
    "rs\0Material_Delivery_Socket\0"
    "Controller_Load_Part_Slot\0Part&\0p\0"
    "Controller_Start_Slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PRINT_CONTROL_NS__Print_System_Controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   50,    2, 0x0a /* Public */,
       7,    1,   53,    2, 0x0a /* Public */,
       8,    1,   56,    2, 0x0a /* Public */,
      11,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

       0        // eod
};

void PRINT_CONTROL_NS::Print_System_Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Print_System_Controller *_t = static_cast<Print_System_Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Laser_Galvo_Command((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->Material_Delivery_Command((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->Laser_Galvo_Socket((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->Material_Delivery_Socket((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->Controller_Load_Part_Slot((*reinterpret_cast< Part(*)>(_a[1]))); break;
        case 5: _t->Controller_Start_Slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Print_System_Controller::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Print_System_Controller::Laser_Galvo_Command)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Print_System_Controller::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Print_System_Controller::Material_Delivery_Command)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PRINT_CONTROL_NS::Print_System_Controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PRINT_CONTROL_NS__Print_System_Controller.data,
      qt_meta_data_PRINT_CONTROL_NS__Print_System_Controller,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PRINT_CONTROL_NS::Print_System_Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PRINT_CONTROL_NS::Print_System_Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PRINT_CONTROL_NS__Print_System_Controller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PRINT_CONTROL_NS::Print_System_Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void PRINT_CONTROL_NS::Print_System_Controller::Laser_Galvo_Command(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PRINT_CONTROL_NS::Print_System_Controller::Material_Delivery_Command(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
