#include "DeathScreen.h"

DeathScreen::DeathScreen()
	:Text("You are Dead", Font::ID::Dialog)
{
	SetColor(Color::BLUE);
	SetPosition(40, 100);
	isVisible = false;
}

DeathScreen::~DeathScreen()
{

}

void DeathScreen::Hide()
{
	isVisible = false;
}

void DeathScreen::Show()
{
	isVisible = true;
}
