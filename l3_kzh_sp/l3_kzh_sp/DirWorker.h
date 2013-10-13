#ifndef DIRWORKER_H
#define DIRWORKER_H
#include <QtCore>

class DirWorker
{
public:
    DirWorker();
    void CreateDir(QString dirName);
    void DeleteDir(QString dirName);
    void SetCurrentDir(QString dirName);
    QList<QString>* FindFiles(QString mask);
};

#endif // DIRWORKER_H
