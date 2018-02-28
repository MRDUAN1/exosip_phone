/****************************************************************************
** Meta object code from reading C++ file 'callback.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../callback.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'callback.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Callback_t {
    QByteArrayData data[10];
    char stringdata[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Callback_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Callback_t qt_meta_stringdata_Callback = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Callback"
QT_MOC_LITERAL(1, 9, 19), // "success_information"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 19), // "failure_information"
QT_MOC_LITERAL(4, 50, 16), // "success_register"
QT_MOC_LITERAL(5, 67, 3), // "str"
QT_MOC_LITERAL(6, 71, 19), // "warning_information"
QT_MOC_LITERAL(7, 91, 16), // "quit_information"
QT_MOC_LITERAL(8, 108, 25), // "client_information_signal"
QT_MOC_LITERAL(9, 134, 19) // "handle_information*"

    },
    "Callback\0success_information\0\0"
    "failure_information\0success_register\0"
    "str\0warning_information\0quit_information\0"
    "client_information_signal\0handle_information*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Callback[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    1,   47,    2, 0x06 /* Public */,
       4,    1,   50,    2, 0x06 /* Public */,
       6,    1,   53,    2, 0x06 /* Public */,
       7,    1,   56,    2, 0x06 /* Public */,
       8,    1,   59,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 9,    2,

       0        // eod
};

void Callback::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Callback *_t = static_cast<Callback *>(_o);
        switch (_id) {
        case 0: _t->success_information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->failure_information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->success_register((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->warning_information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->quit_information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->client_information_signal((*reinterpret_cast< handle_information*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Callback::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Callback::success_information)) {
                *result = 0;
            }
        }
        {
            typedef void (Callback::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Callback::failure_information)) {
                *result = 1;
            }
        }
        {
            typedef void (Callback::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Callback::success_register)) {
                *result = 2;
            }
        }
        {
            typedef void (Callback::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Callback::warning_information)) {
                *result = 3;
            }
        }
        {
            typedef void (Callback::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Callback::quit_information)) {
                *result = 4;
            }
        }
        {
            typedef void (Callback::*_t)(handle_information * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Callback::client_information_signal)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject Callback::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Callback.data,
      qt_meta_data_Callback,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Callback::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Callback::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Callback.stringdata))
        return static_cast<void*>(const_cast< Callback*>(this));
    return QObject::qt_metacast(_clname);
}

int Callback::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Callback::success_information(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Callback::failure_information(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Callback::success_register(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Callback::warning_information(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Callback::quit_information(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Callback::client_information_signal(handle_information * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
