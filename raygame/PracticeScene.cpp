#include "PracticeScene.h"
#include "Transform2D.h"
#include "Enemy.h"

void PracticeScene::start()
{ 
	Enemy* enemy = new Enemy(1, 2);
	enemy->getTransform()->setScale({ 50, 50 });
	addActor(enemy);

}
