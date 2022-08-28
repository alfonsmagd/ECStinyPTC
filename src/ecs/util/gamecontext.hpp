#pragma once 
#include <ecs/cmp/entity.hpp>


//Esta interfaz va a ser pura y abstracta. 
namespace ECS {

    struct GameContext_t {
        
        virtual ~GameContext_t() = default;

        virtual const Entity_t* getEntitybyID(EntityID_t eid) const = 0; //solo lectura
        virtual       Entity_t* getEntitybyID(EntityID_t eid)       = 0;

        virtual const Vec_t<Entity_t>& getEntities() const  = 0; //solo lectura
        virtual       Vec_t<Entity_t>&& getEntities()       = 0;
        
        virtual const Vec_t<PhysicsComponent_t>& getPhysicsComponents() const = 0; //only read
        virtual       Vec_t<PhysicsComponent_t>& getPhysicsComponents()       = 0; 

        virtual const Vec_t<RenderComponent_t>& getRenderComponents() const = 0; //only read
        virtual       Vec_t<RenderComponent_t>& getRenderComponents()       = 0; 

        virtual const Vec_t<InputComponent_t>& getInputComponents() const  = 0; //only read 
        virtual       Vec_t<InputComponent_t>& getInputComponents()        = 0;
        
    };


}