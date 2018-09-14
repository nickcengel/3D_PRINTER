/****************************************************************************
** Meta object code from reading C++ file 'manualcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AppR01_4/powder_app/manualcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manualcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ManualController_t {
    QByteArrayData data[18];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ManualController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ManualController_t qt_meta_stringdata_ManualController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ManualController"
QT_MOC_LITERAL(1, 17, 8), // "galvoJog"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "galvoJogCommand"
QT_MOC_LITERAL(4, 43, 19), // "materialDeliveryJog"
QT_MOC_LITERAL(5, 63, 12), // "mdJogCommand"
QT_MOC_LITERAL(6, 76, 17), // "setNewJogDistance"
QT_MOC_LITERAL(7, 94, 11), // "jogDistance"
QT_MOC_LITERAL(8, 106, 11), // "x_increment"
QT_MOC_LITERAL(9, 118, 11), // "x_decrement"
QT_MOC_LITERAL(10, 130, 11), // "y_increment"
QT_MOC_LITERAL(11, 142, 11), // "y_decrement"
QT_MOC_LITERAL(12, 154, 11), // "z_increment"
QT_MOC_LITERAL(13, 166, 11), // "z_decrement"
QT_MOC_LITERAL(14, 178, 11), // "h_increment"
QT_MOC_LITERAL(15, 190, 11), // "h_decrement"
QT_MOC_LITERAL(16, 202, 11), // "s_increment"
QT_MOC_LITERAL(17, 214, 11) // "s_decrement"

    },
    "ManualController\0galvoJog\0\0galvoJogCommand\0"
    "materialDeliveryJog\0mdJogCommand\0"
    "setNewJogDistance\0jogDistance\0x_increment\0"
    "x_decrement\0y_increment\0y_decrement\0"
    "z_increment\0z_decrement\0h_increment\0"
    "h_decrement\0s_increment\0s_decrement"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManualController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       2,   98, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   85,    2, 0x0a /* Public */,
       8,    0,   88,    2, 0x0a /* Public */,
       9,    0,   89,    2, 0x0a /* Public */,
      10,    0,   90,    2, 0x0a /* Public */,
      11,    0,   91,    2, 0x0a /* Public */,
      12,    0,   92,    2, 0x0a /* Public */,
      13,    0,   93,    2, 0x0a /* Public */,
      14,    0,   94,    2, 0x0a /* Public */,
      15,    0,   95,    2, 0x0a /* Public */,
      16,    0,   96,    2, 0x0a /* Public */,
      17,    0,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00095103,
       5, QMetaType::QString, 0x00095103,

       0        // eod
};

void ManualController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ManualController *_t = static_cast<ManualController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->galvoJog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->materialDeliveryJog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setNewJogDistance((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 3: _t->x_increment(); break;
        case 4: _t->x_decrement(); break;
        case 5: _t->y_increment(); break;
        case 6: _t->y_decrement(); break;
        case 7: _t->z_increment(); break;
        case 8: _t->z_decrement(); break;
        case 9: _t->h_increment(); break;
        case 10: _t->h_decrement(); break;
        case 11: _t->s_increment(); break;
        case 12: _t->s_decrement(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ManualController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ManualController::galvoJog)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ManualController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ManualController::materialDeliveryJog)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ManualController *_t = static_cast<ManualController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->galvoJogCommand(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->mdJogCommand(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ManualController *_t = static_cast<ManualController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setGalvoJogCommand(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setMdJogCommand(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ManualController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ManualController.data,
      qt_meta_data_ManualController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ManualController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManualController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ManualController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ManualController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ManualController::galvoJog(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ManualController::materialDeliveryJog(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
