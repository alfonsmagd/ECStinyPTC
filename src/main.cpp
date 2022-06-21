#include "tinyPTC/src/tinyptc.h"
#include <iostream>
#include <memory>
#include <sys/render.hpp>
#include <man/entitymanager.hpp>
#include <sys/physics.hpp>
#include <sys/collision.hpp>

typedef u_int32_t uint32_t;

const uint32_t KSCRWEIGHT {640};
const uint32_t KSCRHEIGHT {360} ;

int main(){
	
  try{

	ECS::PhysicsSystem_t PhySys;
	ECS::EntityManager_t EntityMan;
	ECS::CollisionSystem_t ColliSys;
	EntityMan.createEntity(0,0,"assets/pica1.png");
	EntityMan.createEntity(222,0,"assets/run-1.png");
	EntityMan.createEntity(11,0,"assets/run-2.png");
	//EntityMan.createEntity(0,0,34,34,0x000000FF);
	
	
	const ECS::RenderSystem_t Render(KSCRWEIGHT,KSCRHEIGHT);

		while(Render.update(EntityMan)){
			PhySys.update(EntityMan);
			ColliSys.update(EntityMan);
		}
	}
	catch(...){
		std::cout << "not execute error \n";
	}

	return 0 ; 
}