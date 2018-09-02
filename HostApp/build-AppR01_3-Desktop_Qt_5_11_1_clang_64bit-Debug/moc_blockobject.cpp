/****************************************************************************
** Meta object code from reading C++ file 'blockobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AppR01_3/system_objects/blockobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'blockobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BlockObject_t {
    QByteArrayData data[47];
    char stringdata0[656];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BlockObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BlockObject_t qt_meta_stringdata_BlockObject = {
    {
QT_MOC_LITERAL(0, 0, 11), // "BlockObject"
QT_MOC_LITERAL(1, 12, 11), // "blockNumber"
QT_MOC_LITERAL(2, 24, 8), // "uint32_t"
QT_MOC_LITERAL(3, 33, 11), // "layerNumber"
QT_MOC_LITERAL(4, 45, 9), // "blockTask"
QT_MOC_LITERAL(5, 55, 8), // "uint16_t"
QT_MOC_LITERAL(6, 64, 13), // "laser_enabled"
QT_MOC_LITERAL(7, 78, 11), // "laser_armed"
QT_MOC_LITERAL(8, 90, 11), // "laser_power"
QT_MOC_LITERAL(9, 102, 7), // "uint8_t"
QT_MOC_LITERAL(10, 110, 12), // "positionMode"
QT_MOC_LITERAL(11, 123, 12), // "PositionMode"
QT_MOC_LITERAL(12, 136, 10), // "x_position"
QT_MOC_LITERAL(13, 147, 10), // "y_position"
QT_MOC_LITERAL(14, 158, 8), // "xy_speed"
QT_MOC_LITERAL(15, 167, 10), // "z_position"
QT_MOC_LITERAL(16, 178, 7), // "z_speed"
QT_MOC_LITERAL(17, 186, 15), // "hopper_position"
QT_MOC_LITERAL(18, 202, 12), // "hopper_speed"
QT_MOC_LITERAL(19, 215, 17), // "spreader_position"
QT_MOC_LITERAL(20, 233, 14), // "spreader_speed"
QT_MOC_LITERAL(21, 248, 9), // "dwellTime"
QT_MOC_LITERAL(22, 258, 11), // "g_code_line"
QT_MOC_LITERAL(23, 270, 19), // "laser_galvo_command"
QT_MOC_LITERAL(24, 290, 9), // "z_command"
QT_MOC_LITERAL(25, 300, 14), // "hopper_command"
QT_MOC_LITERAL(26, 315, 16), // "spreader_command"
QT_MOC_LITERAL(27, 332, 9), // "BlockTask"
QT_MOC_LITERAL(28, 342, 11), // "BLOCK_EMPTY"
QT_MOC_LITERAL(29, 354, 19), // "SET_LASER_ARM_STATE"
QT_MOC_LITERAL(30, 374, 22), // "SET_LASER_ENABLE_STATE"
QT_MOC_LITERAL(31, 397, 15), // "SET_LASER_POWER"
QT_MOC_LITERAL(32, 413, 17), // "SET_POSITION_MODE"
QT_MOC_LITERAL(33, 431, 14), // "SET_X_POSITION"
QT_MOC_LITERAL(34, 446, 14), // "SET_Y_POSITION"
QT_MOC_LITERAL(35, 461, 12), // "SET_XY_SPEED"
QT_MOC_LITERAL(36, 474, 14), // "SET_Z_POSITION"
QT_MOC_LITERAL(37, 489, 11), // "SET_Z_SPEED"
QT_MOC_LITERAL(38, 501, 19), // "SET_HOPPER_POSITION"
QT_MOC_LITERAL(39, 521, 16), // "SET_HOPPER_SPEED"
QT_MOC_LITERAL(40, 538, 21), // "SET_SPREADER_POSITION"
QT_MOC_LITERAL(41, 560, 18), // "SET_SPREADER_SPEED"
QT_MOC_LITERAL(42, 579, 13), // "SET_HOME_AXIS"
QT_MOC_LITERAL(43, 593, 14), // "SET_DWELL_TIME"
QT_MOC_LITERAL(44, 608, 11), // "BLOCK_ERROR"
QT_MOC_LITERAL(45, 620, 17), // "Position_Absolute"
QT_MOC_LITERAL(46, 638, 17) // "Position_Relative"

    },
    "BlockObject\0blockNumber\0uint32_t\0"
    "layerNumber\0blockTask\0uint16_t\0"
    "laser_enabled\0laser_armed\0laser_power\0"
    "uint8_t\0positionMode\0PositionMode\0"
    "x_position\0y_position\0xy_speed\0"
    "z_position\0z_speed\0hopper_position\0"
    "hopper_speed\0spreader_position\0"
    "spreader_speed\0dwellTime\0g_code_line\0"
    "laser_galvo_command\0z_command\0"
    "hopper_command\0spreader_command\0"
    "BlockTask\0BLOCK_EMPTY\0SET_LASER_ARM_STATE\0"
    "SET_LASER_ENABLE_STATE\0SET_LASER_POWER\0"
    "SET_POSITION_MODE\0SET_X_POSITION\0"
    "SET_Y_POSITION\0SET_XY_SPEED\0SET_Z_POSITION\0"
    "SET_Z_SPEED\0SET_HOPPER_POSITION\0"
    "SET_HOPPER_SPEED\0SET_SPREADER_POSITION\0"
    "SET_SPREADER_SPEED\0SET_HOME_AXIS\0"
    "SET_DWELL_TIME\0BLOCK_ERROR\0Position_Absolute\0"
    "Position_Relative"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BlockObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      22,   14, // properties
       2,   80, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, 0x80000000 | 2, 0x0009510b,
       3, 0x80000000 | 2, 0x0009510b,
       4, 0x80000000 | 5, 0x0009510b,
       6, QMetaType::Bool, 0x00095103,
       7, QMetaType::Bool, 0x00095103,
       8, 0x80000000 | 9, 0x0009510b,
      10, 0x80000000 | 11, 0x0009510b,
      12, QMetaType::Float, 0x00095103,
      13, QMetaType::Float, 0x00095103,
      14, QMetaType::Float, 0x00095003,
      15, QMetaType::Float, 0x00095103,
      16, QMetaType::Float, 0x00095103,
      17, QMetaType::Float, 0x00095103,
      18, QMetaType::Float, 0x00095103,
      19, QMetaType::Float, 0x00095103,
      20, QMetaType::Float, 0x00095103,
      21, QMetaType::Float, 0x00095103,
      22, QMetaType::QString, 0x00095103,
      23, QMetaType::QString, 0x00095103,
      24, QMetaType::QString, 0x00095103,
      25, QMetaType::QString, 0x00095103,
      26, QMetaType::QString, 0x00095103,

 // enums: name, flags, count, data
      27, 0x0,   17,   88,
      11, 0x0,    2,  122,

 // enum data: key, value
      28, uint(BlockObject::BLOCK_EMPTY),
      29, uint(BlockObject::SET_LASER_ARM_STATE),
      30, uint(BlockObject::SET_LASER_ENABLE_STATE),
      31, uint(BlockObject::SET_LASER_POWER),
      32, uint(BlockObject::SET_POSITION_MODE),
      33, uint(BlockObject::SET_X_POSITION),
      34, uint(BlockObject::SET_Y_POSITION),
      35, uint(BlockObject::SET_XY_SPEED),
      36, uint(BlockObject::SET_Z_POSITION),
      37, uint(BlockObject::SET_Z_SPEED),
      38, uint(BlockObject::SET_HOPPER_POSITION),
      39, uint(BlockObject::SET_HOPPER_SPEED),
      40, uint(BlockObject::SET_SPREADER_POSITION),
      41, uint(BlockObject::SET_SPREADER_SPEED),
      42, uint(BlockObject::SET_HOME_AXIS),
      43, uint(BlockObject::SET_DWELL_TIME),
      44, uint(BlockObject::BLOCK_ERROR),
      45, uint(BlockObject::Position_Absolute),
      46, uint(BlockObject::Position_Relative),

       0        // eod
};

void BlockObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        BlockObject *_t = static_cast<BlockObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< uint32_t*>(_v) = _t->blockNumber(); break;
        case 1: *reinterpret_cast< uint32_t*>(_v) = _t->layerNumber(); break;
        case 2: *reinterpret_cast< uint16_t*>(_v) = _t->blockTask(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->laser_enabled(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->laser_armed(); break;
        case 5: *reinterpret_cast< uint8_t*>(_v) = _t->laser_power(); break;
        case 6: *reinterpret_cast< PositionMode*>(_v) = _t->positionMode(); break;
        case 7: *reinterpret_cast< float*>(_v) = _t->x_position(); break;
        case 8: *reinterpret_cast< float*>(_v) = _t->y_position(); break;
        case 9: *reinterpret_cast< float*>(_v) = _t->xy_speed(); break;
        case 10: *reinterpret_cast< float*>(_v) = _t->z_position(); break;
        case 11: *reinterpret_cast< float*>(_v) = _t->z_speed(); break;
        case 12: *reinterpret_cast< float*>(_v) = _t->hopper_position(); break;
        case 13: *reinterpret_cast< float*>(_v) = _t->hopper_speed(); break;
        case 14: *reinterpret_cast< float*>(_v) = _t->spreader_position(); break;
        case 15: *reinterpret_cast< float*>(_v) = _t->spreader_speed(); break;
        case 16: *reinterpret_cast< float*>(_v) = _t->dwellTime(); break;
        case 17: *reinterpret_cast< QString*>(_v) = _t->g_code_line(); break;
        case 18: *reinterpret_cast< QString*>(_v) = _t->laser_galvo_command(); break;
        case 19: *reinterpret_cast< QString*>(_v) = _t->z_command(); break;
        case 20: *reinterpret_cast< QString*>(_v) = _t->hopper_command(); break;
        case 21: *reinterpret_cast< QString*>(_v) = _t->spreader_command(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        BlockObject *_t = static_cast<BlockObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBlockNumber(*reinterpret_cast< uint32_t*>(_v)); break;
        case 1: _t->setLayerNumber(*reinterpret_cast< uint32_t*>(_v)); break;
        case 2: _t->setBlockTask(*reinterpret_cast< uint16_t*>(_v)); break;
        case 3: _t->setLaser_enabled(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setLaser_armed(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->setLaser_power(*reinterpret_cast< uint8_t*>(_v)); break;
        case 6: _t->setPositionMode(*reinterpret_cast< PositionMode*>(_v)); break;
        case 7: _t->setX_position(*reinterpret_cast< float*>(_v)); break;
        case 8: _t->setY_position(*reinterpret_cast< float*>(_v)); break;
        case 9: _t->setXY_speed(*reinterpret_cast< float*>(_v)); break;
        case 10: _t->setZ_position(*reinterpret_cast< float*>(_v)); break;
        case 11: _t->setZ_speed(*reinterpret_cast< float*>(_v)); break;
        case 12: _t->setHopper_position(*reinterpret_cast< float*>(_v)); break;
        case 13: _t->setHopper_speed(*reinterpret_cast< float*>(_v)); break;
        case 14: _t->setSpreader_position(*reinterpret_cast< float*>(_v)); break;
        case 15: _t->setSpreader_speed(*reinterpret_cast< float*>(_v)); break;
        case 16: _t->setDwellTime(*reinterpret_cast< float*>(_v)); break;
        case 17: _t->setG_code_line(*reinterpret_cast< QString*>(_v)); break;
        case 18: _t->setLaser_galvo_command(*reinterpret_cast< QString*>(_v)); break;
        case 19: _t->setZ_command(*reinterpret_cast< QString*>(_v)); break;
        case 20: _t->setHopper_command(*reinterpret_cast< QString*>(_v)); break;
        case 21: _t->setSpreader_command(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject BlockObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BlockObject.data,
      qt_meta_data_BlockObject,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BlockObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlockObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BlockObject.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BlockObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 22;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 22;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 22;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 22;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 22;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
