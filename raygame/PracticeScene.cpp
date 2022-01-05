#include "PracticeScene.h"
#include "Transform2D.h"
#include "Enemy.h"
#include "Player.h"
#include "EnemySpawner.h"

void PracticeScene::start()
{ 
	Player* player = new Player(50, 50, "Player");
	player->getTransform()->setScale({ 50, 50 });
	addActor(player);

	//Enemy* enemy = new Enemy(500, 200, 110);
	//addActor(enemy);

	EnemySpanner* spawner = new EnemySpanner();
	addActor(spawner);

	

}


