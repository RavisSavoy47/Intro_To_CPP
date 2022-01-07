#pragma once
#include "Actor.h"

class SpriteComponent;
class MoveComponent;
class Bullet;

class Enemy :
    public Actor
{
public:
    //Defult Contructor 
    Enemy() : Actor::Actor(0, 0, "defult") {};
    //Defult DeConstructor 
    ~Enemy() { };
    //Enemies classifications at intitalization 
    Enemy(float x, float y, int maxSpeed, const char* name = "Enemy");
    
    void start() override;
    void update(float deltaTime) override;
    void draw() override;
    void onCollision(Actor* actor) override;

    
private:
    int m_maxSpeed; 
    SpriteComponent* m_sprite;
    MoveComponent* m_movement;
    Bullet* m_bullets;


    float m_maxLives;

    int m_timer;

};

