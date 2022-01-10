#include "PlayerLifeComponent.h"
#include "Engine.h"
#include "PlayerLives.h"
#include "Transform2D.h"

void PlayerLifeComponent::start()
{
	Component::start();

	life1 = new PlayerLives(185, 770, "Life1");
	life2 = new PlayerLives(230, 770, "Life2");
	life3 = new PlayerLives(280, 770, "Life3");

	life1->getTransform()->setScale({ 50,50 });
	life2->getTransform()->setScale({ 50,50 });
	life3->getTransform()->setScale({ 50,50 });

	Engine::getCurrentScene()->addActor(life1);
	Engine::getCurrentScene()->addActor(life2);
	Engine::getCurrentScene()->addActor(life3);

}

void PlayerLifeComponent::removeLife1()
{
	Engine::getCurrentScene()->removeActor(life1);
}

void PlayerLifeComponent::removeLife2()
{
	Engine::getCurrentScene()->removeActor(life2);
}

void PlayerLifeComponent::removeLife3()
{
	Engine::getCurrentScene()->removeActor(life3);
}

