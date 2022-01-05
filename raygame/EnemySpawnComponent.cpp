#include "EnemySpawnComponent.h"
#include "Enemy.h"
#include "Engine.h"
#include <cstdlib>

void EnemySpawnComponent::start()
{
	Component::start();
	m_timeLimiter = 10;
	m_enemy = new Enemy(1,1,100);
}

void EnemySpawnComponent::update(float deltaTime)
{
	DupilcateEnemies(deltaTime);

}

void EnemySpawnComponent::DupilcateEnemies(float deltaTime)
{

	int rng = rand() % 30 + 1 ;
	m_enemy = new Enemy(25 * rng, 5, 400);

	m_timer += deltaTime;

	if (m_timer >= 1.0f)
	{
		Engine::getCurrentScene()->addActor(m_enemy);
		m_timer = 0;
	}

	
}
