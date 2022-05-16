#include "tinyPTC/src/tinyptc.h"
#include <iostream>
#include <memory>
#include <sys/render.hpp>
#include <man/entitymanager.hpp>

typedef u_int32_t uint32_t;

const uint32_t KSCRWEIGHT {640};
const uint32_t KSCRHEIGHT {360} ;

int main(){
	
  try{

	ECS::EntityManager_t EntityMan;
	EntityMan.createEntity(40,49,16,16,0x00FF0000);
	EntityMan.createEntity(0,0,34,34,0x000000FF);
	
	const ECS::RenderSystem_t Render(KSCRWEIGHT,KSCRHEIGHT,EntityMan);

		while(Render.update());
	}
	catch(...){
		std::cout << "not execute error \n";
	}

	return 0 ; 
}