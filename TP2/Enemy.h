#pragma once

#include "Player.h"

class Enemy :
	public Sprite
{
public:
	Enemy();
	Enemy(Player *player);
	~Enemy();

	void Update();

	// Function that seek the player and go to him if possible
	void GoTo(point<int> toGo);

private:
	// Reference to player, to go to him
	Player *player;

	// HP of the monsters
	int hp;

	//Enemies position
	int currentX, currentY;

	// Enemy speed
	const int SPEED = 50;
};

