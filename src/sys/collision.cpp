#include <sys/collision.hpp>
#include <util/gamecontext.hpp>
#include <iostream>


namespace ECS
{
  
    bool 
    CollisionSystem_t::update(GameContext_t& g) const {

        for(auto& e: g.getEntities()){

          auto* phy = e.getComponent<PhysicsComponent_t>();
          auto* rend = e.getComponent<RenderComponent_t>();

        if(phy != nullptr){
          //Avoid screen x collision.
          if(phy->x > 640 || (phy->x + rend->w) > 640)
          {
            phy->x -= phy->vx ; phy->vx = -phy->vx;
          }
          //Avoid screen y collision.
          if(phy->y >360||  (phy->y + rend->h) >360)
          {
            phy->y -= phy->vy ; phy->vy = -phy->vy;
          }

        }//if(e.phy != nullptr)
          
      }//for(auto& e: g.getEntities())

        return true;
        
    }


} // namespace EC
