/*
迷宫求解，使用递归思想
*/
#include <iostream>

void ShowMaze(char szMaze[][21], int nRow);
void SolutionMaze(char szMaze[][21], int x, int y, int nRow);

int main()
{
	char szMaze[][21] = {
		"11111111111111111111",
		"10100001111110001111",
		"10101100000000100001",
		"10101110111110111101",
		"10100000100011111101",
		"10110110101000000101",
		"10110110101111110101",
		"100000100000000001$1",
		"11111111111111111111"
	};
	int nRow = sizeof(szMaze) / sizeof(szMaze[0]);
	ShowMaze(szMaze, nRow);
	SolutionMaze(szMaze, 1, 1, nRow);

	system("pause");
	return 0;
}

void ShowMaze(char szMaze[][21], int nRow)
{
	for (int i = 0; i < nRow; i++)
	{
		printf("%s\n", szMaze[i]);
	}
}

void SolutionMaze(char szMaze[][21], int x, int y, int nRow)
{
	if ('$' == szMaze[x][y])
	{
		system("cls");
		ShowMaze(szMaze, nRow);
		printf("解迷成功\n");
		exit(0);
	}

	szMaze[x][y] = '\2';
	system("cls");
	ShowMaze(szMaze, nRow);

	if ('$' == szMaze[x + 1][y] || '0' == szMaze[x + 1][y])
	{
		system("pause");
		SolutionMaze(szMaze, x + 1, y, nRow);
	}
	if ('$' == szMaze[x][y + 1] || '0' == szMaze[x][y + 1])
	{
		system("pause");
		SolutionMaze(szMaze, x, y + 1, nRow);
	}
	if ('$' == szMaze[x - 1][y] || '0' == szMaze[x - 1][y])
	{
		system("pause");
		SolutionMaze(szMaze, x - 1, y, nRow);
	}
	if ('$' == szMaze[x][y - 1] || '0' == szMaze[x][y - 1])
	{
		system("pause");
		SolutionMaze(szMaze, x, y - 1, nRow);
	}

	szMaze[x][y] = 0x58;
	system("cls");
	ShowMaze(szMaze, nRow);
}
