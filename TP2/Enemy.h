#pragma once

#include "Player.h"

/*
	The class for the main enemy in the game
*/
class Enemy :
	public Sprite
{
public:
	Enemy();
	// Special CTOR with parameters
	Enemy(Player *player, TileManager *m);
	~Enemy();

	void Update();;

	// Function to move the enemy
	void MoveEnemy(const point<float> toGo);

	// Function that seek the player and go to him if possible
	void GoTo(const point<float> toGo);

	// Function that get the next position of the bullet
	point<float> GetNextPos(const Vector2D &direction);

	// Function that check if the enemy collides and with what
	bool Collides(const Tile *tileToCheck);

private:
	// Game references
	TileManager *manager;
	Player *player;

	// Direction
	Vector2D direction;

	//Enemies position
	float currentX, currentY;

	// Enemy speed
	const int SPEED;
};

