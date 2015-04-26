#include "Enemy.h"

Enemy::Enemy()
	: Sprite(Texture::ID::EnnemyGhost)
	, hp(0)
	, currentX(0)
	, currentY(0)
	, player(nullptr)
	, SPEED(50)
	, manager(nullptr)
	, direction(Vector2D(0, 0))
{

}

Enemy::Enemy(Player *player, TileManager *m)
	: Sprite(Texture::ID::EnnemyGhost)
	, hp(0)
	, currentX(400)
	, currentY(400)
	, player(player)
	, SPEED(50)
	, manager(m)
	, direction(Vector2D(0, 0))
{

}


Enemy::~Enemy()
{

}

point<float> Enemy::GetNextPos(Vector2D &direction)
{
	point<float> p;

	p.x = currentX + direction.x;
	p.y = currentY + direction.y;

	//std::cout << "Next Position: " << p.x << ", " << p.y << std::endl;

	return p;
}

bool Enemy::Collides(Tile *tileToCheck)
{
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

void Enemy::MoveEnemy(point<float> toGo)
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
				SetPosition(currentX, currentY);
			}
			else
			{
				direction = { 1, -1 };
				currentX += SPEED * dt;
				currentY -= SPEED * dt;
				SetPosition(currentX, currentY);
			}
		}
		else
		{
			if (toGo.y >= currentY)
			{
				direction = { -1, 1 };
				currentX -= SPEED * dt;
				currentY += SPEED * dt;
				SetPosition(currentX, currentY);
			}
			else
			{
				direction = { -1, -1 };
				currentX -= SPEED * dt;
				currentY -= SPEED * dt;
				SetPosition(currentX, currentY);
			}
		}
	}
}

// Function to find and seek the player
void Enemy::GoTo(point<float> toGo)
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

void Enemy::Start()
{

}