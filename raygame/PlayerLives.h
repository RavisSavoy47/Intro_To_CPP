#pragma once
#include "Actor.h"

class SpriteComponent;
class PlayerLives :
	public Actor
{
public:
	PlayerLives(float x, float y, const char* name) : Actor(x, y, name) {}

	void start() override;

private:
	SpriteComponent* m_spriteComponent;
};

