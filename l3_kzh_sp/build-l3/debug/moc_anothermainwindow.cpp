/****************************************************************************
** Meta object code from reading C++ file 'anothermainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../l3_kzh_sp_2_0(4)/anothermainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'anothermainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AnotherMainWindow_t {
    QByteArrayData data[17];
    char stringdata[353];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AnotherMainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AnotherMainWindow_t qt_meta_stringdata_AnotherMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 23),
QT_MOC_LITERAL(2, 42, 0),
QT_MOC_LITERAL(3, 43, 28),
QT_MOC_LITERAL(4, 72, 22),
QT_MOC_LITERAL(5, 95, 20),
QT_MOC_LITERAL(6, 116, 21),
QT_MOC_LITERAL(7, 138, 27),
QT_MOC_LITERAL(8, 166, 21),
QT_MOC_LITERAL(9, 188, 36),
QT_MOC_LITERAL(10, 225, 16),
QT_MOC_LITERAL(11, 242, 4),
QT_MOC_LITERAL(12, 247, 26),
QT_MOC_LITERAL(13, 274, 26),
QT_MOC_LITERAL(14, 301, 23),
QT_MOC_LITERAL(15, 325, 21),
QT_MOC_LITERAL(16, 347, 4)
    },
    "AnotherMainWindow\0on_CreateButton_clicked\0"
    "\0on_CreateFileDialog_accepted\0"
    "on_CloseButton_clicked\0on_CreateDir_clicked\0"
    "on_CreateDir_accepted\0on_UpdateFileButton_clicked\0"
    "on_CurrentDir_changed\0"
    "on_OpenedFilesList_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0on_changeDirButton_clicked\0"
    "on_deleteDirButton_clicked\0"
    "on_DoTaskButton_clicked\0on_ThreadWindowClosed\0"
    "arg1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnotherMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08,
       3,    0,   75,    2, 0x08,
       4,    0,   76,    2, 0x08,
       5,    0,   77,    2, 0x08,
       6,    0,   78,    2, 0x08,
       7,    0,   79,    2, 0x08,
       8,    0,   80,    2, 0x08,
       9,    1,   81,    2, 0x08,
      12,    0,   84,    2, 0x08,
      13,    0,   85,    2, 0x08,
      14,    0,   86,    2, 0x08,
      15,    1,   87,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void AnotherMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AnotherMainWindow *_t = static_cast<AnotherMainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_CreateButton_clicked(); break;
        case 1: _t->on_CreateFileDialog_accepted(); break;
        case 2: _t->on_CloseButton_clicked(); break;
        case 3: _t->on_CreateDir_clicked(); break;
        case 4: _t->on_CreateDir_accepted(); break;
        case 5: _t->on_UpdateFileButton_clicked(); break;
        case 6: _t->on_CurrentDir_changed(); break;
        case 7: _t->on_OpenedFilesList_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->on_changeDirButton_clicked(); break;
        case 9: _t->on_deleteDirButton_clicked(); break;
        case 10: _t->on_DoTaskButton_clicked(); break;
        case 11: _t->on_ThreadWindowClosed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AnotherMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AnotherMainWindow.data,
      qt_meta_data_AnotherMainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *AnotherMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnotherMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AnotherMainWindow.stringdata))
        return static_cast<void*>(const_cast< AnotherMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AnotherMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
