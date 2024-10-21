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

// ���� ����
int Sound_CreateSound();
	
// ���� ���
void Sound_PlaySound(int SoundName);
	
// ���� �ߴ�, �ٽý���
void Sound_VolumePause(int SoundName);
	
// ���� ����
void Sound_PauseSound(int soundName);

// ���� �簳
void Sound_ResumeSound(int soundName);
	
// ���� ����
void Sound_DeleteSound();

int Sound_GetisSoundOn();

void Sound_SetisSoundOn(int);


#ifdef __cplusplus
}
#endif



