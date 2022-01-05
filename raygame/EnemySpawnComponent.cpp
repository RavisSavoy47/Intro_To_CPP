#include "EnemySpawnComponent.h"
#include "Enemy.h"
#include "Engine.h"
#include <cstdlib>

void EnemySpawnComponent::start()
{
	m_timer = 0;
	m_timeLimiter = 10;
	m_enemy = new Enemy(1,1,100);
}

void EnemySpawnComponent::update(float deltaTime)
{
	DupilcateEnemies(deltaTime);

}

void EnemySpawnComponent::DupilcateEnemies(float deltaTime)
{
	int rng = rand() % 6 + 1 ;
	m_enemy = new Enemy(100 * rng, 5, 100);

	m_timer = deltaTime;

	if (m_timer >= .150f)
	{
		Engine::getCurrentScene()->addActor(m_enemy);
		m_timer = 0;
	}

	
}
