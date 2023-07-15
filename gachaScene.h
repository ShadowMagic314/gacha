#pragma once
#include"scene.h"
#include"btn.h"
#include"video.h"

struct gachaScene {
	struct scene super;

	IMAGE* bk1;
	IMAGE* bk2;
	
	video* videoSingleToGold;
	video* videoSingleToPurple;
	video* videoSingleToBlue;

	btn* singleBtn;
	bool isSingleGacha;
};

void gachaSceneInit(struct gachaScene* s);
void gachaSceneDestroy(struct gachaScene* s);