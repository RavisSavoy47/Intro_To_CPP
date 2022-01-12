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
#include "UIText.h"
#include "raylib.h"

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
}

/// <summary>
/// When the collides with another actor
/// </summary>
/// <param name="actor"></param>
void Player::onCollision(Actor* actor)
{
	/// <summary>
	/// when the player collides with an enemy
	/// </summary>
	/// <param name="actor"></param>
	if (actor->getName() == "Enemy")
	{
		//Displays collision when they collide with enemy
		std::cout << "collision" << std::endl;
	}

	/// <summary>
	/// Attaches the upgrabes to the player and removes the upgrade
	/// </summary>
	/// <param name="actor"></param>
	if (actor->getName() == "RingAroundUpgrade")
	{
		Engine::destroy(actor);
		m_rotate = new RotationActor(this);
		Engine::getCurrentScene()->addActor(m_rotate);

		m_upgrade = new RingAround(m_rotate, "RingAround");
		Engine::getCurrentScene()->addActor(m_upgrade);

		m_upgradeCount++;
	}

	/// <summary>
	/// Adds a shield to the player when the player collides to the actor
	/// </summary>
	/// <param name="actor"></param>
	if (actor->getName() == "ShieldUpgrade")
	{
		//removes the actor off collision
		Engine::destroy(actor);
		//if their is no sheild 
		if (m_shield == nullptr)
		{
			//Adds a sheild to the player
			m_shield = new Shield(this, "Shield");
			Engine::getCurrentScene()->addActor(m_shield);
		}
	}

	/// <summary>
	/// When the player collides with the enemy's bullet 
	/// </summary>
	/// <param name="actor"></param>
	if (actor->getName() == "enemyBullet")
	{
		//removes the enemy bullet
		Engine::destroy(actor);
		m_shield = nullptr;
		
		//checks the plays health 
		if (m_lives <= 3)
		{
			//removes the player life sprite
			m_playerLife->removeLife3();
		}
		//checks the plays health 
		if (m_lives <= 2)
		{
			//removes the player life sprite
			m_playerLife->removeLife2();
		}
		//checks the plays health 
		if (m_lives <= 1)
		{
			//removes the player life sprite
			m_playerLife->removeLife1();
		}
		//checks the plays health 
		if (m_lives <= 0)
		{
			Engine::setDeltaTimer(0);
			//Displays the game over text
			UIText* End = new UIText(10, 300, "Score", "GameOver", 20, 20, 100, RAYWHITE);
			Engine::getCurrentScene()->addUIElement(End);
		}
		else
			//decrements the player lives
			m_lives--;
	}


}



