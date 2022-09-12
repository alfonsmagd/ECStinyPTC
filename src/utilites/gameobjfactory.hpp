#pragma once

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
    ECS::Entity_t& createSpawner( uint32_t x, uint32_t y)const;


    private:
    ECS::EntityManager_t& m_EntManager;

};