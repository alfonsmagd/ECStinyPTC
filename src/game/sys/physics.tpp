#include "physics.hpp"
#include <game/cmp/physics.hpp>


  
    template <typename GameCTX_T>    
    bool 
    PhysicsSystem_t<GameCTX_T>::update(GameCTX_T& g) const {

        for(auto& phy: g.template getComponents<PhysicsComponent_t>()){

            phy.x += phy.vx;
            phy.y += phy.vy;

        }

        return true;
        
    


        


  



} // namespace EC
