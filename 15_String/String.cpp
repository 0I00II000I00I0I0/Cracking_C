#include "MyString.h"
#include "Wchar.h"

int main()
{
	//ÆÕÍ¨×Ö·û
	char szBuf[128] = { 0 };
	char* pCharDest = (char*)"Hello ";
	char* pCharSour = (char*)"char!!";

	MyStrcat(szBuf, pCharDest);
	MyStrcat(szBuf, pCharSour);
	printf("%s\n", szBuf);

	MyStrncat(szBuf, pCharDest, strlen(pCharDest) - 1);
	MyStrncat(szBuf, pCharSour, strlen(pCharSour) - 1);
	printf("%s\n", szBuf);

	char* pTest = (char*)"Hello";
	if (MyStrcmp(szBuf, pTest))
	{
		printf("different\n");
	}
	else
	{
		printf("same\n");
	}
	if (MyStrncmp(szBuf, pTest, strlen(pTest)))
	{
		printf("different\n");
	}
	else
	{
		printf("same\n");
	}

	MyStrcpy(szBuf, pCharSour);
	printf("%s\n", szBuf);
	MyStrncpy(szBuf, pCharDest, strlen(pCharDest) - 1);
	printf("%s\n", szBuf);

	MyStrupr(szBuf);
	printf("%s\n", szBuf);
	MyStrlwr(szBuf);
	printf("%s\n", szBuf);
	char* pSubstr = MyStrstr(szBuf, (char*)pCharSour);
	if (pSubstr == NULL)
	{
		printf("not find\n");
	}
	else
	{
		printf("%s\n", pSubstr);
	}
	int nLen = MyStrlen(szBuf);
	printf("length:%d\n", nLen);

	//¿í×Ö·û
	//setlocale(LC_ALL, "chs");
	wchar_t szwBuf[128] = { 0 };
	wchar_t* pwCharDest = (wchar_t*)L"Hello ";
	wchar_t* pwCharSour = (wchar_t*)L"Wchar!";

	Wcscat(szwBuf, pwCharDest);
	Wcscat(szwBuf, pwCharSour);
	wprintf(L"%s\n", szwBuf);

	wchar_t* pwTest = (wchar_t*)L"Wcsncat Wchar";
	Wcsncat(szwBuf, pwTest, Wcslen(pwTest));
	wprintf(L"%s\n", szwBuf);

	Wcscpy(szwBuf, pwCharSour);
	wprintf(L"%s\n", szwBuf);
	Wcsncpy(szwBuf, pwCharDest, Wcslen(pwCharDest) - 1);
	wprintf(L"%s\n", szwBuf);

	if (Wcscmp(szwBuf, pwCharDest))
	{
		printf("different\n");
	}
	else
	{
		printf("same\n");
	}

	int wlen = Wcslen(szwBuf);
	printf("%d\n", wlen);

	return 0;
}
