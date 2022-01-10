#include "SpawnerComponent.h"
#include "Enemy.h"
#include "Upgrade.h"
#include "Engine.h"
#include <cstdlib>

SpawnerComponent::SpawnerComponent(char spawn)
{
	m_choice = spawn;
}

void SpawnerComponent::start()
{
	Component::start();
	m_timeLimiter = 10;

}

void SpawnerComponent::update(float deltaTime)
{
	if (m_choice == 'E')
		DupilcateEnemies(deltaTime);
	else if (m_choice == 'U')
		DupilcateUpgrades(deltaTime);

}

/// <summary>
/// Creats a enemy every second once 
/// per update 
/// </summary>
/// <param name="deltaTime">time deviated based off the CPU</param>
void SpawnerComponent::DupilcateEnemies(float deltaTime)
{
	// Gets a number between 2 and 30
	int rng = rand() % 30 + 1 ;
	//Creats an enemy
	m_enemy = new Enemy(25 * rng, 5, 200);
	//adds delta time to the timer once per frame 
	m_timer += deltaTime;

	//check to see if timer ends up beind=g greater then or equal to 
	if (m_timer >= 2.0f)
	{
		// That new enemy to the scene 
		Engine::getCurrentScene()->addActor(m_enemy);
		//sets the timer back to 
		m_timer = 0;
	}
	else
		//Clears un-needed data
		delete m_enemy;
}

/// <summary>
/// Creats a enemy every second once 
/// per update 
/// </summary>
/// <param name="deltaTime">time deviated based off the CPU</param>
void SpawnerComponent::DupilcateUpgrades(float deltaTime)
{
	// Gets a number between 2 and 30
	int rng = rand() % 30 + 1;
	//Creats an upgrade
	m_upgrade = new Upgrade(25 * rng, 5, 200, "RingAround");
	//adds delta time to the timer once per frame 
	m_timer += deltaTime;

	//check to see if timer ends up beind=g greater then or equal to 
	if (m_timer >= 8.0f)
	{
		// That new enemy to the scene 
		Engine::getCurrentScene()->addActor(m_upgrade);
		//sets the timer back to 
		m_timer = 0;
	}
	else
		//Clears un-needed data
		delete m_upgrade;
}
