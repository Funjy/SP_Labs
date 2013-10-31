#ifndef DIRWORKER_H
#define DIRWORKER_H
#include <QtCore>

#include "TripleSonicSlash.h"

class DirWorker
{
public:
    DirWorker();
    static bool CreateNewDir(QString ndirName, bool setCurrent = false);
    static bool DeleteDir(QString dirName);
    static bool SetCurrentDir(QString dirName);
    static void FindFiles(QString directory, QString mask, QList<QString>* foundFiles);
    static QString RootDir;
    static QString CurrentDir();
    enum OperationType
    {
        Create,
        SetCurrent,
        Delete,
        FromDir,
        ToDir
    };
private:
    static QString _currentDir;
};

#endif // DIRWORKER_H
