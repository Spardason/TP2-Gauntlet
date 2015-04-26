#pragma once

#include "Common.h"
#include "Animation.h"
#include "Resources.h"
#include "Vector.h"
#include "TileManager.h"

class Bullet :
	public Sprite
{
public:
	Bullet();
	~Bullet();

	void Update();

	void Init(float currentX, float currentY, Vector2D &direction);
	void MoveBullet();

	// Function to get the next position 
	point<float> Bullet::GetNextPos();

	bool Collides(Tile *tileToCheck);

private:
	// Speed of the bullet
	const int SPEED;

	Vector2D direction;

	// Position of the bullet
	float currentX, currentY;

	// Things for animation
	const int IDLE_NB_FRAME() { return 1; }
	const point<int> FRAME_SIZE() { return{ 16, 16 }; };
	const point<int> TOP_START_SRC() { return{ 0, 0 }; };
};

