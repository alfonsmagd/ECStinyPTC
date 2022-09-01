
#include <ecs/man/entitymanager.hpp>

namespace ECS {
    
    EntityManager_t::EntityManager_t(){
        
        m_Entity.reserve(kNUMINITIALENTITIES);
        
    }
    

   Entity_t* 
   EntityManager_t::getEntitybyID(EntityID_t eid){

    auto eptr = const_cast<const EntityManager_t*>(this)->getEntitybyID(eid);
    return const_cast<Entity_t*>(eptr);
       
   } 

   const Entity_t* 
   EntityManager_t::getEntitybyID(EntityID_t eid) const{
    //Encuentra el ID. 
    auto it = std::find_if(m_Entity.begin(),m_Entity.end(),
    [&](const Entity_t e){return e.getEntityID() == eid;});

    if(it == m_Entity.end()) return nullptr;
     
    return it.base();
       
   } 

}// ECS NAMESPACE