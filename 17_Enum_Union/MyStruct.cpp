#include "MyStruct.h"
#include <iostream>

char GetScoreByChar(PSCORE pScore)
{
	return pScore->unionData.cLevel;
}

int GetScoreByInt(PSCORE pScore)
{
	return pScore->unionData.nNumber;
}

float GetScoreByFloat(PSCORE pScore)
{
	return pScore->unionData.fNumber;
}

double GetScoreByDouble(PSCORE pScore)
{
	return pScore->unionData.dbNumber;
}

char* GetScoreByText(PSCORE pScore)
{
	return pScore->unionData.szText;
}

void SetScoreByChar(PSCORE pScore, char cData)
{
	pScore->enumType = pScore->TY_CHAR;
	pScore->unionData.cLevel = cData;
}

void SetScoreByInt(PSCORE pScore, int nData)
{
	pScore->enumType = pScore->TY_INT;
	pScore->unionData.nNumber = nData;
}

void SetScoreByFloat(PSCORE pScore, float fData)
{
	pScore->enumType = pScore->TY_FLOAT;
	pScore->unionData.fNumber = fData;
}

void SetScoreByDouble(PSCORE pScore, double dData)
{
	pScore->enumType = pScore->TY_DOUBLE;
	pScore->unionData.dbNumber = dData;
}

void SetScoreByText(PSCORE pScore, char* szData)
{
	pScore->enumType = pScore->TY_TEXT;
	strcpy_s(pScore->unionData.szText, szData);
}

void ShowScore(PSCORE pScore)
{
	switch (pScore->enumType)
	{
	case SCORE::TY_CHAR:
		printf("%c\n", GetScoreByChar(pScore));
		break;
	case SCORE::TY_INT:
		printf("%d\n", GetScoreByInt(pScore));
		break;
	case SCORE::TY_FLOAT:
		printf("%f\n", GetScoreByFloat(pScore));
		break;
	case SCORE::TY_DOUBLE:
		printf("%f\n", GetScoreByDouble(pScore));
		break;
	case SCORE::TY_TEXT:
		printf("%s\n", GetScoreByText(pScore));
		break;
	default:
		break;
	}
}
