#include <man/entitymanager.hpp>

namespace ECS {
    
    EntityManager_t::EntityManager_t(){
        
        m_Entity.reserve(kNUMINITIALENTITIES);
        
        
    }
    
    //CreateEntity
    void EntityManager_t::createEntity(uint32_t x, uint32_t y, 
                                        uint32_t w, uint32_t h, uint32_t color)
    {
        auto& e = m_Entity.emplace_back("assets/d.png");
        e.x = x; e.y = y; //Update position. 
        //std::fill(begin(e.sprite),end(e.sprite),color);
        
        //fORMA NO EFICIENTE 
        //for(uint32_t& element : e.sprite)
        //{
        //    element = color;
        //}
      
        
    }
    
}