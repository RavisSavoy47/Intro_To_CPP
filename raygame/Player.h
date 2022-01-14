#pragma once
#include "Actor.h"
class InputComponent;
class MoveComponent;
class SpriteComponent;
class InputShotComponent;
class RingAround;
class RotationActor;
class Shield;
class PlayerLifeComponent;

class Player :
	public Actor
{
public:
	//Defult Contructor 
	Player() : Actor::Actor(0, 0, "defult") {};
	//Defult DeConstructor 
	~Player() { delete m_inputComponent, m_moveComponent, m_spriteComponent, m_shots;  };
	//Player Decloration 
	Player(float x, float y, const char* name) : Actor::Actor(x, y, name) {}

	void start() override;
	void update(float deltaTime) override;
	void onCollision(Actor* actor) override;

private:
	//Gets user input and creats a forward to face
	InputComponent* m_inputComponent;
	
	//Moves actor based of ther forward
	MoveComponent* m_moveComponent;
	
	//illostrates the actor
	SpriteComponent* m_spriteComponent;

	//shots a projectile at the players forward
	InputShotComponent* m_shots;

	//Creats a rotaional actor that faloows the actor 
	RotationActor* m_rotate;

	//Effective upgrade that will be parented to RotationActor
	RingAround* m_upgrade;

	//Effective upgrade that protects the player and it's location
	Shield* m_shield;

	//Ravies YOU NEED TO CPMMENT THIS 
	PlayerLifeComponent* m_playerLife;

	int m_lives;
	int m_maxUpgradeCount;
	int m_upgradeCount;
};

