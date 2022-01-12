#include "RotationActor.h"
#include "Transform2D.h"

RotationActor::RotationActor(Actor* owner)
{
	m_owner = owner;
	getTransform()->setScale({ 50,50 });
}

void RotationActor::start()
{
	Actor::start();
	//Gets The Owner Starting Location
	getTransform()->setWorldPostion(m_owner->getTransform()->getWorldPosition());
	
}

void RotationActor::update(float deltaTime)
{
	Actor::update(deltaTime);
	//Fallows The Owner Location
	getTransform()->setWorldPostion(m_owner->getTransform()->getWorldPosition());
	
	//Rotates 
	m_timer += deltaTime;
	getTransform()->setRotation(m_timer);
	
}
