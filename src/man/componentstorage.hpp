#pragma once 

#include <vector>
#include <cmp/physics.hpp>
#include <util/typealias.hpp>


namespace ECS
{
    struct ComponentStorage_t{
        
        explicit ComponentStorage_t(std::size_t initialize){
            m_physicsComponents.reserve(initialize);
        }
        //Delete all ilegal constructor, because i use only a singletone model to storage all component
        ComponentStorage_t(const ComponentStorage_t& ) = delete;
        ComponentStorage_t(ComponentStorage_t&&) = delete;
        ComponentStorage_t& operator=(const ComponentStorage_t& ) = delete;
        ComponentStorage_t& operator=(ComponentStorage_t&& ) = delete;


        PhysicsComponent_t& createPhysicsComponent();
        //Not use overrdie because not herence in the functions. 
        const Vec_t<PhysicsComponent_t>& getPhysicsComponents() const  {return m_physicsComponents;}
              Vec_t<PhysicsComponent_t>& getPhysicsComponents()        {
                 
                 return const_cast<Vec_t<PhysicsComponent_t>&>(const_cast<const ComponentStorage_t*>(this)->getPhysicsComponents());
                  
                  }
    private:

        Vec_t<PhysicsComponent_t> m_physicsComponents {};



    };
    
} // namespace ECS

