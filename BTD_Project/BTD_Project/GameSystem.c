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
		// 준비시간
		GameSystem_WaveReady();
		UpgradeCommand_WriteMyCommand();
		break;
	}
	case GameSystem_eWaveIng:
	{
		// 웨이브 중
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
		// 아직 게임 시작 전 또는 현재 게임 상태 몰?루
		break;
	}
}

void GameSystem_Render()
{
	// 랜더 할거 추가해주세용
	
}

void GameSystem_GameStart()
{
	GameSystem_InitGameSystem();
	// 게임 시작 오브젝트풀 채우나? 아니면 프로그램이 실행 될?때

	Sound_PlaySound(InGame_Main);


	UpgradeCommand_InitUpgradeCommand();

	// 타워, 투사체 초기화
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

	// 준비시간 끝나면 처리할것들
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
	// 몹 덜 생성했으면 생성하기 나중에 큐로 빼도 될듯
	if (GameSystem_gameSystem.enemyCreateCount >= ENEMYCREATECOUNT)
		return;

	GameSystem_gameSystem.enemyCreateDelay += DeltaTime_GetDeltaTime();

	// 생성 딜레이 대기
	if (GameSystem_gameSystem.enemyCreateDelay < ENEMYCREATEDELAYTIME)
		return;

	
	// 여기에 몹 생성 코드
	Enemy_UpdateSpawn(
		GameSystem_gameSystem.enemyCreateCount,
		GameSystem_gameSystem.nowWave,
		(rand() % 2)+1); // 랜덤 생성

	GameSystem_gameSystem.enemyCreateDelay = 0;
	GameSystem_gameSystem.enemyCreateCount += 1;
	
}

void GameSystem_WaveIng()
{
	// 여기에 몹 움직임이나 타워 공격 처리해도 될듯?
	for(int i = 0 ; i < 30 ; i++)
		Enemy_UpdateMove(i);

	BungEoPpang_UpdateAttack();
	Bullet_Update();
	// 몹 다잡으면 GameSystem_WaveEnd();

	if (GameSystem_gameSystem.enemyKillCount == ENEMYCREATECOUNT)
	{
		GameSystem_WaveEnd();
	}
}

void GameSystem_WaveEnd()
{
	// 웨이브가 끝나면 준비상태로 변경
	Enemy_DisappearWhenGameOver();
	GameSystem_gameSystem.eState = GameSystem_eWaveReady;
	GameSystem_gameSystem.readyTime = 0;
}

void GameSystem_GameOver()
{
	// 내용 추가
	Enemy_DisappearWhenGameOver();
	Sound_PauseSound(InGame_Main);
	GameSystem_gameSystem.eState = GameSystem_eRobby;
	Sound_PlaySound(GameOver);
}

void GameSystem_DeleteGame()
{
	// 사운드 꺼져있으면 동작안함
	if(Sound_GetisSoundOn() == 1)
	{
		Sound_DeleteSound();
		Sound_CreateSound();
	}

	// 이건 로비로 나갈때 해줘야할듯?
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
	// 콤보 맥스 999되도록 수정
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
