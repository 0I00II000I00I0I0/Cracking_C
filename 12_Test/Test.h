#pragma once
#include <stdio.h>
/*
1、写一个函数ChangeArray(int array[],int n)，可以将数组中的n个元素逆序存放。
2、写一个函数ChangeString(char str[])，实现字符串中字符的互换，如abcde换成edcba。
3、二维数组中存放学号和平均分，按照平均分从高到低的顺序输出学号和平均分。提示：对平均分排序，当元素互换时，学号元素对应互换。
4、应用数组实现输入年year、月month、日date，计算该日期是这年的第几天。
5、提示：定义二维数组DaysOfMonth[2][12]，数组第一行由非闰年的12个月的天数组成，第二行由闰年12个月的天数组成，
	闰年时i为1、非闰年时i为0，累计DaysOfMonth[i][0]到DaysOfMonth[i][month-1]的天数，再加上day，得到总天数。
*/
void ExchangeArray(int array[], int n);
void ExchangeString(char array[]);
void ScoreSort(int array[][2], int n);
int GetTheDay(int year, int month, int day);

void ExchangeArray(int array[], int n)
{
	int nTemp = 0;
	for (int i = 0; i <= n / 2; i++)
	{
		nTemp = *(array + i);
		*(array + i) = *(array + n - 1 - i);
		*(array + n - 1 - i) = nTemp;
	}
	return;
}

void ExchangeString(char array[])
{
	int n = 0;
	while (*(array + n) != '\0')
	{
		n++;
	}
	int nTemp = 0;
	for (int i = 0; i <= n / 2; i++)
	{
		nTemp = *(array + i);
		*(array + i) = *(array + n - 1 - i);
		*(array + n - 1 - i) = nTemp;
	}
	return;
}

void ScoreSort(int array[][2], int n)
{
	int arrTemp[2] = { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (array[j][1] < array[n - 1 - i][1])
			{
				arrTemp[0] = array[j][0];
				arrTemp[1] = array[j][1];
				array[j][0] = array[n - 1 - i][0];
				array[j][1] = array[n - 1 - i][1];
				array[n - 1 - i][0] = arrTemp[0];
				array[n - 1 - i][1] = arrTemp[1];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("学号：%d，平均分：%d\n", array[i][0], array[i][1]);
	}
}

int GetTheDay(int year, int month, int day)
{
	int arrDaysOfMonth[2][12] = { {31,28,31,30,31,30,31,31,30,31,30,31},
										 {31,29,31,30,31,30,31,31,30,31,30,31} };
	int nDay = day;
	bool  bLeap = false;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		bLeap = true;
	}
	for (int i = 0; i < month - 1; i++)
	{
		nDay = nDay + *(arrDaysOfMonth[0] + bLeap * (sizeof(arrDaysOfMonth[0]) / sizeof(arrDaysOfMonth[0][0])) + i);
	}
	return nDay;
}

