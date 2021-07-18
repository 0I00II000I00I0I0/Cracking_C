/*
宏定义的用法
*/
#include <iostream>

//符号化常量
#define PI 3.14f
//符号化公式
#define PRODUCT(a,b,c) ((a)*(b)+(c))
//代码块宏
#define OUTPUT(s) printf(s)
#define MYSTRING(s) #s
//宏参数连接##
#define DEF_INT(n) int int_##n
#define GET_INT(n) int_##n
#define DEF_FLOAT(n) float float_##n
#define GET_FLOAT(n) float_##n
//说明性宏
#define IN
#define OUT
int Func(IN int a, OUT int b)
{
	return 0;
}
//兼容性宏
#define INT int
#define near
#define far
#define for if(1)for
//条件编译
#ifdef UNICODE
#define TCHAR wchar_t
#define _tcscpy wcscpy_s
#define _tcscat wcscat_s
#define _tprintf wprintf
#define _tsystem _wsystem
#define __T(x) L##x
#else
#define TCHAR char
#define _tcscpy strcpy
#define _tcscat strcat
#define _tprintf printf
#define _tsystem system
#define __T(x) x
#endif

int main()
{
	printf("%f\n", 2 * PI);
	printf("%d\n", PRODUCT(2, 2, 2));
	OUTPUT("test define\n");
	OUTPUT(MYSTRING(test mystring\n));

	DEF_INT(a) = 123;
	printf("%d\n", int_a);
	int GET_INT(b) = 321;
	printf("%d\n", int_b);

	TCHAR szBuf[16] = __T("test define");
	TCHAR szDes[32] = { 0 };
	_tcscpy(szDes, szBuf);
	_tcscat(szDes, __T(" strcat\n"));
	_tprintf(szDes);
	_tsystem(__T("pause"));

	return 0;
}
