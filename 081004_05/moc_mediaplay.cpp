/****************************************************************************
** Meta object code from reading C++ file 'mediaplay.h'
**
** Created: Sun Oct 5 00:05:18 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0-rc1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mediaplay.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mediaplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0-rc1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PlayerWidget[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      21,   13,   13,   13, 0x08,
      35,   13,   13,   13, 0x08,
      57,   53,   13,   13, 0x08,
      78,   13,   13,   13, 0x08,
     116,   96,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PlayerWidget[] = {
    "PlayerWidget\0\0open()\0catchOutput()\0"
    "pollCurrentTime()\0pos\0timeLineChanged(int)\0"
    "switchPlayState()\0exitCode,exitStatus\0"
    "mplayerEnded(int,QProcess::ExitStatus)\0"
};

const QMetaObject PlayerWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PlayerWidget,
      qt_meta_data_PlayerWidget, 0 }
};

const QMetaObject *PlayerWidget::metaObject() const
{
    return &staticMetaObject;
}

void *PlayerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PlayerWidget))
	return static_cast<void*>(const_cast< PlayerWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PlayerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: open(); break;
        case 1: catchOutput(); break;
        case 2: pollCurrentTime(); break;
        case 3: timeLineChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: switchPlayState(); break;
        case 5: mplayerEnded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
