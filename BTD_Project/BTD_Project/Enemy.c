#include "Enemy.h"
#include <stddef.h>
#include "DeltaTime.h"
#include "GameSystem.h"
#include <math.h>
#include "Sound.h"

Enemy Enemy_EnemyArr[POOLSIZE];  // 전역변수 설정

int WaveLevel = 1;

Enemy Enemy_EnemyInfo[3] =
{		//체력		속도
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
	
	Enemy_EnemyArr[Index].Enemy_Hp *= pow(1.15 , WaveLevel);        // 몬스터의 체력 (기본수치 하드코딩 + 웨이브 별 20% 증가)
	Enemy_EnemyArr[Index].Enemy_Speed = Enemy_EnemyInfo[type].Enemy_Speed * ((0.05 * WaveLevel) + 1);      // 몬스터의 이속 (기본수치 하드코딩 + 웨이브 별 5% 증가)
	Enemy_EnemyArr[Index].Enemy_Xposition = 0;
	Enemy_EnemyArr[Index].Enemy_Yposition = 250;
	Enemy_EnemyArr[Index].Enemy_Headposition = eEnemy_Turn_None;        // 처음에 사진 기본값
	Enemy_EnemyArr[Index].Enemy_Type = type;                // 기본값 0
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
		double Enemy_DeltaTime = DeltaTime_GetDeltaTime();           // 속도에 곱해주기 위해 델타타임 가져옴

		// 슬로우 시간 끝나면 정상 속도로 돌아오게
		if (Enemy_EnemyArr[index].Enemy_slowTime > 0)
		{
			Enemy_EnemyArr[index].Enemy_slowTime -= DeltaTime_GetDeltaTime();

			if (Enemy_EnemyArr[index].Enemy_slowTime <= 0)
			{
				Enemy_EnemyArr[index].Enemy_slowTime = 0;
				Enemy_EnemyArr[index].Enemy_Speed /= 0.4;
			}
		}

		// 맵 따라서 이동 설계 (얘 함수로 따로 뺄까말까 고민중...)
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
				// 여기서 게임 오버 해야됨

				GameSystem_gameSystem.eState = GameSystem_eGameOver;
				UI_ReturnGameOver();
			}
		}
	}

	// 시체 3초뒤 지워짐
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


