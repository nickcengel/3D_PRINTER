/****************************************************************************
** Meta object code from reading C++ file 'powderdaemon.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AppR01_4/powder_app/powderdaemon.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSharedPointer>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'powderdaemon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PowderDaemon_t {
    QByteArrayData data[72];
    char stringdata0[1265];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PowderDaemon_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PowderDaemon_t qt_meta_stringdata_PowderDaemon = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PowderDaemon"
QT_MOC_LITERAL(1, 13, 17), // "xPosition_changed"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 8), // "position"
QT_MOC_LITERAL(4, 41, 17), // "yPosition_changed"
QT_MOC_LITERAL(5, 59, 17), // "zPosition_changed"
QT_MOC_LITERAL(6, 77, 17), // "hPosition_changed"
QT_MOC_LITERAL(7, 95, 17), // "sPosition_changed"
QT_MOC_LITERAL(8, 113, 18), // "laserPower_changed"
QT_MOC_LITERAL(9, 132, 5), // "power"
QT_MOC_LITERAL(10, 138, 24), // "laserEnableState_changed"
QT_MOC_LITERAL(11, 163, 7), // "enabled"
QT_MOC_LITERAL(12, 171, 21), // "laserArmState_changed"
QT_MOC_LITERAL(13, 193, 5), // "armed"
QT_MOC_LITERAL(14, 199, 26), // "currentBlockNumber_changed"
QT_MOC_LITERAL(15, 226, 8), // "blockNum"
QT_MOC_LITERAL(16, 235, 26), // "currentLayerNumber_changed"
QT_MOC_LITERAL(17, 262, 11), // "layerNumber"
QT_MOC_LITERAL(18, 274, 18), // "md_port_txFinished"
QT_MOC_LITERAL(19, 293, 18), // "md_port_rxFinished"
QT_MOC_LITERAL(20, 312, 19), // "md_port_deviceReply"
QT_MOC_LITERAL(21, 332, 5), // "reply"
QT_MOC_LITERAL(22, 338, 13), // "md_port_error"
QT_MOC_LITERAL(23, 352, 5), // "error"
QT_MOC_LITERAL(24, 358, 18), // "lg_port_txFinished"
QT_MOC_LITERAL(25, 377, 18), // "lg_port_rxFinished"
QT_MOC_LITERAL(26, 396, 19), // "lg_port_deviceReply"
QT_MOC_LITERAL(27, 416, 13), // "lg_port_error"
QT_MOC_LITERAL(28, 430, 18), // "printRoutine_error"
QT_MOC_LITERAL(29, 449, 10), // "startPrint"
QT_MOC_LITERAL(30, 460, 9), // "stopPrint"
QT_MOC_LITERAL(31, 470, 13), // "printFinished"
QT_MOC_LITERAL(32, 484, 14), // "tasksRemaining"
QT_MOC_LITERAL(33, 499, 15), // "blocksRemaining"
QT_MOC_LITERAL(34, 515, 13), // "blockComplete"
QT_MOC_LITERAL(35, 529, 17), // "lg_commandPending"
QT_MOC_LITERAL(36, 547, 17), // "md_commandPending"
QT_MOC_LITERAL(37, 565, 17), // "on_lg_port_opened"
QT_MOC_LITERAL(38, 583, 17), // "QSerialPort*const"
QT_MOC_LITERAL(39, 601, 4), // "port"
QT_MOC_LITERAL(40, 606, 17), // "on_md_port_opened"
QT_MOC_LITERAL(41, 624, 19), // "on_config_available"
QT_MOC_LITERAL(42, 644, 30), // "QSharedPointer<SettingsObject>"
QT_MOC_LITERAL(43, 675, 6), // "config"
QT_MOC_LITERAL(44, 682, 21), // "on_partFile_available"
QT_MOC_LITERAL(45, 704, 26), // "QSharedPointer<PartObject>"
QT_MOC_LITERAL(46, 731, 4), // "part"
QT_MOC_LITERAL(47, 736, 21), // "on_startPrint_request"
QT_MOC_LITERAL(48, 758, 20), // "on_stopPrint_request"
QT_MOC_LITERAL(49, 779, 23), // "on_lg_port_bytesWritten"
QT_MOC_LITERAL(50, 803, 5), // "bytes"
QT_MOC_LITERAL(51, 809, 20), // "on_lg_port_bytesRead"
QT_MOC_LITERAL(52, 830, 23), // "on_md_port_bytesWritten"
QT_MOC_LITERAL(53, 854, 20), // "on_md_port_bytesRead"
QT_MOC_LITERAL(54, 875, 17), // "on_lg_portTimeout"
QT_MOC_LITERAL(55, 893, 17), // "on_md_portTimeout"
QT_MOC_LITERAL(56, 911, 16), // "on_lg_port_error"
QT_MOC_LITERAL(57, 928, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(58, 957, 9), // "portError"
QT_MOC_LITERAL(59, 967, 16), // "on_md_port_error"
QT_MOC_LITERAL(60, 984, 20), // "on_printRoutine_init"
QT_MOC_LITERAL(61, 1005, 32), // "on_generateProcessQueueFromBlock"
QT_MOC_LITERAL(62, 1038, 25), // "on_selectProcessFromQueue"
QT_MOC_LITERAL(63, 1064, 17), // "on_send_lgCommand"
QT_MOC_LITERAL(64, 1082, 18), // "on_receive_lgReply"
QT_MOC_LITERAL(65, 1101, 25), // "on_lg_transactionFinished"
QT_MOC_LITERAL(66, 1127, 17), // "on_send_mdCommand"
QT_MOC_LITERAL(67, 1145, 18), // "on_receive_mdReply"
QT_MOC_LITERAL(68, 1164, 25), // "on_md_transactionFinished"
QT_MOC_LITERAL(69, 1190, 27), // "on_selectNextBlockToProcess"
QT_MOC_LITERAL(70, 1218, 24), // "on_printRoutine_finished"
QT_MOC_LITERAL(71, 1243, 21) // "on_printRoutine_error"

    },
    "PowderDaemon\0xPosition_changed\0\0"
    "position\0yPosition_changed\0zPosition_changed\0"
    "hPosition_changed\0sPosition_changed\0"
    "laserPower_changed\0power\0"
    "laserEnableState_changed\0enabled\0"
    "laserArmState_changed\0armed\0"
    "currentBlockNumber_changed\0blockNum\0"
    "currentLayerNumber_changed\0layerNumber\0"
    "md_port_txFinished\0md_port_rxFinished\0"
    "md_port_deviceReply\0reply\0md_port_error\0"
    "error\0lg_port_txFinished\0lg_port_rxFinished\0"
    "lg_port_deviceReply\0lg_port_error\0"
    "printRoutine_error\0startPrint\0stopPrint\0"
    "printFinished\0tasksRemaining\0"
    "blocksRemaining\0blockComplete\0"
    "lg_commandPending\0md_commandPending\0"
    "on_lg_port_opened\0QSerialPort*const\0"
    "port\0on_md_port_opened\0on_config_available\0"
    "QSharedPointer<SettingsObject>\0config\0"
    "on_partFile_available\0QSharedPointer<PartObject>\0"
    "part\0on_startPrint_request\0"
    "on_stopPrint_request\0on_lg_port_bytesWritten\0"
    "bytes\0on_lg_port_bytesRead\0"
    "on_md_port_bytesWritten\0on_md_port_bytesRead\0"
    "on_lg_portTimeout\0on_md_portTimeout\0"
    "on_lg_port_error\0QSerialPort::SerialPortError\0"
    "portError\0on_md_port_error\0"
    "on_printRoutine_init\0"
    "on_generateProcessQueueFromBlock\0"
    "on_selectProcessFromQueue\0on_send_lgCommand\0"
    "on_receive_lgReply\0on_lg_transactionFinished\0"
    "on_send_mdCommand\0on_receive_mdReply\0"
    "on_md_transactionFinished\0"
    "on_selectNextBlockToProcess\0"
    "on_printRoutine_finished\0on_printRoutine_error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PowderDaemon[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      53,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      27,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  279,    2, 0x06 /* Public */,
       4,    1,  282,    2, 0x06 /* Public */,
       5,    1,  285,    2, 0x06 /* Public */,
       6,    1,  288,    2, 0x06 /* Public */,
       7,    1,  291,    2, 0x06 /* Public */,
       8,    1,  294,    2, 0x06 /* Public */,
      10,    1,  297,    2, 0x06 /* Public */,
      12,    1,  300,    2, 0x06 /* Public */,
      14,    1,  303,    2, 0x06 /* Public */,
      16,    1,  306,    2, 0x06 /* Public */,
      18,    0,  309,    2, 0x06 /* Public */,
      19,    0,  310,    2, 0x06 /* Public */,
      20,    1,  311,    2, 0x06 /* Public */,
      22,    1,  314,    2, 0x06 /* Public */,
      24,    0,  317,    2, 0x06 /* Public */,
      25,    0,  318,    2, 0x06 /* Public */,
      26,    1,  319,    2, 0x06 /* Public */,
      27,    1,  322,    2, 0x06 /* Public */,
      28,    1,  325,    2, 0x06 /* Public */,
      29,    0,  328,    2, 0x06 /* Public */,
      30,    0,  329,    2, 0x06 /* Public */,
      31,    0,  330,    2, 0x06 /* Public */,
      32,    0,  331,    2, 0x06 /* Public */,
      33,    0,  332,    2, 0x06 /* Public */,
      34,    0,  333,    2, 0x06 /* Public */,
      35,    0,  334,    2, 0x06 /* Public */,
      36,    0,  335,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      37,    1,  336,    2, 0x0a /* Public */,
      40,    1,  339,    2, 0x0a /* Public */,
      41,    1,  342,    2, 0x0a /* Public */,
      44,    1,  345,    2, 0x0a /* Public */,
      47,    0,  348,    2, 0x0a /* Public */,
      48,    0,  349,    2, 0x0a /* Public */,
      49,    1,  350,    2, 0x0a /* Public */,
      51,    0,  353,    2, 0x0a /* Public */,
      52,    1,  354,    2, 0x0a /* Public */,
      53,    0,  357,    2, 0x0a /* Public */,
      54,    0,  358,    2, 0x0a /* Public */,
      55,    0,  359,    2, 0x0a /* Public */,
      56,    1,  360,    2, 0x0a /* Public */,
      59,    1,  363,    2, 0x0a /* Public */,
      60,    0,  366,    2, 0x0a /* Public */,
      61,    0,  367,    2, 0x0a /* Public */,
      62,    0,  368,    2, 0x0a /* Public */,
      63,    0,  369,    2, 0x0a /* Public */,
      64,    0,  370,    2, 0x0a /* Public */,
      65,    0,  371,    2, 0x0a /* Public */,
      66,    0,  372,    2, 0x0a /* Public */,
      67,    0,  373,    2, 0x0a /* Public */,
      68,    0,  374,    2, 0x0a /* Public */,
      69,    0,  375,    2, 0x0a /* Public */,
      70,    0,  376,    2, 0x0a /* Public */,
      71,    0,  377,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 38,   39,
    QMetaType::Void, 0x80000000 | 38,   39,
    QMetaType::Void, 0x80000000 | 42,   43,
    QMetaType::Void, 0x80000000 | 45,   46,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   50,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   50,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 57,   58,
    QMetaType::Void, 0x80000000 | 57,   58,
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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PowderDaemon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PowderDaemon *_t = static_cast<PowderDaemon *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->xPosition_changed((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 1: _t->yPosition_changed((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 2: _t->zPosition_changed((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 3: _t->hPosition_changed((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 4: _t->sPosition_changed((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 5: _t->laserPower_changed((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 6: _t->laserEnableState_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->laserArmState_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->currentBlockNumber_changed((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 9: _t->currentLayerNumber_changed((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 10: _t->md_port_txFinished(); break;
        case 11: _t->md_port_rxFinished(); break;
        case 12: _t->md_port_deviceReply((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->md_port_error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->lg_port_txFinished(); break;
        case 15: _t->lg_port_rxFinished(); break;
        case 16: _t->lg_port_deviceReply((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->lg_port_error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->printRoutine_error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->startPrint(); break;
        case 20: _t->stopPrint(); break;
        case 21: _t->printFinished(); break;
        case 22: _t->tasksRemaining(); break;
        case 23: _t->blocksRemaining(); break;
        case 24: _t->blockComplete(); break;
        case 25: _t->lg_commandPending(); break;
        case 26: _t->md_commandPending(); break;
        case 27: _t->on_lg_port_opened((*reinterpret_cast< QSerialPort*const(*)>(_a[1]))); break;
        case 28: _t->on_md_port_opened((*reinterpret_cast< QSerialPort*const(*)>(_a[1]))); break;
        case 29: _t->on_config_available((*reinterpret_cast< QSharedPointer<SettingsObject>(*)>(_a[1]))); break;
        case 30: _t->on_partFile_available((*reinterpret_cast< QSharedPointer<PartObject>(*)>(_a[1]))); break;
        case 31: _t->on_startPrint_request(); break;
        case 32: _t->on_stopPrint_request(); break;
        case 33: _t->on_lg_port_bytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 34: _t->on_lg_port_bytesRead(); break;
        case 35: _t->on_md_port_bytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 36: _t->on_md_port_bytesRead(); break;
        case 37: _t->on_lg_portTimeout(); break;
        case 38: _t->on_md_portTimeout(); break;
        case 39: _t->on_lg_port_error((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 40: _t->on_md_port_error((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 41: _t->on_printRoutine_init(); break;
        case 42: _t->on_generateProcessQueueFromBlock(); break;
        case 43: _t->on_selectProcessFromQueue(); break;
        case 44: _t->on_send_lgCommand(); break;
        case 45: _t->on_receive_lgReply(); break;
        case 46: _t->on_lg_transactionFinished(); break;
        case 47: _t->on_send_mdCommand(); break;
        case 48: _t->on_receive_mdReply(); break;
        case 49: _t->on_md_transactionFinished(); break;
        case 50: _t->on_selectNextBlockToProcess(); break;
        case 51: _t->on_printRoutine_finished(); break;
        case 52: _t->on_printRoutine_error(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PowderDaemon::*)(const float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::xPosition_changed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(const float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::yPosition_changed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(const float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::zPosition_changed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(const float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::hPosition_changed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(const float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::sPosition_changed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(const float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::laserPower_changed)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::laserEnableState_changed)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::laserArmState_changed)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::currentBlockNumber_changed)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::currentLayerNumber_changed)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::md_port_txFinished)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::md_port_rxFinished)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::md_port_deviceReply)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::md_port_error)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::lg_port_txFinished)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::lg_port_rxFinished)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::lg_port_deviceReply)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::lg_port_error)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::printRoutine_error)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::startPrint)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::stopPrint)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::printFinished)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::tasksRemaining)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::blocksRemaining)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::blockComplete)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::lg_commandPending)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::md_commandPending)) {
                *result = 26;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PowderDaemon::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PowderDaemon.data,
      qt_meta_data_PowderDaemon,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PowderDaemon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PowderDaemon::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PowderDaemon.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PowderDaemon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 53)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 53;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 53)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 53;
    }
    return _id;
}

// SIGNAL 0
void PowderDaemon::xPosition_changed(const float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PowderDaemon::yPosition_changed(const float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PowderDaemon::zPosition_changed(const float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PowderDaemon::hPosition_changed(const float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PowderDaemon::sPosition_changed(const float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PowderDaemon::laserPower_changed(const float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PowderDaemon::laserEnableState_changed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PowderDaemon::laserArmState_changed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PowderDaemon::currentBlockNumber_changed(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void PowderDaemon::currentLayerNumber_changed(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void PowderDaemon::md_port_txFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void PowderDaemon::md_port_rxFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void PowderDaemon::md_port_deviceReply(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void PowderDaemon::md_port_error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void PowderDaemon::lg_port_txFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void PowderDaemon::lg_port_rxFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void PowderDaemon::lg_port_deviceReply(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void PowderDaemon::lg_port_error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void PowderDaemon::printRoutine_error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void PowderDaemon::startPrint()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void PowderDaemon::stopPrint()
{
    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
}

// SIGNAL 21
void PowderDaemon::printFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void PowderDaemon::tasksRemaining()
{
    QMetaObject::activate(this, &staticMetaObject, 22, nullptr);
}

// SIGNAL 23
void PowderDaemon::blocksRemaining()
{
    QMetaObject::activate(this, &staticMetaObject, 23, nullptr);
}

// SIGNAL 24
void PowderDaemon::blockComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void PowderDaemon::lg_commandPending()
{
    QMetaObject::activate(this, &staticMetaObject, 25, nullptr);
}

// SIGNAL 26
void PowderDaemon::md_commandPending()
{
    QMetaObject::activate(this, &staticMetaObject, 26, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
