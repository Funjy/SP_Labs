/****************************************************************************
** Meta object code from reading C++ file 'ThreadWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../l3_kzh_sp_2_0(4)/ThreadWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThreadWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ThreadWindow_t {
    QByteArrayData data[9];
    char stringdata[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ThreadWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ThreadWindow_t qt_meta_stringdata_ThreadWindow = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 12),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 24),
QT_MOC_LITERAL(4, 52, 25),
QT_MOC_LITERAL(5, 78, 36),
QT_MOC_LITERAL(6, 115, 4),
QT_MOC_LITERAL(7, 120, 14),
QT_MOC_LITERAL(8, 135, 4)
    },
    "ThreadWindow\0WindowClosed\0\0"
    "on_RunStopButton_clicked\0"
    "on_ChangePriority_clicked\0"
    "on_ThreadSelector_currentTextChanged\0"
    "arg1\0on_SetNiceText\0text\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08,
       4,    0,   41,    2, 0x08,
       5,    1,   42,    2, 0x08,
       7,    1,   45,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void ThreadWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ThreadWindow *_t = static_cast<ThreadWindow *>(_o);
        switch (_id) {
        case 0: _t->WindowClosed(); break;
        case 1: _t->on_RunStopButton_clicked(); break;
        case 2: _t->on_ChangePriority_clicked(); break;
        case 3: _t->on_ThreadSelector_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_SetNiceText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ThreadWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadWindow::WindowClosed)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ThreadWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ThreadWindow.data,
      qt_meta_data_ThreadWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *ThreadWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadWindow.stringdata))
        return static_cast<void*>(const_cast< ThreadWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ThreadWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ThreadWindow::WindowClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE