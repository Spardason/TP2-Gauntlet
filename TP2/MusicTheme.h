#pragma once
#include "Audio.h"
#include "Component.h"
#include "Resources.h"
#include "Engine.h"

class MusicTheme :
	public Component
{
public:
	MusicTheme();
	~MusicTheme();

	void Start();
};

