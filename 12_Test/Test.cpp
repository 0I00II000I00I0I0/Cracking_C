#include "Test.h"

int main()
{
	int arrNum[] = { 1,2,3,4,5 };
	int n = sizeof(arrNum) / sizeof(arrNum[0]);
	printf("数组arrNum：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arrNum[i]);
	}
	printf("\n");
	ExchangeArray(arrNum, n);
	printf("数组arrNum：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arrNum[i]);
	}
	printf("\n");

	char string[] = "hello world";
	printf("数组string：%s\n", string);
	ExchangeString(string);
	printf("数组string：%s\n", string);

	int arrScore[][2] = { {1,33},{2,67},{3,98},{4,87},{5,76},{6,60} };
	n = sizeof(arrScore) / sizeof(arrScore[0]);
	ScoreSort(arrScore, n);

	int year = 0;
	int month = 0;
	int day = 0;
	int nDay = 0;
	printf("请输入年月日：\n年份：");
	scanf_s("%d", &year);
	printf("月份：");
	scanf_s("%d", &month);
	printf("日期：");
	scanf_s("%d", &day);
	nDay = GetTheDay(year, month, day);
	printf("该日期是这一年的第%d天\n", nDay);

	return 0;
}
