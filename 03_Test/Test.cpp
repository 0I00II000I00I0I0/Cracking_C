/*
1�������û������룬У�����ȷ����ʾ��½�ɹ���������ʾ��½ʧ�ܣ����������Զ��˳�
2�����������ε������ߣ������
3����ӡASCII���еĿɼ��ַ���33~127
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
	//��½��֤
	printf("username\tpassword\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%s\t\t%d\n", g_aryTagUser[i].username, g_aryTagUser[i].password);
	}
	printf("�����½�������룬�м��ÿո������");

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
			printf("��½�ɹ�\n");
			break;
		}
		else if (n-- == 1)
		{
			printf("ʧ�ܴ������࣬���Ժ�����\n");
			break;
		}
		if (nRet == 0)
		{
			printf("���벻��ȷ����½ʧ�ܣ������µ�½��");
		}
		if (nRet == -1)
		{
			printf("�û������󣬵�½ʧ�ܣ������µ�½��");
		}
		rewind(stdin);
	}

	//�������������
	float fSideA = 0.0f;
	float fSideB = 0.0f;
	float fSideC = 0.0f;
	double dbArea = 0.0;

	printf("���������߳��ȣ�����֮���ÿո������");
	scanf_s("%f%f%f", &fSideA, &fSideB, &fSideC);
	while (fSideA + fSideB <= fSideC || fSideA + fSideC <= fSideB || fSideB + fSideC <= fSideA)
	{
		printf("����ı߳�������������Ҫ�����������룺");
		rewind(stdin);
		scanf_s("%f%f%f", &fSideA, &fSideB, &fSideC);
	}
	dbArea = SquareArea(fSideA, fSideB, fSideC);
	printf("�����ε������%.2f\n", dbArea);

	//��ӡASCII��
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
	printf("ASCII���еĿɼ��ַ���\n");
	for (int i = 33; i < 128; i++)
	{
		printf("%d:%c\t", i, i);
		if (i % 8 == 0)
		{
			printf("\n");
		}
	}
}

