#pragma once
#include "BungEoPpang.h"
#include "GameSystem.h"
#include "GDI.h"


#define UI_GAMESTARTSCENE1		0
#define UI_GAMESTARTSCENE2		1
#define UI_GAMESTARTSCENE3		2
#define UI_GAMESTARTSCENE4		3
#define UI_GAMESTARTSCENE5		4
#define UI_GAMESTARTSCENE6		5
#define UI_GAMESTARTSCENE7		6

#define UI_WINDOWONSTATENUMBER	10
#define UI_CREDITMEMBERWINDOW	11
#define UI_RANKINGWINDOW		12
#define UI_GAMERULEWINDOW1		13
#define UI_GAMERULEWINDOW2		14
#define UI_GAMERULEWINDOW3		15
#define UI_GAMERULEWINDOW4		16

#define UI_INGAMEWHAT			20
#define UI_BOONGTOWER1			21
#define UI_BOONGTOWER2			22
#define UI_BOONGTOWER3			23
#define UI_BUILTBOONGTOWER		24

#define UI_GAMEOVER1			30
#define UI_GAMEOVER2			31


//���콺 Ŭ��
void UI_MouseClickUpdate();

//���콺 ��ġ����
void UI_MousePointerXY(int x, int y);

//���콺 X ��ǥ
int UI_ReturnMousePointerX();

//���콺 Y ��ǥ
int UI_ReturnMousePointerY();

//���콺 Ŭ������ �޾ƿ���
int UI_ReturnUIButtonClickState();

//���� ��ư����
int UI_ReturnUISoundButtonClickState();

// �� ����
void UI_SceneManager();

//UI�� GDI ����
void UI_UIDrawing();

//���ӿ��� ȣ�� �Լ�
int UI_ReturnGameOver();

