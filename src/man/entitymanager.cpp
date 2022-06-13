#include <man/entitymanager.hpp>

namespace ECS {
    
    EntityManager_t::EntityManager_t(){
        
        m_Entity.reserve(kNUMINITIALENTITIES);
        
        
    }
    
    //CreateEntity
    void 
    EntityManager_t::createEntity(uint32_t x, uint32_t y, 
                                        std::string filename)
    {
        auto& e = m_Entity.emplace_back(filename);
        auto& ph = m_components.createPhysicsComponent();
        
        e.phy = &ph;
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