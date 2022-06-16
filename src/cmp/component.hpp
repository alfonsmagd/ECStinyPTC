#pragma once 
#include <cstdint>
#include <cmp/entity.hpp>


// This class its like abstrac class, all components will inherit from this class to build unique components which 
//are identificate by ID. This solution , can help avoid components not be part of entities. 
namespace ECS{


struct Component_t {
    
    explicit Component_t(EntityID_t eid) : entityID{eid}
    {}


    std::size_t ComponentID { ++nextComponentID};
    EntityID_t  entityID{0};
private:

    inline static std::size_t nextComponentID {0};


};

}