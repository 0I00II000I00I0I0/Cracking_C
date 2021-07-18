/*
指针的运算
1、是什么类型的指针参与运算
2、怎么运算
3、运算后得到什么
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
	//p是int[4]类型的数组指针
	printf("%p\n", *p);
	//p是int[4]类型的数组指针，*p得到int[4]的标志符引用，*p是int类型的指针常量
	printf("%0x\n", **p);
	//*p是int类型的指针常量，**p得到int类型指针常量的标志符引用，**p是int类型
	printf("\n");

	printf("%p\r\n", p + 1);
	//p是int[4]类型的数组指针，(int)(p+sizeof(int[4])*1)
	printf("%p\r\n", (p + 1) + 1);
	//(p+1)是int[4]类型的数组指针，(int)((p+1)+sizeof(int[4])*1)
	printf("%p\n", *(p + 1));
	//p+1是int[4]类型的数组指针，*(p+1)得到int[4]的标志符引用，*(p+1)是int类型的指针常量
	printf("%p\n", *(p + 1) + 1);
	//*(p+1)是int类型的指针常量，(int)(*(p+1)+sizeof(int)*1)
	printf("\n");

	printf("%p\r\n", *p + 1);
	//*p是int类型的指针常量，(int)(*p+sizeof(int)*1)
	printf("%0x\n", *(*p + 1));
	//*p+1是int类型的指针常量，*(*p+1)得到int类型指针常量的标志符引用，*(*p+1)是int类型
	printf("%0x\r\n", *(*p + 1) + 1);
	//(*p+1)是int类型的指针常量，*(*p + 1)得到int类型指针常量的标志符引用，*(*p + 1)是int类型
	printf("\n");

	printf("%p\r\n", p[1]);
	//p[1] == *(p+1)，p[1]是int类型的指针常量
	printf("%p\r\n", p[1] + 1);
	//p[1]+1 == *(p+1)+1，*p[1] + 1是int类型的指针常量
	printf("%0x\r\n", p[1][1]);
	//p[1][1] == *(*(p+1)+1)，p[1][1]是int类型
	printf("%0x\n", (p[1] + 1)[1]);
	//p[1] == *(p+1)，*(p+1)是int类型的指针常量，
	// (p[1]+1)[1] == *(*(p+1)+1+1) ，*(p+1)是int类型的指针常量， *((int)(*(p+1)+sizeof(int)*1+sizeof(int)*1))
	// *(*(p+1)+1+1)是int类型，(p[1] + 1)[1]是int类型
	printf("%0x\r\n", *p[1] + 1);
	//*p[1]+1 == *(*(p+1))+1，*(p+1)是int类型的指针常量，*(*(p+1))是int类型

	return 0;
}

