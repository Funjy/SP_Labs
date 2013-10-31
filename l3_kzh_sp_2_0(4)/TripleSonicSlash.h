#ifndef TRIPLESONICSLASH_H
#define TRIPLESONICSLASH_H

#include <QtCore>

class TripleSonicSlash
{
public:
    TripleSonicSlash();
    static QString GetLastErrorMessage();
    static QString GetCodeMessage(DWORD errCode);
    static bool CheckFalseGetError(bool toCheck);
    static void ShowError();
};

class MyException : public QException
{
public:
    MyException();
    MyException(QString message);
    ~MyException() throw() {}
    QString what() throw();
    void SetMessage(QString message) throw();
private:
    QString _message;
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
