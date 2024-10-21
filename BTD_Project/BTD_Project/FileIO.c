#include <stdio.h>
#include <stdlib.h>

#include "FileIO.h"

#include "BungEoPpang.h"
#include "Bullet.h"
#include "Enemy.h"
#include "GameSystem.h"
#include "Path.h"


char* GetNextString(char* ap_src_str, char a_delimiter, char* ap_buffer)
{
	while (*ap_src_str && *ap_src_str != a_delimiter)
	{
		*ap_buffer++ = *ap_src_str++;
	}

	if (*(ap_buffer - 1) == '\n')
	{
		*(ap_buffer - 1) = 0;
	}
	else
	{
		*ap_buffer = 0;
	}

	if (*ap_src_str == a_delimiter)
	{
		ap_src_str++;
	}

	return ap_src_str;
}

void GetBungEoPpangInfo()
{
	FILE* p_file = NULL;
	BungEoPpang* bungInfo = BungEoPpang_GetBungEoPpang_bungEoPpangInfo();

	if (0 == fopen_s(&p_file, STATSPATH(BungEoPpang.csv), "rt"))
	{
		char one_line_string[128], str[32], * p_pos;

		if (NULL != fgets(one_line_string, 128, p_file))
		{
			p_pos = one_line_string;
		}

		int idx = 0;
		while (NULL != fgets(one_line_string, 128, p_file))
		{
			p_pos = one_line_string;

			p_pos = GetNextString(p_pos, ',', str);

			p_pos = GetNextString(p_pos, ',', str);
			bungInfo[idx].attackSpeed = atof(str);

			p_pos = GetNextString(p_pos, ',', str);
			bungInfo[idx].attackRange = atof(str);

			p_pos = GetNextString(p_pos, ',', str);
			bungInfo[idx].attackCount = atoi(str);

			++idx;
		}

		fclose(p_file);
	}
}

void GetBulletInfo()
{
	FILE* p_file = NULL;
	Bullet* bulletInfo = Bullet_GetBulletInfo();;

	if (0 == fopen_s(&p_file, STATSPATH(Bullet.csv), "rt"))
	{
		char one_line_string[128], str[32], * p_pos;

		if (NULL != fgets(one_line_string, 128, p_file)) 
		{
			p_pos = one_line_string;

		}

		int idx = 0;
		while (NULL != fgets(one_line_string, 128, p_file))
		{
			p_pos = one_line_string;

			p_pos = GetNextString(p_pos, ',', str);

			p_pos = GetNextString(p_pos, ',', str);
			bulletInfo[idx].bulletDamage = atof(str);

			p_pos = GetNextString(p_pos, ',', str);
			bulletInfo[idx].bulletSpeed = atof(str);

			p_pos = GetNextString(p_pos, ',', str);
			bulletInfo[idx].bulletSlow = atoi(str);

			++idx;
		}

		fclose(p_file);
	}
}

void GetEnemyInfo()
{
	FILE* p_file = NULL;
	Enemy* enemyInfo = Enemy_GetEnemyInfo();

	if (0 == fopen_s(&p_file, STATSPATH(Enemy.csv), "rt"))
	{
		char one_line_string[128], str[32], * p_pos;

		if (NULL != fgets(one_line_string, 128, p_file))
		{
			p_pos = one_line_string;

		}

		int idx = 1;
		while (NULL != fgets(one_line_string, 128, p_file))
		{
			p_pos = one_line_string;

			p_pos = GetNextString(p_pos, ',', str);

			p_pos = GetNextString(p_pos, ',', str);
			enemyInfo[idx].Enemy_Hp = atof(str);

			p_pos = GetNextString(p_pos, ',', str);
			enemyInfo[idx].Enemy_Speed = atof(str);

			++idx;
		}

		fclose(p_file);
	}
}

void GetRanking()
{
	FILE* p_file = NULL;
	int (*rankArr)[2] =	GameSystem_GetRankArray();

	if (0 == fopen_s(&p_file, RANKPATH(Ranking.csv), "rt"))
	{
		char one_line_string[128], str[32], * p_pos;

		if (NULL != fgets(one_line_string, 128, p_file)) 
		{
			int* rank = GameSystem_GetRankNumber();

			p_pos = one_line_string;
			p_pos = GetNextString(p_pos, ',', str);

			*rank = atoi(str);
			*rank += 1;
		}

		int idx = 0;
		while (NULL != fgets(one_line_string, 128, p_file))
		{
			p_pos = one_line_string;

			p_pos = GetNextString(p_pos, ',', str);
			rankArr[idx][0] = atoi(str);

			p_pos = GetNextString(p_pos, ',', str);
			rankArr[idx][1] = atoi(str);

			++idx;
		}

		fclose(p_file);
	}
}

void SaveRanking()
{
	int(*rankArr)[2] = GameSystem_GetRankArray();

	for (int i = 0; i < 10; ++i)
	{
		if(rankArr[i][1] >= GameSystem_GetNowWave())
		{
			continue;
		}
		
		for (int j = 8; j >= i; --j)
		{
			rankArr[j + 1][0] = rankArr[j][0];
			rankArr[j + 1][1] = rankArr[j][1];
		}

		rankArr[i][0] = *GameSystem_GetRankNumber();
		rankArr[i][1] = GameSystem_GetNowWave();

		break;
	}

	SaveData();
}

void SaveData()
{
	FILE* p_file = NULL;

	if (0 == fopen_s(&p_file, RANKPATH(Ranking.csv), "wt"))
	{
		int (*rankArr)[2] = GameSystem_GetRankArray();
		int* rankNumber = GameSystem_GetRankNumber();

		fprintf(p_file, "%d,웨이브,등수\n",*rankNumber);
		for (int i = 0; i < 10; i++) 
		{
			fprintf(p_file, "%d,%d,%d\n", rankArr[i][0], rankArr[i][1],i+1);
		}

		*rankNumber += 1;
		fclose(p_file);
	}
}