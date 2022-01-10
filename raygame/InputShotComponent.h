#pragma once
#include "Component.h"

class Bullet;
class InputShotComponent :
	public Component
{
public: 
	InputShotComponent(const char* name) : Component::Component(name){};
	void start() override;
	void update(float deltaTime) override;

private:
	Bullet* m_bullet;

	float m_timer;
};

