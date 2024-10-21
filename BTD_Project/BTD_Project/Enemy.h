#pragma once
#include <stdbool.h>

#define POOLSIZE 30

// 적 오브젝트 정보 관련 구조체 선언

typedef enum eEnemy_Turn  // 몹 바라보는 방향 나타내는 열거체
{
	eEnemy_Turn_None,  // 기본 모습 
	eEnemy_Turn_Left,  // 좌로 90도 회전시킴
	eEnemy_Turn_Right, // 우로 90도 회전시킴

}eEnemy_Head;

typedef enum eEnemy_Type  // 몹 상태 나타내주는 열거체
{
	eEnemy_Type_None,
	eEnemy_Monster1,
	eEnemy_Monster2,
	eEnemy_Monster1_Dead,
	eEnemy_Monster2_Dead

}eEnemy_Type;

typedef struct Enemy
{
	int index;
	double Enemy_Hp;      // 몹의 HP 
	double Enemy_Speed;   // 몹의 스피드 
	double Enemy_Xposition;  // 몹 X좌표
	double Enemy_Yposition;  // 몹 Y좌표
	eEnemy_Head Enemy_Headposition; // 몹 바라보는 방향
	eEnemy_Type Enemy_Type;         // 몹 유형

	double Enemy_slowTime;
	double Enemy_disappearTime;
	void (*Die)(int);
} Enemy;

// 외부에서 접근
extern Enemy Enemy_EnemyArr[POOLSIZE];

// 초기화 함수
void Enemy_InitEnemy();

// 배열 속에 있는 Enemy에게 스탯을 전달해줌
void Enemy_Stats(int Index, int WaveLevel, eEnemy_Type type);

// 몬스터 출현시킴 (배열 가리키는 인덱스, 웨이브 단계, 몬스터 타입)
void Enemy_UpdateSpawn(int Index, int WaveLevel, eEnemy_Type Type);

// 맵 따라 몬스터 이동하도록 + 헤드 위치 바뀌도록
void Enemy_UpdateMove(int Index);

// 몬스터 사라지게할때 몬스터 타입 none로 바꿈
void Enemy_Disappear(int);

// 게임 오버시 몬스터 사라짐
void Enemy_DisappearWhenGameOver();

Enemy* Enemy_GetEnemyInfo();