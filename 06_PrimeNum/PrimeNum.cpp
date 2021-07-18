/*
1、求20以内不能被3整除的数和个数
2、打印100以内的素数
3、写一个函数power(double x,int n)，返回x^n
4、求斐波那契数列第n项值,使用递归思想
5、从1~10中取出3个不同的数，共有多少种组合方式
*/
#include <iostream>
#include <math.h>

void PrintfPrimeNum()
{
	int nNum = 2;
	int nCount = 1;
	printf("%d\t", nNum);

	bool bPrime = true;
	for (nNum = 3; nNum <= 100; nNum++)
	{
		bPrime = true;
		int nEnd = (int)sqrt(nNum);
		for (int i = 2; i <= nEnd; i++)
		{
			if (nNum % i == 0)
			{
				bPrime = false;
				break;
			}
		}
		if (bPrime)
		{
			printf("%d\t", nNum);
			nCount++;
			if (nCount % 5 == 0)
			{
				printf("\n");
			}
		}
	}
	printf("总个数：%d\n", nCount);
}

double Power(double x, int n)
{
	if (0 == n)
	{
		x = 1;
	}
	if (1 == n)
	{
		x = x * 1;
	}
	if (n > 1)
	{
		x = x * Power(x, n - 1);
	}
	return x;
}

int Fibonacci(int n)
{
	if (1 == n || 2 == n)
	{
		return 1;
	}
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

//n的阶乘
int Factorial(int n)
{
	if (n > 1)
	{
		n = n * Factorial(n - 1);
	}
	return n;
}

int main()
{
	int nCount = 0;
	printf("20以内不能被3整除的数：\n");
	for (int n = 1; n <= 20; n++)
	{
		if (0 == n % 3)
		{
			continue;
		}
		printf("%d\t", n);
		nCount++;
		if (0 == nCount % 5)
		{
			printf("\n");
		}
	}
	printf("总个数：%d\n", nCount);

	printf("100以内的素数：\n");
	PrintfPrimeNum();

	printf("前20项斐波那契数列：\n");
	for (int i = 1; i <= 20; i++)
	{
		printf("%d\t", Fibonacci(i));
		if (i % 10 == 0)
		{
			printf("\n");
		}
	}

	int result = Factorial(10) / (Factorial(3) * Factorial(10 - 3));
	printf("从1~10中取出3个不同的数，一共有%d种\n", result);

	int x = 0;
	int n = 0;
	printf("输入想要计算的底数和指数，中间用空格隔开：");
	scanf_s("%d%d", &x, &n);
	result = (int)Power(x, n);
	printf("%d^%d=%d\n", x, n, result);

	system("pause");
	return 0;
}

