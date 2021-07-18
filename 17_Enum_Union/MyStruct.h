#pragma once

typedef struct _SCORE
{
	//枚举类型
	enum _SCORETYPE
	{
		TY_CHAR,
		TY_INT,
		TY_FLOAT,
		TY_DOUBLE,
		TY_TEXT,
	}enumType;
	//共用体
	union _SCOREDATA
	{
		char cLevel;
		int nNumber;
		float fNumber;
		double dbNumber;
		char szText[128];
	}unionData;
}SCORE, * PSCORE;

char GetScoreByChar(PSCORE pScore);
int GetScoreByInt(PSCORE pScore);
float GetScoreByFloat(PSCORE pScore);
double GetScoreByDouble(PSCORE pScore);
char* GetScoreByText(PSCORE pScore);

void SetScoreByChar(PSCORE pScore, char cData);
void SetScoreByInt(PSCORE pScore, int nData);
void SetScoreByFloat(PSCORE pScore, float fData);
void SetScoreByDouble(PSCORE pScore, double dData);
void SetScoreByText(PSCORE pScore, char* szData);

void ShowScore(PSCORE pScore);
