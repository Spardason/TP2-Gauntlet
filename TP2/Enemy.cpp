#include "Enemy.h"

Enemy::Enemy()
	: Sprite(Texture::ID::EnnemyGhost)
	, hp(0)
	, currentX(100)
	, currentY(100)
	, player(nullptr)
{

}

// Special ctor
Enemy::Enemy(Player *player)
	: Sprite(Texture::ID::EnnemyGhost)
	, hp(0)
	, currentX(100)
	, currentY(100)
	, player(player)
{
	SetPosition(currentX, currentY);
}

Enemy::~Enemy()
{

}

// FFunction to find and seek the player
void Enemy::GoTo(point<int> toGo)
{
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();;
	if (currentX != toGo.x && currentY != toGo.y)
	{

		if (toGo.x >= currentX )
		{
			if (toGo.y >= currentY)
			{
				currentX += SPEED * dt;
				currentY += SPEED * dt;
				SetPosition(currentX, currentY);
			}
			else
			{
				currentX += SPEED * dt;
				currentY -= SPEED * dt;
				SetPosition(currentX, currentY);
			}
		}
		else
		{
			if (toGo.y >= currentY)
			{
				currentX -= SPEED * dt;
				currentY += SPEED * dt;
				SetPosition(currentX, currentY);
			}
			else
			{
				currentX -= SPEED * dt;
				currentY -= SPEED * dt;
				SetPosition(currentX, currentY);
			}
		}
	}
}

void Enemy::Update()
{
	point<int> toGo = player->GetPostion();
	GoTo(toGo);
}
