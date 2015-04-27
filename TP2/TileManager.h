#pragma once

#include "Tile.h" 
#include "Map.h"

/*
	This class mamage all the tiles, well in this case, more like contains since i had not the time to implement everything I need it 
	is only functionnal, I intend to imporve it afterward.
*/

// ID types tile enum
enum tileType{
	TILE_TYPE_NONE = 0,
	TILE_TYPE_BLOCK,
	TILE_TYPE_DOOR,
	TILE_TYPE_CHEST,
	TILE_TYPE_SPAWN,
	TILE_TYPE_POT,
	TILE_TYPE_FOOD,
	TILE_TYPE_KEY,
	TILE_TYPE_SPAWN1,
	TILE_TYPE_SPAWN2,
	TILE_TYPE_SPAWN3
};

// The size of the map
const int MAP_WIDTH = 33;
const int MAP_HEIGHT = 29;

class TileManager
{
public:
	TileManager();
	// CTOR with parameter, in this case, the map created with int
	TileManager(int map[MAP_HEIGHT][MAP_WIDTH], Map *mapPng);
	~TileManager();
	
	// Function that check the postion in case is a tile or not, and if yes, return the tile
	Tile *CheckForTile(const point<float> posToCheck);

	// Function that geberate the tiles for the map
	void CreateMap(int tiledMap[MAP_HEIGHT][MAP_WIDTH]);

	// Function to move all the tiles in the map vector
	void MoveTiles(Vector2D& direction);

private:
	// Map background
	Map *mapPng;

	// Map with int to get the right tile at the right place
	int tiledMap[MAP_HEIGHT][MAP_WIDTH];

	// The vector of tiles....the map
	std::vector<Tile*> map;

	// The iterator to iterate throught the vector
	std::vector<Tile*>::iterator it;
};

