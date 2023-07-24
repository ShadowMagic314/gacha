#include"btn.h"

void btnDraw(struct btn* b)
{
	putTransparentImage(NULL, b->super.x, b->super.y, b->img);
}

void btnUpdate(struct btn* b)
{

}

void singleBtnInit(struct btn* b)
{
	b->super.draw = (void (*)(struct sprite*))btnDraw;
	b->super.update = (void (*)(struct sprite*))btnUpdate;

	b->super.x = 50;
	b->super.y = 900;
	b->super.width = 532;
	b->super.height = 117;

	b->img = new IMAGE;
	loadimage(b->img, "asset/image/singleBtn.png");
}

void singleBtnDestroy(struct btn* b)
{
	delete b->img;
}

void tenBtnInit(struct btn* b)
{
	b->super.draw = (void (*)(struct sprite*))btnDraw;
	b->super.update = (void (*)(struct sprite*))btnUpdate;

	b->super.x = 1300;
	b->super.y = 900;
	b->super.width = 532;
	b->super.height = 117;

	b->img = new IMAGE;
	loadimage(b->img, "asset/image/tenBtn.png");
}

void tenBtnDestroy(struct btn* b)
{
	delete b->img;
}

void closeBtnInit(struct btn* b)
{
	b->super.draw = (void (*)(struct sprite*))btnDraw;
	b->super.update = (void (*)(struct sprite*))btnUpdate;

	b->super.x = 0;
	b->super.y = 0;
	b->super.width = 101;
	b->super.height = 80;

	b->img = new IMAGE;
	loadimage(b->img, "asset/image/closeBtn.png");
}

void closeBtnDestroy(struct btn* b)
{
	delete b->img;
}

void recordBtnInit(struct btn* b)
{
	b->super.draw = (void (*)(struct sprite*))btnDraw;
	b->super.update = (void (*)(struct sprite*))btnUpdate;

	b->super.x = 1920 - 187 - 50;
	b->super.y = 0;
	b->super.width = 187;
	b->super.height = 80;

	b->img = new IMAGE;
	loadimage(b->img, "asset/image/recordBtn.png");
}

void recordBtnDestroy(struct btn* b)
{
	delete b->img;
}