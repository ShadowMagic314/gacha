#pragma once
#include"vector.h"

//包含的存储库
#include"characterDatabase.h"

struct gameData {
	void (*load)(struct gemeData*);
	void (*save)(struct gameData*);

	//数据库
	struct characterDatabase characterDB;

	//正文
	int gachaTimes;
	bool* ownFiveStarCharacters;
	bool* ownFourStarCharacters;
	int exp;
};

void gameDataInit(struct gameData*gd);
void gameDataDestroy(struct gameData* gd);