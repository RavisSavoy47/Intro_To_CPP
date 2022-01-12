#pragma once
#include "Actor.h"
class SpriteComponent;

class Shield :
    public Actor
{
public:
    Shield(Actor* owner, const char* name);
    void start() override;
    void update(float deltaTime) override;
    void onCollision(Actor* actor) override;

private:
    SpriteComponent* m_spriteComp;
    Actor* m_owner;
    float m_timer;

};

