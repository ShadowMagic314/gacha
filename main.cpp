#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<easyx.h>
#include"gachaScene.h"
#include"gameData.h"
#include"gameloop.h"
#include<time.h>

int main()
{
	srand((unsigned int)time(NULL));
	initgraph(1920, 1080);
	setbkcolor(WHITE);
	cleardevice();
	//start here
	struct gameData gameData;
	gameDataInit(&gameData);

	struct gachaScene gachascene;
	gachaSceneInit(&gachascene);
	gameLoop((scene*)&gachascene, 1, &gameData);
	gachaSceneDestroy(&gachascene);

	gameDataDestroy(&gameData);
	//end
	exit(0);
	char __FOR_STOP__ = getchar();
	closegraph();
	return 0;
}