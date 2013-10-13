#ifndef FILEWORKER_H
#define FILEWORKER_H
//Qt
#include <QString>
//Local
#include "supportclasses.h"
#include "windows.h"
#include "TripleSonicSlash.h"

class FileWorker
{
public:
    FileWorker();
    static void OpenCreateFile(FileCreateParams* params = NULL);
    static void OpenCreateFile(QString fileName);
    static void CloseOpenedFile(FileCreateParams* params);
    static void DeleteExistingFile(FileCreateParams* params);
    static void UpdateFile(FileCreateParams* file);

};

#endif // FILEWORKER_H
