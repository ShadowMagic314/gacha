#pragma once
#include"scene.h"
#include"btn.h"
#include"video.h"

struct gachaScene {
	struct scene super;

	IMAGE* bk;
	
	video* videoSingleToGold;
	video* videoSingleToPurple;
	video* videoSingleToBlue;

	btn* singleBtn;
	bool isSingleGacha;
};

void gachaSceneInit(struct gachaScene* s);
void gachaSceneDestroy(struct gachaScene* s);