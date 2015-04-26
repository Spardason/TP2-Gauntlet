#include "Game.h"

Game::Game()
	: splashScreen(nullptr)
	, theme(nullptr)
	, mapSprite(nullptr)
	, manager(nullptr)
	, player(nullptr)
	, score(nullptr)
	, gameOver(false)
{
	Init();
}

Game::~Game()
{
	//delete splashScreen;
	delete theme;
	delete mapSprite;
	delete manager;
	delete player;
	delete score;
}

void Game::Init()
{
	// Load all the Textures
	Textures->LoadTexture(Texture::ID::Fake, "fakeSquare.png");
	Textures->LoadTexture(Texture::ID::Map, "Map.png");
	Textures->LoadTexture(Texture::ID::Player, "Warrior.png");
	Textures->LoadTexture(Texture::ID::Chest, "Chest.png");
	Textures->LoadTexture(Texture::ID::Food, "Food.png");
	Textures->LoadTexture(Texture::ID::Door, "Door.png");
	Textures->LoadTexture(Texture::ID::DoorHorizontal, "DoorHorizontal.png");
	Textures->LoadTexture(Texture::ID::Key, "Key.png");
	Textures->LoadTexture(Texture::ID::Potion, "Potion.png");
	Textures->LoadTexture(Texture::ID::Bullet, "Bullet.png");
	Textures->LoadTexture(Texture::ID::Spawn1, "Spawn1.png");
	Textures->LoadTexture(Texture::ID::Spawn2, "Spawn2.png");
	Textures->LoadTexture(Texture::ID::Spawn3, "Spawn3.png");
	Textures->LoadTexture(Texture::ID::EnnemyGhost, "Ghost.png");

	// Load all the Fonts
	Fonts->LoadFont(Font::ID::Dialog, "dialog.ttf", 23);

	// Load all the Sounds
	Musics->LoadMusic(Music::ID::Theme, "05gauntlet.mp3");

	// Create all the map consts
	const int MAP_WIDTH = 33;
	const int MAP_HEIGHT = 29;

	// Create the map
	int tileMap[MAP_HEIGHT][MAP_WIDTH] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1 },
	{ 1, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 9, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 0, 0, 0, 0, 0, 1, 7, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 3, 3, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 8, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 7, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 11, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 3, 3, 1, 0, 11, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 11, 0, 1, 0, 1, 3, 3, 1, 0, 5, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };


	// Create all game objects
  
	theme = new MusicTheme();
	mapSprite = new Map();
	manager = new TileManager(tileMap, mapSprite);
	player = new Player(manager);
	enemyGhost = new Enemy(player, manager);
	score = new Score(player);
	splashScreen = new SplashScreen();
}

void Game::Start()
{

}

void Game::Update()
{
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_P))
	{
		splashScreen->Hide();
	}
	
}
