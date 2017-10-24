#pragma once

#include "Block.h"
#include "SpriteSheet.h"
#include "Area.h"

extern class Area;

class CurrentBlock
{
	SpriteSheet* blockSprite;
	int tempBlock[4][4];
	int temp;
public:
	int block[4][4];
	CurrentBlock(Graphics*);
	~CurrentBlock();

	int type;

	void insertBlock(Block*, int, int);
	void drawBlock(int, int);

	bool checkLeftCollision(int, int, Area*);
	bool checkRightCollision(int, int, Area*);
	bool checkBottomCollision(int, int, Area*);

	void turnBlock();
	bool checkTurnBlock(int, int, Area*);
};

