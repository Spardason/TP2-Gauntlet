#include "Map.h"

Map::Map()
	: Sprite(Texture::ID::Map)
	, currentX(0)
	, currentY(0)
	, SPEED(50)
{

}

Map::~Map()
{

}

// Function to move the map
void Map::MoveMap(Vector2D &direction)
{
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();

	// Opération time Base
	currentX -= SPEED * direction.x * dt;
	currentY -= SPEED * direction.y * dt;

	SetPosition((int)currentX, (int)currentY);
}
