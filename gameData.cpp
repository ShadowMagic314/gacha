#include"gameData.h"

void gameDataLoad(struct gameData* gd)//将来在这里写读档函数
{

}

void gameDataSave(struct gameData* gd)//将来在这里写存档函数
{

}

void gameDataInit(struct gameData* gd)
{
	gd->load = (void (*)(struct gemeData*))gameDataLoad;
	gd->save = (void (*)(struct gameData*))gameDataSave;

	characterDatabaseInit(&gd->characterDB);

	gd->gachaTimes = 0;

	gd->ownFiveStarCharacters = (bool*)malloc(sizeof(bool) * gd->characterDB.fiveStarCharacterNum);
	if (gd->ownFiveStarCharacters == NULL) return;
	for (int i = 0; i < gd->characterDB.fiveStarCharacterNum; i++) {
		gd->ownFiveStarCharacters[i] = false;
	}
	gd->ownFourStarCharacters = (bool*)malloc(sizeof(bool) * gd->characterDB.fourStarCharacterNum);
	if (gd->ownFourStarCharacters == NULL) return;
	for (int i = 0; i < gd->characterDB.fourStarCharacterNum; i++) {
		gd->ownFourStarCharacters[i] = false;
	}

	gd->exp = 0;
}

void gameDataDestroy(struct gameData* gd)
{
	characterDatabaseDestroy(&gd->characterDB);
	free(gd->ownFiveStarCharacters);
	free(gd->ownFourStarCharacters);
}