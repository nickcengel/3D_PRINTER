/****************************************************************************
** Meta object code from reading C++ file 'axis.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AppR1/axis.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'axis.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Axis_t {
    QByteArrayData data[77];
    char stringdata0[1040];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Axis_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Axis_t qt_meta_stringdata_Axis = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Axis"
QT_MOC_LITERAL(1, 5, 17), // "portNumberChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "portNumber"
QT_MOC_LITERAL(4, 35, 19), // "deviceNumberChanged"
QT_MOC_LITERAL(5, 55, 12), // "deviceNumber"
QT_MOC_LITERAL(6, 68, 14), // "enabledChanged"
QT_MOC_LITERAL(7, 83, 7), // "enabled"
QT_MOC_LITERAL(8, 91, 16), // "connectedChanged"
QT_MOC_LITERAL(9, 108, 9), // "connected"
QT_MOC_LITERAL(10, 118, 19), // "replyPendingChanged"
QT_MOC_LITERAL(11, 138, 12), // "replyPending"
QT_MOC_LITERAL(12, 151, 16), // "axisTitleChanged"
QT_MOC_LITERAL(13, 168, 9), // "AxisTitle"
QT_MOC_LITERAL(14, 178, 4), // "axis"
QT_MOC_LITERAL(15, 183, 13), // "statusRequest"
QT_MOC_LITERAL(16, 197, 12), // "errorChanged"
QT_MOC_LITERAL(17, 210, 5), // "error"
QT_MOC_LITERAL(18, 216, 18), // "positionMinChanged"
QT_MOC_LITERAL(19, 235, 11), // "positionMin"
QT_MOC_LITERAL(20, 247, 18), // "positionMaxChanged"
QT_MOC_LITERAL(21, 266, 11), // "positionMax"
QT_MOC_LITERAL(22, 278, 15), // "speedMinChanged"
QT_MOC_LITERAL(23, 294, 8), // "speedMin"
QT_MOC_LITERAL(24, 303, 15), // "speedMaxChanged"
QT_MOC_LITERAL(25, 319, 8), // "speedMax"
QT_MOC_LITERAL(26, 328, 17), // "homeOffsetChanged"
QT_MOC_LITERAL(27, 346, 10), // "homeOffset"
QT_MOC_LITERAL(28, 357, 12), // "homedChanged"
QT_MOC_LITERAL(29, 370, 5), // "homed"
QT_MOC_LITERAL(30, 376, 19), // "currentSpeedChanged"
QT_MOC_LITERAL(31, 396, 12), // "currentSpeed"
QT_MOC_LITERAL(32, 409, 26), // "currentAccelerationChanged"
QT_MOC_LITERAL(33, 436, 19), // "currentAcceleration"
QT_MOC_LITERAL(34, 456, 22), // "currentPositionChanged"
QT_MOC_LITERAL(35, 479, 15), // "currentPosition"
QT_MOC_LITERAL(36, 495, 21), // "requestedHomedChanged"
QT_MOC_LITERAL(37, 517, 14), // "requestedHomed"
QT_MOC_LITERAL(38, 532, 21), // "requestedSpeedChanged"
QT_MOC_LITERAL(39, 554, 14), // "requestedSpeed"
QT_MOC_LITERAL(40, 569, 28), // "requestedAccelerationChanged"
QT_MOC_LITERAL(41, 598, 21), // "requestedAcceleration"
QT_MOC_LITERAL(42, 620, 24), // "requestedPositionChanged"
QT_MOC_LITERAL(43, 645, 17), // "requestedPosition"
QT_MOC_LITERAL(44, 663, 10), // "updateAxis"
QT_MOC_LITERAL(45, 674, 5), // "reply"
QT_MOC_LITERAL(46, 680, 13), // "setPortNumber"
QT_MOC_LITERAL(47, 694, 15), // "setDeviceNumber"
QT_MOC_LITERAL(48, 710, 10), // "setEnabled"
QT_MOC_LITERAL(49, 721, 12), // "setConnected"
QT_MOC_LITERAL(50, 734, 12), // "setAxisTitle"
QT_MOC_LITERAL(51, 747, 9), // "axisTitle"
QT_MOC_LITERAL(52, 757, 13), // "requestStatus"
QT_MOC_LITERAL(53, 771, 14), // "setPositionMin"
QT_MOC_LITERAL(54, 786, 14), // "setPositionMax"
QT_MOC_LITERAL(55, 801, 11), // "setSpeedMin"
QT_MOC_LITERAL(56, 813, 11), // "setSpeedMax"
QT_MOC_LITERAL(57, 825, 13), // "setHomeOffset"
QT_MOC_LITERAL(58, 839, 17), // "setRequestedHomed"
QT_MOC_LITERAL(59, 857, 17), // "setRequestedSpeed"
QT_MOC_LITERAL(60, 875, 24), // "setRequestedAcceleration"
QT_MOC_LITERAL(61, 900, 20), // "setRequestedPosition"
QT_MOC_LITERAL(62, 921, 15), // "setReplyPending"
QT_MOC_LITERAL(63, 937, 8), // "setError"
QT_MOC_LITERAL(64, 946, 8), // "setHomed"
QT_MOC_LITERAL(65, 955, 15), // "setCurrentSpeed"
QT_MOC_LITERAL(66, 971, 22), // "setCurrentAcceleration"
QT_MOC_LITERAL(67, 994, 18), // "setCurrentPosition"
QT_MOC_LITERAL(68, 1013, 1), // "X"
QT_MOC_LITERAL(69, 1015, 1), // "Y"
QT_MOC_LITERAL(70, 1017, 1), // "Z"
QT_MOC_LITERAL(71, 1019, 1), // "A"
QT_MOC_LITERAL(72, 1021, 1), // "B"
QT_MOC_LITERAL(73, 1023, 10), // "AxisStatus"
QT_MOC_LITERAL(74, 1034, 1), // "a"
QT_MOC_LITERAL(75, 1036, 1), // "b"
QT_MOC_LITERAL(76, 1038, 1) // "c"

    },
    "Axis\0portNumberChanged\0\0portNumber\0"
    "deviceNumberChanged\0deviceNumber\0"
    "enabledChanged\0enabled\0connectedChanged\0"
    "connected\0replyPendingChanged\0"
    "replyPending\0axisTitleChanged\0AxisTitle\0"
    "axis\0statusRequest\0errorChanged\0error\0"
    "positionMinChanged\0positionMin\0"
    "positionMaxChanged\0positionMax\0"
    "speedMinChanged\0speedMin\0speedMaxChanged\0"
    "speedMax\0homeOffsetChanged\0homeOffset\0"
    "homedChanged\0homed\0currentSpeedChanged\0"
    "currentSpeed\0currentAccelerationChanged\0"
    "currentAcceleration\0currentPositionChanged\0"
    "currentPosition\0requestedHomedChanged\0"
    "requestedHomed\0requestedSpeedChanged\0"
    "requestedSpeed\0requestedAccelerationChanged\0"
    "requestedAcceleration\0requestedPositionChanged\0"
    "requestedPosition\0updateAxis\0reply\0"
    "setPortNumber\0setDeviceNumber\0setEnabled\0"
    "setConnected\0setAxisTitle\0axisTitle\0"
    "requestStatus\0setPositionMin\0"
    "setPositionMax\0setSpeedMin\0setSpeedMax\0"
    "setHomeOffset\0setRequestedHomed\0"
    "setRequestedSpeed\0setRequestedAcceleration\0"
    "setRequestedPosition\0setReplyPending\0"
    "setError\0setHomed\0setCurrentSpeed\0"
    "setCurrentAcceleration\0setCurrentPosition\0"
    "X\0Y\0Z\0A\0B\0AxisStatus\0a\0b\0c"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Axis[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      43,   14, // methods
      20,  354, // properties
       2,  434, // enums/sets
       0,    0, // constructors
       0,       // flags
      21,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  229,    2, 0x06 /* Public */,
       4,    1,  232,    2, 0x06 /* Public */,
       6,    1,  235,    2, 0x06 /* Public */,
       8,    1,  238,    2, 0x06 /* Public */,
      10,    1,  241,    2, 0x06 /* Public */,
      12,    1,  244,    2, 0x06 /* Public */,
      15,    0,  247,    2, 0x06 /* Public */,
      16,    1,  248,    2, 0x06 /* Public */,
      18,    1,  251,    2, 0x06 /* Public */,
      20,    1,  254,    2, 0x06 /* Public */,
      22,    1,  257,    2, 0x06 /* Public */,
      24,    1,  260,    2, 0x06 /* Public */,
      26,    1,  263,    2, 0x06 /* Public */,
      28,    1,  266,    2, 0x06 /* Public */,
      30,    1,  269,    2, 0x06 /* Public */,
      32,    1,  272,    2, 0x06 /* Public */,
      34,    1,  275,    2, 0x06 /* Public */,
      36,    1,  278,    2, 0x06 /* Public */,
      38,    1,  281,    2, 0x06 /* Public */,
      40,    1,  284,    2, 0x06 /* Public */,
      42,    1,  287,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      44,    1,  290,    2, 0x0a /* Public */,
      46,    1,  293,    2, 0x0a /* Public */,
      47,    1,  296,    2, 0x0a /* Public */,
      48,    1,  299,    2, 0x0a /* Public */,
      49,    1,  302,    2, 0x0a /* Public */,
      50,    1,  305,    2, 0x0a /* Public */,
      52,    0,  308,    2, 0x0a /* Public */,
      53,    1,  309,    2, 0x0a /* Public */,
      54,    1,  312,    2, 0x0a /* Public */,
      55,    1,  315,    2, 0x0a /* Public */,
      56,    1,  318,    2, 0x0a /* Public */,
      57,    1,  321,    2, 0x0a /* Public */,
      58,    1,  324,    2, 0x0a /* Public */,
      59,    1,  327,    2, 0x0a /* Public */,
      60,    1,  330,    2, 0x0a /* Public */,
      61,    1,  333,    2, 0x0a /* Public */,
      62,    1,  336,    2, 0x08 /* Private */,
      63,    1,  339,    2, 0x08 /* Private */,
      64,    1,  342,    2, 0x08 /* Private */,
      65,    1,  345,    2, 0x08 /* Private */,
      66,    1,  348,    2, 0x08 /* Private */,
      67,    1,  351,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::Float,   19,
    QMetaType::Void, QMetaType::Float,   21,
    QMetaType::Void, QMetaType::Float,   23,
    QMetaType::Void, QMetaType::Float,   25,
    QMetaType::Void, QMetaType::Float,   27,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void, QMetaType::Float,   31,
    QMetaType::Void, QMetaType::Float,   33,
    QMetaType::Void, QMetaType::Float,   35,
    QMetaType::Void, QMetaType::Bool,   37,
    QMetaType::Void, QMetaType::Float,   39,
    QMetaType::Void, QMetaType::Float,   41,
    QMetaType::Void, QMetaType::Float,   43,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   45,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, 0x80000000 | 13,   51,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,   19,
    QMetaType::Void, QMetaType::Float,   21,
    QMetaType::Void, QMetaType::Float,   23,
    QMetaType::Void, QMetaType::Float,   25,
    QMetaType::Void, QMetaType::Float,   27,
    QMetaType::Void, QMetaType::Bool,   37,
    QMetaType::Void, QMetaType::Float,   39,
    QMetaType::Void, QMetaType::Float,   41,
    QMetaType::Void, QMetaType::Float,   43,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void, QMetaType::Float,   31,
    QMetaType::Void, QMetaType::Float,   33,
    QMetaType::Void, QMetaType::Float,   35,

 // properties: name, type, flags
       3, QMetaType::Int, 0x00495103,
       5, QMetaType::Int, 0x00495103,
       9, QMetaType::Bool, 0x00495103,
      11, QMetaType::Bool, 0x00495103,
       7, QMetaType::Bool, 0x00495103,
      51, 0x80000000 | 13, 0x0049510b,
      17, QMetaType::QString, 0x00495103,
      19, QMetaType::Float, 0x00495103,
      21, QMetaType::Float, 0x00495103,
      23, QMetaType::Float, 0x00495103,
      25, QMetaType::Float, 0x00495103,
      27, QMetaType::Float, 0x00495103,
      29, QMetaType::Bool, 0x00495103,
      31, QMetaType::Float, 0x00495103,
      33, QMetaType::Float, 0x00495103,
      35, QMetaType::Float, 0x00495103,
      37, QMetaType::Bool, 0x00495103,
      39, QMetaType::Bool, 0x00495103,
      41, QMetaType::Bool, 0x00495103,
      43, QMetaType::Float, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       3,
       4,
       2,
       5,
       7,
       8,
       9,
      10,
      11,
      12,
      13,
      14,
      15,
      16,
      17,
      18,
      19,
      20,

 // enums: name, flags, count, data
      13, 0x0,    5,  442,
      73, 0x0,    3,  452,

 // enum data: key, value
      68, uint(Axis::X),
      69, uint(Axis::Y),
      70, uint(Axis::Z),
      71, uint(Axis::A),
      72, uint(Axis::B),
      74, uint(Axis::a),
      75, uint(Axis::b),
      76, uint(Axis::c),

       0        // eod
};

