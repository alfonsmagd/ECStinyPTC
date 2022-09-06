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
	auto& cll = EntityMan.addComponent<ColliderComponent_t>(e);

	//Render component 
	rn.loadFromFile(filename);
	
	ph.x = x;
	ph.y = y; 
	//Colliders relativos al objeto Xo = 0; Yo = 0 ; son los del entity no el absoluto de la pantalla 
	cll.box.xLeft = 0;
	cll.box.xRight= rn.w;
	cll.box.yUp  = 0;
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
		createEntity(EntityMan,x,y,"assets/rsz_d.png");
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


	createFire(EntityMan,50,50,"assets/pica1.png");
	createPlayer(EntityMan,1,1);
	
	
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