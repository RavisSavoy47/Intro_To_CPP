#pragma once
#include "Actor.h"
class EnemySpawnComponent;

class EnemySpawner :
    public Actor
{
public:
    void start() override;

private:
    EnemySpawnComponent* m_enemy;
};

