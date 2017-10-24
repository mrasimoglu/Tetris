#include "SpriteSheet.h"

#pragma comment(lib, "windowscodecs.lib")

SpriteSheet::SpriteSheet(wchar_t* filename, Graphics* gfx)
{
	//Init
	this->gfx = gfx;
	bmp = NULL;
	HRESULT hr;

	//Create a WIC factory
	IWICImagingFactory* wicFactory = NULL;
	hr = CoCreateInstance(CLSID_WICImagingFactory1, NULL, CLSCTX_INPROC_SERVER, IID_IWICImagingFactory, (LPVOID*)&wicFactory);

	//Create a decoder
	IWICBitmapDecoder* wicDecoder = NULL;
	hr = wicFactory->CreateDecoderFromFilename(filename, NULL, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &wicDecoder);

	//Read a frame from the image
	IWICBitmapFrameDecode* wicFrame = NULL;
	hr = wicDecoder->GetFrame(0, &wicFrame);

	//Create converter
	IWICFormatConverter* wicConverter = NULL;
	hr = wicFactory->CreateFormatConverter(&wicConverter);

	//Setup the converter
	hr = wicConverter->Initialize(wicFrame, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.0, WICBitmapPaletteTypeCustom);

	//Use the converter to create an D2D1Bitmap
	gfx->GetRenderTarget()->CreateBitmapFromWicBitmap(wicConverter, NULL, &bmp);

	if (wicFactory) wicFactory->Release();
	if (wicDecoder) wicDecoder->Release();
	if (wicConverter) wicConverter->Release();
	if (wicFrame) wicFrame->Release();
}


void SpriteSheet::DrawArea()
{
	gfx->GetRenderTarget()->DrawBitmap(
		bmp,
		D2D1::RectF(300, 100, 621, 721),
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF(0, 0, 321, 621)
	);
}

void SpriteSheet::DrawBlocks(int x, int y, int type)
{
	int a, b;
	type--;

	a = x * 32 + 300;
	b = y * 31 + 100;

	gfx->GetRenderTarget()->DrawBitmap(
		bmp,
		D2D1::RectF(a + 1, b + 1, a + 32, b + 31),
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF(30 * type, 0, 30 + 30 * type, 30)
	);
}

void SpriteSheet::DrawCurrentBlock(int x, int y, int j, int i, int type)
{
	int a, b;
	type--;

	a = x * 32 + j * 32 + 300;
	b = y * 31 + i * 31 + 100;

	gfx->GetRenderTarget()->DrawBitmap(
		bmp,
		D2D1::RectF(a + 1, b + 1, a + 32, b + 31),
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF(30 * type, 0, 30 + 30 * type, 30)
	);
}

void SpriteSheet::DrawNextTile()
{
	for (int i = 0; i < 2; i++)
	{
		gfx->GetRenderTarget()->DrawBitmap(
			bmp,
			D2D1::RectF(700, 100 + i*150, 825, 225 + i*150),
			1.0f,
			D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
			D2D1::RectF(0, 0, 125, 125)
		);
	}
}

void SpriteSheet::DrawNextBlocks(int c, int type)
{
	Block* block;
	block = new Block(type + 1);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block->block[j][i] != 0)
			{
				gfx->GetRenderTarget()->DrawBitmap(
					bmp,
					D2D1::RectF(700 + i*30 + i + 1, 100 + j*30 + 150*c + j + 1, 730 + i * 30 + i + 1, 130 + j * 30 + 150*c + j + 1),
					1.0f,
					D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
					D2D1::RectF(30 * type, 0, 30 + 30 * type, 30)
				);
			}
		}
	}	
}

void SpriteSheet::DrawHoldingTile()
{
	gfx->GetRenderTarget()->DrawBitmap(
		bmp,
		D2D1::RectF(100, 100, 225, 225),
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF(0, 0, 125, 125)
	);
}

void SpriteSheet::DrawHoldingBlock(int type)
{
	Block* block;
	block = new Block(type);
	type--;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block->block[j][i] != 0)
			{
				gfx->GetRenderTarget()->DrawBitmap(
					bmp,
					D2D1::RectF(100 + i * 30 + i + 1, 100 + j * 30 + j + 1, 130 + i * 30 + i + 1, 130 + j * 30 + j + 1),
					1.0f,
					D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
					D2D1::RectF(30 * type, 0, 30 + 30 * type, 30)
				);
			}
		}
	}
}


SpriteSheet::~SpriteSheet()
{
	if (bmp) bmp->Release();
}