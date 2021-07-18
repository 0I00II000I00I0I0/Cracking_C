#include "Sort.h"

int main()
{
	int aryNum[16] = { 0 };
	int length = sizeof(aryNum) / sizeof(aryNum[0]);

	RandomArray(aryNum, length);
	printf("生成随机数组：\n");
	PrintfArray(aryNum, length);
	QuickSort(aryNum, 0, length - 1);
	printf("快速排序结果：\n");
	PrintfArray(aryNum, length);

	system("pause");
	RandomArray(aryNum, length);
	printf("生成随机数组：\n");
	PrintfArray(aryNum, length);
	BubbleSort(aryNum, length);
	printf("冒泡排序结果：\n");
	PrintfArray(aryNum, length);

	system("pause");
	RandomArray(aryNum, length);
	printf("生成随机数组：\n");
	PrintfArray(aryNum, length);
	BubbleSort(aryNum, length);
	printf("选择排序结果：\n");
	PrintfArray(aryNum, length);

	system("pause");
	int n = 0;
	int result = 0;
	printf("你想查找的数：");
	scanf_s("%d", &n);
	result = HalfSearch(0, length - 1, n, aryNum);
	printf("折半查找下标：%d\n", result);

	return 0;
}

