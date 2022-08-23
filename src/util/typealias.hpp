#pragma once 

#include <vector>
#include <unordered_map>
//#include <cmp/entity.hpp> avoid circular declaration 
//#include <cmp/physics.hpp>

namespace ECS {

    
    template<typename T>
    using Vec_t = std::vector<T>;

    template<typename ID,typename CMP>
    using mapComponent_t = std::unordered_map<ID,CMP>;  


    //using VecPhysComponents_t   = std::vector<PhysicsComponent_t>;
    using ComponentID_t         = std::size_t;
    using EntityID_t            = std::size_t;
    using ComponentTypeID_t     = std::size_t;
}