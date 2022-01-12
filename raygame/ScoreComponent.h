#pragma once
#include "Component.h"
#include "UIText.h"
class ScoreComponent :
	public Component
{
public:
	void update(float deltaTime) override;
	void draw() override;

	void setCurrentScore(float value) { m_currentScore = value; }

	void setUIText(UIText* text) { m_scoreComponent = text; }

private:
	UIText* m_scoreComponent;
	float m_currentScore;
	char* m_scoreText;
};

