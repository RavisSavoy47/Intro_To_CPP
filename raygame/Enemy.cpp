#include "Enemy.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "AutoShotComponent.h"
#include "Transform2D.h"
#include "Engine.h"
#include "CircleCollider.h"
#include <iostream>

Enemy::Enemy(float x, float y, int maxSpeed, const char* name) : Actor::Actor(x, y, name)
{
	m_movement = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_sprite = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/enemy.png")));

	m_shotComp = dynamic_cast<AutoShotComponent*>(addComponent(new AutoShotComponent("EnemyBullet")));
	m_shotComp->assignOwner(this);

	getTransform()->setScale({ 50,50 });

	CircleCollider* circleCollider = new CircleCollider({ 30, this });
	this->setCollider(circleCollider);

	m_maxSpeed = maxSpeed;
}


void Enemy::start()
{
	Actor::start();

	MathLibrary::Vector2 moveDirection = MathLibrary::Vector2(0, 1);
	getTransform()->setForward(moveDirection);
	m_movement->setVelocity(moveDirection * m_maxSpeed);

	//Sets the amount of lives 
	m_lives = 3;

	m_timer = 0;
}

void Enemy::update(float deltaTime)
{
	Actor::draw();
	getCollider()->draw();
}
void Enemy::update(float deltaTime)
{
	Actor::update(deltaTime);

	//If their lives equal zero
	if (m_lives <= 0)
	{
		//removes the enemy from the scene
		Engine::getCurrentScene()->removeActor(this);
	}

	m_timer += deltaTime;
	if (m_timer >= 5.0f)
		Engine::destroy(this);
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
		std::cout << "Enemycollision" << std::endl;
		actor->getTransform()->setWorldPostion({ 50, 50 });
		m_lives--;
	}
}



