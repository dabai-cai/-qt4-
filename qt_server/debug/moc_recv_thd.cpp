/****************************************************************************
** Meta object code from reading C++ file 'recv_thd.h'
**
** Created: Tue Sep 16 21:08:15 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../recv_thd.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recv_thd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_recv_thd[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      35,    9,    9,    9, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_recv_thd[] = {
    "recv_thd\0\0recv_msg_signal(QString)\0"
    "err_msg_signal(QString)\0"
};

const QMetaObject recv_thd::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_recv_thd,
      qt_meta_data_recv_thd, 0 }
};

const QMetaObject *recv_thd::metaObject() const
{
    return &staticMetaObject;
}

void *recv_thd::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_recv_thd))
	return static_cast<void*>(const_cast< recv_thd*>(this));
    return QThread::qt_metacast(_clname);
}

int recv_thd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: recv_msg_signal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: err_msg_signal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void recv_thd::recv_msg_signal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void recv_thd::err_msg_signal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
