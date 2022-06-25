#pragma once


#include <cmp/render.hpp>
#include <cmp/physics.hpp>

 //Entity desing 
 namespace ECS {

    
    struct Entity_t
    {
        explicit Entity_t() = default;
     
        
        
        PhysicsComponent_t* phy {nullptr};
        RenderComponent_t * rend {nullptr};
        EntityID_t entityID {++nextID};
        inline static EntityID_t nextID {0};


    };
 }