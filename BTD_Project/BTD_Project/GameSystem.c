#include "GameSystem.h"
#include "DeltaTime.h"
#include "Frame.h"
#include "Enemy.h"
#include "Bullet.h"
#include "BungEoPpang.h"
#include "Sound.h"
#include "UpgradeCommand.h"

GameSystem GameSystem_gameSystem;

void GameSystem_Update()
{
	
	

	GameSystem_InGame();


	GameSystem_Render();


	


}

void GameSystem_InGame()
{
		
	switch (GameSystem_gameSystem.eState)
	{
	case GameSystem_eWaveReady:
	{
		// �غ�ð�
		GameSystem_WaveReady();
		UpgradeCommand_WriteMyCommand();
		break;
	}
	case GameSystem_eWaveIng:
	{
		// ���̺� ��
		UpgradeCommand_WriteMyCommand();
		GameSystem_WaveEnemyCreate();

		GameSystem_WaveIng();

		break;
	}
	case GameSystem_eGameOver:
	{
		GameSystem_GameOver();
		break;
	}
	case GameSystem_eRobby:
	{

		break;
	}
	default:
		// ���� ���� ���� �� �Ǵ� ���� ���� ���� ��?��
		break;
	}
}

void GameSystem_Render()
{
	// ���� �Ұ� �߰����ּ���
	
}

void GameSystem_GameStart()
{
	GameSystem_InitGameSystem();
	// ���� ���� ������ƮǮ ä�쳪? �ƴϸ� ���α׷��� ���� ��?��

	Sound_PlaySound(InGame_Main);


	UpgradeCommand_InitUpgradeCommand();

	// Ÿ��, ����ü �ʱ�ȭ
	BungEoPpang_InitBungEoPpang();

	Bullet_InitBullet();

	GameSystem_gameSystem.eState = GameSystem_eWaveReady;
	
	Enemy_InitEnemy();
}

void GameSystem_InitGameSystem()
{
	GameSystem_gameSystem.eState = GameSystem_eRobby;
	GameSystem_gameSystem.nowWave = 0;
	GameSystem_gameSystem.readyTime = 0;
	GameSystem_gameSystem.upgradeCombo = 0;

	GameSystem_gameSystem.money = STARTGAMEMONEY;
}

void GameSystem_WaveReady()
{

	GameSystem_gameSystem.readyTime += DeltaTime_GetDeltaTime();

	// �غ�ð� ������ ó���Ұ͵�
	if (GameSystem_gameSystem.readyTime >= ROUNDREADYTIME)
	{
		GameSystem_gameSystem.nowWave += 1;
		
		GameSystem_gameSystem.enemyCreateCount = 0;
		GameSystem_gameSystem.enemyCreateDelay = ENEMYCREATEDELAYTIME;

		GameSystem_gameSystem.enemyKillCount = 0;

		GameSystem_gameSystem.eState = GameSystem_eWaveIng;
	}
}


void GameSystem_WaveEnemyCreate()
{
	// �� �� ���������� �����ϱ� ���߿� ť�� ���� �ɵ�
	if (GameSystem_gameSystem.enemyCreateCount >= ENEMYCREATECOUNT)
		return;

	GameSystem_gameSystem.enemyCreateDelay += DeltaTime_GetDeltaTime();

	// ���� ������ ���
	if (GameSystem_gameSystem.enemyCreateDelay < ENEMYCREATEDELAYTIME)
		return;

	
	// ���⿡ �� ���� �ڵ�
	Enemy_UpdateSpawn(
		GameSystem_gameSystem.enemyCreateCount,
		GameSystem_gameSystem.nowWave,
		(rand() % 2)+1); // ���� ����

	GameSystem_gameSystem.enemyCreateDelay = 0;
	GameSystem_gameSystem.enemyCreateCount += 1;
	
}

void GameSystem_WaveIng()
{
	// ���⿡ �� �������̳� Ÿ�� ���� ó���ص� �ɵ�?
	for(int i = 0 ; i < 30 ; i++)
		Enemy_UpdateMove(i);

	BungEoPpang_UpdateAttack();
	Bullet_Update();
	// �� �������� GameSystem_WaveEnd();

	if (GameSystem_gameSystem.enemyKillCount == ENEMYCREATECOUNT)
	{
		GameSystem_WaveEnd();
	}
}

void GameSystem_WaveEnd()
{
	// ���̺갡 ������ �غ���·� ����
	Enemy_DisappearWhenGameOver();
	GameSystem_gameSystem.eState = GameSystem_eWaveReady;
	GameSystem_gameSystem.readyTime = 0;
}

void GameSystem_GameOver()
{
	// ���� �߰�
	Enemy_DisappearWhenGameOver();
	Sound_PauseSound(InGame_Main);
	GameSystem_gameSystem.eState = GameSystem_eRobby;
	Sound_PlaySound(GameOver);
}

void GameSystem_DeleteGame()
{
	// ���� ���������� ���۾���
	if(Sound_GetisSoundOn() == 1)
	{
		Sound_DeleteSound();
		Sound_CreateSound();
	}

	// �̰� �κ�� ������ ������ҵ�?
	SaveRanking();
	BungEoPpang_DeleteBungEoPpang();
	Bullet_DeleteBullet();
	GameSystem_gameSystem.eState = GameSystem_eRobby;
}

int GameSystem_GetUpgradeCombo()
{
	return GameSystem_gameSystem.upgradeCombo;
}

void GameSystem_AddUpgradeCombo()
{
	// �޺� �ƽ� 999�ǵ��� ����
	if (GameSystem_gameSystem.upgradeCombo >= 999)
	{
		GameSystem_gameSystem.upgradeCombo = 999;
	}
	else
	{
		GameSystem_gameSystem.upgradeCombo += 1;
	}
}

void GameSystem_DownUpgradeCombo()
{
	if (GameSystem_gameSystem.upgradeCombo < 50)
	{
		GameSystem_gameSystem.upgradeCombo = 0;
	}
	else
	{
		GameSystem_gameSystem.upgradeCombo -= 50;
	}
}

double GameSystem_GetAttackDamageIncrease()
{
	return (GameSystem_gameSystem.upgradeCombo / 10) * 0.05;
}

int GameSystem_GetMoney()
{
	return GameSystem_gameSystem.money;
}

int* GameSystem_GetRankNumber()
{
	return &GameSystem_gameSystem.rankNumber;
}

int* GameSystem_GetRankArray()
{
	return (int*)GameSystem_gameSystem.rankArray;
}

int GameSystem_GetNowWave()
{
	return  GameSystem_gameSystem.nowWave;
}
