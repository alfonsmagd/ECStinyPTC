#pragma once

#include <chrono>
#include <ecs/cmp/component.hpp>


struct PositionSpawn_t{

    uint32_t xSpanw, ySpwan;

};

struct SpawnComponent_t : public ECS::ComponentBase_t<SpawnComponent_t>
{
    using clock = std::chrono::steady_clock;

   explicit SpawnComponent_t(ECS::EntityID_t eid) : ComponentBase_t(eid) {};
    
    //ratio<1,1> is like a 1 second. 
    clock::time_point end_Spawn_time{clock::now()};
    std::chrono::duration<int,std::ratio<1,1>> Spawn_Elapse{5}; 
    std::size_t to_be_spawned{3};

    PositionSpawn_t spawnerPosition;


};