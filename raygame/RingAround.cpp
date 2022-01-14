#include "RingAround.h"
#include "SpriteComponent.h"
#include "AutoShotComponent.h"
#include "Transform2D.h"

RingAround::RingAround(Actor* owner, const char* name)
{
	owner->getTransform()->addChild(getTransform());
	getTransform()->setScale({ 30,30 });
	setName(name);
}

/// <summary>
/// Gives the actor assecess to spirte component and autoShot component
/// </summary>
void RingAround::start()
{
	Actor::start();
	m_spriteComp = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/Nebula.png")));
	m_autoShotComp = dynamic_cast<AutoShotComponent*>(addComponent(new AutoShotComponent("playerBullet")));

	//Sets the scale
	getTransform()->setLocalPosition({ 1,1 });

}

void RingAround::update(float deltaTime)
{
	Actor::update(deltaTime);
	/// <summary>
	/// Updates the rotation based on the timer
	/// </summary>
	/// <param name="deltaTime"></param>
	m_timer += deltaTime;
	getTransform()->setRotation(m_timer * -1000);
}

void RingAround::onCollision(Actor* actor)
{
}
