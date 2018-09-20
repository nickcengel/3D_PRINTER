/****************************************************************************
** Meta object code from reading C++ file 'powder_transport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Powder_R02_00/powder_app/powder_transport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSharedPointer>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'powder_transport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PowderTransport_t {
    QByteArrayData data[109];
    char stringdata0[2031];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PowderTransport_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PowderTransport_t qt_meta_stringdata_PowderTransport = {
    {
QT_MOC_LITERAL(0, 0, 15), // "PowderTransport"
QT_MOC_LITERAL(1, 16, 17), // "xPosition_changed"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 8), // "position"
QT_MOC_LITERAL(4, 44, 17), // "yPosition_changed"
QT_MOC_LITERAL(5, 62, 15), // "xySpeed_changed"
QT_MOC_LITERAL(6, 78, 5), // "speed"
QT_MOC_LITERAL(7, 84, 17), // "zPosition_changed"
QT_MOC_LITERAL(8, 102, 17), // "hPosition_changed"
QT_MOC_LITERAL(9, 120, 17), // "sPosition_changed"
QT_MOC_LITERAL(10, 138, 18), // "laserPower_changed"
QT_MOC_LITERAL(11, 157, 5), // "power"
QT_MOC_LITERAL(12, 163, 24), // "laserEnableState_changed"
QT_MOC_LITERAL(13, 188, 10), // "laserState"
QT_MOC_LITERAL(14, 199, 21), // "laserArmState_changed"
QT_MOC_LITERAL(15, 221, 5), // "armed"
QT_MOC_LITERAL(16, 227, 26), // "currentBlockNumber_changed"
QT_MOC_LITERAL(17, 254, 8), // "blockNum"
QT_MOC_LITERAL(18, 263, 26), // "currentLayerNumber_changed"
QT_MOC_LITERAL(19, 290, 11), // "layerNumber"
QT_MOC_LITERAL(20, 302, 14), // "buildPlateBusy"
QT_MOC_LITERAL(21, 317, 9), // "galvoBusy"
QT_MOC_LITERAL(22, 327, 10), // "hopperBusy"
QT_MOC_LITERAL(23, 338, 12), // "spreaderBusy"
QT_MOC_LITERAL(24, 351, 18), // "md_port_txFinished"
QT_MOC_LITERAL(25, 370, 18), // "md_port_rxFinished"
QT_MOC_LITERAL(26, 389, 18), // "lg_port_txFinished"
QT_MOC_LITERAL(27, 408, 18), // "lg_port_rxFinished"
QT_MOC_LITERAL(28, 427, 10), // "startPrint"
QT_MOC_LITERAL(29, 438, 9), // "stopPrint"
QT_MOC_LITERAL(30, 448, 13), // "printFinished"
QT_MOC_LITERAL(31, 462, 14), // "tasksRemaining"
QT_MOC_LITERAL(32, 477, 15), // "blocksRemaining"
QT_MOC_LITERAL(33, 493, 13), // "blockComplete"
QT_MOC_LITERAL(34, 507, 11), // "jogComplete"
QT_MOC_LITERAL(35, 519, 17), // "lg_commandPending"
QT_MOC_LITERAL(36, 537, 17), // "md_commandPending"
QT_MOC_LITERAL(37, 555, 25), // "lg_port_connectionChanged"
QT_MOC_LITERAL(38, 581, 4), // "open"
QT_MOC_LITERAL(39, 586, 25), // "md_port_connectionChanged"
QT_MOC_LITERAL(40, 612, 11), // "resetDaemon"
QT_MOC_LITERAL(41, 624, 19), // "md_port_deviceReply"
QT_MOC_LITERAL(42, 644, 5), // "reply"
QT_MOC_LITERAL(43, 650, 19), // "lg_port_deviceReply"
QT_MOC_LITERAL(44, 670, 13), // "lg_port_error"
QT_MOC_LITERAL(45, 684, 5), // "error"
QT_MOC_LITERAL(46, 690, 13), // "md_port_error"
QT_MOC_LITERAL(47, 704, 18), // "printRoutine_error"
QT_MOC_LITERAL(48, 723, 23), // "on_printManager_enabled"
QT_MOC_LITERAL(49, 747, 7), // "enabled"
QT_MOC_LITERAL(50, 755, 24), // "on_manualControl_enabled"
QT_MOC_LITERAL(51, 780, 21), // "on_lgPortName_changed"
QT_MOC_LITERAL(52, 802, 4), // "name"
QT_MOC_LITERAL(53, 807, 21), // "on_mdPortName_changed"
QT_MOC_LITERAL(54, 829, 30), // "on_lg_port_connectionRequested"
QT_MOC_LITERAL(55, 860, 30), // "on_md_port_connectionRequested"
QT_MOC_LITERAL(56, 891, 19), // "on_config_available"
QT_MOC_LITERAL(57, 911, 30), // "QSharedPointer<PowderSettings>"
QT_MOC_LITERAL(58, 942, 6), // "config"
QT_MOC_LITERAL(59, 949, 21), // "on_partFile_available"
QT_MOC_LITERAL(60, 971, 26), // "QSharedPointer<PowderPart>"
QT_MOC_LITERAL(61, 998, 4), // "part"
QT_MOC_LITERAL(62, 1003, 21), // "on_startPrint_request"
QT_MOC_LITERAL(63, 1025, 20), // "on_stopPrint_request"
QT_MOC_LITERAL(64, 1046, 16), // "on_reset_request"
QT_MOC_LITERAL(65, 1063, 23), // "on_jogIncrement_changed"
QT_MOC_LITERAL(66, 1087, 12), // "jogIncrement"
QT_MOC_LITERAL(67, 1100, 20), // "on_homeOption_change"
QT_MOC_LITERAL(68, 1121, 10), // "homeOption"
QT_MOC_LITERAL(69, 1132, 15), // "on_home_request"
QT_MOC_LITERAL(70, 1148, 30), // "on_increment_xPosition_request"
QT_MOC_LITERAL(71, 1179, 30), // "on_decrement_xPosition_request"
QT_MOC_LITERAL(72, 1210, 30), // "on_increment_yPosition_request"
QT_MOC_LITERAL(73, 1241, 30), // "on_decrement_yPosition_request"
QT_MOC_LITERAL(74, 1272, 30), // "on_increment_zPosition_request"
QT_MOC_LITERAL(75, 1303, 30), // "on_decrement_zPosition_request"
QT_MOC_LITERAL(76, 1334, 30), // "on_increment_hPosition_request"
QT_MOC_LITERAL(77, 1365, 30), // "on_decrement_hPosition_request"
QT_MOC_LITERAL(78, 1396, 30), // "on_increment_sPosition_request"
QT_MOC_LITERAL(79, 1427, 30), // "on_decrement_sPosition_request"
QT_MOC_LITERAL(80, 1458, 21), // "on_clearError_request"
QT_MOC_LITERAL(81, 1480, 15), // "ping_laserGalvo"
QT_MOC_LITERAL(82, 1496, 21), // "ping_materialDelivery"
QT_MOC_LITERAL(83, 1518, 6), // "devNum"
QT_MOC_LITERAL(84, 1525, 7), // "axisNum"
QT_MOC_LITERAL(85, 1533, 23), // "on_lg_port_bytesWritten"
QT_MOC_LITERAL(86, 1557, 5), // "bytes"
QT_MOC_LITERAL(87, 1563, 20), // "on_lg_port_bytesRead"
QT_MOC_LITERAL(88, 1584, 17), // "on_lg_portTimeout"
QT_MOC_LITERAL(89, 1602, 16), // "on_lg_port_error"
QT_MOC_LITERAL(90, 1619, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(91, 1648, 9), // "portError"
QT_MOC_LITERAL(92, 1658, 23), // "on_md_port_bytesWritten"
QT_MOC_LITERAL(93, 1682, 20), // "on_md_port_bytesRead"
QT_MOC_LITERAL(94, 1703, 17), // "on_md_portTimeout"
QT_MOC_LITERAL(95, 1721, 16), // "on_md_port_error"
QT_MOC_LITERAL(96, 1738, 11), // "poll_mdPort"
QT_MOC_LITERAL(97, 1750, 20), // "on_printRoutine_init"
QT_MOC_LITERAL(98, 1771, 32), // "on_generateProcessQueueFromBlock"
QT_MOC_LITERAL(99, 1804, 25), // "on_selectProcessFromQueue"
QT_MOC_LITERAL(100, 1830, 17), // "on_send_lgCommand"
QT_MOC_LITERAL(101, 1848, 18), // "on_receive_lgReply"
QT_MOC_LITERAL(102, 1867, 25), // "on_lg_transactionFinished"
QT_MOC_LITERAL(103, 1893, 17), // "on_send_mdCommand"
QT_MOC_LITERAL(104, 1911, 18), // "on_receive_mdReply"
QT_MOC_LITERAL(105, 1930, 25), // "on_md_transactionFinished"
QT_MOC_LITERAL(106, 1956, 27), // "on_selectNextBlockToProcess"
QT_MOC_LITERAL(107, 1984, 24), // "on_printRoutine_finished"
QT_MOC_LITERAL(108, 2009, 21) // "on_printRoutine_error"

    },
    "PowderTransport\0xPosition_changed\0\0"
    "position\0yPosition_changed\0xySpeed_changed\0"
    "speed\0zPosition_changed\0hPosition_changed\0"
    "sPosition_changed\0laserPower_changed\0"
    "power\0laserEnableState_changed\0"
    "laserState\0laserArmState_changed\0armed\0"
    "currentBlockNumber_changed\0blockNum\0"
    "currentLayerNumber_changed\0layerNumber\0"
    "buildPlateBusy\0galvoBusy\0hopperBusy\0"
    "spreaderBusy\0md_port_txFinished\0"
    "md_port_rxFinished\0lg_port_txFinished\0"
    "lg_port_rxFinished\0startPrint\0stopPrint\0"
    "printFinished\0tasksRemaining\0"
    "blocksRemaining\0blockComplete\0jogComplete\0"
    "lg_commandPending\0md_commandPending\0"
    "lg_port_connectionChanged\0open\0"
    "md_port_connectionChanged\0resetDaemon\0"
    "md_port_deviceReply\0reply\0lg_port_deviceReply\0"
    "lg_port_error\0error\0md_port_error\0"
    "printRoutine_error\0on_printManager_enabled\0"
    "enabled\0on_manualControl_enabled\0"
    "on_lgPortName_changed\0name\0"
    "on_mdPortName_changed\0"
    "on_lg_port_connectionRequested\0"
    "on_md_port_connectionRequested\0"
    "on_config_available\0QSharedPointer<PowderSettings>\0"
    "config\0on_partFile_available\0"
    "QSharedPointer<PowderPart>\0part\0"
    "on_startPrint_request\0on_stopPrint_request\0"
    "on_reset_request\0on_jogIncrement_changed\0"
    "jogIncrement\0on_homeOption_change\0"
    "homeOption\0on_home_request\0"
    "on_increment_xPosition_request\0"
    "on_decrement_xPosition_request\0"
    "on_increment_yPosition_request\0"
    "on_decrement_yPosition_request\0"
    "on_increment_zPosition_request\0"
    "on_decrement_zPosition_request\0"
    "on_increment_hPosition_request\0"
    "on_decrement_hPosition_request\0"
    "on_increment_sPosition_request\0"
    "on_decrement_sPosition_request\0"
    "on_clearError_request\0ping_laserGalvo\0"
    "ping_materialDelivery\0devNum\0axisNum\0"
    "on_lg_port_bytesWritten\0bytes\0"
    "on_lg_port_bytesRead\0on_lg_portTimeout\0"
    "on_lg_port_error\0QSerialPort::SerialPortError\0"
    "portError\0on_md_port_bytesWritten\0"
    "on_md_port_bytesRead\0on_md_portTimeout\0"
    "on_md_port_error\0poll_mdPort\0"
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

static const uint qt_meta_data_PowderTransport[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      84,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      36,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  434,    2, 0x06 /* Public */,
       4,    1,  437,    2, 0x06 /* Public */,
       5,    1,  440,    2, 0x06 /* Public */,
       7,    1,  443,    2, 0x06 /* Public */,
       8,    1,  446,    2, 0x06 /* Public */,
       9,    1,  449,    2, 0x06 /* Public */,
      10,    1,  452,    2, 0x06 /* Public */,
      12,    1,  455,    2, 0x06 /* Public */,
      14,    1,  458,    2, 0x06 /* Public */,
      16,    1,  461,    2, 0x06 /* Public */,
      18,    1,  464,    2, 0x06 /* Public */,
      20,    0,  467,    2, 0x06 /* Public */,
      21,    0,  468,    2, 0x06 /* Public */,
      22,    0,  469,    2, 0x06 /* Public */,
      23,    0,  470,    2, 0x06 /* Public */,
      24,    0,  471,    2, 0x06 /* Public */,
      25,    0,  472,    2, 0x06 /* Public */,
      26,    0,  473,    2, 0x06 /* Public */,
      27,    0,  474,    2, 0x06 /* Public */,
      28,    0,  475,    2, 0x06 /* Public */,
      29,    0,  476,    2, 0x06 /* Public */,
      30,    0,  477,    2, 0x06 /* Public */,
      31,    0,  478,    2, 0x06 /* Public */,
      32,    0,  479,    2, 0x06 /* Public */,
      33,    0,  480,    2, 0x06 /* Public */,
      34,    0,  481,    2, 0x06 /* Public */,
      35,    0,  482,    2, 0x06 /* Public */,
      36,    0,  483,    2, 0x06 /* Public */,
      37,    1,  484,    2, 0x06 /* Public */,
      39,    1,  487,    2, 0x06 /* Public */,
      40,    0,  490,    2, 0x06 /* Public */,
      41,    1,  491,    2, 0x06 /* Public */,
      43,    1,  494,    2, 0x06 /* Public */,
      44,    1,  497,    2, 0x06 /* Public */,
      46,    1,  500,    2, 0x06 /* Public */,
      47,    1,  503,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      48,    1,  506,    2, 0x0a /* Public */,
      50,    1,  509,    2, 0x0a /* Public */,
      51,    1,  512,    2, 0x0a /* Public */,
      53,    1,  515,    2, 0x0a /* Public */,
      54,    1,  518,    2, 0x0a /* Public */,
      55,    1,  521,    2, 0x0a /* Public */,
      56,    1,  524,    2, 0x0a /* Public */,
      59,    1,  527,    2, 0x0a /* Public */,
      62,    0,  530,    2, 0x0a /* Public */,
      63,    0,  531,    2, 0x0a /* Public */,
      64,    0,  532,    2, 0x0a /* Public */,
      65,    1,  533,    2, 0x0a /* Public */,
      67,    1,  536,    2, 0x0a /* Public */,
      69,    0,  539,    2, 0x0a /* Public */,
      70,    0,  540,    2, 0x0a /* Public */,
      71,    0,  541,    2, 0x0a /* Public */,
      72,    0,  542,    2, 0x0a /* Public */,
      73,    0,  543,    2, 0x0a /* Public */,
      74,    0,  544,    2, 0x0a /* Public */,
      75,    0,  545,    2, 0x0a /* Public */,
      76,    0,  546,    2, 0x0a /* Public */,
      77,    0,  547,    2, 0x0a /* Public */,
      78,    0,  548,    2, 0x0a /* Public */,
      79,    0,  549,    2, 0x0a /* Public */,
      80,    0,  550,    2, 0x0a /* Public */,
      81,    0,  551,    2, 0x0a /* Public */,
      82,    2,  552,    2, 0x0a /* Public */,
      85,    1,  557,    2, 0x08 /* Private */,
      87,    0,  560,    2, 0x08 /* Private */,
      88,    0,  561,    2, 0x08 /* Private */,
      89,    1,  562,    2, 0x08 /* Private */,
      92,    1,  565,    2, 0x08 /* Private */,
      93,    0,  568,    2, 0x08 /* Private */,
      94,    0,  569,    2, 0x08 /* Private */,
      95,    1,  570,    2, 0x08 /* Private */,
      96,    0,  573,    2, 0x08 /* Private */,
      97,    0,  574,    2, 0x08 /* Private */,
      98,    0,  575,    2, 0x08 /* Private */,
      99,    0,  576,    2, 0x08 /* Private */,
     100,    0,  577,    2, 0x08 /* Private */,
     101,    0,  578,    2, 0x08 /* Private */,
     102,    0,  579,    2, 0x08 /* Private */,
     103,    0,  580,    2, 0x08 /* Private */,
     104,    0,  581,    2, 0x08 /* Private */,
     105,    0,  582,    2, 0x08 /* Private */,
     106,    0,  583,    2, 0x08 /* Private */,
     107,    0,  584,    2, 0x08 /* Private */,
     108,    0,  585,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   38,
    QMetaType::Void, QMetaType::Bool,   38,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   42,
    QMetaType::Void, QMetaType::QString,   42,
    QMetaType::Void, QMetaType::QString,   45,
    QMetaType::Void, QMetaType::QString,   45,
    QMetaType::Void, QMetaType::QString,   45,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   49,
    QMetaType::Void, QMetaType::Bool,   49,
    QMetaType::Void, QMetaType::QString,   52,
    QMetaType::Void, QMetaType::QString,   52,
    QMetaType::Void, QMetaType::Bool,   38,
    QMetaType::Void, QMetaType::Bool,   38,
    QMetaType::Void, 0x80000000 | 57,   58,
    QMetaType::Void, 0x80000000 | 60,   61,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   66,
    QMetaType::Void, QMetaType::Int,   68,
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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   83,   84,
    QMetaType::Void, QMetaType::LongLong,   86,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 90,   91,
    QMetaType::Void, QMetaType::LongLong,   86,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 90,   91,
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
    QMetaType::Void,

       0        // eod
};

