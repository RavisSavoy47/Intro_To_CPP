#include "MainScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Spawner.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "UIText.h"
#include "CircleCollider.h"
#include <iostream>
#include "string.h"

void MainScene::start()
{
    Player* player = new Player(100, 400, "Player");
    addActor(player);

    CircleCollider* playercollider = new CircleCollider(30, player);
    player->setCollider(playercollider);

    Enemy* enemy = new Enemy(200, 1, 100);
    addActor(enemy);

    CircleCollider* enemycollider = new CircleCollider(30, enemy);
    enemy->setCollider(enemycollider);

    /*EnemySpawner* spawner = new EnemySpawner();
    addActor(spawner);*/

    //strint
    UIText* UI = new UIText(600, 10, "Lives", "Lives", 20, 20, 75, RAYWHITE);
    addUIElement(UI);

}