#pragma once 

#include "cstdint"
#include <ecs/util/typealias.hpp>


template <typename GameCTX_T>
struct PhysicsSystem_t {

    explicit PhysicsSystem_t() = default; 
        
        
        //se modifican las propiedades fisicas velocidad de las entidades. 
    bool update( GameCTX_T& g) const ;


    };




