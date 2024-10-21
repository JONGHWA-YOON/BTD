#include "UI.h"
#include <windows.h>
#include "GDI.h"
#include "Sound.h"

//기본 전역변수
HDC UI_hdc = NULL;
int UI_mousePointerX;
int UI_mousePointerY;
int UI_uIButtonClickState = UI_WINDOWONSTATENUMBER;
int UI_uISoundButtonClickState = TRUE;


//설치된 타워 클릭시 XY좌표 
int UI_builtTowerPointX1 = NULL;
int UI_builtTowerPointY1 = NULL;

//설치된 타워 클릭후 놓을때 XY좌표 
int UI_builtTowerPointX2 = NULL;
int UI_builtTowerPointY2 = NULL;


enum UIButtonClick
{
	UIButtonClickOff, UIButtonClickOn
};

int UI_ReturnGameOver()
{
	return UI_uIButtonClickState = UI_GAMEOVER1;
}

void UI_Initialize(HWND hWnd)
{
	UI_hdc = GetDC(hWnd);
}

//버튼 눌림상태
int UI_mouseClickJustPressed = FALSE;
int UI_mouseClickPressed = FALSE;
int UI_mouseClickUnPressed = FALSE;

//int UI_upKeyClickJustPressed = FALSE;
//int UI_rightKeyClickJustPressed = FALSE;
//int UI_downKeyClickJustPressed = FALSE;

//마우스  왼쪽버튼을 눌렀을때
void UI_MouseClickUpdate()
{
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		if (UI_mouseClickPressed == FALSE)
		{
			UI_mouseClickJustPressed = TRUE;
		}
		else
		{
			UI_mouseClickJustPressed = FALSE;
		}

		UI_mouseClickPressed = TRUE;
		UI_mouseClickUnPressed = FALSE;
	}
	else
	{
		UI_mouseClickJustPressed = FALSE;
		UI_mouseClickPressed = FALSE;
		UI_mouseClickUnPressed = TRUE;
	}
}

void UI_MousePointerXY(int x, int y)
{	
	UI_mousePointerX = x;
	UI_mousePointerY = y;
}

int UI_ReturnMousePointerX()
{
	return UI_mousePointerX;
}

int UI_ReturnMousePointerY()
{
	return UI_mousePointerY;
}

int UI_ReturnUIButtonClickState()
{
	return UI_uIButtonClickState;
}

int UI_ReturnUISoundButtonClickState()
{
	return UI_uISoundButtonClickState;
}

