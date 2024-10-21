#include "GDI.h"
#include <windows.h>
#pragma comment(lib,"msimg32.lib")
#define _USE_MATH_DEFINES
#include <math.h>
#include "Path.h"



extern BulletList Bullet_bulletList;
//extern GameSystem GameSystem_gameSystem;

//기본 전역변수 
HDC hScreenDC = NULL;		// 화면 출력용 DC
HDC MemDC = 0;
HDC backMemDC = 0;			// 더블 버퍼링용 백버퍼
HDC betaDC = 0;
RECT window_rt;
HBITMAP backBitmap = NULL;

HBITMAP oldBitmap = 0;


//비트맵 전역변수
HBITMAP GDI_a = 0;

HBITMAP GDI_rankingWavePont = 0;
HBITMAP GDI_rankingNumberPont = 0;


HBITMAP GDI_titleBackGroundBitmap = 0;
HBITMAP GDI_rankingWindow = 0;
HBITMAP GDI_creditWindow = 0;
HBITMAP GDI_gameRuleWindow1 = 0;
HBITMAP GDI_gameRuleWindow2 = 0;
HBITMAP GDI_gameRuleWindow3 = 0;
HBITMAP GDI_gameRuleWindow4 = 0;
HBITMAP GDI_soudOffButtonBitmap = 0;

HBITMAP GDI_sceneBitmap1 = 0;
HBITMAP GDI_sceneBitmap2 = 0;
HBITMAP GDI_sceneBitmap3 = 0;
HBITMAP GDI_sceneBitmap4 = 0;
HBITMAP GDI_sceneBitmap5 = 0;
HBITMAP GDI_sceneBitmap6 = 0;
HBITMAP GDI_sceneBitmap7 = 0;


HBITMAP GDI_exitButtonBitmap = 0;
HBITMAP GDI_ingameBackGroundBitmap = 0;
HBITMAP GDI_comboEnglish = 0;
HBITMAP GDI_attackUpPercent = 0;

HBITMAP GDI_bungTowerBuilding1 = 0;
HBITMAP GDI_bungTowerBuilding2 = 0;
HBITMAP GDI_bungTowerBuilding3 = 0;

HBITMAP GDI_bungTowerPointer1 = 0;
HBITMAP GDI_bungTowerPointer2 = 0;
HBITMAP GDI_bungTowerPointer3 = 0;
HBITMAP GDI_bungTowerPointer4 = 0;
HBITMAP GDI_bungTowerPointer5 = 0;
HBITMAP GDI_bungTowerPointer6 = 0;
HBITMAP GDI_bungTowerPointer7 = 0;
HBITMAP GDI_bungTowerPointer8 = 0;
HBITMAP GDI_bungTowerPointer9 = 0;
HBITMAP GDI_bungTowerPointer10 = 0;
HBITMAP GDI_bungTowerPointer11 = 0;

HBITMAP GDI_b_BungTowerPointer1 = 0;
HBITMAP GDI_b_BungTowerPointer2 = 0;
HBITMAP GDI_b_BungTowerPointer3 = 0;
HBITMAP GDI_b_BungTowerPointer4 = 0;
HBITMAP GDI_b_BungTowerPointer5 = 0;
HBITMAP GDI_b_BungTowerPointer6 = 0;
HBITMAP GDI_b_BungTowerPointer7 = 0;
HBITMAP GDI_b_BungTowerPointer8 = 0;
HBITMAP GDI_b_BungTowerPointer9 = 0;
HBITMAP GDI_b_BungTowerPointer10 = 0;
HBITMAP GDI_b_BungTowerPointer11 = 0;


HBITMAP GDI_buildSpaceBitmap = 0;

HBITMAP GDI_Monster1 = 0;
HBITMAP GDI_Monster2 = 0;
HBITMAP GDI_Monster1_Dead = 0;
HBITMAP GDI_Monster2_Dead = 0;


HBITMAP GDI_upgradeCommandUP = 0;
HBITMAP GDI_upgradeCommandDown = 0;
HBITMAP GDI_upgradeCommandLeft = 0;
HBITMAP GDI_upgradeCommandRight = 0;

HBITMAP GDI_bungTowerBullet1 = 0;
HBITMAP GDI_bungTowerBullet2 = 0;
HBITMAP GDI_bungTowerBullet3 = 0;

HBITMAP GDI_bungTowerRange150 = 0;
HBITMAP GDI_bungTowerRange200 = 0;
HBITMAP GDI_bungTowerRange250 = 0;
HBITMAP GDI_bungTowerRange300 = 0;


HBITMAP GDI_waveNumberPont = 0;
HBITMAP GDI_moneyNumberPont = 0;
HBITMAP GDI_comboNumberPont = 0;
HBITMAP GDI_damageIncreaseNumberPont = 0;

HBITMAP GDI_gameOverBackGroundBitmap = 0;
HBITMAP GDI_gameOverUIBitmap = 0;


RECT rt = { 0,0,1600,900 };

extern int UI_builtTowerPointX1;
extern int UI_builtTowerPointY1;


void GDI_Initialize(HWND hWnd)
{
	hScreenDC = GetDC(hWnd);
}

HDC GDI_GetScreenDC()
{
	return hScreenDC;
}

HDC GDI_GetBackBuffer()
{
	return backMemDC;
}

void GDI_CreateDC()
{
	//메모리 DC
	MemDC = CreateCompatibleDC(hScreenDC);
	backMemDC = CreateCompatibleDC(hScreenDC);
	betaDC = CreateCompatibleDC(hScreenDC);
	backBitmap = CreateCompatibleBitmap(hScreenDC, rt.right, rt.bottom);
	SelectObject(backMemDC, backBitmap);

	FillRect(backMemDC, &rt, (HBRUSH)GetStockObject(GRAY_BRUSH));
}

