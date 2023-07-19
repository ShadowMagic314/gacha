#include"btn.h"

void btnDraw(struct btn* b)
{
	putTransparentImage_mask(b->super.x, b->super.y, b->mask, b->img);
}

void btnUpdate(struct btn* b)
{

}

void btnInit(struct btn* b)
{
	b->super.draw = (void (*)(struct sprite*))btnDraw;
	b->super.update = (void (*)(struct sprite*))btnUpdate;

	b->super.x = 50;
	b->super.y = 900;
	b->super.width = 532;
	b->super.height = 117;

	b->img = new IMAGE;
	b->mask = new IMAGE;
	loadimage(b->img, "asset/image/singleBtn.png");
	loadimage(b->mask, "asset/image/singleBtn_mask.png");
}

void btnDestroy(struct btn* b)
{
	delete b->img;
	delete b->mask;
}