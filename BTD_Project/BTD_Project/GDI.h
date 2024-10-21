#pragma once
#include <Windows.h>
#include "BungEoPpang.h"
#include "GameSystem.h"
#include "UpgradeCommand.h"
#include "Bullet.h"
#include "GameSystem.h"



//�ӽ� ��Ʈ�� �׸���
void GDI_DrawBitmap();

//��� ��Ʈ�� �ε�
void GDI_LoadBitmap();

//�ڵ� ��������
void GDI_Initialize(HWND hWnd);

HDC GDI_GetScreenDC();
HDC GDI_GetBackBuffer();

//������۸� �����۾�
void GDI_PrintDoubleBuffering();

// ������ �����Ѵ�.
void GDI_Finalize();

//���� ���۸��� ���� DC�� ��������
void GDI_CreateDC();

//Ÿ��Ʋ UI �׸���
void GDI_TitleUIDraw();

//��ŷ �˾�â ��Ʈ �׸���
void GDI_RankingPontDraw();

//Ÿ��Ʋ���� ��ŷ �˾�â �׸���
void GDI_RankingWindowDraw();

//Ÿ��Ʋ���� ���ӹ�� �˾�â �׸��� 4��
void GDI_GameRuleWindowDraw1();
void GDI_GameRuleWindowDraw2();
void GDI_GameRuleWindowDraw3();
void GDI_GameRuleWindowDraw4();

//Ÿ��Ʋ���� ������ �˾�â �׸���
void GDI_CreditWindowDraw();

//������� ��Ʈ�� �׸���
void GDI_DrawSoundOffBitmap();


//�ΰ��� UI �׸���
void GDI_IngameUIDraw();

//Ÿ�� ��ġ ���� ��� ����Ʈ
void GDI_TowerBuildSpaceBitmap();

//�ؾŸ�� 3�� �׸���
void GDI_BungTowerDragBitmap1(int pointerX, int pointerY);
void GDI_BungTowerDragBitmap2(int pointerX, int pointerY);
void GDI_BungTowerDragBitmap3(int pointerX, int pointerY);

//��ġ�� �ؾ �׸���
void GDI_BuiltBungTowerBitmap();

//��ġ�� �ؾ Ŭ���� �巡�� ����Ʈ
void GDI_DragTowerBitmap(int pointerX, int pointerY);

//�ؾ źȯ �׸���
void GDI_BungTowerBulletBitmap();

//���� �׸���
void GDI_MonsterBitmap(int Enemy_X, int Enemy_Y, eEnemy_Head Enemy_Head, eEnemy_Type Enemy_Type);


// ���׷��̵� Ŀ�ǵ� �� ���� 
void GDI_UpgradeCommandUp();


// ���׷��̵� Ŀ�ǵ� �Ʒ� ����
void GDI_UpgradeCommandDown();


// ���׷��̵� Ŀ�ǵ� ���� ����
void GDI_UpgradeCommandLeft();


// ���׷��̵� Ŀ�ǵ� ������ ����
void GDI_UpgradeCommandRight();


//�ΰ��� ��Ʈ ���
void GDI_NumberPontBitmap();


//���ӿ��� ȭ�� ���
void GDI_GameOverUIDraw();
void GDI_GameOverBackGroundDraw();


//�ƾ� �׸��� 7��
void GDI_DrawSceneBitmap1();
void GDI_DrawSceneBitmap2();
void GDI_DrawSceneBitmap3();
void GDI_DrawSceneBitmap4();
void GDI_DrawSceneBitmap5();
void GDI_DrawSceneBitmap6();
void GDI_DrawSceneBitmap7();