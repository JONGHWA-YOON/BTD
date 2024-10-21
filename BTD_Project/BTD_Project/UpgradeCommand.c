#include "UpgradeCommand.h"
#include <stdio.h>
#include <Windows.h>
#include "GameSystem.h"
#include "Sound.h"

// 업그레이드 정답 커맨드 
int UpgradeCommand_rightAnswer = 0;

// 내가 제출한 정답 커맨드
int UpgradeCommand_myAnswer;


void UpgradeCommand_InitUpgradeCommand()
{
	UpgradeCommand_CreateAnswerCommand();
}

void UpgradeCommand_CreateAnswerCommand()
{
	while (1)
	{
		int temp = rand() % 4;
		if (temp != UpgradeCommand_rightAnswer)
		{
			UpgradeCommand_rightAnswer = temp;
			break;
		}
	}
}

// 그리기 관련 함수라 gdi쪽에 빼야할수도..?
void UpgradeCommand_DrawAnswerCommand()
{
	switch (UpgradeCommand_rightAnswer)
	{
	case 0:
	{
		GDI_UpgradeCommandLeft();
		break;
	}
	case 1:
	{
		GDI_UpgradeCommandRight();
		break;
	}
	case 2:
	{
		GDI_UpgradeCommandUp();
		break;
	}
	case 3:
	{
		GDI_UpgradeCommandDown();
		break;
	}
	}
}

void UpgradeCommand_CheckAnswer()
{
	if (UpgradeCommand_myAnswer == UpgradeCommand_rightAnswer)
	{
		Sound_PlaySound(Combo_Success);
		// 업그레이드로 인한 능력치 증가
		GameSystem_AddUpgradeCombo();
		UpgradeCommand_CreateAnswerCommand();
	}
	else
	{
		Sound_PlaySound(Combo_Fail);
		GameSystem_DownUpgradeCombo();
		UpgradeCommand_CreateAnswerCommand();
	}
}

void UpgradeCommand_WriteMyCommand()
{
	if (GetAsyncKeyState(0x41) & 0x0001)
	{
		UpgradeCommand_myAnswer = UpgradeCommand_eAkey;
		UpgradeCommand_CheckAnswer();
	}
	else if (GetAsyncKeyState(0x44) & 0x0001)
	{
		UpgradeCommand_myAnswer = UpgradeCommand_eDkey;
		UpgradeCommand_CheckAnswer();
	}
	else if (GetAsyncKeyState(0x57) & 0x0001)
	{
		UpgradeCommand_myAnswer = UpgradeCommand_eWkey;
		UpgradeCommand_CheckAnswer();
	}
	else if (GetAsyncKeyState(0x53) & 0x0001)
	{
		UpgradeCommand_myAnswer = UpgradeCommand_eSkey;
		UpgradeCommand_CheckAnswer();
	}
}
