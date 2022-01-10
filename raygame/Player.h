#pragma once
#include "Actor.h"
class InputComponent;
class MoveComponent;
class SpriteComponent;
class PlayerLives;

class Player :
	public Actor
{
public:
	//Defult Contructor 
	Player() : Actor::Actor(0, 0, "defult") {};
	//Defult DeConstructor 
	~Player() { };
	Player(float x, float y, const char* name) : Actor(x, y, name) {}

	int getLives() { return m_lives; };

	void start() override;
	void update(float deltaTime) override;
	void draw() override;
	void onCollision(Actor* actor) override;
	void removeLives(PlayerLives* actor);

private:
	InputComponent* m_inputComponent;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	int m_lives;
};

