#pragma once
#include "Actor.h"

class SpriteComponent;

class RotationActor : 
	public Actor
{
public:
	RotationActor(Actor* owner);
	void start() override;
	void update(float deltaTime) override;

private:
	SpriteComponent* m_spriteComp;
	float m_timer;
	Actor* m_owner;

};

