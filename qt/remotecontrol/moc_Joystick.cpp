/****************************************************************************
** Meta object code from reading C++ file 'Joystick.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Joystick.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Joystick.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Joystick_t {
    QByteArrayData data[13];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Joystick_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Joystick_t qt_meta_stringdata_Joystick = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Joystick"
QT_MOC_LITERAL(1, 9, 9), // "axisEvent"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 4), // "axis"
QT_MOC_LITERAL(4, 25, 5), // "value"
QT_MOC_LITERAL(5, 31, 11), // "buttonPress"
QT_MOC_LITERAL(6, 43, 6), // "button"
QT_MOC_LITERAL(7, 50, 13), // "buttonRelease"
QT_MOC_LITERAL(8, 64, 11), // "setJoystick"
QT_MOC_LITERAL(9, 76, 8), // "jsNumber"
QT_MOC_LITERAL(10, 85, 10), // "timerEvent"
QT_MOC_LITERAL(11, 96, 12), // "QTimerEvent*"
QT_MOC_LITERAL(12, 109, 5) // "event"

    },
    "Joystick\0axisEvent\0\0axis\0value\0"
    "buttonPress\0button\0buttonRelease\0"
    "setJoystick\0jsNumber\0timerEvent\0"
    "QTimerEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Joystick[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       5,    1,   44,    2, 0x06 /* Public */,
       7,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   50,    2, 0x0a /* Public */,
      10,    1,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void Joystick::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Joystick *_t = static_cast<Joystick *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->axisEvent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->buttonPress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->buttonRelease((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setJoystick((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->timerEvent((*reinterpret_cast< QTimerEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Joystick::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Joystick::axisEvent)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Joystick::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Joystick::buttonPress)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Joystick::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Joystick::buttonRelease)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Joystick::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Joystick.data,
      qt_meta_data_Joystick,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Joystick::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Joystick::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Joystick.stringdata0))
        return static_cast<void*>(const_cast< Joystick*>(this));
    return QObject::qt_metacast(_clname);
}

int Joystick::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Joystick::axisEvent(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Joystick::buttonPress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Joystick::buttonRelease(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
