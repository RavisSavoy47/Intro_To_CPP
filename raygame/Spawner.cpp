#include "Spawner.h"
#include "Enemy.h"
#include "SpawnerComponent.h"

void Spawner::start()
{
	Actor::start();
	//Attaches enemies to the spawner
	m_enemy = dynamic_cast<SpawnerComponent*>(addComponent(new SpawnerComponent('E')));
	//Attaches upgrades to the spawner
	m_upgrade = dynamic_cast<SpawnerComponent*>(addComponent(new SpawnerComponent('U')));
}