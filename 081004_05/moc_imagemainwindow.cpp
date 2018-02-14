/****************************************************************************
** Meta object code from reading C++ file 'imagemainwindow.h'
**
** Created: Sun Oct 5 00:04:52 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0-rc1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "imagemainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagemainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0-rc1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      24,   11,   11,   11, 0x0a,
      31,   11,   11,   11, 0x0a,
      38,   11,   11,   11, 0x0a,
      51,   11,   11,   11, 0x0a,
      65,   11,   11,   11, 0x0a,
      74,   11,   11,   11, 0x0a,
      84,   11,   11,   11, 0x0a,
      95,   11,   11,   11, 0x0a,
     106,   11,   11,   11, 0x0a,
     116,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0selectDir()\0next()\0prev()\0"
    "rotateLeft()\0rotateRight()\0zoomIn()\0"
    "zoomOut()\0sdcardir()\0udiskdir()\0"
    "present()\0bluetooth()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
	return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: selectDir(); break;
        case 1: next(); break;
        case 2: prev(); break;
        case 3: rotateLeft(); break;
        case 4: rotateRight(); break;
        case 5: zoomIn(); break;
        case 6: zoomOut(); break;
        case 7: sdcardir(); break;
        case 8: udiskdir(); break;
        case 9: present(); break;
        case 10: bluetooth(); break;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
