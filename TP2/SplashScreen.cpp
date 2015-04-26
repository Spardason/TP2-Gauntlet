#include "SplashScreen.h"


SplashScreen::SplashScreen()
	:Text(Text("Press P tp Start", Font::ID::Dialog))
{
	
}

SplashScreen::~SplashScreen()
{

}

void SplashScreen::Start()
{
	SetPosition(100, 100);
}
