#include "Test.h"

int main()
{
	int arrNum[] = { 1,2,3,4,5 };
	int n = sizeof(arrNum) / sizeof(arrNum[0]);
	printf("����arrNum��");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arrNum[i]);
	}
	printf("\n");
	ExchangeArray(arrNum, n);
	printf("����arrNum��");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arrNum[i]);
	}
	printf("\n");

	char string[] = "hello world";
	printf("����string��%s\n", string);
	ExchangeString(string);
	printf("����string��%s\n", string);

	int arrScore[][2] = { {1,33},{2,67},{3,98},{4,87},{5,76},{6,60} };
	n = sizeof(arrScore) / sizeof(arrScore[0]);
	ScoreSort(arrScore, n);

	int year = 0;
	int month = 0;
	int day = 0;
	int nDay = 0;
	printf("�����������գ�\n��ݣ�");
	scanf_s("%d", &year);
	printf("�·ݣ�");
	scanf_s("%d", &month);
	printf("���ڣ�");
	scanf_s("%d", &day);
	nDay = GetTheDay(year, month, day);
	printf("����������һ��ĵ�%d��\n", nDay);

	return 0;
}
