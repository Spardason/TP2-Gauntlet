#include "Theme.h"

Theme::Theme()
{

}

Theme::~Theme()
{

}


void Theme::Start()
{
	AudioSys->SetMusicVolume(100);
	AudioSys->PlayMusic(Musics->Get(Music::ID::Theme));
}