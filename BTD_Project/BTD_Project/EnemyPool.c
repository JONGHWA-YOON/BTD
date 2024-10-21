#include <stdio.h>
#include "EnemyPool.h"


void EnemyPool_CreateMonsterPool(Enemy** EnemyPool_MonsterPool)
{
	for (int i = 0; i < POOLSIZE; i++)
	{
		EnemyPool_MonsterPool[i] = (Enemy*)malloc(sizeof(Enemy));
	}
}


void EnemyPool_DestroyPool(Enemy** EnemyPool_MonstePool)
{
	for (int i = 0; i < POOLSIZE; i++)
	{
		free(EnemyPool_MonstePool[i]);
	}
}