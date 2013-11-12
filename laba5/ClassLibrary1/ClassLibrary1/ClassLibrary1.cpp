// ֳכאגםûי DLL-פאיכ.


#include "stdafx.h"
#include "ClassLibrary1.h"
using namespace System::Text;

extern "C"
{
 int __stdcall  Calc(int A, int B, int C)
    {
		return A*B-C;
    }
void __stdcall LineAdd(const char* Str1,const char* Str2,char* Str3)
    {
		int len3 = strlen(Str1) + strlen(Str2) + 1;
		StringBuilder^ sb = gcnew StringBuilder(len3);
		sb->Append(Str1);
		sb->Append(Str2);
		System::String ^s = sb->ToString();
		pin_ptr<char> pChar = s->ToCharArray();
		Str3 = (sb->ToString());
		//strcpy_s(Str3,strlen(Str1) + 1,Str1);
		//strcat_s(Str3,len3,Str2);
    }
 int __stdcall setb(int b)
    {
		return b;
    }
}