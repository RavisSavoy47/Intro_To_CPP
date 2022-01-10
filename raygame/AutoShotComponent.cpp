#include "AutoShotComponent.h"
#include "Bullet.h"
#include "Engine.h"

void AutoShotComponent::update(float deltaTime)
{
	m_bullet = new Bullet(1000, getOwner(), getName());
	m_timer += deltaTime;
	if (m_timer > .80f)
	{
		Engine::getCurrentScene()->addActor(m_bullet);
		m_timer = 0;
	}
	else
		delete m_bullet;
}
