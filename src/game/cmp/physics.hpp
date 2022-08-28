#pragma once

#include "cstdint"
#include <ecs/cmp/component.hpp>




struct PhysicsComponent_t : public ECS::Component_t{


 static ECS::ComponentTypeID_t getComponentTypeID() noexcept{
    return static_cast<ECS::ComponentTypeID_t>(2);
   }


   explicit PhysicsComponent_t(ECS::EntityID_t eid) : ECS::Component_t(eid) {};
    
        uint32_t x{0}, y{0};
        int32_t vx{1}, vy{1};

    };
