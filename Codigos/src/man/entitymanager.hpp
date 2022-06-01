#pragma once 

#include "cstdint"
#include <memory>
#include <vector> 
#include <util/typealias.hpp>
#include <util/gamecontext.hpp>

namespace ECS
{
   
    
    //EntityManager 
    struct EntityManager_t : public GameContext_t
    {
       
        //Definimos el tam total de numeros de entidades que vamos a reservar.
        static constexpr std::size_t kNUMINITIALENTITIES {1000};
        void createEntity(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color);
        
        explicit EntityManager_t();
        
        //Estoy devolviendo una copia de de entidades, para ello hay que devolver
        //una referencia para para que no este creando cada vez que se se llama 
        //de momento todo lectura y se pone un const a la derecha y aparte 
        //este metodo no cambia los valores y por eso tiene const. 
        
        //El final se utiliza para que el hijo que herede de aqui no tenga que herdedar getEntities. 
        const VecEntities_t& getEntities()  const override  { return m_Entity;}
        //int num() const override {return 3;}
         VecEntities_t& getEntities()   override { return m_Entity;}
        private:
        
        VecEntities_t m_Entity;
    };



}