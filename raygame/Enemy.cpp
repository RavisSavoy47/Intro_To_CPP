#include "Enemy.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Engine.h"
#include "CircleCollider.h"

#include <iostream>

Enemy::Enemy(float x, float y, int maxSpeed, const char* name) : Actor::Actor(x, y, name)
{
	m_movement = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_sprite = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/enemy.png")));

	getTransform()->setScale({ 50,50 });

	m_maxSpeed = maxSpeed;
}

void Enemy::start()
{
	MathLibrary::Vector2 moveDirection = MathLibrary::Vector2(0, 1);
	getTransform()->setForward(moveDirection);
	m_movement->setVelocity(moveDirection * m_maxSpeed);

	m_timer = 0;
}

void Enemy::draw()
{
	Actor::draw();
	getCollider()->draw();
}

void Enemy::onCollision(Actor* actor)
{
	if (actor->getName() == "Player")
	{
		std::cout << "collision" << std::endl;
		getTransform()->setLocalPosition(MathLibrary::Vector2(100, 1));
	}
}


