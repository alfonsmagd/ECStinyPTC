#pragma once 

#include "cstdint"
#include <vector> 
#include <string_view>
#include <algorithm>
#include <man/componentstorage.hpp>
#include <util/typealias.hpp>
#include <util/gamecontext.hpp>


namespace ECS
{
  
    
    //EntityManager implements GameCOntext_T Interface. 
    struct EntityManager_t : public GameContext_t
    {
       
        //Definimos el tam total de numeros de entidades que vamos a reservar.
        static constexpr std::size_t kNUMINITIALENTITIES {1000};
        Entity_t& createEntity(uint32_t x, uint32_t y, const std::string_view filename);
        
        explicit EntityManager_t();
        void  addInputController(Entity_t& e);
        //Estoy devolviendo una copia de de entidades, para ello hay que devolver
        //una referencia para para que no este creando cada vez que se se llama 
        //de momento todo lectura y se pone un const a la derecha y aparte 
        //este metodo no cambia los valores y por eso tiene const. 
        
        //El final se utiliza para que el hijo que herede de aqui no tenga que herdedar getEntities. 
        const Vec_t<Entity_t>& getEntities()  const override  { return m_Entity;}
              Vec_t<Entity_t>& getEntities()        override  { return m_Entity;}
        
        //Get physics Cpomonent from ComponentStorage and these are inherence about GameContext
        const Vec_t<PhysicsComponent_t>& getPhysicsComponents() const override {return m_components.getPhysicsComponents();}
              Vec_t<PhysicsComponent_t>& getPhysicsComponents()       override {return m_components.getPhysicsComponents();}
         //Get Render Component from ComponentStorage ande this are inherence about GameContext
         const Vec_t<RenderComponent_t>& getRenderComponents() const override {return m_components.getRenderComponents();}
               Vec_t<RenderComponent_t>& getRenderComponents()       override {return m_components.getRenderComponents();}

         const Vec_t<InputComponent_t>& getInputComponents() const override {return m_components.getInputComponents();}
               Vec_t<InputComponent_t>& getInputComponents()       override {return m_components.getInputComponents();}

        const Entity_t* getEntitybyID(EntityID_t eid) const override;
              Entity_t* getEntitybyID(EntityID_t eid)       override;         
              
        private:

        //ComponentStorage se encarga de almacenar los componentes para mejorar la gestion
        ComponentStorage_t m_components {kNUMINITIALENTITIES};
        Vec_t<Entity_t> m_Entity;
        
    };



}