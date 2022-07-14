#pragma once

#include <cmp/inputcomponent.hpp>
#include <cmp/render.hpp>
#include <cmp/physics.hpp>

 //Entity desing 
 namespace ECS {

    
    struct Entity_t
    {
        explicit Entity_t() = default;
     
        //Differentes Entities
        InputComponent_t*   inp {nullptr};
        PhysicsComponent_t* phy {nullptr};
        RenderComponent_t* rend {nullptr};

        constexpr EntityID_t getEntityID() const noexcept {return entityID;}
        private:

        EntityID_t entityID {++nextID};
        inline static EntityID_t nextID {0};


    };
 }