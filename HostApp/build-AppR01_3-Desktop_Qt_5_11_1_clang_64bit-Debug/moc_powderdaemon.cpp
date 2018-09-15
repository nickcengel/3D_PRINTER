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
    QByteArrayData data[98];
    char stringdata0[1875];
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
QT_MOC_LITERAL(5, 59, 15), // "xySpeed_changed"
QT_MOC_LITERAL(6, 75, 5), // "speed"
QT_MOC_LITERAL(7, 81, 17), // "zPosition_changed"
QT_MOC_LITERAL(8, 99, 17), // "hPosition_changed"
QT_MOC_LITERAL(9, 117, 17), // "sPosition_changed"
QT_MOC_LITERAL(10, 135, 18), // "laserPower_changed"
QT_MOC_LITERAL(11, 154, 5), // "power"
QT_MOC_LITERAL(12, 160, 24), // "laserEnableState_changed"
QT_MOC_LITERAL(13, 185, 10), // "laserState"
QT_MOC_LITERAL(14, 196, 21), // "laserArmState_changed"
QT_MOC_LITERAL(15, 218, 5), // "armed"
QT_MOC_LITERAL(16, 224, 26), // "currentBlockNumber_changed"
QT_MOC_LITERAL(17, 251, 8), // "blockNum"
QT_MOC_LITERAL(18, 260, 26), // "currentLayerNumber_changed"
QT_MOC_LITERAL(19, 287, 11), // "layerNumber"
QT_MOC_LITERAL(20, 299, 18), // "md_port_txFinished"
QT_MOC_LITERAL(21, 318, 18), // "md_port_rxFinished"
QT_MOC_LITERAL(22, 337, 19), // "md_port_deviceReply"
QT_MOC_LITERAL(23, 357, 5), // "reply"
QT_MOC_LITERAL(24, 363, 18), // "lg_port_txFinished"
QT_MOC_LITERAL(25, 382, 18), // "lg_port_rxFinished"
QT_MOC_LITERAL(26, 401, 19), // "lg_port_deviceReply"
QT_MOC_LITERAL(27, 421, 13), // "lg_port_error"
QT_MOC_LITERAL(28, 435, 5), // "error"
QT_MOC_LITERAL(29, 441, 13), // "md_port_error"
QT_MOC_LITERAL(30, 455, 18), // "printRoutine_error"
QT_MOC_LITERAL(31, 474, 25), // "lg_port_connectionChanged"
QT_MOC_LITERAL(32, 500, 4), // "open"
QT_MOC_LITERAL(33, 505, 25), // "md_port_connectionChanged"
QT_MOC_LITERAL(34, 531, 10), // "startPrint"
QT_MOC_LITERAL(35, 542, 9), // "stopPrint"
QT_MOC_LITERAL(36, 552, 13), // "printFinished"
QT_MOC_LITERAL(37, 566, 14), // "tasksRemaining"
QT_MOC_LITERAL(38, 581, 15), // "blocksRemaining"
QT_MOC_LITERAL(39, 597, 13), // "blockComplete"
QT_MOC_LITERAL(40, 611, 11), // "jogComplete"
QT_MOC_LITERAL(41, 623, 17), // "lg_commandPending"
QT_MOC_LITERAL(42, 641, 17), // "md_commandPending"
QT_MOC_LITERAL(43, 659, 11), // "resetDaemon"
QT_MOC_LITERAL(44, 671, 23), // "on_printManager_enabled"
QT_MOC_LITERAL(45, 695, 7), // "enabled"
QT_MOC_LITERAL(46, 703, 24), // "on_manualControl_enabled"
QT_MOC_LITERAL(47, 728, 21), // "on_lgPortName_changed"
QT_MOC_LITERAL(48, 750, 4), // "name"
QT_MOC_LITERAL(49, 755, 21), // "on_mdPortName_changed"
QT_MOC_LITERAL(50, 777, 30), // "on_lg_port_connectionRequested"
QT_MOC_LITERAL(51, 808, 30), // "on_md_port_connectionRequested"
QT_MOC_LITERAL(52, 839, 19), // "on_config_available"
QT_MOC_LITERAL(53, 859, 30), // "QSharedPointer<SettingsObject>"
QT_MOC_LITERAL(54, 890, 6), // "config"
QT_MOC_LITERAL(55, 897, 21), // "on_partFile_available"
QT_MOC_LITERAL(56, 919, 26), // "QSharedPointer<PartObject>"
QT_MOC_LITERAL(57, 946, 4), // "part"
QT_MOC_LITERAL(58, 951, 21), // "on_startPrint_request"
QT_MOC_LITERAL(59, 973, 20), // "on_stopPrint_request"
QT_MOC_LITERAL(60, 994, 23), // "on_lg_port_bytesWritten"
QT_MOC_LITERAL(61, 1018, 5), // "bytes"
QT_MOC_LITERAL(62, 1024, 20), // "on_lg_port_bytesRead"
QT_MOC_LITERAL(63, 1045, 23), // "on_md_port_bytesWritten"
QT_MOC_LITERAL(64, 1069, 20), // "on_md_port_bytesRead"
QT_MOC_LITERAL(65, 1090, 17), // "on_lg_portTimeout"
QT_MOC_LITERAL(66, 1108, 17), // "on_md_portTimeout"
QT_MOC_LITERAL(67, 1126, 16), // "on_lg_port_error"
QT_MOC_LITERAL(68, 1143, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(69, 1172, 9), // "portError"
QT_MOC_LITERAL(70, 1182, 16), // "on_md_port_error"
QT_MOC_LITERAL(71, 1199, 20), // "on_printRoutine_init"
QT_MOC_LITERAL(72, 1220, 32), // "on_generateProcessQueueFromBlock"
QT_MOC_LITERAL(73, 1253, 25), // "on_selectProcessFromQueue"
QT_MOC_LITERAL(74, 1279, 17), // "on_send_lgCommand"
QT_MOC_LITERAL(75, 1297, 18), // "on_receive_lgReply"
QT_MOC_LITERAL(76, 1316, 25), // "on_lg_transactionFinished"
QT_MOC_LITERAL(77, 1342, 17), // "on_send_mdCommand"
QT_MOC_LITERAL(78, 1360, 18), // "on_receive_mdReply"
QT_MOC_LITERAL(79, 1379, 25), // "on_md_transactionFinished"
QT_MOC_LITERAL(80, 1405, 27), // "on_selectNextBlockToProcess"
QT_MOC_LITERAL(81, 1433, 24), // "on_printRoutine_finished"
QT_MOC_LITERAL(82, 1458, 21), // "on_printRoutine_error"
QT_MOC_LITERAL(83, 1480, 23), // "on_jogIncrement_changed"
QT_MOC_LITERAL(84, 1504, 12), // "jogIncrement"
QT_MOC_LITERAL(85, 1517, 20), // "on_homeOption_change"
QT_MOC_LITERAL(86, 1538, 10), // "homeOption"
QT_MOC_LITERAL(87, 1549, 15), // "on_home_request"
QT_MOC_LITERAL(88, 1565, 30), // "on_increment_xPosition_request"
QT_MOC_LITERAL(89, 1596, 30), // "on_decrement_xPosition_request"
QT_MOC_LITERAL(90, 1627, 30), // "on_increment_yPosition_request"
QT_MOC_LITERAL(91, 1658, 30), // "on_decrement_yPosition_request"
QT_MOC_LITERAL(92, 1689, 30), // "on_increment_zPosition_request"
QT_MOC_LITERAL(93, 1720, 30), // "on_decrement_zPosition_request"
QT_MOC_LITERAL(94, 1751, 30), // "on_increment_hPosition_request"
QT_MOC_LITERAL(95, 1782, 30), // "on_decrement_hPosition_request"
QT_MOC_LITERAL(96, 1813, 30), // "on_increment_sPosition_request"
QT_MOC_LITERAL(97, 1844, 30) // "on_decrement_sPosition_request"

    },
    "PowderDaemon\0xPosition_changed\0\0"
    "position\0yPosition_changed\0xySpeed_changed\0"
    "speed\0zPosition_changed\0hPosition_changed\0"
    "sPosition_changed\0laserPower_changed\0"
    "power\0laserEnableState_changed\0"
    "laserState\0laserArmState_changed\0armed\0"
    "currentBlockNumber_changed\0blockNum\0"
    "currentLayerNumber_changed\0layerNumber\0"
    "md_port_txFinished\0md_port_rxFinished\0"
    "md_port_deviceReply\0reply\0lg_port_txFinished\0"
    "lg_port_rxFinished\0lg_port_deviceReply\0"
    "lg_port_error\0error\0md_port_error\0"
    "printRoutine_error\0lg_port_connectionChanged\0"
    "open\0md_port_connectionChanged\0"
    "startPrint\0stopPrint\0printFinished\0"
    "tasksRemaining\0blocksRemaining\0"
    "blockComplete\0jogComplete\0lg_commandPending\0"
    "md_commandPending\0resetDaemon\0"
    "on_printManager_enabled\0enabled\0"
    "on_manualControl_enabled\0on_lgPortName_changed\0"
    "name\0on_mdPortName_changed\0"
    "on_lg_port_connectionRequested\0"
    "on_md_port_connectionRequested\0"
    "on_config_available\0QSharedPointer<SettingsObject>\0"
    "config\0on_partFile_available\0"
    "QSharedPointer<PartObject>\0part\0"
    "on_startPrint_request\0on_stopPrint_request\0"
    "on_lg_port_bytesWritten\0bytes\0"
    "on_lg_port_bytesRead\0on_md_port_bytesWritten\0"
    "on_md_port_bytesRead\0on_lg_portTimeout\0"
    "on_md_portTimeout\0on_lg_port_error\0"
    "QSerialPort::SerialPortError\0portError\0"
    "on_md_port_error\0on_printRoutine_init\0"
    "on_generateProcessQueueFromBlock\0"
    "on_selectProcessFromQueue\0on_send_lgCommand\0"
    "on_receive_lgReply\0on_lg_transactionFinished\0"
    "on_send_mdCommand\0on_receive_mdReply\0"
    "on_md_transactionFinished\0"
    "on_selectNextBlockToProcess\0"
    "on_printRoutine_finished\0on_printRoutine_error\0"
    "on_jogIncrement_changed\0jogIncrement\0"
    "on_homeOption_change\0homeOption\0"
    "on_home_request\0on_increment_xPosition_request\0"
    "on_decrement_xPosition_request\0"
    "on_increment_yPosition_request\0"
    "on_decrement_yPosition_request\0"
    "on_increment_zPosition_request\0"
    "on_decrement_zPosition_request\0"
    "on_increment_hPosition_request\0"
    "on_decrement_hPosition_request\0"
    "on_increment_sPosition_request\0"
    "on_decrement_sPosition_request"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PowderDaemon[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      75,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      32,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  389,    2, 0x06 /* Public */,
       4,    1,  392,    2, 0x06 /* Public */,
       5,    1,  395,    2, 0x06 /* Public */,
       7,    1,  398,    2, 0x06 /* Public */,
       8,    1,  401,    2, 0x06 /* Public */,
       9,    1,  404,    2, 0x06 /* Public */,
      10,    1,  407,    2, 0x06 /* Public */,
      12,    1,  410,    2, 0x06 /* Public */,
      14,    1,  413,    2, 0x06 /* Public */,
      16,    1,  416,    2, 0x06 /* Public */,
      18,    1,  419,    2, 0x06 /* Public */,
      20,    0,  422,    2, 0x06 /* Public */,
      21,    0,  423,    2, 0x06 /* Public */,
      22,    1,  424,    2, 0x06 /* Public */,
      24,    0,  427,    2, 0x06 /* Public */,
      25,    0,  428,    2, 0x06 /* Public */,
      26,    1,  429,    2, 0x06 /* Public */,
      27,    1,  432,    2, 0x06 /* Public */,
      29,    1,  435,    2, 0x06 /* Public */,
      30,    1,  438,    2, 0x06 /* Public */,
      31,    1,  441,    2, 0x06 /* Public */,
      33,    1,  444,    2, 0x06 /* Public */,
      34,    0,  447,    2, 0x06 /* Public */,
      35,    0,  448,    2, 0x06 /* Public */,
      36,    0,  449,    2, 0x06 /* Public */,
      37,    0,  450,    2, 0x06 /* Public */,
      38,    0,  451,    2, 0x06 /* Public */,
      39,    0,  452,    2, 0x06 /* Public */,
      40,    0,  453,    2, 0x06 /* Public */,
      41,    0,  454,    2, 0x06 /* Public */,
      42,    0,  455,    2, 0x06 /* Public */,
      43,    0,  456,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      44,    1,  457,    2, 0x0a /* Public */,
      46,    1,  460,    2, 0x0a /* Public */,
      47,    1,  463,    2, 0x0a /* Public */,
      49,    1,  466,    2, 0x0a /* Public */,
      50,    1,  469,    2, 0x0a /* Public */,
      51,    1,  472,    2, 0x0a /* Public */,
      52,    1,  475,    2, 0x0a /* Public */,
      55,    1,  478,    2, 0x0a /* Public */,
      58,    0,  481,    2, 0x0a /* Public */,
      59,    0,  482,    2, 0x0a /* Public */,
      60,    1,  483,    2, 0x0a /* Public */,
      62,    0,  486,    2, 0x0a /* Public */,
      63,    1,  487,    2, 0x0a /* Public */,
      64,    0,  490,    2, 0x0a /* Public */,
      65,    0,  491,    2, 0x0a /* Public */,
      66,    0,  492,    2, 0x0a /* Public */,
      67,    1,  493,    2, 0x0a /* Public */,
      70,    1,  496,    2, 0x0a /* Public */,
      71,    0,  499,    2, 0x0a /* Public */,
      72,    0,  500,    2, 0x0a /* Public */,
      73,    0,  501,    2, 0x0a /* Public */,
      74,    0,  502,    2, 0x0a /* Public */,
      75,    0,  503,    2, 0x0a /* Public */,
      76,    0,  504,    2, 0x0a /* Public */,
      77,    0,  505,    2, 0x0a /* Public */,
      78,    0,  506,    2, 0x0a /* Public */,
      79,    0,  507,    2, 0x0a /* Public */,
      80,    0,  508,    2, 0x0a /* Public */,
      81,    0,  509,    2, 0x0a /* Public */,
      82,    0,  510,    2, 0x0a /* Public */,
      83,    1,  511,    2, 0x0a /* Public */,
      85,    1,  514,    2, 0x0a /* Public */,
      87,    0,  517,    2, 0x0a /* Public */,
      88,    0,  518,    2, 0x0a /* Public */,
      89,    0,  519,    2, 0x0a /* Public */,
      90,    0,  520,    2, 0x0a /* Public */,
      91,    0,  521,    2, 0x0a /* Public */,
      92,    0,  522,    2, 0x0a /* Public */,
      93,    0,  523,    2, 0x0a /* Public */,
      94,    0,  524,    2, 0x0a /* Public */,
      95,    0,  525,    2, 0x0a /* Public */,
      96,    0,  526,    2, 0x0a /* Public */,
      97,    0,  527,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::Bool,   32,
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

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   45,
    QMetaType::Void, QMetaType::Bool,   45,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, 0x80000000 | 53,   54,
    QMetaType::Void, 0x80000000 | 56,   57,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   61,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   61,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 68,   69,
    QMetaType::Void, 0x80000000 | 68,   69,
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
    QMetaType::Void, QMetaType::Double,   84,
    QMetaType::Void, QMetaType::Int,   86,
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
        case 0: _t->xPosition_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->yPosition_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->xySpeed_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->zPosition_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->hPosition_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->sPosition_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->laserPower_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->laserEnableState_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->laserArmState_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->currentBlockNumber_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->currentLayerNumber_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->md_port_txFinished(); break;
        case 12: _t->md_port_rxFinished(); break;
        case 13: _t->md_port_deviceReply((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->lg_port_txFinished(); break;
        case 15: _t->lg_port_rxFinished(); break;
        case 16: _t->lg_port_deviceReply((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->lg_port_error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->md_port_error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->printRoutine_error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->lg_port_connectionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->md_port_connectionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->startPrint(); break;
        case 23: _t->stopPrint(); break;
        case 24: _t->printFinished(); break;
        case 25: _t->tasksRemaining(); break;
        case 26: _t->blocksRemaining(); break;
        case 27: _t->blockComplete(); break;
        case 28: _t->jogComplete(); break;
        case 29: _t->lg_commandPending(); break;
        case 30: _t->md_commandPending(); break;
        case 31: _t->resetDaemon(); break;
        case 32: _t->on_printManager_enabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->on_manualControl_enabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->on_lgPortName_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 35: _t->on_mdPortName_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 36: _t->on_lg_port_connectionRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 37: _t->on_md_port_connectionRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->on_config_available((*reinterpret_cast< QSharedPointer<SettingsObject>(*)>(_a[1]))); break;
        case 39: _t->on_partFile_available((*reinterpret_cast< QSharedPointer<PartObject>(*)>(_a[1]))); break;
        case 40: _t->on_startPrint_request(); break;
        case 41: _t->on_stopPrint_request(); break;
        case 42: _t->on_lg_port_bytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 43: _t->on_lg_port_bytesRead(); break;
        case 44: _t->on_md_port_bytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 45: _t->on_md_port_bytesRead(); break;
        case 46: _t->on_lg_portTimeout(); break;
        case 47: _t->on_md_portTimeout(); break;
        case 48: _t->on_lg_port_error((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 49: _t->on_md_port_error((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 50: _t->on_printRoutine_init(); break;
        case 51: _t->on_generateProcessQueueFromBlock(); break;
        case 52: _t->on_selectProcessFromQueue(); break;
        case 53: _t->on_send_lgCommand(); break;
        case 54: _t->on_receive_lgReply(); break;
        case 55: _t->on_lg_transactionFinished(); break;
        case 56: _t->on_send_mdCommand(); break;
        case 57: _t->on_receive_mdReply(); break;
        case 58: _t->on_md_transactionFinished(); break;
        case 59: _t->on_selectNextBlockToProcess(); break;
        case 60: _t->on_printRoutine_finished(); break;
        case 61: _t->on_printRoutine_error(); break;
        case 62: _t->on_jogIncrement_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 63: _t->on_homeOption_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 64: _t->on_home_request(); break;
        case 65: _t->on_increment_xPosition_request(); break;
        case 66: _t->on_decrement_xPosition_request(); break;
        case 67: _t->on_increment_yPosition_request(); break;
        case 68: _t->on_decrement_yPosition_request(); break;
        case 69: _t->on_increment_zPosition_request(); break;
        case 70: _t->on_decrement_zPosition_request(); break;
        case 71: _t->on_increment_hPosition_request(); break;
        case 72: _t->on_decrement_hPosition_request(); break;
        case 73: _t->on_increment_sPosition_request(); break;
        case 74: _t->on_decrement_sPosition_request(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PowderDaemon::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::xPosition_changed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::yPosition_changed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::xySpeed_changed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::zPosition_changed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::hPosition_changed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::sPosition_changed)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::laserPower_changed)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::laserEnableState_changed)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::laserArmState_changed)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::currentBlockNumber_changed)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::currentLayerNumber_changed)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::md_port_txFinished)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::md_port_rxFinished)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::md_port_deviceReply)) {
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
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::md_port_error)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::printRoutine_error)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::lg_port_connectionChanged)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::md_port_connectionChanged)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::startPrint)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::stopPrint)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::printFinished)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::tasksRemaining)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::blocksRemaining)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::blockComplete)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::jogComplete)) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::lg_commandPending)) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::md_commandPending)) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (PowderDaemon::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderDaemon::resetDaemon)) {
                *result = 31;
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
        if (_id < 75)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 75;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 75)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 75;
    }
    return _id;
}

