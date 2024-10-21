#include "Bullet.h"
#include "math.h"
#include "DeltaTime.h"
#include "GameSystem.h"
#define LEVLE1TOWER1DAMAGE 40
#define LEVLE1TOWER2DAMAGE 80
#define LEVLE1TOWER3DAMAGE 60


Bullet Bullet_bulletInfo[11] =
{
	// źȯ ����				���ݷ�							���ư��� �ӵ�		���ο� �ð�
	{ Bullet_e1_1		, LEVLE1TOWER1DAMAGE				,	 700	,		0		,0,0,0},
	{ Bullet_e1_2		, LEVLE1TOWER2DAMAGE				,	 700	,		0		,0,0,0},
	{ Bullet_e1_3		, LEVLE1TOWER3DAMAGE 				,	 700	,		1		,0,0,0},
	{ Bullet_e2_1		, LEVLE1TOWER1DAMAGE * 1.4			,	 700	,		0		,0,0,0},
	{ Bullet_e2_2		, LEVLE1TOWER2DAMAGE * 1.4			,	 700	,		0		,0,0,0},
	{ Bullet_e2_3		, LEVLE1TOWER3DAMAGE * 1.4			,	 700	,		1		,0,0,0},
	{ Bullet_e3_1		, LEVLE1TOWER1DAMAGE * 1.4 * 1.4	,	 700	,		0		,0,0,0},
	{ Bullet_e3_2		, LEVLE1TOWER2DAMAGE * 1.4 * 1.4	,	 700	,		0		,0,0,0},
	{ Bullet_e3_3		, LEVLE1TOWER3DAMAGE * 1.4 * 1.4	,	 700	,		1		,0,0,0},
	{ Bullet_e3_4		, 10								,	 700	,		1		,0,0,0},
	{ Bullet_e3_5		, 10								,	 700	,		1		,0,0,0},
};

BulletList Bullet_bulletList;

BulletList Bullet_bulletListObjectPool;

void Bullet_InitBullet()
{
	{	// ���� ������� źȯ ����Ʈ �ʱ�ȭ
		Bullet_bulletList._beginNode = (BulletNode*)malloc(sizeof(BulletNode));
		Bullet_bulletList._endNode = (BulletNode*)malloc(sizeof(BulletNode));

		Bullet_bulletList._beginNode->_prev = NULL;
		Bullet_bulletList._beginNode->_next = Bullet_bulletList._endNode;

		Bullet_bulletList._endNode->_prev = Bullet_bulletList._beginNode;
		Bullet_bulletList._endNode->_next = NULL;

		Bullet_bulletList._size = 0;
	}

	{	// ������ƮǮ ����Ʈ �ʱ�ȭ
		Bullet_bulletListObjectPool._beginNode = (BulletNode*)malloc(sizeof(BulletNode));
		Bullet_bulletListObjectPool._endNode = (BulletNode*)malloc(sizeof(BulletNode));

		Bullet_bulletListObjectPool._beginNode->_prev = NULL;
		Bullet_bulletListObjectPool._beginNode->_next = Bullet_bulletListObjectPool._endNode;

		Bullet_bulletListObjectPool._endNode->_prev = Bullet_bulletListObjectPool._beginNode;
		Bullet_bulletListObjectPool._endNode->_next = NULL;

		Bullet_bulletListObjectPool._size = 0;
	}

	for (int i = 0; i < 200; ++i)
	{
		Bullet_BulletObjectPoolMalloc();
	}

}

void Bullet_DeleteBullet()
{
	while (Bullet_bulletList._size != 0)
	{
		Bullet_BulletEraseNode(&Bullet_bulletList, Bullet_bulletList._beginNode->_next);
	}

	free(Bullet_bulletList._beginNode);
	free(Bullet_bulletList._endNode);

	while (Bullet_bulletListObjectPool._size != 0)
	{
		Bullet_BulletEraseNode(&Bullet_bulletListObjectPool, Bullet_bulletListObjectPool._beginNode->_next);
	}

	free(Bullet_bulletListObjectPool._beginNode);
	free(Bullet_bulletListObjectPool._endNode);

}

