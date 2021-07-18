#include "Wchar.h"

int Wcscmp(wchar_t* wDest, wchar_t* wSour)
{
	while (!(*(wchar_t*)wDest - *(wchar_t*)wSour) && *wDest)
	{
		wDest++;
		wSour++;
	}
	return *(unsigned char*)wDest - *(unsigned char*)wSour;
}

wchar_t* Wcscat(wchar_t* wDest, wchar_t* wSour)
{
	while (*wDest != '\0')
	{
		wDest++;
	}
	while (*wDest == '\0' && *wSour != '\0')
	{
		*wDest = *wSour;
		wDest++;
		wSour++;
	}
	return wDest;
}

wchar_t* Wcsncat(wchar_t* wDest, wchar_t* wSour, size_t length)
{
	while (*wDest != '\0')
	{
		wDest++;
	}
	while (*wDest == '\0' && *wSour != '\0' && length != 0)
	{
		*wDest = *wSour;
		wDest++;
		wSour++;
		length--;
	}
	return wDest;
}

wchar_t* Wcscpy(wchar_t* wDest, wchar_t* wSour)
{
	while (*wSour != '\0')
	{
		*wDest = *wSour;
		wDest++;
		wSour++;
	}
	return wDest;
}

wchar_t* Wcsncpy(wchar_t* wDest, wchar_t* wSour, size_t length)
{
	while (*wSour != '\0' && length != 0)
	{
		*wDest = *wSour;
		wDest++;
		wSour++;
		length--;
	}
	return wDest;
}

size_t Wcslen(wchar_t* wString)
{
	int n = 0;
	while (*wString != '\0')
	{
		wString++;
		n++;
	}
	return n;
}

