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
    //Spawns Enemies at a time at a location
    void DupilcateEnemies(float deltaTime);
    
    //Spawns Upgrades at a timer at a location
    void DupilcateUpgrades(float deltaTime);

    

private:
    Enemy* m_enemy;
    Upgrade* m_upgrade;

    //timer in between spawns 
    float m_timer;

    //The tag of the spawner 
    char m_choice;
};

