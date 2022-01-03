#include "EnemySpawnComponent.h"
#include "Enemy.h"
#include <cstdlib>

void EnemySpawnComponent::DupilcateEnemies(float deltaTime)
{
	int rng = rand() % 10;
	if (m_timer >= m_timeLimiter)
		if (rng == 2)
			m_enemy = new Enemy(1, 2, 100);

}
