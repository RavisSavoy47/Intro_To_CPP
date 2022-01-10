#pragma once
#include "Actor.h"

class MoveComponent;
class SpriteComponent;
class Actor;

class Bullet :
    public Actor
{
public:
    Bullet(float maxSpeed, Actor* owner, const char* name);

    void start() override;
    void update(float deltaTime) override;

private:
    MoveComponent* m_moveComp;
    SpriteComponent* m_spriteComp;

    float m_maxSpeed;
    Actor* m_owner;

    float m_timer;

};

