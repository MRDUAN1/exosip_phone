/****************************************************************************
** Meta object code from reading C++ file 'sip_network.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../sip_network.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sip_network.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_sip_network_t {
    QByteArrayData data[16];
    char stringdata[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_sip_network_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_sip_network_t qt_meta_stringdata_sip_network = {
    {
QT_MOC_LITERAL(0, 0, 11), // "sip_network"
QT_MOC_LITERAL(1, 12, 19), // "success_information"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 19), // "failure_information"
QT_MOC_LITERAL(4, 53, 19), // "start_time_register"
QT_MOC_LITERAL(5, 73, 14), // "register_state"
QT_MOC_LITERAL(6, 88, 15), // "slot_time_start"
QT_MOC_LITERAL(7, 104, 17), // "register_time_out"
QT_MOC_LITERAL(8, 122, 14), // "register_leave"
QT_MOC_LITERAL(9, 137, 19), // "register_successful"
QT_MOC_LITERAL(10, 157, 10), // "set_detail"
QT_MOC_LITERAL(11, 168, 3), // "_id"
QT_MOC_LITERAL(12, 172, 7), // "_domain"
QT_MOC_LITERAL(13, 180, 7), // "_passwd"
QT_MOC_LITERAL(14, 188, 9), // "port_name"
QT_MOC_LITERAL(15, 198, 17) // "_authoration_name"

    },
    "sip_network\0success_information\0\0"
    "failure_information\0start_time_register\0"
    "register_state\0slot_time_start\0"
    "register_time_out\0register_leave\0"
    "register_successful\0set_detail\0_id\0"
    "_domain\0_passwd\0port_name\0_authoration_name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_sip_network[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    0,   65,    2, 0x06 /* Public */,
       5,    1,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   69,    2, 0x0a /* Public */,
       7,    0,   70,    2, 0x0a /* Public */,
       8,    0,   71,    2, 0x0a /* Public */,
       9,    1,   72,    2, 0x0a /* Public */,
      10,    5,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   11,   12,   13,   14,   15,

       0        // eod
};

void sip_network::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        sip_network *_t = static_cast<sip_network *>(_o);
        switch (_id) {
        case 0: _t->success_information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->failure_information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->start_time_register(); break;
        case 3: _t->register_state((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slot_time_start(); break;
        case 5: _t->register_time_out(); break;
        case 6: _t->register_leave(); break;
        case 7: _t->register_successful((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->set_detail((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (sip_network::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&sip_network::success_information)) {
                *result = 0;
            }
        }
        {
            typedef void (sip_network::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&sip_network::failure_information)) {
                *result = 1;
            }
        }
        {
            typedef void (sip_network::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&sip_network::start_time_register)) {
                *result = 2;
            }
        }
        {
            typedef void (sip_network::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&sip_network::register_state)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject sip_network::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_sip_network.data,
      qt_meta_data_sip_network,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *sip_network::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sip_network::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_sip_network.stringdata))
        return static_cast<void*>(const_cast< sip_network*>(this));
    return QThread::qt_metacast(_clname);
}

int sip_network::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void sip_network::success_information(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void sip_network::failure_information(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void sip_network::start_time_register()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void sip_network::register_state(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
