#include "RingAround.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "AutoShotComponent.h"
#include "Transform2D.h"

RingAround::RingAround(Actor* owner, const char* name)
{
	owner->getTransform()->addChild(getTransform());
	getTransform()->setScale({ 50,50 });
	setName(name);
}

void RingAround::start()
{
	Actor::start();
	m_spriteComp = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/Nebula.png")));
	m_moveComp = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_autoShotComp = dynamic_cast<AutoShotComponent*>(addComponent(new AutoShotComponent("PlayerBullets")));

	getTransform()->setLocalPosition({ 1,1 });

}

void RingAround::update(float deltaTime)
{
	Actor::update(deltaTime);
	m_timer += deltaTime;
	getTransform()->setRotation(m_timer);
}

void RingAround::onCollision(Actor* actor)
{
}