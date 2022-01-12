#include "Player.h"
#include "InputComponent.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "InputShotComponent.h"
#include "CircleCollider.h"
#include <iostream>
#include "Engine.h"
#include "UIText.h"
#include "PlayerLives.h"
#include "PlayerLifeComponent.h"

void Player::start()
{
	Actor::start();
	
	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	m_moveComponent = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_moveComponent->setMaxSpeed(100);
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/player.png")));
	m_shots = dynamic_cast<InputShotComponent*>(addComponent(new InputShotComponent("playerBullet")));
	m_shots->assignOwner(this);
	CircleCollider* circleCollider = new CircleCollider({ 30, this });
	this->setCollider(circleCollider);
	m_playerLifeComponent = dynamic_cast<PlayerLifeComponent*>(addComponent(new PlayerLifeComponent()));

	m_lives = 3;

	getTransform()->setScale({ 50,50 });


	//Set spawn point 
	//Set move speed
	//Set position clamps(boundies)
}



void Player::update(float deltaTime)
{
	Actor::update(deltaTime);

	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	//player rotation
	if (m_moveComponent->getVelocity().getMagnitude() > 0)
	{
		getTransform()->setForward(m_moveComponent->getVelocity());
	}

	m_moveComponent->setVelocity(moveDirection.getNormalized() * 1000);

	//If their lives equal zero
	if (m_lives <= 0)
	{
		//removes the player from the scene
		//Engine::getCurrentScene()->removeActor(this);
		//Engine::CloseApplication();
	}
}

void Player::draw()
{
	Actor::draw();
	getCollider()->draw();
}

void Player::onCollision(Actor* actor)
{
	if (actor->getName() == "Enemy")
	{
		std::cout << "Playercollision" << std::endl;

		if (m_lives == 3)
		{
			m_playerLifeComponent->removeLife3();
		}
		if (m_lives == 2)
		{
			m_playerLifeComponent->removeLife2();
		}
		if (m_lives == 0)
		{
			m_playerLifeComponent->removeLife1();
		}
		else
			m_lives--;

	}
}






