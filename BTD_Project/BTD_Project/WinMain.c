///
/// BTD_Project - 붕어빵 타워 디펜스
/// 
/// WinMain MBCS 디폴트
/// 
/// 
/// 

#include <windows.h>
#include <tchar.h>
#include <stdlib.h>

#include "GameSystem.h"
#include "GDI.h"
#include "UI.h"
#include "KonamiCommand.h"
#include "Sound.h"
#include "BungEoPpang.h"
#include "FileIO.h"

extern BungEoPpang BungEoPpang_bungEoPpangArray[5][12];



// 윈도 핸들 전역변수
HWND hWnd;
PAINTSTRUCT ps;
HINSTANCE hInst;

// 윈도 프로시저의 선언부. 전방선언
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

/// WinMain 함수 : 윈도즈 프로그램의 최초 진입점 ( Entry Point )
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR	lpCmdLine, int nCmdShow)
{
	char szAppName[] = _T("BungeoppangTowerDefense");

	MSG msg;
	WNDCLASS wndclass;

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	/// 윈도 클래스 등록
	RegisterClass(&wndclass);

	/// 윈도 생성
	hWnd = CreateWindow(
		szAppName,
		szAppName,
		(WS_OVERLAPPED | WS_SYSMENU),
		CW_USEDEFAULT, CW_USEDEFAULT,
		1616, 939,						// 윈도우 크기
		NULL, NULL,
		hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	// 엑셀에서 수치 읽어와서 설정
	{
		GetBungEoPpangInfo();
		GetBulletInfo();
		GetEnemyInfo();
		GetRanking();
	}

	/// 음악 생성
	Sound_CreateSound();

	/// 음악 재생
	Sound_PlaySound(CutScene);
	

	/// 생성된 윈도를 화면에 표시
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// 윈도 핸들로부터 화면의 HDC를 구한다.
	GDI_Initialize(hWnd);

	// 각종 메모리 DC등을 만든다.
	GDI_CreateDC();

	// 비트맵을 로드한다.
	GDI_LoadBitmap();

	srand(time(NULL)); // 매번 다른 시드값 생성

	/// 메시지 루프
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			DispatchMessage(&msg);
		}
		else
		{
			DeltaTime_StartRecordDeltaTime();

			UI_MouseClickUpdate();
			UI_SceneManager();
			UI_UIDrawing();

			// 30마리 전부 테스트
			// Loadimage 매번 하지말고 겜 시작할때 변수에 미리 담아둔뒤에 사용하기
			// 이거 위치는 GameSystem에 waveIng 내부로 이동시키기
			for (int i = 0; i < 30; ++i)
				GDI_MonsterBitmap(
					Enemy_EnemyArr[i].Enemy_Xposition,
					Enemy_EnemyArr[i].Enemy_Yposition,
					Enemy_EnemyArr[i].Enemy_Headposition,
					Enemy_EnemyArr[i].Enemy_Type);


			TCHAR tt[10];
			_itoa_s(Frame_GetFPS(), tt, 10, 10);
			TextOut(GDI_GetBackBuffer(), 0, 0, _T(tt), _tcslen(tt));
			 
			/// 커맨드 관련 함수들
			KonamiCommand_Hidden();

			GameSystem_Update();

			GDI_PrintDoubleBuffering();

			// 델타타임 측정
			DeltaTime_EndRecordDeltaTime();

			// 프레임 출력
			Frame_FrameCheck();
			// 백버퍼의 내용을 모두 화면 버퍼로 출력한다.
		}
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_MOUSEMOVE:
	{
		UI_MousePointerXY(LOWORD(lParam), HIWORD(lParam));
		return 0;
	}

	case WM_DESTROY:
	{
		PostQuitMessage(0);

		break;
	}

	default:
	{
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	}
	return 0;
}
