#include "Bullet.h"


Bullet::Bullet()
	: Animation(Texture::ID::Bullet, IDLE_NB_FRAME(), ANIM_DEFAULT_SPEED, TOP_START_SRC(), FRAME_SIZE())
	, currentX(0)
	, currentY(0)
	, SPEED(0)
{

}

// Specila ctor
Bullet::Bullet(point<int> pos)
	: Animation(Texture::ID::Bullet, IDLE_NB_FRAME(), ANIM_DEFAULT_SPEED, TOP_START_SRC(), FRAME_SIZE())
	, currentX(pos.x)
	, currentY(pos.y)
	, SPEED(50)
{
	SetPosition(currentX, currentY);
}

Bullet::~Bullet()
{

}

void Bullet::Update()
{
	// Supposed to move the bullet <-----TO DO
	std::cout << "BULLET!!!!" << std::endl;
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();
	currentY += SPEED * dt;
	SetPosition(currentX, currentY);
}
