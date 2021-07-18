/*
1��дһ������prime(int n)�����n����������1�����򷵻�0
2���õݹ�ķ����������
*/
#include <iostream>

int IsPrime(int number);
void PrintfPalindrome(char ch);

int main()
{
	int nRet = 0;
	int nNum = 0;
	printf("����һ������1����Ȼ����");
	scanf_s("%d", &nNum);
	nRet = IsPrime(nNum);
	switch (nRet)
	{
	case 0:
		printf("%d��������\n", nNum);
		break;
	case 1:
		printf("%d������\n", nNum);
		break;
	}

	//�õݹ�ķ����������
	char ch = 0;
	printf("����һ��СдӢ���ַ���");
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

