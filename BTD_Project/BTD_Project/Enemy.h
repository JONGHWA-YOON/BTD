#pragma once
#include <stdbool.h>

#define POOLSIZE 30

// �� ������Ʈ ���� ���� ����ü ����

typedef enum eEnemy_Turn  // �� �ٶ󺸴� ���� ��Ÿ���� ����ü
{
	eEnemy_Turn_None,  // �⺻ ��� 
	eEnemy_Turn_Left,  // �·� 90�� ȸ����Ŵ
	eEnemy_Turn_Right, // ��� 90�� ȸ����Ŵ

}eEnemy_Head;

typedef enum eEnemy_Type  // �� ���� ��Ÿ���ִ� ����ü
{
	eEnemy_Type_None,
	eEnemy_Monster1,
	eEnemy_Monster2,
	eEnemy_Monster1_Dead,
	eEnemy_Monster2_Dead

}eEnemy_Type;

typedef struct Enemy
{
	int index;
	double Enemy_Hp;      // ���� HP 
	double Enemy_Speed;   // ���� ���ǵ� 
	double Enemy_Xposition;  // �� X��ǥ
	double Enemy_Yposition;  // �� Y��ǥ
	eEnemy_Head Enemy_Headposition; // �� �ٶ󺸴� ����
	eEnemy_Type Enemy_Type;         // �� ����

	double Enemy_slowTime;
	double Enemy_disappearTime;
	void (*Die)(int);
} Enemy;

// �ܺο��� ����
extern Enemy Enemy_EnemyArr[POOLSIZE];

// �ʱ�ȭ �Լ�
void Enemy_InitEnemy();

// �迭 �ӿ� �ִ� Enemy���� ������ ��������
void Enemy_Stats(int Index, int WaveLevel, eEnemy_Type type);

// ���� ������Ŵ (�迭 ����Ű�� �ε���, ���̺� �ܰ�, ���� Ÿ��)
void Enemy_UpdateSpawn(int Index, int WaveLevel, eEnemy_Type Type);

// �� ���� ���� �̵��ϵ��� + ��� ��ġ �ٲ��
void Enemy_UpdateMove(int Index);

// ���� ��������Ҷ� ���� Ÿ�� none�� �ٲ�
void Enemy_Disappear(int);

// ���� ������ ���� �����
void Enemy_DisappearWhenGameOver();

Enemy* Enemy_GetEnemyInfo();