#pragma once
#include "Text.h"
#include "Resources.h"

/*
	This is the class for the splash scree, here only text
*/

class SplashScreen :
	public Text
{
public:
	SplashScreen();
	~SplashScreen();

	// Function to hide the splashScreen when needed
	void Hide();
};

