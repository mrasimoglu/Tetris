#pragma once

#include <wincodec.h>
#include "Graphics.h"
#include "Block.h"

class SpriteSheet
{
	Graphics* gfx;
	ID2D1Bitmap* bmp;
public:
	SpriteSheet(wchar_t* filename, Graphics* gfx);
	~SpriteSheet();

	void DrawArea();
	void DrawBlocks(int, int, int);
	void DrawCurrentBlock(int, int, int, int, int);

	void DrawNextBlocks(int, int);
	void DrawNextTile();

	void DrawHoldingTile();
	void DrawHoldingBlock(int);
};