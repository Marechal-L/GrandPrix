/****************************************************************************
** Meta object code from reading C++ file 'gpcontrol.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/gpcontrol.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gpcontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GPControl[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      22,   10,   10,   10, 0x05,
      42,   10,   10,   10, 0x05,
      58,   10,   10,   10, 0x05,
      72,   10,   10,   10, 0x05,
      90,   86,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     103,   10,   10,   10, 0x0a,
     114,   10,   10,   10, 0x08,
     140,   10,   10,   10, 0x08,
     165,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GPControl[] = {
    "GPControl\0\0carMoved()\0carMovedWithBoost()\0"
    "driverTimeout()\0invalidMove()\0"
    "syntaxError()\0res\0end(QString)\0"
    "nextMove()\0readyReadStandardOutput()\0"
    "readyReadStandardError()\0timeout()\0"
};

void GPControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GPControl *_t = static_cast<GPControl *>(_o);
        switch (_id) {
        case 0: _t->carMoved(); break;
        case 1: _t->carMovedWithBoost(); break;
        case 2: _t->driverTimeout(); break;
        case 3: _t->invalidMove(); break;
        case 4: _t->syntaxError(); break;
        case 5: _t->end((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->nextMove(); break;
        case 7: _t->readyReadStandardOutput(); break;
        case 8: _t->readyReadStandardError(); break;
        case 9: _t->timeout(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GPControl::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GPControl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GPControl,
      qt_meta_data_GPControl, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GPControl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GPControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GPControl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GPControl))
        return static_cast<void*>(const_cast< GPControl*>(this));
    return QObject::qt_metacast(_clname);
}

int GPControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void GPControl::carMoved()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GPControl::carMovedWithBoost()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void GPControl::driverTimeout()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void GPControl::invalidMove()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void GPControl::syntaxError()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void GPControl::end(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
