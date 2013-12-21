/****************************************************************************
** Meta object code from reading C++ file 'piechartqt.h'
**
** Created: Sat Nov 17 11:48:10 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "piechartqt.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'piechartqt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Arena[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      23,    6,    6,    6, 0x0a,
      36,    6,    6,    6, 0x0a,
      52,    6,    6,    6, 0x0a,
      64,    6,    6,    6, 0x0a,
      76,    6,    6,    6, 0x0a,
      87,    6,    6,    6, 0x0a,
      98,    6,    6,    6, 0x0a,
     106,    6,    6,    6, 0x0a,
     118,    6,    6,    6, 0x0a,
     126,    6,    6,    6, 0x0a,
     136,    6,    6,    6, 0x0a,
     148,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Arena[] = {
    "Arena\0\0openrecording()\0backtomain()\0"
    "transferinput()\0startTree()\0startTrie()\0"
    "nextCall()\0prevCall()\0reset()\0bCall(fax*)\0"
    "quitA()\0resetIt()\0preSearch()\0"
    "completeSearch()\0"
};

const QMetaObject Arena::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Arena,
      qt_meta_data_Arena, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Arena::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Arena::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Arena::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Arena))
        return static_cast<void*>(const_cast< Arena*>(this));
    return QWidget::qt_metacast(_clname);
}

int Arena::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openrecording(); break;
        case 1: backtomain(); break;
        case 2: transferinput(); break;
        case 3: startTree(); break;
        case 4: startTrie(); break;
        case 5: nextCall(); break;
        case 6: prevCall(); break;
        case 7: reset(); break;
        case 8: bCall((*reinterpret_cast< fax*(*)>(_a[1]))); break;
        case 9: quitA(); break;
        case 10: resetIt(); break;
        case 11: preSearch(); break;
        case 12: completeSearch(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
