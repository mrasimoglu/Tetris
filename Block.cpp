#include "Block.h"



Block::Block(int type)
{
	if (type == 0)
	{
		int blockTemp[4][4] = {
			{ 0,0,0,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 },
			{ 0,0,0,0 }
		};

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				block[i][j] = blockTemp[i][j];
	}
	else if (type == 1)
	{
		int blockTemp[4][4] = {
			{ 0,1,0,0 },
			{ 0,1,0,0 },
			{ 0,1,1,0 },
			{ 0,0,0,0 }
		};

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				block[i][j] = blockTemp[i][j];
	}
	else if (type == 2)
	{
		int blockTemp[4][4] = {
			{ 0,0,2,0 },
			{ 0,0,2,0 },
			{ 0,2,2,0 },
			{ 0,0,0,0 }
		};

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				block[i][j] = blockTemp[i][j];
	}
	else if (type == 3)
	{
		int blockTemp[4][4] = {
			{ 0,0,0,0 },
			{ 0,3,3,0 },
			{ 3,3,0,0 },
			{ 0,0,0,0 }
		};

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				block[i][j] = blockTemp[i][j];
	}
	else if (type == 4)
	{
		int blockTemp[4][4] = {
			{ 0,0,0,0 },
			{ 0,4,4,0 },
			{ 0,0,4,4 },
			{ 0,0,0,0 }
		};

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				block[i][j] = blockTemp[i][j];
	}
	else if (type == 5)
	{
		int blockTemp[4][4] = {
			{ 0,5,0,0 },
			{ 0,5,0,0 },
			{ 0,5,0,0 },
			{ 0,5,0,0 }
		};

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				block[i][j] = blockTemp[i][j];
	}
	else if (type == 6)
	{
		int blockTemp[4][4] = {
			{ 0,0,0,0 },
			{ 0,6,0,0 },
			{ 6,6,6,0 },
			{ 0,0,0,0 }
		};

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				block[i][j] = blockTemp[i][j];
	}
	else if (type == 7)
	{
		int blockTemp[4][4] = {
			{ 0,0,0,0 },
			{ 0,7,7,0 },
			{ 0,7,7,0 },
			{ 0,0,0,0 }
		};

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				block[i][j] = blockTemp[i][j];
	}
}


Block::~Block()
{
}
