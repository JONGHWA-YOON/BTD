#pragma once


#ifdef _DEBUG
#define UIPATH(text) TEXT("..\\..\\..\\4_Resources\\"#text)
#define SOUNDPATH(text) "../../../4_Resources/Music/"#text

#define STATSPATH(text) "..\\..\\..\\4_Resources\\Stats\\"#text
#define RANKPATH(text) "..\\..\\..\\4_Resources\\Ranking\\"#text

#else
#define UIPATH(text) TEXT("..\\..\\4_Resources\\"#text)
#define SOUNDPATH(text) "../../4_Resources/Music/"#text

#define STATSPATH(text) "..\\..\\4_Resources\\Stats\\"#text
#define RANKPATH(text) "..\\..\\4_Resources\\Ranking\\"#text

#endif


