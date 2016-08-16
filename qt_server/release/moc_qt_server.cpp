/****************************************************************************
** Meta object code from reading C++ file 'qt_server.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qt_server.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt_server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qt_server[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      21,   10,   10,   10, 0x08,
      32,   10,   10,   10, 0x0a,
      52,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_qt_server[] = {
    "qt_server\0\0started()\0send_msg()\0"
    "update_msg(QString)\0err_msg_update(QString)\0"
};

void qt_server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qt_server *_t = static_cast<qt_server *>(_o);
        switch (_id) {
        case 0: _t->started(); break;
        case 1: _t->send_msg(); break;
        case 2: _t->update_msg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->err_msg_update((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qt_server::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qt_server::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_qt_server,
      qt_meta_data_qt_server, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qt_server::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qt_server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qt_server::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qt_server))
        return static_cast<void*>(const_cast< qt_server*>(this));
    return QWidget::qt_metacast(_clname);
}

int qt_server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void qt_server::started()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
