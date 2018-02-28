/****************************************************************************
** Meta object code from reading C++ file 'handle_information.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../handle_information.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'handle_information.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_handle_information_t {
    QByteArrayData data[6];
    char stringdata[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_handle_information_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_handle_information_t qt_meta_stringdata_handle_information = {
    {
QT_MOC_LITERAL(0, 0, 18), // "handle_information"
QT_MOC_LITERAL(1, 19, 10), // "emit_leave"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 19), // "handle_information*"
QT_MOC_LITERAL(4, 51, 10), // "emit_start"
QT_MOC_LITERAL(5, 62, 8) // "time_out"

    },
    "handle_information\0emit_leave\0\0"
    "handle_information*\0emit_start\0time_out"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_handle_information[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void handle_information::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        handle_information *_t = static_cast<handle_information *>(_o);
        switch (_id) {
        case 0: _t->emit_leave((*reinterpret_cast< handle_information*(*)>(_a[1]))); break;
        case 1: _t->emit_start((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->time_out(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< handle_information* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (handle_information::*_t)(handle_information * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&handle_information::emit_leave)) {
                *result = 0;
            }
        }
        {
            typedef void (handle_information::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&handle_information::emit_start)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject handle_information::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_handle_information.data,
      qt_meta_data_handle_information,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *handle_information::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *handle_information::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_handle_information.stringdata))
        return static_cast<void*>(const_cast< handle_information*>(this));
    return QObject::qt_metacast(_clname);
}

int handle_information::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void handle_information::emit_leave(handle_information * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void handle_information::emit_start(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
