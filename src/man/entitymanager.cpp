#include <man/entitymanager.hpp>

namespace ECS {
    
    EntityManager_t::EntityManager_t(){
        
        m_Entity.reserve(kNUMINITIALENTITIES);
        
        
    }
    
    //CreateEntity
    void 
    EntityManager_t::createEntity(uint32_t x, uint32_t y, 
                                  const std::string_view filename)
    {
        auto& e = m_Entity.emplace_back();
        auto& ph = m_components.createPhysicsComponent(e.entityID);
        auto& rn = m_components.createRenderComponent(e.entityID);
        
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
      
        
    }
    
}