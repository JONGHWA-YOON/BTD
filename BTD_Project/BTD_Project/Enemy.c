#include "Enemy.h"
#include <stddef.h>
#include "DeltaTime.h"
#include "GameSystem.h"
#include <math.h>
#include "Sound.h"

Enemy Enemy_EnemyArr[POOLSIZE];  // �������� ����

int WaveLevel = 1;

Enemy Enemy_EnemyInfo[3] =
{		//ü��		�ӵ�
	{-1	,	0	,	0	,	0	,	0	,	},
	{-1	,	50	,	100	,	0	,	0	,	},
	{-1	,	50	,	500	,	0	,	0	,	}
};

void Enemy_InitEnemy()
{
	for (int i = 0; i < POOLSIZE; ++i)
	{
		Enemy_EnemyArr[i] = Enemy_EnemyInfo[0];
	}
}

void Enemy_Stats(int Index, int WaveLevel , eEnemy_Type type)
{
	WaveLevel -= 1;

	Enemy_EnemyArr[Index] = Enemy_EnemyInfo[type];

	Enemy_EnemyArr[Index].index = Index;
	
	Enemy_EnemyArr[Index].Enemy_Hp *= pow(1.15 , WaveLevel);        // ������ ü�� (�⺻��ġ �ϵ��ڵ� + ���̺� �� 20% ����)
	Enemy_EnemyArr[Index].Enemy_Speed = Enemy_EnemyInfo[type].Enemy_Speed * ((0.05 * WaveLevel) + 1);      // ������ �̼� (�⺻��ġ �ϵ��ڵ� + ���̺� �� 5% ����)
	Enemy_EnemyArr[Index].Enemy_Xposition = 0;
	Enemy_EnemyArr[Index].Enemy_Yposition = 250;
	Enemy_EnemyArr[Index].Enemy_Headposition = eEnemy_Turn_None;        // ó���� ���� �⺻��
	Enemy_EnemyArr[Index].Enemy_Type = type;                // �⺻�� 0
	Enemy_EnemyArr[Index].Die = Enemy_Disappear;
}

void Enemy_UpdateSpawn(int Index, int WaveLevel, eEnemy_Type Type)   
{
	Enemy_Stats(Index, WaveLevel,Type);
}

void Enemy_DisappearWhenGameOver()
{
	for (int index = 29; index >= 0; index--)
	{
		Enemy_EnemyArr[index].Enemy_Type = eEnemy_Type_None;
	}
}

Enemy* Enemy_GetEnemyInfo()
{
	return Enemy_EnemyInfo;
}

void Enemy_Disappear(int index)
{
	if (Enemy_EnemyArr[index].Enemy_Type == eEnemy_Monster1 ||
		Enemy_EnemyArr[index].Enemy_Type == eEnemy_Monster2)
	{
		Enemy_EnemyArr[index].Enemy_Speed = 0;
		Enemy_EnemyArr[index].Enemy_Type += 2;
		Enemy_EnemyArr[index].Enemy_disappearTime = 3;
	}
	
	GameSystem_gameSystem.enemyKillCount += 1;
	Sound_PlaySound(GetMoney);
	GameSystem_gameSystem.money += ENEMYKILLMONOY;
}

