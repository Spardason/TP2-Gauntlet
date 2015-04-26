#include "SplashScreen.h"


SplashScreen::SplashScreen()
	:Text("Press P To Start", Font::ID::Dialog)
{
	SetColor(Color::RED);
	SetPosition(40, 100);
}

SplashScreen::~SplashScreen()
{

}

void SplashScreen::Hide()
{
	isVisible = false;
}
