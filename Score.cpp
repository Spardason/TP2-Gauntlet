#include "Score.h"
std::stringstream points;

Score::Score()
	: Text("", Font::ID::Dialog)
	, timer(1.0f)
{

}

//Special ctor
Score::Score(Player *p)
	: player(p)
	, Text("", Font::ID::Dialog)
	, timer(1.0f)
{

}

Score::~Score()
{

}


void Score::Start()
{
	// Set the base score and the base position
	points << player->GetScore();
	SetPosition(player->GetPostion().x - 100, player->GetPostion().y - 100);
}

void Score::Update()
{
	points << player->GetScore();

	// Get the time and see if its past 1 second
	if (Engine::GetInstance()->GetTimer()->GetGameTime() >= timer)
	{
		// Decrement the score and reset the timer
		int currentScore = player->GetScore();
		player->SetScore(currentScore -= 1);
		Engine::GetInstance()->GetTimer()->Reset();
	}

	// Set the new text after update
	SetText("Score: " + points.str());
	Text::Update();

	// Reset the text string
	points.str(std::string());
	SetPosition(player->GetPostion().x - 100, player->GetPostion().y - 100);
}

