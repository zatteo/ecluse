/****************************************************************************
** Meta object code from reading C++ file 'porte.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tp_note/porte.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'porte.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Porte_t {
    QByteArrayData data[13];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Porte_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Porte_t qt_meta_stringdata_Porte = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Porte"
QT_MOC_LITERAL(1, 6, 9), // "etatPorte"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 13), // "positionPorte"
QT_MOC_LITERAL(4, 31, 9), // "ouverture"
QT_MOC_LITERAL(5, 41, 9), // "fermeture"
QT_MOC_LITERAL(6, 51, 5), // "arret"
QT_MOC_LITERAL(7, 57, 7), // "urgence"
QT_MOC_LITERAL(8, 65, 16), // "deplacementPorte"
QT_MOC_LITERAL(9, 82, 12), // "mettreAlarme"
QT_MOC_LITERAL(10, 95, 13), // "enleverAlarme"
QT_MOC_LITERAL(11, 109, 11), // "mettrePanne"
QT_MOC_LITERAL(12, 121, 12) // "enleverPanne"

    },
    "Porte\0etatPorte\0\0positionPorte\0ouverture\0"
    "fermeture\0arret\0urgence\0deplacementPorte\0"
    "mettreAlarme\0enleverAlarme\0mettrePanne\0"
    "enleverPanne"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Porte[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    1,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   75,    2, 0x0a /* Public */,
       5,    0,   76,    2, 0x0a /* Public */,
       6,    0,   77,    2, 0x0a /* Public */,
       7,    0,   78,    2, 0x0a /* Public */,
       8,    1,   79,    2, 0x0a /* Public */,
       9,    0,   82,    2, 0x0a /* Public */,
      10,    0,   83,    2, 0x0a /* Public */,
      11,    0,   84,    2, 0x0a /* Public */,
      12,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Int, QMetaType::Int,    2,
    QMetaType::Int, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Porte::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Porte *_t = static_cast<Porte *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->etatPorte((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->positionPorte((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: _t->ouverture(); break;
        case 3: _t->fermeture(); break;
        case 4: _t->arret(); break;
        case 5: _t->urgence(); break;
        case 6: _t->deplacementPorte((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->mettreAlarme(); break;
        case 8: _t->enleverAlarme(); break;
        case 9: _t->mettrePanne(); break;
        case 10: _t->enleverPanne(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef int (Porte::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Porte::etatPorte)) {
                *result = 0;
                return;
            }
        }
        {
            typedef int (Porte::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Porte::positionPorte)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Porte::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Porte.data,
      qt_meta_data_Porte,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Porte::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Porte::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Porte.stringdata0))
        return static_cast<void*>(const_cast< Porte*>(this));
    return QObject::qt_metacast(_clname);
}

int Porte::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
int Porte::etatPorte(int _t1)
{
    int _t0 = int();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
int Porte::positionPorte(int _t1)
{
    int _t0 = int();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
