#include "MusicTheme.h"


MusicTheme::MusicTheme()
{
	// Play the music
	AudioSys->PlayMusic(Musics->Get(Music::ID::Theme));
}

MusicTheme::~MusicTheme()
{

}

void MusicTheme::Start()
{

}
