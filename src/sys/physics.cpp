#include <sys/physics.hpp>
#include <util/gamecontext.hpp>


namespace ECS
{
  
        
        
    bool 
    PhysicsSystem_t::update(GameContext_t& g) const {

        for(auto& e: g.getEntities()){

          e.x += e.vx;
          e.y += e.vy;

        }

        return true;
        
    }


        


  



} // namespace EC