void Enemy_UpdateMove(int index)
{
	if (Enemy_EnemyArr[index].Enemy_Type == eEnemy_Monster1 ||
		Enemy_EnemyArr[index].Enemy_Type == eEnemy_Monster2)
	{
		double Enemy_DeltaTime = DeltaTime_GetDeltaTime();           // �ӵ��� �����ֱ� ���� ��ŸŸ�� ������

		// ���ο� �ð� ������ ���� �ӵ��� ���ƿ���
		if (Enemy_EnemyArr[index].Enemy_slowTime > 0)
		{
			Enemy_EnemyArr[index].Enemy_slowTime -= DeltaTime_GetDeltaTime();

			if (Enemy_EnemyArr[index].Enemy_slowTime <= 0)
			{
				Enemy_EnemyArr[index].Enemy_slowTime = 0;
				Enemy_EnemyArr[index].Enemy_Speed /= 0.4;
			}
		}

		// �� ���� �̵� ���� (�� �Լ��� ���� ����� �����...)
		if (Enemy_EnemyArr[index].Enemy_Xposition < 350 && Enemy_EnemyArr[index].Enemy_Yposition == 250)
		{
			Enemy_EnemyArr[index].Enemy_Xposition += (Enemy_EnemyArr[index].Enemy_Speed * Enemy_DeltaTime);
			if (Enemy_EnemyArr[index].Enemy_Xposition >= 350)
			{
				Enemy_EnemyArr[index].Enemy_Xposition = 350;
				Enemy_EnemyArr[index].Enemy_Headposition = eEnemy_Turn_Right;
			}
		}

		else if (Enemy_EnemyArr[index].Enemy_Xposition == 350 && Enemy_EnemyArr[index].Enemy_Yposition >= 250 && Enemy_EnemyArr[index].Enemy_Yposition < 650)
		{
			Enemy_EnemyArr[index].Enemy_Yposition += (Enemy_EnemyArr[index].Enemy_Speed * Enemy_DeltaTime);
			if (Enemy_EnemyArr[index].Enemy_Yposition >= 650)
			{
				Enemy_EnemyArr[index].Enemy_Yposition = 650;
				Enemy_EnemyArr[index].Enemy_Headposition = eEnemy_Turn_Left;
			}
		}

		else if (Enemy_EnemyArr[index].Enemy_Xposition < 650 && Enemy_EnemyArr[index].Enemy_Xposition >= 350 && Enemy_EnemyArr[index].Enemy_Yposition == 650)
		{
			Enemy_EnemyArr[index].Enemy_Xposition += (Enemy_EnemyArr[index].Enemy_Speed * Enemy_DeltaTime);
			if (Enemy_EnemyArr[index].Enemy_Xposition >= 650)
			{
				Enemy_EnemyArr[index].Enemy_Xposition = 650;
				Enemy_EnemyArr[index].Enemy_Headposition = eEnemy_Turn_Left;
			}
		}

		else if (Enemy_EnemyArr[index].Enemy_Xposition == 650 && Enemy_EnemyArr[index].Enemy_Yposition > 250 && Enemy_EnemyArr[index].Enemy_Yposition <= 650)
		{
			Enemy_EnemyArr[index].Enemy_Yposition -= (Enemy_EnemyArr[index].Enemy_Speed * Enemy_DeltaTime);
			if (Enemy_EnemyArr[index].Enemy_Yposition <= 250)
			{
				Enemy_EnemyArr[index].Enemy_Yposition = 250;
				Enemy_EnemyArr[index].Enemy_Headposition = eEnemy_Turn_Right;
			}
		}

		else if (Enemy_EnemyArr[index].Enemy_Xposition < 950 && Enemy_EnemyArr[index].Enemy_Xposition >= 650 && Enemy_EnemyArr[index].Enemy_Yposition == 250)
		{
			Enemy_EnemyArr[index].Enemy_Xposition += (Enemy_EnemyArr[index].Enemy_Speed * Enemy_DeltaTime);
			if (Enemy_EnemyArr[index].Enemy_Xposition >= 950)
			{
				Enemy_EnemyArr[index].Enemy_Xposition = 950;
				Enemy_EnemyArr[index].Enemy_Headposition = eEnemy_Turn_Right;
			}
		}

		else if (Enemy_EnemyArr[index].Enemy_Xposition == 950 && Enemy_EnemyArr[index].Enemy_Yposition >= 250 && Enemy_EnemyArr[index].Enemy_Yposition < 650)
		{
			Enemy_EnemyArr[index].Enemy_Yposition += (Enemy_EnemyArr[index].Enemy_Speed * Enemy_DeltaTime);
			if (Enemy_EnemyArr[index].Enemy_Yposition >= 650)
			{
				Enemy_EnemyArr[index].Enemy_Yposition = 650;
				Enemy_EnemyArr[index].Enemy_Headposition = eEnemy_Turn_Left;
			}
		}

		else if (Enemy_EnemyArr[index].Enemy_Xposition < 1250 && Enemy_EnemyArr[index].Enemy_Xposition >= 950 && Enemy_EnemyArr[index].Enemy_Yposition == 650)
		{
			Enemy_EnemyArr[index].Enemy_Xposition += (Enemy_EnemyArr[index].Enemy_Speed * Enemy_DeltaTime);
			if (Enemy_EnemyArr[index].Enemy_Xposition >= 1250)
			{
				Enemy_EnemyArr[index].Enemy_Xposition = 1250;
				Enemy_EnemyArr[index].Enemy_Headposition = eEnemy_Turn_Left;
			}
		}

		else if (Enemy_EnemyArr[index].Enemy_Xposition == 1250 && Enemy_EnemyArr[index].Enemy_Yposition > 250 && Enemy_EnemyArr[index].Enemy_Yposition <= 650)
		{
			Enemy_EnemyArr[index].Enemy_Yposition -= (Enemy_EnemyArr[index].Enemy_Speed * Enemy_DeltaTime);
			if (Enemy_EnemyArr[index].Enemy_Yposition <= 250)
			{
				Enemy_EnemyArr[index].Enemy_Yposition = 250;
				Enemy_EnemyArr[index].Enemy_Headposition = eEnemy_Turn_Right;
			}
		}

		else if (Enemy_EnemyArr[index].Enemy_Xposition < 1650 && Enemy_EnemyArr[index].Enemy_Xposition >= 1250 && Enemy_EnemyArr[index].Enemy_Yposition == 250)
		{
			Enemy_EnemyArr[index].Enemy_Xposition += (Enemy_EnemyArr[index].Enemy_Speed * Enemy_DeltaTime);
			if (Enemy_EnemyArr[index].Enemy_Xposition >= 1650)
			{
				Enemy_EnemyArr[index].Enemy_Xposition = 1650;
				// ���⼭ ���� ���� �ؾߵ�

				GameSystem_gameSystem.eState = GameSystem_eGameOver;
				UI_ReturnGameOver();
			}
		}
	}

	// ��ü 3�ʵ� ������
	if (Enemy_EnemyArr[index].Enemy_Type == eEnemy_Monster1_Dead ||
		Enemy_EnemyArr[index].Enemy_Type == eEnemy_Monster2_Dead)
	{
		Enemy_EnemyArr[index].Enemy_disappearTime -= DeltaTime_GetDeltaTime();

		if (Enemy_EnemyArr[index].Enemy_disappearTime <= 0)
		{
			Enemy_EnemyArr[index].Enemy_Type = eEnemy_Type_None;
		}
	}
}


