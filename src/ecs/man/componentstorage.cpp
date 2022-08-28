#include "componentstorage.hpp"

namespace ECS {

//Create Pyshycs Component Method. 
PhysicsComponent_t&
 ComponentStorage_t::createPhysicsComponent(EntityID_t eid){
  //auto& cmp = m_physicsComponents.emplace_back(eid);
   
  //return cmp;
   return createComponent<PhysicsComponent_t>(eid); 
 }

//Crete Render Component Method. 
RenderComponent_t&
ComponentStorage_t::createRenderComponent(EntityID_t eid){

    //auto& cmp = m_renderComponents.emplace_back(eid);

    //return cmp;
    return createComponent<RenderComponent_t>(eid);
}

//Create INput COmponent Method. 
InputComponent_t&
ComponentStorage_t::createInputComponent(EntityID_t eid){

    //auto& cmp = m_inputComponents.emplace_back(eid);

    //return cmp;
    return createComponent<InputComponent_t>(eid);
}

}