void GDI_LoadBitmap()
{
	const char* UIPATH = "..\\..\\..\\4_Resources\\";

	GDI_a = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\2.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	GDI_rankingWavePont = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\Text\\Alphabet.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_rankingNumberPont = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\Text\\Combo_Number.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	GDI_titleBackGroundBitmap = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\BackGround\\Start.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_rankingWindow = (HBITMAP)LoadImage(NULL, UIPATH(CutScene\\Ranking.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_creditWindow = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\BackGround\\Credit.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_gameRuleWindow1 = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\BackGround\\Game_explain_1.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_gameRuleWindow2 = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\BackGround\\Game_explain_2.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_gameRuleWindow3 = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\BackGround\\Game_explain_3.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_gameRuleWindow4 = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\BackGround\\Game_explain_4.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	GDI_soudOffButtonBitmap = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\Icon\\Volume_X.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	GDI_sceneBitmap1 = (HBITMAP)LoadImage(NULL, UIPATH(CutScene\\Starting_Cut1_1.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_sceneBitmap2 = (HBITMAP)LoadImage(NULL, UIPATH(CutScene\\Starting_Cut1_2.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_sceneBitmap3 = (HBITMAP)LoadImage(NULL, UIPATH(CutScene\\Starting_Cut1_3.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_sceneBitmap4 = (HBITMAP)LoadImage(NULL, UIPATH(CutScene\\Starting_Cut2_1.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_sceneBitmap5 = (HBITMAP)LoadImage(NULL, UIPATH(CutScene\\Starting_Cut2_2.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_sceneBitmap6 = (HBITMAP)LoadImage(NULL, UIPATH(CutScene\\Starting_Cut2_3.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_sceneBitmap7 = (HBITMAP)LoadImage(NULL, UIPATH(CutScene\\Starting_Cut3.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);


	GDI_exitButtonBitmap = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\Icon\\Out.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_ingameBackGroundBitmap = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\BackGround\\BTD_UI_combine.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_comboEnglish = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\Text\\COMBO.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_attackUpPercent = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\Text\\Increase_Attack.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	GDI_bungTowerBuilding1 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\1_king_1.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_bungTowerBuilding2 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\2_king_1.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_bungTowerBuilding3 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\3_bung_1.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	GDI_bungTowerPointer1 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\1_king_1.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_bungTowerPointer2 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\2_king_1.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_bungTowerPointer3 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\3_bung_1.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_bungTowerPointer4 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\1_king_2.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_bungTowerPointer5 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\2_king_2.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_bungTowerPointer6 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\3_bung_2.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_bungTowerPointer7 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\1_king_3.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_bungTowerPointer8 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\2_king_3.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_bungTowerPointer9 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\3_bung_3.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_bungTowerPointer10 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\Burn_1_king.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_bungTowerPointer11 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\Burn_2_king.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	GDI_b_BungTowerPointer1 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\b_1_king_1.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_b_BungTowerPointer2 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\b_2_king_1.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_b_BungTowerPointer3 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\b_3_bung_1.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_b_BungTowerPointer4 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\b_1_king_2.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_b_BungTowerPointer5 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\b_2_king_2.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_b_BungTowerPointer6 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\b_3_bung_2.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_b_BungTowerPointer7 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\b_1_king_3.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_b_BungTowerPointer8 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\b_2_king_3.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_b_BungTowerPointer9 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\b_3_bung_3.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_b_BungTowerPointer10 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\b_Burn_1_king.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_b_BungTowerPointer11 = (HBITMAP)LoadImage(NULL, UIPATH(Bung\\b_Burn_2_king.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);


	GDI_buildSpaceBitmap = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\BackGround\\InGame_Build_Able.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	GDI_Monster1 = (HBITMAP)LoadImage(NULL, UIPATH(Character\\Monster_Move_2.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_Monster2 = (HBITMAP)LoadImage(NULL, UIPATH(Character\\Monster_Move_1.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_Monster1_Dead = (HBITMAP)LoadImage(NULL, UIPATH(Character\\Montser1_Death.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_Monster2_Dead = (HBITMAP)LoadImage(NULL, UIPATH(Character\\Montser2_Death.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);


	GDI_upgradeCommandUP = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\Icon\\Point_W_Light.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_upgradeCommandDown = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\Icon\\Point_S_Light.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_upgradeCommandLeft = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\Icon\\Point_A_Light.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_upgradeCommandRight = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\Icon\\Point_D_Light.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);


	GDI_bungTowerBullet1 = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\Icon\\King_1_Shot.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_bungTowerBullet2 = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\Icon\\King_2_Shot.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_bungTowerBullet3 = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\Icon\\King_3_Shot.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	
	GDI_bungTowerRange150 = (HBITMAP)LoadImage(NULL, UIPATH(Range\\Range_150.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_bungTowerRange200 = (HBITMAP)LoadImage(NULL, UIPATH(Range\\Range_200.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_bungTowerRange250 = (HBITMAP)LoadImage(NULL, UIPATH(Range\\Range_250.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_bungTowerRange300 = (HBITMAP)LoadImage(NULL, UIPATH(Range\\Range_300.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);


	GDI_waveNumberPont = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\Text\\Wave.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_moneyNumberPont = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\Text\\Money.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_comboNumberPont = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\Text\\Combo_Number.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_damageIncreaseNumberPont = (HBITMAP)LoadImage(NULL, UIPATH(UI_Bitmap\\Text\\Attack.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);


	GDI_gameOverBackGroundBitmap = (HBITMAP)LoadImage(NULL, UIPATH(CutScene\\Ending_Scene.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GDI_gameOverUIBitmap = (HBITMAP)LoadImage(NULL, UIPATH(CutScene\\GameOver.bmp), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
}

void GDI_RankingPontDraw()
{
	int GDI_playerTenNumber;
	int GDI_playerOneNumber;
	int GDI_waveTenNumber;
	int GDI_waveOneNumber;


	for (int i = 0; i < 10; i++)
	{
		//랭킹 플레이어 넘버 출력
		if (GameSystem_gameSystem.rankArray[i][0] < 10)
		{
			GDI_playerOneNumber = GameSystem_gameSystem.rankArray[i][0];

			SelectObject(MemDC, GDI_rankingNumberPont);
			TransparentBlt(backMemDC, 1210, i * 88 + 30, 42, 50, MemDC, GDI_playerOneNumber * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
		}
		else if (GameSystem_gameSystem.rankArray[i][0] >= 10)
		{
			GDI_playerTenNumber = GameSystem_gameSystem.rankArray[i][0] / 10;
			GDI_playerOneNumber = GameSystem_gameSystem.rankArray[i][0] % 10;

			SelectObject(MemDC, GDI_rankingNumberPont);
			TransparentBlt(backMemDC, 1170, i * 88 + 30, 42, 50, MemDC, GDI_playerTenNumber * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
			SelectObject(MemDC, GDI_rankingNumberPont);
			TransparentBlt(backMemDC, 1210, i * 88 + 30, 42, 50, MemDC, GDI_playerOneNumber * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
		}

		//랭킹 웨이브 넘버 출력
		if (GameSystem_gameSystem.rankArray[i][1] < 10)
		{
			GDI_waveOneNumber = GameSystem_gameSystem.rankArray[i][1];

			SelectObject(MemDC, GDI_rankingNumberPont);
			TransparentBlt(backMemDC, 1390, i * 88 + 30, 42, 50, MemDC, GDI_waveOneNumber * 52 + 10, 10, 42, 50, RGB(255, 0, 255));

			SelectObject(MemDC, GDI_rankingWavePont);
			TransparentBlt(backMemDC, 1435, i * 88 + 30, 42, 50, MemDC, 1154, 10, 42, 50, RGB(255, 0, 255));
			TransparentBlt(backMemDC, 1477, i * 88 + 30, 42, 50, MemDC, 10, 10, 42, 50, RGB(255, 0, 255));
			TransparentBlt(backMemDC, 1519, i * 88 + 30, 42, 50, MemDC, 1102, 10, 42, 50, RGB(255, 0, 255));
			TransparentBlt(backMemDC, 1556, i * 88 + 30, 42, 50, MemDC, 218, 10, 42, 50, RGB(255, 0, 255));
		}
		else if (GameSystem_gameSystem.rankArray[i][1] >= 10)
		{
			GDI_waveTenNumber = GameSystem_gameSystem.rankArray[i][1] / 10;
			GDI_waveOneNumber = GameSystem_gameSystem.rankArray[i][1] % 10;

			SelectObject(MemDC, GDI_rankingNumberPont);
			TransparentBlt(backMemDC, 1350, i * 90 + 25, 42, 50, MemDC, GDI_waveTenNumber * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
			SelectObject(MemDC, GDI_rankingNumberPont);
			TransparentBlt(backMemDC, 1390, i * 90 + 25, 42, 50, MemDC, GDI_waveOneNumber * 52 + 10, 10, 42, 50, RGB(255, 0, 255));

			SelectObject(MemDC, GDI_rankingWavePont);
			TransparentBlt(backMemDC, 1435, i * 88 + 30, 42, 50, MemDC, 1154, 10, 42, 50, RGB(255, 0, 255));
			TransparentBlt(backMemDC, 1477, i * 88 + 30, 42, 50, MemDC, 10, 10, 42, 50, RGB(255, 0, 255));
			TransparentBlt(backMemDC, 1519, i * 88 + 30, 42, 50, MemDC, 1102, 10, 42, 50, RGB(255, 0, 255));
			TransparentBlt(backMemDC, 1556, i * 88 + 30, 42, 50, MemDC, 218, 10, 42, 50, RGB(255, 0, 255));
		}

		//player 폰트 출력
		SelectObject(MemDC, GDI_rankingWavePont);
		TransparentBlt(backMemDC, 930, i * 88 + 30, 42, 50, MemDC, 790, 10, 42, 50, RGB(255, 0, 255));		//p
		TransparentBlt(backMemDC, 967, i * 88 + 30, 42, 50, MemDC, 582, 10, 42, 50, RGB(255, 0, 255));		//l
		TransparentBlt(backMemDC, 1004, i * 88 + 30, 42, 50, MemDC, 10, 10, 42, 50, RGB(255, 0, 255));		//a
		TransparentBlt(backMemDC, 1041, i * 88 + 30, 42, 50, MemDC, 1258, 10, 42, 50, RGB(255, 0, 255));	//y
		TransparentBlt(backMemDC, 1078, i * 88 + 30, 42, 50, MemDC, 218, 10, 42, 50, RGB(255, 0, 255));		//e
		TransparentBlt(backMemDC, 1115, i * 88 + 30, 42, 50, MemDC, 894, 10, 42, 50, RGB(255, 0, 255));		//r
	}
}

void GDI_TitleUIDraw()
{
	SelectObject(MemDC, GDI_titleBackGroundBitmap);
	BitBlt(backMemDC, 0, 0, 1600, 900, MemDC, 0, 0, SRCCOPY);
}

void GDI_RankingWindowDraw()
{
	SelectObject(MemDC, GDI_rankingWindow);
	BitBlt(backMemDC, 0, 0, 1600, 900, MemDC, 0, 0, SRCCOPY);
}

void GDI_CreditWindowDraw()
{
	SelectObject(MemDC, GDI_creditWindow);
	TransparentBlt(backMemDC, 0, 0, 1600, 900, MemDC, 0, 0, 1600, 900, RGB(255, 0, 255));
}

void GDI_GameRuleWindowDraw1()
{
	SelectObject(MemDC, GDI_gameRuleWindow1);
	TransparentBlt(backMemDC, 0, 0, 1600, 900, MemDC, 0, 0, 1600, 900, RGB(255, 0, 255));
}

void GDI_GameRuleWindowDraw2()
{
	SelectObject(MemDC, GDI_gameRuleWindow2);
	TransparentBlt(backMemDC, 0, 0, 1600, 900, MemDC, 0, 0, 1600, 900, RGB(255, 0, 255));
}

void GDI_GameRuleWindowDraw3()
{
	SelectObject(MemDC, GDI_gameRuleWindow3);
	TransparentBlt(backMemDC, 0, 0, 1600, 900, MemDC, 0, 0, 1600, 900, RGB(255, 0, 255));
}

void GDI_GameRuleWindowDraw4()
{
	SelectObject(MemDC, GDI_gameRuleWindow4);
	TransparentBlt(backMemDC, 0, 0, 1600, 900, MemDC, 0, 0, 1600, 900, RGB(255, 0, 255));
}

//게임 시작시 그리기
void GDI_IngameUIDraw()
{
	//백 DC에 그리기
	SelectObject(MemDC, GDI_ingameBackGroundBitmap);
	BitBlt(backMemDC, 0, 0, 1600, 900, MemDC, 0, 0, SRCCOPY);

	SelectObject(MemDC, GDI_comboEnglish);
	TransparentBlt(backMemDC, 478, 750, 175, 52, MemDC, 0, 0, 175, 52, RGB(255, 0, 255));

	SelectObject(MemDC, GDI_attackUpPercent);
	TransparentBlt(backMemDC, 360, 717, 286, 32, MemDC, 0, 0, 286, 32, RGB(255, 0, 255));
}


void GDI_GameOverBackGroundDraw()
{
	SelectObject(MemDC, GDI_gameOverBackGroundBitmap);
	BitBlt(backMemDC, 0, 0, 1600, 900, MemDC, 0, 0, SRCCOPY);
}

void GDI_GameOverUIDraw()
{
	SelectObject(MemDC, GDI_gameOverUIBitmap);
	TransparentBlt(backMemDC, 0, 0, 1600, 900, MemDC, 0, 0, 1600, 900, RGB(255, 0, 255));
}




void GDI_DrawBitmap()
{
	SelectObject(MemDC, GDI_a);
	static BLENDFUNCTION bf;
	bf.BlendOp = bf.BlendFlags = bf.AlphaFormat = 0;
	bf.SourceConstantAlpha = 200;
	AlphaBlend(backMemDC, 400, 100, 800, 600, MemDC, 0, 0, 800, 600, bf);
}

void GDI_DrawSoundOffBitmap()
{
	SelectObject(MemDC, GDI_soudOffButtonBitmap);
	TransparentBlt(backMemDC, 1271, 739, 67, 67, MemDC, 0, 0, 67, 67, RGB(255, 0, 255));
}

//컷씬 그리기
void GDI_DrawSceneBitmap1()
{
	SelectObject(MemDC, GDI_sceneBitmap1);
	BitBlt(backMemDC, 0, 0, 1600, 900, MemDC, 0, 0, SRCCOPY);
}

void GDI_DrawSceneBitmap2()
{
	SelectObject(MemDC, GDI_sceneBitmap2);
	BitBlt(backMemDC, 0, 0, 1600, 900, MemDC, 0, 0, SRCCOPY);
}

void GDI_DrawSceneBitmap3()
{
	SelectObject(MemDC, GDI_sceneBitmap3);
	BitBlt(backMemDC, 0, 0, 1600, 900, MemDC, 0, 0, SRCCOPY);
}

void GDI_DrawSceneBitmap4()
{
	SelectObject(MemDC, GDI_sceneBitmap4);
	BitBlt(backMemDC, 0, 0, 1600, 900, MemDC, 0, 0, SRCCOPY);
}

void GDI_DrawSceneBitmap5()
{
	SelectObject(MemDC, GDI_sceneBitmap5);
	BitBlt(backMemDC, 0, 0, 1600, 900, MemDC, 0, 0, SRCCOPY);
}

void GDI_DrawSceneBitmap6()
{
	SelectObject(MemDC, GDI_sceneBitmap6);
	BitBlt(backMemDC, 0, 0, 1600, 900, MemDC, 0, 0, SRCCOPY);
}

void GDI_DrawSceneBitmap7()
{
	SelectObject(MemDC, GDI_sceneBitmap7);
	BitBlt(backMemDC, 0, 0, 1600, 900, MemDC, 0, 0, SRCCOPY);
}


//붕어빵 3종
void GDI_BungTowerDragBitmap1(int pointerX, int pointerY)
{
	SelectObject(MemDC, GDI_bungTowerBuilding1);
	TransparentBlt(backMemDC, pointerX - 50, pointerY - 50, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
}

void GDI_BungTowerDragBitmap2(int pointerX, int pointerY)
{
	SelectObject(MemDC, GDI_bungTowerBuilding2);
	TransparentBlt(backMemDC, pointerX - 50, pointerY - 50, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
}

void GDI_BungTowerDragBitmap3(int pointerX, int pointerY)
{
	SelectObject(MemDC, GDI_bungTowerBuilding3);
	TransparentBlt(backMemDC, pointerX - 50, pointerY - 50, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
}


//설치된 모든 붕어빵 그리기
void GDI_BuiltBungTowerBitmap()
{
	// 	POINT m_tPoint[3];
	// 	double m_fDis = 50 * sqrt(2);
	// 	double PI = M_PI;

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 12; x++)
		{
			//                          B의Y   A의Y   B의X   A의X 
		// 	double m_fAngle = atan2f((float)BungEoPpang_bungEoPpangArray[y][x].y - Enemy_EnemyArr[0].Enemy_Yposition, (float)BungEoPpang_bungEoPpangArray[y][x].x - Enemy_EnemyArr[0].Enemy_Xposition) * 180 / PI;
		// 
		// 	m_tPoint[0].x = (LONG)(50 + cosf((135 + m_fAngle) * PI / 180.f) * m_fDis);
		// 	m_tPoint[0].y = (LONG)(50 - sinf((135 + m_fAngle) * PI / 180.f) * m_fDis);
		// 
		// 	m_tPoint[1].x = (LONG)(50 + cosf((45 + m_fAngle) * PI / 180.f) * m_fDis);
		// 	m_tPoint[1].y = (LONG)(50 - sinf((45 + m_fAngle) * PI / 180.f) * m_fDis);
		// 
		// 	m_tPoint[2].x = (LONG)(50 + cosf((225 + m_fAngle) * PI / 180.f) * m_fDis);
		// 	m_tPoint[2].y = (LONG)(50 - sinf((225 + m_fAngle) * PI / 180.f) * m_fDis);
			switch (BungEoPpang_bungEoPpangArray[y][x].kind)
			{
			case BungEoPpang_e1_1:
			{
				if (x == 2 || x == 5 || x == 8 || x == 11)
				{
					SelectObject(MemDC, GDI_bungTowerPointer1);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}
				else if (x == 0 || x == 3 || x == 6 || x == 9)
				{
					SelectObject(MemDC, GDI_b_BungTowerPointer1);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}
				//회전 만들다 실패한 주석
				//PlgBlt(MemDC, m_tPoint, betaDC, 0, 0, 100, 100, NULL, NULL, NULL);
			}
			break;

			case BungEoPpang_e1_2:
			{
				if (x == 2 || x == 5 || x == 8 || x == 11)
				{
					SelectObject(MemDC, GDI_bungTowerPointer2);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}
				else if (x == 0 || x == 3 || x == 6 || x == 9)
				{
					SelectObject(MemDC, GDI_b_BungTowerPointer2);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}

			}
			break;

			case BungEoPpang_e1_3:
			{
				if (x == 2 || x == 5 || x == 8 || x == 11)
				{
					SelectObject(MemDC, GDI_bungTowerPointer3);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}
				else if (x == 0 || x == 3 || x == 6 || x == 9)
				{
					SelectObject(MemDC, GDI_b_BungTowerPointer3);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}

			}
			break;

			case 3:
			{
				if (x == 2 || x == 5 || x == 8 || x == 11)
				{
					SelectObject(MemDC, GDI_bungTowerPointer4);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}
				else if (x == 0 || x == 3 || x == 6 || x == 9)
				{
					SelectObject(MemDC, GDI_b_BungTowerPointer4);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}

			}
			break;

			case 4:
			{
				if (x == 2 || x == 5 || x == 8 || x == 11)
				{
					SelectObject(MemDC, GDI_bungTowerPointer5);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}
				else if (x == 0 || x == 3 || x == 6 || x == 9)
				{
					SelectObject(MemDC, GDI_b_BungTowerPointer5);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}

			}
			break;

			case 5:
			{
				if (x == 2 || x == 5 || x == 8 || x == 11)
				{
					SelectObject(MemDC, GDI_bungTowerPointer6);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}
				else if (x == 0 || x == 3 || x == 6 || x == 9)
				{
					SelectObject(MemDC, GDI_b_BungTowerPointer6);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}

			}
			break;

			case 6:
			{
				if (x == 2 || x == 5 || x == 8 || x == 11)
				{
					SelectObject(MemDC, GDI_bungTowerPointer7);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}
				else if (x == 0 || x == 3 || x == 6 || x == 9)
				{
					SelectObject(MemDC, GDI_b_BungTowerPointer7);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}

			}
			break;

			case 7:
			{
				if (x == 2 || x == 5 || x == 8 || x == 11)
				{
					SelectObject(MemDC, GDI_bungTowerPointer8);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}
				else if (x == 0 || x == 3 || x == 6 || x == 9)
				{
					SelectObject(MemDC, GDI_b_BungTowerPointer8);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}

			}
			break;

			case 8:
			{
				if (x == 2 || x == 5 || x == 8 || x == 11)
				{
					SelectObject(MemDC, GDI_bungTowerPointer9);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}
				else if (x == 0 || x == 3 || x == 6 || x == 9)
				{
					SelectObject(MemDC, GDI_b_BungTowerPointer9);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}

			}
			break;

			case 9:
			{
				if (x == 2 || x == 5 || x == 8 || x == 11)
				{
					SelectObject(MemDC, GDI_bungTowerPointer10);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}
				else if (x == 0 || x == 3 || x == 6 || x == 9)
				{
					SelectObject(MemDC, GDI_b_BungTowerPointer10);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}

			}
			break;

			case 10:
			{
				if (x == 2 || x == 5 || x == 8 || x == 11)
				{
					SelectObject(MemDC, GDI_bungTowerPointer11);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}
				else if (x == 0 || x == 3 || x == 6 || x == 9)
				{
					SelectObject(MemDC, GDI_b_BungTowerPointer11);
					TransparentBlt(backMemDC, 200 + x * 100, 200 + y * 100, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
				}

			}
			break;
			}
		}
	}
}

//설치된 붕어빵 클릭시 드래그 프린트
void GDI_DragTowerBitmap(int pointerX, int pointerY)
{
	//이미지 로딩	
	switch (BungEoPpang_bungEoPpangArray[UI_builtTowerPointY1][UI_builtTowerPointX1].kind)
	{
	case 0:
	{
		SelectObject(MemDC, GDI_bungTowerRange200);
		TransparentBlt(backMemDC, UI_builtTowerPointX1 * 100 - 50, UI_builtTowerPointY1*100 - 55, 600, 600, MemDC, 0, 0, 600, 600, RGB(255, 0, 255));

		SelectObject(MemDC, GDI_bungTowerPointer1);
		TransparentBlt(backMemDC, pointerX - 50, pointerY - 50, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
	}
	break;

	case 1:
	{
		SelectObject(MemDC, GDI_bungTowerRange150);
		TransparentBlt(backMemDC, UI_builtTowerPointX1 * 100 - 50, UI_builtTowerPointY1 * 100 - 55, 600, 600, MemDC, 0, 0, 600, 600, RGB(255, 0, 255));

		SelectObject(MemDC, GDI_bungTowerPointer2);
		TransparentBlt(backMemDC, pointerX - 50, pointerY - 50, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
	}
	break;

	case 2:
	{
		SelectObject(MemDC, GDI_bungTowerRange150);
		TransparentBlt(backMemDC, UI_builtTowerPointX1 * 100 - 50, UI_builtTowerPointY1 * 100 - 55, 600, 600, MemDC, 0, 0, 600, 600, RGB(255, 0, 255));

		SelectObject(MemDC, GDI_bungTowerPointer3);
		TransparentBlt(backMemDC, pointerX - 50, pointerY - 50, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
	}
	break;

	case 3:
	{
		SelectObject(MemDC, GDI_bungTowerRange250);
		TransparentBlt(backMemDC, UI_builtTowerPointX1 * 100 - 50, UI_builtTowerPointY1 * 100 - 55, 600, 600, MemDC, 0, 0, 600, 600, RGB(255, 0, 255));

		SelectObject(MemDC, GDI_bungTowerPointer4);
		TransparentBlt(backMemDC, pointerX - 50, pointerY - 50, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
	}
	break;

	case 4:
	{
		SelectObject(MemDC, GDI_bungTowerRange200);
		TransparentBlt(backMemDC, UI_builtTowerPointX1 * 100 - 50, UI_builtTowerPointY1 * 100 - 55, 600, 600, MemDC, 0, 0, 600, 600, RGB(255, 0, 255));

		SelectObject(MemDC, GDI_bungTowerPointer5);
		TransparentBlt(backMemDC, pointerX - 50, pointerY - 50, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
	}
	break;

	case 5:
	{
		SelectObject(MemDC, GDI_bungTowerRange200);
		TransparentBlt(backMemDC, UI_builtTowerPointX1 * 100 - 50, UI_builtTowerPointY1 * 100 - 55, 600, 600, MemDC, 0, 0, 600, 600, RGB(255, 0, 255));

		SelectObject(MemDC, GDI_bungTowerPointer6);
		TransparentBlt(backMemDC, pointerX - 50, pointerY - 50, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
	}
	break;

	case 6:
	{
		SelectObject(MemDC, GDI_bungTowerRange300);
		TransparentBlt(backMemDC, UI_builtTowerPointX1 * 100 - 50, UI_builtTowerPointY1 * 100 - 55, 600, 600, MemDC, 0, 0, 600, 600, RGB(255, 0, 255));

		SelectObject(MemDC, GDI_bungTowerPointer7);
		TransparentBlt(backMemDC, pointerX - 50, pointerY - 50, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
	}
	break;

	case 7:
	{
		SelectObject(MemDC, GDI_bungTowerRange200);
		TransparentBlt(backMemDC, UI_builtTowerPointX1 * 100 - 50, UI_builtTowerPointY1 * 100 - 55, 600, 600, MemDC, 0, 0, 600, 600, RGB(255, 0, 255));

		SelectObject(MemDC, GDI_bungTowerPointer8);
		TransparentBlt(backMemDC, pointerX - 50, pointerY - 50, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
	}
	break;

	case 8:
	{
		SelectObject(MemDC, GDI_bungTowerRange300);
		TransparentBlt(backMemDC, UI_builtTowerPointX1 * 100 - 50, UI_builtTowerPointY1 * 100 - 55, 600, 600, MemDC, 0, 0, 600, 600, RGB(255, 0, 255));

		SelectObject(MemDC, GDI_bungTowerPointer9);
		TransparentBlt(backMemDC, pointerX - 50, pointerY - 50, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
	}
	break;

	case 9:
	{
		SelectObject(MemDC, GDI_bungTowerRange250);
		TransparentBlt(backMemDC, UI_builtTowerPointX1 * 100 - 50, UI_builtTowerPointY1 * 100 - 55, 600, 600, MemDC, 0, 0, 600, 600, RGB(255, 0, 255));

		SelectObject(MemDC, GDI_bungTowerPointer10);
		TransparentBlt(backMemDC, pointerX - 50, pointerY - 50, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
	}
	break;

	case 10:
	{
		SelectObject(MemDC, GDI_bungTowerRange200);
		TransparentBlt(backMemDC, UI_builtTowerPointX1 * 100 - 50, UI_builtTowerPointY1 * 100 - 55, 600, 600, MemDC, 0, 0, 600, 600, RGB(255, 0, 255));

		SelectObject(MemDC, GDI_bungTowerPointer11);
		TransparentBlt(backMemDC, pointerX - 50, pointerY - 50, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
	}
	break;

	default:
		break;
	}
}

void GDI_TowerBuildSpaceBitmap()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			if (BungEoPpang_bungEoPpangArray[i][j].kind == BungEoPpang_eNull)
			{
				SelectObject(MemDC, GDI_buildSpaceBitmap);
				static BLENDFUNCTION bf;
				bf.BlendOp = bf.BlendFlags = bf.AlphaFormat = 0;
				bf.SourceConstantAlpha = 200;
				AlphaBlend(backMemDC, 200 + 100 * j, 200 + 100 * i, 100, 100, MemDC, 0, 0, 100, 100, bf);
			}
		}
	}
}

void GDI_BungTowerBulletBitmap()
{
	for (BulletNode* node = Bullet_bulletList._beginNode->_next;
		node != Bullet_bulletList._endNode;
		node = node->_next)
	{
		if (node->_bullet.bulletType == 0 || node->_bullet.bulletType == 3 || node->_bullet.bulletType == 6)
		{
			SelectObject(MemDC, GDI_bungTowerBullet1);
			TransparentBlt(backMemDC, node->_bullet.posX - 25, node->_bullet.posY - 25, 50, 50, MemDC, 0, 0, 50, 50, RGB(255, 0, 255));
		}
		else if (node->_bullet.bulletType == 1 || node->_bullet.bulletType == 4 || node->_bullet.bulletType == 7)
		{
			SelectObject(MemDC, GDI_bungTowerBullet2);
			TransparentBlt(backMemDC, node->_bullet.posX - 25, node->_bullet.posY - 25, 50, 50, MemDC, 0, 0, 50, 50, RGB(255, 0, 255));

		}
		else if (node->_bullet.bulletType == 2 || node->_bullet.bulletType == 5 || node->_bullet.bulletType == 8 || node->_bullet.bulletType == 9 || node->_bullet.bulletType == 10)
		{
			SelectObject(MemDC, GDI_bungTowerBullet3);
			TransparentBlt(backMemDC, node->_bullet.posX - 25, node->_bullet.posY - 25, 50, 50, MemDC, 0, 0, 50, 50, RGB(255, 0, 255));

		}
	}
}


double Animation_Checktime = 0;
int Animation_Xposition = 0;

void GDI_MonsterBitmap(int Enemy_X, int Enemy_Y, eEnemy_Head Enemy_Head, eEnemy_Type Enemy_Type)
{
	// 애니메이션 출력 간격을 위한 타이머
	Animation_Checktime += DeltaTime_GetDeltaTime();

	if (Animation_Checktime <= 4)
	{
		Animation_Xposition = 0;
	}

	if (Animation_Checktime > 4 && Animation_Checktime <= 8)
	{
		Animation_Xposition = 100;
	}

	if (Animation_Checktime > 8 && Animation_Checktime <= 12)
	{
		Animation_Xposition = 200;
	}

	if (Animation_Checktime > 12)
	{
		Animation_Checktime = 0;
	}

	//이미지 로딩
	if (Enemy_Type == eEnemy_Monster1)
	{
		SelectObject(MemDC, GDI_Monster1);
		TransparentBlt(backMemDC, Enemy_X - 50, Enemy_Y - 50, 100, 100, MemDC, Animation_Xposition, 0, 100, 100, RGB(255, 8, 255));
	}
	else if (Enemy_Type == eEnemy_Monster2)
	{
		SelectObject(MemDC, GDI_Monster2);
		TransparentBlt(backMemDC, Enemy_X - 50, Enemy_Y - 50, 100, 100, MemDC, Animation_Xposition, 0, 100, 100, RGB(255, 0, 255));
	}
	else if (Enemy_Type == eEnemy_Monster1_Dead)
	{
		SelectObject(MemDC, GDI_Monster1_Dead);
		TransparentBlt(backMemDC, Enemy_X - 50, Enemy_Y - 50, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
	}
	else if (Enemy_Type == eEnemy_Monster2_Dead)
	{
		SelectObject(MemDC, GDI_Monster2_Dead);
		TransparentBlt(backMemDC, Enemy_X - 50, Enemy_Y - 50, 100, 100, MemDC, 0, 0, 100, 100, RGB(255, 0, 255));
	}
}


// 입력해야할 커맨드 표시
void GDI_UpgradeCommandUp()
{
	SelectObject(MemDC, GDI_upgradeCommandUP);
	TransparentBlt(backMemDC, 28, 670, 206, 206, MemDC, 0, 0, 206, 206, RGB(255, 0, 255));
}

void GDI_UpgradeCommandDown()
{
	SelectObject(MemDC, GDI_upgradeCommandDown);
	TransparentBlt(backMemDC, 28, 670, 206, 206, MemDC, 0, 0, 206, 206, RGB(255, 0, 255));
}

void GDI_UpgradeCommandLeft()
{
	SelectObject(MemDC, GDI_upgradeCommandLeft);
	TransparentBlt(backMemDC, 28, 670, 206, 206, MemDC, 0, 0, 206, 206, RGB(255, 0, 255));
}

void GDI_UpgradeCommandRight()
{
	SelectObject(MemDC, GDI_upgradeCommandRight);
	TransparentBlt(backMemDC, 28, 670, 206, 206, MemDC, 0, 0, 206, 206, RGB(255, 0, 255));
}

//폰트 출력
void GDI_NumberPontBitmap()
{
	int GDI_waveTenNumber;
	int GDI_waveOneNumber;
	int GDI_moneyOneNumber;
	int GDI_moneyTenNumber;
	int GDI_moneyHundredNumber;
	int GDI_moneyThousandNumber;
	int GDI_comboOneNumber;
	int GDI_comboTenNumber;
	int GDI_comboHundredNumber;
	double GDI_damageIncreaseNumber;
	int GDI_damageIncreaseOneNumber;
	int GDI_damageIncreaseTenNumber;
	int GDI_damageIncreaseHundredNumber;


	// Wave 99넘어가면 99로 출력 고정되도록 추가
	if (GameSystem_gameSystem.nowWave > 99)
	{
		GDI_waveTenNumber = 9;
		GDI_waveOneNumber = 9;
	}
	else
	{
		GDI_waveOneNumber = (GameSystem_gameSystem.nowWave % 10);
		GDI_waveTenNumber = (GameSystem_gameSystem.nowWave / 10);
	}

	// 개발자 모드때 9999로 돈 되도록 수정
	if (GameSystem_gameSystem.money > 9999)
	{
		GDI_moneyThousandNumber = 9;
		GDI_moneyHundredNumber = 9;
		GDI_moneyTenNumber = 9;
		GDI_moneyOneNumber = 9;
	}
	else
	{
		GDI_moneyThousandNumber = (GameSystem_gameSystem.money / 1000);
		GDI_moneyHundredNumber = ((GameSystem_gameSystem.money - GDI_moneyThousandNumber * 1000) / 100);
		GDI_moneyTenNumber = ((GameSystem_gameSystem.money - GDI_moneyThousandNumber * 1000 - GDI_moneyHundredNumber * 100) / 10);
		GDI_moneyOneNumber = ((GameSystem_gameSystem.money - GDI_moneyThousandNumber * 1000 - GDI_moneyHundredNumber * 100 - GDI_moneyTenNumber * 10) % 10);
	}

	GDI_comboHundredNumber = ((GameSystem_GetUpgradeCombo()) / 100);
	GDI_comboTenNumber = ((GameSystem_GetUpgradeCombo() - GDI_comboHundredNumber * 100) / 10);
	GDI_comboOneNumber = ((GameSystem_GetUpgradeCombo() - GDI_comboHundredNumber * 100 - GDI_comboTenNumber * 10) % 10);


	GDI_damageIncreaseNumber = GameSystem_GetAttackDamageIncrease() * 100;
	GDI_damageIncreaseHundredNumber = (GDI_damageIncreaseNumber / 100);
	GDI_damageIncreaseTenNumber = ((GDI_damageIncreaseNumber - GDI_damageIncreaseHundredNumber * 100) / 10);
	GDI_damageIncreaseOneNumber = ((GDI_damageIncreaseNumber - GDI_damageIncreaseHundredNumber * 100 - GDI_damageIncreaseTenNumber * 10));


	if (GameSystem_gameSystem.nowWave < 10)
	{
		SelectObject(MemDC, GDI_waveNumberPont);
		TransparentBlt(backMemDC, 879, 37, 42, 50, MemDC, (GDI_waveOneNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
	}

	if (GameSystem_gameSystem.nowWave >= 10)
	{
		SelectObject(MemDC, GDI_waveNumberPont);
		TransparentBlt(backMemDC, 899, 37, 42, 50, MemDC, (GDI_waveOneNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
		SelectObject(MemDC, GDI_waveNumberPont);
		TransparentBlt(backMemDC, 857, 37, 42, 50, MemDC, (GDI_waveTenNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
	}

	if (GameSystem_gameSystem.money < 10)
	{
		SelectObject(MemDC, GDI_moneyNumberPont);
		TransparentBlt(backMemDC, 905, 104, 42, 50, MemDC, (GDI_moneyOneNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
	}
	else if (GameSystem_gameSystem.money < 100)
	{
		SelectObject(MemDC, GDI_moneyNumberPont);
		TransparentBlt(backMemDC, 905, 104, 42, 50, MemDC, (GDI_moneyOneNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
		SelectObject(MemDC, GDI_moneyNumberPont);
		TransparentBlt(backMemDC, 867, 104, 42, 50, MemDC, (GDI_moneyTenNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
	}
	else if (GameSystem_gameSystem.money < 1000)
	{
		SelectObject(MemDC, GDI_moneyNumberPont);
		TransparentBlt(backMemDC, 905, 104, 42, 50, MemDC, (GDI_moneyOneNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
		SelectObject(MemDC, GDI_moneyNumberPont);
		TransparentBlt(backMemDC, 867, 104, 42, 50, MemDC, (GDI_moneyTenNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
		SelectObject(MemDC, GDI_moneyNumberPont);
		TransparentBlt(backMemDC, 829, 104, 42, 50, MemDC, (GDI_moneyHundredNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
	}
	else if (GameSystem_gameSystem.money < 10000)
	{
		SelectObject(MemDC, GDI_moneyNumberPont);
		TransparentBlt(backMemDC, 905, 104, 42, 50, MemDC, (GDI_moneyOneNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
		SelectObject(MemDC, GDI_moneyNumberPont);
		TransparentBlt(backMemDC, 867, 104, 42, 50, MemDC, (GDI_moneyTenNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
		SelectObject(MemDC, GDI_moneyNumberPont);
		TransparentBlt(backMemDC, 829, 104, 42, 50, MemDC, (GDI_moneyHundredNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
		SelectObject(MemDC, GDI_moneyNumberPont);
		TransparentBlt(backMemDC, 791, 104, 42, 50, MemDC, (GDI_moneyThousandNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
	}

	if (GameSystem_GetUpgradeCombo() < 10)
	{
		SelectObject(MemDC, GDI_comboNumberPont);
		TransparentBlt(backMemDC, 429, 750, 42, 50, MemDC, (GDI_comboOneNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
	}
	else if (GameSystem_GetUpgradeCombo() < 100)
	{
		SelectObject(MemDC, GDI_comboNumberPont);
		TransparentBlt(backMemDC, 429, 750, 42, 50, MemDC, (GDI_comboOneNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
		SelectObject(MemDC, GDI_comboNumberPont);
		TransparentBlt(backMemDC, 384, 750, 42, 50, MemDC, (GDI_comboTenNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
	}
	else if (GameSystem_GetUpgradeCombo() < 1000)
	{
		SelectObject(MemDC, GDI_comboNumberPont);
		TransparentBlt(backMemDC, 429, 750, 42, 50, MemDC, (GDI_comboOneNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
		SelectObject(MemDC, GDI_comboNumberPont);
		TransparentBlt(backMemDC, 384, 750, 42, 50, MemDC, (GDI_comboTenNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
		SelectObject(MemDC, GDI_comboNumberPont);
		TransparentBlt(backMemDC, 339, 750, 42, 50, MemDC, (GDI_comboHundredNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
	}

	if (GDI_damageIncreaseNumber < 10)
	{
		SelectObject(MemDC, GDI_damageIncreaseNumberPont);
		TransparentBlt(backMemDC, 574, 708, 42, 50, MemDC, (GDI_damageIncreaseOneNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
	}
	else if (GDI_damageIncreaseNumber < 100)
	{
		SelectObject(MemDC, GDI_damageIncreaseNumberPont);
		TransparentBlt(backMemDC, 574, 708, 42, 50, MemDC, (GDI_damageIncreaseOneNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
		SelectObject(MemDC, GDI_damageIncreaseNumberPont);
		TransparentBlt(backMemDC, 545, 708, 42, 50, MemDC, (GDI_damageIncreaseTenNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
	}
	else if (GDI_damageIncreaseNumber < 1000)
	{
		SelectObject(MemDC, GDI_damageIncreaseNumberPont);
		TransparentBlt(backMemDC, 574, 708, 42, 50, MemDC, (GDI_damageIncreaseOneNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
		SelectObject(MemDC, GDI_damageIncreaseNumberPont);
		TransparentBlt(backMemDC, 545, 708, 42, 50, MemDC, (GDI_damageIncreaseTenNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
		SelectObject(MemDC, GDI_damageIncreaseNumberPont);
		TransparentBlt(backMemDC, 516, 708, 42, 50, MemDC, (GDI_damageIncreaseHundredNumber) * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
	}


	//나중에 추가된 플레이어 폰트 번호 출력
	int GDI_playerTenNumber;
	int GDI_playerOneNumber;
	
	
	//플레이어 넘버 출력
	if (*GameSystem_GetRankNumber() < 10)
	{
		GDI_playerOneNumber = *GameSystem_GetRankNumber();

		SelectObject(MemDC, GDI_rankingNumberPont);
		TransparentBlt(backMemDC, 1520, 28, 42, 50, MemDC, GDI_playerOneNumber * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
	}
	else if (*GameSystem_GetRankNumber() >= 10)
	{
		GDI_playerTenNumber = *GameSystem_GetRankNumber() / 10;
		GDI_playerOneNumber = *GameSystem_GetRankNumber() % 10;

		SelectObject(MemDC, GDI_rankingNumberPont);
		TransparentBlt(backMemDC, 1500, 28, 42, 50, MemDC, GDI_playerTenNumber * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
		SelectObject(MemDC, GDI_rankingNumberPont);
		TransparentBlt(backMemDC, 1542, 28, 42, 50, MemDC, GDI_playerOneNumber * 52 + 10, 10, 42, 50, RGB(255, 0, 255));
	}

	SelectObject(MemDC, GDI_rankingWavePont);
	TransparentBlt(backMemDC, 1230, 30, 42, 50, MemDC, 790, 10, 42, 50, RGB(255, 0, 255));		//p
	TransparentBlt(backMemDC, 1272, 30, 42, 50, MemDC, 582, 10, 42, 50, RGB(255, 0, 255));		//l
	TransparentBlt(backMemDC, 1314, 30, 42, 50, MemDC, 10, 10, 42, 50, RGB(255, 0, 255));		//a
	TransparentBlt(backMemDC, 1366, 30, 42, 50, MemDC, 1258, 10, 42, 50, RGB(255, 0, 255));		//y
	TransparentBlt(backMemDC, 1408, 30, 42, 50, MemDC, 218, 10, 42, 50, RGB(255, 0, 255));		//e
	TransparentBlt(backMemDC, 1450, 30, 42, 50, MemDC, 894, 10, 42, 50, RGB(255, 0, 255));		//r
}



void GDI_PrintDoubleBuffering()
{
	BitBlt(hScreenDC, 0, 0, 1600, 900, backMemDC, 0, 0, SRCCOPY);
}

/// 엔진의 모든 것을 정리하고, 삭제한다.
void GDI_Finalize()
{
	DeleteDC(betaDC);
	DeleteDC(backMemDC);
	DeleteDC(MemDC);
}



//POINT* GDI_RetrunPoint()
//{
//	POINT m_tPoint[3];
//	double m_fDis = 50 * sqrt(2);
//	double PI = M_PI;
//	//                          B의Y   A의Y   B의X   A의X 
//	double m_fAngle = atan2f((float)0 - 50, (float)0 - 50) * 180 / PI;
//
//	m_tPoint[0].x = (LONG)(50 + cosf((135 + m_fAngle) * PI / 180.f) * m_fDis);
//	m_tPoint[0].y = (LONG)(50 - sinf((135 + m_fAngle) * PI / 180.f) * m_fDis);
//
//	m_tPoint[1].x = (LONG)(50 + cosf((45 + m_fAngle) * PI / 180.f) * m_fDis);
//	m_tPoint[1].y = (LONG)(50 - sinf((45 + m_fAngle) * PI / 180.f) * m_fDis);
//
//	m_tPoint[2].x = (LONG)(50 + cosf((225 + m_fAngle) * PI / 180.f) * m_fDis);
//	m_tPoint[2].y = (LONG)(50 - sinf((225 + m_fAngle) * PI / 180.f) * m_fDis);
//
//	return m_tPoint;
//}