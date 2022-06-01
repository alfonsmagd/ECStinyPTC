#include <sys/collision.hpp>
#include <util/gamecontext.hpp>
#include <iostream>


namespace ECS
{
  
    bool 
    CollisionSystem_t::update(GameContext_t& g) const {

        for(auto& e: g.getEntities()){

          if(e.x > 640 || (e.x + e.w) > 640){e.x -= e.vx ; e.vx = -e.vx;}
          //std::cout<<"el valor de e.x es = >"<<e.x+e.w;
          
          if(e.y >360||  (e.y + e.h) >360) {e.y -= e.vy ; e.vy = -e.vy;}
          //std::cout<<"el valor de e.y es => "<<e.y + e.h<< "\n";
        }

        return true;
        
    }


} // namespace EC
