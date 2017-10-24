#include "HoldingBlock.h"



HoldingBlock::HoldingBlock(Graphics* gfx)
{
	blockSprite = new SpriteSheet(L"color1.png", gfx);
	tileSprite = new SpriteSheet(L"tile.png", gfx);

	holdingType = 0;
}

void HoldingBlock::DrawHoldingTile()
{
	tileSprite->DrawHoldingTile();
}

void HoldingBlock::DrawHoldingBlock()
{
	blockSprite->DrawHoldingBlock(holdingType);
}


HoldingBlock::~HoldingBlock()
{
}
