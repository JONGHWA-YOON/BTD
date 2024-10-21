///
/// BTD_Project - �ؾ Ÿ�� ���潺
/// 
/// WinMain MBCS ����Ʈ
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



// ���� �ڵ� ��������
HWND hWnd;
PAINTSTRUCT ps;
HINSTANCE hInst;

// ���� ���ν����� �����. ���漱��
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

/// WinMain �Լ� : ������ ���α׷��� ���� ������ ( Entry Point )
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

	/// ���� Ŭ���� ���
	RegisterClass(&wndclass);

	/// ���� ����
	hWnd = CreateWindow(
		szAppName,
		szAppName,
		(WS_OVERLAPPED | WS_SYSMENU),
		CW_USEDEFAULT, CW_USEDEFAULT,
		1616, 939,						// ������ ũ��
		NULL, NULL,
		hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	// �������� ��ġ �о�ͼ� ����
	{
		GetBungEoPpangInfo();
		GetBulletInfo();
		GetEnemyInfo();
		GetRanking();
	}

	/// ���� ����
	Sound_CreateSound();

	/// ���� ���
	Sound_PlaySound(CutScene);
	

	/// ������ ������ ȭ�鿡 ǥ��
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// ���� �ڵ�κ��� ȭ���� HDC�� ���Ѵ�.
	GDI_Initialize(hWnd);

	// ���� �޸� DC���� �����.
	GDI_CreateDC();

	// ��Ʈ���� �ε��Ѵ�.
	GDI_LoadBitmap();

	srand(time(NULL)); // �Ź� �ٸ� �õ尪 ����

	/// �޽��� ����
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

			// 30���� ���� �׽�Ʈ
			// Loadimage �Ź� �������� �� �����Ҷ� ������ �̸� ��Ƶеڿ� ����ϱ�
			// �̰� ��ġ�� GameSystem�� waveIng ���η� �̵���Ű��
			for (int i = 0; i < 30; ++i)
				GDI_MonsterBitmap(
					Enemy_EnemyArr[i].Enemy_Xposition,
					Enemy_EnemyArr[i].Enemy_Yposition,
					Enemy_EnemyArr[i].Enemy_Headposition,
					Enemy_EnemyArr[i].Enemy_Type);


			TCHAR tt[10];
			_itoa_s(Frame_GetFPS(), tt, 10, 10);
			TextOut(GDI_GetBackBuffer(), 0, 0, _T(tt), _tcslen(tt));
			 
			/// Ŀ�ǵ� ���� �Լ���
			KonamiCommand_Hidden();

			GameSystem_Update();

			GDI_PrintDoubleBuffering();

			// ��ŸŸ�� ����
			DeltaTime_EndRecordDeltaTime();

			// ������ ���
			Frame_FrameCheck();
			// ������� ������ ��� ȭ�� ���۷� ����Ѵ�.
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
