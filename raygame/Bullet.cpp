#include "Bullet.h"
#include "Transform2D.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "Engine.h"

Bullet::Bullet(float x, float y, float maxSpeed, Actor owner, const char* name = "bullet") : Actor::Actor(x, y, name)
{
	getTransform()->setScale({ 50,50 });
	getTransform()->setForward(owner.getTransform()->getForward());
	
}

void Bullet::start() 
{
	Actor::start();

	m_moveComp = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_spriteComp = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/bullet.png")));
}

void Bullet::update(float deltaTime)
{
	Actor::update(deltaTime);
	m_timer += deltaTime;
	if (m_timer >= 5.0f)
		Engine::destroy(this);
}
