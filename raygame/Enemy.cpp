#include "Enemy.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"

Enemy::Enemy(float x, float y, const char* name) : Actor::Actor(x, y, name)
{
	m_movement = dynamic_cast<MoveComponent*>(new MoveComponent());
	m_sprite = dynamic_cast<SpriteComponent*>(new SpriteComponent("Images/enemy.png"));
}

void Enemy::start()
{
}
