#pragma once

//比较
int Wcscmp(wchar_t* wDest, wchar_t* wSour);

//拼接
wchar_t* Wcscat(wchar_t* wDest, wchar_t* wSour);

//拼接n个宽字符
wchar_t* Wcsncat(wchar_t* wDest, wchar_t* wSour, size_t length);

//复制
wchar_t* Wcscpy(wchar_t* wDest, wchar_t* wSour);

//复制n个宽字符
wchar_t* Wcsncpy(wchar_t* wDest, wchar_t* wSour, size_t length);

//宽字符串长度
size_t Wcslen(wchar_t* wString);
