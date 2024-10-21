#pragma once
#include <Windows.h>
#include "BungEoPpang.h"
#include "GameSystem.h"
#include "UpgradeCommand.h"
#include "Bullet.h"
#include "GameSystem.h"



//임시 비트맵 그리기
void GDI_DrawBitmap();

//모든 비트맵 로드
void GDI_LoadBitmap();

//핸들 가져오기
void GDI_Initialize(HWND hWnd);

HDC GDI_GetScreenDC();
HDC GDI_GetBackBuffer();

//더블버퍼링 최종작업
void GDI_PrintDoubleBuffering();

// 엔진을 정리한다.
void GDI_Finalize();

//더블 버퍼링을 위한 DC값 가져오기
void GDI_CreateDC();

//타이틀 UI 그리기
void GDI_TitleUIDraw();

//랭킹 팝업창 폰트 그리기
void GDI_RankingPontDraw();

//타이틀에서 랭킹 팝업창 그리기
void GDI_RankingWindowDraw();

//타이틀에서 게임방법 팝업창 그리기 4개
void GDI_GameRuleWindowDraw1();
void GDI_GameRuleWindowDraw2();
void GDI_GameRuleWindowDraw3();
void GDI_GameRuleWindowDraw4();

//타이틀에서 제작진 팝업창 그리기
void GDI_CreditWindowDraw();

//사운드오프 비트맵 그리기
void GDI_DrawSoundOffBitmap();


//인게임 UI 그리기
void GDI_IngameUIDraw();

//타워 설치 가능 장소 프린트
void GDI_TowerBuildSpaceBitmap();

//붕어빵타워 3종 그리기
void GDI_BungTowerDragBitmap1(int pointerX, int pointerY);
void GDI_BungTowerDragBitmap2(int pointerX, int pointerY);
void GDI_BungTowerDragBitmap3(int pointerX, int pointerY);

//설치된 붕어빵 그리기
void GDI_BuiltBungTowerBitmap();

//설치된 붕어빵 클릭시 드래그 프린트
void GDI_DragTowerBitmap(int pointerX, int pointerY);

//붕어빵 탄환 그리기
void GDI_BungTowerBulletBitmap();

//몬스터 그리기
void GDI_MonsterBitmap(int Enemy_X, int Enemy_Y, eEnemy_Head Enemy_Head, eEnemy_Type Enemy_Type);


// 업그레이드 커맨드 위 빛남 
void GDI_UpgradeCommandUp();


// 업그레이드 커맨드 아래 빛남
void GDI_UpgradeCommandDown();


// 업그레이드 커맨드 왼쪽 빛남
void GDI_UpgradeCommandLeft();


// 업그레이드 커맨드 오른쪽 빛남
void GDI_UpgradeCommandRight();


//인게임 폰트 출력
void GDI_NumberPontBitmap();


//게임오버 화면 출력
void GDI_GameOverUIDraw();
void GDI_GameOverBackGroundDraw();


//컷씬 그리기 7개
void GDI_DrawSceneBitmap1();
void GDI_DrawSceneBitmap2();
void GDI_DrawSceneBitmap3();
void GDI_DrawSceneBitmap4();
void GDI_DrawSceneBitmap5();
void GDI_DrawSceneBitmap6();
void GDI_DrawSceneBitmap7();