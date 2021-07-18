/*
1�������������������������ݵ�����һ������
2������ָ���ַ��������ָ�룬�������е��ַ���ȫ����������
3���Զ��庯��ģ��memcpy�Ĺ���
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