void Bullet_Update()
{
	BulletNode* node = Bullet_bulletList._beginNode->_next;
	while (node != Bullet_bulletList._endNode)
	{
		// �������� �Ἥ x y �� ���ÿ� �̵���ų�� ó���� ������ϴµ� ���ٸ��� �ϴ���

		Bullet* bullet = &node->_bullet;
		Enemy* target = node->_bullet.target;

		// �浹 �� Ÿ���� �̹� �׾����� ����
		if (target->Enemy_Hp <= 0)
		{
			node = node->_next;
			Bullet_BulletEraseNode(&Bullet_bulletList, node->_prev);
			continue;
		}

		// źȯ�� Ÿ�� �Ÿ�
		double distY = bullet->posY - target->Enemy_Yposition;
		double distX = bullet->posX - target->Enemy_Xposition;

		// źȯ�� �̵��� �Ÿ�
		double moveY = bullet->bulletSpeed * DeltaTime_GetDeltaTime();
		double moveX = bullet->bulletSpeed * DeltaTime_GetDeltaTime();

		// �̵��� �Ÿ����� ������
		{
			if (abs(distY) < moveY)
			{
				bullet->posY = target->Enemy_Yposition;
			}
			else
			{
				// źȯ�� Ÿ�ٺ��� �Ʒ�
				if (distY > 0)
				{
					moveY = -moveY;
				}

				bullet->posY += moveY;
			}

			if (abs(distX) < moveX)
			{
				bullet->posX = target->Enemy_Xposition;
			}
			else
			{
				// źȯ�� Ÿ�ٺ��� �Ʒ�
				if (distX > 0)
				{
					moveX = -moveX;
				}

				bullet->posX += moveX;
			}
		}

		// �̵� �� �浹üũ �� ü�� ��� �Ѿ� ����
		if (bullet->posX == target->Enemy_Xposition &&
			bullet->posY == target->Enemy_Yposition)
		{
			target->Enemy_Hp -= bullet->bulletDamage * (GameSystem_GetAttackDamageIncrease() + 1);

			if (target->Enemy_Hp <= 0)
			{
				target->Die(target->index);
			}

			// ���ο� ����
			{
				if (target->Enemy_slowTime < bullet->bulletSlow)
				{
					if(target->Enemy_slowTime <= 0)
					{
						target->Enemy_Speed *= 0.4;
					}

					target->Enemy_slowTime = bullet->bulletSlow;
				}
			}

			node = node->_next;
			Bullet_BulletEraseNode(&Bullet_bulletList, node->_prev);
			continue;
		}


		node = node->_next;
	}


}

void Bullet_BulletObjectPoolMalloc()
{
	BulletNode* newNode = (BulletNode*)malloc(sizeof(BulletNode));

	// �Ҵ� ����
	if (newNode == NULL)
	{
		return;
	}

	Bullet_BulletPushNode(&Bullet_bulletListObjectPool, newNode);
}

void Bullet_BulletPushNode(BulletList* list, BulletNode* node)
{
	node->_next = list->_beginNode->_next;
	list->_beginNode->_next = node;

	node->_prev = node->_next->_prev;
	node->_next->_prev = node;

	++list->_size;
}

BulletNode* Bullet_BulletEraseNode(BulletList* list, BulletNode* node)
{
	node->_prev->_next = node->_next;
	node->_next->_prev = node->_prev;

	--list->_size;

	return node;
}

BulletNode* Bullet_GetBulletToObjectPool()
{
	// ���� źȯ ������ �����ؼ� �־��ֱ�
	if (Bullet_bulletListObjectPool._size <= 0)
		Bullet_BulletObjectPoolMalloc();

	return Bullet_BulletEraseNode(&Bullet_bulletListObjectPool, Bullet_bulletListObjectPool._beginNode->_next);
}

void Bullet_ReturnBulletToObjectPool(BulletNode* node)
{
	Bullet_BulletEraseNode(&Bullet_bulletList, node);

	Bullet_BulletPushNode(&Bullet_bulletListObjectPool, node);
}

void Bullet_Shot(eBullet eType, int x, int y, Enemy* target)
{
	BulletNode* node = Bullet_GetBulletToObjectPool();

	node->_bullet = Bullet_bulletInfo[eType];
	node->_bullet.posX = x * 100 + 250;
	node->_bullet.posY = y * 100 + 250;
	node->_bullet.target = target;

	Bullet_BulletPushNode(&Bullet_bulletList, node);
}

Bullet* Bullet_GetBulletInfo()
{
	return Bullet_bulletInfo;
}
