/****************************************************************************
** Meta object code from reading C++ file 'txtmainwindow.h'
**
** Created: Sun Oct 5 00:05:31 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0-rc1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "txtmainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'txtmainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0-rc1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Txtmaiwindow[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      33,   24,   13,   13, 0x0a,
      51,   13,   13,   13, 0x08,
      58,   13,   13,   13, 0x08,
      65,   13,   13,   13, 0x08,
      74,   13,   13,   13, 0x08,
      80,   13,   13,   13, 0x08,
      87,   13,   13,   13, 0x08,
      95,   13,   13,   13, 0x08,
     103,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Txtmaiwindow[] = {
    "Txtmaiwindow\0\0newFile()\0fileName\0"
    "openFile(QString)\0open()\0save()\0"
    "saveAs()\0cut()\0copy()\0paste()\0about()\0"
    "updateMenus()\0"
};

const QMetaObject Txtmaiwindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Txtmaiwindow,
      qt_meta_data_Txtmaiwindow, 0 }
};

const QMetaObject *Txtmaiwindow::metaObject() const
{
    return &staticMetaObject;
}

void *Txtmaiwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Txtmaiwindow))
	return static_cast<void*>(const_cast< Txtmaiwindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Txtmaiwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newFile(); break;
        case 1: openFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: open(); break;
        case 3: save(); break;
        case 4: saveAs(); break;
        case 5: cut(); break;
        case 6: copy(); break;
        case 7: paste(); break;
        case 8: about(); break;
        case 9: updateMenus(); break;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
