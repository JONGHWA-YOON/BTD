#pragma once


//#include "Enemy.h"
// ���� �غ� �ð�
#define ROUNDREADYTIME 5

// �� ���� ������ �ð�
#define ENEMYCREATEDELAYTIME 0.4f

// ���帶�� �� ���� ����
#define ENEMYCREATECOUNT 30

// �����Ҷ� ��
#define STARTGAMEMONEY 1000

#define ENEMYKILLMONOY 20

// ���ݷ� ������
#define ATTACKDAMAGEBONUS 0.1

// ���� ���� ���¸� �����ϴ� enum
typedef enum eGameSystemState
{
	GameSystem_eRobby,
	GameSystem_eWaveReady,
	GameSystem_eWaveIng,
	GameSystem_eGameOver,

}eGameSystemState;


// ���� ���� ����
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

// �� ������ ���� ���� ������Ʈ �ؾ��ϴ� ��
void GameSystem_Update();

// �� ������ �ΰ��� ����?
void GameSystem_InGame();

// �� ������ ���� ���� 
void GameSystem_Render();



// ���ӽ��� ��ư �������� ����
void GameSystem_GameStart();

// GameSystem ����ü �ʱ�ȭ
void GameSystem_InitGameSystem();

/// InGame ���̺� ���� ////////////
// ���� �غ�ð��� �����ؾߵɰ�
void GameSystem_WaveReady();

// ���̺� ���� -> �� ����
void GameSystem_WaveEnemyCreate();

// ���̺� �� -> �� �̵��̳� Ÿ�� ����
void GameSystem_WaveIng();

// ���̺� �� -> �غ�ð�
void GameSystem_WaveEnd();
/// //////////////////

// ���� ����
void GameSystem_GameOver();

// �����, �κ� ������ �Ҷ� ȣ�����ּ���
void GameSystem_DeleteGame();

// �޺� ���� ����
int GameSystem_GetUpgradeCombo();

void GameSystem_AddUpgradeCombo();

void GameSystem_DownUpgradeCombo();

// 10�� 0.05
double GameSystem_GetAttackDamageIncrease();

// ��
int GameSystem_GetMoney();

// ��ŷ ����
int* GameSystem_GetRankNumber();

int* GameSystem_GetRankArray();

int GameSystem_GetNowWave();
