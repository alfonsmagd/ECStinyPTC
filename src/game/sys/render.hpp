#pragma once 

#include "cstdint"
#include <memory>
#include <ecs/util/typealias.hpp>
#include <ecs/cmp/entity.hpp>



    template <typename GameCTX_T>
    struct RenderSystem_t {

        
        explicit RenderSystem_t(uint32_t w, uint32_t h );
        
        ~RenderSystem_t();
        
        bool update(const GameCTX_T& g) const ;
        void drawAllEntities(const GameCTX_T& g) const;
        bool clippingSprite2D(uint32_t& h, uint32_t& w, uint32_t& x, uint32_t& y, uint32_t rh, uint32_t rw, uint32_t& left_off, uint32_t& up_off) const;
        constexpr void EnableDebugMode() noexcept {b_DebugModeRender = true;}
        constexpr void DisableDebugMode() noexcept {b_DebugModeRender = false;}
        constexpr void SetColorDebugMode(uint32_t color) noexcept {m_DebugColor = color;}


        private:
        //Funciones de ayuda. 
        constexpr uint32_t* getPosicionScreenXY(uint32_t x, uint32_t y)const noexcept {return m_framebuffer.get() + y*m_w +x;};
        constexpr void drawBox(const BoundingBox_t& box, uint32_t x, uint32_t y, uint32_t color) const noexcept;
        constexpr void renderAlignedLineClipped(uint32_t x1, uint32_t x2,uint32_t y, bool yaxis, uint32_t color)const noexcept;
        const uint32_t Kg = 0x0000FF00; //constexpr calcula en tiempo de compilaci´on. 
        const uint32_t Kr = 0x00FF0000;
        const uint32_t Kb = 0x000000FF;
        

        const uint32_t sprite[4*4] = {
	                Kr,Kb,Kb,Kb,
	                Kb,Kr,Kb,Kb,
	                Kb,Kb,Kr,Kb,
                    Kb,Kb,Kr,Kb      };

        private:

        bool b_DebugModeRender{false};
        uint32_t m_DebugColor {0xFFFF0000};
        const uint32_t m_w {0}, m_h{0};
        std::unique_ptr<uint32_t[]> m_framebuffer{nullptr};
        


    };


