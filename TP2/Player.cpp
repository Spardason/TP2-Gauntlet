#include "Player.h"

// Default constructor when the player is created
Player::Player()
	: Animation(Texture::ID::Player, WALK_NB_FRAME(), ANIM_DEFAULT_SPEED, WALK_DOWN_START_SRC(), FRAME_SIZE())
	, currentX(100)
	, currentY(100)
	, currentState(IDLE)
	, score(900)
	, keys(0)
	, manager(nullptr) // L'erreur était ici, tu ne peut pas donner null à ça, ça pète pcq tu call des affaires dans ce constructeur la.
	, SPEED(50)
	, MAX_WIDTH(528)
	, MAX_HEIGHT(464)
	//, bulletPool(nullptr)
{
	camera = {0, 0, 256, 240};
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
	, MAX_WIDTH(528)
	, MAX_HEIGHT(464)
	//, bulletPool(nullptr)
{
	camera = { 0, 0, 256, 240 };
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
point<int> Player::GetNextPos(Vector2D& direction)
{
	point<int> p;

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
void Player::MoveMap(Vector2D& direction)
{
	manager->MoveTiles(direction);
}

void Player::MovePlayer()
{
	bool canMove = false;

	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();

	Vector2D direction = Vector2D(
		Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_A) ? -1 : 0 + Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_D) ? 1 : 0,
		Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_S) ? 1 : 0 + Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_W) ? -1 : 0)
		;

	if ((currentX < 0) || currentX + FRAME_SIZE().x > MAX_WIDTH)
	{
		currentX -= SPEED;
	}

	if ((currentY < 0) || currentY + FRAME_SIZE().y > MAX_HEIGHT)
	{
		currentY -= SPEED;
	}

	//std::cout << direction.x << ", " << direction.y << std::endl;
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
				currentX += direction.x * SPEED * dt;
				currentY += direction.y * SPEED * dt;
				//std::cout << currentX << ", " << currentY << std::endl;
				SetPosition(currentX, currentY);
			}
		}

		//MoveMap(direction);
	}
}

// Update of the player (Mostly handling inputs and player actions)
void Player::Update()
{	
	Animation::Update();
	
	MovePlayer();

	//Center the camera over the player
	camera.x = (currentX + FRAME_SIZE().x / 2) - 256 / 2;
	camera.y = (currentY + FRAME_SIZE().y / 2) - 240 / 2;

	//Keep the camera in bounds
	if (camera.x < 0)
	{
		camera.x = 0;
	}
	if (camera.y < 0)
	{
		camera.y = 0;
	}
	if (camera.x > MAX_WIDTH - camera.w)
	{
		camera.x = MAX_WIDTH - camera.w;
	}
	if (camera.y > MAX_HEIGHT - camera.h)
	{
		camera.y = MAX_HEIGHT - camera.h;
	}

	SDL_SetRenderDrawColor(Engine::GetInstance()->GetRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(Engine::GetInstance()->GetRenderer());

	manager->Draw();

	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_SPACE))
	{
		//Bullet *actualBullet;
		//actualBullet = bulletPool->NewInstance();
	}


	/*if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_A))
	{
		Tile *tileToCheck = manager.CheckForTile(GetNextPos(DIRECTION[5]));

		if (tileToCheck != nullptr)
		{
			if (Collides(tileToCheck))
			{
				isMovingLeft = true;
				currentX -= SPEED * dt;
				SetPosition(currentX, currentY);
			}
			else
			{
				isMovingLeft = false;
			}
		}
		else
		{
			isMovingLeft = true;
			currentX -= SPEED * dt;
			SetPosition(currentX, currentY);
		}
	}
	else if (Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_A))
	{
		isMovingLeft = false;
	}

	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_S))
	{
		if (!GetIsPlaying())
		{
			changeState(WALK_DOWN);
			this->Play();
		}
		
		Tile *tileToCheck = manager.CheckForTile(GetNextPos(DIRECTION[3]));

		if (tileToCheck != nullptr)
		{
			if (Collides(tileToCheck))
			{
				isMovingDown = true;
				currentY += SPEED * dt;
				SetPosition(currentX, currentY);
			}
			else
			{
				isMovingDown = false;
			}
		}
		else
		{
			isMovingDown = true;
			currentY += SPEED * dt;
			SetPosition(currentX, currentY);
		}
	}

	else if (Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_S))
	{
		isMovingDown = false;
		if (GetIsPlaying())
		{
			changeState(IDLE);
			this->Stop();
		}
	}

	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_D))
	{
		Tile *tileToCheck = manager.CheckForTile(GetNextPos(DIRECTION[1]));

		if (tileToCheck != nullptr)
		{
			if (Collides(tileToCheck))
			{
				isMovingRight = true;
				currentX += SPEED * dt;
				SetPosition(currentX, currentY);
			}
			else
			{
				isMovingRight = false;
			}
		}
		else
		{
			isMovingRight = true;
			currentX += SPEED * dt;
			SetPosition(currentX, currentY);
		}
	}
	else if (Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_D))
	{
		isMovingRight = false;
	}*/
}	
