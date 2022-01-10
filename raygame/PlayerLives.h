#pragma once
#include "Actor.h"
class SpriteComponent;

class PlayerLives :
	public Actor
{
public:
	PlayerLives(float x, float y, const char* name) : Actor(x, y, name) {};

	void start() override;
	void update(float deltaTime) override;

private:
	SpriteComponent* m_spriteComponent;
};

