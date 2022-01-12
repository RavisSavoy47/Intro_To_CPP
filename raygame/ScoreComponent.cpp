#include "ScoreComponent.h"
#include "UIText.h"
#include "ScoreManager.h"
#include "string.h"
#include <iostream>
void ScoreComponent::update(float deltaTime)
{
	delete[] m_scoreText;

	m_scoreText = new char[9999]{ " " };

	sprintf_s(m_scoreText, sizeof(char) * 10, "%d",  ScoreManager::Score);

	m_scoreComponent->setText(m_scoreText);
}

void ScoreComponent::draw()
{
	m_scoreComponent->draw();
}
