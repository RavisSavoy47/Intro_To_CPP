#include "Bullet.h"
#include "Transform2D.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "CircleCollider.h"
#include "Engine.h"

Bullet::Bullet(float maxSpeed, Actor* owner, const char* name = "Bullet") : Actor::Actor(0, 0, name)
{
	//Sets the scale
	getTransform()->setScale({ 50,50 });
	//Gets the actors owner
	getTransform()->setWorldPostion(owner->getTransform()->getWorldPosition());

	CircleCollider* circleCollider = new CircleCollider({ 30, this });
	this->setCollider(circleCollider);

	m_owner = owner;
	m_maxSpeed = maxSpeed;
}

void Bullet::start() 
{
	Actor::start();

	/// <summary>
	/// Gives the bullet asseces to the move component and a sprite component
	/// </summary>
	m_moveComp = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_spriteComp = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/bullet.png")));
	
	/// <summary>
	/// Sets the the movement
	/// </summary>
	MathLibrary::Vector2 moveDirection = m_owner->getTransform()->getForward();
	m_moveComp->setVelocity(moveDirection * m_maxSpeed);
}

void Bullet::update(float deltaTime)
{
	Actor::update(deltaTime);
	/// <summary>
	/// destorys the bullet after a certain time
	/// </summary>
	/// <param name="deltaTime"></param>
	m_timer += deltaTime;
	if (m_timer >= 5.0f)
		Engine::destroy(this);
}
