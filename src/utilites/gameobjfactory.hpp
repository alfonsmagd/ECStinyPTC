#pragma once

#include <game/cmp/collider.hpp>
#include <game/cmp/render.hpp>
#include <game/cmp/physics.hpp>
#include <game/cmp/spawner.hpp>
#include <ecs/man/entitymanager.hpp>
#include <string_view>

//Voy a usar forward declaration para implementar, ya que no necesito conocer ninguna propiedd interna de las clases
//EntityManager_t ni Enity para evitar que se confunda el compilador , entre si es un struct dentro de otro struct 
//o si es un namespace, usar nameSpace

namespace ECS{
struct EntityManager_t;
struct Entity_t;
}

struct GameObjectFactory_t{

    explicit GameObjectFactory_t(ECS::EntityManager_t& EntityMan) : m_EntManager(EntityMan){}

    ECS::Entity_t& createEntity(uint32_t x, uint32_t y,   const std::string_view filename) const;
    ECS::Entity_t& createPlayer(uint32_t x, uint32_t y) const;
    ECS::Entity_t& createFire( uint32_t x, uint32_t y,   const std::string_view filename) const;

    template <typename CALLABLE_t>
    ECS::Entity_t& createSpawner( uint32_t x, uint32_t y, CALLABLE_t callback) const {

		auto& e = m_EntManager.createEntity();
		auto&rn = m_EntManager.addComponent<RenderComponent_t>(e);
		auto& spw = m_EntManager.addComponent<SpawnComponent_t>(e);
		auto& phy = m_EntManager.addComponent<PhysicsComponent_t>(e);
		rn.loadFromFile("assets/rsz_d.png");
		m_EntManager.addComponent<ColliderComponent_t>(e);

		phy.y = y;
		phy.x = x;
		phy.vy = 1;
		phy.vx = 0;

		spw.spawnMethod = callback;
		//No se puede hacer un delegado a un lambda si hay capturas. usar functional. 
	
        return e;
}


    private:
    ECS::EntityManager_t& m_EntManager;

};