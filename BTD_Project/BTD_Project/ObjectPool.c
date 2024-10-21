#include <stdio.h>
#include "ObjectPool.h"


Enemy* ObjectPool_enemyArr[POOLSIZE]; 
//Enemy* MonsterPool[POOLSIZE];  // 이거 필요없지 않나..?

int index = 0; // Pool 위치 가르킬 인덱스


// void로 해야하나... 리턴을 해야하나...
Enemy** ObjectPool_CreateMonsterPool(Enemy** ObjectPool_MonsterPool)
{
	for (int i = 0; i < POOLSIZE; i++)
	{
		ObjectPool_MonsterPool[i] = (Enemy*)malloc(sizeof(Enemy));
	}
	return ObjectPool_MonsterPool;
}

void ObjectPool_MonsterAppear(Enemy** ObjectPool_MonsterPool)  
{
	if (index == 30)
	{
		index = 0;
	}

	if (index < 30)
	{
		ObjectPool_enemyArr[index] = ObjectPool_MonsterPool[index];  // 리스트에 풀에 있는것 집어넣음
		ObjectPool_MonsterPool[index] = NULL;                        // 풀에 있던 거는 NULL
		index++;                                                     // 다음 칸 이동
	}
}

void ObjectPool_MonseterDisappear(Enemy** ObjectPool_MonsterPool, int ObjectPool_MonsterNum) // 죽은 애 몇번 배열인지 num을 인자로 받아오면
{
	ObjectPool_MonsterPool[ObjectPool_MonsterNum] = ObjectPool_enemyArr[ObjectPool_MonsterNum];            
	ObjectPool_enemyArr[ObjectPool_MonsterNum] = NULL;                      
}


void ObjectPool_DestroyPool(Enemy** ObjectPool_MonstePool)
{
	for (int i = 0; i < POOLSIZE; i++)
	{
		free(ObjectPool_MonstePool[i]);
	}
}