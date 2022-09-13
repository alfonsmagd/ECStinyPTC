#include "gameobjfactory.hpp"
#include <game/cmp/collider.hpp>
#include <game/cmp/render.hpp>
#include <game/cmp/physics.hpp>
#include <game/cmp/spawner.hpp>
#include <ecs/man/entitymanager.hpp>



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
		auto& enemy = createEntity(x,y,"assets/rsz_d.png");
        return enemy;
}

ECS::Entity_t&
GameObjectFactory_t:: createSpawner( uint32_t x, uint32_t y) const {

		auto& e = m_EntManager.createEntity();
		auto&rn = m_EntManager.addComponent<RenderComponent_t>(e);
		auto& spw = m_EntManager.addComponent<SpawnComponent_t>(e);
		auto& phy = m_EntManager.addComponent<PhysicsComponent_t>(e);
		auto& coll = m_EntManager.addComponent<ColliderComponent_t>(e);
		rn.loadFromFile("assets/rsz_d.png");
		m_EntManager.addComponent<ColliderComponent_t>(e);

		
		phy.y = y;
		phy.x = x;
		phy.vy = 1;
		phy.vx = 0;
			//coll.box.xLeft = 10;
	//coll.box.xRight= rn.w -30;
	//coll.box.yUp  = 10;
	//coll.box.yDown = rn.h;

		
		//No se puede hacer un delegado a un lambda si hay capturas. usar functional. 
		spw.spawnMethod = [&](const SpawnComponent_t& spwncomponent){

			auto* e_spwaner = m_EntManager.getEntitybyID(spwncomponent.getEntityID());
			
			if(!e_spwaner)return;
			auto* phy = e_spwaner->getComponent<PhysicsComponent_t>();
			if(!phy)return;
			[[maybe_unused]]auto& e = createFire(phy->x,phy->y,"assets/rsz_d.png");
		};
		
        return e;
}
