#include "PracticeScene.h"
#include "Transform2D.h"
#include "Enemy.h"
#include "Player.h"
#include "Spawner.h"
#include "RingAround.h"
#include "RotationActor.h"
#include "Actor.h"

void PracticeScene::start()
{ 
	Player* player = new Player(350, 900, "Player");	
	player->getTransform()->setForward({ 0,-1 });
	addActor(player);

	//Enemy* enemy = new Enemy(500, 200, 110);
	//addActor(enemy);

	Spawner * spawner = new Spawner();
	addActor(spawner);

	

}


