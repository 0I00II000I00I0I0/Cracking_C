/*
��ȡ�ļ���ȡѧ��������ʵ�����������һ�ֿ��ظ���һ�ֲ����ظ�
*/
#include <iostream>
#include <time.h>

int main()
{
	char* szPath = (char*)"randomname.txt";
	FILE* file = NULL;
	errno_t err = fopen_s(&file, szPath, "r");
	if (err != 0 || file == NULL)
	{
		return 1;
	}

	int n = 0;
	char aryName[16][16] = { 0 };
	while (!feof(file))
	{
		char* p = fgets(aryName[n], 16, file);
		if (p == NULL)
		{
			break;
		}
		n++;
	};
	fclose(file);

	int nSelect = 0;
	printf("1�����ظ�����\n2�����ظ�����\n��ѡ��");
	scanf_s("%d", &nSelect);
	int nLen = n;
	int nRandNum = 0;
	char cChoose = '\0';
	char* szTemp = NULL;
	srand((unsigned)time(NULL));

	n = 0;
	switch (nSelect)
	{
	case 1:
		do
		{
			nRandNum = rand() % nLen;
			n++;
			printf("��%d�ε���:%s\n", n, aryName[nRandNum]);
			printf("�Ƿ��������(y/n):");
			rewind(stdin);
			scanf_s("%c", &cChoose, 1);
		} while (cChoose == 'y');
		break;

	case 2:
		do
		{
			nRandNum = rand() % (nLen - n);
			n++;
			printf("��%d�ε���:%s\n", n, aryName[nRandNum]);
			if (n >= nLen)
			{
				break;
			}
			szTemp = aryName[nRandNum];
			memcpy(aryName[nRandNum], aryName[nLen - n], 16);
			memcpy(aryName[nLen - n], szTemp, 16);
			printf("�Ƿ��������(y/n):");
			rewind(stdin);
			scanf_s("%c", &cChoose, 1);
		} while (cChoose == 'y');
		break;
	}

	return 0;
}
