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
	SetPosition((int)this->currentX, (int)this->currentY);
}

bool Bullet::Collides(const Tile *tileToCheck)
{
	std::cout << "Collides()" << std::endl;
	bool canMove = true;

	switch (tileToCheck->GetId())
	{
	case TILE_TYPE_NONE:
		break;

	case TILE_TYPE_BLOCK:
		canMove = false;
		break;

	case TILE_TYPE_DOOR:
		break;

	case TILE_TYPE_CHEST:
		break;

	case TILE_TYPE_SPAWN:
		break;

	case TILE_TYPE_POT:
		break;

	case TILE_TYPE_FOOD:
		break;

	case TILE_TYPE_KEY:
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

	this->SetPosition(currentX, currentY);
}
