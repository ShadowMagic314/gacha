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

	characterDatabaseInit(&gd->cdb);
}

void gameDataDestroy(struct gameData* gd)
{
	characterDatabaseDestroy(&gd->cdb);
}