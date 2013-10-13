#ifndef DIRWORKER_H
#define DIRWORKER_H
#include <QtCore>

#include "TripleSonicSlash.h"

class DirWorker
{
public:
    DirWorker();
    bool CreateNewDir(QString ndirName);
    void DeleteDir(QString dirName);
    void SetCurrentDir(QString dirName);
    QList<QString>* FindFiles(QString mask);
    static QString RootDir;
};

#endif // DIRWORKER_H
