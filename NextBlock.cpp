#include "NextBlock.h"



NextBlock::NextBlock(Graphics* gfx)
{
	srand(time(NULL));
	next[0] = (rand() % 7) + 1;
	next[1] = (rand() % 7) + 1;

	blockSprite = new SpriteSheet(L"color1.png", gfx);
	tileSprite = new SpriteSheet(L"tile.png", gfx);
}

void NextBlock::createNext()
{
	next[0] = next[1];
	next[1] = (rand() % 7) + 1;
}

void NextBlock::drawNextTile()
{
	for (int i = 0; i < 2; i++)
		tileSprite->DrawNextTile();
}

void NextBlock::drawNextBlock()
{
	for (int i = 0; i < 2; i++)
		blockSprite->DrawNextBlocks(i, next[i] - 1);
}


NextBlock::~NextBlock()
{
}
