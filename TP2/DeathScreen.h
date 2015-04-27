#pragma once

#include "Text.h"
#include "Resources.h"

class DeathScreen :
	public Text
{
public:
	DeathScreen();
	~DeathScreen();

	// Functions to Hide Show the screen
	void Hide();
	void Show();
};

