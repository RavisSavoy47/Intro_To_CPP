#pragma once
#include "Component.h"
class PlayerLives;

class PlayerLifeComponent :
	public Component
{
public:
	PlayerLifeComponent(const char* name = "PlayerLifeComponent") : Component::Component(name) {}

	void start() override;

public:
	void removeLife1();
	void removeLife2();
	void removeLife3();

private:
	PlayerLives* life1;
	PlayerLives* life2;
	PlayerLives* life3;
};

