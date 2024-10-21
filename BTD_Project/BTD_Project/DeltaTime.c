#include "DeltaTime.h"
#include <windows.h>

LARGE_INTEGER DeltaTime_frequency;
LARGE_INTEGER DeltaTime_startCounter;
LARGE_INTEGER DeltaTime_endCounter;

double DeltaTime_counts = 0;
double DeltaTime_deltaTime = 0;

void DeltaTime_StartRecordDeltaTime()
{
	QueryPerformanceFrequency(&DeltaTime_frequency);

	QueryPerformanceCounter(&DeltaTime_startCounter);
}

void DeltaTime_EndRecordDeltaTime()
{

	QueryPerformanceCounter(&DeltaTime_endCounter);

	DeltaTime_counts = (double)DeltaTime_endCounter.QuadPart - (double)DeltaTime_startCounter.QuadPart;

	DeltaTime_deltaTime = DeltaTime_counts / (double)DeltaTime_frequency.QuadPart;

}

double DeltaTime_GetDeltaTime()
{
	return DeltaTime_deltaTime;
}