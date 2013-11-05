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
    static FileCreateParams* OpenCreateFile(QString fileName);
    static void CreateMappingFile(FileCreateParams* params = NULL);
    static void CloseOpenedFile(FileCreateParams* params);
    static void CloseOpenedMapping(FileCreateParams* params);
    static void DeleteExistingFile(FileCreateParams* params);
    static void UpdateFile(FileCreateParams* file);
    static void SwapSymbols(FileCreateParams* params, char toFind, char toSwap, int interval = 0);

};

#endif // FILEWORKER_H
