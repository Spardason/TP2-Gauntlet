#pragma once

#include "Sprite.h"
#include "Vector.h"
#include "Resources.h"

/*
	This is the class for the background map sprite
*/

class Map :
	public Sprite
{
public:
	Map();
	~Map();

	// Function to move the map accordingly to the player movement
	void MoveMap(Vector2D& direction);

private:
	// Map position
	float currentX, currentY;

	// Map speed
	const int SPEED;
};

