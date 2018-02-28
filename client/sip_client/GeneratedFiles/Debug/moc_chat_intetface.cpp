/****************************************************************************
** Meta object code from reading C++ file 'chat_intetface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chat_intetface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chat_intetface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_chat_intetface_t {
    QByteArrayData data[11];
    char stringdata[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_chat_intetface_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_chat_intetface_t qt_meta_stringdata_chat_intetface = {
    {
QT_MOC_LITERAL(0, 0, 14), // "chat_intetface"
QT_MOC_LITERAL(1, 15, 12), // "insert_class"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "switchClicked"
QT_MOC_LITERAL(4, 43, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(5, 60, 12), // "send_message"
QT_MOC_LITERAL(6, 73, 9), // "send_call"
QT_MOC_LITERAL(7, 83, 10), // "send_video"
QT_MOC_LITERAL(8, 94, 10), // "paintEvent"
QT_MOC_LITERAL(9, 105, 12), // "QPaintEvent*"
QT_MOC_LITERAL(10, 118, 5) // "event"

    },
    "chat_intetface\0insert_class\0\0switchClicked\0"
    "QListWidgetItem*\0send_message\0send_call\0"
    "send_video\0paintEvent\0QPaintEvent*\0"
    "event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chat_intetface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x0a /* Public */,
       3,    1,   49,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void chat_intetface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        chat_intetface *_t = static_cast<chat_intetface *>(_o);
        switch (_id) {
        case 0: _t->insert_class((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->switchClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->send_message(); break;
        case 3: _t->send_call(); break;
        case 4: _t->send_video(); break;
        case 5: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject chat_intetface::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_chat_intetface.data,
      qt_meta_data_chat_intetface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *chat_intetface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chat_intetface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_chat_intetface.stringdata))
        return static_cast<void*>(const_cast< chat_intetface*>(this));
    return QWidget::qt_metacast(_clname);
}

int chat_intetface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
