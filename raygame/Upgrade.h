#pragma once
#include "Actor.h"

class SpriteComponent;
class MoveComponent;

class Upgrade :
    public Actor
{
public:
    Upgrade() : Actor::Actor(0, 0, "defult") {};
    Upgrade(float x, float y, int maxSpeed, const char* name);
    void start() override;
    void update(float deltaTime) override;

private:
    SpriteComponent* m_spriteComp;
    MoveComponent* m_moveComp;
    
    float m_timer;
    float m_maxSpeed;
};

