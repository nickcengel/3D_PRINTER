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
    QByteArrayData data[14];
    char stringdata0[215];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SystemController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SystemController_t qt_meta_stringdata_SystemController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "SystemController"
QT_MOC_LITERAL(1, 17, 21), // "LaserGalvoCommand_sig"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 22), // "current_lg_command_str"
QT_MOC_LITERAL(4, 63, 27), // "MaterialDeliveryCommand_sig"
QT_MOC_LITERAL(5, 91, 22), // "current_md_command_str"
QT_MOC_LITERAL(6, 114, 10), // "simpleSend"
QT_MOC_LITERAL(7, 125, 1), // "s"
QT_MOC_LITERAL(8, 127, 20), // "LaserGalvoReply_slot"
QT_MOC_LITERAL(9, 148, 7), // "Message"
QT_MOC_LITERAL(10, 156, 8), // "lg_reply"
QT_MOC_LITERAL(11, 165, 26), // "MaterialDeliveryReply_slot"
QT_MOC_LITERAL(12, 192, 8), // "md_reply"
QT_MOC_LITERAL(13, 201, 13) // "simpleReceive"

    },
    "SystemController\0LaserGalvoCommand_sig\0"
    "\0current_lg_command_str\0"
    "MaterialDeliveryCommand_sig\0"
    "current_md_command_str\0simpleSend\0s\0"
    "LaserGalvoReply_slot\0Message\0lg_reply\0"
    "MaterialDeliveryReply_slot\0md_reply\0"
    "simpleReceive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SystemController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   53,    2, 0x0a /* Public */,
      11,    1,   56,    2, 0x0a /* Public */,
      13,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   12,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void SystemController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SystemController *_t = static_cast<SystemController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->LaserGalvoCommand_sig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->MaterialDeliveryCommand_sig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->simpleSend((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->LaserGalvoReply_slot((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 4: _t->MaterialDeliveryReply_slot((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 5: _t->simpleReceive((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SystemController::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SystemController::LaserGalvoCommand_sig)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SystemController::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SystemController::MaterialDeliveryCommand_sig)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SystemController::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SystemController::simpleSend)) {
                *result = 2;
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
void SystemController::LaserGalvoCommand_sig(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SystemController::MaterialDeliveryCommand_sig(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SystemController::simpleSend(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
