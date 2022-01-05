#include "EnemySpawner.h"
#include "Enemy.h"
#include "EnemySpawnComponent.h"

void EnemySpanner::start()
{
	Actor::start();
	m_enemy = dynamic_cast<EnemySpawnComponent*>(addComponent(new EnemySpawnComponent()));
}