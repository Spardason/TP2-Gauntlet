#include "Enemy.h"

Enemy::Enemy()
	: Sprite(Texture::ID::EnnemyGhost)
	, currentX(400)
	, currentY(400)
	, player(nullptr)
	, SPEED(50)
	, manager(nullptr)
	, direction(Vector2D(0, 0))
{
	SetPosition((int)currentX, (int)currentY);
}

Enemy::Enemy(Player *player, TileManager *m)
	: Sprite(Texture::ID::EnnemyGhost)
	, currentX(400)
	, currentY(400)
	, player(player)
	, SPEED(50)
	, manager(m)
	, direction(Vector2D(0, 0))
{
	SetPosition((int)currentX, (int)currentY);
}


Enemy::~Enemy()
{

}

point<float> Enemy::GetNextPos(const Vector2D &direction)
{
	point<float> p;

	p.x = currentX + direction.x;
	p.y = currentY + direction.y;

	return p;
}

bool Enemy::Collides(const Tile *tileToCheck)
{
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

void Enemy::MoveEnemy(const point<float> toGo)
{
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();

	if (currentX != toGo.x && currentY != toGo.y)
	{
		if (toGo.x >= currentX)
		{
			if (toGo.y >= currentY)
			{
				direction = { 1, 1 };
				currentX += SPEED * dt;
				currentY += SPEED * dt;
				SetPosition((int)currentX, (int)currentY);
			}
			else
			{
				direction = { 1, -1 };
				currentX += SPEED * dt;
				currentY -= SPEED * dt;
				SetPosition((int)currentX, (int)currentY);
			}
		}
		else
		{
			if (toGo.y >= currentY)
			{
				direction = { -1, 1 };
				currentX -= SPEED * dt;
				currentY += SPEED * dt;
				SetPosition((int)currentX, (int)currentY);
			}
			else
			{
				direction = { -1, -1 };
				currentX -= SPEED * dt;
				currentY -= SPEED * dt;
				SetPosition((int)currentX, (int)currentY);
			}
		}
	}
}

// Function to find and seek the player
void Enemy::GoTo(const point<float> toGo)
{
	Tile *tileToCheck = manager->CheckForTile(GetNextPos(direction));

	if (tileToCheck != nullptr)
	{
		if (Collides(tileToCheck))
		{
			MoveEnemy(toGo);
		}
		else
		{

		}
	}
	else
	{
		MoveEnemy(toGo);
	}
}

void Enemy::Update()
{
	point<float> toGo = player->GetPostion();
	GoTo(toGo);
}
