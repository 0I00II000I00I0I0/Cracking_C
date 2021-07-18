/*
1������100�Ľ׳ˣ�ʵ�ִ�������
2��˼·����Ϊ����100�Ľ׳� , ����100���ڵ����������˻��������ֵ������ 10000
100*99=9900��9900*98=970200������10000ȡ���0200������10000��97�����ŷֱ�*97
*/
#include <stdio.h>

void Factorial(int nNum)
{
	int aryResult[128];
	int nCarry = 0;
	int nTemp = 1;
	aryResult[0] = 1;
	int nLength = 1;
	int j = 0;

	for (int i = nNum; i > 1; i--)
	{
		nCarry = 0;
		for (j = 0; j < nLength; j++)
		{
			nTemp = aryResult[j] * i + nCarry;
			aryResult[j] = nTemp % 10000;
			nCarry = nTemp / 10000;
		}
		aryResult[j] = nCarry;
		if (nCarry > 0)
		{
			nLength++;
		}
	}
	printf("%d", aryResult[nLength - 1]);
	for (int i = nLength - 2; i >= 0; i--)
	{
		printf("%04d", aryResult[i]);
	}
	printf("\n");
}

int main()
{
	int nNum = 100;
	Factorial(nNum);
}

