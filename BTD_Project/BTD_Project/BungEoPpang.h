#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include "Bullet.h"
#include "Enemy.h"

typedef enum eBungEoPpangEnum
{
	// �곽 �ؾ�ε� Ÿ���̸� �ٲ�ߵ�
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


	// ���ڸ� , ���� �� ���� �ڸ�
	BungEoPpang_eNull,
	BungEoPpang_eCantUse,
}eBungEoPpangEnum;

typedef struct BungEoPpang
{
	// �곽 Ÿ�� �Ǽ��ϸ鼭 �ʱ�ȭ ���ֱ�
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

	// ȸ����?
}BungEoPpang;

extern BungEoPpang BungEoPpang_bungEoPpangArray[5][12];

/// �ؾ ����Ʈ
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

// �ؾ �迭 �ʱ�ȭ ���� �����Ҷ� ���ָ� ��
void BungEoPpang_InitBungEoPpang();

// ���� �������� �����Ҵ� Ǯ����
void BungEoPpang_DeleteBungEoPpang();

// ������Ʈ�� ��������ֱ� , �ؾ ���ݽ�Ŵ
void BungEoPpang_UpdateAttack();

/// Ÿ�� �߰� ���� �ռ�
bool BungEoPpang_AddBungEoPpang(int, int, eBungEoPpangEnum);

bool BungEoPpang_EraseBungEoPpang(int, int);

bool BungEoPpang_CombineBungEoPpang(int,int,int,int);

// ����Ʈ ���� �Լ�
void BungEoPpang_BungEoPpangPushNode(BungEoPpangNode*);

BungEoPpangNode* BungEoPpang_BungEoPpangEraseNode(BungEoPpangNode*);


/// Ÿ�� �ϳ��� ���� ���� �Լ�
// Ÿ�� ���ϰ���, ��Ƽ����, ��������

void BungEoPpang_Attack(BungEoPpang*);


// Ÿ���� �� �Ÿ� ���ϴ� �Լ�
double BungEoPpang_GetDistance(int, int, int, int);

BungEoPpang* BungEoPpang_GetBungEoPpang_bungEoPpangInfo();
