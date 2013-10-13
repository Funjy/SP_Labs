//#include "mainwindow.h"
#include <QApplication>
#include "anothermainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AnotherMainWindow w;
    w.show();

    return a.exec();
}
