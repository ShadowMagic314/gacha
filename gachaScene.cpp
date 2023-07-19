#include"gachaScene.h"
#define GOLD_NUM 4
#define PURPLE_NUM 4

void OutGold(struct gachaScene* s)
{
	int m = 1;
	int n = GOLD_NUM;
	int r = rand() % (n - m) + m;
}

void singleGacha(struct gachaScene* s)
{
	int m = 1, n = 60;
	int r = rand() % (n - m + 1) + m;//1~60
	if (r==1) {
		s->videoSingleToGold->play(s->videoSingleToGold);
	}
	else if (1 < r && r <= 6) {
		s->videoSingleToPurple->play(s->videoSingleToPurple);
	}
	else {
		s->videoSingleToBlue->play(s->videoSingleToBlue);
	}
}

void gachaSceneDraw(struct gachaScene* s)
{
	putimage(0, 0, s->bk1);
	putimage(0, 0, s->bk2);

	s->singleBtn->super.draw((sprite*)s->singleBtn);
}

void gachaSceneUpdate(struct gachaScene* s)
{
	if (s->isSingleGacha == true) {
		s->isSingleGacha = false;
		singleGacha(s);
	}
}

void gachaSceneControl(struct gachaScene* s, ExMessage* msg)
{
	if (msg->message == WM_LBUTTONDOWN) {
		if (s->singleBtn->super.x < msg->x && msg->x < s->singleBtn->super.x + s->singleBtn->super.width) {
			if (s->singleBtn->super.y < msg->y && msg->y < s->singleBtn->super.y + s->singleBtn->super.height) {
				s->isSingleGacha = true;
			}
		}
	}
}

bool gachaSceneIsQuit(struct gachaScene* s)
{
	return false;
}

void gachaSceneInit(struct gachaScene* s)
{
	s->super.draw = (void (*)(struct scene*))gachaSceneDraw;
	s->super.update = (void (*)(struct scene*))gachaSceneUpdate;
	s->super.control = (void (*)(struct scene*, ExMessage*))gachaSceneControl;
	s->super.isQuit = (bool (*)(struct scene*))gachaSceneIsQuit;

	s->bk1 = new IMAGE;
	loadimage(s->bk1, "asset/image/bk1.jpg");
	s->bk2 = new IMAGE;
	loadimage(s->bk2, "asset/image/bk2.jpg");

	s->videoSingleToGold = (struct video*)malloc(sizeof(struct video));
	videoInit(s->videoSingleToGold,"asset/video/singleToGold","asset/sounds/sound.wma",177,30);
	s->videoSingleToPurple = (struct video*)malloc(sizeof(struct video));
	videoInit(s->videoSingleToPurple, "asset/video/singleToPurple", "asset/sounds/sound.wma", 177, 30);
	s->videoSingleToBlue = (struct video*)malloc(sizeof(struct video));
	videoInit(s->videoSingleToBlue, "asset/video/singleToBlue", "asset/sounds/sound.wma", 177, 30);

	s->singleBtn = (struct btn*)malloc(sizeof(struct btn));
	btnInit(s->singleBtn);

	s->isSingleGacha = false;
}

void gachaSceneDestroy(struct gachaScene* s)
{
	delete s->bk1;
	delete s->bk2;

	videoDestroy(s->videoSingleToGold);
	videoDestroy(s->videoSingleToPurple);
	videoDestroy(s->videoSingleToBlue);
	btnDestroy(s->singleBtn);
}