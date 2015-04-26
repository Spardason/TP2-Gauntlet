#pragma once

// Includes all the stuffs for the game to work

#include "Sprite.h"
#include "Player.h"
#include "Map.h"
#include "Enemy.h"
#include "Chest.h"
#include "Tile.h"
#include "TileManager.h"
#include "Resources.h"
#include "Common.h"
#include "Game.h"
#include "Score.h"
#include "Pool.h"
#include "Bullet.h"
#include "Audio.h"

class Game :
	public Component
{
public:
	Game();
	~Game();

private:
	TileManager *manager;
	Player *player;
	Score *score;
	Map *mapSprite;
};

