#pragma once

#include "GameLevel.h"
#include "Area.h"
#include "Block.h"
#include "CurrentBlock.h"
#include "NextBlock.h"
#include "HoldingBlock.h"

#include <stdlib.h>
#include <conio.h>
#include <time.h>

class Level1 : public GameLevel
{
	SpriteSheet* sprites;
	Area* area;
	Block* block;
	CurrentBlock* cBlock;
	NextBlock* nBlock;
	HoldingBlock* hBlock;

	int cX, cY;
	int timer;

	bool rightToSwitch;

	bool newBlock;

	bool kbFlag_SPACE, kbFlag_A;

	int wait;
public:
	void Load() override;
	void Unload() override;
	void Update() override;
	void Render() override;
};