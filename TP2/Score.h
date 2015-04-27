#pragma once

#include "Text.h"
#include "Player.h"

/*
	This is the class for the score, the display of it
*/

class Score :
	public Text
{
public:
	Score();
	// CTOR with parameter, in this case, the player, to update his score
	Score(Player *p);
	~Score();

	void Start();
	void Update();

private:
	// The player for the score
	Player *player;

	// Intern variable for score update
	int point;

	// Timer to decrement the score
	float timer;
};