void UI_SceneManager()
{
	int towerPointX = 0;
	int towerPointY = 0;


	//마우스 클릭했을때 씬 및 상태 전환
	if (UI_mouseClickJustPressed == TRUE)
	{
		switch (UI_uIButtonClickState)
		{

		//첫 화면 상태
		case UI_WINDOWONSTATENUMBER:
		{
			if (UI_mousePointerX > 304 && UI_mousePointerX < 508 && UI_mousePointerY > 545 && UI_mousePointerY < 712)
			{
				Sound_PlaySound(Bungeoppang_ButtonClick);
				UI_uIButtonClickState = UI_CREDITMEMBERWINDOW;
			}

			else if (UI_mousePointerX > 661 && UI_mousePointerX < 837 && UI_mousePointerY > 545 && UI_mousePointerY < 712)
			{
				Sound_PlaySound(Bungeoppang_ButtonClick);
				UI_uIButtonClickState = UI_GAMESTARTSCENE1;
			}

			else if (UI_mousePointerX > 1017 && UI_mousePointerX < 1294 && UI_mousePointerY > 545 && UI_mousePointerY < 712)
			{
				Sound_PlaySound(Bungeoppang_ButtonClick);
				UI_uIButtonClickState = UI_GAMERULEWINDOW1;
			}

			else if (UI_mousePointerX > 246 && UI_mousePointerX < 315 && UI_mousePointerY > 736 && UI_mousePointerY < 807)
			{
				PostQuitMessage(0);
			}

			else if (UI_mousePointerX > 1172 && UI_mousePointerX < 1241 && UI_mousePointerY > 736 && UI_mousePointerY < 807)
			{
				Sound_PlaySound(Bungeoppang_ButtonClick);
				UI_uIButtonClickState = UI_RANKINGWINDOW;
			}

			else if (UI_uISoundButtonClickState == TRUE && UI_mousePointerX > 1270 && UI_mousePointerX < 1339 && UI_mousePointerY > 736 && UI_mousePointerY < 807)
			{
				for (int i = 0; i < 10; i++)
				{
					Sound_SetisSoundOn(0);
					Sound_DeleteSound();
				}

				UI_uISoundButtonClickState = FALSE;
			}

			else if (UI_uISoundButtonClickState == FALSE && UI_mousePointerX > 1270 && UI_mousePointerX < 1339 && UI_mousePointerY > 736 && UI_mousePointerY < 807)
			{
				Sound_SetisSoundOn(1);
				Sound_CreateSound();
				Sound_PlaySound(0);
				UI_uISoundButtonClickState = TRUE;
			}
		}
		break;


		//첫 화면상태에서 사운드 이외의 버튼 하나를 누른 상태
		case UI_CREDITMEMBERWINDOW:
		{
			if (UI_mousePointerX > 1268 && UI_mousePointerX < 1322 && UI_mousePointerY > 80 && UI_mousePointerY < 134)
			{
				Sound_PlaySound(Bungeoppang_ButtonClick);
				UI_uIButtonClickState = UI_WINDOWONSTATENUMBER;
			}
		}
		break;

		case UI_GAMERULEWINDOW1:
		{
			if (UI_mousePointerX > 1268 && UI_mousePointerX < 1322 && UI_mousePointerY > 80 && UI_mousePointerY < 134)
			{
				Sound_PlaySound(Bungeoppang_ButtonClick);
				UI_uIButtonClickState = UI_WINDOWONSTATENUMBER;
			}
			else if (UI_mousePointerX > 756 && UI_mousePointerX < 842 && UI_mousePointerY > 648 && UI_mousePointerY < 696)
			{
				Sound_PlaySound(Bungeoppang_ButtonClick);
				UI_uIButtonClickState = UI_GAMERULEWINDOW2;
			}
		}
		break;

		case UI_GAMERULEWINDOW2:
		{
			if (UI_mousePointerX > 1268 && UI_mousePointerX < 1322 && UI_mousePointerY > 80 && UI_mousePointerY < 134)
			{
				Sound_PlaySound(Bungeoppang_ButtonClick);
				UI_uIButtonClickState = UI_WINDOWONSTATENUMBER;
			}
			else if (UI_mousePointerX > 756 && UI_mousePointerX < 842 && UI_mousePointerY > 648 && UI_mousePointerY < 696)
			{
				Sound_PlaySound(Bungeoppang_ButtonClick);
				UI_uIButtonClickState = UI_GAMERULEWINDOW3;
			}
		}
		break;

		case UI_GAMERULEWINDOW3:
		{
			if (UI_mousePointerX > 1268 && UI_mousePointerX < 1322 && UI_mousePointerY > 80 && UI_mousePointerY < 134)
			{
				Sound_PlaySound(Bungeoppang_ButtonClick);
				UI_uIButtonClickState = UI_WINDOWONSTATENUMBER;
			}
			else if (UI_mousePointerX > 756 && UI_mousePointerX < 842 && UI_mousePointerY > 648 && UI_mousePointerY < 696)
			{
				Sound_PlaySound(Bungeoppang_ButtonClick);
				UI_uIButtonClickState = UI_GAMERULEWINDOW4;
			}
		}
		break;

		case UI_GAMERULEWINDOW4:
		{
			if (UI_mousePointerX > 1268 && UI_mousePointerX < 1322 && UI_mousePointerY > 80 && UI_mousePointerY < 134)
			{
				Sound_PlaySound(Bungeoppang_ButtonClick);
				UI_uIButtonClickState = UI_WINDOWONSTATENUMBER;
			}
		}
		break;

		case UI_RANKINGWINDOW:
		{
			if (UI_mousePointerX > 22 && UI_mousePointerX < 76 && UI_mousePointerY > 829 && UI_mousePointerY < 884)
			{
				Sound_PlaySound(Bungeoppang_ButtonClick);
				UI_uIButtonClickState = UI_WINDOWONSTATENUMBER;
			}
		}
		break;


		//게임스타트씬
		case UI_GAMESTARTSCENE1: 
		{
			Sound_PlaySound(Bungeoppang_ButtonClick);
			UI_uIButtonClickState = UI_GAMESTARTSCENE2; 
		}
		break;

		case UI_GAMESTARTSCENE2: 
		{
			Sound_PlaySound(Bungeoppang_ButtonClick);
			UI_uIButtonClickState = UI_GAMESTARTSCENE3; 
		}
		break;

		case UI_GAMESTARTSCENE3: 
		{
			Sound_PlaySound(Bungeoppang_ButtonClick);
			UI_uIButtonClickState = UI_GAMESTARTSCENE4; 
		}
		break;

		case UI_GAMESTARTSCENE4:
		{
			Sound_PlaySound(Bungeoppang_ButtonClick);
			UI_uIButtonClickState = UI_GAMESTARTSCENE5; 
		}
		break;

		case UI_GAMESTARTSCENE5:
		{
			Sound_PlaySound(Bungeoppang_ButtonClick);
			UI_uIButtonClickState = UI_GAMESTARTSCENE6; 
		}
		break;

		case UI_GAMESTARTSCENE6:
		{
			Sound_PlaySound(Bungeoppang_ButtonClick);
			UI_uIButtonClickState = UI_GAMESTARTSCENE7; 
		}
		break;

		case UI_GAMESTARTSCENE7:
		{
			// 씬 음악 끄고 메인음악 틀어주기
			Sound_PlaySound(Bungeoppang_ButtonClick);
			Sound_PauseSound(CutScene);
			GameSystem_GameStart();
			UI_uIButtonClickState = UI_INGAMEWHAT; 

		}
		break;


		//인게임 상태
		case UI_INGAMEWHAT:
		{
			if (UI_mousePointerX > 944 && UI_mousePointerX < 1127 && UI_mousePointerY > 737 && UI_mousePointerY < 872)
			{
				if (GameSystem_GetMoney() >= 500) Sound_PlaySound(Bungeoppang_ButtonClick);
				UI_uIButtonClickState = UI_BOONGTOWER1;
			}

			if (UI_mousePointerX > 1145 && UI_mousePointerX < 1331 && UI_mousePointerY > 737 && UI_mousePointerY < 872)
			{
				if (GameSystem_GetMoney() >= 750) Sound_PlaySound(Bungeoppang_ButtonClick);
				UI_uIButtonClickState = UI_BOONGTOWER2;
			}

			if (UI_mousePointerX > 1349 && UI_mousePointerX < 1532 && UI_mousePointerY > 737 && UI_mousePointerY < 872)
			{
				if (GameSystem_GetMoney() >= 1000)
				UI_uIButtonClickState = UI_BOONGTOWER3;
			}

			if (UI_mousePointerX > 200 && UI_mousePointerX <= 1400 && UI_mousePointerY > 200 && UI_mousePointerY <= 700)
			{
				for (int i = 1; i < 13; i++)
				{
					if (100 + 100 * i < UI_mousePointerX && UI_mousePointerX <= 200 + 100 * i)
					{
						UI_mousePointerX = 150 + 100 * i;
						towerPointX = i - 1;
					}
				}
				for (int i = 1; i < 6; i++)
				{
					if (100 + 100 * i < UI_mousePointerY && UI_mousePointerY <= 200 + 100 * i)
					{
						UI_mousePointerY = 150 + 100 * i;
						towerPointY = i - 1;
					}
				}

				if (BungEoPpang_bungEoPpangArray[towerPointY][towerPointX].kind != BungEoPpang_eNull && BungEoPpang_bungEoPpangArray[towerPointY][towerPointX].kind != BungEoPpang_eCantUse)
				{
					UI_builtTowerPointX1 = towerPointX;
					UI_builtTowerPointY1 = towerPointY;
					UI_uIButtonClickState = UI_BUILTBOONGTOWER;
				}
				else
				{
					UI_uIButtonClickState = UI_INGAMEWHAT;
				}
			}
		}
		break;

		//인게임 상태에서 타워 버튼을 하나 누른 상태	
		case UI_BOONGTOWER1:
		{
			
			if (UI_mousePointerX > 200 && UI_mousePointerX <= 1400 && UI_mousePointerY > 200 && UI_mousePointerY <= 700)
			{
				//타워 건설 좌표 받기
				for (int i = 1; i < 13; i++)
				{
					if (100 + 100 * i < UI_mousePointerX && UI_mousePointerX <= 200 + 100 * i)
					{
						UI_mousePointerX = 150 + 100 * i;
						towerPointX = i-1;
					}
				}
				for (int i = 1; i < 6; i++)
				{
					if (100 + 100 * i < UI_mousePointerY && UI_mousePointerY <= 200 + 100 * i)
					{
						UI_mousePointerY = 150 + 100 * i;
						towerPointY = i-1;
					}
				}

				//조건부 타워 건설
				if (BungEoPpang_bungEoPpangArray[towerPointY][towerPointX].kind == BungEoPpang_eNull)
				{
					if (GameSystem_GetMoney() >= 500) Sound_PlaySound(Bungeoppang_Collocate);
					BungEoPpang_AddBungEoPpang(towerPointY, towerPointX, BungEoPpang_e1_1);
					UI_uIButtonClickState = UI_INGAMEWHAT;
				}
				else
				{
					UI_uIButtonClickState = UI_INGAMEWHAT;
				}
			}
			else
			{
				UI_uIButtonClickState = UI_INGAMEWHAT;
			}
		}
		break;

		case UI_BOONGTOWER2:
		{
			if (UI_mousePointerX >= 200 && UI_mousePointerX <= 1400 && UI_mousePointerY >= 200 && UI_mousePointerY <= 700)
			{
				//타워 건설 좌표 받기
				for (int i = 1; i < 13; i++)
				{
					if (100 + 100 * i < UI_mousePointerX && UI_mousePointerX <= 200 + 100 * i)
					{
						UI_mousePointerX = 150 + 100 * i;
						towerPointX = i-1;
					}
				}
				for (int i = 1; i < 6; i++)
				{
					if (100 + 100 * i < UI_mousePointerY && UI_mousePointerY <= 200 + 100 * i)
					{
						UI_mousePointerY = 150 + 100 * i;
						towerPointY = i-1;
					}
				}

				//조건부 타워 건설
				if (BungEoPpang_bungEoPpangArray[towerPointY][towerPointX].kind == BungEoPpang_eNull)
				{				
					if (GameSystem_GetMoney() >= 750) Sound_PlaySound(Bungeoppang_Collocate);
					BungEoPpang_AddBungEoPpang(towerPointY, towerPointX, BungEoPpang_e1_2);
					UI_uIButtonClickState = UI_INGAMEWHAT;
				}
				else
				{
					UI_uIButtonClickState = UI_INGAMEWHAT;
				}
			}
			else
			{
				UI_uIButtonClickState = UI_INGAMEWHAT;
			}
		}
		break;

		case UI_BOONGTOWER3:
		{
			if (UI_mousePointerX >= 200 && UI_mousePointerX <= 1400 && UI_mousePointerY >= 200 && UI_mousePointerY <= 700)
			{
				for (int i = 1; i < 13; i++)
				{
					if (100 + 100 * i < UI_mousePointerX && UI_mousePointerX <= 200 + 100 * i)
					{
						UI_mousePointerX = 150 + 100 * i;
						towerPointX = i-1;
					}
				}
				for (int i = 1; i < 6; i++)
				{
					if (100 + 100 * i < UI_mousePointerY && UI_mousePointerY <= 200 + 100 * i)
					{
						UI_mousePointerY = 150 + 100 * i;
						towerPointY = i-1;
					}
				}
				//조건부 타워 건설
				if (BungEoPpang_bungEoPpangArray[towerPointY][towerPointX].kind == BungEoPpang_eNull)
				{
					if (GameSystem_GetMoney() >= 1000) Sound_PlaySound(Bungeoppang_Collocate);
					BungEoPpang_AddBungEoPpang(towerPointY, towerPointX, BungEoPpang_e1_3);
					UI_uIButtonClickState = UI_INGAMEWHAT;
				}
				else
				{
					UI_uIButtonClickState = UI_INGAMEWHAT;
				}
			}
			else
			{
				UI_uIButtonClickState = UI_INGAMEWHAT;
			}
		}
		break;

		//설치된 타워 클릭시
		case UI_BUILTBOONGTOWER:
		{
			for (int i = 1; i < 13; i++)
			{
				if (100 + 100 * i < UI_mousePointerX && UI_mousePointerX < 200 + 100 * i)
				{
					UI_mousePointerX = 150 + 100 * i;
					towerPointX = i - 1;
				}
			}
			for (int i = 1; i < 6; i++)
			{
				if (100 + 100 * i < UI_mousePointerY && UI_mousePointerY < 200 + 100 * i)
				{
					UI_mousePointerY = 150 + 100 * i;
					towerPointY = i - 1;
				}
			}
			if (BungEoPpang_bungEoPpangArray[towerPointY][towerPointX].kind != BungEoPpang_eNull && BungEoPpang_bungEoPpangArray[towerPointY][towerPointX].kind != BungEoPpang_eCantUse)
			{
				UI_builtTowerPointX2 = towerPointX;
				UI_builtTowerPointY2 = towerPointY;
			
				BungEoPpang_CombineBungEoPpang(UI_builtTowerPointX1, UI_builtTowerPointY1, UI_builtTowerPointX2, UI_builtTowerPointY2);

				//전달 좌표 초기화
				UI_builtTowerPointX1 = NULL;
				UI_builtTowerPointY1 = NULL;
				UI_builtTowerPointX2 = NULL;
				UI_builtTowerPointY2 = NULL;

				UI_uIButtonClickState = UI_INGAMEWHAT;
			}
			else
			{
				UI_uIButtonClickState = UI_INGAMEWHAT;
			}
		}
		break;

		case UI_GAMEOVER1:
		{
			// 메인 게임 음악 종료 및 게임오버 음악 실행
			
			UI_uIButtonClickState = UI_GAMEOVER2;
		}
		break;

		case UI_GAMEOVER2:
		{
			if (UI_mousePointerX > 614 && UI_mousePointerX < 714 && UI_mousePointerY > 771 && UI_mousePointerY < 871)
			{
				// 홈 화면 클릭시 씬 음악 재생
				Sound_PauseSound(GameOver);

				GameSystem_DeleteGame();
				Sound_PlaySound(Bungeoppang_ButtonClick);
				Sound_PlaySound(CutScene);
				UI_uIButtonClickState = UI_WINDOWONSTATENUMBER;
			}
			if (UI_mousePointerX > 872 && UI_mousePointerX < 972 && UI_mousePointerY > 771 && UI_mousePointerY < 871)
			{
				// 되 돌아가기 클릭시 메인 게임 음악 다시 재생
				Sound_PauseSound(GameOver);
				Sound_PlaySound(CutScene);
				GameSystem_DeleteGame();
				Sound_PlaySound(Bungeoppang_ButtonClick);
				GameSystem_GameStart();
				UI_uIButtonClickState = UI_INGAMEWHAT;
			}
		}
		break;

		default:
			break;
		}
	}
}

