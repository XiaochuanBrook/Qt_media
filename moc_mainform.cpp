/****************************************************************************
** Meta object code from reading C++ file 'mainform.h'
**
** Created: Wed May 7 16:52:45 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0-rc1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0-rc1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Mainform[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      33,    9,    9,    9, 0x0a,
      53,    9,    9,    9, 0x0a,
      73,    9,    9,    9, 0x0a,
      95,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Mainform[] = {
    "Mainform\0\0imagebrowser_clicked()\0"
    "mp3player_clicked()\0aviplayer_clicked()\0"
    "textbrowser_clicked()\0daytime_clicked()\0"
};

const QMetaObject Mainform::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Mainform,
      qt_meta_data_Mainform, 0 }
};

const QMetaObject *Mainform::metaObject() const
{
    return &staticMetaObject;
}

void *Mainform::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Mainform))
	return static_cast<void*>(const_cast< Mainform*>(this));
    return QWidget::qt_metacast(_clname);
}

int Mainform::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: imagebrowser_clicked(); break;
        case 1: mp3player_clicked(); break;
        case 2: aviplayer_clicked(); break;
        case 3: textbrowser_clicked(); break;
        case 4: daytime_clicked(); break;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
