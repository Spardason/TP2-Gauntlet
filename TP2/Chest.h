#pragma once
#include "Sprite.h"
#include "Common.h"
#include "Resources.h"

class Chest :
	public Sprite
{
public:
	Chest();
	~Chest();

private:
	// Chest Position
	int currentX, currentY;
};

