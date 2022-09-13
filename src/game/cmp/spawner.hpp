#pragma once

#include <chrono>
#include <functional>
#include <ecs/cmp/component.hpp>



struct PositionSpawn_t{

    uint32_t xSpawn, ySpawn;

};

struct SpawnComponent_t : public ECS::ComponentBase_t<SpawnComponent_t>
{
    using clock = std::chrono::steady_clock;
   

   explicit SpawnComponent_t(ECS::EntityID_t eid) : ComponentBase_t(eid) {};
    
    //ratio<1,1> is like a 1 second. function es una clase que cotiene un void (*)void encapuslado, y permite conversioens. 
    //Cualquier cosa llamable que reciba void y que devuelva void es convertible a std::function.
    std::function<void(const SpawnComponent_t&)> spawnMethod {};
    clock::time_point end_Spawn_time{clock::now()};
    std::chrono::duration<int,std::ratio<1,1>> Spawn_Elapse{5}; 
    std::size_t to_be_spawned{3};

    PositionSpawn_t spawnerPosition;


};
