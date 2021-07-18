/*
1����20���ڲ��ܱ�3���������͸���
2����ӡ100���ڵ�����
3��дһ������power(double x,int n)������x^n
4����쳲��������е�n��ֵ,ʹ�õݹ�˼��
5����1~10��ȡ��3����ͬ���������ж�������Ϸ�ʽ
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
	printf("�ܸ�����%d\n", nCount);
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

//n�Ľ׳�
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
	printf("20���ڲ��ܱ�3����������\n");
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
	printf("�ܸ�����%d\n", nCount);

	printf("100���ڵ�������\n");
	PrintfPrimeNum();

	printf("ǰ20��쳲��������У�\n");
	for (int i = 1; i <= 20; i++)
	{
		printf("%d\t", Fibonacci(i));
		if (i % 10 == 0)
		{
			printf("\n");
		}
	}

	int result = Factorial(10) / (Factorial(3) * Factorial(10 - 3));
	printf("��1~10��ȡ��3����ͬ������һ����%d��\n", result);

	int x = 0;
	int n = 0;
	printf("������Ҫ����ĵ�����ָ�����м��ÿո������");
	scanf_s("%d%d", &x, &n);
	result = (int)Power(x, n);
	printf("%d^%d=%d\n", x, n, result);

	system("pause");
	return 0;
}

