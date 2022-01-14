#include "Shield.h"
#include "Transform2D.h"
#include "Engine.h"
#include "SpriteComponent.h"
#include "CircleCollider.h"

Shield::Shield(Actor* owner, const char* name)
{
	m_owner = owner;
	getTransform()->setScale({ 150,150 });
	CircleCollider* circleCollider = new CircleCollider({ 75, this });
	this->setCollider(circleCollider);
	setName(name);
}

void Shield::start()
{
	Actor::start();
	m_spriteComp = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/bubble.png")));
	//Gets The Owner Starting Location
	getTransform()->setWorldPostion(m_owner->getTransform()->getWorldPosition());
}

void Shield::update(float deltaTime)
{
	Actor::update(deltaTime);
	//Fallows The Owner Location
	getTransform()->setWorldPostion(m_owner->getTransform()->getWorldPosition());

	//Rotates 
	m_timer += deltaTime;
	getTransform()->setRotation(-m_timer);
}

/// <summary>
/// If the actor collides with an enemy
/// </summary>
/// <param name="actor"></param>
void Shield::onCollision(Actor* actor)
{
	//if the actor is named "enemyBullet". . .
	if (actor->getName() == "enemyBullet")
	{
		//destroy the actor
		Engine::destroy(actor);
		//destroy this actor
		Engine::destroy(this);
	}
}
