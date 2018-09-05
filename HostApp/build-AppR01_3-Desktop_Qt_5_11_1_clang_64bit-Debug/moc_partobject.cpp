/****************************************************************************
** Meta object code from reading C++ file 'partobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AppR01_4/powder_objects/partobject.h"
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
    QByteArrayData data[23];
    char stringdata0[340];
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
QT_MOC_LITERAL(5, 49, 21), // "QVector<BlockObject*>"
QT_MOC_LITERAL(6, 71, 10), // "partStatus"
QT_MOC_LITERAL(7, 82, 10), // "PartStatus"
QT_MOC_LITERAL(8, 93, 12), // "partFilePath"
QT_MOC_LITERAL(9, 106, 12), // "parserStatus"
QT_MOC_LITERAL(10, 119, 12), // "ParserStatus"
QT_MOC_LITERAL(11, 132, 8), // "errorStr"
QT_MOC_LITERAL(12, 141, 5), // "gcode"
QT_MOC_LITERAL(13, 147, 19), // "laserGalvo_commands"
QT_MOC_LITERAL(14, 167, 25), // "materialDelivery_commands"
QT_MOC_LITERAL(15, 193, 13), // "PART_IS_EMPTY"
QT_MOC_LITERAL(16, 207, 13), // "PART_IS_VALID"
QT_MOC_LITERAL(17, 221, 15), // "PART_IS_INVALID"
QT_MOC_LITERAL(18, 237, 14), // "PARSER_SUCCESS"
QT_MOC_LITERAL(19, 252, 11), // "PARSER_INIT"
QT_MOC_LITERAL(20, 264, 12), // "PARSER_READY"
QT_MOC_LITERAL(21, 277, 35), // "PARSER_FAILED_INVALID_CONFIGU..."
QT_MOC_LITERAL(22, 313, 26) // "PARSER_FAILED_INVALID_PART"

    },
    "PartObject\0blockCount\0uint32_t\0"
    "layerCount\0blocks\0QVector<BlockObject*>\0"
    "partStatus\0PartStatus\0partFilePath\0"
    "parserStatus\0ParserStatus\0errorStr\0"
    "gcode\0laserGalvo_commands\0"
    "materialDelivery_commands\0PART_IS_EMPTY\0"
    "PART_IS_VALID\0PART_IS_INVALID\0"
    "PARSER_SUCCESS\0PARSER_INIT\0PARSER_READY\0"
    "PARSER_FAILED_INVALID_CONFIGURATION\0"
    "PARSER_FAILED_INVALID_PART"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PartObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      10,   14, // properties
       2,   44, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, 0x80000000 | 2, 0x0009510b,
       3, 0x80000000 | 2, 0x0009510b,
       4, 0x80000000 | 5, 0x0009510b,
       6, 0x80000000 | 7, 0x0009510b,
       8, QMetaType::QString, 0x00095103,
       9, 0x80000000 | 10, 0x0009510b,
      11, QMetaType::QString, 0x00095103,
      12, QMetaType::QStringList, 0x00095103,
      13, QMetaType::QStringList, 0x00095103,
      14, QMetaType::QStringList, 0x00095103,

 // enums: name, flags, count, data
       7, 0x0,    3,   52,
      10, 0x0,    5,   58,

 // enum data: key, value
      15, uint(PartObject::PART_IS_EMPTY),
      16, uint(PartObject::PART_IS_VALID),
      17, uint(PartObject::PART_IS_INVALID),
      18, uint(PartObject::PARSER_SUCCESS),
      19, uint(PartObject::PARSER_INIT),
      20, uint(PartObject::PARSER_READY),
      21, uint(PartObject::PARSER_FAILED_INVALID_CONFIGURATION),
      22, uint(PartObject::PARSER_FAILED_INVALID_PART),

       0        // eod
};

void PartObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<BlockObject*> >(); break;
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
        case 2: *reinterpret_cast< QVector<BlockObject*>*>(_v) = _t->blocks(); break;
        case 3: *reinterpret_cast< PartStatus*>(_v) = _t->partStatus(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->partFilePath(); break;
        case 5: *reinterpret_cast< ParserStatus*>(_v) = _t->parserStatus(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->errorStr(); break;
        case 7: *reinterpret_cast< QStringList*>(_v) = _t->gcode(); break;
        case 8: *reinterpret_cast< QStringList*>(_v) = _t->laserGalvo_commands(); break;
        case 9: *reinterpret_cast< QStringList*>(_v) = _t->materialDelivery_commands(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        PartObject *_t = static_cast<PartObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBlockCount(*reinterpret_cast< uint32_t*>(_v)); break;
        case 1: _t->setLayerCount(*reinterpret_cast< uint32_t*>(_v)); break;
        case 2: _t->setBlocks(*reinterpret_cast< QVector<BlockObject*>*>(_v)); break;
        case 3: _t->setPartStatus(*reinterpret_cast< PartStatus*>(_v)); break;
        case 4: _t->setPartFilePath(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setParserStatus(*reinterpret_cast< ParserStatus*>(_v)); break;
        case 6: _t->setErrorStr(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->setGcode(*reinterpret_cast< QStringList*>(_v)); break;
        case 8: _t->setLaserGalvo_commands(*reinterpret_cast< QStringList*>(_v)); break;
        case 9: _t->setMaterialDelivery_commands(*reinterpret_cast< QStringList*>(_v)); break;
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
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
