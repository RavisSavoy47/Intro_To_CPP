#pragma once
#include "Actor.h"

class MoveComponent;
class SpriteComponent;
class AutoShotComponent;

class RingAround :
    public Actor
{
public:
    RingAround(Actor* owner, const char* name);
    void start() override;
    void update(float deltaTime) override;
    void onCollision(Actor* actor) override;

private:
    MoveComponent* m_moveComp;
    SpriteComponent* m_spriteComp;
    AutoShotComponent* m_autoShotComp;

    Actor* m_owner;

    float m_timer;
};

