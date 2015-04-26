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
	void Start();

	// Function to move the map accordingly to the player movement
	void MoveMap(Vector2D& direction);

private:
	// Map position
	float currentX, currentY;

	const int MAX_WIDTH;
	const int MAX_HEIGHT;

	// Map speed
	const int SPEED;
};

