#ifndef ResourcesID
#define ResourcesID

// This header contains the ID of every image, sound, text in the game.

namespace Texture
{
	enum ID
	{
		Map,
		EnnemyGhost,
		Chest,
		Player,
		Fake,
		Food,
		Door,
		Key,
		Potion,
		DoorHorizontal,
		Bullet
	};
}

namespace Sound
{
	enum ID
	{
		EnemyHit
	};
}

namespace Music
{
	enum ID
	{
		Theme
	};
}

namespace Font
{
	enum ID
	{
		Dialog
	};
}

#endif 
