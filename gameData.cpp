#include"gameData.h"

void gameDataLoad(struct gameData* gd)//����������д��������
{

}

void gameDataSave(struct gameData* gd)//����������д�浵����
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