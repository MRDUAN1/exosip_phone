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
    QByteArrayData data[15];
    char stringdata[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Callback_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Callback_t qt_meta_stringdata_Callback = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Callback"
QT_MOC_LITERAL(1, 9, 15), // "message_failure"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 19), // "success_information"
QT_MOC_LITERAL(4, 46, 19), // "failure_information"
QT_MOC_LITERAL(5, 66, 14), // "invite_failure"
QT_MOC_LITERAL(6, 81, 16), // "success_register"
QT_MOC_LITERAL(7, 98, 3), // "str"
QT_MOC_LITERAL(8, 102, 16), // "failure_register"
QT_MOC_LITERAL(9, 119, 13), // "status_invite"
QT_MOC_LITERAL(10, 133, 11), // "message_com"
QT_MOC_LITERAL(11, 145, 12), // "subject_call"
QT_MOC_LITERAL(12, 158, 15), // "eXosip_event_t*"
QT_MOC_LITERAL(13, 174, 7), // "message"
QT_MOC_LITERAL(14, 182, 12) // "passive_call"

    },
    "Callback\0message_failure\0\0success_information\0"
    "failure_information\0invite_failure\0"
    "success_register\0str\0failure_register\0"
    "status_invite\0message_com\0subject_call\0"
    "eXosip_event_t*\0message\0passive_call"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Callback[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    1,   67,    2, 0x06 /* Public */,
       4,    1,   70,    2, 0x06 /* Public */,
       5,    1,   73,    2, 0x06 /* Public */,
       6,    1,   76,    2, 0x06 /* Public */,
       8,    1,   79,    2, 0x06 /* Public */,
       9,    2,   82,    2, 0x06 /* Public */,
      10,    2,   87,    2, 0x06 /* Public */,
      11,    1,   92,    2, 0x06 /* Public */,
      14,    1,   95,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void Callback::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Callback *_t = static_cast<Callback *>(_o);
        switch (_id) {
        case 0: _t->message_failure((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->success_information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->failure_information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->invite_failure((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->success_register((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->failure_register((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->status_invite((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->message_com((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->subject_call((*reinterpret_cast< eXosip_event_t*(*)>(_a[1]))); break;
        case 9: _t->passive_call((*reinterpret_cast< eXosip_event_t*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Callback::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Callback::message_failure)) {
                *result = 0;
            }
        }
        {
            typedef void (Callback::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Callback::success_information)) {
                *result = 1;
            }
        }
        {
            typedef void (Callback::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Callback::failure_information)) {
                *result = 2;
            }
        }
        {
            typedef void (Callback::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Callback::invite_failure)) {
                *result = 3;
            }
        }
        {
            typedef void (Callback::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Callback::success_register)) {
                *result = 4;
            }
        }
        {
            typedef void (Callback::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Callback::failure_register)) {
                *result = 5;
            }
        }
        {
            typedef void (Callback::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Callback::status_invite)) {
                *result = 6;
            }
        }
        {
            typedef void (Callback::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Callback::message_com)) {
                *result = 7;
            }
        }
        {
            typedef void (Callback::*_t)(eXosip_event_t * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Callback::subject_call)) {
                *result = 8;
            }
        }
        {
            typedef void (Callback::*_t)(eXosip_event_t * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Callback::passive_call)) {
                *result = 9;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Callback::message_failure(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Callback::success_information(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Callback::failure_information(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Callback::invite_failure(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Callback::success_register(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Callback::failure_register(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Callback::status_invite(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Callback::message_com(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Callback::subject_call(eXosip_event_t * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Callback::passive_call(eXosip_event_t * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
