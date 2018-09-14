/****************************************************************************
** Meta object code from reading C++ file 'lasergalvodaemon.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AppR01_4/hardware_tools/lasergalvodaemon.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lasergalvodaemon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LaserGalvoDaemon_t {
    QByteArrayData data[22];
    char stringdata0[261];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LaserGalvoDaemon_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LaserGalvoDaemon_t qt_meta_stringdata_LaserGalvoDaemon = {
    {
QT_MOC_LITERAL(0, 0, 16), // "LaserGalvoDaemon"
QT_MOC_LITERAL(1, 17, 16), // "port_isConnected"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 14), // "commandPending"
QT_MOC_LITERAL(4, 50, 9), // "portError"
QT_MOC_LITERAL(5, 60, 5), // "error"
QT_MOC_LITERAL(6, 66, 10), // "replyError"
QT_MOC_LITERAL(7, 77, 11), // "commandSent"
QT_MOC_LITERAL(8, 89, 16), // "commandConfirmed"
QT_MOC_LITERAL(9, 106, 9), // "reconnect"
QT_MOC_LITERAL(10, 116, 11), // "setPortName"
QT_MOC_LITERAL(11, 128, 4), // "name"
QT_MOC_LITERAL(12, 133, 13), // "on_daemonInit"
QT_MOC_LITERAL(13, 147, 8), // "openPort"
QT_MOC_LITERAL(14, 156, 11), // "writeToPort"
QT_MOC_LITERAL(15, 168, 7), // "command"
QT_MOC_LITERAL(16, 176, 17), // "checkBytesWritten"
QT_MOC_LITERAL(17, 194, 5), // "bytes"
QT_MOC_LITERAL(18, 200, 14), // "checkBytesRead"
QT_MOC_LITERAL(19, 215, 14), // "commandTimeout"
QT_MOC_LITERAL(20, 230, 12), // "replyTimeout"
QT_MOC_LITERAL(21, 243, 17) // "clearDaemonErrors"

    },
    "LaserGalvoDaemon\0port_isConnected\0\0"
    "commandPending\0portError\0error\0"
    "replyError\0commandSent\0commandConfirmed\0"
    "reconnect\0setPortName\0name\0on_daemonInit\0"
    "openPort\0writeToPort\0command\0"
    "checkBytesWritten\0bytes\0checkBytesRead\0"
    "commandTimeout\0replyTimeout\0"
    "clearDaemonErrors"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LaserGalvoDaemon[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,
       4,    1,   96,    2, 0x06 /* Public */,
       6,    1,   99,    2, 0x06 /* Public */,
       7,    0,  102,    2, 0x06 /* Public */,
       8,    0,  103,    2, 0x06 /* Public */,
       9,    0,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,  105,    2, 0x0a /* Public */,
      12,    0,  108,    2, 0x0a /* Public */,
      13,    0,  109,    2, 0x0a /* Public */,
      14,    1,  110,    2, 0x0a /* Public */,
      16,    1,  113,    2, 0x0a /* Public */,
      18,    0,  116,    2, 0x0a /* Public */,
      19,    0,  117,    2, 0x0a /* Public */,
      20,    0,  118,    2, 0x0a /* Public */,
      21,    0,  119,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::LongLong,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LaserGalvoDaemon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LaserGalvoDaemon *_t = static_cast<LaserGalvoDaemon *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->port_isConnected(); break;
        case 1: _t->commandPending(); break;
        case 2: _t->portError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->replyError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->commandSent(); break;
        case 5: _t->commandConfirmed(); break;
        case 6: _t->reconnect(); break;
        case 7: _t->setPortName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_daemonInit(); break;
        case 9: _t->openPort(); break;
        case 10: _t->writeToPort((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->checkBytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 12: _t->checkBytesRead(); break;
        case 13: _t->commandTimeout(); break;
        case 14: _t->replyTimeout(); break;
        case 15: _t->clearDaemonErrors(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LaserGalvoDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LaserGalvoDaemon::port_isConnected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LaserGalvoDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LaserGalvoDaemon::commandPending)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LaserGalvoDaemon::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LaserGalvoDaemon::portError)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (LaserGalvoDaemon::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LaserGalvoDaemon::replyError)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (LaserGalvoDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LaserGalvoDaemon::commandSent)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (LaserGalvoDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LaserGalvoDaemon::commandConfirmed)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (LaserGalvoDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LaserGalvoDaemon::reconnect)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LaserGalvoDaemon::staticMetaObject = {
    { &QStateMachine::staticMetaObject, qt_meta_stringdata_LaserGalvoDaemon.data,
      qt_meta_data_LaserGalvoDaemon,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LaserGalvoDaemon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LaserGalvoDaemon::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LaserGalvoDaemon.stringdata0))
        return static_cast<void*>(this);
    return QStateMachine::qt_metacast(_clname);
}

