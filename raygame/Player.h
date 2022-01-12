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
	InputComponent* m_inputComponent;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	InputShotComponent* m_shots;
	RotationActor* m_rotate;
	RingAround* m_upgrade;
	Shield* m_shield;
	PlayerLifeComponent* m_playerLife;

	int m_lives;
	int m_maxUpgradeCount;
	int m_upgradeCount;
};

