#pragma once
#include "Component.h"
class Bullet;

class AutoShotComponent :
	public Component
{
public:
	AutoShotComponent(const char* name) :Component::Component(name) {};
	void update(float deltaTime);
private:
	Bullet* m_bullet;
	float m_timer = 0;


};

