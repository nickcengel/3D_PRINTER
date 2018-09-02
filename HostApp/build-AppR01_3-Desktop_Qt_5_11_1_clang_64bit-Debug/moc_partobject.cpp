/****************************************************************************
** Meta object code from reading C++ file 'partobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AppR01_3/system_objects/partobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'partobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PartObject_t {
    QByteArrayData data[12];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PartObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PartObject_t qt_meta_stringdata_PartObject = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PartObject"
QT_MOC_LITERAL(1, 11, 10), // "blockCount"
QT_MOC_LITERAL(2, 22, 8), // "uint32_t"
QT_MOC_LITERAL(3, 31, 10), // "layerCount"
QT_MOC_LITERAL(4, 42, 6), // "blocks"
QT_MOC_LITERAL(5, 49, 20), // "QVector<BlockObject>"
QT_MOC_LITERAL(6, 70, 10), // "partStatus"
QT_MOC_LITERAL(7, 81, 10), // "PartStatus"
QT_MOC_LITERAL(8, 92, 12), // "partFilePath"
QT_MOC_LITERAL(9, 105, 13), // "PART_IS_EMPTY"
QT_MOC_LITERAL(10, 119, 13), // "PART_IS_VALID"
QT_MOC_LITERAL(11, 133, 15) // "PART_IS_INVALID"

    },
    "PartObject\0blockCount\0uint32_t\0"
    "layerCount\0blocks\0QVector<BlockObject>\0"
    "partStatus\0PartStatus\0partFilePath\0"
    "PART_IS_EMPTY\0PART_IS_VALID\0PART_IS_INVALID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PartObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       5,   14, // properties
       1,   29, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, 0x80000000 | 2, 0x0009510b,
       3, 0x80000000 | 2, 0x0009510b,
       4, 0x80000000 | 5, 0x0009510b,
       6, 0x80000000 | 7, 0x0009510b,
       8, QMetaType::QString, 0x00095103,

 // enums: name, flags, count, data
       7, 0x0,    3,   33,

 // enum data: key, value
       9, uint(PartObject::PART_IS_EMPTY),
      10, uint(PartObject::PART_IS_VALID),
      11, uint(PartObject::PART_IS_INVALID),

       0        // eod
};

void PartObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<BlockObject> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        PartObject *_t = static_cast<PartObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< uint32_t*>(_v) = _t->blockCount(); break;
        case 1: *reinterpret_cast< uint32_t*>(_v) = _t->layerCount(); break;
        case 2: *reinterpret_cast< QVector<BlockObject>*>(_v) = _t->blocks(); break;
        case 3: *reinterpret_cast< PartStatus*>(_v) = _t->partStatus(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->partFilePath(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        PartObject *_t = static_cast<PartObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBlockCount(*reinterpret_cast< uint32_t*>(_v)); break;
        case 1: _t->setLayerCount(*reinterpret_cast< uint32_t*>(_v)); break;
        case 2: _t->setBlocks(*reinterpret_cast< QVector<BlockObject>*>(_v)); break;
        case 3: _t->setPartStatus(*reinterpret_cast< PartStatus*>(_v)); break;
        case 4: _t->setPartFilePath(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
}

QT_INIT_METAOBJECT const QMetaObject PartObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PartObject.data,
      qt_meta_data_PartObject,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PartObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PartObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PartObject.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PartObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
