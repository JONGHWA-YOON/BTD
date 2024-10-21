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

/// ���� �����ϴ� �Ѿ˵� �����ҰŶ� ������ƮǮ��
typedef struct BulletList
{
	BulletNode* _beginNode;
	BulletNode* _endNode;
	int _size;

}BulletList;

// ��� �ϳ� �����Ҵ��ؼ� Ǯ�� �־��ִ°�
void Bullet_BulletObjectPoolMalloc();

// ��� ����
void Bullet_BulletPushNode(BulletList*, BulletNode*);

// ��� ����
BulletNode* Bullet_BulletEraseNode(BulletList* ,BulletNode*);

// źȯ �� �� ������ƮǮ���� �����ͼ� �� �ְ� �����
BulletNode* Bullet_GetBulletToObjectPool();

// źȯ �ǰ� �� or ����� �ڿ� �ٽ� Ǯ�� �����ֱ�
void Bullet_ReturnBulletToObjectPool(BulletNode*);

/// //////////////////////////////

/// ���� ���� �ÿ� �ʱ�ȭ ���ٰ�
void Bullet_InitBullet();

void Bullet_DeleteBullet();

/// �Ѿ� ���ư��� ��ġ ���� ���ֱ�
void Bullet_Update();

/// �Ѿ� �߻�
void Bullet_Shot(eBullet, int, int, Enemy*);

Bullet* Bullet_GetBulletInfo();