void PowderTransport::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PowderTransport *_t = static_cast<PowderTransport *>(_o);
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
        case 11: _t->buildPlateBusy(); break;
        case 12: _t->galvoBusy(); break;
        case 13: _t->hopperBusy(); break;
        case 14: _t->spreaderBusy(); break;
        case 15: _t->md_port_txFinished(); break;
        case 16: _t->md_port_rxFinished(); break;
        case 17: _t->lg_port_txFinished(); break;
        case 18: _t->lg_port_rxFinished(); break;
        case 19: _t->startPrint(); break;
        case 20: _t->stopPrint(); break;
        case 21: _t->printFinished(); break;
        case 22: _t->tasksRemaining(); break;
        case 23: _t->blocksRemaining(); break;
        case 24: _t->blockComplete(); break;
        case 25: _t->jogComplete(); break;
        case 26: _t->lg_commandPending(); break;
        case 27: _t->md_commandPending(); break;
        case 28: _t->lg_port_connectionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->md_port_connectionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->resetDaemon(); break;
        case 31: _t->md_port_deviceReply((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 32: _t->lg_port_deviceReply((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 33: _t->lg_port_error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 34: _t->md_port_error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 35: _t->printRoutine_error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 36: _t->on_printManager_enabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 37: _t->on_manualControl_enabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->on_lgPortName_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 39: _t->on_mdPortName_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 40: _t->on_lg_port_connectionRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 41: _t->on_md_port_connectionRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->on_config_available((*reinterpret_cast< QSharedPointer<PowderSettings>(*)>(_a[1]))); break;
        case 43: _t->on_partFile_available((*reinterpret_cast< QSharedPointer<PowderPart>(*)>(_a[1]))); break;
        case 44: _t->on_startPrint_request(); break;
        case 45: _t->on_stopPrint_request(); break;
        case 46: _t->on_reset_request(); break;
        case 47: _t->on_jogIncrement_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 48: _t->on_homeOption_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 49: _t->on_home_request(); break;
        case 50: _t->on_increment_xPosition_request(); break;
        case 51: _t->on_decrement_xPosition_request(); break;
        case 52: _t->on_increment_yPosition_request(); break;
        case 53: _t->on_decrement_yPosition_request(); break;
        case 54: _t->on_increment_zPosition_request(); break;
        case 55: _t->on_decrement_zPosition_request(); break;
        case 56: _t->on_increment_hPosition_request(); break;
        case 57: _t->on_decrement_hPosition_request(); break;
        case 58: _t->on_increment_sPosition_request(); break;
        case 59: _t->on_decrement_sPosition_request(); break;
        case 60: _t->on_clearError_request(); break;
        case 61: _t->ping_laserGalvo(); break;
        case 62: _t->ping_materialDelivery((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 63: _t->on_lg_port_bytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 64: _t->on_lg_port_bytesRead(); break;
        case 65: _t->on_lg_portTimeout(); break;
        case 66: _t->on_lg_port_error((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 67: _t->on_md_port_bytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 68: _t->on_md_port_bytesRead(); break;
        case 69: _t->on_md_portTimeout(); break;
        case 70: _t->on_md_port_error((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 71: _t->poll_mdPort(); break;
        case 72: _t->on_printRoutine_init(); break;
        case 73: _t->on_generateProcessQueueFromBlock(); break;
        case 74: _t->on_selectProcessFromQueue(); break;
        case 75: _t->on_send_lgCommand(); break;
        case 76: _t->on_receive_lgReply(); break;
        case 77: _t->on_lg_transactionFinished(); break;
        case 78: _t->on_send_mdCommand(); break;
        case 79: _t->on_receive_mdReply(); break;
        case 80: _t->on_md_transactionFinished(); break;
        case 81: _t->on_selectNextBlockToProcess(); break;
        case 82: _t->on_printRoutine_finished(); break;
        case 83: _t->on_printRoutine_error(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PowderTransport::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::xPosition_changed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::yPosition_changed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::xySpeed_changed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::zPosition_changed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::hPosition_changed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::sPosition_changed)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::laserPower_changed)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::laserEnableState_changed)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::laserArmState_changed)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::currentBlockNumber_changed)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::currentLayerNumber_changed)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::buildPlateBusy)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::galvoBusy)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::hopperBusy)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::spreaderBusy)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::md_port_txFinished)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::md_port_rxFinished)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::lg_port_txFinished)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::lg_port_rxFinished)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::startPrint)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::stopPrint)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::printFinished)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::tasksRemaining)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::blocksRemaining)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::blockComplete)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::jogComplete)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::lg_commandPending)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::md_commandPending)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::lg_port_connectionChanged)) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::md_port_connectionChanged)) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::resetDaemon)) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::md_port_deviceReply)) {
                *result = 31;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::lg_port_deviceReply)) {
                *result = 32;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::lg_port_error)) {
                *result = 33;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::md_port_error)) {
                *result = 34;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::printRoutine_error)) {
                *result = 35;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PowderTransport::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PowderTransport.data,
      qt_meta_data_PowderTransport,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PowderTransport::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PowderTransport::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PowderTransport.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PowderTransport::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 84)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 84;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 84)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 84;
    }
    return _id;
}

