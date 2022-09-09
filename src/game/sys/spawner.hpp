#pragma once 

#include "cstdint"
#include <ecs/util/gamecontext.hpp>


template<typename GameCTX_T>
    struct SpawnerSystem_t {

        explicit SpawnerSystem_t() = default;
        
        
        //se actualiza el update de nuestro colissionsystem_t
        void update( GameCTX_T& g) const ;
        void generateSpawn(GameCTX_T& g, uint32_t x , uint32_t y ) const;

    };


