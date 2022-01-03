#pragma once
#include "Actor.h"
class EnemySpawnComponent;

class EnemySpawner :
    public Actor
{
public:
    void start() override;
    void update(float deltaTime) override;

private:
    EnemySpawnComponent* m_enemy;
};

