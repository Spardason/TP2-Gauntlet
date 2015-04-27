#pragma once

#include "Common.h"
#include "Sprite.h"
#include "Rectangle.h"
#include "Resources.h"

/*
	This is the class for all tiles in the game, visibl or not.
*/

class Tile: 
	public Sprite
{

public:
	Tile();
	//CTOR's with parameters to create different types of tile, in this case with or without texture
	Tile(Texture::ID id, int tileWidth, int tileHeight, int tileId, point<int> pos);
	Tile(int tileWidth, int tileHeight, int tileId, point<int> pos);
	~Tile();

	// Tile size getters
	int GetWidth() const { return tileWidth; }
	int GetHeight() const { return tileHeight; }

	// ID getter
	int GetId() const { return tileId; }

	// Function to move the tile according to the player
	void MoveTile(const Vector2D& direction);



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

