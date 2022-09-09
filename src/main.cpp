#include "tinyPTC/src/tinyptc.h"
#include <iostream>
#include <memory>
#include <game/sys/input.tpp>
#include <game/sys/render.tpp>
#include <game/sys/physics.tpp>
#include <game/sys/collision.tpp>
#include <game/sys/spawner.tpp>
#include <ecs/man/entitymanager.hpp>

typedef u_int32_t uint32_t;

const uint32_t KSCRWEIGHT {1080};
const uint32_t KSCRHEIGHT {360} ;


ECS::Entity_t&
createEntity(ECS::EntityManager_t& EntityMan, uint32_t x, uint32_t y,   const std::string_view filename){

	auto& e = EntityMan.createEntity();
	auto& ph = EntityMan.addComponent<PhysicsComponent_t>(e);
	auto& rn = EntityMan.addComponent<RenderComponent_t>(e);
	auto& cll = EntityMan.addComponent<ColliderComponent_t>(e);

	//Render component 
	rn.loadFromFile(filename);
	
	ph.x = x;
	ph.y = y; 
	//Colliders relativos al objeto Xo = 0; Yo = 0 ; son los del entity no el absoluto de la pantalla 
	cll.box.xLeft = 10;
	cll.box.xRight= rn.w -30;
	cll.box.yUp  = 10;
	cll.box.yDown = rn.h;

	return e;

}

void
createPlayer(ECS::EntityManager_t& EntityMan, uint32_t x, uint32_t y){
	auto& e_player = createEntity(EntityMan,x,y,"assets/run-2.png");
	EntityMan.addComponent<InputComponent_t>(e_player);
}

void
createFire(ECS::EntityManager_t& EntityMan, uint32_t x, uint32_t y,   const std::string_view filename){
		auto& enemy = createEntity(EntityMan,x,y,"assets/rsz_d.png");
}

void 
createSpawner(ECS::EntityManager_t& EntityMan, uint32_t x, uint32_t y){

		auto& e = EntityMan.createEntity();
		auto& phy = EntityMan.addComponent<PhysicsComponent_t>(e);
		auto& spw = EntityMan.addComponent<SpawnComponent_t>(e);

		spw.spawnerPosition.xSpanw = x;
		spw.spawnerPosition.ySpwan = y;
		
		phy.x = spw.spawnerPosition.xSpanw;
		phy.y = spw.spawnerPosition.ySpwan;
		phy.vx = 0;
		phy.vy = 0;
}




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


	createFire(EntityMan,50,50,"assets/pica1.png");
	createPlayer(EntityMan,1,1);
	createSpawner(EntityMan,10,10);
	
	
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