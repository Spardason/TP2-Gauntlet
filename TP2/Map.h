#pragma once

#include "Sprite.h"
#include "Vector.h"
#include "Resources.h"

class Map :
	public Sprite
{
public:
	Map();
	~Map();

	void Update();

	// Function to move the map accordingly to the player movement
	void MoveMap(Vector2D& direction);

private:
	// Map position
	int currentX, currentY;

	// Map speed
	const int SPEED;
};
