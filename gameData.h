#pragma once
#include"vector.h"

struct gameData {
	void (*load)(struct gemeData*);
	void (*save)(struct gameData*);

	vector vecCharacters;
};

void gameDataInit(struct gameData*gd);
void gameDataDestroy(struct gameData* gd);