int LaserGalvoDaemon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStateMachine::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void LaserGalvoDaemon::port_isConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LaserGalvoDaemon::commandPending()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void LaserGalvoDaemon::portError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LaserGalvoDaemon::replyError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void LaserGalvoDaemon::commandSent()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void LaserGalvoDaemon::commandConfirmed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void LaserGalvoDaemon::reconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
struct qt_meta_stringdata_LaserGalvoController_t {
    QByteArrayData data[23];
    char stringdata0[452];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LaserGalvoController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LaserGalvoController_t qt_meta_stringdata_LaserGalvoController = {
    {
QT_MOC_LITERAL(0, 0, 20), // "LaserGalvoController"
QT_MOC_LITERAL(1, 21, 28), // "controllerPort_isOpen_output"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 31), // "controllerCommandPending_output"
QT_MOC_LITERAL(4, 83, 7), // "command"
QT_MOC_LITERAL(5, 91, 26), // "controllerPortError_output"
QT_MOC_LITERAL(6, 118, 5), // "error"
QT_MOC_LITERAL(7, 124, 23), // "deviceReplyError_output"
QT_MOC_LITERAL(8, 148, 26), // "transactionComplete_output"
QT_MOC_LITERAL(9, 175, 18), // "newPortName_signal"
QT_MOC_LITERAL(10, 194, 4), // "name"
QT_MOC_LITERAL(11, 199, 25), // "activateController_signal"
QT_MOC_LITERAL(12, 225, 27), // "deactivateController_signal"
QT_MOC_LITERAL(13, 253, 18), // "clearErrors_signal"
QT_MOC_LITERAL(14, 272, 18), // "portName_inputSlot"
QT_MOC_LITERAL(15, 291, 28), // "activateController_inputSlot"
QT_MOC_LITERAL(16, 320, 30), // "deactivateController_inputSlot"
QT_MOC_LITERAL(17, 351, 13), // "command_input"
QT_MOC_LITERAL(18, 365, 21), // "clearErrors_inputSlot"
QT_MOC_LITERAL(19, 387, 13), // "on_portOpened"
QT_MOC_LITERAL(20, 401, 12), // "on_portError"
QT_MOC_LITERAL(21, 414, 13), // "on_replyError"
QT_MOC_LITERAL(22, 428, 23) // "on_transactionCompleted"

    },
    "LaserGalvoController\0controllerPort_isOpen_output\0"
    "\0controllerCommandPending_output\0"
    "command\0controllerPortError_output\0"
    "error\0deviceReplyError_output\0"
    "transactionComplete_output\0"
    "newPortName_signal\0name\0"
    "activateController_signal\0"
    "deactivateController_signal\0"
    "clearErrors_signal\0portName_inputSlot\0"
    "activateController_inputSlot\0"
    "deactivateController_inputSlot\0"
    "command_input\0clearErrors_inputSlot\0"
    "on_portOpened\0on_portError\0on_replyError\0"
    "on_transactionCompleted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LaserGalvoController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    1,  105,    2, 0x06 /* Public */,
       5,    1,  108,    2, 0x06 /* Public */,
       7,    1,  111,    2, 0x06 /* Public */,
       8,    0,  114,    2, 0x06 /* Public */,
       9,    1,  115,    2, 0x06 /* Public */,
      11,    0,  118,    2, 0x06 /* Public */,
      12,    0,  119,    2, 0x06 /* Public */,
      13,    0,  120,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,  121,    2, 0x0a /* Public */,
      15,    0,  124,    2, 0x0a /* Public */,
      16,    0,  125,    2, 0x0a /* Public */,
      17,    1,  126,    2, 0x0a /* Public */,
      18,    0,  129,    2, 0x0a /* Public */,
      19,    0,  130,    2, 0x0a /* Public */,
      20,    1,  131,    2, 0x0a /* Public */,
      21,    1,  134,    2, 0x0a /* Public */,
      22,    0,  137,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

       0        // eod
};

void LaserGalvoController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LaserGalvoController *_t = static_cast<LaserGalvoController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->controllerPort_isOpen_output(); break;
        case 1: _t->controllerCommandPending_output((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->controllerPortError_output((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->deviceReplyError_output((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->transactionComplete_output(); break;
        case 5: _t->newPortName_signal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->activateController_signal(); break;
        case 7: _t->deactivateController_signal(); break;
        case 8: _t->clearErrors_signal(); break;
        case 9: _t->portName_inputSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->activateController_inputSlot(); break;
        case 11: _t->deactivateController_inputSlot(); break;
        case 12: _t->command_input((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->clearErrors_inputSlot(); break;
        case 14: _t->on_portOpened(); break;
        case 15: _t->on_portError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->on_replyError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->on_transactionCompleted(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LaserGalvoController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LaserGalvoController::controllerPort_isOpen_output)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LaserGalvoController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LaserGalvoController::controllerCommandPending_output)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LaserGalvoController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LaserGalvoController::controllerPortError_output)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (LaserGalvoController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LaserGalvoController::deviceReplyError_output)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (LaserGalvoController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LaserGalvoController::transactionComplete_output)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (LaserGalvoController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LaserGalvoController::newPortName_signal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (LaserGalvoController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LaserGalvoController::activateController_signal)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (LaserGalvoController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LaserGalvoController::deactivateController_signal)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (LaserGalvoController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LaserGalvoController::clearErrors_signal)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LaserGalvoController::staticMetaObject = {
    { &QStateMachine::staticMetaObject, qt_meta_stringdata_LaserGalvoController.data,
      qt_meta_data_LaserGalvoController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LaserGalvoController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LaserGalvoController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LaserGalvoController.stringdata0))
        return static_cast<void*>(this);
    return QStateMachine::qt_metacast(_clname);
}

int LaserGalvoController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStateMachine::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void LaserGalvoController::controllerPort_isOpen_output()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LaserGalvoController::controllerCommandPending_output(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LaserGalvoController::controllerPortError_output(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LaserGalvoController::deviceReplyError_output(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void LaserGalvoController::transactionComplete_output()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void LaserGalvoController::newPortName_signal(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void LaserGalvoController::activateController_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void LaserGalvoController::deactivateController_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void LaserGalvoController::clearErrors_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
