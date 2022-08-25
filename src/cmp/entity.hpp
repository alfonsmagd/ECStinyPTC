#pragma once

#include <cmp/inputcomponent.hpp>
#include <cmp/render.hpp>
#include <cmp/physics.hpp>
#include <util/typealias.hpp>

 //Entity desing 
 namespace ECS {

    
    struct Entity_t
    {
        explicit Entity_t() = default;

        template<typename CMP_T>
        void addComponent(CMP_T& cmp){
            auto type = cmp.getComponentTypeID();
            m_components[type] = &cmp;
        }

        template<typename CMP_T>
        CMP_T* getComponent(){

            auto type = CMP_T::getComponentTypeID();
            auto it  =  m_components.find(type);
            if(it != m_components.end()){
                return static_cast<CMP_T*>(it->second);
            }
                return nullptr;
        }

        template<typename CMP_T>
        const CMP_T* getComponent() const {
            auto* cmp = const_cast<Entity_t*>(this)->getComponent<CMP_T>();
            return const_cast<const CMP_T*>(cmp);
        }
     
        //Differentes Entities
        InputComponent_t*   inp {nullptr};
        PhysicsComponent_t* phy {nullptr};
        RenderComponent_t* rend {nullptr};

        constexpr EntityID_t getEntityID() const noexcept {return entityID;}

        private:
        mapComponent_t<ComponentTypeID_t,Component_t*> m_components;
        EntityID_t entityID {++nextID};
        inline static EntityID_t nextID {0};


    };
 }