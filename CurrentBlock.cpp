#include "CurrentBlock.h"



CurrentBlock::CurrentBlock(Graphics* gfx)
{
	blockSprite = new SpriteSheet(L"color1.png", gfx);
}


void CurrentBlock::insertBlock(Block* block, int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->block[i][j] = block->block[i][j];
			if (block->block[i][j] != 0)
				this->type = block->block[i][j];
		}
	}
}

void CurrentBlock::drawBlock(int x, int y)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (this->block[i][j] != 0)
				if (y - (3 - i)> -1)
					if(this->type != 0)
						blockSprite->DrawCurrentBlock(x, y - 3, j, i, this->block[i][j]);
}


bool CurrentBlock::checkLeftCollision(int x, int y, Area* area)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (this->block[j][i] != 0)
			{
				if (area->area[y - 3 + j][x + i - 1] != 0)
					if (y > 2)
						return false;
					else;
					if (x + i - 1 < 0)
						return false;
			}
		}

	return true;
}

bool CurrentBlock::checkRightCollision(int x, int y, Area* area)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (this->block[j][3 - i] != 0)
			{
				if (area->area[y - 3 + j][x + 4 - i] != 0)
					if (y > 2)
						return false;
					else;
					if (x + 4 - i > 9)
						return false;
			}
		}

	return true;
}

bool CurrentBlock::checkBottomCollision(int x, int y, Area* area)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (this->block[3 - i][j] != 0)
					if (area->area[y - i + 1][x + j] != 0)
						if(y > 2)
							return false;
						else;
					else if (y - i + 1 > 19)
						return false;

	return true;
}


bool CurrentBlock::checkTurnBlock(int x, int y, Area* area)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tempBlock[j][i] = this->block[i][j];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			temp = tempBlock[i][j];
			tempBlock[i][j] = tempBlock[i][3 - j];
			tempBlock[i][3 - j] = temp;
		}
	}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (tempBlock[j][i] != 0)
					if (area->area[y - 3 + j][x + i] != 0)
						return false;
					else if (y - 3 + j > 19)
						return false;
					else if (x + i < 0 || x + i > 9)
						return false;
					else;


	return true;
}


void CurrentBlock::turnBlock()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tempBlock[j][i] = this->block[i][j];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			temp = tempBlock[i][j];
			tempBlock[i][j] = tempBlock[i][3 - j];
			tempBlock[i][3 - j] = temp;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->block[i][j] = tempBlock[i][j];
		}
	}
}


CurrentBlock::~CurrentBlock()
{
}
