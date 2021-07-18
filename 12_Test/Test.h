#pragma once
#include <stdio.h>
/*
1��дһ������ChangeArray(int array[],int n)�����Խ������е�n��Ԫ�������š�
2��дһ������ChangeString(char str[])��ʵ���ַ������ַ��Ļ�������abcde����edcba��
3����ά�����д��ѧ�ź�ƽ���֣�����ƽ���ִӸߵ��͵�˳�����ѧ�ź�ƽ���֡���ʾ����ƽ�������򣬵�Ԫ�ػ���ʱ��ѧ��Ԫ�ض�Ӧ������
4��Ӧ������ʵ��������year����month����date�����������������ĵڼ��졣
5����ʾ�������ά����DaysOfMonth[2][12]�������һ���ɷ������12���µ�������ɣ��ڶ���������12���µ�������ɣ�
	����ʱiΪ1��������ʱiΪ0���ۼ�DaysOfMonth[i][0]��DaysOfMonth[i][month-1]���������ټ���day���õ���������
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
		printf("ѧ�ţ�%d��ƽ���֣�%d\n", array[i][0], array[i][1]);
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

