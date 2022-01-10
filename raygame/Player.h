#pragma once
#include "Actor.h"
class InputComponent;
class MoveComponent;
class SpriteComponent;
class InputShotComponent;

class Player :
	public Actor
{
public:
	//Defult Contructor 
	Player() : Actor::Actor(0, 0, "defult") {};
	//Defult DeConstructor 
	~Player() { };
	Player(float x, float y, const char* name) : Actor(x, y, name) {}

	void start() override;
	void update(float deltaTime) override;
	void draw() override;
	void onCollision(Actor* actor) override;

private:
	InputComponent* m_inputComponent;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	InputShotComponent* m_shots;
};

