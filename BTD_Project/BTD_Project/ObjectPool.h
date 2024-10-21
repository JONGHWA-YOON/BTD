//#pragma once
#include "Enemy.h"
#include <stddef.h>

#define POOLSIZE 30 // 풀 사이즈 30으로 규정


// 게임 시작할 때 풀 초기화 함수
Enemy** ObjectPool_CreateMonsterPool(Enemy** ObjectPool_MonsterPool);

// 생성함수 - 몬스터 출현시 리스트에 들어감 
void ObjectPool_MonsterAppear(Enemy** MonsterPool);

// 제거함수 - 몬스터 죽을시 리스트에서 빠져나감
void ObjectPool_MonseterDisappear(Enemy** MonsterPool, int num);

// 게임 끝날 때 몬스터 풀 파괴!
void ObjectPool_DestroyPool(Enemy** ObjectPool_MonstePool);


// 몬스터 이동 관련 함수 - 아직 미구현
// void ObjectPool_MonsterMove(Enemy** enemyArr);