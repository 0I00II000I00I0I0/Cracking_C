/*
1、写一个函数prime(int n)，如果n是素数返回1，否则返回0
2、用递归的方法输出回文
*/
#include <iostream>

int IsPrime(int number);
void PrintfPalindrome(char ch);

int main()
{
	int nRet = 0;
	int nNum = 0;
	printf("输入一个大于1的自然数：");
	scanf_s("%d", &nNum);
	nRet = IsPrime(nNum);
	switch (nRet)
	{
	case 0:
		printf("%d不是素数\n", nNum);
		break;
	case 1:
		printf("%d是素数\n", nNum);
		break;
	}

	//用递归的方法输出回文
	char ch = 0;
	printf("输入一个小写英文字符：");
	rewind(stdin);
	scanf_s("%c", &ch, 1);
	PrintfPalindrome(ch);

	return 0;
}

int IsPrime(int number)
{
	int i = 2;
	int nEnd = (int)sqrt(number);
	for (i; i <= nEnd; i++)
	{
		if (number % i == 0)
		{
			break;
		}
	}
	if (i > nEnd)
	{
		return 1;
	}
	return 0;
}

void PrintfPalindrome(char ch)
{
	if ('a' == ch)
	{
		printf("%c", ch);
	}
	if (ch > 'a')
	{
		printf("%c", ch);
		PrintfPalindrome(ch - 1);
		printf("%c", ch);
	}
}

