#pragma once 

#include "cstdint"
//#include <ecs/util/gamecontext.hpp>


namespace ECS
{
  
    template <typename GameCTX_T>
    struct PhysicsSystem_t {

        explicit PhysicsSystem_t() = default; 
        
        
        //se modifican las propiedades fisicas velocidad de las entidades. 
        bool update( GameCTX_T& g) const ;


    };



} // namespace EC

