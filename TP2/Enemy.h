#pragma once

#include "Player.h"

class Enemy :
	public Sprite
{
public:
	Enemy();
	Enemy(Player *player, TileManager *m);
	~Enemy();

	void Update();
	void Start();

	void Init(float currentX, float currentY, Player *player);

	void MoveEnemy(point<float> toGo);
	// Function that seek the player and go to him if possible
	void GoTo(point<float> toGo);

	point<float> GetNextPos(Vector2D &direction);

private:
	TileManager *manager;
	// Reference to player, to go to him
	Player *player;

	bool Collides(Tile *tileToCheck);

	Vector2D direction;

	// HP of the monsters
	int hp;

	//Enemies position
	float currentX, currentY;

	// Enemy speed
	const int SPEED;
};

