#include "Enemy.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "AutoShotComponent.h"
#include "ScoreComponent.h"
#include "Transform2D.h"
#include "Engine.h"
#include "CircleCollider.h"
#include <iostream>
#include "UIText.h"
#include "ScoreManager.h"

Enemy::Enemy(float x, float y, int maxSpeed, const char* name) : Actor::Actor(x, y, name)
{
	//Attaches movement to the actor
	m_movement = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	//attcehs a png to the location of this actor 
	m_sprite = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/enemy.png")));

	//attaches an automatic shooting to the actor
	m_shotComp = dynamic_cast<AutoShotComponent*>(addComponent(new AutoShotComponent("enemyBullet")));
	m_shotComp->assignOwner(this);

	//sets the enemy scale
	getTransform()->setScale({ 50,50 });

	CircleCollider* circleCollider = new CircleCollider({ 30, this });
	this->setCollider(circleCollider);

	m_maxSpeed = maxSpeed;
}

/// <summary>
/// How the enemy moves off start
/// </summary>
void Enemy::start()
{
	Actor::start();

	MathLibrary::Vector2 moveDirection = MathLibrary::Vector2(0, 1);
	getTransform()->setForward(moveDirection);
	m_movement->setVelocity(moveDirection * m_maxSpeed);

	m_timer = 0;
}
/// <summary>
/// Updates its timer and sets a time to destory the actor 
/// </summary>
/// <param name="deltaTime"></param>
void Enemy::update(float deltaTime)
{
	Actor::update(deltaTime);
	m_timer += deltaTime;
	if (m_timer >= 5.0f)
		Engine::destroy(this);
}
	
/// <summary>
/// when the actor collides with another actor
/// </summary>
/// <param name="actor"></param>
void Enemy::onCollision(Actor* actor)
{
	/// <summary>
	/// Every time the enemy collies with a player
	/// </summary>
	/// <param name="actor"></param>
	if (actor->getName() == "Player")
	{
		std::cout << "collision" << std::endl;
	}
	/// <summary>
	/// Every time the enemy collies with a player's bullet
	/// </summary>
	/// <param name="actor"></param>
	if (actor->getName() == "playerBullet")
	{
		//Deletes the enemy and adds the score
 		ScoreManager::Score += 10;
		Engine::destroy(this);
	}
}



