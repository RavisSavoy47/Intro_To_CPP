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
	int rng = rand() % 10;

	//if (m_timer >= 2)
	//{
		if (rng == 1)
			Engine::getCurrentScene()->addActor(new Enemy(100, 1, 100));

		if (rng == 2)
			Engine::getCurrentScene()->addActor(new Enemy(200, 1, 100));

		if (rng == 3)
			Engine::getCurrentScene()->addActor(new Enemy(300, 1, 100));

		if (rng == 4)
			Engine::getCurrentScene()->addActor(new Enemy(400, 1, 100));

		if (rng == 5)
			Engine::getCurrentScene()->addActor(new Enemy(500, 1, 100));

		if (rng == 6)
			Engine::getCurrentScene()->addActor(new Enemy(600, 1, 100));

		if (rng == 7)
			Engine::getCurrentScene()->addActor(new Enemy(700, 1, 100));

		if (rng == 8)
			Engine::getCurrentScene()->addActor(new Enemy(800, 1, 100));

		if (rng == 9)
			Engine::getCurrentScene()->addActor(new Enemy(900, 1, 100));

		m_timer = 0;
	//}
	m_timer += deltaTime;
}
