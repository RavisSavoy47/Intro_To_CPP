#include "InputShotComponent.h"
#include "Engine.h"
#include "Bullet.h"
#include <raylib.h>

void InputShotComponent::start()
{
	Component::start();
	m_timer = 0;
}

void InputShotComponent::update(float deltaTime)
{

	//Defines what a bullet is at the first edaration 
	m_bullet = new Bullet(1000, getOwner(), getName());
	//adds delta time to the timer 
	m_timer += deltaTime;

	//if the space is is pressed down and the m_timer is greater then second
	if (RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_SPACE) && m_timer > .1f)
	{
		//Adds m_bullet to the scene 
		Engine::getCurrentScene()->addActor(m_bullet);
		//Rests the timer back to zero
		m_timer = 0;
	}
	else
	{
		//else delete the created bullet 
		delete m_bullet;
	}
}
