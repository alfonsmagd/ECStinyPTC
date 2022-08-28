#include "tinyPTC/src/tinyptc.h"
#include <iostream>
#include <memory>
#include <game/sys/input.tpp>
#include <game/sys/render.tpp>
#include <ecs/man/entitymanager.hpp>
#include <game/sys/physics.tpp>
#include <game/sys/collision.tpp>

typedef u_int32_t uint32_t;

const uint32_t KSCRWEIGHT {640};
const uint32_t KSCRHEIGHT {360} ;

int main(){
	
  try{

    const ECS::RenderSystem_t<ECS::EntityManager_t> Render(KSCRWEIGHT,KSCRHEIGHT);
	PhysicsSystem_t<ECS::EntityManager_t> PhySys;
	ECS::EntityManager_t EntityMan;
	ECS::CollisionSystem_t<ECS::EntityManager_t> ColliSys;
	
	EntityMan.createEntity(0,0,"assets/pica1.png");
	EntityMan.createEntity(222,0,"assets/run-1.png");
	auto& e_player = EntityMan.createEntity(0,0,"assets/run-2.png");
	//EntityMan.createEntity(0,0,34,34,0x000000FF);
	EntityMan.addInputController(e_player);
	
	
	InputSystem_t<ECS::EntityManager_t>   InputSys;
		while(Render.update(EntityMan)){

			 PhySys.update(EntityMan);
			 ColliSys.update(EntityMan);
			 InputSys.update(EntityMan);
		}
	}
	catch(...){
		std::cout << "not execute error \n";
	}

	return 0 ; 
}