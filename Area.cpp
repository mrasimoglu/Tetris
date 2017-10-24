#include "Area.h"


Area::Area(Graphics* gfx)
{
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 10; j++)
			this->area[i][j] = 0;

	areaSprite = new SpriteSheet(L"Tile.png", gfx);
	blockSprite = new SpriteSheet(L"color1.png", gfx);
}


void Area::DrawArea()
{
	areaSprite->DrawArea();

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 10; j++)
			if (area[i][j] != 0)
				blockSprite->DrawBlocks(j, i, area[i][j]);
}


void Area::insertBlock(CurrentBlock* block, int x, int y)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if(block->block[3-i][j] != 0)
				this->area[y - i][x + j] = block->block[3-i][j];
}


void Area::checkLine()
{
	int counter = 0;

	for (int i = 19; i > -1; i--)
	{
		bool tf = true;
		int j = 0;

		while (tf && j < 10)
		{
			if (this->area[i][j] == 0)
				tf = false;
			j++;
		}

		if (tf)
		{
			for (int j = 0; j < 10; j++)
			{
				this->area[i][j] += 7;
			}
		}
	}

}

void Area::destroyCompletedLines()
{
	for (int i = 19; i > -1; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			if (area[i][j] > 7)
			{
				for (int k = i ; k > 0; k--)
				{
					area[k][j] = area[k - 1][j];
				}
				j--;
			}
		}
	}
}


Area::~Area()
{
}
