#include "componentstorage.hpp"

namespace ECS {

PhysicsComponent_t&
 ComponentStorage_t::createPhysicsComponent(){
  auto& cmp = m_physicsComponents.emplace_back();
   
  return cmp;

 }


}