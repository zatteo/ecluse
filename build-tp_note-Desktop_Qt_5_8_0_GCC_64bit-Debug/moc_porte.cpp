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
    QByteArrayData data[16];
    char stringdata0[163];
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
QT_MOC_LITERAL(4, 31, 11), // "alarmePorte"
QT_MOC_LITERAL(5, 43, 9), // "ouverture"
QT_MOC_LITERAL(6, 53, 9), // "fermeture"
QT_MOC_LITERAL(7, 63, 5), // "arret"
QT_MOC_LITERAL(8, 69, 7), // "urgence"
QT_MOC_LITERAL(9, 77, 16), // "deplacementPorte"
QT_MOC_LITERAL(10, 94, 12), // "mettreAlarme"
QT_MOC_LITERAL(11, 107, 13), // "enleverAlarme"
QT_MOC_LITERAL(12, 121, 11), // "mettrePanne"
QT_MOC_LITERAL(13, 133, 12), // "enleverPanne"
QT_MOC_LITERAL(14, 146, 7), // "isPanne"
QT_MOC_LITERAL(15, 154, 8) // "isAlarme"

    },
    "Porte\0etatPorte\0\0positionPorte\0"
    "alarmePorte\0ouverture\0fermeture\0arret\0"
    "urgence\0deplacementPorte\0mettreAlarme\0"
    "enleverAlarme\0mettrePanne\0enleverPanne\0"
    "isPanne\0isAlarme"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Porte[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       3,    1,   87,    2, 0x06 /* Public */,
       4,    1,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   93,    2, 0x0a /* Public */,
       6,    0,   94,    2, 0x0a /* Public */,
       7,    0,   95,    2, 0x0a /* Public */,
       8,    0,   96,    2, 0x0a /* Public */,
       9,    1,   97,    2, 0x0a /* Public */,
      10,    1,  100,    2, 0x0a /* Public */,
      11,    0,  103,    2, 0x0a /* Public */,
      12,    0,  104,    2, 0x0a /* Public */,
      13,    0,  105,    2, 0x0a /* Public */,
      14,    0,  106,    2, 0x0a /* Public */,
      15,    0,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Int, QMetaType::Int,    2,
    QMetaType::Int, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,

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
        case 2: _t->alarmePorte((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ouverture(); break;
        case 4: _t->fermeture(); break;
        case 5: _t->arret(); break;
        case 6: _t->urgence(); break;
        case 7: _t->deplacementPorte((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->mettreAlarme((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->enleverAlarme(); break;
        case 10: _t->mettrePanne(); break;
        case 11: _t->enleverPanne(); break;
        case 12: { bool _r = _t->isPanne();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { bool _r = _t->isAlarme();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
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
        {
            typedef void (Porte::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Porte::alarmePorte)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Porte::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Porte.data,
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
    return QThread::qt_metacast(_clname);
}

int Porte::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
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

// SIGNAL 2
void Porte::alarmePorte(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
