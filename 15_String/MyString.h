#pragma once
#include <iostream>

//拼接
char* MyStrcat(char* dest, char* sour);
//拼接n个字符
char* MyStrncat(char* dest, char* sour, size_t n);
//比较
int MyStrcmp(char* dest, char* sour);
//比较n个字符
int MyStrncmp(char* dest, char* sour, size_t n);
//复制
char* MyStrcpy(char* dest, char* sour);
//复制n个字符
char* MyStrncpy(char* dest, char* sour, size_t n);
//转换为小写
char* MyStrlwr(char* str);
//转换为大写
char* MyStrupr(char* str);
//在字符串dest中查找sour第一次出现的位置
char* MyStrstr(char* dest, char* sour);
//字符串长度
size_t MyStrlen(char* str);
