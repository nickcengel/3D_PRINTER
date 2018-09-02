/****************************************************************************
** Meta object code from reading C++ file 'gcode_parser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AppR01_3/gcode_utility/gcode_parser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gcode_parser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GCode_Parser_t {
    QByteArrayData data[7];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GCode_Parser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GCode_Parser_t qt_meta_stringdata_GCode_Parser = {
    {
QT_MOC_LITERAL(0, 0, 12), // "GCode_Parser"
QT_MOC_LITERAL(1, 13, 12), // "ParserStatus"
QT_MOC_LITERAL(2, 26, 14), // "PARSER_SUCCESS"
QT_MOC_LITERAL(3, 41, 11), // "PARSER_INIT"
QT_MOC_LITERAL(4, 53, 12), // "PARSER_READY"
QT_MOC_LITERAL(5, 66, 35), // "PARSER_FAILED_INVALID_CONFIGU..."
QT_MOC_LITERAL(6, 102, 26) // "PARSER_FAILED_INVALID_PART"

    },
    "GCode_Parser\0ParserStatus\0PARSER_SUCCESS\0"
    "PARSER_INIT\0PARSER_READY\0"
    "PARSER_FAILED_INVALID_CONFIGURATION\0"
    "PARSER_FAILED_INVALID_PART"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GCode_Parser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,    5,   18,

 // enum data: key, value
       2, uint(GCode_Parser::PARSER_SUCCESS),
       3, uint(GCode_Parser::PARSER_INIT),
       4, uint(GCode_Parser::PARSER_READY),
       5, uint(GCode_Parser::PARSER_FAILED_INVALID_CONFIGURATION),
       6, uint(GCode_Parser::PARSER_FAILED_INVALID_PART),

       0        // eod
};

void GCode_Parser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GCode_Parser::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GCode_Parser.data,
      qt_meta_data_GCode_Parser,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GCode_Parser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GCode_Parser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GCode_Parser.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GCode_Parser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
