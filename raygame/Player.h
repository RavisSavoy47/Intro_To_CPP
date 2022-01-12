#pragma once
#include "Actor.h"
class InputComponent;
class MoveComponent;
class SpriteComponent;
class PlayerLifeComponent;
class InputShotComponent;
class RingAround;
class RotationActor;
class Shield;

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

	int getLives() { return m_lives; };

	void start() override;
	void update(float deltaTime) override;
	void draw() override;
	void onCollision(Actor* actor) override;

private:
	InputComponent* m_inputComponent;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	PlayerLifeComponent* m_playerLifeComponent;
	int m_lives;
	InputShotComponent* m_shots;

	RotationActor* m_rotate;

	RingAround* m_upgrade;

	Shield* m_shield;

	int m_maxUpgradeCount;
	int m_upgradeCount;
};

