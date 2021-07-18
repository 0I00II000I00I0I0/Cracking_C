/*
1、定义结构体，查看结构体的内存分布
2、用结构体输出数组
3、求结构体的地址到它的成员变量的地址的距离（字节为单位）
*/
#include <iostream>

typedef struct _STUDENT
{
	int nID;
	char cGender;
	short int shAge;
	char szName[16];
	double dbScore;
}STUDENT, * PSTUDENT;

typedef struct _Data
{
	int nLength;
	char szInfo[1];
}Data, * PData;

typedef struct _PERSON
{
	int id;
	char name[16];
	int age;
}PERSON, * PPERSON;

int main()
{
	STUDENT tagStu = { 6,'M',20,"xiaoxin",60 };
	printf("sizeof(tagStu)：%d\n", sizeof(tagStu));

	unsigned char arrData[61] = {
		0x08, 0x00, 0x00, 0x00, 0x63, 0x72, 0x61, 0x63,
		0x6B, 0x69, 0x6e, 0x67, 0x0D, 0x00, 0x00, 0x00,
		0x77, 0x77, 0x77, 0x2E, 0x35, 0x31, 0x61, 0x73,
		0x6D, 0x2E, 0x63, 0x6F, 0x6D, 0x1c, 0x00, 0x00,
		0x00, 0x74, 0x65, 0x73, 0x74, 0x20, 0x75, 0x73,
		0x65, 0x20, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74,
		0x20, 0x70, 0x72, 0x69, 0x6e, 0x74, 0x66, 0x20,
		0x61, 0x72, 0x72, 0x61, 0x79 };
	PData pTagData = (PData)arrData;
	while ((unsigned char*)pTagData < arrData + sizeof(arrData))
	{
		for (int i = 0; i < pTagData->nLength; i++)
		{
			printf("%c", pTagData->szInfo[i]);
		}
		printf("\n");
		pTagData = (PData)((int)pTagData + pTagData->nLength + sizeof(pTagData->nLength));
	}

	//求结构体的地址到它的成员变量的地址的距离（字节为单位）
	int nIdOffset = (size_t) & (((PPERSON)0)->id);
	int nNameOffset = (size_t) & (((PPERSON)0)->name);
	int nAgeOffset = (size_t) & (((PPERSON)0)->age);
	printf("offset：id:%d,name:%d,age:%d\n", nIdOffset, nNameOffset, nAgeOffset);
	PERSON tagPerson = { 9,"xiaoxin",6 };
	int nID = *(int*)((int)&tagPerson + nIdOffset);
	char* szName = (char*)((int)&tagPerson + nNameOffset);
	int nAge = *(int*)((int)&tagPerson + nAgeOffset);
	printf("person：id:%d,name:%s,age:%d\n", nID, szName, nAge);

	return 0;
}
