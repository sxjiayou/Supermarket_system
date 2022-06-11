/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Supermarket_system/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata[533];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 21),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 22),
QT_MOC_LITERAL(4, 57, 20),
QT_MOC_LITERAL(5, 78, 20),
QT_MOC_LITERAL(6, 99, 22),
QT_MOC_LITERAL(7, 122, 25),
QT_MOC_LITERAL(8, 148, 28),
QT_MOC_LITERAL(9, 177, 28),
QT_MOC_LITERAL(10, 206, 28),
QT_MOC_LITERAL(11, 235, 23),
QT_MOC_LITERAL(12, 259, 26),
QT_MOC_LITERAL(13, 286, 26),
QT_MOC_LITERAL(14, 313, 26),
QT_MOC_LITERAL(15, 340, 23),
QT_MOC_LITERAL(16, 364, 25),
QT_MOC_LITERAL(17, 390, 26),
QT_MOC_LITERAL(18, 417, 24),
QT_MOC_LITERAL(19, 442, 40),
QT_MOC_LITERAL(20, 483, 3),
QT_MOC_LITERAL(21, 487, 6),
QT_MOC_LITERAL(22, 494, 38)
    },
    "MainWindow\0on_btn_reduce_clicked\0\0"
    "on_btn_magnify_clicked\0on_btn_close_clicked\0"
    "on_btn_goods_clicked\0on_btn_workers_clicked\0"
    "on_addworkers_btn_clicked\0"
    "on_deleteworkers_btn_clicked\0"
    "on_changeworkers_btn_clicked\0"
    "on_selectworkers_btn_clicked\0"
    "on_addgoods_btn_clicked\0"
    "on_deletegoods_btn_clicked\0"
    "on_changegoods_btn_clicked\0"
    "on_selectgoods_btn_clicked\0"
    "on_goods_upload_clicked\0"
    "on_workers_uoload_clicked\0"
    "on_showworkers_btn_clicked\0"
    "on_showgoods_btn_clicked\0"
    "on_workers_tableWidget_cellDoubleClicked\0"
    "row\0column\0on_goods_tableWidget_cellDoubleClicked"
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
       1,    0,  109,    2, 0x08 /* Private */,
       3,    0,  110,    2, 0x08 /* Private */,
       4,    0,  111,    2, 0x08 /* Private */,
       5,    0,  112,    2, 0x08 /* Private */,
       6,    0,  113,    2, 0x08 /* Private */,
       7,    0,  114,    2, 0x08 /* Private */,
       8,    0,  115,    2, 0x08 /* Private */,
       9,    0,  116,    2, 0x08 /* Private */,
      10,    0,  117,    2, 0x08 /* Private */,
      11,    0,  118,    2, 0x08 /* Private */,
      12,    0,  119,    2, 0x08 /* Private */,
      13,    0,  120,    2, 0x08 /* Private */,
      14,    0,  121,    2, 0x08 /* Private */,
      15,    0,  122,    2, 0x08 /* Private */,
      16,    0,  123,    2, 0x08 /* Private */,
      17,    0,  124,    2, 0x08 /* Private */,
      18,    0,  125,    2, 0x08 /* Private */,
      19,    2,  126,    2, 0x08 /* Private */,
      22,    2,  131,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   20,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   20,   21,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_btn_reduce_clicked(); break;
        case 1: _t->on_btn_magnify_clicked(); break;
        case 2: _t->on_btn_close_clicked(); break;
        case 3: _t->on_btn_goods_clicked(); break;
        case 4: _t->on_btn_workers_clicked(); break;
        case 5: _t->on_addworkers_btn_clicked(); break;
        case 6: _t->on_deleteworkers_btn_clicked(); break;
        case 7: _t->on_changeworkers_btn_clicked(); break;
        case 8: _t->on_selectworkers_btn_clicked(); break;
        case 9: _t->on_addgoods_btn_clicked(); break;
        case 10: _t->on_deletegoods_btn_clicked(); break;
        case 11: _t->on_changegoods_btn_clicked(); break;
        case 12: _t->on_selectgoods_btn_clicked(); break;
        case 13: _t->on_goods_upload_clicked(); break;
        case 14: _t->on_workers_uoload_clicked(); break;
        case 15: _t->on_showworkers_btn_clicked(); break;
        case 16: _t->on_showgoods_btn_clicked(); break;
        case 17: _t->on_workers_tableWidget_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 18: _t->on_goods_tableWidget_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
