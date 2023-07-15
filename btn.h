#pragma once
#include"sprite.h"
#include<easyx.h>
#include"image.h"

struct btn {
	struct sprite super;

	IMAGE* img;
	IMAGE* mask;
};

void btnInit(struct btn*);
void btnDestroy(struct btn*);