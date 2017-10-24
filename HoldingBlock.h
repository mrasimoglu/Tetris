#pragma once

#include "CurrentBlock.h"

class HoldingBlock
{
	SpriteSheet* blockSprite;
	SpriteSheet* tileSprite;
public:
	int holdingType;

	HoldingBlock(Graphics*);
	~HoldingBlock();

	void DrawHoldingBlock();
	void DrawHoldingTile();
};

