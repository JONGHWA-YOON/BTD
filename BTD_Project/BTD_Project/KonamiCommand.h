#pragma once

// 키보드 상태를 정의하는 함수
typedef enum eKeyCode
{
	KonamiCommand_eNokey,
	KonamiCommand_eLeftArrow,
	KonamiCommand_eRightArrow,
	KonamiCommand_eUpArrow,
	KonamiCommand_eDownArrow,
}eKeyCode;

// 코나미 커맨드 실행
void KonamiCommand_Hidden();