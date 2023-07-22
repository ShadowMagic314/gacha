#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"scene.h"
#include"btn.h"
#include"video.h"
#include"image.h"
#include"gameData.h"

struct gachaScene {
	struct scene super;

	IMAGE* bk1;
	IMAGE* bk2;
	IMAGE* bkout;

	video* videoSingleToGold;
	video* videoSingleToPurple;
	video* videoSingleToBlue;

	btn* singleBtn;
	bool isSingleGacha;
};

void gachaSceneInit(struct gachaScene* s);
void gachaSceneDestroy(struct gachaScene* s);