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


     struct RenderComponent_t :  public ECS::ComponentBase_t<RenderComponent_t>
    {
        explicit RenderComponent_t(ECS::EntityID_t eid) : ComponentBase_t(eid)
        {}

        //Load from file function, to load file . 
        void loadFromFile(const std::string_view fileName);

        void convertSpriteRGBAtoBGRA(std::vector<unsigned char>& pixels);

        //Not need de ID, Component_t pass a one ID. hn
        uint32_t w{0}, h{0};
        std::vector<uint32_t> sprite{} ;
        
    };
   
 