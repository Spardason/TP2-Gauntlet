#include "Chest.h"

Chest::Chest()
	: Sprite(Texture::ID::Chest)
	, currentX(350)
	, currentY(350)
{
	SetPosition(currentX, currentY);
}

Chest::~Chest()
{

}

void Chest::Start()
{

}