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


//마우스 클릭
void UI_MouseClickUpdate();

//마우스 위치정보
void UI_MousePointerXY(int x, int y);

//마우스 X 좌표
int UI_ReturnMousePointerX();

//마우스 Y 좌표
int UI_ReturnMousePointerY();

//마우스 클릭상태 받아오기
int UI_ReturnUIButtonClickState();

//사운드 버튼상태
int UI_ReturnUISoundButtonClickState();

// 씬 관리
void UI_SceneManager();

//UI와 GDI 연동
void UI_UIDrawing();

//게임오버 호출 함수
int UI_ReturnGameOver();

