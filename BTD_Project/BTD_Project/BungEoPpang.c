#include "BungEoPpang.h"
#include "DeltaTime.h"
#include <math.h>
#include "GameSystem.h"
#include "Sound.h"
#include <stdio.h>

BungEoPpang BungEoPpang_bungEoPpangInfo[11] =
{
	// Ÿ�� ����		  /	  ���� / ��Ÿ�	/	Ÿ��Ƚ��  /  ��� źȯ
	{ BungEoPpang_e1_1	, 0.5	,	200		,	1	,	Bullet_e1_1		,0,0,0,0,0,0},
	{ BungEoPpang_e1_2	, 0.8	,	150		,	2	,	Bullet_e1_2		,0,0,0,0,0,0},
	{ BungEoPpang_e1_3	, 0.2	,	120		,	30	,	Bullet_e1_3		,0,0,0,0,0,0},
	{ BungEoPpang_e2_1	, 0.2	,	200		,	1	,	Bullet_e2_1		,0,0,0,0,0,0},
	{ BungEoPpang_e2_2	, 0.2	,	200		,	3	,	Bullet_e2_2		,0,0,0,0,0,0},
	{ BungEoPpang_e2_3	, 0.2	,	200		,	30	,	Bullet_e2_3		,0,0,0,0,0,0},
	{ BungEoPpang_e3_1	, 0.2	,	200		,	1	,	Bullet_e3_1		,0,0,0,0,0,0},
	{ BungEoPpang_e3_2	, 0.2	,	200		,	4	,	Bullet_e3_2		,0,0,0,0,0,0},
	{ BungEoPpang_e3_3	, 0.2	,	200		,	30	,	Bullet_e3_3		,0,0,0,0,0,0},
	{ BungEoPpang_e3_4	, 0.2	,	200		,	1	,	Bullet_e3_4		,0,0,0,0,0,0},
	{ BungEoPpang_e3_5	, 0.2	,	200		,	1	,	Bullet_e3_5		,0,0,0,0,0,0},
};

BungEoPpang BungEoPpang_bungEoPpangArray[5][12];

BungEoPpangList BungEoPpang_bungEoPpangList;

void BungEoPpang_InitBungEoPpang()
{
	//�ؾ �����鼭 �����Ҵ�
	for (int y = 0; y < 5; ++y)
	{
		for (int x = 0; x < 12; ++x)
		{
			BungEoPpang_bungEoPpangArray[y][x].y = y;
			BungEoPpang_bungEoPpangArray[y][x].x = x;
			BungEoPpang_bungEoPpangArray[y][x].kind = BungEoPpang_eNull;

			do
			{
				BungEoPpang_bungEoPpangArray[y][x]._node = (BungEoPpangNode*)malloc(sizeof(BungEoPpangNode));
			} while (BungEoPpang_bungEoPpangArray[y][x]._node == NULL);

			BungEoPpang_bungEoPpangArray[y][x]._node->_bungEoPpang = &BungEoPpang_bungEoPpangArray[y][x];
		}
	}

	// �ؾ ������ �ڸ���
	{
		{
			int tempX[] = { 0, 5,6, 11 };
			for (int i = 0; i < (sizeof(tempX) / sizeof(int)); ++i)
			{
				BungEoPpang_bungEoPpangArray[0][tempX[i]].kind = BungEoPpang_eCantUse;
			}
		}
		{
			int tempX[] = { 2,3,8,9 };
			for (int i = 0; i < (sizeof(tempX) / sizeof(int)); ++i)
			{
				BungEoPpang_bungEoPpangArray[4][tempX[i]].kind = BungEoPpang_eCantUse;
			}
		}
		{
			int tempY[] = { 0,1,2,3,4 };
			for (int i = 0; i < (sizeof(tempY) / sizeof(int)); ++i)
			{
				BungEoPpang_bungEoPpangArray[tempY[i]][1].kind = BungEoPpang_eCantUse;
				BungEoPpang_bungEoPpangArray[tempY[i]][4].kind = BungEoPpang_eCantUse;
				BungEoPpang_bungEoPpangArray[tempY[i]][7].kind = BungEoPpang_eCantUse;
				BungEoPpang_bungEoPpangArray[tempY[i]][10].kind = BungEoPpang_eCantUse;
			}
		}
	}

	// ����Ʈ �ʱ�ȭ
	{
		BungEoPpang_bungEoPpangList._beginNode = (BungEoPpangNode*)malloc(sizeof(BungEoPpangNode));
		BungEoPpang_bungEoPpangList._endNode = (BungEoPpangNode*)malloc(sizeof(BungEoPpangNode));

		BungEoPpang_bungEoPpangList._beginNode->_prev = NULL;
		BungEoPpang_bungEoPpangList._beginNode->_next = BungEoPpang_bungEoPpangList._endNode;

		BungEoPpang_bungEoPpangList._endNode->_prev = BungEoPpang_bungEoPpangList._beginNode;
		BungEoPpang_bungEoPpangList._endNode->_next = NULL;
		BungEoPpang_bungEoPpangList._size = 0;
	}
}

