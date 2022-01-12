#pragma once
#include "Actor.h"

class SpriteComponent;
class MoveComponent;
class AutoShotComponent;
class ScoreManager;

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
    void setScoreManager(ScoreManager* manager) { m_scoreManager = manager; }
    
private:
    //Keeps track of the assigned speed 
    int m_maxSpeed; 
    //Illostrates the actor 
    SpriteComponent* m_sprite;
    //Dedicated for movemnt 
    MoveComponent* m_movement;
    //Componet created to automatically shot based of the users forwards 
    AutoShotComponent* m_shotComp;
    ScoreManager* m_scoreManager;

    //Keeps tabs on it's life cycle 
    float m_timer;

};

