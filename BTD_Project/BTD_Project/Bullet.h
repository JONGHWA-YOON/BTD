#pragma once
#include <stdlib.h>
#include "Enemy.h"
#include "DeltaTime.h"
#include "DeltaTime.h"



typedef enum eBullet
{
	Bullet_e1_1,
	Bullet_e1_2,
	Bullet_e1_3,
	Bullet_e2_1,
	Bullet_e2_2,
	Bullet_e2_3,
	Bullet_e3_1,
	Bullet_e3_2,
	Bullet_e3_3,
	Bullet_e3_4,
	Bullet_e3_5,
}eBullet;

typedef struct Bullet
{
	eBullet bulletType;
	double bulletDamage;
	double bulletSpeed;
	double bulletSlow;

	double posY;
	double posX;

	Enemy* target;
}Bullet;

typedef struct BulletNode
{
	struct BulletNode* _prev;
	struct BulletNode* _next;

	Bullet _bullet;

}BulletNode;

/// 현재 존재하는 총알들 관리할거랑 오브젝트풀용
typedef struct BulletList
{
	BulletNode* _beginNode;
	BulletNode* _endNode;
	int _size;

}BulletList;

// 노드 하나 동적할당해서 풀에 넣어주는거
void Bullet_BulletObjectPoolMalloc();

// 노드 삽입
void Bullet_BulletPushNode(BulletList*, BulletNode*);

// 노드 삭제
BulletNode* Bullet_BulletEraseNode(BulletList* ,BulletNode*);

// 탄환 쏠 때 오브젝트풀에서 가져와서 값 넣고 쓰면됨
BulletNode* Bullet_GetBulletToObjectPool();

// 탄환 피격 후 or 사라진 뒤에 다시 풀에 돌려주기
void Bullet_ReturnBulletToObjectPool(BulletNode*);

/// //////////////////////////////

/// 게임 시작 시에 초기화 해줄것
void Bullet_InitBullet();

void Bullet_DeleteBullet();

/// 총알 날아가는 위치 연산 해주기
void Bullet_Update();

/// 총알 발사
void Bullet_Shot(eBullet, int, int, Enemy*);

Bullet* Bullet_GetBulletInfo();
