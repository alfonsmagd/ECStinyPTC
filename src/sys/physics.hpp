#pragma once 

#include "cstdint"
#include <util/gamecontext.hpp>


namespace ECS
{
    struct EntityManager_t;
    struct  GameContext_t ;
    
    struct PhysicsSystem_t {

        explicit PhysicsSystem_t() = default; 
        
        
        //se modifican las propiedades fisicas velocidad de las entidades. 
        bool update( GameContext_t& g) const ;


        


    };



} // namespace EC