// SIGNAL 0
void PowderDaemon::xPosition_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PowderDaemon::yPosition_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PowderDaemon::xySpeed_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PowderDaemon::zPosition_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PowderDaemon::hPosition_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PowderDaemon::sPosition_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PowderDaemon::laserPower_changed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PowderDaemon::laserEnableState_changed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PowderDaemon::laserArmState_changed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void PowderDaemon::currentBlockNumber_changed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void PowderDaemon::currentLayerNumber_changed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void PowderDaemon::md_port_txFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void PowderDaemon::md_port_rxFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void PowderDaemon::md_port_deviceReply(const QString & _t1)
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
void PowderDaemon::md_port_error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void PowderDaemon::printRoutine_error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void PowderDaemon::lg_port_connectionChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void PowderDaemon::md_port_connectionChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void PowderDaemon::startPrint()
{
    QMetaObject::activate(this, &staticMetaObject, 22, nullptr);
}

// SIGNAL 23
void PowderDaemon::stopPrint()
{
    QMetaObject::activate(this, &staticMetaObject, 23, nullptr);
}

// SIGNAL 24
void PowderDaemon::printFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void PowderDaemon::tasksRemaining()
{
    QMetaObject::activate(this, &staticMetaObject, 25, nullptr);
}

// SIGNAL 26
void PowderDaemon::blocksRemaining()
{
    QMetaObject::activate(this, &staticMetaObject, 26, nullptr);
}

// SIGNAL 27
void PowderDaemon::blockComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 27, nullptr);
}

// SIGNAL 28
void PowderDaemon::jogComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 28, nullptr);
}

// SIGNAL 29
void PowderDaemon::lg_commandPending()
{
    QMetaObject::activate(this, &staticMetaObject, 29, nullptr);
}

// SIGNAL 30
void PowderDaemon::md_commandPending()
{
    QMetaObject::activate(this, &staticMetaObject, 30, nullptr);
}

// SIGNAL 31
void PowderDaemon::resetDaemon()
{
    QMetaObject::activate(this, &staticMetaObject, 31, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
