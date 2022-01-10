#include "PlayerLives.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Engine.h"
#include "raylib.h"

void PlayerLives::start()
{
	Actor::start();
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/player.png")));
	getTransform()->setScale({ 50,50 });
	
}

void PlayerLives::update(float deltaTime)
{
	Actor::update(deltaTime);
	getTransform()->setForward(MathLibrary::Vector2(0, -1));
}
