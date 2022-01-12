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
    int m_maxSpeed; 
    SpriteComponent* m_sprite;
    MoveComponent* m_movement;
    AutoShotComponent* m_shotComp;
    ScoreManager* m_scoreManager;

    int m_score;

    float m_timer;

    float m_lives;
};

