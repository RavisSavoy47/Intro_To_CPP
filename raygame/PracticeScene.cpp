#include "PracticeScene.h"
#include "Transform2D.h"
#include "Enemy.h"
#include "Player.h"
#include "EnemySpawner.h"
#include "RingAround.h"
#include "RotationActor.h"
#include "Actor.h"

void PracticeScene::start()
{ 
	Player* player = new Player(350, 900, "Player");
	player->getTransform()->setScale({ .055, .055 });
	player->getTransform()->setForward({ 0,-1 });
	addActor(player);

	//Enemy* enemy = new Enemy(500, 200, 110);
	//addActor(enemy);

	RotationActor* rotate = new RotationActor(player);
	addActor(rotate);

	RingAround* upgrade = new RingAround(rotate,"RingAround");
	addActor(upgrade);

	EnemySpanner* spawner = new EnemySpanner();
	addActor(spawner);

	

}


