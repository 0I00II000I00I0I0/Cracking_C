/*
了解malloc申请的堆内存空间详细信息
*/
#include <iostream>
#ifdef DEBUG
#define malloc(size) _malloc_dbg(size,_NORMAL_BLOCK,__FILE__,__LINE__)
#endif // DEBUG

typedef struct _MYHEAPINFO
{
	int* PreHeapAddress;
	int* NextHeapAddress;
	int* FileAddress;
	int ApplyHeapLine;
	int HeapType;
	int HeapSize;
	int HeapNum;
	char PreOverflowSign[4];
	char Info[1];
}HEAPINFO, * PHEAPINFO;

void PrintHeapInfo(PHEAPINFO pHeapInfo)
{
	int i = 0;
	printf("上一个堆地址：%p\n", pHeapInfo->PreHeapAddress);
	printf("下一个堆地址：%p\n", pHeapInfo->NextHeapAddress);
	printf("文件地址：%p\n", pHeapInfo->FileAddress);
	printf("所在行：%d\n", pHeapInfo->ApplyHeapLine);
	printf("堆类型：%d\n", pHeapInfo->HeapType);
	printf("堆长度：%d\n", pHeapInfo->HeapSize);
	printf("堆编号：%d\n", pHeapInfo->HeapNum);
	printf("上溢标志：%2X%2X%2X%2X\n", (unsigned char)pHeapInfo->PreOverflowSign[0], (unsigned char)pHeapInfo->PreOverflowSign[1],
		(unsigned char)pHeapInfo->PreOverflowSign[2], (unsigned char)pHeapInfo->PreOverflowSign[3]);
	printf("下溢标志：%2X%2X%2X%2X\n", (unsigned char)(pHeapInfo->Info[pHeapInfo->HeapSize]),
		(unsigned char)(pHeapInfo->Info[pHeapInfo->HeapSize + 1]),
		(unsigned char)(pHeapInfo->Info[pHeapInfo->HeapSize + 2]),
		(unsigned char)(pHeapInfo->Info[pHeapInfo->HeapSize + 3]));
	printf("堆内容：");
	for (i = 0; i < pHeapInfo->HeapSize; i++)
	{
		if (i == 128)
		{
			printf("...");
			break;
		}
		printf("%c", pHeapInfo->Info[i]);
	}
	printf("\n");
	printf("----------------------------------------------\n");
}

int main()
{
	char* szBuf = (char*)malloc(128);
	if (szBuf != NULL)
	{
		memset(szBuf, 0, 128);
		strcpy_s(szBuf, 128, "test heapinfo");
	}

	PHEAPINFO pTagHeapInfo = (PHEAPINFO)((int)szBuf - 32);
	PHEAPINFO pTemp = pTagHeapInfo;
	do {
		PrintHeapInfo(pTemp);
		pTemp = (PHEAPINFO)pTemp->PreHeapAddress;

	} while (pTemp->PreHeapAddress != 0);

	do {
		PrintHeapInfo(pTagHeapInfo);
		pTagHeapInfo = (PHEAPINFO)pTagHeapInfo->NextHeapAddress;
	} while (pTagHeapInfo->NextHeapAddress != 0);

	free(szBuf);
	return 0;
}
