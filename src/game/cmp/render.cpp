
#include "render.hpp"
#include <tuple>



    auto
    loadPNGintoVector(const std::string_view fileName){

        std::vector<unsigned char> pixels{};
        unsigned long dw{0},dh{0};
        //abrir fichero 
        std::ifstream file(fileName.data(), std::ios::binary);
        //Iterador al principio del file y despues del file 
        std::vector<unsigned char> filevec(
            std::istreambuf_iterator<char>{file},
            std::istreambuf_iterator<char>{}
        );
        decodePNG(pixels,dw,dh,filevec.data(),filevec.size());

        return std::tuple{dw,dh,pixels};
    }

//Convert sprite color, to RGBA to BGRA, this funciont depends of Systems Operations. probably you should modify some features. 
void
RenderComponent_t::convertSpriteRGBAtoBGRA(std::vector<unsigned char>& pixels){

    sprite.reserve(pixels.size()/4);
            
        for(auto p = pixels.begin(); p != pixels.end(); p += 4  ){

                uint32_t pixelaux = 

                static_cast<uint32_t>(*(p+0))<<16 |
                static_cast<uint32_t>(*(p+1))<<8  |
                static_cast<uint32_t>(*(p+2))     |
                static_cast<uint32_t>(*(p+3))<<24 ;

                sprite.push_back(pixelaux);
                
            }
}

void
RenderComponent_t::loadFromFile(const std::string_view fileName){

        //Strucutre Bindings C++17
        auto [ dw,dh,pixels ]= loadPNGintoVector(fileName);
        //RGBA TO BGRA   
        //reorderpixels.resize(pixels.size()/4);
        convertSpriteRGBAtoBGRA(pixels);

        w =dw, h = dh;

 } //end void loadFromFile();



