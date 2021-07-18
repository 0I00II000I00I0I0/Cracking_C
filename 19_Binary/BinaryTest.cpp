/*
1、代码编写规范
2、求浮点数的二进制表示
*/
#include <iostream>
#define SAFE_FREE(p) if(p){free(p);p=NULL;}

//处理错误
void ErrorProc()
{
	puts("malloc failed");
}

//流程设计
void MallocMemory()
{
	//引用或操作资源的变量必须初始化为无效值
	char* pText = NULL;
	//申请资源后必须检查结果
	pText = (char*)malloc(16);
	if (pText == NULL)
	{
		//如果错误按需求处理错误
		ErrorProc();
		goto EXIT_PROC;
	}
	puts("malloc ok");
	strcpy_s(pText, 16, "test malloc");
	puts(pText);

EXIT_PROC:
	//释放资源前必须检查资源是否有效
	if (pText != NULL)
	{
		//释放资源后必须重置为无效值
		free(pText);
		pText = NULL;
	}
}

//解析float位段结构
typedef struct _FLOAT_ANALYSIS
{
	int Fraction : 23;
	int Exponent : 8;
	int Sign : 1;
}FLOAT_ANALYSIS, * PFLOAT_ANALYSIS;

//解析double位段结构
typedef struct _DOUBLE_ANALYSIS
{
	int Fraction2 : 32;
	int Fraction1 : 20;
	int Exponent : 11;
	int Sign : 1;
}DOUBLE_ANALYSIS, * PDOUBLE_ANALYSIS;

void GetFloatBin(PFLOAT_ANALYSIS pTagFNum, char* szBin)
{
	int t = 1;
	int i = 0;
	for (i = 0; i < 1; i++)
	{
		szBin[i] = pTagFNum->Sign;
	}
	for (i = 1; i < 9; i++)
	{
		szBin[i] = pTagFNum->Exponent & (t << (7 + 1 - i)) ? 1 : 0;
	}
	for (i = 9; i < 32; i++)
	{
		szBin[i] = pTagFNum->Fraction & (t << (22 + 9 - i)) ? 1 : 0;
	}
}
void GetDoubleBin(PDOUBLE_ANALYSIS pTagDbNum, char szBin[])
{
	int t = 1;
	int i = 0;
	for (i = 0; i < 1; i++)
	{
		szBin[i] = pTagDbNum->Sign;
	}
	for (i = 1; i < 12; i++)
	{
		szBin[i] = pTagDbNum->Exponent & (t << (10 + 1 - i)) ? 1 : 0;
	}
	for (i = 12; i < 32; i++)
	{
		szBin[i] = pTagDbNum->Fraction1 & (t << (19 + 12 - i)) ? 1 : 0;
	}
	for (i = 32; i < 64; i++)
	{
		szBin[i] = pTagDbNum->Fraction2 & (t << (31 + 32 - i)) ? 1 : 0;
	}
}

int main()
{
	MallocMemory();

	float fNum = 1.25f;
	PFLOAT_ANALYSIS pNum = (PFLOAT_ANALYSIS)&fNum;
	char szfBin[32] = { 0 };
	GetFloatBin(pNum, szfBin);
	printf("fNum = %f\n", fNum);
	printf("二进制： ");
	for (int i = 0; i < 32; i++)
	{
		printf("%d", szfBin[i]);
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
	printf("符号位：%d\n", szfBin[0]);
	printf("指数位：");
	for (int i = 1; i < 9; i++)
	{
		printf("%d", szfBin[i]);
	}
	printf("\n");
	printf("数据位：");
	for (int i = 9; i < 32; i++)
	{
		printf("%d", szfBin[i]);
	}
	printf("\n");

	double dbNum = 1.25f;
	PDOUBLE_ANALYSIS pdNum = (PDOUBLE_ANALYSIS)&dbNum;
	char szdBin[64] = { 0 };
	GetDoubleBin(pdNum, szdBin);
	printf("dbNum = %f\n", dbNum);
	printf("二进制：");
	for (int i = 0; i < 64; i++)
	{
		printf("%d", szdBin[i]);
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");

	return 0;
}
