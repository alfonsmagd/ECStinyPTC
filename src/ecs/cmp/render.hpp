#pragma once

#include "cstdint"
#include <vector>
#include <string_view>
#include <picoPNG/src/picopng.hpp>
#include <fstream>
#include <cstring>
#include <ecs/cmp/component.hpp>
#include <ecs/util/typealias.hpp>
 //Entity desing 
 namespace ECS {

     struct RenderComponent_t :  public Component_t
    {
        explicit RenderComponent_t(EntityID_t eid) : Component_t(eid)
        {}

        static ComponentTypeID_t getComponentTypeID() noexcept{
            return static_cast<ComponentTypeID_t>(3);
        }
        //Load from file function, to load file . 
        void loadFromFile(const std::string_view fileName);

        void convertSpriteRGBAtoBGRA(std::vector<unsigned char>& pixels);

        //Not need de ID, Component_t pass a one ID. hn
        uint32_t w{0}, h{0};
        std::vector<uint32_t> sprite{} ;
        
    };
   
 }