void UI_UIDrawing()
{
	//타이틀 UI
	if (UI_uIButtonClickState >= UI_WINDOWONSTATENUMBER && UI_uIButtonClickState < UI_INGAMEWHAT)
	{
		GDI_TitleUIDraw();
		
		//소리버튼 누를시
		if (UI_ReturnUISoundButtonClickState() == FALSE)
		{
			GDI_DrawSoundOffBitmap();
		}

		//버튼 누를때
		switch (UI_uIButtonClickState)
		{

		//게임방법 버튼누를시1~4
		case UI_GAMERULEWINDOW1:
		{
			GDI_GameRuleWindowDraw1();
		}
		break;

		case UI_GAMERULEWINDOW2:
		{
			GDI_GameRuleWindowDraw2();
		}
		break;

		case UI_GAMERULEWINDOW3:
		{
			GDI_GameRuleWindowDraw3();
		}
		break;

		case UI_GAMERULEWINDOW4:
		{
			GDI_GameRuleWindowDraw4();
		}
		break;

		//제작진들 버튼 누를시
		case UI_CREDITMEMBERWINDOW:
		{
			GDI_CreditWindowDraw();
		}
		break;

		//랭킹버튼 누를시
		case UI_RANKINGWINDOW:
		{
			GDI_RankingWindowDraw();
			GDI_RankingPontDraw();
		}
		break;

		default:
			break;
		}
	}

	//게임시작 컷신 7개
	else if (UI_uIButtonClickState == UI_GAMESTARTSCENE1)
	{
		GDI_DrawSceneBitmap1();
	}
	else if (UI_uIButtonClickState == UI_GAMESTARTSCENE2)
	{
		GDI_DrawSceneBitmap2();
	}
	else if (UI_uIButtonClickState == UI_GAMESTARTSCENE3)
	{
		GDI_DrawSceneBitmap3();
	}
	else if (UI_uIButtonClickState == UI_GAMESTARTSCENE4)
	{
		GDI_DrawSceneBitmap4();
	}
	else if (UI_uIButtonClickState == UI_GAMESTARTSCENE5)
	{
		GDI_DrawSceneBitmap5();
	}
	else if (UI_uIButtonClickState == UI_GAMESTARTSCENE6)
	{
		GDI_DrawSceneBitmap6();
	}
	else if (UI_uIButtonClickState == UI_GAMESTARTSCENE7)
	{
		GDI_DrawSceneBitmap7();
	}

	
	//인게임 UI
	else if (UI_uIButtonClickState >= UI_INGAMEWHAT && UI_uIButtonClickState < 30)
	{
		GDI_IngameUIDraw();
		GDI_NumberPontBitmap();
		GDI_BuiltBungTowerBitmap();
		GDI_BungTowerBulletBitmap();
		UpgradeCommand_DrawAnswerCommand();


		switch (UI_uIButtonClickState)
		{

		case UI_BUILTBOONGTOWER:
		{
			GDI_TowerBuildSpaceBitmap();
			GDI_DragTowerBitmap(UI_mousePointerX, UI_mousePointerY);
		}
		break;

		case UI_BOONGTOWER1:
		{
			if (GameSystem_GetMoney() < 500)
			{
				break;
			}

			GDI_TowerBuildSpaceBitmap();
			if (UI_mousePointerX >= 200 && UI_mousePointerX <= 1400 && UI_mousePointerY >= 200 && UI_mousePointerY <= 700)
			{
				for (int i = 1; i < 13; i++)
				{
					if (100 + 100 * i < UI_mousePointerX && UI_mousePointerX <= 200 + 100 * i)
					{
						UI_mousePointerX = 150 + 100 * i;
					}
				}
				for (int i = 1; i < 6; i++)
				{
					if (100 + 100 * i < UI_mousePointerY && UI_mousePointerY <= 200 + 100 * i)
					{
						UI_mousePointerY = 150 + 100 * i;
					}
				}
			}
			GDI_BungTowerDragBitmap1(UI_ReturnMousePointerX(), UI_ReturnMousePointerY());
		}
		break;

		case UI_BOONGTOWER2:
		{
			if (GameSystem_GetMoney() < 750)
			{
				break;
			}

			GDI_TowerBuildSpaceBitmap();
			if (UI_mousePointerX >= 200 && UI_mousePointerX <= 1400 && UI_mousePointerY >= 200 && UI_mousePointerY <= 700)
			{
				for (int i = 1; i < 13; i++)
				{
					if (100 + 100 * i < UI_mousePointerX && UI_mousePointerX <= 200 + 100 * i)
					{
						UI_mousePointerX = 150 + 100 * i;
					}
				}
				for (int i = 1; i < 6; i++)
				{
					if (100 + 100 * i < UI_mousePointerY && UI_mousePointerY <= 200 + 100 * i)
					{
						UI_mousePointerY = 150 + 100 * i;
					}
				}
			}
			GDI_BungTowerDragBitmap2(UI_ReturnMousePointerX(), UI_ReturnMousePointerY());
		}
		break;

		case UI_BOONGTOWER3:
		{
			if (GameSystem_GetMoney() < 1000)
			{
				break;
			}

			GDI_TowerBuildSpaceBitmap();
			if (UI_mousePointerX >= 200 && UI_mousePointerX <= 1400 && UI_mousePointerY >= 200 && UI_mousePointerY <= 700)
			{
				for (int i = 1; i < 13; i++)
				{
					if (100 + 100 * i < UI_mousePointerX && UI_mousePointerX <= 200 + 100 * i)
					{
						UI_mousePointerX = 150 + 100 * i;
					}
				}
				for (int i = 1; i < 6; i++)
				{
					if (100 + 100 * i < UI_mousePointerY && UI_mousePointerY <= 200 + 100 * i)
					{
						UI_mousePointerY = 150 + 100 * i;
					}
				}
			}
			GDI_BungTowerDragBitmap3(UI_ReturnMousePointerX(), UI_ReturnMousePointerY());
		}
		break;

		default:
			break;
		}
	}
	else if (UI_uIButtonClickState >= UI_INGAMEWHAT)
	{
		switch (UI_uIButtonClickState)
		{
		case UI_GAMEOVER1:
		{
			GDI_GameOverBackGroundDraw();
		}
		break;
		case UI_GAMEOVER2:
		{
			GDI_GameOverUIDraw();
		}
		break;

		default:
			break;
		}
	}

}