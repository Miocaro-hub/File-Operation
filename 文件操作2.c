#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//6.文件的打开和关闭
//文件在读写之前应该先打开文件,在使用结束后应该关闭文件
//在编写程序的时候,在打开文件的同时,都会返回一个FILE*的指针变量指向该文件,也相当于建立了指针和文件的关系

//ANSIC规定使用fopen函数来打开文件,fclose来关闭文件
//FILE* fopen(const char* filename , const char* mode);
//int fclose (FILE* stream);