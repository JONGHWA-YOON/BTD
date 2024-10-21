#include <stdio.h>
#include "ObjectPool.h"


Enemy* ObjectPool_enemyArr[POOLSIZE]; 
//Enemy* MonsterPool[POOLSIZE];  // �̰� �ʿ���� �ʳ�..?

int index = 0; // Pool ��ġ ����ų �ε���


// void�� �ؾ��ϳ�... ������ �ؾ��ϳ�...
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
		ObjectPool_enemyArr[index] = ObjectPool_MonsterPool[index];  // ����Ʈ�� Ǯ�� �ִ°� �������
		ObjectPool_MonsterPool[index] = NULL;                        // Ǯ�� �ִ� �Ŵ� NULL
		index++;                                                     // ���� ĭ �̵�
	}
}

void ObjectPool_MonseterDisappear(Enemy** ObjectPool_MonsterPool, int ObjectPool_MonsterNum) // ���� �� ��� �迭���� num�� ���ڷ� �޾ƿ���
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