/****************************************************************************
** Meta object code from reading C++ file 'settingsobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AppR01_3/system_objects/settingsobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingsobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SettingsObject_t {
    QByteArrayData data[49];
    char stringdata0[872];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingsObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingsObject_t qt_meta_stringdata_SettingsObject = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SettingsObject"
QT_MOC_LITERAL(1, 15, 16), // "settingsFilePath"
QT_MOC_LITERAL(2, 32, 6), // "status"
QT_MOC_LITERAL(3, 39, 14), // "SettingsStatus"
QT_MOC_LITERAL(4, 54, 22), // "laser_galvo_portNumber"
QT_MOC_LITERAL(5, 77, 7), // "uint8_t"
QT_MOC_LITERAL(6, 85, 27), // "materialDelivery_portNumber"
QT_MOC_LITERAL(7, 113, 18), // "laser_deviceNumber"
QT_MOC_LITERAL(8, 132, 18), // "galvo_deviceNumber"
QT_MOC_LITERAL(9, 151, 14), // "z_deviceNumber"
QT_MOC_LITERAL(10, 166, 19), // "hopper_deviceNumber"
QT_MOC_LITERAL(11, 186, 21), // "spreader_deviceNumber"
QT_MOC_LITERAL(12, 208, 16), // "laser_axisNumber"
QT_MOC_LITERAL(13, 225, 12), // "x_axisNumber"
QT_MOC_LITERAL(14, 238, 12), // "y_axisNumber"
QT_MOC_LITERAL(15, 251, 12), // "z_axisNumber"
QT_MOC_LITERAL(16, 264, 17), // "hopper_axisNumber"
QT_MOC_LITERAL(17, 282, 19), // "spreader_axisNumber"
QT_MOC_LITERAL(18, 302, 22), // "laser_power_resolution"
QT_MOC_LITERAL(19, 325, 21), // "x_position_resolution"
QT_MOC_LITERAL(20, 347, 21), // "y_position_resolution"
QT_MOC_LITERAL(21, 369, 21), // "z_position_resolution"
QT_MOC_LITERAL(22, 391, 26), // "hopper_position_resolution"
QT_MOC_LITERAL(23, 418, 28), // "spreader_position_resolution"
QT_MOC_LITERAL(24, 447, 19), // "laser_power_default"
QT_MOC_LITERAL(25, 467, 15), // "laser_power_max"
QT_MOC_LITERAL(26, 483, 15), // "laser_power_min"
QT_MOC_LITERAL(27, 499, 14), // "x_position_max"
QT_MOC_LITERAL(28, 514, 14), // "x_position_min"
QT_MOC_LITERAL(29, 529, 14), // "y_position_max"
QT_MOC_LITERAL(30, 544, 14), // "y_position_min"
QT_MOC_LITERAL(31, 559, 16), // "xy_speed_default"
QT_MOC_LITERAL(32, 576, 12), // "xy_speed_max"
QT_MOC_LITERAL(33, 589, 12), // "xy_speed_min"
QT_MOC_LITERAL(34, 602, 14), // "z_position_max"
QT_MOC_LITERAL(35, 617, 14), // "z_position_min"
QT_MOC_LITERAL(36, 632, 15), // "z_speed_default"
QT_MOC_LITERAL(37, 648, 11), // "z_speed_max"
QT_MOC_LITERAL(38, 660, 11), // "z_speed_min"
QT_MOC_LITERAL(39, 672, 19), // "hopper_position_max"
QT_MOC_LITERAL(40, 692, 19), // "hopper_position_min"
QT_MOC_LITERAL(41, 712, 20), // "hopper_speed_default"
QT_MOC_LITERAL(42, 733, 16), // "hopper_speed_max"
QT_MOC_LITERAL(43, 750, 16), // "hopper_speed_min"
QT_MOC_LITERAL(44, 767, 21), // "spreader_position_max"
QT_MOC_LITERAL(45, 789, 21), // "spreader_position_min"
QT_MOC_LITERAL(46, 811, 22), // "spreader_speed_default"
QT_MOC_LITERAL(47, 834, 18), // "spreader_speed_max"
QT_MOC_LITERAL(48, 853, 18) // "spreader_speed_min"

    },
    "SettingsObject\0settingsFilePath\0status\0"
    "SettingsStatus\0laser_galvo_portNumber\0"
    "uint8_t\0materialDelivery_portNumber\0"
    "laser_deviceNumber\0galvo_deviceNumber\0"
    "z_deviceNumber\0hopper_deviceNumber\0"
    "spreader_deviceNumber\0laser_axisNumber\0"
    "x_axisNumber\0y_axisNumber\0z_axisNumber\0"
    "hopper_axisNumber\0spreader_axisNumber\0"
    "laser_power_resolution\0x_position_resolution\0"
    "y_position_resolution\0z_position_resolution\0"
    "hopper_position_resolution\0"
    "spreader_position_resolution\0"
    "laser_power_default\0laser_power_max\0"
    "laser_power_min\0x_position_max\0"
    "x_position_min\0y_position_max\0"
    "y_position_min\0xy_speed_default\0"
    "xy_speed_max\0xy_speed_min\0z_position_max\0"
    "z_position_min\0z_speed_default\0"
    "z_speed_max\0z_speed_min\0hopper_position_max\0"
    "hopper_position_min\0hopper_speed_default\0"
    "hopper_speed_max\0hopper_speed_min\0"
    "spreader_position_max\0spreader_position_min\0"
    "spreader_speed_default\0spreader_speed_max\0"
    "spreader_speed_min"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingsObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      46,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095103,
       2, 0x80000000 | 3, 0x0009510b,
       4, 0x80000000 | 5, 0x0009510b,
       6, 0x80000000 | 5, 0x0009510b,
       7, 0x80000000 | 5, 0x0009510b,
       8, 0x80000000 | 5, 0x0009510b,
       9, 0x80000000 | 5, 0x0009510b,
      10, 0x80000000 | 5, 0x0009510b,
      11, 0x80000000 | 5, 0x0009510b,
      12, 0x80000000 | 5, 0x0009510b,
      13, 0x80000000 | 5, 0x0009510b,
      14, 0x80000000 | 5, 0x0009510b,
      15, 0x80000000 | 5, 0x0009510b,
      16, 0x80000000 | 5, 0x0009510b,
      17, 0x80000000 | 5, 0x0009510b,
      18, QMetaType::Float, 0x00095103,
      19, QMetaType::Float, 0x00095103,
      20, QMetaType::Float, 0x00095103,
      21, QMetaType::Float, 0x00095103,
      22, QMetaType::Float, 0x00095103,
      23, QMetaType::Float, 0x00095103,
      24, QMetaType::Float, 0x00095103,
      25, QMetaType::Float, 0x00095103,
      26, QMetaType::Float, 0x00095103,
      27, QMetaType::Float, 0x00095103,
      28, QMetaType::Float, 0x00095103,
      29, QMetaType::Float, 0x00095103,
      30, QMetaType::Float, 0x00095103,
      31, QMetaType::Float, 0x00095003,
      32, QMetaType::Float, 0x00095003,
      33, QMetaType::Float, 0x00095003,
      34, QMetaType::Float, 0x00095103,
      35, QMetaType::Float, 0x00095103,
      36, QMetaType::Float, 0x00095103,
      37, QMetaType::Float, 0x00095103,
      38, QMetaType::Float, 0x00095103,
      39, QMetaType::Float, 0x00095103,
      40, QMetaType::Float, 0x00095103,
      41, QMetaType::Float, 0x00095103,
      42, QMetaType::Float, 0x00095103,
      43, QMetaType::Float, 0x00095103,
      44, QMetaType::Float, 0x00095103,
      45, QMetaType::Float, 0x00095103,
      46, QMetaType::Float, 0x00095103,
      47, 0x80000000 | 5, 0x0009510b,
      48, 0x80000000 | 5, 0x0009510b,

       0        // eod
};

void SettingsObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        SettingsObject *_t = static_cast<SettingsObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->settingsFilePath(); break;
        case 1: *reinterpret_cast< SettingsStatus*>(_v) = _t->status(); break;
        case 2: *reinterpret_cast< uint8_t*>(_v) = _t->laser_galvo_portNumber(); break;
        case 3: *reinterpret_cast< uint8_t*>(_v) = _t->materialDelivery_portNumber(); break;
        case 4: *reinterpret_cast< uint8_t*>(_v) = _t->laser_deviceNumber(); break;
        case 5: *reinterpret_cast< uint8_t*>(_v) = _t->galvo_deviceNumber(); break;
        case 6: *reinterpret_cast< uint8_t*>(_v) = _t->z_deviceNumber(); break;
        case 7: *reinterpret_cast< uint8_t*>(_v) = _t->hopper_deviceNumber(); break;
        case 8: *reinterpret_cast< uint8_t*>(_v) = _t->spreader_deviceNumber(); break;
        case 9: *reinterpret_cast< uint8_t*>(_v) = _t->laser_axisNumber(); break;
        case 10: *reinterpret_cast< uint8_t*>(_v) = _t->x_axisNumber(); break;
        case 11: *reinterpret_cast< uint8_t*>(_v) = _t->y_axisNumber(); break;
        case 12: *reinterpret_cast< uint8_t*>(_v) = _t->z_axisNumber(); break;
        case 13: *reinterpret_cast< uint8_t*>(_v) = _t->hopper_axisNumber(); break;
        case 14: *reinterpret_cast< uint8_t*>(_v) = _t->spreader_axisNumber(); break;
        case 15: *reinterpret_cast< float*>(_v) = _t->laser_power_resolution(); break;
        case 16: *reinterpret_cast< float*>(_v) = _t->x_position_resolution(); break;
        case 17: *reinterpret_cast< float*>(_v) = _t->y_position_resolution(); break;
        case 18: *reinterpret_cast< float*>(_v) = _t->z_position_resolution(); break;
        case 19: *reinterpret_cast< float*>(_v) = _t->hopper_position_resolution(); break;
        case 20: *reinterpret_cast< float*>(_v) = _t->spreader_position_resolution(); break;
        case 21: *reinterpret_cast< float*>(_v) = _t->laser_power_default(); break;
        case 22: *reinterpret_cast< float*>(_v) = _t->laser_power_max(); break;
        case 23: *reinterpret_cast< float*>(_v) = _t->laser_power_min(); break;
        case 24: *reinterpret_cast< float*>(_v) = _t->x_position_max(); break;
        case 25: *reinterpret_cast< float*>(_v) = _t->x_position_min(); break;
        case 26: *reinterpret_cast< float*>(_v) = _t->y_position_max(); break;
        case 27: *reinterpret_cast< float*>(_v) = _t->y_position_min(); break;
        case 28: *reinterpret_cast< float*>(_v) = _t->xy_speed_default(); break;
        case 29: *reinterpret_cast< float*>(_v) = _t->xy_speed_max(); break;
        case 30: *reinterpret_cast< float*>(_v) = _t->xy_speed_min(); break;
        case 31: *reinterpret_cast< float*>(_v) = _t->z_position_max(); break;
        case 32: *reinterpret_cast< float*>(_v) = _t->z_position_min(); break;
        case 33: *reinterpret_cast< float*>(_v) = _t->z_speed_default(); break;
        case 34: *reinterpret_cast< float*>(_v) = _t->z_speed_max(); break;
        case 35: *reinterpret_cast< float*>(_v) = _t->z_speed_min(); break;
        case 36: *reinterpret_cast< float*>(_v) = _t->hopper_position_max(); break;
        case 37: *reinterpret_cast< float*>(_v) = _t->hopper_position_min(); break;
        case 38: *reinterpret_cast< float*>(_v) = _t->hopper_speed_default(); break;
        case 39: *reinterpret_cast< float*>(_v) = _t->hopper_speed_max(); break;
        case 40: *reinterpret_cast< float*>(_v) = _t->hopper_speed_min(); break;
        case 41: *reinterpret_cast< float*>(_v) = _t->spreader_position_max(); break;
        case 42: *reinterpret_cast< float*>(_v) = _t->spreader_position_min(); break;
        case 43: *reinterpret_cast< float*>(_v) = _t->spreader_speed_default(); break;
        case 44: *reinterpret_cast< uint8_t*>(_v) = _t->spreader_speed_max(); break;
        case 45: *reinterpret_cast< uint8_t*>(_v) = _t->spreader_speed_min(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        SettingsObject *_t = static_cast<SettingsObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSettingsFilePath(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setStatus(*reinterpret_cast< SettingsStatus*>(_v)); break;
        case 2: _t->setLaser_galvo_portNumber(*reinterpret_cast< uint8_t*>(_v)); break;
        case 3: _t->setMaterialDelivery_portNumber(*reinterpret_cast< uint8_t*>(_v)); break;
        case 4: _t->setLaser_deviceNumber(*reinterpret_cast< uint8_t*>(_v)); break;
        case 5: _t->setGalvo_deviceNumber(*reinterpret_cast< uint8_t*>(_v)); break;
        case 6: _t->setZ_deviceNumber(*reinterpret_cast< uint8_t*>(_v)); break;
        case 7: _t->setHopper_deviceNumber(*reinterpret_cast< uint8_t*>(_v)); break;
        case 8: _t->setSpreader_deviceNumber(*reinterpret_cast< uint8_t*>(_v)); break;
        case 9: _t->setLaser_axisNumber(*reinterpret_cast< uint8_t*>(_v)); break;
        case 10: _t->setX_axisNumber(*reinterpret_cast< uint8_t*>(_v)); break;
        case 11: _t->setY_axisNumber(*reinterpret_cast< uint8_t*>(_v)); break;
        case 12: _t->setZ_axisNumber(*reinterpret_cast< uint8_t*>(_v)); break;
        case 13: _t->setHopper_axisNumber(*reinterpret_cast< uint8_t*>(_v)); break;
        case 14: _t->setSpreader_axisNumber(*reinterpret_cast< uint8_t*>(_v)); break;
        case 15: _t->setLaser_power_resolution(*reinterpret_cast< float*>(_v)); break;
        case 16: _t->setX_position_resolution(*reinterpret_cast< float*>(_v)); break;
        case 17: _t->setY_position_resolution(*reinterpret_cast< float*>(_v)); break;
        case 18: _t->setZ_position_resolution(*reinterpret_cast< float*>(_v)); break;
        case 19: _t->setHopper_position_resolution(*reinterpret_cast< float*>(_v)); break;
        case 20: _t->setSpreader_position_resolution(*reinterpret_cast< float*>(_v)); break;
        case 21: _t->setLaser_power_default(*reinterpret_cast< float*>(_v)); break;
        case 22: _t->setLaser_power_max(*reinterpret_cast< float*>(_v)); break;
        case 23: _t->setLaser_power_min(*reinterpret_cast< float*>(_v)); break;
        case 24: _t->setX_position_max(*reinterpret_cast< float*>(_v)); break;
        case 25: _t->setX_position_min(*reinterpret_cast< float*>(_v)); break;
        case 26: _t->setY_position_max(*reinterpret_cast< float*>(_v)); break;
        case 27: _t->setY_position_min(*reinterpret_cast< float*>(_v)); break;
        case 28: _t->setXY_speed_default(*reinterpret_cast< float*>(_v)); break;
        case 29: _t->setXY_speed_max(*reinterpret_cast< float*>(_v)); break;
        case 30: _t->setXY_speed_min(*reinterpret_cast< float*>(_v)); break;
        case 31: _t->setZ_position_max(*reinterpret_cast< float*>(_v)); break;
        case 32: _t->setZ_position_min(*reinterpret_cast< float*>(_v)); break;
        case 33: _t->setZ_speed_default(*reinterpret_cast< float*>(_v)); break;
        case 34: _t->setZ_speed_max(*reinterpret_cast< float*>(_v)); break;
        case 35: _t->setZ_speed_min(*reinterpret_cast< float*>(_v)); break;
        case 36: _t->setHopper_position_max(*reinterpret_cast< float*>(_v)); break;
        case 37: _t->setHopper_position_min(*reinterpret_cast< float*>(_v)); break;
        case 38: _t->setHopper_speed_default(*reinterpret_cast< float*>(_v)); break;
        case 39: _t->setHopper_speed_max(*reinterpret_cast< float*>(_v)); break;
        case 40: _t->setHopper_speed_min(*reinterpret_cast< float*>(_v)); break;
        case 41: _t->setSpreader_position_max(*reinterpret_cast< float*>(_v)); break;
        case 42: _t->setSpreader_position_min(*reinterpret_cast< float*>(_v)); break;
        case 43: _t->setSpreader_speed_default(*reinterpret_cast< float*>(_v)); break;
        case 44: _t->setSpreader_speed_max(*reinterpret_cast< uint8_t*>(_v)); break;
        case 45: _t->setSpreader_speed_min(*reinterpret_cast< uint8_t*>(_v)); break;
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

QT_INIT_METAOBJECT const QMetaObject SettingsObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SettingsObject.data,
      qt_meta_data_SettingsObject,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SettingsObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingsObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsObject.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SettingsObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 46;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 46;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 46;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 46;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 46;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
