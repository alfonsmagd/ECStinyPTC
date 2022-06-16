#pragma once

#include "cstdint"
#include <vector>
#include <string>
#include <picoPNG/src/picopng.hpp>
#include <fstream>
#include <cstring>
#include <cmp/physics.hpp>
#include <util/typealias.hpp>
 //Entity desing 
 namespace ECS {

    
    struct Entity_t
    {
        explicit Entity_t(uint32_t pw, uint32_t ph) : w{pw},h{ph}
        {
            sprite.resize(w*h);
            
        }
        explicit Entity_t(std::string fileName)
        {
            std::vector<unsigned char> pixels{};
            std::vector<unsigned char> reorderpixels{};
            unsigned long dw{0},dh{0};
            //abrir fichero 
            std::ifstream file(fileName, std::ios::binary);
            //Iterador al principio del file y despues del file 
            std::vector<unsigned char> filevec(
                std::istreambuf_iterator<char>{file},
                std::istreambuf_iterator<char>{}
            );

            //RGBA TO BGRA
            decodePNG(pixels,dw,dh,filevec.data(),filevec.size());
            reorderpixels.resize(pixels.size()/4);
            sprite.reserve(pixels.size()/4);
            
            for(auto p = pixels.begin(); p != pixels.end(); p += 4  ){

                    uint32_t pixelaux = 

                    static_cast<uint32_t>(*(p+0))<<16 |
                    static_cast<uint32_t>(*(p+1))<<8  |
                    static_cast<uint32_t>(*(p+2))     |
                    static_cast<uint32_t>(*(p+4))<<24 ;

                sprite.push_back(pixelaux);
                
            }
        
            w =dw, h = dh;

        }
        PhysicsComponent_t* phy {nullptr};
        uint32_t w{0}, h{0};
        EntityID_t entityID {++nextID};
        std::vector<uint32_t> sprite{} ;
        
        private:
        inline static EntityID_t nextID {0};


    };
 }