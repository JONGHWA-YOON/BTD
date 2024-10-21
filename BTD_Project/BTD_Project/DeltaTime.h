#pragma once


// 델타타임 구하기 위한 기록을 시작하는 함수
void DeltaTime_StartRecordDeltaTime();

// 델타타임 기록 시작부터 얼마나 걸렸는지 측정해서 델타타임 갱신
void DeltaTime_EndRecordDeltaTime();

// 현재 델타타임 가져옴
double DeltaTime_GetDeltaTime();