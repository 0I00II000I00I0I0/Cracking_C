#pragma once
#include <iostream>

//ƴ��
char* MyStrcat(char* dest, char* sour);
//ƴ��n���ַ�
char* MyStrncat(char* dest, char* sour, size_t n);
//�Ƚ�
int MyStrcmp(char* dest, char* sour);
//�Ƚ�n���ַ�
int MyStrncmp(char* dest, char* sour, size_t n);
//����
char* MyStrcpy(char* dest, char* sour);
//����n���ַ�
char* MyStrncpy(char* dest, char* sour, size_t n);
//ת��ΪСд
char* MyStrlwr(char* str);
//ת��Ϊ��д
char* MyStrupr(char* str);
//���ַ���dest�в���sour��һ�γ��ֵ�λ��
char* MyStrstr(char* dest, char* sour);
//�ַ�������
size_t MyStrlen(char* str);
