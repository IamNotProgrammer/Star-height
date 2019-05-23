/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[318];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 22), // "on_dec_deg_textChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 4), // "arg1"
QT_MOC_LITERAL(4, 40, 22), // "on_dec_min_textChanged"
QT_MOC_LITERAL(5, 63, 22), // "on_dec_sec_textChanged"
QT_MOC_LITERAL(6, 86, 18), // "on_lon_textChanged"
QT_MOC_LITERAL(7, 105, 18), // "on_lat_textChanged"
QT_MOC_LITERAL(8, 124, 17), // "on_LT_timeChanged"
QT_MOC_LITERAL(9, 142, 4), // "time"
QT_MOC_LITERAL(10, 147, 25), // "on_time_zone_valueChanged"
QT_MOC_LITERAL(11, 173, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(12, 205, 5), // "index"
QT_MOC_LITERAL(13, 211, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(14, 233, 19), // "on_Date_dateChanged"
QT_MOC_LITERAL(15, 253, 4), // "date"
QT_MOC_LITERAL(16, 258, 19), // "on_ra_h_textChanged"
QT_MOC_LITERAL(17, 278, 19), // "on_ra_m_textChanged"
QT_MOC_LITERAL(18, 298, 19) // "on_ra_s_textChanged"

    },
    "MainWindow\0on_dec_deg_textChanged\0\0"
    "arg1\0on_dec_min_textChanged\0"
    "on_dec_sec_textChanged\0on_lon_textChanged\0"
    "on_lat_textChanged\0on_LT_timeChanged\0"
    "time\0on_time_zone_valueChanged\0"
    "on_comboBox_currentIndexChanged\0index\0"
    "on_pushButton_clicked\0on_Date_dateChanged\0"
    "date\0on_ra_h_textChanged\0on_ra_m_textChanged\0"
    "on_ra_s_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       4,    1,   82,    2, 0x08 /* Private */,
       5,    1,   85,    2, 0x08 /* Private */,
       6,    1,   88,    2, 0x08 /* Private */,
       7,    1,   91,    2, 0x08 /* Private */,
       8,    1,   94,    2, 0x08 /* Private */,
      10,    1,   97,    2, 0x08 /* Private */,
      11,    1,  100,    2, 0x08 /* Private */,
      13,    0,  103,    2, 0x08 /* Private */,
      14,    1,  104,    2, 0x08 /* Private */,
      16,    1,  107,    2, 0x08 /* Private */,
      17,    1,  110,    2, 0x08 /* Private */,
      18,    1,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QTime,    9,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,   15,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_dec_deg_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_dec_min_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_dec_sec_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_lon_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_lat_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_LT_timeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 6: _t->on_time_zone_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_clicked(); break;
        case 9: _t->on_Date_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 10: _t->on_ra_h_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_ra_m_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_ra_s_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
