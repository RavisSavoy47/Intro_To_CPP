#pragma once
#include "Component.h"
class  Enemy;
class EnemySpawnComponent :
    public Component
{
public:
    void start() override;
    void update(float deltaTime) override;

private:
    void DupilcateEnemies(float deltaTime);

private:
    Enemy* m_enemy;


};

