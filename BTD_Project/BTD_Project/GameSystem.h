#pragma once


//#include "Enemy.h"
// 라운드 준비 시간
#define ROUNDREADYTIME 5

// 몹 생성 딜레이 시간
#define ENEMYCREATEDELAYTIME 0.4f

// 라운드마다 몹 생성 개수
#define ENEMYCREATECOUNT 30

// 시작할때 돈
#define STARTGAMEMONEY 1000

#define ENEMYKILLMONOY 20

// 공격력 증가량
#define ATTACKDAMAGEBONUS 0.1

// 현재 게임 상태를 정의하는 enum
typedef enum eGameSystemState
{
	GameSystem_eRobby,
	GameSystem_eWaveReady,
	GameSystem_eWaveIng,
	GameSystem_eGameOver,

}eGameSystemState;


// 현재 게임 상태
typedef struct GameSystem
{
	eGameSystemState eState;
	int nowWave;
	double readyTime;
	double enemyCreateDelay;
	int enemyCreateCount;
	int enemyKillCount;

	int upgradeCombo;
	int attackDamageIncrease;

	int money;

	int rankNumber;
	int rankArray[10][2];
}GameSystem;

extern GameSystem GameSystem_gameSystem;

// 매 프레임 게임 정보 업데이트 해야하는 곳
void GameSystem_Update();

// 매 프레임 인게임 연산?
void GameSystem_InGame();

// 매 프레임 게임 랜더 
void GameSystem_Render();



// 게임시작 버튼 눌렀을때 실행
void GameSystem_GameStart();

// GameSystem 구조체 초기화
void GameSystem_InitGameSystem();

/// InGame 웨이브 관련 ////////////
// 라운드 준비시간때 실행해야될것
void GameSystem_WaveReady();

// 웨이브 시작 -> 몹 생성
void GameSystem_WaveEnemyCreate();

// 웨이브 중 -> 몹 이동이나 타워 공격
void GameSystem_WaveIng();

// 웨이브 끝 -> 준비시간
void GameSystem_WaveEnd();
/// //////////////////

// 게임 종료
void GameSystem_GameOver();

// 재시작, 로비 나가기 할때 호출해주세용
void GameSystem_DeleteGame();

// 콤보 업글 관련
int GameSystem_GetUpgradeCombo();

void GameSystem_AddUpgradeCombo();

void GameSystem_DownUpgradeCombo();

// 10당 0.05
double GameSystem_GetAttackDamageIncrease();

// 돈
int GameSystem_GetMoney();

// 랭킹 관련
int* GameSystem_GetRankNumber();

int* GameSystem_GetRankArray();

int GameSystem_GetNowWave();
