#include "MainScene.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemySpawner.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "UIText.h"
#include "CircleCollider.h"
#include "PlayerLives.h"

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

    Enemy* enemy2 = new Enemy(300, 1, 100);
    addActor(enemy2);

    CircleCollider* enemy2collider = new CircleCollider(30, enemy2);
    enemy2->setCollider(enemy2collider);

    /*EnemySpawner* spawner = new EnemySpawner();
    addActor(spawner);*/

    //strint
    UIText* UI = new UIText(600, 10, "Health", "Lives", 20, 20, 50, RAYWHITE);
    addUIElement(UI);

    PlayerLives* life1 = new PlayerLives(185, 770, "Life1");
    PlayerLives* life2 = new PlayerLives(230, 770, "Life2");
    PlayerLives* life3 = new PlayerLives(280, 770, "Life3");

    life1->getTransform()->setScale({ 50,50 });
    life2->getTransform()->setScale({ 50,50 });
    life3->getTransform()->setScale({ 50,50 });

    addActor(life1);
    addActor(life2);
    addActor(life3);
}