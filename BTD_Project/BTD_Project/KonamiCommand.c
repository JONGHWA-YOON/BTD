#include "KonamiCommand.h"
#include <stdio.h>
#include <windows.h>
#include "GameSystem.h"
// 배열 인덱스 
int KonamiCommand_Index;

// 발동 커맨드 - 좌 우 위 아래 좌 우
int KonamiCommand_RightAnswer[6] = { KonamiCommand_eLeftArrow, KonamiCommand_eRightArrow, KonamiCommand_eUpArrow, KonamiCommand_eDownArrow, KonamiCommand_eLeftArrow, KonamiCommand_eRightArrow };

// 내가 누른 키보드 값 배열
int KonamiCommand_MyAnswer[6] = { 0, };

// 게임 초기 시작 UI에서 발동되게 하면 될 듯?
void KonamiCommand_Hidden()
{
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			KonamiCommand_MyAnswer[KonamiCommand_Index] = KonamiCommand_eLeftArrow;

			if (KonamiCommand_MyAnswer[KonamiCommand_Index] == KonamiCommand_RightAnswer[KonamiCommand_Index])
			{
				KonamiCommand_Index++;
			}
			else
			{
				KonamiCommand_Index = 0;
			}
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			KonamiCommand_MyAnswer[KonamiCommand_Index] = KonamiCommand_eRightArrow;

			if (KonamiCommand_MyAnswer[KonamiCommand_Index] == KonamiCommand_RightAnswer[KonamiCommand_Index])
			{
				KonamiCommand_Index++;
			}
			else
			{
				KonamiCommand_Index = 0;
			}
		}

		else if (GetAsyncKeyState(VK_UP) & 0x0001)
		{
			KonamiCommand_MyAnswer[KonamiCommand_Index] = KonamiCommand_eUpArrow;

			if (KonamiCommand_MyAnswer[KonamiCommand_Index] == KonamiCommand_RightAnswer[KonamiCommand_Index])
			{
				KonamiCommand_Index++;
			}
			else
			{
				KonamiCommand_Index = 0;
			}
		}

		else if (GetAsyncKeyState(VK_DOWN) & 0x0001)
		{
			KonamiCommand_MyAnswer[KonamiCommand_Index] = KonamiCommand_eDownArrow;

			if (KonamiCommand_MyAnswer[KonamiCommand_Index] == KonamiCommand_RightAnswer[KonamiCommand_Index])
			{
				KonamiCommand_Index++;
			}
			else
			{
				KonamiCommand_Index = 0;
			}
		}

	}


	if (KonamiCommand_Index == 6)
	{
		// 돈 증가
		GameSystem_gameSystem.money = 9999;
		GameSystem_gameSystem.upgradeCombo += 300;
		// 무한루프 안돌도록 히드커맨드 완료되면 0으로 초기화시켜줌
		KonamiCommand_Index = 0;
	}
}