/****************************************************************************
** Meta object code from reading C++ file 'register_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../register_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'register_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_register_dialog_t {
    QByteArrayData data[13];
    char stringdata[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_register_dialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_register_dialog_t qt_meta_stringdata_register_dialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "register_dialog"
QT_MOC_LITERAL(1, 16, 15), // "warning_message"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 10), // "detail_set"
QT_MOC_LITERAL(4, 44, 3), // "_id"
QT_MOC_LITERAL(5, 48, 17), // "_authorization_id"
QT_MOC_LITERAL(6, 66, 5), // "_port"
QT_MOC_LITERAL(7, 72, 7), // "_passwd"
QT_MOC_LITERAL(8, 80, 7), // "_domain"
QT_MOC_LITERAL(9, 88, 11), // "register_ok"
QT_MOC_LITERAL(10, 100, 9), // "hide_slot"
QT_MOC_LITERAL(11, 110, 17), // "change_state_call"
QT_MOC_LITERAL(12, 128, 21) // "change_state_presence"

    },
    "register_dialog\0warning_message\0\0"
    "detail_set\0_id\0_authorization_id\0_port\0"
    "_passwd\0_domain\0register_ok\0hide_slot\0"
    "change_state_call\0change_state_presence"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_register_dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    5,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   58,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,
      11,    1,   60,    2, 0x08 /* Private */,
      12,    1,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,    6,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void register_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        register_dialog *_t = static_cast<register_dialog *>(_o);
        switch (_id) {
        case 0: _t->warning_message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->detail_set((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 2: _t->register_ok(); break;
        case 3: _t->hide_slot(); break;
        case 4: _t->change_state_call((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->change_state_presence((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (register_dialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&register_dialog::warning_message)) {
                *result = 0;
            }
        }
        {
            typedef void (register_dialog::*_t)(QString , QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&register_dialog::detail_set)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject register_dialog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_register_dialog.data,
      qt_meta_data_register_dialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *register_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *register_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_register_dialog.stringdata))
        return static_cast<void*>(const_cast< register_dialog*>(this));
    return QWidget::qt_metacast(_clname);
}

int register_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void register_dialog::warning_message(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void register_dialog::detail_set(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
