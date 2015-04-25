#pragma once

#include "Common.h"
#include "Resources.h"
#include "Animation.h"
#include "TileManager.h"

class Player :
	public Animation
{
public:
	Player();
	// CTOR with parameter, on this case the tile manager, yeah I know that injection is bad in this case but, we were short in time
	// So I had to do something functionnal
	Player(TileManager m);
	~Player();

	void Start();
	void Update();

	// Position getter 
	point<int> GetPostion() { point<int> p; p.x = currentX; p.y = currentY; return p; }

	// Score getter
	int GetScore() { return score; }

	// Score setter
	void SetScore(int s) { score = s; }

	// Function that move the background
	void MoveMap(Vector2D& direction);

private:
	// Pool of bullet....only one yeah...but I had to, I don't want to recreate a bullet each time I shoot
    //Pool<Bullet> *bulletPool;

	// player speed
	const int SPEED;

	// Player postion
	int currentX, currentY;

	// Player score
	int score;

	// Player keys
	int keys;

	// The tile manager
	TileManager manager;

	//States used to determine which animation will take place 
	enum state { IDLE, WALK_DOWN, WALK_UP, WALK_RIGTH, WALK_LEFT, WALK_DR, WALK_DL, WALK_UL, WALK_UR};
	state currentState;

	//State Setter
	void changeState(state newState);

	// Check if the player collides with another object
	bool Collides(Tile *tileToCheck);

	// Get the next postion the player will go to see if it will collide
	point<int> GetNextPos(Vector2D& direction);

	// Set Animation constant
	const int WALK_NB_FRAME() { return 2; }
	const int IDLE_NB_FRAME() { return 1; }

	// Set animation position on sprite sheets
	const point<int> FRAME_SIZE() { return{ 16, 16 }; };
	const point<int> WALK_DOWN_START_SRC() { return{ 0, 0 }; };

	
};

