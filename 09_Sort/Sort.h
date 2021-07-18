/*
1����������
2��ð������
3��ѡ������
4���۰����
*/
#pragma once
#include <iostream>
#include <time.h>

void RandomArray(int array[], int length);
void PrintfArray(int array[], int  length);
void QuickSort(int array[], int left, int right);
void BubbleSort(int array[], int length);
void ChooseSort(int array[], int length);
int HalfSearch(int left, int right, int n, int array[]);

/*�����������*/
void RandomArray(int array[], int length)
{
	srand((int)time(NULL));
	for (int i = 0; i < length; i++)
	{
		array[i] = rand() % 100;
	}
}
/*��ӡ����*/
void PrintfArray(int array[], int  length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
/*ʹ�õݹ鷽ʽʵ�ֿ�������*/
void QuickSort(int array[], int low, int high)
{
	if (low < high)
	{
		int i = low;
		int j = high;
		int key = array[i];
		while (i < j)
		{
			while (i < j && array[j] >= key)
			{
				j--;
			}
			if (i < j)
			{
				array[i++] = array[j];
			}
			while (i < j && array[i] <= key)
			{
				i++;
			}
			if (i < j)
			{
				array[j--] = array[i];
			}
		}
		array[i] = key;
		QuickSort(array, low, i - 1);
		QuickSort(array, i + 1, high);
	}
}
/*ð������*/
void BubbleSort(int array[], int length)
{
	int temp = 0;
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}
/*ѡ������*/
void ChooseSort(int array[], int length)
{
	int min = 0;
	int temp = 0;
	for (int i = 0; i < length; i++)
	{
		min = array[i];
		for (int j = i; j < length; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				temp = j;
			}
		}
		array[temp] = array[i];
		array[i] = min;
	}
}
/*ʹ�õݹ鷽ʽʵ���۰����*/
int HalfSearch(int left, int right, int n, int array[])
{
	int mid = (left + right) / 2;

	if (left <= right)
	{
		if (array[mid] < n)
		{
			left = mid + 1;
			return HalfSearch(left, right, n, array);
		}
		else if (array[mid] > n)
		{
			right = mid - 1;
			return HalfSearch(left, right, n, array);
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

