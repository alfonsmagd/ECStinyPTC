#pragma once 

#include "cstdint"
#include <memory>
#include <vector> 
#include <man/componentstorage.hpp>
#include <util/typealias.hpp>
#include <util/gamecontext.hpp>

namespace ECS
{
   
    
    //EntityManager 
    struct EntityManager_t : public GameContext_t
    {
       
        //Definimos el tam total de numeros de entidades que vamos a reservar.
        static constexpr std::size_t kNUMINITIALENTITIES {1000};
        void createEntity(uint32_t x, uint32_t y, std::string filename);
        
        explicit EntityManager_t();
        
        //Estoy devolviendo una copia de de entidades, para ello hay que devolver
        //una referencia para para que no este creando cada vez que se se llama 
        //de momento todo lectura y se pone un const a la derecha y aparte 
        //este metodo no cambia los valores y por eso tiene const. 
        
        //El final se utiliza para que el hijo que herede de aqui no tenga que herdedar getEntities. 
        const VecEntities_t& getEntities()  const override  { return m_Entity;}
        //int num() const override {return 3;}
         VecEntities_t& getEntities()   override { return m_Entity;}
        
        const VecPhysComponents_t& getPhysicsComponents() const override {return m_components.getPhysicsComponents();}
              VecPhysComponents_t& getPhysicsComponents()       override {return m_components.getPhysicsComponents();}
         
        private:

        //ComponentStorage se encarga de almacenar los componentes para mejorar la gestion
        ComponentStorage_t m_components {kNUMINITIALENTITIES};
        VecEntities_t m_Entity;
    };



}