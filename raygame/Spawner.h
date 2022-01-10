#pragma once
#include "Actor.h"
class SpawnerComponent;

class Spawner :
    public Actor
{
public:
    void start() override;

private:
    SpawnerComponent* m_enemy;
    SpawnerComponent* m_upgrade;
};

