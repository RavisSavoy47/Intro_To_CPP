#include "InputShotComponent.h"
#include "Engine.h"
#include "Bullet.h"
#include <raylib.h>

void InputShotComponent::start()
{
	m_timer = 0;
}

void InputShotComponent::update(float deltaTime)
{

	//Defines what a bullet is at the first edaration 
	m_bullet = new Bullet(1000, getOwner(), getName());
	//adds delta time to the timer 
	m_timer += deltaTime;
	if (RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_SPACE ))
	{
		if (m_timer > .80f)
		{
			Engine::getCurrentScene()->addActor(m_bullet);
			m_timer = 0;
		}
	}
	else
	{
		delete m_bullet;
	}
}
