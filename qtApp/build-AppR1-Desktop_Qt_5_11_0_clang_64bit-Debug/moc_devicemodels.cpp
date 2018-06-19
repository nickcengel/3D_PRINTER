/****************************************************************************
** Meta object code from reading C++ file 'devicemodels.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AppR1/devicemodels.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'devicemodels.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SystemController_t {
    QByteArrayData data[13];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SystemController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SystemController_t qt_meta_stringdata_SystemController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "SystemController"
QT_MOC_LITERAL(1, 17, 16), // "laserGalvoSignal"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 10), // "LG_Package"
QT_MOC_LITERAL(4, 46, 6), // "lgsOut"
QT_MOC_LITERAL(5, 53, 22), // "MaterialDeliverySignal"
QT_MOC_LITERAL(6, 76, 10), // "MD_Package"
QT_MOC_LITERAL(7, 87, 6), // "mdsOut"
QT_MOC_LITERAL(8, 94, 15), // "laserGalvoReply"
QT_MOC_LITERAL(9, 110, 6), // "LG_Map"
QT_MOC_LITERAL(10, 117, 5), // "reply"
QT_MOC_LITERAL(11, 123, 21), // "MaterialDeliveryReply"
QT_MOC_LITERAL(12, 145, 6) // "MD_Map"

    },
    "SystemController\0laserGalvoSignal\0\0"
    "LG_Package\0lgsOut\0MaterialDeliverySignal\0"
    "MD_Package\0mdsOut\0laserGalvoReply\0"
    "LG_Map\0reply\0MaterialDeliveryReply\0"
    "MD_Map"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SystemController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   40,    2, 0x0a /* Public */,
      11,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   10,

       0        // eod
};

void SystemController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SystemController *_t = static_cast<SystemController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->laserGalvoSignal((*reinterpret_cast< LG_Package(*)>(_a[1]))); break;
        case 1: _t->MaterialDeliverySignal((*reinterpret_cast< MD_Package(*)>(_a[1]))); break;
        case 2: _t->laserGalvoReply((*reinterpret_cast< LG_Map(*)>(_a[1]))); break;
        case 3: _t->MaterialDeliveryReply((*reinterpret_cast< MD_Map(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SystemController::*)(LG_Package );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SystemController::laserGalvoSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SystemController::*)(MD_Package );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SystemController::MaterialDeliverySignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SystemController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SystemController.data,
      qt_meta_data_SystemController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SystemController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SystemController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SystemController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SystemController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void SystemController::laserGalvoSignal(LG_Package _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SystemController::MaterialDeliverySignal(MD_Package _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
