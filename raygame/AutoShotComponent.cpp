#include "AutoShotComponent.h"
#include "Bullet.h"
#include "Engine.h"

void AutoShotComponent::update(float deltaTime)
{
	//Crats a new bullet and it's appointed to the bullet pointer
	m_bullet = new Bullet(1000, getOwner(), getName());
	//Adds deta time to the current timer 
	m_timer += deltaTime;
	//If the timer is 8 seconds . . .
	if (m_timer > .80f)
	{
		//Add ther created actor to the to the current scene 
		Engine::getCurrentScene()->addActor(m_bullet);
		//Sets the timer to be zero again 
		m_timer = 0;
	}
	//other wise. . .
	else
		//delete whatever was asigned to m_bulllet
		delete m_bullet;
}
