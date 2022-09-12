#include "tinyPTC/src/tinyptc.h"
#include <iostream>
#include <memory>
#include <game/sys/input.tpp>
#include <game/sys/render.tpp>
#include <game/sys/physics.tpp>
#include <game/sys/collision.tpp>
#include <game/sys/spawner.tpp>
#include <utilites/gameobjfactory.hpp>
#include <ecs/man/entitymanager.hpp>

typedef u_int32_t uint32_t;

const uint32_t KSCRWEIGHT {1080};
const uint32_t KSCRHEIGHT {360} ;


int main(){
	
  try{

	//Systems
    const RenderSystem_t<ECS::EntityManager_t> Render(KSCRWEIGHT,KSCRHEIGHT);
	PhysicsSystem_t<ECS::EntityManager_t> PhySys;
	CollisionSystem_t<ECS::EntityManager_t> ColliSys(KSCRHEIGHT,KSCRWEIGHT);
	InputSystem_t<ECS::EntityManager_t>   InputSys;
	SpawnerSystem_t<ECS::EntityManager_t> SpawnerSys;

	//Entities
	ECS::EntityManager_t EntityMan{};
	GameObjectFactory_t GameFactory{EntityMan};

	GameFactory.createFire(50,50,"assets/pica1.png");
	GameFactory.createPlayer(1,1);
	GameFactory.createSpawner(10,10);
	
	
		while(Render.update(EntityMan)){

			 PhySys.update(EntityMan);
			 ColliSys.update(EntityMan);
			 InputSys.update(EntityMan);
			 SpawnerSys.update(EntityMan);
		}
	}
	catch(...){
		std::cout << "not execute error \n";
	}

	return 0 ; 
}