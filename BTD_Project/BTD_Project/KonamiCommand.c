#include "KonamiCommand.h"
#include <stdio.h>
#include <windows.h>
#include "GameSystem.h"
// �迭 �ε��� 
int KonamiCommand_Index;

// �ߵ� Ŀ�ǵ� - �� �� �� �Ʒ� �� ��
int KonamiCommand_RightAnswer[6] = { KonamiCommand_eLeftArrow, KonamiCommand_eRightArrow, KonamiCommand_eUpArrow, KonamiCommand_eDownArrow, KonamiCommand_eLeftArrow, KonamiCommand_eRightArrow };

// ���� ���� Ű���� �� �迭
int KonamiCommand_MyAnswer[6] = { 0, };

// ���� �ʱ� ���� UI���� �ߵ��ǰ� �ϸ� �� ��?
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
		// �� ����
		GameSystem_gameSystem.money = 9999;
		GameSystem_gameSystem.upgradeCombo += 300;
		// ���ѷ��� �ȵ����� ����Ŀ�ǵ� �Ϸ�Ǹ� 0���� �ʱ�ȭ������
		KonamiCommand_Index = 0;
	}
}