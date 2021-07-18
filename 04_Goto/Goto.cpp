/*
使用goto模拟三种循环方式：for循环、while循环、do while循环
*/
#include <iostream>

void RoundFor(int n);
void RoundWhile(int n);
void RouneDoWhile(int n);

int main()
{
	printf("for循环:\n");
	RoundFor(9);
	printf("while循环:\n");
	RoundWhile(9);
	printf("do while循环:\n");
	RouneDoWhile(9);

	return 0;
}

/*模拟for循环*/
void RoundFor(int n)
{
	/*loopinit*/
	int i = 0;
	goto loopcmp;
loopstep:
	i++;
	goto loopcmp;
loopcmp:
	if (i >= n)
	{
		goto loopend;
	}
	/*循环代码块*/
	printf("loop:%d\t", i);
	goto loopstep;
loopend:
	printf("循环结束\n");
}

/*模拟while循环*/
void RoundWhile(int n)
{
	int i = 0;
next:
	if (i >= n)
	{
		goto end;
	}
	/*循环代码块*/
	printf("loop:%d\t", i);
	i++;
	goto next;
end:
	printf("循环结束\n");
}

/*模拟do while循环*/
void RouneDoWhile(int n)
{
	int i = 0;
next:
	/*循环代码块*/
	printf("loop:%d\t", i);
	i++;
	if (i >= n)
	{
		goto end;
	}
	goto next;
end:
	printf("循环结束\n");
}
