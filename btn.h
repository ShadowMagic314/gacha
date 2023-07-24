#pragma once
#include"sprite.h"
#include<easyx.h>
#include"image.h"

struct btn {
	struct sprite super;

	IMAGE* img;
};

void singleBtnInit(struct btn*);
void singleBtnDestroy(struct btn*);

void tenBtnInit(struct btn*);
void tenBtnDestroy(struct btn*);

void closeBtnInit(struct btn*);
void closeBtnDestroy(struct btn*);

void recordBtnInit(struct btn*);
void recordBtnDestroy(struct btn*);