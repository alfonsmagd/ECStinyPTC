#pragma once 
#include <cstdint>
#include <util/typealias.hpp>

// This class its like abstrac class, all components will inherit from this class to build unique components which 
//are identificate by ID. This solution , can help avoid components not be part of entities. 
namespace ECS{


struct Component_t {
    
    explicit Component_t(EntityID_t eid) : entityID{eid}
    {}

    constexpr EntityID_t getEntityID() const noexcept{ return entityID;}
    
private:
    ComponentID_t ComponentID { ++nextComponentID};
    EntityID_t  entityID{0};
    inline static ComponentID_t nextComponentID {0};


};

}