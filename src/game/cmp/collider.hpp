#pragma once

#include "cstdint"
#include <ecs/cmp/component.hpp>


struct BoundingBox_t{

    uint32_t xLeft, xRight;
    uint32_t yUp, yDown;

};

struct ColliderComponent_t : public ECS::ComponentBase_t<ColliderComponent_t>
{
   explicit ColliderComponent_t(ECS::EntityID_t eid) : ComponentBase_t(eid) {};
    
    BoundingBox_t box;
};
