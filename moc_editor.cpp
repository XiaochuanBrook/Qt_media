/****************************************************************************
** Meta object code from reading C++ file 'editor.h'
**
** Created: Wed May 7 16:52:37 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0-rc1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "editor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0-rc1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Editor[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Editor[] = {
    "Editor\0\0documentWasModified()\0"
};

const QMetaObject Editor::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_Editor,
      qt_meta_data_Editor, 0 }
};

const QMetaObject *Editor::metaObject() const
{
    return &staticMetaObject;
}

void *Editor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Editor))
	return static_cast<void*>(const_cast< Editor*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int Editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: documentWasModified(); break;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
