#pragma once

//�Ƚ�
int Wcscmp(wchar_t* wDest, wchar_t* wSour);

//ƴ��
wchar_t* Wcscat(wchar_t* wDest, wchar_t* wSour);

//ƴ��n�����ַ�
wchar_t* Wcsncat(wchar_t* wDest, wchar_t* wSour, size_t length);

//����
wchar_t* Wcscpy(wchar_t* wDest, wchar_t* wSour);

//����n�����ַ�
wchar_t* Wcsncpy(wchar_t* wDest, wchar_t* wSour, size_t length);

//���ַ�������
size_t Wcslen(wchar_t* wString);
