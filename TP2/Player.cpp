#include "Player.h"

// Default constructor when the player is created
Player::Player()
	: Animation(Texture::ID::Player, WALK_NB_FRAME(), ANIM_DEFAULT_SPEED, WALK_DOWN_START_SRC(), FRAME_SIZE())
	, currentX(100)
	, currentY(100)
	, currentState(IDLE)
	, score(900)
	, keys(0)
	, manager(nullptr)
	, SPEED(50)
	, bulletPool(nullptr)
	, actualBullet(nullptr)
	, bulletCanMove(false)
	, bulletIsSpawned(false)
	, bulletIsMoving(false)
	
{
	bulletPool = new Pool<Bullet>(1);
	//Start the animation on creation
	this->Stop();

	//Make it loop
	this->SetIsLooping(true);
	SetPosition(currentX, currentY);
}

// Special ctor
Player::Player(TileManager* m)
	: Animation(Texture::ID::Player, WALK_NB_FRAME(), ANIM_DEFAULT_SPEED, WALK_DOWN_START_SRC(), FRAME_SIZE())
	, currentX(100)
	, currentY(100)
	, currentState(IDLE)
	, score(900)
	, keys(0)
	, manager(m)
	, SPEED(50)
	, bulletPool(nullptr)
	, actualBullet(nullptr)
	, bulletCanMove(false)
	, bulletIsSpawned(false)
	, bulletIsMoving(false)
{
	bulletPool = new Pool<Bullet>(1);
	//Start the animation on creation
	this->Stop();

	//Make it loop
	this->SetIsLooping(true);
	SetPosition(currentX, currentY);
}

Player::~Player()
{

}

void Player::Start()
{

}

// Function to get the next position 
point<float> Player::GetNextPos(Vector2D& direction)
{
	point<float> p;

	p.x = currentX + direction.x + FRAME_SIZE().x/2;
	p.y = currentY + direction.y + FRAME_SIZE().y/2; 

	//std::cout << "Next Position: " << p.x << ", " << p.y << std::endl;

	return p;
}

// Function that handle the change of the animation states
void Player::changeState(state newState)
{
	if (this->currentState != newState)
	{
		switch (newState)
		{
		case Player::IDLE:
			if (currentState == WALK_DOWN)
			{
				this->SetSrcPos(WALK_DOWN_START_SRC());
			}
			break;
		case Player::WALK_DOWN:
			this->SetSrcPos(WALK_DOWN_START_SRC());
			this->SetNbFrame(WALK_NB_FRAME());
			this->SetFrameRate(ANIM_DEFAULT_SPEED);
			break;
		case Player::WALK_UP:
			break;
		case Player::WALK_RIGTH:
			break;
		case Player::WALK_LEFT:
			break;
		case Player::WALK_DR:
			break;
		case Player::WALK_DL:
			break;
		case Player::WALK_UL:
			break;
		case Player::WALK_UR:
			break;
		default:
			break;
		}
		//It's important to reset back to the first frame on change
		this->currentState = newState;
		this->ResetCurrentFrame();
	}
}

// Check wich tile the player is colliding with and handle it
bool Player::Collides(Tile *tileToCheck)
{
	bool canMove = true;

	//std::cout << "TileId: "<< tileToCheck->GetId() << std::endl;

	switch (tileToCheck->GetId())
	{
	case TILE_TYPE_NONE:
		break;

	case TILE_TYPE_BLOCK:
		canMove = false;
		break;

	case TILE_TYPE_DOOR:
		//std::cout << "DOOR" << std::endl;
		break;

	case TILE_TYPE_CHEST:
		//std::cout << "Chest" << std::endl;
		break;

	case TILE_TYPE_SPAWN:
		//std::cout << "Spawn" << std::endl;
		break;

	case TILE_TYPE_POT:
		//std::cout << "Potion" << std::endl;
		break;

	case TILE_TYPE_FOOD:
		//std::cout << "Food" << std::endl;
		break;

	case TILE_TYPE_KEY:
		//std::cout << "Key" << std::endl;
		break;

	default:
		break;
	}

	return canMove;
}

// Function to move the map accordingly to the player
void Player::MoveMap(Vector2D &direction)
{
	manager->MoveTiles(direction);
}

void Player::MovePlayer(Vector2D &direction)
{
	bool canMove = false;

	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();

	if (Normalize(&direction))
	{
		if ( LengthSq(&direction) != 0 )
		{
			Tile *tileToCheck = manager->CheckForTile(GetNextPos(direction));

			if (tileToCheck != nullptr)
			{
				canMove = Collides(tileToCheck);
			}
			else
			{
				canMove = true;
			}

			if (canMove)
			{
				MoveMap(direction);
			}
		}
	}
}

// Update of the player (Mostly handling inputs and player actions)
void Player::Update()
{

	Animation::Update();

	Vector2D direction = Vector2D(
		Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_A) ? -1 : 0 + Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_D) ? 1 : 0,
		Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_S) ? 1 : 0 + Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_W) ? -1 : 0)
		;

	MovePlayer(direction);

	if (!bulletIsSpawned && !bulletIsMoving)
	{
		if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_SPACE))
		{
			actualBullet = bulletPool->NewInstance();
			actualBullet->Init(currentX, currentY, direction);
			bulletIsSpawned = true;
		}
	}

	if (bulletIsSpawned)
	{
		Tile *bulletTileToCheck = manager->CheckForTile(actualBullet->GetNextPos());

		if (bulletTileToCheck != nullptr)
		{
			bulletCanMove = actualBullet->Collides(bulletTileToCheck);
		}
		else
		{
			bulletCanMove = true;
		}

		if (bulletCanMove)
		{
			actualBullet->MoveBullet();
		}
		else
		{
			actualBullet->SetAlpha(0);
			bulletPool->FreeInstance(actualBullet);
			bulletIsSpawned = false;
			bulletIsMoving = false;
		}
	}
		
	
}