/****************************************************************************
** Meta object code from reading C++ file 'printcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AppR01_4/powder_app/printcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'printcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PrintController_t {
    QByteArrayData data[28];
    char stringdata0[406];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PrintController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PrintController_t qt_meta_stringdata_PrintController = {
    {
QT_MOC_LITERAL(0, 0, 15), // "PrintController"
QT_MOC_LITERAL(1, 16, 10), // "printStart"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "printStop"
QT_MOC_LITERAL(4, 38, 18), // "x_position_changed"
QT_MOC_LITERAL(5, 57, 10), // "x_position"
QT_MOC_LITERAL(6, 68, 18), // "y_position_changed"
QT_MOC_LITERAL(7, 87, 10), // "y_position"
QT_MOC_LITERAL(8, 98, 18), // "z_position_changed"
QT_MOC_LITERAL(9, 117, 10), // "z_position"
QT_MOC_LITERAL(10, 128, 18), // "h_position_changed"
QT_MOC_LITERAL(11, 147, 10), // "h_position"
QT_MOC_LITERAL(12, 158, 18), // "s_position_changed"
QT_MOC_LITERAL(13, 177, 10), // "s_position"
QT_MOC_LITERAL(14, 188, 22), // "laser_armState_changed"
QT_MOC_LITERAL(15, 211, 8), // "armState"
QT_MOC_LITERAL(16, 220, 25), // "laser_enableState_changed"
QT_MOC_LITERAL(17, 246, 11), // "enableState"
QT_MOC_LITERAL(18, 258, 20), // "on_startPrint_button"
QT_MOC_LITERAL(19, 279, 19), // "on_stopPrint_button"
QT_MOC_LITERAL(20, 299, 16), // "on_blockComplete"
QT_MOC_LITERAL(21, 316, 8), // "blockNum"
QT_MOC_LITERAL(22, 325, 18), // "on_processComplete"
QT_MOC_LITERAL(23, 344, 11), // "on_lg_error"
QT_MOC_LITERAL(24, 356, 5), // "error"
QT_MOC_LITERAL(25, 362, 11), // "on_md_error"
QT_MOC_LITERAL(26, 374, 10), // "blockStack"
QT_MOC_LITERAL(27, 385, 20) // "QVector<BlockObject>"

    },
    "PrintController\0printStart\0\0printStop\0"
    "x_position_changed\0x_position\0"
    "y_position_changed\0y_position\0"
    "z_position_changed\0z_position\0"
    "h_position_changed\0h_position\0"
    "s_position_changed\0s_position\0"
    "laser_armState_changed\0armState\0"
    "laser_enableState_changed\0enableState\0"
    "on_startPrint_button\0on_stopPrint_button\0"
    "on_blockComplete\0blockNum\0on_processComplete\0"
    "on_lg_error\0error\0on_md_error\0blockStack\0"
    "QVector<BlockObject>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PrintController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       1,  124, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    1,   91,    2, 0x06 /* Public */,
       6,    1,   94,    2, 0x06 /* Public */,
       8,    1,   97,    2, 0x06 /* Public */,
      10,    1,  100,    2, 0x06 /* Public */,
      12,    1,  103,    2, 0x06 /* Public */,
      14,    1,  106,    2, 0x06 /* Public */,
      16,    1,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,  112,    2, 0x0a /* Public */,
      19,    0,  113,    2, 0x0a /* Public */,
      20,    1,  114,    2, 0x0a /* Public */,
      22,    0,  117,    2, 0x0a /* Public */,
      23,    1,  118,    2, 0x08 /* Private */,
      25,    1,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void, QMetaType::Float,    7,
    QMetaType::Void, QMetaType::Float,    9,
    QMetaType::Void, QMetaType::Float,   11,
    QMetaType::Void, QMetaType::Float,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   17,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,   24,

 // properties: name, type, flags
      26, 0x80000000 | 27, 0x0009510b,

       0        // eod
};

void PrintController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PrintController *_t = static_cast<PrintController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->printStart(); break;
        case 1: _t->printStop(); break;
        case 2: _t->x_position_changed((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 3: _t->y_position_changed((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 4: _t->z_position_changed((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 5: _t->h_position_changed((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 6: _t->s_position_changed((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 7: _t->laser_armState_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->laser_enableState_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_startPrint_button(); break;
        case 10: _t->on_stopPrint_button(); break;
        case 11: _t->on_blockComplete((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 12: _t->on_processComplete(); break;
        case 13: _t->on_lg_error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_md_error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PrintController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PrintController::printStart)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PrintController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PrintController::printStop)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PrintController::*)(const float & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PrintController::x_position_changed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PrintController::*)(const float & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PrintController::y_position_changed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PrintController::*)(const float & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PrintController::z_position_changed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PrintController::*)(const float & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PrintController::h_position_changed)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PrintController::*)(const float & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PrintController::s_position_changed)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (PrintController::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PrintController::laser_armState_changed)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (PrintController::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PrintController::laser_enableState_changed)) {
                *result = 8;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<BlockObject> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        PrintController *_t = static_cast<PrintController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVector<BlockObject>*>(_v) = _t->blockStack(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        PrintController *_t = static_cast<PrintController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBlockStack(*reinterpret_cast< QVector<BlockObject>*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject PrintController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PrintController.data,
      qt_meta_data_PrintController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PrintController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PrintController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PrintController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PrintController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
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
void PrintController::printStart()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PrintController::printStop()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PrintController::x_position_changed(const float & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PrintController::y_position_changed(const float & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PrintController::z_position_changed(const float & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PrintController::h_position_changed(const float & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PrintController::s_position_changed(const float & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PrintController::laser_armState_changed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PrintController::laser_enableState_changed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
