/****************************************************************************
** Meta object code from reading C++ file 'partblock.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AppR01_3/partblock.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'partblock.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PartBlock_t {
    QByteArrayData data[16];
    char stringdata0[241];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PartBlock_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PartBlock_t qt_meta_stringdata_PartBlock = {
    {
QT_MOC_LITERAL(0, 0, 9), // "PartBlock"
QT_MOC_LITERAL(1, 10, 9), // "BlockTask"
QT_MOC_LITERAL(2, 20, 19), // "LASER_SET_ARM_STATE"
QT_MOC_LITERAL(3, 40, 22), // "LASER_SET_ENABLE_STATE"
QT_MOC_LITERAL(4, 63, 15), // "LASER_SET_POWER"
QT_MOC_LITERAL(5, 79, 14), // "SET_X_POSITION"
QT_MOC_LITERAL(6, 94, 14), // "SET_Y_POSITION"
QT_MOC_LITERAL(7, 109, 14), // "SET_Z_POSITION"
QT_MOC_LITERAL(8, 124, 14), // "SET_H_POSITION"
QT_MOC_LITERAL(9, 139, 14), // "SET_S_POSITION"
QT_MOC_LITERAL(10, 154, 9), // "SET_SPEED"
QT_MOC_LITERAL(11, 164, 17), // "SET_POSITION_MODE"
QT_MOC_LITERAL(12, 182, 9), // "HOME_AXIS"
QT_MOC_LITERAL(13, 192, 12), // "PositionMode"
QT_MOC_LITERAL(14, 205, 17), // "Position_Absolute"
QT_MOC_LITERAL(15, 223, 17) // "Position_Relative"

    },
    "PartBlock\0BlockTask\0LASER_SET_ARM_STATE\0"
    "LASER_SET_ENABLE_STATE\0LASER_SET_POWER\0"
    "SET_X_POSITION\0SET_Y_POSITION\0"
    "SET_Z_POSITION\0SET_H_POSITION\0"
    "SET_S_POSITION\0SET_SPEED\0SET_POSITION_MODE\0"
    "HOME_AXIS\0PositionMode\0Position_Absolute\0"
    "Position_Relative"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PartBlock[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       2,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,   11,   22,
      13, 0x0,    2,   44,

 // enum data: key, value
       2, uint(PartBlock::LASER_SET_ARM_STATE),
       3, uint(PartBlock::LASER_SET_ENABLE_STATE),
       4, uint(PartBlock::LASER_SET_POWER),
       5, uint(PartBlock::SET_X_POSITION),
       6, uint(PartBlock::SET_Y_POSITION),
       7, uint(PartBlock::SET_Z_POSITION),
       8, uint(PartBlock::SET_H_POSITION),
       9, uint(PartBlock::SET_S_POSITION),
      10, uint(PartBlock::SET_SPEED),
      11, uint(PartBlock::SET_POSITION_MODE),
      12, uint(PartBlock::HOME_AXIS),
      14, uint(PartBlock::Position_Absolute),
      15, uint(PartBlock::Position_Relative),

       0        // eod
};

void PartBlock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject PartBlock::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PartBlock.data,
      qt_meta_data_PartBlock,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PartBlock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PartBlock::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PartBlock.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PartBlock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
