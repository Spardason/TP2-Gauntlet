#pragma once

// Includes all the stuffs for the game to work
#include "Sprite.h"
#include "Player.h"
#include "Map.h"
#include "Enemy.h"
#include "Tile.h"
#include "TileManager.h"
#include "Resources.h"
#include "Common.h"
#include "Game.h"
#include "Score.h"
#include "Pool.h"
#include "Bullet.h"
#include "Theme.h"
#include "SplashScreen.h"
#include "DeathScreen.h"

/*
	This the Game class, it contains every game objects and includes necessary for ti to work
*/

class Game :
	public Component
{
public:
	Game();
	~Game();

	void Init();
	void Update();

private:
	bool gameOver;

	// All the game objects
	DeathScreen *deathScreen;
	Enemy *enemyGhost;
	SplashScreen *splashScreen;
	Theme *theme;
	TileManager *manager;
	Player *player;
	Score *score;
	Map *mapSprite;
};

