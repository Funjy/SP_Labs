// ClassLibrary1.h
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>

#ifndef _ClassLibrary1_H_
#define _ClassLibrary1_H_

extern "C" 
{
	
    __declspec(dllexport) int __stdcall  Calc(int A, int B, int C);
    __declspec(dllexport) void __stdcall LineAdd(const char* Str1,const char* Str2,char* Str3);
    __declspec(dllexport) int __stdcall setb(int b);
	//__declspec(dllexport) double mas[3][3] = {{1,2,3},{1,2,3},{1,2,3}};

}

#endif //dll