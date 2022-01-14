#include "ScoreManager.h"
#include "ScoreComponent.h"

int ScoreManager::Score = 0;

/// <summary>
/// Gives the actor asscess to score component 
/// </summary>
void ScoreManager::start()
{
	Actor::start();
	m_scoreComp = dynamic_cast<ScoreComponent*>(addComponent(new ScoreComponent()));
	m_scoreComp->setUIText(m_scoreDisplay);
}

void ScoreManager::update(float deltaTime)
{
	Actor::update(deltaTime);
}
