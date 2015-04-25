#pragma once

#include "Common.h"
#include "Player.h"

class Bullet :
	public Animation
{
public:
	Bullet();
	// CTOR with parameters, wich are the starting position
	Bullet(point<int> pos);
	~Bullet();

	void Update();

private:
	// Speed of the bullet
	const int SPEED;

	// Position of the bullet
	int currentX, currentY;

	// Things for animation
	const int IDLE_NB_FRAME() { return 1; }
	const point<int> FRAME_SIZE() { return{ 16, 16 }; };
	const point<int> TOP_START_SRC() { return{ 0, 0 }; };
};

