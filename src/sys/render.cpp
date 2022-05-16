
#include <tinyPTC/src/tinyptc.h>
#include <sys/render.hpp>
#include <man/entitymanager.hpp>
#include <iostream>
#include <algorithm>

namespace ECS {

    RenderSystem_t::RenderSystem_t(uint32_t w, uint32_t h,EntityManager_t& em ) : m_w(w), m_h(h),
        m_framebuffer{std::make_unique<uint32_t[]>(m_w*m_h)},
        m_Entity{em}
    {
    
       ptc_open("window",m_w,m_h);


    }

    void RenderSystem_t::drawAllEntities() const {

        //Devuelve el vector de entidades que dibujaremos una a una
        auto& entities = m_Entity.getEntities();

        for(auto& e:entities)
        {
            //Es decir cada vez que queramos dibuajr todas las entidades, neceitamos obtener el puntero
            //de la pantalla , para poder ubicarnos , el puntero de la pantalla siempre va a tener un origen,begin(), 
            //m_framebuffer
            uint32_t* screen = m_framebuffer.get(); //puntero a la pantalla 
            screen += e.y*m_w +e.x; //necesito saltar y veces para colocarme en su sitio, y despues solamente recorrer la X. 
            //ya estoy colocado en la pantalla, ahora necesito recorrecor mi sprite 
            //Recorro el alto, y voy rellando el ancho , copiando my entiti al screen. 
            auto sprite_it = begin(e.sprite);
        //  auto sprite_it = e.sprite.data() otra forma igual al hacer. 
            for(size_t i = 0; i<(e.h); ++i)
            {
                //cuando tenemos un vector y queremos copiar, usamos esta tecnica. 
                std::copy(sprite_it, (sprite_it + e.w), screen);
                //actualizo sprite_it a la siguiente linea 
                sprite_it += e.w; 
                //Salto la pantalla 
                screen += m_w;

            }

        }//for(auto& e:entities)



    }

/*
    void RenderSystem_t::drawSprite(){

        uint32_t *pscreen  = screen.get();
		psrite = sprite;
		for(uint32_t i = 0; i< 4 ; ++i)
		{
			for(uint32_t j = 0; j<4 ; ++j){

				*pscreen = *psrite;
				++pscreen;
				++psrite;

			}//una fila del sprite se ha rellenado, ahora toca rellenar la columnas
			pscreen += this->m_w- 4;
		}



    }
*/    

    bool RenderSystem_t::update() const 
    {

        auto screen = m_framebuffer.get();
        auto size = m_w*m_h;
        std::cout << size << "el valor medio es :"<<(size/2)<<"   " << (size/3) << "\n";
        std::fill(screen, screen+(size/2),Kg);
        std::fill(screen+(size/2)+1,screen + size, Kr); //Rellena el ptr desde inicio (screen hsata el final. )

		drawAllEntities(); 
		ptc_update(screen);

        return !ptc_process_events();

    }//end update const 

    RenderSystem_t::~RenderSystem_t()
    {
        ptc_close();
    }



}