#include "Upgrade.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "CircleCollider.h"
#include "Transform2D.h"
#include "Engine.h"

Upgrade::Upgrade(float x, float y, int maxSpeed, const char* path, const char* name) : Actor::Actor(x, y, name)
{

	m_moveComp = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_spriteComp = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent(path)));

	getTransform()->setScale({ 25,25 });

	CircleCollider* circleCollider = new CircleCollider({ 30, this });
	this->setCollider(circleCollider);

	m_maxSpeed = maxSpeed;
}

void Upgrade::start()
{
	Actor::start();

	MathLibrary::Vector2 moveDirection = MathLibrary::Vector2(0, 1);
	getTransform()->setForward(moveDirection);
	m_moveComp->setVelocity(moveDirection * m_maxSpeed);
}

void Upgrade::update(float deltaTime)
{
	Actor::update(deltaTime);
	m_timer += deltaTime;
	getTransform()->setRotation(m_timer);
	if (m_timer >= 10.0f)
		Engine::destroy(this);
}