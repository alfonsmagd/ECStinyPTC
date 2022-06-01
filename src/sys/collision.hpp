#pragma once 

#include "cstdint"
#include <util/gamecontext.hpp>


namespace ECS
{
    struct EntityManager_t;
    struct  GameContext_t ;
    
    struct CollisionSystem_t {

        explicit CollisionSystem_t() = default; 
        
        
        //se actualiza el update de nuestro colissionsystem_t
        bool update( GameContext_t& g) const ;


        


    };



} // namespace EC

