/*
至少实现5种类型的简单变体，方法：使用结构体实现6组Get/Set函数
*/
#include <iostream>
#include "MyStruct.h"

int main()
{
	SCORE tagScore;
	SetScoreByChar(&tagScore, 'A');
	ShowScore(&tagScore);

	SetScoreByInt(&tagScore, 99);
	ShowScore(&tagScore);

	SetScoreByFloat(&tagScore, 99.9f);
	ShowScore(&tagScore);

	SetScoreByDouble(&tagScore, 99.9f);
	ShowScore(&tagScore);

	SetScoreByText(&tagScore, (char*)"good student");
	ShowScore(&tagScore);

	return 0;
}
