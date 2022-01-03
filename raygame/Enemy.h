#pragma once
#include "Actor.h"

class SpriteComponent;
class MoveComponent;
class Bullet;

class Enemy :
    public Actor
{
public:
    Enemy() {};
    ~Enemy() { };
    Enemy(float x, float y, int maxSpeed, const char* name = "Enemy");
    
    void start() override;
    
private:
    int m_maxSpeed; 
    SpriteComponent* m_sprite;
    MoveComponent* m_movement;
    Bullet* m_bullets;

};

