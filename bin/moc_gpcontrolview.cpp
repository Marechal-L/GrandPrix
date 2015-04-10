/****************************************************************************
** Meta object code from reading C++ file 'gpcontrolview.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/gpcontrolview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gpcontrolview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GPControlView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   15,   14,   14, 0x05,
      48,   14,   14,   14, 0x05,
      66,   14,   14,   14, 0x05,
      89,   14,   14,   14, 0x05,
     110,   14,   14,   14, 0x05,
     131,   14,   14,   14, 0x05,
     155,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     171,  163,   14,   14, 0x08,
     219,  209,   14,   14, 0x08,
     258,   14,   14,   14, 0x08,
     288,  281,   14,   14, 0x08,
     323,  281,   14,   14, 0x08,
     363,  281,   14,   14, 0x08,
     408,  402,   14,   14, 0x08,
     441,   14,   14,   14, 0x08,
     462,   14,   14,   14, 0x08,
     492,   14,   14,   14, 0x08,
     515,   14,   14,   14, 0x08,
     541,   14,   14,   14, 0x08,
     565,   14,   14,   14, 0x08,
     589,   14,   14,   14, 0x08,
     620,  614,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GPControlView[] = {
    "GPControlView\0\0gpControl\0"
    "mapChanged(GPControl*)\0carMoved(QString)\0"
    "driverTimeout(QString)\0invalidMove(QString)\0"
    "syntaxError(QString)\0serverResponse(QString)\0"
    "start()\0mapPath\0on_gpMapSelector_mapSelected(QString)\0"
    "car,debug\0gpDriverSelector_debugToggle(int,bool)\0"
    "on_runbutton_clicked()\0toggle\0"
    "on_randomRadioButton_toggled(bool)\0"
    "on_deterministRadioButton_toggled(bool)\0"
    "on_sequentialRadioButton_toggled(bool)\0"
    "value\0on_delaySlider_valueChanged(int)\0"
    "gpControl_carMoved()\0gpControl_carMovedWithBoost()\0"
    "gpControl_end(QString)\0gpControl_driverTimeout()\0"
    "gpControl_invalidMove()\0gpControl_syntaxError()\0"
    "on_abortbutton_clicked()\0reply\0"
    "serviceRequestFinished(QNetworkReply*)\0"
};

void GPControlView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GPControlView *_t = static_cast<GPControlView *>(_o);
        switch (_id) {
        case 0: _t->mapChanged((*reinterpret_cast< GPControl*(*)>(_a[1]))); break;
        case 1: _t->carMoved((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->driverTimeout((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->invalidMove((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->syntaxError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->serverResponse((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->start(); break;
        case 7: _t->on_gpMapSelector_mapSelected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->gpDriverSelector_debugToggle((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->on_runbutton_clicked(); break;
        case 10: _t->on_randomRadioButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_deterministRadioButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_sequentialRadioButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_delaySlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->gpControl_carMoved(); break;
        case 15: _t->gpControl_carMovedWithBoost(); break;
        case 16: _t->gpControl_end((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->gpControl_driverTimeout(); break;
        case 18: _t->gpControl_invalidMove(); break;
        case 19: _t->gpControl_syntaxError(); break;
        case 20: _t->on_abortbutton_clicked(); break;
        case 21: _t->serviceRequestFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GPControlView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GPControlView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GPControlView,
      qt_meta_data_GPControlView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GPControlView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GPControlView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GPControlView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GPControlView))
        return static_cast<void*>(const_cast< GPControlView*>(this));
    return QWidget::qt_metacast(_clname);
}

int GPControlView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void GPControlView::mapChanged(GPControl * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GPControlView::carMoved(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GPControlView::driverTimeout(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GPControlView::invalidMove(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GPControlView::syntaxError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GPControlView::serverResponse(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GPControlView::start()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
