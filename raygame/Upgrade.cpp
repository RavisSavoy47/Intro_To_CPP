#include "Upgrade.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "CircleCollider.h"
#include "Transform2D.h"
#include "Engine.h"

Upgrade::Upgrade(float x, float y, int maxSpeed, const char* path, const char* name) : Actor::Actor(x, y, name)
{
	// Componet that handles the actors movement
	m_moveComp = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));

	//Creats an image on the screen for the user to visualize 
	m_spriteComp = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent(path)));

	//Sests the scale for this actor 
	getTransform()->setScale({ 25,25 });

	//Creats a collider for this actor 
	CircleCollider* circleCollider = new CircleCollider({ 30, this });
	this->setCollider(circleCollider);

	//Sets the max speed 
	m_maxSpeed = maxSpeed;
}

void Upgrade::start()
{
	//base start
	Actor::start();

	//Creaing a the direction the actor will be facing 
	MathLibrary::Vector2 moveDirection = MathLibrary::Vector2(0, 1);
	getTransform()->setForward(moveDirection);
	//Sets the move componet to be set by the direction and the speed of this actor
	m_moveComp->setVelocity(moveDirection * m_maxSpeed);
}

void Upgrade::update(float deltaTime)
{
	//base actor update
	Actor::update(deltaTime);
	//every update add delta time to the timer
	m_timer += deltaTime;
	//Update the rasians of this transform bt the timer
	getTransform()->setRotation(m_timer);
	//If the timer reaches 10 seconds
	if (m_timer >= 10.0f)
		//distroy this actor
		Engine::destroy(this);
}