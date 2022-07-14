#pragma once 

#include <vector>
#include <cmp/inputcomponent.hpp>
#include <cmp/physics.hpp>
#include <cmp/render.hpp>
#include <util/typealias.hpp>


namespace ECS
{
    struct ComponentStorage_t{
        
        explicit ComponentStorage_t(std::size_t initialize){
            
            m_physicsComponents.reserve(initialize);
            m_renderComponents.reserve(initialize);
            m_inputComponents.reserve(10);
        }
        //Delete all ilegal constructor, because i use only a singletone model to storage all component
        ComponentStorage_t(const ComponentStorage_t& ) = delete;
        ComponentStorage_t(ComponentStorage_t&&) = delete;
        ComponentStorage_t& operator=(const ComponentStorage_t& ) = delete;
        ComponentStorage_t& operator=(ComponentStorage_t&& ) = delete;

        //Create Components. 
        PhysicsComponent_t& createPhysicsComponent(EntityID_t eid);
        RenderComponent_t&  createRenderComponent(EntityID_t eid);
        InputComponent_t&  createInputComponent(EntityID_t eid);

        //Physycs Components Get 
        const Vec_t<PhysicsComponent_t>& getPhysicsComponents() const  {return m_physicsComponents;}
              Vec_t<PhysicsComponent_t>& getPhysicsComponents()        {
                 
                 return const_cast<Vec_t<PhysicsComponent_t>&>(const_cast<const ComponentStorage_t*>(this)->getPhysicsComponents());
                  
                  }
        //Render Components Get        
        const Vec_t<RenderComponent_t>& getRenderComponents() const  {return m_renderComponents;}
               Vec_t<RenderComponent_t>& getRenderComponents()       {return m_renderComponents;} 

        //Input Components Get        
        const Vec_t<InputComponent_t>&  getInputComponents() const  {return m_inputComponents;}
              Vec_t<InputComponent_t>& getInputComponents()        {return m_inputComponents;} 

    private:

        Vec_t<PhysicsComponent_t> m_physicsComponents {};
        Vec_t<RenderComponent_t>  m_renderComponents  {};
        Vec_t<InputComponent_t>   m_inputComponents   {};



    };
    
} // namespace ECS

