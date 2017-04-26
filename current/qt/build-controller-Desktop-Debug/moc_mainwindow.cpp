/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../controller/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[25];
    char stringdata0[345];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 17), // "connectionSuccess"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "displayError"
QT_MOC_LITERAL(4, 43, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(5, 72, 13), // "serverConnect"
QT_MOC_LITERAL(6, 86, 16), // "serverDisconnect"
QT_MOC_LITERAL(7, 103, 8), // "getStuff"
QT_MOC_LITERAL(8, 112, 9), // "heartBeat"
QT_MOC_LITERAL(9, 122, 10), // "ignitionOn"
QT_MOC_LITERAL(10, 133, 11), // "ignitionOff"
QT_MOC_LITERAL(11, 145, 17), // "leftButtonPressed"
QT_MOC_LITERAL(12, 163, 18), // "rightButtonPressed"
QT_MOC_LITERAL(13, 182, 15), // "goButtonPressed"
QT_MOC_LITERAL(14, 198, 17), // "stopButtonPressed"
QT_MOC_LITERAL(15, 216, 18), // "leftButtonReleased"
QT_MOC_LITERAL(16, 235, 19), // "rightButtonReleased"
QT_MOC_LITERAL(17, 255, 16), // "goButtonReleased"
QT_MOC_LITERAL(18, 272, 18), // "stopButtonReleased"
QT_MOC_LITERAL(19, 291, 11), // "buttonPress"
QT_MOC_LITERAL(20, 303, 6), // "button"
QT_MOC_LITERAL(21, 310, 13), // "buttonRelease"
QT_MOC_LITERAL(22, 324, 9), // "axisEvent"
QT_MOC_LITERAL(23, 334, 4), // "axis"
QT_MOC_LITERAL(24, 339, 5) // "value"

    },
    "MainWindow\0connectionSuccess\0\0"
    "displayError\0QAbstractSocket::SocketError\0"
    "serverConnect\0serverDisconnect\0getStuff\0"
    "heartBeat\0ignitionOn\0ignitionOff\0"
    "leftButtonPressed\0rightButtonPressed\0"
    "goButtonPressed\0stopButtonPressed\0"
    "leftButtonReleased\0rightButtonReleased\0"
    "goButtonReleased\0stopButtonReleased\0"
    "buttonPress\0button\0buttonRelease\0"
    "axisEvent\0axis\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x0a /* Public */,
       3,    1,  110,    2, 0x0a /* Public */,
       5,    0,  113,    2, 0x0a /* Public */,
       6,    0,  114,    2, 0x0a /* Public */,
       7,    0,  115,    2, 0x0a /* Public */,
       8,    0,  116,    2, 0x0a /* Public */,
       9,    0,  117,    2, 0x0a /* Public */,
      10,    0,  118,    2, 0x0a /* Public */,
      11,    0,  119,    2, 0x0a /* Public */,
      12,    0,  120,    2, 0x0a /* Public */,
      13,    0,  121,    2, 0x0a /* Public */,
      14,    0,  122,    2, 0x0a /* Public */,
      15,    0,  123,    2, 0x0a /* Public */,
      16,    0,  124,    2, 0x0a /* Public */,
      17,    0,  125,    2, 0x0a /* Public */,
      18,    0,  126,    2, 0x0a /* Public */,
      19,    1,  127,    2, 0x0a /* Public */,
      21,    1,  130,    2, 0x0a /* Public */,
      22,    2,  133,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
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
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   23,   24,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectionSuccess(); break;
        case 1: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 2: _t->serverConnect(); break;
        case 3: _t->serverDisconnect(); break;
        case 4: _t->getStuff(); break;
        case 5: _t->heartBeat(); break;
        case 6: _t->ignitionOn(); break;
        case 7: _t->ignitionOff(); break;
        case 8: _t->leftButtonPressed(); break;
        case 9: _t->rightButtonPressed(); break;
        case 10: _t->goButtonPressed(); break;
        case 11: _t->stopButtonPressed(); break;
        case 12: _t->leftButtonReleased(); break;
        case 13: _t->rightButtonReleased(); break;
        case 14: _t->goButtonReleased(); break;
        case 15: _t->stopButtonReleased(); break;
        case 16: _t->buttonPress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->buttonRelease((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->axisEvent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
