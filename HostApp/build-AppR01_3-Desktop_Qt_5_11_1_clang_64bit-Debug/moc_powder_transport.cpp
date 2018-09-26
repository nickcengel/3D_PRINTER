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
    QByteArrayData data[132];
    char stringdata0[2560];
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
QT_MOC_LITERAL(8, 102, 14), // "zSpeed_changed"
QT_MOC_LITERAL(9, 117, 17), // "hPosition_changed"
QT_MOC_LITERAL(10, 135, 14), // "hSpeed_changed"
QT_MOC_LITERAL(11, 150, 17), // "sPosition_changed"
QT_MOC_LITERAL(12, 168, 14), // "sSpeed_changed"
QT_MOC_LITERAL(13, 183, 22), // "laserIntensity_changed"
QT_MOC_LITERAL(14, 206, 9), // "intensity"
QT_MOC_LITERAL(15, 216, 24), // "laserEnableState_changed"
QT_MOC_LITERAL(16, 241, 10), // "laserState"
QT_MOC_LITERAL(17, 252, 21), // "laserArmState_changed"
QT_MOC_LITERAL(18, 274, 5), // "armed"
QT_MOC_LITERAL(19, 280, 26), // "currentBlockNumber_changed"
QT_MOC_LITERAL(20, 307, 8), // "blockNum"
QT_MOC_LITERAL(21, 316, 26), // "currentLayerNumber_changed"
QT_MOC_LITERAL(22, 343, 11), // "layerNumber"
QT_MOC_LITERAL(23, 355, 9), // "laserBusy"
QT_MOC_LITERAL(24, 365, 14), // "buildPlateBusy"
QT_MOC_LITERAL(25, 380, 9), // "galvoBusy"
QT_MOC_LITERAL(26, 390, 10), // "hopperBusy"
QT_MOC_LITERAL(27, 401, 12), // "spreaderBusy"
QT_MOC_LITERAL(28, 414, 21), // "laser_port_txFinished"
QT_MOC_LITERAL(29, 436, 21), // "laser_port_rxFinished"
QT_MOC_LITERAL(30, 458, 18), // "md_port_txFinished"
QT_MOC_LITERAL(31, 477, 18), // "md_port_rxFinished"
QT_MOC_LITERAL(32, 496, 21), // "galvo_port_txFinished"
QT_MOC_LITERAL(33, 518, 21), // "galvo_port_rxFinished"
QT_MOC_LITERAL(34, 540, 10), // "startPrint"
QT_MOC_LITERAL(35, 551, 9), // "stopPrint"
QT_MOC_LITERAL(36, 561, 13), // "printFinished"
QT_MOC_LITERAL(37, 575, 14), // "tasksRemaining"
QT_MOC_LITERAL(38, 590, 15), // "blocksRemaining"
QT_MOC_LITERAL(39, 606, 13), // "blockComplete"
QT_MOC_LITERAL(40, 620, 11), // "jogComplete"
QT_MOC_LITERAL(41, 632, 20), // "laser_commandPending"
QT_MOC_LITERAL(42, 653, 20), // "galvo_commandPending"
QT_MOC_LITERAL(43, 674, 17), // "md_commandPending"
QT_MOC_LITERAL(44, 692, 28), // "laser_port_connectionChanged"
QT_MOC_LITERAL(45, 721, 4), // "open"
QT_MOC_LITERAL(46, 726, 28), // "galvo_port_connectionChanged"
QT_MOC_LITERAL(47, 755, 25), // "md_port_connectionChanged"
QT_MOC_LITERAL(48, 781, 11), // "resetDaemon"
QT_MOC_LITERAL(49, 793, 17), // "laser_deviceReply"
QT_MOC_LITERAL(50, 811, 5), // "reply"
QT_MOC_LITERAL(51, 817, 11), // "laser_error"
QT_MOC_LITERAL(52, 829, 5), // "error"
QT_MOC_LITERAL(53, 835, 22), // "buildPlate_deviceReply"
QT_MOC_LITERAL(54, 858, 18), // "hopper_deviceReply"
QT_MOC_LITERAL(55, 877, 20), // "spreader_deviceReply"
QT_MOC_LITERAL(56, 898, 13), // "md_port_error"
QT_MOC_LITERAL(57, 912, 17), // "galvo_deviceReply"
QT_MOC_LITERAL(58, 930, 11), // "galvo_error"
QT_MOC_LITERAL(59, 942, 15), // "transport_error"
QT_MOC_LITERAL(60, 958, 23), // "on_printManager_enabled"
QT_MOC_LITERAL(61, 982, 7), // "enabled"
QT_MOC_LITERAL(62, 990, 24), // "on_manualControl_enabled"
QT_MOC_LITERAL(63, 1015, 24), // "on_laserPortName_changed"
QT_MOC_LITERAL(64, 1040, 4), // "name"
QT_MOC_LITERAL(65, 1045, 24), // "on_galvoPortName_changed"
QT_MOC_LITERAL(66, 1070, 21), // "on_mdPortName_changed"
QT_MOC_LITERAL(67, 1092, 33), // "on_laser_port_connectionReque..."
QT_MOC_LITERAL(68, 1126, 33), // "on_galvo_port_connectionReque..."
QT_MOC_LITERAL(69, 1160, 30), // "on_md_port_connectionRequested"
QT_MOC_LITERAL(70, 1191, 19), // "on_config_available"
QT_MOC_LITERAL(71, 1211, 30), // "QSharedPointer<PowderSettings>"
QT_MOC_LITERAL(72, 1242, 6), // "config"
QT_MOC_LITERAL(73, 1249, 21), // "on_partFile_available"
QT_MOC_LITERAL(74, 1271, 26), // "QSharedPointer<PowderPart>"
QT_MOC_LITERAL(75, 1298, 4), // "part"
QT_MOC_LITERAL(76, 1303, 21), // "on_startPrint_request"
QT_MOC_LITERAL(77, 1325, 20), // "on_stopPrint_request"
QT_MOC_LITERAL(78, 1346, 16), // "on_reset_request"
QT_MOC_LITERAL(79, 1363, 25), // "on_emergency_stop_request"
QT_MOC_LITERAL(80, 1389, 23), // "on_jogIncrement_changed"
QT_MOC_LITERAL(81, 1413, 12), // "jogIncrement"
QT_MOC_LITERAL(82, 1426, 20), // "on_homeOption_change"
QT_MOC_LITERAL(83, 1447, 10), // "homeOption"
QT_MOC_LITERAL(84, 1458, 15), // "on_home_request"
QT_MOC_LITERAL(85, 1474, 30), // "on_increment_xPosition_request"
QT_MOC_LITERAL(86, 1505, 30), // "on_decrement_xPosition_request"
QT_MOC_LITERAL(87, 1536, 30), // "on_increment_yPosition_request"
QT_MOC_LITERAL(88, 1567, 30), // "on_decrement_yPosition_request"
QT_MOC_LITERAL(89, 1598, 30), // "on_increment_zPosition_request"
QT_MOC_LITERAL(90, 1629, 30), // "on_decrement_zPosition_request"
QT_MOC_LITERAL(91, 1660, 30), // "on_increment_hPosition_request"
QT_MOC_LITERAL(92, 1691, 30), // "on_decrement_hPosition_request"
QT_MOC_LITERAL(93, 1722, 30), // "on_increment_sPosition_request"
QT_MOC_LITERAL(94, 1753, 30), // "on_decrement_sPosition_request"
QT_MOC_LITERAL(95, 1784, 21), // "on_clearError_request"
QT_MOC_LITERAL(96, 1806, 22), // "on_reset_galvo_request"
QT_MOC_LITERAL(97, 1829, 10), // "ping_galvo"
QT_MOC_LITERAL(98, 1840, 21), // "ping_materialDelivery"
QT_MOC_LITERAL(99, 1862, 6), // "devNum"
QT_MOC_LITERAL(100, 1869, 7), // "axisNum"
QT_MOC_LITERAL(101, 1877, 26), // "on_laser_port_bytesWritten"
QT_MOC_LITERAL(102, 1904, 5), // "bytes"
QT_MOC_LITERAL(103, 1910, 23), // "on_laser_port_bytesRead"
QT_MOC_LITERAL(104, 1934, 20), // "on_laser_portTimeout"
QT_MOC_LITERAL(105, 1955, 19), // "on_laser_port_error"
QT_MOC_LITERAL(106, 1975, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(107, 2004, 9), // "portError"
QT_MOC_LITERAL(108, 2014, 26), // "on_galvo_port_bytesWritten"
QT_MOC_LITERAL(109, 2041, 23), // "on_galvo_port_bytesRead"
QT_MOC_LITERAL(110, 2065, 20), // "on_galvo_portTimeout"
QT_MOC_LITERAL(111, 2086, 19), // "on_galvo_port_error"
QT_MOC_LITERAL(112, 2106, 23), // "on_md_port_bytesWritten"
QT_MOC_LITERAL(113, 2130, 20), // "on_md_port_bytesRead"
QT_MOC_LITERAL(114, 2151, 17), // "on_md_portTimeout"
QT_MOC_LITERAL(115, 2169, 16), // "on_md_port_error"
QT_MOC_LITERAL(116, 2186, 11), // "poll_mdPort"
QT_MOC_LITERAL(117, 2198, 20), // "on_printRoutine_init"
QT_MOC_LITERAL(118, 2219, 32), // "on_generateProcessQueueFromBlock"
QT_MOC_LITERAL(119, 2252, 25), // "on_selectProcessFromQueue"
QT_MOC_LITERAL(120, 2278, 20), // "on_send_laserCommand"
QT_MOC_LITERAL(121, 2299, 21), // "on_receive_laserReply"
QT_MOC_LITERAL(122, 2321, 28), // "on_laser_transactionFinished"
QT_MOC_LITERAL(123, 2350, 20), // "on_send_galvoCommand"
QT_MOC_LITERAL(124, 2371, 21), // "on_receive_galvoReply"
QT_MOC_LITERAL(125, 2393, 28), // "on_galvo_transactionFinished"
QT_MOC_LITERAL(126, 2422, 17), // "on_send_mdCommand"
QT_MOC_LITERAL(127, 2440, 18), // "on_receive_mdReply"
QT_MOC_LITERAL(128, 2459, 25), // "on_md_transactionFinished"
QT_MOC_LITERAL(129, 2485, 27), // "on_selectNextBlockToProcess"
QT_MOC_LITERAL(130, 2513, 24), // "on_printRoutine_finished"
QT_MOC_LITERAL(131, 2538, 21) // "on_printRoutine_error"

    },
    "PowderTransport\0xPosition_changed\0\0"
    "position\0yPosition_changed\0xySpeed_changed\0"
    "speed\0zPosition_changed\0zSpeed_changed\0"
    "hPosition_changed\0hSpeed_changed\0"
    "sPosition_changed\0sSpeed_changed\0"
    "laserIntensity_changed\0intensity\0"
    "laserEnableState_changed\0laserState\0"
    "laserArmState_changed\0armed\0"
    "currentBlockNumber_changed\0blockNum\0"
    "currentLayerNumber_changed\0layerNumber\0"
    "laserBusy\0buildPlateBusy\0galvoBusy\0"
    "hopperBusy\0spreaderBusy\0laser_port_txFinished\0"
    "laser_port_rxFinished\0md_port_txFinished\0"
    "md_port_rxFinished\0galvo_port_txFinished\0"
    "galvo_port_rxFinished\0startPrint\0"
    "stopPrint\0printFinished\0tasksRemaining\0"
    "blocksRemaining\0blockComplete\0jogComplete\0"
    "laser_commandPending\0galvo_commandPending\0"
    "md_commandPending\0laser_port_connectionChanged\0"
    "open\0galvo_port_connectionChanged\0"
    "md_port_connectionChanged\0resetDaemon\0"
    "laser_deviceReply\0reply\0laser_error\0"
    "error\0buildPlate_deviceReply\0"
    "hopper_deviceReply\0spreader_deviceReply\0"
    "md_port_error\0galvo_deviceReply\0"
    "galvo_error\0transport_error\0"
    "on_printManager_enabled\0enabled\0"
    "on_manualControl_enabled\0"
    "on_laserPortName_changed\0name\0"
    "on_galvoPortName_changed\0on_mdPortName_changed\0"
    "on_laser_port_connectionRequested\0"
    "on_galvo_port_connectionRequested\0"
    "on_md_port_connectionRequested\0"
    "on_config_available\0QSharedPointer<PowderSettings>\0"
    "config\0on_partFile_available\0"
    "QSharedPointer<PowderPart>\0part\0"
    "on_startPrint_request\0on_stopPrint_request\0"
    "on_reset_request\0on_emergency_stop_request\0"
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
    "on_decrement_sPosition_request\0"
    "on_clearError_request\0on_reset_galvo_request\0"
    "ping_galvo\0ping_materialDelivery\0"
    "devNum\0axisNum\0on_laser_port_bytesWritten\0"
    "bytes\0on_laser_port_bytesRead\0"
    "on_laser_portTimeout\0on_laser_port_error\0"
    "QSerialPort::SerialPortError\0portError\0"
    "on_galvo_port_bytesWritten\0"
    "on_galvo_port_bytesRead\0on_galvo_portTimeout\0"
    "on_galvo_port_error\0on_md_port_bytesWritten\0"
    "on_md_port_bytesRead\0on_md_portTimeout\0"
    "on_md_port_error\0poll_mdPort\0"
    "on_printRoutine_init\0"
    "on_generateProcessQueueFromBlock\0"
    "on_selectProcessFromQueue\0"
    "on_send_laserCommand\0on_receive_laserReply\0"
    "on_laser_transactionFinished\0"
    "on_send_galvoCommand\0on_receive_galvoReply\0"
    "on_galvo_transactionFinished\0"
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
     107,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      48,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  549,    2, 0x06 /* Public */,
       4,    1,  552,    2, 0x06 /* Public */,
       5,    1,  555,    2, 0x06 /* Public */,
       7,    1,  558,    2, 0x06 /* Public */,
       8,    1,  561,    2, 0x06 /* Public */,
       9,    1,  564,    2, 0x06 /* Public */,
      10,    1,  567,    2, 0x06 /* Public */,
      11,    1,  570,    2, 0x06 /* Public */,
      12,    1,  573,    2, 0x06 /* Public */,
      13,    1,  576,    2, 0x06 /* Public */,
      15,    1,  579,    2, 0x06 /* Public */,
      17,    1,  582,    2, 0x06 /* Public */,
      19,    1,  585,    2, 0x06 /* Public */,
      21,    1,  588,    2, 0x06 /* Public */,
      23,    0,  591,    2, 0x06 /* Public */,
      24,    0,  592,    2, 0x06 /* Public */,
      25,    0,  593,    2, 0x06 /* Public */,
      26,    0,  594,    2, 0x06 /* Public */,
      27,    0,  595,    2, 0x06 /* Public */,
      28,    0,  596,    2, 0x06 /* Public */,
      29,    0,  597,    2, 0x06 /* Public */,
      30,    0,  598,    2, 0x06 /* Public */,
      31,    0,  599,    2, 0x06 /* Public */,
      32,    0,  600,    2, 0x06 /* Public */,
      33,    0,  601,    2, 0x06 /* Public */,
      34,    0,  602,    2, 0x06 /* Public */,
      35,    0,  603,    2, 0x06 /* Public */,
      36,    0,  604,    2, 0x06 /* Public */,
      37,    0,  605,    2, 0x06 /* Public */,
      38,    0,  606,    2, 0x06 /* Public */,
      39,    0,  607,    2, 0x06 /* Public */,
      40,    0,  608,    2, 0x06 /* Public */,
      41,    0,  609,    2, 0x06 /* Public */,
      42,    0,  610,    2, 0x06 /* Public */,
      43,    0,  611,    2, 0x06 /* Public */,
      44,    1,  612,    2, 0x06 /* Public */,
      46,    1,  615,    2, 0x06 /* Public */,
      47,    1,  618,    2, 0x06 /* Public */,
      48,    0,  621,    2, 0x06 /* Public */,
      49,    1,  622,    2, 0x06 /* Public */,
      51,    1,  625,    2, 0x06 /* Public */,
      53,    1,  628,    2, 0x06 /* Public */,
      54,    1,  631,    2, 0x06 /* Public */,
      55,    1,  634,    2, 0x06 /* Public */,
      56,    1,  637,    2, 0x06 /* Public */,
      57,    1,  640,    2, 0x06 /* Public */,
      58,    1,  643,    2, 0x06 /* Public */,
      59,    1,  646,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      60,    1,  649,    2, 0x0a /* Public */,
      62,    1,  652,    2, 0x0a /* Public */,
      63,    1,  655,    2, 0x0a /* Public */,
      65,    1,  658,    2, 0x0a /* Public */,
      66,    1,  661,    2, 0x0a /* Public */,
      67,    1,  664,    2, 0x0a /* Public */,
      68,    1,  667,    2, 0x0a /* Public */,
      69,    1,  670,    2, 0x0a /* Public */,
      70,    1,  673,    2, 0x0a /* Public */,
      73,    1,  676,    2, 0x0a /* Public */,
      76,    0,  679,    2, 0x0a /* Public */,
      77,    0,  680,    2, 0x0a /* Public */,
      78,    0,  681,    2, 0x0a /* Public */,
      79,    0,  682,    2, 0x0a /* Public */,
      80,    1,  683,    2, 0x0a /* Public */,
      82,    1,  686,    2, 0x0a /* Public */,
      84,    0,  689,    2, 0x0a /* Public */,
      85,    0,  690,    2, 0x0a /* Public */,
      86,    0,  691,    2, 0x0a /* Public */,
      87,    0,  692,    2, 0x0a /* Public */,
      88,    0,  693,    2, 0x0a /* Public */,
      89,    0,  694,    2, 0x0a /* Public */,
      90,    0,  695,    2, 0x0a /* Public */,
      91,    0,  696,    2, 0x0a /* Public */,
      92,    0,  697,    2, 0x0a /* Public */,
      93,    0,  698,    2, 0x0a /* Public */,
      94,    0,  699,    2, 0x0a /* Public */,
      95,    0,  700,    2, 0x0a /* Public */,
      96,    0,  701,    2, 0x0a /* Public */,
      97,    0,  702,    2, 0x0a /* Public */,
      98,    2,  703,    2, 0x0a /* Public */,
     101,    1,  708,    2, 0x08 /* Private */,
     103,    0,  711,    2, 0x08 /* Private */,
     104,    0,  712,    2, 0x08 /* Private */,
     105,    1,  713,    2, 0x08 /* Private */,
     108,    1,  716,    2, 0x08 /* Private */,
     109,    0,  719,    2, 0x08 /* Private */,
     110,    0,  720,    2, 0x08 /* Private */,
     111,    1,  721,    2, 0x08 /* Private */,
     112,    1,  724,    2, 0x08 /* Private */,
     113,    0,  727,    2, 0x08 /* Private */,
     114,    0,  728,    2, 0x08 /* Private */,
     115,    1,  729,    2, 0x08 /* Private */,
     116,    0,  732,    2, 0x08 /* Private */,
     117,    0,  733,    2, 0x08 /* Private */,
     118,    0,  734,    2, 0x08 /* Private */,
     119,    0,  735,    2, 0x08 /* Private */,
     120,    0,  736,    2, 0x08 /* Private */,
     121,    0,  737,    2, 0x08 /* Private */,
     122,    0,  738,    2, 0x08 /* Private */,
     123,    0,  739,    2, 0x08 /* Private */,
     124,    0,  740,    2, 0x08 /* Private */,
     125,    0,  741,    2, 0x08 /* Private */,
     126,    0,  742,    2, 0x08 /* Private */,
     127,    0,  743,    2, 0x08 /* Private */,
     128,    0,  744,    2, 0x08 /* Private */,
     129,    0,  745,    2, 0x08 /* Private */,
     130,    0,  746,    2, 0x08 /* Private */,
     131,    0,  747,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   22,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   45,
    QMetaType::Void, QMetaType::Bool,   45,
    QMetaType::Void, QMetaType::Bool,   45,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   50,
    QMetaType::Void, QMetaType::QString,   52,
    QMetaType::Void, QMetaType::QString,   50,
    QMetaType::Void, QMetaType::QString,   50,
    QMetaType::Void, QMetaType::QString,   50,
    QMetaType::Void, QMetaType::QString,   52,
    QMetaType::Void, QMetaType::QString,   50,
    QMetaType::Void, QMetaType::QString,   52,
    QMetaType::Void, QMetaType::QString,   52,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   61,
    QMetaType::Void, QMetaType::Bool,   61,
    QMetaType::Void, QMetaType::QString,   64,
    QMetaType::Void, QMetaType::QString,   64,
    QMetaType::Void, QMetaType::QString,   64,
    QMetaType::Void, QMetaType::Bool,   45,
    QMetaType::Void, QMetaType::Bool,   45,
    QMetaType::Void, QMetaType::Bool,   45,
    QMetaType::Void, 0x80000000 | 71,   72,
    QMetaType::Void, 0x80000000 | 74,   75,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   81,
    QMetaType::Void, QMetaType::Int,   83,
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
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   99,  100,
    QMetaType::Void, QMetaType::LongLong,  102,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 106,  107,
    QMetaType::Void, QMetaType::LongLong,  102,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 106,  107,
    QMetaType::Void, QMetaType::LongLong,  102,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 106,  107,
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
        case 4: _t->zSpeed_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->hPosition_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->hSpeed_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->sPosition_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->sSpeed_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->laserIntensity_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->laserEnableState_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->laserArmState_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->currentBlockNumber_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->currentLayerNumber_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->laserBusy(); break;
        case 15: _t->buildPlateBusy(); break;
        case 16: _t->galvoBusy(); break;
        case 17: _t->hopperBusy(); break;
        case 18: _t->spreaderBusy(); break;
        case 19: _t->laser_port_txFinished(); break;
        case 20: _t->laser_port_rxFinished(); break;
        case 21: _t->md_port_txFinished(); break;
        case 22: _t->md_port_rxFinished(); break;
        case 23: _t->galvo_port_txFinished(); break;
        case 24: _t->galvo_port_rxFinished(); break;
        case 25: _t->startPrint(); break;
        case 26: _t->stopPrint(); break;
        case 27: _t->printFinished(); break;
        case 28: _t->tasksRemaining(); break;
        case 29: _t->blocksRemaining(); break;
        case 30: _t->blockComplete(); break;
        case 31: _t->jogComplete(); break;
        case 32: _t->laser_commandPending(); break;
        case 33: _t->galvo_commandPending(); break;
        case 34: _t->md_commandPending(); break;
        case 35: _t->laser_port_connectionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->galvo_port_connectionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 37: _t->md_port_connectionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->resetDaemon(); break;
        case 39: _t->laser_deviceReply((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 40: _t->laser_error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 41: _t->buildPlate_deviceReply((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 42: _t->hopper_deviceReply((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 43: _t->spreader_deviceReply((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 44: _t->md_port_error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 45: _t->galvo_deviceReply((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 46: _t->galvo_error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 47: _t->transport_error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 48: _t->on_printManager_enabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 49: _t->on_manualControl_enabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 50: _t->on_laserPortName_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 51: _t->on_galvoPortName_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 52: _t->on_mdPortName_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 53: _t->on_laser_port_connectionRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 54: _t->on_galvo_port_connectionRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 55: _t->on_md_port_connectionRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 56: _t->on_config_available((*reinterpret_cast< QSharedPointer<PowderSettings>(*)>(_a[1]))); break;
        case 57: _t->on_partFile_available((*reinterpret_cast< QSharedPointer<PowderPart>(*)>(_a[1]))); break;
        case 58: _t->on_startPrint_request(); break;
        case 59: _t->on_stopPrint_request(); break;
        case 60: _t->on_reset_request(); break;
        case 61: _t->on_emergency_stop_request(); break;
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
        case 75: _t->on_clearError_request(); break;
        case 76: _t->on_reset_galvo_request(); break;
        case 77: _t->ping_galvo(); break;
        case 78: _t->ping_materialDelivery((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 79: _t->on_laser_port_bytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 80: _t->on_laser_port_bytesRead(); break;
        case 81: _t->on_laser_portTimeout(); break;
        case 82: _t->on_laser_port_error((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 83: _t->on_galvo_port_bytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 84: _t->on_galvo_port_bytesRead(); break;
        case 85: _t->on_galvo_portTimeout(); break;
        case 86: _t->on_galvo_port_error((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 87: _t->on_md_port_bytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 88: _t->on_md_port_bytesRead(); break;
        case 89: _t->on_md_portTimeout(); break;
        case 90: _t->on_md_port_error((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 91: _t->poll_mdPort(); break;
        case 92: _t->on_printRoutine_init(); break;
        case 93: _t->on_generateProcessQueueFromBlock(); break;
        case 94: _t->on_selectProcessFromQueue(); break;
        case 95: _t->on_send_laserCommand(); break;
        case 96: _t->on_receive_laserReply(); break;
        case 97: _t->on_laser_transactionFinished(); break;
        case 98: _t->on_send_galvoCommand(); break;
        case 99: _t->on_receive_galvoReply(); break;
        case 100: _t->on_galvo_transactionFinished(); break;
        case 101: _t->on_send_mdCommand(); break;
        case 102: _t->on_receive_mdReply(); break;
        case 103: _t->on_md_transactionFinished(); break;
        case 104: _t->on_selectNextBlockToProcess(); break;
        case 105: _t->on_printRoutine_finished(); break;
        case 106: _t->on_printRoutine_error(); break;
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
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::zSpeed_changed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::hPosition_changed)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::hSpeed_changed)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::sPosition_changed)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::sSpeed_changed)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::laserIntensity_changed)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::laserEnableState_changed)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::laserArmState_changed)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::currentBlockNumber_changed)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::currentLayerNumber_changed)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::laserBusy)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::buildPlateBusy)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::galvoBusy)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::hopperBusy)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::spreaderBusy)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::laser_port_txFinished)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::laser_port_rxFinished)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::md_port_txFinished)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::md_port_rxFinished)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::galvo_port_txFinished)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::galvo_port_rxFinished)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::startPrint)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::stopPrint)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::printFinished)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::tasksRemaining)) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::blocksRemaining)) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::blockComplete)) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::jogComplete)) {
                *result = 31;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::laser_commandPending)) {
                *result = 32;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::galvo_commandPending)) {
                *result = 33;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::md_commandPending)) {
                *result = 34;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::laser_port_connectionChanged)) {
                *result = 35;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::galvo_port_connectionChanged)) {
                *result = 36;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::md_port_connectionChanged)) {
                *result = 37;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::resetDaemon)) {
                *result = 38;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::laser_deviceReply)) {
                *result = 39;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::laser_error)) {
                *result = 40;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::buildPlate_deviceReply)) {
                *result = 41;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::hopper_deviceReply)) {
                *result = 42;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::spreader_deviceReply)) {
                *result = 43;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::md_port_error)) {
                *result = 44;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::galvo_deviceReply)) {
                *result = 45;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::galvo_error)) {
                *result = 46;
                return;
            }
        }
        {
            using _t = void (PowderTransport::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowderTransport::transport_error)) {
                *result = 47;
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
        if (_id < 107)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 107;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 107)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 107;
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
void PowderTransport::zSpeed_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PowderTransport::hPosition_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PowderTransport::hSpeed_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PowderTransport::sPosition_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PowderTransport::sSpeed_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void PowderTransport::laserIntensity_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void PowderTransport::laserEnableState_changed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void PowderTransport::laserArmState_changed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void PowderTransport::currentBlockNumber_changed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void PowderTransport::currentLayerNumber_changed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void PowderTransport::laserBusy()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void PowderTransport::buildPlateBusy()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void PowderTransport::galvoBusy()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void PowderTransport::hopperBusy()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void PowderTransport::spreaderBusy()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void PowderTransport::laser_port_txFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void PowderTransport::laser_port_rxFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
}

