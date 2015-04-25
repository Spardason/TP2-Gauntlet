#pragma once

#include "Common.h"
#include "Sprite.h"
#include "Rectangle.h"
#include "Resources.h"

class Tile: 
	public Sprite
{

public:
	Tile();
	//CTOR's with parameters to create different types of tile, in this case with or without texture
	Tile(Texture::ID id, int tileWidth, int tileHeight, int tileId, point<int> pos);
	Tile(int tileWidth, int tileHeight, int tileId, point<int> pos);
	~Tile();

	void Update();

	// Tile size getters
	int GetWidth() const { return tileWidth; }
	int GetHeight() const { return tileHeight; }

	// Function to move the tile according to the player
	void MoveTile(Vector2D& direction);

	// ID getter
	int GetId() const { return tileId; }

private:
	// Tile speed
	const int SPEED;

	// Tile Position
	float currentX, currentY;
	
	// Tile parameters
	int tileWidth;
	int tileHeight;
	int tileId;
};

