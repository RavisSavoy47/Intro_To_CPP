#pragma once
#include "Component.h"
class  Enemy;
class Upgrade;
class SpawnerComponent :
    public Component
{
public:
    SpawnerComponent(char spawn);
    void start() override;
    void update(float deltaTime) override;

private:
    void DupilcateEnemies(float deltaTime);
    void DupilcateUpgrades(float deltaTime);

    

private:
    Enemy* m_enemy;
    Upgrade* m_upgrade;

    float m_timer;
    float m_timeLimiter;

    char m_choice;
};

