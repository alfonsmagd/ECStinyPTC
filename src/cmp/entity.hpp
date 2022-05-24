#pragma once

#include "cstdint"
#include <vector>
#include <string>
#include <picoPNG/src/picopng.hpp>
#include <fstream>
#include <cstring>

 //Entity desing 
    struct Entity_t
    {
        explicit Entity_t(uint32_t _w, uint32_t _h) : w{_w},h{_h}
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
            reorderpixels.resize(pixels.size());
            
            // Otra forma de hacer
            
            for(auto p = pixels.begin() ; p != pixels.end() ; p +=4)
            {
               uint32_t pixelaux = 
               static_cast<uint32_t>(*(p+0))<<16 |
               static_cast<uint32_t>(*(p+1))<<8  |
               static_cast<uint32_t>(*(p+2))     |
               static_cast<uint32_t>(*(p+3))<<24
            
             sprite.push_back(pixelaux);
            }
            
            
            for(size_t i = 0; i < pixels.size(); i+=4)
            {
                reorderpixels[i] = pixels[i+2];
                reorderpixels[i+1] = pixels[i+1];
                reorderpixels[i+2] = pixels[i];
                reorderpixels[i+3] = pixels[i+3];
            }




            sprite.resize(pixels.size()/4); //Divido entre 4 por que paso de UINT32--> CHAR  
            std::memcpy(sprite.data(),reorderpixels.data(),reorderpixels.size());

           

            w =dw, h = dh;

        }
        uint32_t x{0}, y{0};
        uint32_t w{0}, h{0};
        
        std::vector<uint32_t> sprite{} ;


    };
