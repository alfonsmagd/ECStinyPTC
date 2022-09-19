#include "spawner.hpp"
#include <game/cmp/spawner.hpp>
#include <iostream>


    template <typename GameCTX_T>    
    void 
    SpawnerSystem_t<GameCTX_T>::update(GameCTX_T& g) const {
        using namespace std::chrono;

        auto now = steady_clock::now();
       // auto now = SpawnComponent_t::clock::now();
        for(auto& spwn: g.template getComponents<SpawnComponent_t>()){
           
           //auto* phy = spwn.template getRequieredOtherTypeComponent<GameCTX_T,SpawnComponent_t,PhysicsComponent_t>(g,spwn);
           steady_clock::duration elapsed {now - spwn.end_Spawn_time};
           if(spwn.to_be_spawned >0 && elapsed>spwn.Spawn_Elapse){
            spwn.spawnMethod(spwn);
            std::cout<<"Spawn!"<<std::endl;
            //update features spawn component. 
            spwn.end_Spawn_time = now;
            --spwn.to_be_spawned;
           }
        }

}
