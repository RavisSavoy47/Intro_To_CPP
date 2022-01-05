#pragma once
#include "Actor.h"

class MoveComponent;
class SpriteComponent;

class Bullet :
    public Actor
{
public:
    Bullet(float x, float y, float maxSpeed, Actor owner, const char* name = "Bullet");

    void start() override;
    void update(float deltaTime) override;

private:
    MoveComponent* m_moveComp;
    SpriteComponent* m_spriteComp;

    float m_timer;

};

