/*
ָ�������
1����ʲô���͵�ָ���������
2����ô����
3�������õ�ʲô
*/
#include <iostream>

int main()
{
	int array[3][4] = {
		{0x10,0x20,0x30,0x00},
		{0x40,0x50,0x60,0x00},
		{0x70,0x80,0x90,0x00}
	};
	int(*p)[4] = array;
	printf("%p\n", p);
	//p��int[4]���͵�����ָ��
	printf("%p\n", *p);
	//p��int[4]���͵�����ָ�룬*p�õ�int[4]�ı�־�����ã�*p��int���͵�ָ�볣��
	printf("%0x\n", **p);
	//*p��int���͵�ָ�볣����**p�õ�int����ָ�볣���ı�־�����ã�**p��int����
	printf("\n");

	printf("%p\r\n", p + 1);
	//p��int[4]���͵�����ָ�룬(int)(p+sizeof(int[4])*1)
	printf("%p\r\n", (p + 1) + 1);
	//(p+1)��int[4]���͵�����ָ�룬(int)((p+1)+sizeof(int[4])*1)
	printf("%p\n", *(p + 1));
	//p+1��int[4]���͵�����ָ�룬*(p+1)�õ�int[4]�ı�־�����ã�*(p+1)��int���͵�ָ�볣��
	printf("%p\n", *(p + 1) + 1);
	//*(p+1)��int���͵�ָ�볣����(int)(*(p+1)+sizeof(int)*1)
	printf("\n");

	printf("%p\r\n", *p + 1);
	//*p��int���͵�ָ�볣����(int)(*p+sizeof(int)*1)
	printf("%0x\n", *(*p + 1));
	//*p+1��int���͵�ָ�볣����*(*p+1)�õ�int����ָ�볣���ı�־�����ã�*(*p+1)��int����
	printf("%0x\r\n", *(*p + 1) + 1);
	//(*p+1)��int���͵�ָ�볣����*(*p + 1)�õ�int����ָ�볣���ı�־�����ã�*(*p + 1)��int����
	printf("\n");

	printf("%p\r\n", p[1]);
	//p[1] == *(p+1)��p[1]��int���͵�ָ�볣��
	printf("%p\r\n", p[1] + 1);
	//p[1]+1 == *(p+1)+1��*p[1] + 1��int���͵�ָ�볣��
	printf("%0x\r\n", p[1][1]);
	//p[1][1] == *(*(p+1)+1)��p[1][1]��int����
	printf("%0x\n", (p[1] + 1)[1]);
	//p[1] == *(p+1)��*(p+1)��int���͵�ָ�볣����
	// (p[1]+1)[1] == *(*(p+1)+1+1) ��*(p+1)��int���͵�ָ�볣���� *((int)(*(p+1)+sizeof(int)*1+sizeof(int)*1))
	// *(*(p+1)+1+1)��int���ͣ�(p[1] + 1)[1]��int����
	printf("%0x\r\n", *p[1] + 1);
	//*p[1]+1 == *(*(p+1))+1��*(p+1)��int���͵�ָ�볣����*(*(p+1))��int����

	return 0;
}
