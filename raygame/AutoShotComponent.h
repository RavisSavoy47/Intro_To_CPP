#pragma once
#include "Component.h"
class Bullet;

class AutoShotComponent :
	public Component
{
public:
	//Auto Shot Component Deloration 
	AutoShotComponent(const char* name) :Component::Component(name) {};
	//Updates once per frame 
	void update(float deltaTime);
private:
	// Takes in a custom madde actor designed to be a bullet 
	Bullet* m_bullet;
	//Meant to keep tabs on the time between bullets made 
	float m_timer = 0;


};

