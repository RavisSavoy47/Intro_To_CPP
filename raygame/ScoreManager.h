#pragma once
#include "Actor.h"

class UIText;
class ScoreComponent;

class ScoreManager :
	public Actor
{
public:
	ScoreManager(float x, float y, const char* name) : Actor::Actor(x, y, name) {}
	void start() override;
	void update(float deltaTime) override;

	/// <summary>
	/// Sets the ui text 
	/// </summary>
	/// <param name="text"></param>
	void setUIText(UIText* text) { m_scoreDisplay = text; }

public:
	static int Score;

private:

	ScoreComponent* m_scoreComp;
	UIText* m_scoreDisplay;
	
};

