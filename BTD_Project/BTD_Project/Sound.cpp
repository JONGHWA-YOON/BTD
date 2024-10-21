#include <windows.h>
#include "fmod.hpp" 
#include <iostream>
#include <conio.h>
#pragma comment(lib, "fmod_vc.lib") // 해당 라이브러리 필요하다는 뜻
#include "Sound.h" 
#include <thread>
#include "Path.h"
extern "C" {
}

using std::thread;
using namespace std;
FMOD::Sound* g_sound[15];     //사운드 배열, 총 갯수
FMOD::Channel* g_channel[15]; // sound의 갯수와 같다.

FMOD_RESULT    result;
unsigned int   version;
FMOD::System* SoundSystem(nullptr);

int isSoundOn = true;

int Sound_CreateSound()
{
	result = FMOD::System_Create(&SoundSystem);	// 시스템 객체 생성
	if (result != FMOD_OK) return -1; // 문제 생길시 return -1로 종료 
	result = SoundSystem->init(32, FMOD_INIT_NORMAL, NULL); // 시스템 초기화 : channel 32개까지 사용하겠다.
	if (result != FMOD_OK) return -1;
	result = SoundSystem->createSound(SOUNDPATH(CutScene.wav), FMOD_LOOP_NORMAL, nullptr, &g_sound[CutScene]);
	if (result != FMOD_OK) return -1; 
	result = SoundSystem->createSound(SOUNDPATH(Ingame_Main.wav), FMOD_LOOP_NORMAL, nullptr, &g_sound[InGame_Main]);
	if (result != FMOD_OK) return -1;
	result = SoundSystem->createSound(SOUNDPATH(GameOver.wav), FMOD_LOOP_OFF, nullptr, &g_sound[GameOver]);
	if (result != FMOD_OK) return -1;
	result = SoundSystem->createSound(SOUNDPATH(Combo_Success.wav), FMOD_LOOP_OFF, nullptr, &g_sound[Combo_Success]);
	if (result != FMOD_OK) return -1;
	result = SoundSystem->createSound(SOUNDPATH(Combo_Fail.wav), FMOD_LOOP_OFF, nullptr, &g_sound[Combo_Fail]);
	if (result != FMOD_OK) return -1;
	result = SoundSystem->createSound(SOUNDPATH(Bungeoppang_Attack.wav), FMOD_LOOP_OFF, nullptr, &g_sound[Bungeoppang_Attack]);
	if (result != FMOD_OK) return -1;
	result = SoundSystem->createSound(SOUNDPATH(Bungeoppang_Collocate.wav), FMOD_LOOP_OFF, nullptr, &g_sound[Bungeoppang_Collocate]);
	if (result != FMOD_OK) return -1;
	result = SoundSystem->createSound(SOUNDPATH(Bungeoppang_Synthesis.wav), FMOD_LOOP_OFF, nullptr, &g_sound[Bungeoppang_Synthesis]);
	if (result != FMOD_OK) return -1;
	result = SoundSystem->createSound(SOUNDPATH(Bungeoppang_ButtonClick.wav), FMOD_LOOP_OFF, nullptr, &g_sound[Bungeoppang_ButtonClick]);
	if (result != FMOD_OK) return -1;
	result = SoundSystem->createSound(SOUNDPATH(GetMoney.wav), FMOD_LOOP_OFF, nullptr, &g_sound[GetMoney]);
	if (result != FMOD_OK) return -1;

}


void Sound_PlaySound(int SoundName)
{
	switch (SoundName) //재생 파트, 아래 PlatSound를 추가 하면 새 사운드를 재생 할 수 있다.
	{
	case 0:
		result = SoundSystem->playSound(g_sound[CutScene], nullptr, false, &g_channel[CutScene]);
		break;
	case 1:
		result = SoundSystem->playSound(g_sound[InGame_Main], nullptr, false, &g_channel[InGame_Main]);
		break;
	case 2:
		result = SoundSystem->playSound(g_sound[GameOver], nullptr, false, &g_channel[GameOver]);
		break;
	case 3:
		result = SoundSystem->playSound(g_sound[Combo_Success], nullptr, false, &g_channel[Combo_Success]);
		break;
	case 4:
		result = SoundSystem->playSound(g_sound[Combo_Fail], nullptr, false, &g_channel[Combo_Fail]);
		break;
	case 5:
		result = SoundSystem->playSound(g_sound[Bungeoppang_Attack], nullptr, false, &g_channel[Bungeoppang_Attack]);
		break;
	case 6:
		result = SoundSystem->playSound(g_sound[Bungeoppang_Collocate], nullptr, false, &g_channel[Bungeoppang_Collocate]);
		break;
	case 7:
		result = SoundSystem->playSound(g_sound[Bungeoppang_Synthesis], nullptr, false, &g_channel[Bungeoppang_Synthesis]);
		break;
	case 8:
		result = SoundSystem->playSound(g_sound[Bungeoppang_ButtonClick], nullptr, false, &g_channel[Bungeoppang_ButtonClick]);
		break;
	case 9:
		result = SoundSystem->playSound(g_sound[GetMoney], nullptr, false, &g_channel[GetMoney]);
		break;
	default:
		break;
	}
}


void Sound_VolumePause(int soundName) //일시정지 파트
{
	static BOOL nowPlaying = 1;

	if (nowPlaying == 1)
	{
		g_channel[soundName]->setPaused(true);
		nowPlaying = 0;
	}
	else
	{
		g_channel[soundName]->setPaused(false);
		nowPlaying = 1;
	}
}

void Sound_PauseSound(int soundName)
{
	g_channel[soundName]->setPaused(true);
}

void Sound_ResumeSound(int soundName)
{
	g_channel[soundName]->setPaused(false);
}

void Sound_DeleteSound()
{
	SoundSystem->release();
}

int Sound_GetisSoundOn()
{
	return isSoundOn;
}

void Sound_SetisSoundOn(int flag)
{
	isSoundOn = flag;
}
