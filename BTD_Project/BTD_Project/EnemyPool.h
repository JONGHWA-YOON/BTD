//#pragma once
#include "Enemy.h"
#include <stddef.h>

#define POOLSIZE 30 // Ǯ ������ 30���� ����


// ���� ������ �� Ǯ �ʱ�ȭ �Լ�
void ObjectPool_CreateMonsterPool(Enemy** ObjectPool_MonsterPool);


// ���� ���� �� ���� Ǯ �ı�!
void ObjectPool_DestroyPool(Enemy** ObjectPool_MonstePool);

