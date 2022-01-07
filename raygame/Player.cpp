#include "Player.h"
#include "InputComponent.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "CircleCollider.h"
#include <iostream>
#include "Engine.h"

void Player::start()
{
	Actor::start();

	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	m_moveComponent = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_moveComponent->setMaxSpeed(100);
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/player.png")));

	m_maxLives = 30;

	getTransform()->setScale({ 50,50 });


	//Set spawn point 
	//Set move speed
	//Set position clamps(boundies)
}

void Player::update(float deltaTime)
{
	Actor::update(deltaTime);

	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	//If their lives equal zero
	if (m_maxLives <= 0)
	{
		//removes the player from the scene
		Engine::getCurrentScene()->removeActor(this);
		Engine::CloseApplication();
	}

	//player rotation
	if (m_moveComponent->getVelocity().getMagnitude() > 0)
		getTransform()->setForward(m_moveComponent->getVelocity());

	m_moveComponent->setVelocity(moveDirection.getNormalized() * 500);

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
		m_maxLives--;
	}
}