// SIGNAL 0
void PowderTransport::xPosition_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PowderTransport::yPosition_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PowderTransport::xySpeed_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PowderTransport::zPosition_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PowderTransport::hPosition_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PowderTransport::sPosition_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PowderTransport::laserPower_changed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PowderTransport::laserEnableState_changed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PowderTransport::laserArmState_changed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void PowderTransport::currentBlockNumber_changed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void PowderTransport::currentLayerNumber_changed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void PowderTransport::buildPlateBusy()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void PowderTransport::galvoBusy()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void PowderTransport::hopperBusy()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void PowderTransport::spreaderBusy()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void PowderTransport::md_port_txFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void PowderTransport::md_port_rxFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void PowderTransport::lg_port_txFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void PowderTransport::lg_port_rxFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void PowderTransport::startPrint()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void PowderTransport::stopPrint()
{
    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
}

// SIGNAL 21
void PowderTransport::printFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void PowderTransport::tasksRemaining()
{
    QMetaObject::activate(this, &staticMetaObject, 22, nullptr);
}

// SIGNAL 23
void PowderTransport::blocksRemaining()
{
    QMetaObject::activate(this, &staticMetaObject, 23, nullptr);
}

// SIGNAL 24
void PowderTransport::blockComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void PowderTransport::jogComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 25, nullptr);
}

// SIGNAL 26
void PowderTransport::lg_commandPending()
{
    QMetaObject::activate(this, &staticMetaObject, 26, nullptr);
}

// SIGNAL 27
void PowderTransport::md_commandPending()
{
    QMetaObject::activate(this, &staticMetaObject, 27, nullptr);
}

// SIGNAL 28
void PowderTransport::lg_port_connectionChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void PowderTransport::md_port_connectionChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void PowderTransport::resetDaemon()
{
    QMetaObject::activate(this, &staticMetaObject, 30, nullptr);
}

// SIGNAL 31
void PowderTransport::md_port_deviceReply(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}

// SIGNAL 32
void PowderTransport::lg_port_deviceReply(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 33
void PowderTransport::lg_port_error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 33, _a);
}

// SIGNAL 34
void PowderTransport::md_port_error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 34, _a);
}

// SIGNAL 35
void PowderTransport::printRoutine_error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 35, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
