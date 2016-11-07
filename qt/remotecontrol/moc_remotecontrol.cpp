/****************************************************************************
** Meta object code from reading C++ file 'remotecontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "remotecontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'remotecontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RemoteControl_t {
    QByteArrayData data[34];
    char stringdata0[445];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RemoteControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RemoteControl_t qt_meta_stringdata_RemoteControl = {
    {
QT_MOC_LITERAL(0, 0, 13), // "RemoteControl"
QT_MOC_LITERAL(1, 14, 12), // "displayError"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(4, 57, 11), // "getthestuff"
QT_MOC_LITERAL(5, 69, 17), // "connectionSuccess"
QT_MOC_LITERAL(6, 87, 5), // "about"
QT_MOC_LITERAL(7, 93, 13), // "serverConnect"
QT_MOC_LITERAL(8, 107, 16), // "serverDisconnect"
QT_MOC_LITERAL(9, 124, 13), // "start_forward"
QT_MOC_LITERAL(10, 138, 12), // "stop_forward"
QT_MOC_LITERAL(11, 151, 12), // "stop_reverse"
QT_MOC_LITERAL(12, 164, 13), // "start_reverse"
QT_MOC_LITERAL(13, 178, 10), // "start_left"
QT_MOC_LITERAL(14, 189, 9), // "stop_left"
QT_MOC_LITERAL(15, 199, 11), // "start_right"
QT_MOC_LITERAL(16, 211, 10), // "stop_right"
QT_MOC_LITERAL(17, 222, 17), // "start_turret_left"
QT_MOC_LITERAL(18, 240, 16), // "stop_turret_left"
QT_MOC_LITERAL(19, 257, 18), // "start_turret_right"
QT_MOC_LITERAL(20, 276, 17), // "stop_turret_right"
QT_MOC_LITERAL(21, 294, 15), // "start_turret_up"
QT_MOC_LITERAL(22, 310, 14), // "stop_turret_up"
QT_MOC_LITERAL(23, 325, 17), // "start_turret_down"
QT_MOC_LITERAL(24, 343, 16), // "stop_turret_down"
QT_MOC_LITERAL(25, 360, 10), // "start_fire"
QT_MOC_LITERAL(26, 371, 9), // "stop_fire"
QT_MOC_LITERAL(27, 381, 9), // "axisEvent"
QT_MOC_LITERAL(28, 391, 4), // "axis"
QT_MOC_LITERAL(29, 396, 5), // "value"
QT_MOC_LITERAL(30, 402, 11), // "buttonPress"
QT_MOC_LITERAL(31, 414, 6), // "button"
QT_MOC_LITERAL(32, 421, 13), // "buttonRelease"
QT_MOC_LITERAL(33, 435, 9) // "heartBeat"

    },
    "RemoteControl\0displayError\0\0"
    "QAbstractSocket::SocketError\0getthestuff\0"
    "connectionSuccess\0about\0serverConnect\0"
    "serverDisconnect\0start_forward\0"
    "stop_forward\0stop_reverse\0start_reverse\0"
    "start_left\0stop_left\0start_right\0"
    "stop_right\0start_turret_left\0"
    "stop_turret_left\0start_turret_right\0"
    "stop_turret_right\0start_turret_up\0"
    "stop_turret_up\0start_turret_down\0"
    "stop_turret_down\0start_fire\0stop_fire\0"
    "axisEvent\0axis\0value\0buttonPress\0"
    "button\0buttonRelease\0heartBeat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RemoteControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  154,    2, 0x0a /* Public */,
       4,    0,  157,    2, 0x0a /* Public */,
       5,    0,  158,    2, 0x0a /* Public */,
       6,    0,  159,    2, 0x0a /* Public */,
       7,    0,  160,    2, 0x0a /* Public */,
       8,    0,  161,    2, 0x0a /* Public */,
       9,    0,  162,    2, 0x0a /* Public */,
      10,    0,  163,    2, 0x0a /* Public */,
      11,    0,  164,    2, 0x0a /* Public */,
      12,    0,  165,    2, 0x0a /* Public */,
      13,    0,  166,    2, 0x0a /* Public */,
      14,    0,  167,    2, 0x0a /* Public */,
      15,    0,  168,    2, 0x0a /* Public */,
      16,    0,  169,    2, 0x0a /* Public */,
      17,    0,  170,    2, 0x0a /* Public */,
      18,    0,  171,    2, 0x0a /* Public */,
      19,    0,  172,    2, 0x0a /* Public */,
      20,    0,  173,    2, 0x0a /* Public */,
      21,    0,  174,    2, 0x0a /* Public */,
      22,    0,  175,    2, 0x0a /* Public */,
      23,    0,  176,    2, 0x0a /* Public */,
      24,    0,  177,    2, 0x0a /* Public */,
      25,    0,  178,    2, 0x0a /* Public */,
      26,    0,  179,    2, 0x0a /* Public */,
      27,    2,  180,    2, 0x0a /* Public */,
      30,    1,  185,    2, 0x0a /* Public */,
      32,    1,  188,    2, 0x0a /* Public */,
      33,    0,  191,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   28,   29,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void,

       0        // eod
};

void RemoteControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RemoteControl *_t = static_cast<RemoteControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 1: _t->getthestuff(); break;
        case 2: _t->connectionSuccess(); break;
        case 3: _t->about(); break;
        case 4: _t->serverConnect(); break;
        case 5: _t->serverDisconnect(); break;
        case 6: _t->start_forward(); break;
        case 7: _t->stop_forward(); break;
        case 8: _t->stop_reverse(); break;
        case 9: _t->start_reverse(); break;
        case 10: _t->start_left(); break;
        case 11: _t->stop_left(); break;
        case 12: _t->start_right(); break;
        case 13: _t->stop_right(); break;
        case 14: _t->start_turret_left(); break;
        case 15: _t->stop_turret_left(); break;
        case 16: _t->start_turret_right(); break;
        case 17: _t->stop_turret_right(); break;
        case 18: _t->start_turret_up(); break;
        case 19: _t->stop_turret_up(); break;
        case 20: _t->start_turret_down(); break;
        case 21: _t->stop_turret_down(); break;
        case 22: _t->start_fire(); break;
        case 23: _t->stop_fire(); break;
        case 24: _t->axisEvent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 25: _t->buttonPress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->buttonRelease((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->heartBeat(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject RemoteControl::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RemoteControl.data,
      qt_meta_data_RemoteControl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RemoteControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RemoteControl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RemoteControl.stringdata0))
        return static_cast<void*>(const_cast< RemoteControl*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int RemoteControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
