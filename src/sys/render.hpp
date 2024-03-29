#pragma once 

#include "cstdint"
#include <memory>
#include <ecs/util/typealias.hpp>
#include <ecs/cmp/entity.hpp>


namespace ECS
{
  
    template <typename GameCTX_T>
    struct RenderSystem_t {

        
        explicit RenderSystem_t(uint32_t w, uint32_t h );
        
        ~RenderSystem_t();
        
        bool update(const GameCTX_T& g) const ;
        void drawSprite();
        void drawAllEntities(const GameCTX_T& g) const;

        //Constantes 

        const uint32_t Kg = 0x0000FF00; //constexpr calcula en tiempo de compilaci´on. 
        const uint32_t Kr = 0x00FF0000;
        const uint32_t Kb = 0x000000FF;
        

        const uint32_t sprite[4*4] = {
	                Kr,Kb,Kb,Kb,
	                Kb,Kr,Kb,Kb,
	                Kb,Kb,Kr,Kb,
                    Kb,Kb,Kr,Kb      };

        private:

        const uint32_t m_w {0}, m_h{0};
        std::unique_ptr<uint32_t[]> m_framebuffer{nullptr};
        


    };



} // namespace EC

