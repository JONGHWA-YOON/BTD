#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include "Bullet.h"
#include "Enemy.h"

typedef enum eBungEoPpangEnum
{
	// 얘낸 붕어빵인데 타워이름 바꿔야됨
	BungEoPpang_e1_1,
	BungEoPpang_e1_2,
	BungEoPpang_e1_3,
	BungEoPpang_e2_1,
	BungEoPpang_e2_2,
	BungEoPpang_e2_3,
	BungEoPpang_e3_1,
	BungEoPpang_e3_2,
	BungEoPpang_e3_3,
	BungEoPpang_e3_4,
	BungEoPpang_e3_5,


	// 빈자리 , 놓을 수 없는 자리
	BungEoPpang_eNull,
	BungEoPpang_eCantUse,
}eBungEoPpangEnum;

typedef struct BungEoPpang
{
	// 얘낸 타워 건설하면서 초기화 해주기
	eBungEoPpangEnum kind;

	double attackSpeed;

	double attackRange;
	
	int attackCount;

	eBullet ebullet;

	/// /////////////

	int y;
	int x;

	double attackNowDelay;
	int attackCountNow;

	Enemy* target;

	struct BungEoPpangNode* _node;

	// 회전각?
}BungEoPpang;

extern BungEoPpang BungEoPpang_bungEoPpangArray[5][12];

/// 붕어빵 리스트
typedef struct BungEoPpangNode
{
	struct BungEoPpangNode* _prev;
	struct BungEoPpangNode* _next;

	BungEoPpang* _bungEoPpang;
}BungEoPpangNode;

typedef struct BungEoPpangList
{
	BungEoPpangNode* _beginNode;
	BungEoPpangNode* _endNode;
	int _size;

}BungEoPpangList;

// 붕어빵 배열 초기화 게임 시작할때 해주면 됨
void BungEoPpang_InitBungEoPpang();

// 게임 끝날을때 동적할당 풀어줌
void BungEoPpang_DeleteBungEoPpang();

// 업데이트때 실행시켜주기 , 붕어빵 공격시킴
void BungEoPpang_UpdateAttack();

/// 타워 추가 삭제 합성
bool BungEoPpang_AddBungEoPpang(int, int, eBungEoPpangEnum);

bool BungEoPpang_EraseBungEoPpang(int, int);

bool BungEoPpang_CombineBungEoPpang(int,int,int,int);

// 리스트 관련 함수
void BungEoPpang_BungEoPpangPushNode(BungEoPpangNode*);

BungEoPpangNode* BungEoPpang_BungEoPpangEraseNode(BungEoPpangNode*);


/// 타워 하나의 동작 관련 함수
// 타워 단일공격, 멀티공격, 범위공격

void BungEoPpang_Attack(BungEoPpang*);


// 타워와 몹 거리 구하는 함수
double BungEoPpang_GetDistance(int, int, int, int);

BungEoPpang* BungEoPpang_GetBungEoPpang_bungEoPpangInfo();
