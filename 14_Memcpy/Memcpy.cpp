/*
1、将程序参数倒序输出，并传递调用另一个程序
2、利用指向字符串数组的指针，将数组中的字符串全部连接起来
3、自定义函数模仿memcpy的功能
*/
#include <iostream>

void* MyMemcpy(void* dst, void* src, int n);

int main(int argc, char* argv[], char* envp[])
{
	printf("caller parameter:\n");
	for (int i = argc - 1; i >= 0; i--)
	{
		puts(argv[i]);
	}
	system("pause");

	char szPath[256] = "..\\Debug\\14_CalledProgram.exe";
	char** ppString = argv;
	char szBuf[256] = { 0 };
	//strcpy_s(szBuf, *ppString + 1);
	for (int i = 1; i <= argc - 1; i++)
	{
		strcat_s(szBuf, " ");
		strcat_s(szBuf, *(ppString + i));
	}

	if (argc == 1)
	{
		system(szPath);
	}
	else
	{
		strcat_s(szPath, szBuf);
		system(szPath);
	}

	char szString[256] = { 0 };
	MyMemcpy(szString, szPath, strlen(szPath));
	printf("called cmd:\n");
	printf("%s\n", szString);

	return 0;
}

void* MyMemcpy(void* dest, void* sour, int length)
{
	if (dest == NULL || sour == NULL || length <= 0)
	{
		return NULL;
	}
	char* pDest = (char*)dest;
	char* pSour = (char*)sour;
	if (pSour < pDest && pDest < pSour + length)
	{
		pDest = pDest + length - 1;
		pSour = pSour + length - 1;
		while (length--)
		{
			*pDest = *pSour;
			pDest--;
			pSour--;
		}
	}
	else
	{
		while (length--)
		{
			*pDest = *pSour;
			pDest++;
			pSour++;
		}
	}
	return dest;
}

