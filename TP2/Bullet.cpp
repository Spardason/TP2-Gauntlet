#include "Bullet.h"


Bullet::Bullet()
	: Sprite(Texture::ID::Bullet, TOP_START_SRC(), FRAME_SIZE())
	, currentX(0)
	, currentY(0)
	, SPEED(60)
	, direction(Vector2D(1, 0))
{
	isVisible = false;
}

Bullet::~Bullet()
{

}

void Bullet::OnClear()
{
	isVisible = false;
}

void Bullet::Update()
{

}

void Bullet::Start()
{

}

void Bullet::Init(float currentX, float currentY, Vector2D &direction)
{
	if (direction.x == 0 && direction.y == 0)
	{
		direction.y = 1;
	}

	isVisible = true;
	this->direction = direction;
	this->currentX = currentX;
	this->currentY = currentY;
	SetPosition(this->currentX, this->currentY);
}

bool Bullet::Collides(Tile *tileToCheck)
{
	std::cout << "Collides()" << std::endl;
	bool canMove = true;

	//std::cout << "TileId: "<< tileToCheck->GetId() << std::endl;

	switch (tileToCheck->GetId())
	{
	case TILE_TYPE_NONE:
		break;

	case TILE_TYPE_BLOCK:
		canMove = false;
		break;

	case TILE_TYPE_DOOR:
		//std::cout << "DOOR" << std::endl;
		break;

	case TILE_TYPE_CHEST:
		//std::cout << "Chest" << std::endl;
		break;

	case TILE_TYPE_SPAWN:
		//std::cout << "Spawn" << std::endl;
		break;

	case TILE_TYPE_POT:
		//std::cout << "Potion" << std::endl;
		break;

	case TILE_TYPE_FOOD:
		//std::cout << "Food" << std::endl;
		break;

	case TILE_TYPE_KEY:
		//std::cout << "Key" << std::endl;
		break;

	default:
		break;
	}

	return canMove;
}

// Function to get the next position 
point<float> Bullet::GetNextPos()
{
	std::cout << "GetNextPos()" << std::endl;
	point<float> p;

	p.x = currentX + direction.x + FRAME_SIZE().x / 2;
	p.y = currentY + direction.y + FRAME_SIZE().y / 2;

	//std::cout << "Next Position: " << p.x << ", " << p.y << std::endl;

	return p;
}

void Bullet::MoveBullet()
{
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();

	// Opération time Base
	currentX += SPEED * direction.x * dt;
	currentY += SPEED * direction.y * dt;
	//std::cout << "currentX: " << currentX << "'" << "currentY: " << currentY << std::endl;

	SetPosition(currentX, currentY);
}
