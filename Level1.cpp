#include "GameController.h"
#include "Level1.h"

void Level1::Load()
{
	srand(time(NULL));

	sprites = new SpriteSheet(L"Tile.png", gfx);
	area = new Area(gfx);
	cBlock = new CurrentBlock(gfx);
	nBlock = new NextBlock(gfx);
	hBlock = new HoldingBlock(gfx);
	
	newBlock = true;

	rightToSwitch = true;

	kbFlag_SPACE = false;
	kbFlag_A = false;
}

void Level1::Unload()
{
	delete sprites;
}

void Level1::Update()
{ 
	if (wait < 0)
	{
		if (newBlock)
		{
			area->destroyCompletedLines();
			cX = 3; cY = 0;
			timer = 0;
			block = new Block(nBlock->next[0]);
			nBlock->createNext();
			cBlock->insertBlock(block, cX, cY);
			newBlock = false;
		}
		else
		{
			if(timer % 5 == 0)
			{
				if (GetAsyncKeyState(VK_LEFT))
					if (cBlock->checkLeftCollision(cX, cY, area))
						cX--;
					else;
				else if (GetAsyncKeyState(VK_RIGHT))
					if (cBlock->checkRightCollision(cX, cY, area))
						cX++;
					else;
			}
			if (GetAsyncKeyState(VK_DOWN))
					if (cBlock->checkBottomCollision(cX, cY, area))
						cY++;
					else; 
			
			else if (GetAsyncKeyState(VK_SPACE) && !kbFlag_SPACE)
			{
				kbFlag_SPACE = true;
				if (cBlock->checkTurnBlock(cX, cY, area))
					cBlock->turnBlock();
				else;
			}
			else if (GetAsyncKeyState('A') && !kbFlag_A && rightToSwitch && hBlock->holdingType != cBlock->type)
			{
				kbFlag_A = true;
				rightToSwitch = false;
				if (hBlock->holdingType == 0)
				{
					hBlock->holdingType = cBlock->type;
					newBlock = true;
				}
				else
				{
					cX = 3; cY = 0;
					timer = 0;
					block = new Block(hBlock->holdingType);
					hBlock->holdingType = cBlock->type;
					cBlock->insertBlock(block, cX, cY);
					newBlock = false;
				}
				
			}

			if (!GetAsyncKeyState(VK_SPACE))
				kbFlag_SPACE = false;
			if (!GetAsyncKeyState('A'))
				kbFlag_A = false;

			

			timer++;
			if (timer == 30)
				if (cBlock->checkBottomCollision(cX, cY, area))
				{
					cY++;
					timer = 0;
				}
				else
				{
					newBlock = true;
					area->insertBlock(cBlock, cX, cY);
					area->checkLine();
					wait = 20;
					rightToSwitch = true;
					cBlock->type = 0;
				}
		}
	}
	wait--;
}


void Level1::Render()
{
	gfx->ClearScreen(1, 1, 1);

	area->DrawArea();

	cBlock->drawBlock(cX, cY);

	nBlock->drawNextTile();
	nBlock->drawNextBlock();

	hBlock->DrawHoldingTile();
	hBlock->DrawHoldingBlock();
}