// SIGNAL 21
void PowderTransport::md_port_txFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void PowderTransport::md_port_rxFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 22, nullptr);
}

// SIGNAL 23
void PowderTransport::galvo_port_txFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 23, nullptr);
}

// SIGNAL 24
void PowderTransport::galvo_port_rxFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void PowderTransport::startPrint()
{
    QMetaObject::activate(this, &staticMetaObject, 25, nullptr);
}

// SIGNAL 26
void PowderTransport::stopPrint()
{
    QMetaObject::activate(this, &staticMetaObject, 26, nullptr);
}

// SIGNAL 27
void PowderTransport::printFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 27, nullptr);
}

// SIGNAL 28
void PowderTransport::tasksRemaining()
{
    QMetaObject::activate(this, &staticMetaObject, 28, nullptr);
}

// SIGNAL 29
void PowderTransport::blocksRemaining()
{
    QMetaObject::activate(this, &staticMetaObject, 29, nullptr);
}

// SIGNAL 30
void PowderTransport::blockComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 30, nullptr);
}

// SIGNAL 31
void PowderTransport::jogComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 31, nullptr);
}

// SIGNAL 32
void PowderTransport::laser_commandPending()
{
    QMetaObject::activate(this, &staticMetaObject, 32, nullptr);
}

