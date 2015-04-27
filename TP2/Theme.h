#pragma once
#include "Audio.h"
#include "Component.h"
#include "Resources.h"
#include "Engine.h"

/*
	The class for the main music
*/

class Theme :
	public Component
{
public:
	Theme();
	~Theme();

	void Start();
};

