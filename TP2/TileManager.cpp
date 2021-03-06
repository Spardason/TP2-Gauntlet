#include "TileManager.h"

TileManager::TileManager()
	: mapPng(nullptr)
{

}

//Special ctor
TileManager::TileManager(int _map[MAP_HEIGHT][MAP_WIDTH], Map *mapPng)
	: mapPng(mapPng)
{
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			tiledMap[j][i] = _map[j][i];
		}
	}
	CreateMap(tiledMap);
}

TileManager::~TileManager()
{

}

// Function to create the map of tiles
void TileManager::CreateMap(int tiledMap[MAP_HEIGHT][MAP_WIDTH])
{
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			// Switch on the number from the int map to see wich tile to create
			switch (tiledMap[j][i])
			{	
			case 1:
			{
				Tile *blockTile = new Tile(16, 16, TILE_TYPE_BLOCK, point<int>(i * 16, j * 16));
				map.push_back(blockTile);
			}
				break;

			case 2:
			{
				Tile *doorTile = new Tile(Texture::ID::Door, 16, 16, TILE_TYPE_DOOR, point<int>(i * 16, j * 16));
				map.push_back(doorTile);
			}
				break;

			case 3:
			{
				Tile *chesTile = new Tile(Texture::ID::Chest, 16, 16, TILE_TYPE_CHEST, point<int>(i * 16, j * 16));
				map.push_back(chesTile);
			}
				break;

			case 4:
				break;

			case 5:
			{
				Tile *potTile = new Tile(Texture::ID::Potion, 16, 16, TILE_TYPE_POT, point<int>(i * 16, j * 16));
				map.push_back(potTile);
			}
				break;

			case 6:
			{
				Tile *foodTile = new Tile(Texture::ID::Food, 16, 16, TILE_TYPE_FOOD, point<int>(i * 16, j * 16));
				map.push_back(foodTile);
			}
				break;

			case 7:
			{				
				Tile *keyTile = new Tile(Texture::ID::Key, 16, 16, TILE_TYPE_KEY, point<int>(i * 16, j * 16));
				map.push_back(keyTile);
			}
				break;

			case 8:
			{
				Tile *doorTile = new Tile(Texture::ID::DoorHorizontal, 16, 16, TILE_TYPE_DOOR, point<int>(i * 16, j * 16));
				map.push_back(doorTile);
			}
				break;

			case 9:
			{
				Tile *spawn1Tile = new Tile(Texture::ID::Spawn1, 16, 16, TILE_TYPE_SPAWN1, point<int>(i * 16, j * 16));
				map.push_back(spawn1Tile);
			}
				break;

			case 10:
			{
				Tile *spawn2Tile = new Tile(Texture::ID::Spawn2, 16, 16, TILE_TYPE_SPAWN2, point<int>(i * 16, j * 16));
				map.push_back(spawn2Tile);
			}
				break;

			case 11:
			{
				Tile *spawn3Tile = new Tile(Texture::ID::Spawn3, 16, 16, TILE_TYPE_SPAWN3, point<int>(i * 16, j * 16));
				map.push_back(spawn3Tile);
			}
				break;

			default:
				break;
			}
		}
	}
}

// Function to move all the tiles
void TileManager::MoveTiles(Vector2D &direction)
{
	mapPng->MoveMap(direction);
	for (it = map.begin(); it != map.end(); ++it)
	{
		(*it)->MoveTile(direction);
	}
}

// Function that look for tiles  at the next position that the player will go and return it if there's one
Tile* TileManager::CheckForTile(const point<float> posToCheck)
{
	Tile *tileToReturn = nullptr;
	
	for (it = map.begin(); it != map.end(); ++it)
	{
		float startRectX = (float)(*it)->GetPosition().x;
		float startRectY = (float)(*it)->GetPosition().y;
		float rectWidth = (float)(*it)->GetWidth();
		float rectHeight = (float)(*it)->GetHeight();

		Rectangle *tileRect = new Rectangle(startRectX, startRectY, rectWidth, rectHeight);

		if (tileRect->Contains(posToCheck.x, posToCheck.y))
		{
			tileToReturn = (*it);
		}
	}

	return tileToReturn;
}