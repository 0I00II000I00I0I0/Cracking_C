#include "Sort.h"

int main()
{
	int aryNum[16] = { 0 };
	int length = sizeof(aryNum) / sizeof(aryNum[0]);

	RandomArray(aryNum, length);
	printf("����������飺\n");
	PrintfArray(aryNum, length);
	QuickSort(aryNum, 0, length - 1);
	printf("������������\n");
	PrintfArray(aryNum, length);

	system("pause");
	RandomArray(aryNum, length);
	printf("����������飺\n");
	PrintfArray(aryNum, length);
	BubbleSort(aryNum, length);
	printf("ð����������\n");
	PrintfArray(aryNum, length);

	system("pause");
	RandomArray(aryNum, length);
	printf("����������飺\n");
	PrintfArray(aryNum, length);
	BubbleSort(aryNum, length);
	printf("ѡ����������\n");
	PrintfArray(aryNum, length);

	system("pause");
	int n = 0;
	int result = 0;
	printf("������ҵ�����");
	scanf_s("%d", &n);
	result = HalfSearch(0, length - 1, n, aryNum);
	printf("�۰�����±꣺%d\n", result);

	return 0;
}

