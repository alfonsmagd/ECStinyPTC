#include "gameobjfactory.hpp"




ECS::Entity_t&
GameObjectFactory_t::createEntity( uint32_t x, uint32_t y,   const std::string_view filename) const {

	auto& e = m_EntManager.createEntity();
	auto& ph = m_EntManager.addComponent<PhysicsComponent_t>(e);
	auto& rn = m_EntManager.addComponent<RenderComponent_t>(e);
	auto& cll = m_EntManager.addComponent<ColliderComponent_t>(e);

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


ECS::Entity_t&
GameObjectFactory_t::createPlayer (uint32_t x, uint32_t y)const {
	auto& e_player = createEntity(x,y,"assets/run-2.png");
	m_EntManager.addComponent<InputComponent_t>(e_player);
    return e_player;
}

ECS::Entity_t&
GameObjectFactory_t::createFire(uint32_t x, uint32_t y,   const std::string_view filename) const{
		auto& enemy = createEntity(x,y,filename);
        return enemy;
}


