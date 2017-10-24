#pragma once

#include "SpriteSheet.h"
#include "Graphics.h"

#include <stdlib.h>
#include <time.h>

class NextBlock
{
	SpriteSheet* blockSprite;
	SpriteSheet* tileSprite;
public:
	int next[2];

	NextBlock(Graphics*);
	~NextBlock();

	void createNext();
	void drawNextBlock();
	void drawNextTile();
};

