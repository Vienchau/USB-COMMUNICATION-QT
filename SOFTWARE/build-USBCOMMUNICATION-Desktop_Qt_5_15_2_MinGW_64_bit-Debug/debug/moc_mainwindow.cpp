/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../USBCOMMUNICATION/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[392];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "serialport_read"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 21), // "on_openButton_clicked"
QT_MOC_LITERAL(4, 50, 21), // "on_sendButton_clicked"
QT_MOC_LITERAL(5, 72, 24), // "on_sendpidButton_clicked"
QT_MOC_LITERAL(6, 97, 24), // "on_tunningButton_clicked"
QT_MOC_LITERAL(7, 122, 24), // "on_requestButton_clicked"
QT_MOC_LITERAL(8, 147, 23), // "on_motionButton_clicked"
QT_MOC_LITERAL(9, 171, 20), // "on_runButton_clicked"
QT_MOC_LITERAL(10, 192, 26), // "on_senparamsButton_clicked"
QT_MOC_LITERAL(11, 219, 20), // "on_getButton_clicked"
QT_MOC_LITERAL(12, 240, 24), // "on_savePIDButton_clicked"
QT_MOC_LITERAL(13, 265, 25), // "on_clearPIDButton_clicked"
QT_MOC_LITERAL(14, 291, 24), // "on_infoPIDButton_clicked"
QT_MOC_LITERAL(15, 316, 29), // "on_clearReceiveButton_clicked"
QT_MOC_LITERAL(16, 346, 22), // "on_closeButton_clicked"
QT_MOC_LITERAL(17, 369, 22) // "on_clearButton_clicked"

    },
    "MainWindow\0serialport_read\0\0"
    "on_openButton_clicked\0on_sendButton_clicked\0"
    "on_sendpidButton_clicked\0"
    "on_tunningButton_clicked\0"
    "on_requestButton_clicked\0"
    "on_motionButton_clicked\0on_runButton_clicked\0"
    "on_senparamsButton_clicked\0"
    "on_getButton_clicked\0on_savePIDButton_clicked\0"
    "on_clearPIDButton_clicked\0"
    "on_infoPIDButton_clicked\0"
    "on_clearReceiveButton_clicked\0"
    "on_closeButton_clicked\0on_clearButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,

 // slots: parameters
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

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->serialport_read(); break;
        case 1: _t->on_openButton_clicked(); break;
        case 2: _t->on_sendButton_clicked(); break;
        case 3: _t->on_sendpidButton_clicked(); break;
        case 4: _t->on_tunningButton_clicked(); break;
        case 5: _t->on_requestButton_clicked(); break;
        case 6: _t->on_motionButton_clicked(); break;
        case 7: _t->on_runButton_clicked(); break;
        case 8: _t->on_senparamsButton_clicked(); break;
        case 9: _t->on_getButton_clicked(); break;
        case 10: _t->on_savePIDButton_clicked(); break;
        case 11: _t->on_clearPIDButton_clicked(); break;
        case 12: _t->on_infoPIDButton_clicked(); break;
        case 13: _t->on_clearReceiveButton_clicked(); break;
        case 14: _t->on_closeButton_clicked(); break;
        case 15: _t->on_clearButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
