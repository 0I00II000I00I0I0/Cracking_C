/*
奇数阶幻方问题：幻方是一种将数字安排在正方形格子中，使每行、列和对角线上的数字和都相等的方法
*/
#include <iostream>
void MagicSquare(int arrNumber[][100], int nNum);

int main()
{
	int nNum = 0;
	int arrNumber[100][100] = { 0 };
	do
	{
		printf("输入一个100以内的奇数：\n");
		rewind(stdin);
		scanf_s("%d", &nNum);
	} while (nNum % 2 == 0);

	printf("%d阶幻方结果：\n", nNum);
	MagicSquare(arrNumber, nNum);
	return 0;
}

void MagicSquare(int arrNumber[][100], int nNum)
{
	int nStartX = nNum - 1;
	int nStartY = nNum / 2;

	for (int i = 1; i <= nNum * nNum; i++)
	{
		int x = nStartX;
		int y = nStartY;
		if (nStartX == nNum)
		{
			nStartX = 0;
		}
		if (nStartY == -1)
		{
			nStartY = nNum - 1;
		}
		if (arrNumber[nStartX][nStartY] != 0)
		{
			nStartX = x - 2;
			nStartY = y + 1;
		}
		arrNumber[nStartX][nStartY] = i;
		nStartX++;
		nStartY--;
	}

	for (int i = 0; i < nNum; i++)
	{
		for (int j = 0; j < nNum; j++)
		{
			printf(" %-3d", arrNumber[i][j]);
		}
		printf("\n");
	}
}

