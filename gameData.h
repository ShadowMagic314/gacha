#pragma once
#include"vector.h"

//�����Ĵ洢��
#include"characterDatabase.h"

struct gameData {
	void (*load)(struct gemeData*);
	void (*save)(struct gameData*);

	//���ݿ�
	struct characterDatabase characterDB;

	//����
	int gachaTimes;
	bool* ownFiveStarCharacters;
	bool* ownFourStarCharacters;
	int exp;
};

void gameDataInit(struct gameData*gd);
void gameDataDestroy(struct gameData* gd);