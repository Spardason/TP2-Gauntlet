#pragma once

#include "Common.h"
#include "Resources.h"
#include "Animation.h"
#include "TileManager.h"
#include "Pool.h"
#include "Bullet.h"

class Player :
	public Animation
{
public:
	Player();
	// CTOR with parameter, on this case the tile manager, yeah I know that injection is bad in this case but, we were short in time
	// So I had to do something functionnal
	Player(TileManager *m);
	~Player();

	void Start();
	void Update();

	// Position getter 
	point<float> GetPostion() { point<float> p; p.x = currentX; p.y = currentY; return p; }

	// Score getter
	int GetScore() { return score; }

	// Score setter
	void SetScore(int s) { score = s; }

	// Function that move the background
	void MoveMap(Vector2D &direction);

	void MovePlayer(Vector2D &direction);

	void UpdateAnim(Vector2D &direction);

private:
	// Pool of bullet....only one yeah...but I had to, I don't want to recreate a bullet each time I shoot
	Pool<Bullet> *bulletPool;
	Bullet *actualBullet;
	// player speed
	const int SPEED;

	// Booleans for the bullet
	bool bulletCanMove;
	bool bulletIsSpawned;
	bool bulletIsMoving;

	bool canPlay;

	// Player postion
	float currentX, currentY;

	// Player score
	int score;

	// Player keys
	int keys;

	// The tile manager
	TileManager* manager;

	//States used to determine which animation will take place 
	enum state { IDLE, WALK_DOWN, WALK_UP, WALK_RIGTH, WALK_LEFT, WALK_DR, WALK_DL, WALK_UL, WALK_UR};
	state currentState;

	//State Setter
	void changeState(state newState);

	// Check if the player collides with another object
	bool Collides(Tile *tileToCheck);

	// Get the next postion the player will go to see if it will collide
	point<float> GetNextPos(Vector2D& direction);

	// Set Animation constant
	const int WALK_NB_FRAME() { return 2; }
	const int IDLE_NB_FRAME() { return 1; }

	// Set animation position on sprite sheets
	const point<int> FRAME_SIZE()					{ return{ 16, 16 }; };
	const point<int> WALK_DOWN_START_SRC()			{ return{ 0, 0 }; };
	const point<int> WALK_DOWN_LEFT_START_SRC()		{ return{ 0, 16 }; };
	const point<int> WALK_RIGHT_START_SRC()			{ return{ 0, 32 }; };
	const point<int> WALK_DOWN_RIGHT_START_SRC()	{ return{ 0, 48 }; };
	const point<int> WALK_LEFT_START_SRC()			{ return{ 0, 64 }; };
	const point<int> WALK_UP_RIGHT_START_SRC()		{ return{ 0, 80 }; };
	const point<int> WALK_UP_START_SRC()			{ return{ 0, 96 }; };
	const point<int> WALK_UP_LEFT_START_SRC()		{ return{ 0, 112 }; };

	
};

