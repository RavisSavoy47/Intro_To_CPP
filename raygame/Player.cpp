#include "Player.h"
#include "InputComponent.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "InputShotComponent.h"
#include "RotationActor.h"
#include "Shield.h"
#include "CircleCollider.h"
#include "RingAround.h"
#include "PlayerLifeComponent.h"
#include <iostream>
#include "Engine.h"

void Player::start()
{
	//Calls the original Actor start 
	Actor::start();

	//Initialze default values
	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	m_moveComponent = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/player.png")));
	m_shots = dynamic_cast<InputShotComponent*>(addComponent(new InputShotComponent("playerBullet")));
	m_playerLife = dynamic_cast<PlayerLifeComponent*>(addComponent(new PlayerLifeComponent()));
	//Assignes owner to be this actor 
	m_shots->assignOwner(this);

	CircleCollider* circleCollider = new CircleCollider({ 30, this });
	this->setCollider(circleCollider);

	getTransform()->setScale({ 50,50 });

	m_lives = 3;

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
		getTransform()->setForward(m_moveComponent->getVelocity());

	m_moveComponent->setVelocity(moveDirection.getNormalized() * 1000);

	if (m_lives <= 0)
		Engine::CloseApplication();
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
		std::cout << "collision" << std::endl;
		//Engine::getCurrentScene()->removeActor(actor);
	}
	if (actor->getName() == "RingAroundUpgrade")
	{
		Engine::destroy(actor);
		m_rotate = new RotationActor(this);
		Engine::getCurrentScene()->addActor(m_rotate);

		m_upgrade = new RingAround(m_rotate, "RingAround");
		Engine::getCurrentScene()->addActor(m_upgrade);

		m_upgradeCount++;
	}
	if (actor->getName() == "ShieldUpgrade")
	{
		Engine::destroy(actor);
		if (m_shield == nullptr)
		{
			m_shield = new Shield(this, "Shield");
			Engine::getCurrentScene()->addActor(m_shield);
		}
	}
	if (actor->getName() == "enemyBullet")
	{
		Engine::destroy(actor);
		m_shield = nullptr;
		
		if (m_lives <= 3)
		{
			m_playerLife->removeLife3();
		}
		if (m_lives <= 2)
		{
			m_playerLife->removeLife2();
		}
		if (m_lives <= 1)
		{
			m_playerLife->removeLife1();
		}
		else
			m_lives--;
	}


}



