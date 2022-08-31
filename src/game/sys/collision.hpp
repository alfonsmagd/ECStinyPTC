#pragma once 

#include "cstdint"
#include <ecs/util/gamecontext.hpp>



    template<typename GameCTX_T>
    
    struct CollisionSystem_t {

        explicit CollisionSystem_t() = default; 
        
        
        //se actualiza el update de nuestro colissionsystem_t
        bool update( GameCTX_T& g) const ;

    };





