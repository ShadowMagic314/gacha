#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"vector.h"
#include<easyx.h>
#include<stdio.h>
#define FIVESTARCHARACTERNUM 4
#define FOURSTARCHARACTERNUM 4

//该模块仅仅作为存储库供查找，故没有方法，只有init和destroy

struct characterDatabase {
	const char* fiveStarCharacterName[FIVESTARCHARACTERNUM] = { "可莉","砂糖","早柚","钟离", };
	const char* fourStarCharacterName[FOURSTARCHARACTERNUM] = { "安柏","迪卢克","七七","香菱", };

	const int fiveStarCharacterNum = FIVESTARCHARACTERNUM;
	const int fourStarCharacterNum = FOURSTARCHARACTERNUM;

	vector vecFiveStarCharacterImg;
	vector vecFiveStarCharacterMask;
	vector vecFourStarCharacterImg;
	vector vecFourStarCharacterMask;
};

void characterDatabaseInit(struct characterDatabase*cd);
void characterDatabaseDestroy(struct characterDatabase*cd);