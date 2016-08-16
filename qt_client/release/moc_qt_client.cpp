/****************************************************************************
** Meta object code from reading C++ file 'qt_client.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qt_client.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt_client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qt_client[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      22,   10,   10,   10, 0x08,
      31,   29,   10,   10, 0x0a,
      51,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_qt_client[] = {
    "qt_client\0\0send_msg()\0conn()\0s\0"
    "update_msg(QString)\0err_msg_update(QString)\0"
};

void qt_client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qt_client *_t = static_cast<qt_client *>(_o);
        switch (_id) {
        case 0: _t->send_msg(); break;
        case 1: _t->conn(); break;
        case 2: _t->update_msg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->err_msg_update((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qt_client::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qt_client::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_qt_client,
      qt_meta_data_qt_client, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qt_client::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qt_client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qt_client::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qt_client))
        return static_cast<void*>(const_cast< qt_client*>(this));
    return QWidget::qt_metacast(_clname);
}

int qt_client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
