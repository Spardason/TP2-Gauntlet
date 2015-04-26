#include "Tile.h"

Tile::Tile()
	: Sprite()
	, tileHeight(0)
	, tileWidth(0)
	, tileId(0)
	, currentX(0)
	, currentY(0)
	, SPEED(0)
{

}

// Special ctor
Tile::Tile(Texture::ID id, int tileWidth, int tileHeight, int tileId, point<int> pos)
	: Sprite(id)
	, tileHeight(tileHeight)
	, tileWidth(tileWidth)
	, tileId(tileId)
	, currentX(pos.x)
	, currentY(pos.y)
	, SPEED(50)
{
	SetPosition(pos.x, pos.y);
}

// Special ctor
Tile::Tile(int tileWidth, int tileHeight, int tileId, point<int> pos)
	: Sprite()
	, tileHeight(tileHeight)
	, tileWidth(tileWidth)
	, tileId(tileId)
	, currentX(pos.x)
	, currentY(pos.y)
	, SPEED(50)
{
	SetPosition(pos.x, pos.y);
}

Tile::~Tile()
{

}

// Function to move the tile
void Tile::MoveTile(Vector2D& direction)
{
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();

	// Opération time Base
	currentX -= SPEED * direction.x * dt;
	currentY -= SPEED * direction.y * dt;
	SetPosition(currentX, currentY);
}

void Tile::Update()
{
	
}

void Tile::Start()
{

}
