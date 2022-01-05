#include "MainScene.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemySpawner.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "UIText.h"
#include "CircleCollider.h"

void MainScene::start()
{
    Player* player = new Player(50, 50, "Player");
    player->getTransform()->setScale({ 50, 50 });
    addActor(player);

    CircleCollider* playercollider = new CircleCollider(30, player);
    player->setCollider(playercollider);

    Enemy* enemy = new Enemy(100, 1, 100, "Enemy");
    addActor(enemy);

    CircleCollider* enemycollider = new CircleCollider(30, enemy);
    enemy->setCollider(enemycollider);

    /*EnemySpawner* spawner = new EnemySpawner();
    addActor(spawner);*/


    UIText* UI = new UIText(100, 1000, "Lives", "Lives", 20, 20, 75, RAYWHITE);
    addUIElement(UI);
}