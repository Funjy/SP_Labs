#ifndef TRIPLESONICSLASH_H
#define TRIPLESONICSLASH_H

#include <QtCore>

class TripleSonicSlash
{
public:
    TripleSonicSlash();
    static QString GetCodeMessage(DWORD errCode);
    static void CheckFalseGetError(bool toCheck);
    static void ShowError();
};

/*class Buffer<T>
{
public:
    Buffer();
    void Add(T item);
    T Get();
private:

}*/

#endif // TRIPLESONICSLASH_H
