#pragma once

#include "GameLevel.h"

class GameController
{
	GameController();
	static GameLevel* currentLevel;
public:
	static bool Loading;

	static void Init();

	static void LoadInitialLevel(GameLevel* lev);
	static void SwitchLevel(GameLevel* lev);

	static void Update();
	static void Render();
};