void BungEoPpang_DeleteBungEoPpang()
{
	for (int y = 0; y < 5; ++y)
	{
		for (int x = 0; x < 12; ++x)
		{
			free(BungEoPpang_bungEoPpangArray[y][x]._node);
			BungEoPpang_bungEoPpangArray[y][x]._node = NULL;
		}
	}

	free(BungEoPpang_bungEoPpangList._beginNode);
	free(BungEoPpang_bungEoPpangList._endNode);
}

void BungEoPpang_UpdateAttack()
{
	for (BungEoPpangNode* node = BungEoPpang_bungEoPpangList._beginNode->_next;
		node != BungEoPpang_bungEoPpangList._endNode; node = node->_next)
	{
		node->_bungEoPpang->attackNowDelay += DeltaTime_GetDeltaTime();

		// ���� �����̰� ���� �ʾҴٸ� �����ɷ�
		if (node->_bungEoPpang->attackNowDelay < node->_bungEoPpang->attackSpeed)
		{
			continue;
		}

		// �������ֱ�

		BungEoPpang_Attack(node->_bungEoPpang);

		node->_bungEoPpang->attackNowDelay = 0;
	}
}

bool BungEoPpang_AddBungEoPpang(int y, int x, eBungEoPpangEnum eKind)
{
	if (BungEoPpang_bungEoPpangArray[y][x].kind != BungEoPpang_eNull)
	{
		return false;
	}

	// �ؾ �� �����ϰ� ����
	{
		if (eKind == BungEoPpang_e1_1)
		{
			if (GameSystem_gameSystem.money < 500)
			{
				return false;
			}
			GameSystem_gameSystem.money -= 500;
		}
		else if (eKind == BungEoPpang_e1_2)
		{
			if (GameSystem_gameSystem.money < 750)
			{
				return false;
			}
			GameSystem_gameSystem.money -= 750;
		}
		else if (eKind == BungEoPpang_e1_3)
		{
			if (GameSystem_gameSystem.money < 1000)
			{
				return false;
			}
			GameSystem_gameSystem.money -= 1000;
		}
	}

	BungEoPpang_bungEoPpangArray[y][x].kind = eKind;
	BungEoPpang_bungEoPpangArray[y][x].attackSpeed = BungEoPpang_bungEoPpangInfo[eKind].attackSpeed;
	BungEoPpang_bungEoPpangArray[y][x].attackRange = BungEoPpang_bungEoPpangInfo[eKind].attackRange;
	BungEoPpang_bungEoPpangArray[y][x].attackCount = BungEoPpang_bungEoPpangInfo[eKind].attackCount;
	BungEoPpang_bungEoPpangArray[y][x].ebullet = BungEoPpang_bungEoPpangInfo[eKind].ebullet;

	// �ؾ ����Ʈ �߰�
	BungEoPpang_BungEoPpangPushNode(BungEoPpang_bungEoPpangArray[y][x]._node);

	return true;
}

bool BungEoPpang_EraseBungEoPpang(int y, int x)
{
	if (BungEoPpang_bungEoPpangArray[y][x].kind == BungEoPpang_eNull ||
		BungEoPpang_bungEoPpangArray[y][x].kind == BungEoPpang_eCantUse)
	{
		return false;
	}

	BungEoPpang_bungEoPpangArray[y][x].kind = BungEoPpang_eNull;

	// �ؾ ����Ʈ ����
	BungEoPpang_BungEoPpangEraseNode(BungEoPpang_bungEoPpangArray[y][x]._node);

	return true;
}

