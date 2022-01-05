#include "EnemySpawner.h"
#include "Enemy.h"
#include "EnemySpawnComponent.h"

void EnemySpawner::start()
{
	m_enemy = dynamic_cast<EnemySpawnComponent*>(addComponent(new EnemySpawnComponent()));
}