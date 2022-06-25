#include <sys/collision.hpp>
#include <util/gamecontext.hpp>
#include <iostream>


namespace ECS
{
  
    bool 
    CollisionSystem_t::update(GameContext_t& g) const {

        for(auto& e: g.getEntities()){

        if(e.phy != nullptr){
          //Avoid screen x collision.
          if(e.phy->x > 640 || (e.phy->x + e.rend->w) > 640)
          {
            e.phy->x -= e.phy->vx ; e.phy->vx = -e.phy->vx;
          }
          //Avoid screen y collision.
          if(e.phy->y >360||  (e.phy->y + e.rend->h) >360)
          {
            e.phy->y -= e.phy->vy ; e.phy->vy = -e.phy->vy;
          }

        }//if(e.phy != nullptr)
          
      }//for(auto& e: g.getEntities())

        return true;
        
    }


} // namespace EC
