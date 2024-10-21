//#pragma once
#include "Enemy.h"
#include <stddef.h>

#define POOLSIZE 30 // 풀 사이즈 30으로 규정


// 게임 시작할 때 풀 초기화 함수
void ObjectPool_CreateMonsterPool(Enemy** ObjectPool_MonsterPool);


// 게임 끝날 때 몬스터 풀 파괴!
void ObjectPool_DestroyPool(Enemy** ObjectPool_MonstePool);

