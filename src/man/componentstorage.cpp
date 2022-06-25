#include "componentstorage.hpp"

namespace ECS {

//Create Pyshycs Component Method. 
PhysicsComponent_t&
 ComponentStorage_t::createPhysicsComponent(EntityID_t eid){
  auto& cmp = m_physicsComponents.emplace_back(eid);
   
  return cmp;

 }

//Crete Render Component Method. 
RenderComponent_t&
ComponentStorage_t::createRenderComponent(EntityID_t eid){

    auto& cmp = m_renderComponents.emplace_back(eid);

    return cmp;

}


}