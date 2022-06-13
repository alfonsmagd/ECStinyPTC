#pragma once 

#include <vector>
#include <cmp/entity.hpp>
#include <cmp/physics.hpp>

namespace ECS {

    using VecEntities_t = std::vector<Entity_t>;
    using VecPhysComponents_t = std::vector<PhysicsComponent_t>;

}