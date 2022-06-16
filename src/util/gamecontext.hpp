#pragma once 
#include <cmp/entity.hpp>


//Esta interfaz va a ser pura y abstracta. 
namespace ECS {

    struct GameContext_t {
        
        virtual ~GameContext_t() = default;
        virtual const Vec_t<Entity_t>& getEntities() const = 0; //solo lectura
        virtual       Vec_t<Entity_t>&& getEntities()       = 0;
        
        virtual const VecPhysComponents_t& getPhysicsComponents() const = 0; //only read
        virtual       VecPhysComponents_t& getPhysicsComponents()       = 0; 

    };


}