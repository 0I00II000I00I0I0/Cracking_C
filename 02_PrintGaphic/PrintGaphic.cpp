/*
1����ӡ�������
2����ӡ�����״Ϊֱ�������εľžų˷���
3����ȡһ��������5λ�����������ֱ��ӡ��ÿһλ�����λ�����������ӡ���
*/
#include <iostream>
#include <math.h>

void PrintfDiamond(int n);
void PrintfTable();
void PrintfCount();

int main()
{
	printf("9�����Σ�\n");
	PrintfDiamond(9);

	printf("�žų˷���\n");
	PrintfTable();

	PrintfCount();

	return 0;
}

void PrintfTable()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%d ", i, j, i * j);
		}
		printf("\n");
	}
}

void PrintfDiamond(int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < abs(n / 2 - i); j++)
		{
			printf(" ");
		}
		printf("*");
		for (j = 0; j < n - 2 * abs(n / 2 - i) - 2; j++)
		{
			printf(" ");
		}
		if (j != 0)
		{
			printf("*");
		}
		printf("\n");
	}
}

void PrintfCount()
{
	int nNum = 0;
	int nCount = 0;
	int nTemp = 0;
	int aryNum[5] = { 0 };

	printf("������һ��������5λ����������");
	scanf_s("%d", &nNum);
	while (nNum >= 100000)
	{
		printf("���볬����Χ�����������룺");
		scanf_s("%d", &nNum);
	}

	for (int i = 0; i < 5; i++)
	{
		nTemp = (int)(nNum / (10000 / pow(10, i)));
		if (nTemp != 0)
		{
			for (int j = i; j < 5; j++)
			{
				nTemp = (int)(nNum / (10000 / pow(10, j)));
				nNum = nNum % (int)(10000 / pow(10, j));
				aryNum[j - i] = nTemp;
				nCount++;
				printf("%d ", aryNum[j - i]);
			}
			i++;
		}
	}

	printf("����һ��%dλ��\n", nCount);
	printf("���������");
	for (int i = nCount; i > 0; i--)
	{
		printf("%d", aryNum[i - 1]);
	}
	printf("\n");
}
