/*
1、输入用户名密码，校验后正确，显示登陆成功，错误，显示登陆失败，错误三次自动退出
2、输入三角形的三个边，求面积
3、打印ASCII码中的可见字符，33~127
*/
#include <iostream>
#include <math.h>
#include <string.h>

typedef struct _USER
{
	char* username;
	int password;
}USER, * PUSER;

int CheckPwd(char* username, int password);
double SquareArea(float sideA, float sideB, float sideC);
void PrintfASCII();
USER g_aryTagUser[3] = { {(char*)"xiaoming",123},{ (char*)"xiaoxin",321},{(char*)"xiaobai",222} };

int main()
{
	//登陆验证
	printf("username\tpassword\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%s\t\t%d\n", g_aryTagUser[i].username, g_aryTagUser[i].password);
	}
	printf("输入登陆名和密码，中间用空格隔开：");

	char szName[16] = { 0 };
	int password = 0;
	int n = 3;
	while (n)
	{
		scanf_s("%s", szName, 16);
		scanf_s("%d", &password);
		int nRet = CheckPwd(szName, password);
		if (nRet == 1)
		{
			printf("登陆成功\n");
			break;
		}
		else if (n-- == 1)
		{
			printf("失败次数过多，请稍后重试\n");
			break;
		}
		if (nRet == 0)
		{
			printf("密码不正确，登陆失败，请重新登陆：");
		}
		if (nRet == -1)
		{
			printf("用户名错误，登陆失败，请重新登陆：");
		}
		rewind(stdin);
	}

	//计算三角形面积
	float fSideA = 0.0f;
	float fSideB = 0.0f;
	float fSideC = 0.0f;
	double dbArea = 0.0;

	printf("请输入三边长度，长度之间用空格隔开：");
	scanf_s("%f%f%f", &fSideA, &fSideB, &fSideC);
	while (fSideA + fSideB <= fSideC || fSideA + fSideC <= fSideB || fSideB + fSideC <= fSideA)
	{
		printf("输入的边长不满足三角形要求，请重新输入：");
		rewind(stdin);
		scanf_s("%f%f%f", &fSideA, &fSideB, &fSideC);
	}
	dbArea = SquareArea(fSideA, fSideB, fSideC);
	printf("三角形的面积：%.2f\n", dbArea);

	//打印ASCII码
	PrintfASCII();

	return 0;
}

double SquareArea(float sideA, float sideB, float sideC)
{
	double p = (sideA + sideB + sideC) / 2;
	double dbArea = sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
	return dbArea;
}

int CheckPwd(char* username, int password)
{
	int result = 0;
	for (int i = 0; i < 3; i++)
	{
		if (!strcmp(g_aryTagUser[i].username, username))
		{
			if (g_aryTagUser[i].password == password)
			{
				result = 1;
			}
			else
			{
				result = 0;
			}
			break;
		}
		if (i == 2 && strcmp(g_aryTagUser[i].username, username) != 0)
		{
			result = -1;
		}
	}
	return result;
}

void PrintfASCII()
{
	printf("ASCII码中的可见字符：\n");
	for (int i = 33; i < 128; i++)
	{
		printf("%d:%c\t", i, i);
		if (i % 8 == 0)
		{
			printf("\n");
		}
	}
}

