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


	//Creats a new Vector2 using the input taken from the input componet
	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	//player rotation
	if (m_moveComponent->getVelocity().getMagnitude() > 0)
		getTransform()->setForward(m_moveComponent->getVelocity());
	
	//Sets the move componet volocity
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

	//If actors name is "RingAroundUpgrade" . . .
	if (actor->getName() == "RingAroundUpgrade")
	{
		//. . . destroy this actor 
		Engine::destroy(actor);
		
		//creata new Rotation Actor and attach it to this actor
		m_rotate = new RotationActor(this);

		//Add "m_rotate" to the scene
		Engine::getCurrentScene()->addActor(m_rotate);

		//create a new ring Ring Around and then attach it to m_rotate
		m_upgrade = new RingAround(m_rotate, "RingAround");
		
		//Add "m_upgrade" to the scene
		Engine::getCurrentScene()->addActor(m_upgrade);

		//Update upgradeCount by one
		m_upgradeCount++;
	}

	//If actors Name is "ShieldUpgrade". . . 
	if (actor->getName() == "ShieldUpgrade")
	{
		//removes the actor off collision
		Engine::destroy(actor);
		//if their is no sheild 
		if (m_shield == nullptr)
		{
			//Adds a sheild to the player
			m_shield = new Shield(this, "Shield");

			//Adds shield 
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
			//Rests deltaTimer For effect
			Engine::setDeltaTimer(0);
			Engine::getCurrentScene()->removeActor(this);
			//Displays the game over text
			UIText* End = new UIText(10, 300, "Score", "GameOver", 20, 20, 100, RAYWHITE);
			Engine::getCurrentScene()->addUIElement(End);
		}
		else
			//decrements the player lives
			m_lives--;
	}


}



