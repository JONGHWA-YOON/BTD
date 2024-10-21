#include "Frame.h"
#include "DeltaTime.h"

int Frame_callCount = 0;
double Frame_checkTime = 0;

int Frame_FPS = 0;

void Frame_FrameCheck()
{
	++Frame_callCount;
	Frame_checkTime += DeltaTime_GetDeltaTime();
	if (Frame_checkTime >= 1)
	{
		Frame_FPS = Frame_callCount; // 1초에 몇번 불러졋나 = FPS

		Frame_checkTime = 0;
		Frame_callCount = 0;
	}
}

int Frame_GetFPS()
{
	return Frame_FPS;
}