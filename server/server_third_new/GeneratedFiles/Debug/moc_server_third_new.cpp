/****************************************************************************
** Meta object code from reading C++ file 'server_third_new.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../server_third_new.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server_third_new.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_server_third_new_t {
    QByteArrayData data[12];
    char stringdata[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_server_third_new_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_server_third_new_t qt_meta_stringdata_server_third_new = {
    {
QT_MOC_LITERAL(0, 0, 16), // "server_third_new"
QT_MOC_LITERAL(1, 17, 4), // "stop"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "start"
QT_MOC_LITERAL(4, 29, 7), // "restart"
QT_MOC_LITERAL(5, 37, 19), // "status_information_"
QT_MOC_LITERAL(6, 57, 19), // "handle_information*"
QT_MOC_LITERAL(7, 77, 15), // "out_information"
QT_MOC_LITERAL(8, 93, 19), // "warning_information"
QT_MOC_LITERAL(9, 113, 17), // "wrong_information"
QT_MOC_LITERAL(10, 131, 17), // "other_information"
QT_MOC_LITERAL(11, 149, 17) // "leave_information"

    },
    "server_third_new\0stop\0\0start\0restart\0"
    "status_information_\0handle_information*\0"
    "out_information\0warning_information\0"
    "wrong_information\0other_information\0"
    "leave_information"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_server_third_new[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    1,   62,    2, 0x0a /* Public */,
       7,    1,   65,    2, 0x0a /* Public */,
       8,    1,   68,    2, 0x0a /* Public */,
       9,    1,   71,    2, 0x0a /* Public */,
      10,    1,   74,    2, 0x0a /* Public */,
      11,    1,   77,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void server_third_new::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        server_third_new *_t = static_cast<server_third_new *>(_o);
        switch (_id) {
        case 0: _t->stop(); break;
        case 1: _t->start(); break;
        case 2: _t->restart(); break;
        case 3: _t->status_information_((*reinterpret_cast< handle_information*(*)>(_a[1]))); break;
        case 4: _t->out_information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->warning_information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->wrong_information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->other_information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->leave_information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject server_third_new::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_server_third_new.data,
      qt_meta_data_server_third_new,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *server_third_new::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *server_third_new::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_server_third_new.stringdata))
        return static_cast<void*>(const_cast< server_third_new*>(this));
    return QWidget::qt_metacast(_clname);
}

int server_third_new::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
