#pragma once

#include "SpriteSheet.h"
#include "Graphics.h"
#include "Block.h"
#include "CurrentBlock.h"

extern class CurrentBlock;

class Area
{
	SpriteSheet* areaSprite;
	SpriteSheet* blockSprite;
public:
	int area[20][10];

	Area(Graphics*);
	~Area();

	void DrawArea();
	void insertBlock(CurrentBlock*, int, int);

	void checkLine();
	void destroyCompletedLines();
};

