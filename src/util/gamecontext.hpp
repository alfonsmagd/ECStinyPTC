#pragma once 
#include "cstdint"
#include <memory>
#include <util/typealias.hpp>

//Esta interfaz va a ser pura y abstracta. 
namespace ECS {

    struct GameContext_t {
        
        virtual ~GameContext_t() = default;
        virtual const VecEntities_t& getEntities() const = 0;


    };


}