#pragma once
#include"vector.h"

//°üº¬µÄ´æ´¢¿â
#include"characterDatabase.h"

struct gameData {
	void (*load)(struct gemeData*);
	void (*save)(struct gameData*);

	struct characterDatabase characterDB;
};

void gameDataInit(struct gameData*gd);
void gameDataDestroy(struct gameData* gd);