// SIGNAL 33
void PowderTransport::galvo_commandPending()
{
    QMetaObject::activate(this, &staticMetaObject, 33, nullptr);
}

// SIGNAL 34
void PowderTransport::md_commandPending()
{
    QMetaObject::activate(this, &staticMetaObject, 34, nullptr);
}

// SIGNAL 35
void PowderTransport::laser_port_connectionChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 35, _a);
}

// SIGNAL 36
void PowderTransport::galvo_port_connectionChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 36, _a);
}

// SIGNAL 37
void PowderTransport::md_port_connectionChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 37, _a);
}

// SIGNAL 38
void PowderTransport::resetDaemon()
{
    QMetaObject::activate(this, &staticMetaObject, 38, nullptr);
}

// SIGNAL 39
void PowderTransport::laser_deviceReply(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 39, _a);
}

// SIGNAL 40
void PowderTransport::laser_error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 40, _a);
}

// SIGNAL 41
void PowderTransport::buildPlate_deviceReply(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 41, _a);
}

// SIGNAL 42
void PowderTransport::hopper_deviceReply(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 42, _a);
}

// SIGNAL 43
void PowderTransport::spreader_deviceReply(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 43, _a);
}

// SIGNAL 44
void PowderTransport::md_port_error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 44, _a);
}

// SIGNAL 45
void PowderTransport::galvo_deviceReply(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 45, _a);
}

// SIGNAL 46
void PowderTransport::galvo_error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 46, _a);
}

// SIGNAL 47
void PowderTransport::transport_error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 47, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
