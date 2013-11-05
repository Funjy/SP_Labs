#-------------------------------------------------
#
# Project created by QtCreator 2013-10-01T15:34:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = l3_kzh_sp
TEMPLATE = app


SOURCES += main.cpp\
    fileworker.cpp \
    createfiledialog.cpp \
    constants.cpp \
    supportclasses.cpp \
    TripleSonicSlash.cpp \
    anothermainwindow.cpp \
    CreateDirDialog.cpp \
    DirWorker.cpp \
    megathread.cpp \
    ThreadWindow.cpp

HEADERS  += \
    fileworker.h \
    createfiledialog.h \
    constants.h \
    supportclasses.h \
    TripleSonicSlash.h \
    anothermainwindow.h \
    CreateDirDialog.h \
    DirWorker.h \
    megathread.h \
    ThreadWindow.h

FORMS    += mainwindow.ui \
    createfiledialog.ui \
    anothermainwindow.ui \
    CreateDirDialog.ui \
    ThreadWindow.ui
