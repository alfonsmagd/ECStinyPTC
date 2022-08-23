
#include <man/entitymanager.hpp>

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
    [&](const Entity_t e){return e.getEntityID() ==eid;});

    if(it == m_Entity.end()) return nullptr;
     
    return it.base();
       
   } 


    //CreateEntity
    Entity_t&
    EntityManager_t::createEntity(uint32_t x, uint32_t y, 
                                  const std::string_view filename)
    {
        auto& e = m_Entity.emplace_back();
        auto e_id = e.getEntityID();
        printf("%d",e_id);
        auto& ph = m_components.createPhysicsComponent(e_id);
        auto& rn = m_components.createRenderComponent(e_id);
        
        rn.loadFromFile(filename);

        e.phy = &ph;
        e.rend  = &rn;
        ph.x = x; 
        ph.y = y;

        //Update position. 
        //std::fill(begin(e.sprite),end(e.sprite),color);
        
        //fORMA NO EFICIENTE 
        //for(uint32_t& element : e.sprite)
        //{
        //    element = color;
        //}
      
        return e;
    }

    void 
    EntityManager_t::addInputController(Entity_t& e){

        if(!e.inp){
        auto& cmp = m_components.createInputComponent(e.getEntityID());
        e.inp = &cmp;
        }
    }
    
}