/*
1、计算100的阶乘，实现大数运算
2、思路：因为是求100的阶乘 , 所以100以内的两个数作乘积运算最大值不超过 10000
100*99=9900，9900*98=970200，超过10000取余得0200，除以10000得97，接着分别*97
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

