#include "MainScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Spawner.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "UIText.h"
#include "CircleCollider.h"
#include "PlayerLives.h"
#include "ScoreManager.h"

void MainScene::start()
{
    Player* player = new Player(100, 400, "Player");
    addActor(player);

    CircleCollider* playercollider = new CircleCollider(30, player);
    player->setCollider(playercollider);

    Enemy* enemy = new Enemy(200, 1, 1);
    addActor(enemy);

    CircleCollider* enemycollider = new CircleCollider(30, enemy);
    enemy->setCollider(enemycollider);

    /*EnemySpawner* spawner = new EnemySpawner();
    addActor(spawner);*/

    //strint
    UIText* UI = new UIText(10, 900, "Health", "Lives", 20, 20, 40, RAYWHITE);
    addUIElement(UI);

    UIText* CurrentScore = new UIText(450, 10, "CurrentScore", "Score", 20, 20, 40, RAYWHITE);
    addUIElement(CurrentScore);

    UIText* UIScore = new UIText(650, 10, "Score", "Score", 20, 20, 40, RAYWHITE);
    

    ScoreManager* ScoreDisplay = new ScoreManager(350, 900, "Score");
    ScoreDisplay->setUIText(UIScore);
    enemy->setScoreManager(ScoreDisplay);
    enemy2->setScoreManager(ScoreDisplay);
    addActor(ScoreDisplay);

}