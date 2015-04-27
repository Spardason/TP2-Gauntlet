#pragma once

#include "Common.h"
#include "Animation.h"
#include "Resources.h"
#include "Vector.h"
#include "TileManager.h"
/*
	This is the class for the player projectile
*/
class Bullet :
	public Sprite
{
public:
	Bullet();
	~Bullet();

	// Init function for when created from the pool
	void Init(float currentX, float currentY, Vector2D &direction);

	// Function to remove the bullet from screen before free the pool instance
	void OnClear();

	// Function to move the bullet
	void MoveBullet();

	// Function to get the next position 
	point<float> Bullet::GetNextPos();

	// Function that check if the bullet collides with a wall
	bool Collides(const Tile *tileToCheck);

private:
	// Speed of the bullet
	const int SPEED;

	// Direction of the bullet
	Vector2D direction;

	// Position of the bullet
	float currentX, currentY;

	// Things for animation
	const int IDLE_NB_FRAME() { return 1; }
	const point<int> FRAME_SIZE() { return{ 16, 16 }; };
	const point<int> TOP_START_SRC() { return{ 0, 0 }; };
};

