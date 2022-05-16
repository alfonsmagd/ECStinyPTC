#pragma once 
#include "cstdint"
#include <memory>
#include <vector> 

namespace ECS
{
    //Entity desing 
    struct Entity_t
    {
        explicit Entity_t(uint32_t _w, uint32_t _h) : w{_w},h{_h}
        {
            sprite.resize(w*h);
            
        }
        uint32_t x{0}, y{0};
        uint32_t w{0}, h{0};
        
        std::vector<uint32_t> sprite{} ;


    };
    
    //EntityManager 
    struct EntityManager_t
    {
        using VecEntities_t = std::vector<Entity_t>;
        //Definimos el tam total de numeros de entidades que vamos a reservar.
        static constexpr std::size_t kNUMINITIALENTITIES {1000};
        void createEntity(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color);
        
        explicit EntityManager_t();
        
        //Estoy devolviendo una copia de de entidades, para ello hay que devolver
        //una referencia para para que no este creando cada vez que se se llama 
        //de momento todo lectura y se pone un const a la derecha y aparte 
        //este metodo no cambia los valores y por eso tiene const. 
        const VecEntities_t& getEntities() const { return m_Entity;}
        
        private:
        
        VecEntities_t m_Entity;
    };



}