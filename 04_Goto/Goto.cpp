/*
ʹ��gotoģ������ѭ����ʽ��forѭ����whileѭ����do whileѭ��
*/
#include <iostream>

void RoundFor(int n);
void RoundWhile(int n);
void RouneDoWhile(int n);

int main()
{
	printf("forѭ��:\n");
	RoundFor(9);
	printf("whileѭ��:\n");
	RoundWhile(9);
	printf("do whileѭ��:\n");
	RouneDoWhile(9);

	return 0;
}

/*ģ��forѭ��*/
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
	/*ѭ�������*/
	printf("loop:%d\t", i);
	goto loopstep;
loopend:
	printf("ѭ������\n");
}

/*ģ��whileѭ��*/
void RoundWhile(int n)
{
	int i = 0;
next:
	if (i >= n)
	{
		goto end;
	}
	/*ѭ�������*/
	printf("loop:%d\t", i);
	i++;
	goto next;
end:
	printf("ѭ������\n");
}

/*ģ��do whileѭ��*/
void RouneDoWhile(int n)
{
	int i = 0;
next:
	/*ѭ�������*/
	printf("loop:%d\t", i);
	i++;
	if (i >= n)
	{
		goto end;
	}
	goto next;
end:
	printf("ѭ������\n");
}
