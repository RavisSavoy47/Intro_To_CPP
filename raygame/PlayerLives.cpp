#include "PlayerLives.h"
#include"SpriteComponent.h"
#include "Transform2D.h"

void PlayerLives::start()
{
	Actor::start();
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/player.png")));
}

void PlayerLives::update(float deltaTime)
{
	Actor::update(deltaTime);
	getTransform()->setForward(MathLibrary::Vector2(0, -1));
}
