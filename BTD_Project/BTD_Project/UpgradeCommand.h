#pragma once

typedef enum eUpgradeCommandCode
{
	UpgradeCommand_eAkey,
	UpgradeCommand_eDkey,
	UpgradeCommand_eWkey,
	UpgradeCommand_eSkey,
}eUpgradeCommandCode;

// 초기화 해주기
void UpgradeCommand_InitUpgradeCommand();

// 난수 이용해서 랜덤 정답 만드는 함수
void UpgradeCommand_CreateAnswerCommand();

// 내가 정답 입력한 것 기록하는 함수
void UpgradeCommand_WriteMyCommand();

// 랜덤 정답 출력하는 함수
void UpgradeCommand_DrawAnswerCommand();

void UpgradeCommand_CheckAnswer();