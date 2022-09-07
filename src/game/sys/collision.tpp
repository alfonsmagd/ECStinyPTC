#include <game/sys/collision.hpp>
#include <game/cmp/collider.hpp>
#include <ecs/util/gamecontext.hpp>
#include <iostream>


template <typename GameCTX_T>
CollisionSystem_t<GameCTX_T>::CollisionSystem_t(uint32_t h, uint32_t w) : m_h(h),m_w(w){}


template <typename GameCTX_T>
PhysicsComponent_t*
CollisionSystem_t<GameCTX_T>::getRequieredPhyComponent(GameCTX_T& g, const ColliderComponent_t& cll) const {

    auto* e = g.getEntitybyID(cll.getEntityID());
    if(e)
      return e->template getComponent<PhysicsComponent_t>();
    return nullptr;

}

    template <typename GameCTX_T>
    bool 
    CollisionSystem_t<GameCTX_T>::update(GameCTX_T& g) const {

        for(auto& col: g.template getComponents<ColliderComponent_t>()){

        auto* phy = getRequieredPhyComponent(g,col);    
        if(!phy) continue; //salta la siguiente iteraccion. 
          //Avoid screen x collision.


         //Left Collision
          auto xl {phy->x + col.box.xLeft};
          auto xr {phy->x + col.box.xRight};
          auto yu {phy->y + col.box.yUp};
          auto yd {phy->y + col.box.yDown};
          
          if(xl > m_w|| xr > m_w){
            phy->x -= phy->vx ; phy->vx = -phy->vx;
          }
          //Vertical COllision
          //Avoid screen y collision.
          if( yu > m_h || yd > m_h){
            phy->y -= phy->vy ; phy->vy = -phy->vy;
          }

          
      }//for(auto& e: g.getEntities())

        return true;
        
    }


