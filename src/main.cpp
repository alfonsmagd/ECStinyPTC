#include "tinyPTC/src/tinyptc.h"
#include <iostream>
#include <memory>
#include <game/sys/input.tpp>
#include <game/sys/render.tpp>
#include <game/sys/physics.tpp>
#include <game/sys/collision.tpp>
#include <ecs/man/entitymanager.hpp>

typedef u_int32_t uint32_t;

const uint32_t KSCRWEIGHT {640};
const uint32_t KSCRHEIGHT {360} ;


ECS::Entity_t&
createEntity(ECS::EntityManager_t& EntityMan, uint32_t x, uint32_t y,   const std::string_view filename){

auto& e = EntityMan.createEntity();
auto& ph = EntityMan.addComponent<PhysicsComponent_t>(e);
auto& rn = EntityMan.addComponent<RenderComponent_t>(e);

rn.loadFromFile(filename);
ph.x = x;
ph.y = y; 

return e;

}


int main(){
	
  try{

	//Systems
    const RenderSystem_t<ECS::EntityManager_t> Render(KSCRWEIGHT,KSCRHEIGHT);
	PhysicsSystem_t<ECS::EntityManager_t> PhySys;
	CollisionSystem_t<ECS::EntityManager_t> ColliSys;
	InputSystem_t<ECS::EntityManager_t>   InputSys;

	//Entities
	ECS::EntityManager_t EntityMan{};
	createEntity(EntityMan,0,0,"assets/pica1.png");
	createEntity(EntityMan,222,0,"assets/run-1.png");
	auto& e_player = createEntity(EntityMan,0,0,"assets/run-2.png");
	//EntityMan.createEntity(0,0,34,34,0x000000FF);
	EntityMan.addComponent<InputComponent_t>(e_player);
	
	
	
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