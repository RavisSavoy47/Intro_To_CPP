#include "PlayerLives.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Engine.h"

void PlayerLives::start()
{
	Actor::start();

	m_spriteComp = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/player.png")));
	getTransform()->setScale({50, 50});
	getTransform()->setForward(MathLibrary::Vector2(0, -1));
}
