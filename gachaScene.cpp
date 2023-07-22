#include"gachaScene.h"

void outGold(struct gachaScene* s, struct gameData* gd)
{
	s->videoSingleToGold->play(s->videoSingleToGold);

	int m = 0;
	int n = gd->characterDB.fiveStarCharacterNum;
	int r = rand() % (n - m) + m;//假如有四个角色，这里r就是0、1、2、3
	putimage(0, 0, s->bkout);
	putTransparentImage(NULL, 0, 0, (IMAGE*)gd->characterDB.vecFiveStarCharacterMask.get(&gd->characterDB.vecFiveStarCharacterMask, r));
	FlushBatchDraw();
	Sleep(1000);
	putTransparentImage(NULL, 0, 0, (IMAGE*)gd->characterDB.vecFiveStarCharacterImg.get(&gd->characterDB.vecFiveStarCharacterImg, r));

	settextcolor(WHITE);
	settextstyle(100, 0, "微软雅黑");
	setbkmode(TRANSPARENT);
	outtextxy(200, 700, gd->characterDB.fiveStarCharacterName[r]);
	FlushBatchDraw();
	Sleep(1000);
}

void outPurple(struct gachaScene* s, struct gameData* gd)
{
	s->videoSingleToPurple->play(s->videoSingleToPurple);

	int m = 0;
	int n = gd->characterDB.fourStarCharacterNum;
	int r = rand() % (n - m) + m;//假如有四个角色，这里r就是0、1、2、3
	putimage(0, 0, s->bkout);
	putTransparentImage(NULL, 0, 0, (IMAGE*)gd->characterDB.vecFourStarCharacterMask.get(&gd->characterDB.vecFourStarCharacterMask, r));
	FlushBatchDraw();
	Sleep(1000);
	putTransparentImage(NULL, 0, 0, (IMAGE*)gd->characterDB.vecFourStarCharacterImg.get(&gd->characterDB.vecFourStarCharacterImg, r));
	FlushBatchDraw();
	Sleep(1000);
}

void outBlue(struct gachaScene* s, struct gameData* gd)
{
	s->videoSingleToBlue->play(s->videoSingleToBlue);

	int m = 1;
	int n = 10;
	int r = rand() % (n - m) + m;//经验值从1到10

	putimage(0, 0, s->bkout);
	IMAGE* imgExp = new IMAGE;
	loadimage(imgExp, "asset/image/exp.png");
	putTransparentImage(NULL, 0, 0, imgExp);

	settextcolor(WHITE);
	settextstyle(300, 0, "微软雅黑");
	setbkmode(TRANSPARENT);
	char info[50];
	sprintf(info, "%dEXP", r);
	outtextxy(700, 700, info);
	FlushBatchDraw();

	Sleep(1000);
}

void singleGacha(struct gachaScene* s, struct gameData* gd)
{
	int m = 1, n = 60;
	int r = rand() % (n - m + 1) + m;//1~60
//	if (r==1) {
		outGold(s, gd);
//	}
//	else if (1 < r && r <= 6) {
//		outPurple(s, gd);
//	}
//	else {
//		outBlue(s, gd);
//	}
}

void gachaSceneDraw(struct gachaScene* s, struct gameData* gd)
{
	putimage(0, 0, s->bk1);
	putimage(0, 0, s->bk2);

	s->singleBtn->super.draw((sprite*)s->singleBtn);
}

void gachaSceneUpdate(struct gachaScene* s, struct gameData* gd)
{
	if (s->isSingleGacha == true) {
		s->isSingleGacha = false;
		singleGacha(s, gd);
	}
}

void gachaSceneControl(struct gachaScene* s, ExMessage* msg, struct gameData* gd)
{
	if (msg->message == WM_LBUTTONDOWN) {
		if (s->singleBtn->super.x < msg->x && msg->x < s->singleBtn->super.x + s->singleBtn->super.width) {
			if (s->singleBtn->super.y < msg->y && msg->y < s->singleBtn->super.y + s->singleBtn->super.height) {
				s->isSingleGacha = true;
			}
		}
	}
}

bool gachaSceneIsQuit(struct gachaScene* s, struct gameData* gd)
{
	return false;
}

void gachaSceneInit(struct gachaScene* s)
{
	s->super.draw = (void (*)(struct scene*, struct gameData* gd))gachaSceneDraw;
	s->super.update = (void (*)(struct scene*, struct gameData* gd))gachaSceneUpdate;
	s->super.control = (void (*)(struct scene*, ExMessage*, struct gameData* gd))gachaSceneControl;
	s->super.isQuit = (bool (*)(struct scene*, struct gameData* gd))gachaSceneIsQuit;

	s->bk1 = new IMAGE;
	loadimage(s->bk1, "asset/image/bk1.jpg");
	s->bk2 = new IMAGE;
	loadimage(s->bk2, "asset/image/bk2.jpg");
	s->bkout = new IMAGE;
	loadimage(s->bkout, "asset/image/bkout.jpg");

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
	delete s->bkout;

	videoDestroy(s->videoSingleToGold);
	videoDestroy(s->videoSingleToPurple);
	videoDestroy(s->videoSingleToBlue);
	btnDestroy(s->singleBtn);
}