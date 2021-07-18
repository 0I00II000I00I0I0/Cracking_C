/*
* 1���������
* 2���۰����
* 3�����ӳ������⣬�ֱ�ʵ�����Խ׺ͳ���������
���ӵ�һ��ժ�����ɸ����ӣ�����һ���һ�����Ժ�ÿ�춼����ǰһ��ʣ�µ�һ���һ��������n�컹ʣ��һ�����ӣ�����ӵ�һ��ժ�˶��ٸ����ӡ�
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
	printf("����������飺\n");
	for (int i = 0; i < nLength; i++)
	{
		printf("%d ", aryNumber[i]);
	}
	printf("\n");

	QuickSort(aryNumber, 0, nLength - 1);
	printf("������������\n");
	for (int i = 0; i < nLength; i++)
	{
		printf("%d ", aryNumber[i]);
	}
	printf("\n");

	int n = 0;
	printf("�۰���ҵ�����");
	scanf_s("%d", &n);
	int result = HalfSearch(n, aryNumber, nLength);
	printf("�ǵݹ��۰���ҽ����\n");
	printf("%d\n", result);
	result = RecursionSearch(0, nLength - 1, n, aryNumber);
	printf("�ݹ��۰���ҽ����\n");
	printf("%d\n", result);

	printf("���ӳ������⣺\n");
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

/*�����������*/
void RandomArray(int* buf, int len)
{
	srand((int)time(NULL));
	for (int i = 0; i < len; i++)
	{
		buf[i] = rand() % 100;
	}
}

/*��������*/
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

/*ʹ�õݹ鷽ʽʵ���۰����*/
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

/*ʹ�÷ǵݹ鷽ʽʵ���۰����*/
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

/*���ӳ������⣬�ֱ�ʵ�����Խ׺ͳ���������*/
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
