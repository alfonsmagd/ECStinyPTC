#include <sys/collision.hpp>
#include <ecs/util/gamecontext.hpp>
#include <iostream>


namespace ECS
{
    template <typename GameCTX_T>
    bool 
    CollisionSystem_t<GameCTX_T>::update(GameCTX_T& g) const {

        for(auto& e: g.getEntities()){

          auto* phy = e.template getComponent<PhysicsComponent_t>();
          auto* rend = e.template getComponent<RenderComponent_t>();

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