void Axis::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Axis *_t = static_cast<Axis *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->portNumberChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->deviceNumberChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->enabledChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->connectedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->replyPendingChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->axisTitleChanged((*reinterpret_cast< AxisTitle(*)>(_a[1]))); break;
        case 6: _t->statusRequest(); break;
        case 7: _t->errorChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->positionMinChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 9: _t->positionMaxChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 10: _t->speedMinChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 11: _t->speedMaxChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 12: _t->homeOffsetChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 13: _t->homedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->currentSpeedChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 15: _t->currentAccelerationChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 16: _t->currentPositionChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 17: _t->requestedHomedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->requestedSpeedChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 19: _t->requestedAccelerationChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 20: _t->requestedPositionChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 21: _t->updateAxis((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->setPortNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->setDeviceNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->setEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->setConnected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->setAxisTitle((*reinterpret_cast< const AxisTitle(*)>(_a[1]))); break;
        case 27: _t->requestStatus(); break;
        case 28: _t->setPositionMin((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 29: _t->setPositionMax((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 30: _t->setSpeedMin((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 31: _t->setSpeedMax((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 32: _t->setHomeOffset((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 33: _t->setRequestedHomed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->setRequestedSpeed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 35: _t->setRequestedAcceleration((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 36: _t->setRequestedPosition((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 37: _t->setReplyPending((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->setError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 39: _t->setHomed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 40: _t->setCurrentSpeed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 41: _t->setCurrentAcceleration((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 42: _t->setCurrentPosition((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Axis::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::portNumberChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Axis::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::deviceNumberChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Axis::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::enabledChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Axis::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::connectedChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Axis::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::replyPendingChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Axis::*)(AxisTitle );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::axisTitleChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Axis::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::statusRequest)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Axis::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::errorChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Axis::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::positionMinChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Axis::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::positionMaxChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Axis::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::speedMinChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Axis::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::speedMaxChanged)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Axis::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::homeOffsetChanged)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Axis::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::homedChanged)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (Axis::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::currentSpeedChanged)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (Axis::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::currentAccelerationChanged)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (Axis::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::currentPositionChanged)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (Axis::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::requestedHomedChanged)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (Axis::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::requestedSpeedChanged)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (Axis::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::requestedAccelerationChanged)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (Axis::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Axis::requestedPositionChanged)) {
                *result = 20;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Axis *_t = static_cast<Axis *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getPortNumber(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getDeviceNumber(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->isConnected(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->isReplyPending(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->isEnabled(); break;
        case 5: *reinterpret_cast< AxisTitle*>(_v) = _t->getAxisTitle(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->getError(); break;
        case 7: *reinterpret_cast< float*>(_v) = _t->getPositionMin(); break;
        case 8: *reinterpret_cast< float*>(_v) = _t->getPositionMax(); break;
        case 9: *reinterpret_cast< float*>(_v) = _t->getSpeedMin(); break;
        case 10: *reinterpret_cast< float*>(_v) = _t->getSpeedMax(); break;
        case 11: *reinterpret_cast< float*>(_v) = _t->getHomeOffset(); break;
        case 12: *reinterpret_cast< bool*>(_v) = _t->isHomed(); break;
        case 13: *reinterpret_cast< float*>(_v) = _t->getCurrentSpeed(); break;
        case 14: *reinterpret_cast< float*>(_v) = _t->getCurrentAcceleration(); break;
        case 15: *reinterpret_cast< float*>(_v) = _t->getCurrentPosition(); break;
        case 16: *reinterpret_cast< bool*>(_v) = _t->getRequestedHomed(); break;
        case 17: *reinterpret_cast< bool*>(_v) = _t->getRequestedSpeed(); break;
        case 18: *reinterpret_cast< bool*>(_v) = _t->getRequestedAcceleration(); break;
        case 19: *reinterpret_cast< float*>(_v) = _t->getRequestedPosition(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Axis *_t = static_cast<Axis *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPortNumber(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setDeviceNumber(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setConnected(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setReplyPending(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setEnabled(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->setAxisTitle(*reinterpret_cast< AxisTitle*>(_v)); break;
        case 6: _t->setError(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->setPositionMin(*reinterpret_cast< float*>(_v)); break;
        case 8: _t->setPositionMax(*reinterpret_cast< float*>(_v)); break;
        case 9: _t->setSpeedMin(*reinterpret_cast< float*>(_v)); break;
        case 10: _t->setSpeedMax(*reinterpret_cast< float*>(_v)); break;
        case 11: _t->setHomeOffset(*reinterpret_cast< float*>(_v)); break;
        case 12: _t->setHomed(*reinterpret_cast< bool*>(_v)); break;
        case 13: _t->setCurrentSpeed(*reinterpret_cast< float*>(_v)); break;
        case 14: _t->setCurrentAcceleration(*reinterpret_cast< float*>(_v)); break;
        case 15: _t->setCurrentPosition(*reinterpret_cast< float*>(_v)); break;
        case 16: _t->setRequestedHomed(*reinterpret_cast< bool*>(_v)); break;
        case 17: _t->setRequestedSpeed(*reinterpret_cast< bool*>(_v)); break;
        case 18: _t->setRequestedAcceleration(*reinterpret_cast< bool*>(_v)); break;
        case 19: _t->setRequestedPosition(*reinterpret_cast< float*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Axis::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Axis.data,
      qt_meta_data_Axis,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Axis::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Axis::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Axis.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Axis::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 43)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 43;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 43)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 43;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 20;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Axis::portNumberChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Axis::deviceNumberChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Axis::enabledChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Axis::connectedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Axis::replyPendingChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Axis::axisTitleChanged(AxisTitle _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Axis::statusRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Axis::errorChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Axis::positionMinChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Axis::positionMaxChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Axis::speedMinChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Axis::speedMaxChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Axis::homeOffsetChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Axis::homedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Axis::currentSpeedChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Axis::currentAccelerationChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Axis::currentPositionChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void Axis::requestedHomedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void Axis::requestedSpeedChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void Axis::requestedAccelerationChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void Axis::requestedPositionChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
