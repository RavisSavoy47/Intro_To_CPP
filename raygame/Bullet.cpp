#include "Bullet.h"
#include "Transform2D.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "Engine.h"

Bullet::Bullet(float maxSpeed, Actor* owner, const char* name) : Actor::Actor(0, 0, name)
{
	getTransform()->setScale({ 50,50 });
	getTransform()->setWorldPostion(owner->getTransform()->getWorldPosition());
	m_owner = owner;
	m_maxSpeed = maxSpeed;
}

void Bullet::start() 
{
	Actor::start();

	m_moveComp = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_spriteComp = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/bullet.png")));

	MathLibrary::Vector2 moveDirection = m_owner->getTransform()->getForward();

	m_moveComp->setVelocity(moveDirection * m_maxSpeed);
}

void Bullet::update(float deltaTime)
{
	Actor::update(deltaTime);
	m_timer += deltaTime;
	if (m_timer >= 5.0f)
		Engine::destroy(this);
}
