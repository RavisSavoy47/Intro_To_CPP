#include "RotationActor.h"
#include "Transform2D.h"
#include "SpriteComponent.h"

RotationActor::RotationActor(Actor* owner)
{
	m_owner = owner;
	getTransform()->setScale({ 50,50 });
}

void RotationActor::start()
{
	Actor::start();
	getTransform()->setWorldPostion(m_owner->getTransform()->getWorldPosition());
	
}

void RotationActor::update(float deltaTime)
{
	Actor::update(deltaTime);
	getTransform()->setWorldPostion(m_owner->getTransform()->getWorldPosition());
	m_timer += deltaTime;
	getTransform()->setRotation(m_timer);
	
}
