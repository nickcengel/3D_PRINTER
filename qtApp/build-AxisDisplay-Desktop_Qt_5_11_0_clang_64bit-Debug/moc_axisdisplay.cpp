/****************************************************************************
** Meta object code from reading C++ file 'axisdisplay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AxisDisplay/axisdisplay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'axisdisplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AxisDisplay_t {
    QByteArrayData data[22];
    char stringdata0[286];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AxisDisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AxisDisplay_t qt_meta_stringdata_AxisDisplay = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AxisDisplay"
QT_MOC_LITERAL(1, 12, 19), // "enableButtonPressed"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 6), // "state_"
QT_MOC_LITERAL(4, 40, 18), // "jogDistanceChanged"
QT_MOC_LITERAL(5, 59, 4), // "dist"
QT_MOC_LITERAL(6, 64, 11), // "incPosition"
QT_MOC_LITERAL(7, 76, 3), // "jog"
QT_MOC_LITERAL(8, 80, 11), // "decPosition"
QT_MOC_LITERAL(9, 92, 6), // "homing"
QT_MOC_LITERAL(10, 99, 8), // "isHoming"
QT_MOC_LITERAL(11, 108, 11), // "setPosition"
QT_MOC_LITERAL(12, 120, 5), // "value"
QT_MOC_LITERAL(13, 126, 12), // "setAxisLabel"
QT_MOC_LITERAL(14, 139, 5), // "axis_"
QT_MOC_LITERAL(15, 145, 10), // "setEnabled"
QT_MOC_LITERAL(16, 156, 5), // "state"
QT_MOC_LITERAL(17, 162, 23), // "on_enableButton_clicked"
QT_MOC_LITERAL(18, 186, 29), // "on_jogSizeInput_returnPressed"
QT_MOC_LITERAL(19, 216, 23), // "on_incPosButton_clicked"
QT_MOC_LITERAL(20, 240, 23), // "on_decPosButton_clicked"
QT_MOC_LITERAL(21, 264, 21) // "on_homeButton_clicked"

    },
    "AxisDisplay\0enableButtonPressed\0\0"
    "state_\0jogDistanceChanged\0dist\0"
    "incPosition\0jog\0decPosition\0homing\0"
    "isHoming\0setPosition\0value\0setAxisLabel\0"
    "axis_\0setEnabled\0state\0on_enableButton_clicked\0"
    "on_jogSizeInput_returnPressed\0"
    "on_incPosButton_clicked\0on_decPosButton_clicked\0"
    "on_homeButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AxisDisplay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       6,    1,   85,    2, 0x06 /* Public */,
       8,    1,   88,    2, 0x06 /* Public */,
       9,    1,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   94,    2, 0x0a /* Public */,
      13,    1,   97,    2, 0x0a /* Public */,
      15,    1,  100,    2, 0x0a /* Public */,
      17,    0,  103,    2, 0x08 /* Private */,
      18,    0,  104,    2, 0x08 /* Private */,
      19,    0,  105,    2, 0x08 /* Private */,
      20,    0,  106,    2, 0x08 /* Private */,
      21,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void, QMetaType::Float,    7,
    QMetaType::Void, QMetaType::Float,    7,
    QMetaType::Void, QMetaType::Bool,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,   12,
    QMetaType::Void, QMetaType::Char,   14,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AxisDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AxisDisplay *_t = static_cast<AxisDisplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->enableButtonPressed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->jogDistanceChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->incPosition((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->decPosition((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->homing((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setPosition((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: _t->setAxisLabel((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 7: _t->setEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_enableButton_clicked(); break;
        case 9: _t->on_jogSizeInput_returnPressed(); break;
        case 10: _t->on_incPosButton_clicked(); break;
        case 11: _t->on_decPosButton_clicked(); break;
        case 12: _t->on_homeButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AxisDisplay::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AxisDisplay::enableButtonPressed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AxisDisplay::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AxisDisplay::jogDistanceChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AxisDisplay::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AxisDisplay::incPosition)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AxisDisplay::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AxisDisplay::decPosition)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (AxisDisplay::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AxisDisplay::homing)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AxisDisplay::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AxisDisplay.data,
      qt_meta_data_AxisDisplay,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AxisDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AxisDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AxisDisplay.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AxisDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void AxisDisplay::enableButtonPressed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AxisDisplay::jogDistanceChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AxisDisplay::incPosition(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AxisDisplay::decPosition(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void AxisDisplay::homing(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
