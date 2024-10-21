//#pragma once
#include "Enemy.h"
#include <stddef.h>

#define POOLSIZE 30 // Ǯ ������ 30���� ����


// ���� ������ �� Ǯ �ʱ�ȭ �Լ�
Enemy** ObjectPool_CreateMonsterPool(Enemy** ObjectPool_MonsterPool);

// �����Լ� - ���� ������ ����Ʈ�� �� 
void ObjectPool_MonsterAppear(Enemy** MonsterPool);

// �����Լ� - ���� ������ ����Ʈ���� ��������
void ObjectPool_MonseterDisappear(Enemy** MonsterPool, int num);

// ���� ���� �� ���� Ǯ �ı�!
void ObjectPool_DestroyPool(Enemy** ObjectPool_MonstePool);


// ���� �̵� ���� �Լ� - ���� �̱���
// void ObjectPool_MonsterMove(Enemy** enemyArr);