/*
* 1、随机数组
* 2、折半查找
* 3、猴子吃桃问题，分别实现线性阶和常量阶运算
猴子第一天摘下若干个桃子，吃了一半多一个，以后每天都吃了前一天剩下的一半多一个，到第n天还剩下一个桃子，求猴子第一天摘了多少个桃子。
*/
#include <iostream>
#include <math.h>
#include <time.h>

void RandomArray(int* buf, int len);
void QuickSort(int* aryNum, int left, int right);
int HalfSearch(int n, int* buf, int length);
int RecursionSearch(int left, int right, int n, int* buf);
int LinearPeach(int day, int n);
int ConstantPeach(int day, int n);

int main()
{
	int aryNumber[16] = { 0 };
	int nLength = sizeof(aryNumber) / sizeof(aryNumber[0]);
	RandomArray(aryNumber, nLength);
	printf("生成随机数组：\n");
	for (int i = 0; i < nLength; i++)
	{
		printf("%d ", aryNumber[i]);
	}
	printf("\n");

	QuickSort(aryNumber, 0, nLength - 1);
	printf("快速排序结果：\n");
	for (int i = 0; i < nLength; i++)
	{
		printf("%d ", aryNumber[i]);
	}
	printf("\n");

	int n = 0;
	printf("折半查找的数：");
	scanf_s("%d", &n);
	int result = HalfSearch(n, aryNumber, nLength);
	printf("非递归折半查找结果：\n");
	printf("%d\n", result);
	result = RecursionSearch(0, nLength - 1, n, aryNumber);
	printf("递归折半查找结果：\n");
	printf("%d\n", result);

	printf("猴子吃桃问题：\n");
	for (int i = 1; i < 10; i++)
	{
		int num = LinearPeach(i, 1);
		printf("%d\t", num);
	}
	printf("\n");
	for (int i = 1; i < 10; i++)
	{
		int num = ConstantPeach(i, 1);
		printf("%d\t", num);
	}

	return 0;
}

/*创建随机数组*/
void RandomArray(int* buf, int len)
{
	srand((int)time(NULL));
	for (int i = 0; i < len; i++)
	{
		buf[i] = rand() % 100;
	}
}

/*快速排序*/
void QuickSort(int* buf, int left, int right)
{
	int i = left;
	int j = right;
	int base = buf[left];

	if (left < right)
	{
		while (left < right)
		{
			while (left < right && base <= buf[right])
			{
				right--;
			}
			buf[left] = buf[right];
			while (left < right && base >= buf[left])
			{
				left++;
			}
			buf[right] = buf[left];
		}
		buf[left] = base;
		QuickSort(buf, i, right - 1);
		QuickSort(buf, left + 1, j);
	}
}

/*使用递归方式实现折半查找*/
int RecursionSearch(int left, int right, int n, int* buf)
{
	int mid = (left + right) / 2;

	if (left <= right)
	{
		if (buf[mid] < n)
		{
			left = mid + 1;
			return RecursionSearch(left, right, n, buf);
		}
		else if (buf[mid] > n)
		{
			right = mid - 1;
			return RecursionSearch(left, right, n, buf);
		}
		else
		{
			return mid;
		}
	}
	else
	{
		return -1;
	}
}

/*使用非递归方式实现折半查找*/
int HalfSearch(int n, int* buf, int length)
{
	int left = 0;
	int right = length - 1;
	int mid = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (buf[mid] > n)
		{
			right = mid - 1;
		}
		else if (buf[mid] < n)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

/*猴子吃桃问题，分别实现线性阶和常量阶运算*/
int LinearPeach(int day, int n)
{
	for (int i = 1; i <= day; i++)
	{
		n = (n + 1) * 2;
	}
	return n;
}

int ConstantPeach(int day, int n)
{
	n = (n + 2) * (int)pow(2, day) - 2;
	return n;
}
