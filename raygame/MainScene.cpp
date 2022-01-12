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
    Player* player = new Player(350, 900, "Player");
    player->getTransform()->setForward({ 0,-1 });
    addActor(player);

    Spawner* spawner = new Spawner();
    addActor(spawner);

    UIText* UI = new UIText(10, 900, "Health", "Lives", 20, 20, 40, RAYWHITE);
    addUIElement(UI);

    UIText* CurrentScore = new UIText(450, 10, "CurrentScore", "Score", 20, 20, 40, RAYWHITE);
    addUIElement(CurrentScore);

    UIText* UIScore = new UIText(600, 10, "Score", "Score", 20, 20, 40, RAYWHITE);
    

    ScoreManager* ScoreDisplay = new ScoreManager(350, 900, "Score");
    ScoreDisplay->setUIText(UIScore);
    addActor(ScoreDisplay);
    
}