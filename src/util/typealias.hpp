#pragma once 

#include <vector>
//#include <cmp/entity.hpp> avoid circular declaration 
#include <cmp/physics.hpp>

namespace ECS {

    
    template<typename T>
    using Vec_t = std::vector<T>;

   
    using VecPhysComponents_t   = std::vector<PhysicsComponent_t>;
    using EntityID_t            = std::size_t;
}