// x1 y1 �� �ű� �ؾ x2 y2 �ڸ��� �ռ��� Ÿ���� ���;ߵ�
bool BungEoPpang_CombineBungEoPpang(int x1, int y1, int x2, int y2)
{
	if (x1 == x2 && y1 == y2)
	{
		return false;
	}

	eBungEoPpangEnum bung1 = BungEoPpang_bungEoPpangArray[y1][x1].kind;
	eBungEoPpangEnum bung2 = BungEoPpang_bungEoPpangArray[y2][x2].kind;

	// ������ �ռ�
	if (bung1 == bung2)
	{
		switch (bung1)
		{
		case BungEoPpang_e1_1:
		{
			BungEoPpang_EraseBungEoPpang(y1, x1);
			BungEoPpang_EraseBungEoPpang(y2, x2);

			BungEoPpang_AddBungEoPpang(y2, x2, BungEoPpang_e2_1);
			Sound_PlaySound(Bungeoppang_Synthesis);
			return true;
		}
		case BungEoPpang_e1_2:
		{
			BungEoPpang_EraseBungEoPpang(y1, x1);
			BungEoPpang_EraseBungEoPpang(y2, x2);

			BungEoPpang_AddBungEoPpang(y2, x2, BungEoPpang_e2_2);
			Sound_PlaySound(Bungeoppang_Synthesis);
			return true;
		}
		case BungEoPpang_e1_3:
		{
			BungEoPpang_EraseBungEoPpang(y1, x1);
			BungEoPpang_EraseBungEoPpang(y2, x2);

			BungEoPpang_AddBungEoPpang(y2, x2, BungEoPpang_e2_3);
			Sound_PlaySound(Bungeoppang_Synthesis);
			return true;
		}
		case BungEoPpang_e2_1:
		{
			BungEoPpang_EraseBungEoPpang(y1, x1);
			BungEoPpang_EraseBungEoPpang(y2, x2);

			BungEoPpang_AddBungEoPpang(y2, x2, BungEoPpang_e3_1);
			Sound_PlaySound(Bungeoppang_Synthesis);
			return true;
		}
		case BungEoPpang_e2_2:
		{
			BungEoPpang_EraseBungEoPpang(y1, x1);
			BungEoPpang_EraseBungEoPpang(y2, x2);

			BungEoPpang_AddBungEoPpang(y2, x2, BungEoPpang_e3_2);
			Sound_PlaySound(Bungeoppang_Synthesis);
			return true;
		}
		case BungEoPpang_e2_3:
		{
			BungEoPpang_EraseBungEoPpang(y1, x1);
			BungEoPpang_EraseBungEoPpang(y2, x2);

			BungEoPpang_AddBungEoPpang(y2, x2, BungEoPpang_e3_3);
			Sound_PlaySound(Bungeoppang_Synthesis);
			return true;
		}
		default:
			return false;
		}
	}

	// �ٸ��� �ռ� 2_3 + 2_1 or 2_3 + 2_2
	else if (bung1 == BungEoPpang_e2_3 || bung2 == BungEoPpang_e2_3)
	{
		// 1���� 2_3�� ������
		if (bung1 != BungEoPpang_e2_3)
		{
			eBungEoPpangEnum temp = bung1;
			bung1 = bung2;
			bung2 = temp;
		}

		if (bung2 == BungEoPpang_e2_1)
		{
			BungEoPpang_EraseBungEoPpang(y1, x1);
			BungEoPpang_EraseBungEoPpang(y2, x2);

			BungEoPpang_AddBungEoPpang(y2, x2, BungEoPpang_e3_4);
			Sound_PlaySound(Bungeoppang_Synthesis);
			return true;
		}
		else if (bung2 == BungEoPpang_e2_2)
		{
			BungEoPpang_EraseBungEoPpang(y1, x1);
			BungEoPpang_EraseBungEoPpang(y2, x2);

			BungEoPpang_AddBungEoPpang(y2, x2, BungEoPpang_e3_5);
			Sound_PlaySound(Bungeoppang_Synthesis);
			return true;
		}

	}
	return false;
}

void BungEoPpang_BungEoPpangPushNode(BungEoPpangNode* node)
{
	node->_next = BungEoPpang_bungEoPpangList._beginNode->_next;
	BungEoPpang_bungEoPpangList._beginNode->_next = node;

	node->_prev = node->_next->_prev;
	node->_next->_prev = node;

	++BungEoPpang_bungEoPpangList._size;
}

BungEoPpangNode* BungEoPpang_BungEoPpangEraseNode(BungEoPpangNode* node)
{
	BungEoPpangNode* reNode = node->_next;

	node->_prev->_next = node->_next;
	node->_next->_prev = node->_prev;

	--BungEoPpang_bungEoPpangList._size;

	return reNode;
}


void BungEoPpang_Attack(BungEoPpang* bungEoPpang)
{
	// ���� �� �� ���� ���
	for (int i = 0; i < sizeof(Enemy_EnemyArr) / sizeof(Enemy); ++i)
	{
		if (Enemy_EnemyArr[i].Enemy_Hp <= 0)
			continue;

		// Ÿ���� ���� �Ÿ�
		double dist = BungEoPpang_GetDistance(
			(int)Enemy_EnemyArr[i].Enemy_Xposition,
			bungEoPpang->x,
			(int)Enemy_EnemyArr[i].Enemy_Yposition,
			bungEoPpang->y);

		// ��Ÿ� ���� ������ �� 
		if (dist <= bungEoPpang->attackRange)
		{
			Sound_PlaySound(Bungeoppang_Attack);
			Bullet_Shot(bungEoPpang->ebullet, bungEoPpang->x, bungEoPpang->y, &Enemy_EnemyArr[i]);

			//������ Ƚ�� �ø���
			bungEoPpang->attackCountNow += 1;
			if (bungEoPpang->attackCountNow == bungEoPpang->attackCount)
			{
				break;
			}
		}
	}

	// ������ ����Ƚ�� �ʱ�ȭ
	bungEoPpang->attackCountNow = 0;
}


/// <param name="x1">Enemy�� X��ǥ</param>
/// <param name="x2">Ÿ���� X��ǥ</param>
/// <param name="y1">Enemy�� Y��ǥ</param>
/// <param name="y2">Ÿ���� Y��ǥ</param>
double BungEoPpang_GetDistance(int x1, int x2, int y1, int y2)
{
	return sqrt(pow(x1 - ((x2 * 100) + 250), 2) + pow(y1 - ((y2 * 100) + 250), 2));
}

BungEoPpang* BungEoPpang_GetBungEoPpang_bungEoPpangInfo()
{
	return BungEoPpang_bungEoPpangInfo;
}
