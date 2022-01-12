#include "Spawner.h"
#include "Enemy.h"
#include "SpawnerComponent.h"

void Spawner::start()
{
	Actor::start();
	m_enemy = dynamic_cast<SpawnerComponent*>(addComponent(new SpawnerComponent('E')));
	
	m_upgrade = dynamic_cast<SpawnerComponent*>(addComponent(new SpawnerComponent('U')));
}