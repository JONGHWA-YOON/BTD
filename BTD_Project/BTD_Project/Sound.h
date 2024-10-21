#pragma once

#ifdef __cplusplus
extern "C" {
#endif


typedef enum eSoundName
{
	CutScene,
	InGame_Main,
	GameOver,
	Combo_Success,
	Combo_Fail,
	Bungeoppang_Attack,
	Bungeoppang_Collocate,
	Bungeoppang_Synthesis,
	Bungeoppang_ButtonClick,
	GetMoney
}eSoundName;

// 사운드 생성
int Sound_CreateSound();
	
// 사운드 출력
void Sound_PlaySound(int SoundName);
	
// 사운드 중단, 다시실행
void Sound_VolumePause(int SoundName);
	
// 사운드 중지
void Sound_PauseSound(int soundName);

// 사운드 재개
void Sound_ResumeSound(int soundName);
	
// 사운드 삭제
void Sound_DeleteSound();

int Sound_GetisSoundOn();

void Sound_SetisSoundOn(int);


#ifdef __cplusplus
}
#endif



