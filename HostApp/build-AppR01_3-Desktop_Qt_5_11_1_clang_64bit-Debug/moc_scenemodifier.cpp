/****************************************************************************
** Meta object code from reading C++ file 'scenemodifier.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AppR01_3/scenemodifier.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scenemodifier.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SceneModifier_t {
    QByteArrayData data[23];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SceneModifier_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SceneModifier_t qt_meta_stringdata_SceneModifier = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SceneModifier"
QT_MOC_LITERAL(1, 14, 14), // "enableBoundBox"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "enabled"
QT_MOC_LITERAL(4, 38, 10), // "enableAxis"
QT_MOC_LITERAL(5, 49, 10), // "addSegment"
QT_MOC_LITERAL(6, 60, 18), // "Qt3DCore::QEntity*"
QT_MOC_LITERAL(7, 79, 7), // "segment"
QT_MOC_LITERAL(8, 87, 10), // "QVector3D&"
QT_MOC_LITERAL(9, 98, 5), // "start"
QT_MOC_LITERAL(10, 104, 3), // "end"
QT_MOC_LITERAL(11, 108, 5), // "width"
QT_MOC_LITERAL(12, 114, 5), // "color"
QT_MOC_LITERAL(13, 120, 6), // "xStart"
QT_MOC_LITERAL(14, 127, 6), // "yStart"
QT_MOC_LITERAL(15, 134, 6), // "zStart"
QT_MOC_LITERAL(16, 141, 4), // "xEnd"
QT_MOC_LITERAL(17, 146, 4), // "yEnd"
QT_MOC_LITERAL(18, 151, 4), // "zEnd"
QT_MOC_LITERAL(19, 156, 12), // "clearSegment"
QT_MOC_LITERAL(20, 169, 13), // "segmentNumber"
QT_MOC_LITERAL(21, 183, 13), // "clearSegments"
QT_MOC_LITERAL(22, 197, 12) // "showSegments"

    },
    "SceneModifier\0enableBoundBox\0\0enabled\0"
    "enableAxis\0addSegment\0Qt3DCore::QEntity*\0"
    "segment\0QVector3D&\0start\0end\0width\0"
    "color\0xStart\0yStart\0zStart\0xEnd\0yEnd\0"
    "zEnd\0clearSegment\0segmentNumber\0"
    "clearSegments\0showSegments"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SceneModifier[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       4,    1,   57,    2, 0x0a /* Public */,
       5,    1,   60,    2, 0x0a /* Public */,
       5,    4,   63,    2, 0x0a /* Public */,
       5,    8,   72,    2, 0x0a /* Public */,
      19,    1,   89,    2, 0x0a /* Public */,
      21,    0,   92,    2, 0x0a /* Public */,
      22,    1,   93,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 8, QMetaType::Float, QMetaType::QColor,    9,   10,   11,   12,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::QColor,   13,   14,   15,   16,   17,   18,   11,   12,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void SceneModifier::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SceneModifier *_t = static_cast<SceneModifier *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->enableBoundBox((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->enableAxis((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->addSegment((*reinterpret_cast< Qt3DCore::QEntity*(*)>(_a[1]))); break;
        case 3: _t->addSegment((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< QVector3D(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< QColor(*)>(_a[4]))); break;
        case 4: _t->addSegment((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6])),(*reinterpret_cast< float(*)>(_a[7])),(*reinterpret_cast< QColor(*)>(_a[8]))); break;
        case 5: _t->clearSegment((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->clearSegments(); break;
        case 7: _t->showSegments((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Qt3DCore::QEntity* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SceneModifier::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SceneModifier.data,
      qt_meta_data_SceneModifier,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SceneModifier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SceneModifier::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SceneModifier.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SceneModifier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
