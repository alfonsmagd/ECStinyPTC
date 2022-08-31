
#include <tinyPTC/src/tinyptc.h>
#include <game/sys/render.hpp>
#include <ecs/man/entitymanager.hpp>
//#include <ecs/util/typealias.hpp>
#include <iostream>
#include <algorithm>




    template <typename GameCTX_T>
    RenderSystem_t<GameCTX_T>::RenderSystem_t(uint32_t w, uint32_t h ) : m_w(w), m_h(h),
        m_framebuffer{std::make_unique<uint32_t[]>(m_w*m_h)}
        
    {
    
       ptc_open("window",m_w,m_h);


    }

    template <typename GameCTX_T>
    void 
    RenderSystem_t<GameCTX_T>::drawAllEntities(const GameCTX_T& g) const {

        //Devuelve el vector de entidades que dibujaremos una a una
        
        auto screen = m_framebuffer.get();
        
        
            auto getPosicionScreenXY = [&](uint32_t x, uint32_t y){return screen + y*m_w +x;};
            //funcion lambda para simplificar los calculos. usamos & para referencia o = para copia. 
            auto drawEntity = [&](const RenderComponent_t& rc ){
            //Es decir cada vez que queramos dibuajr todas las entidades, neceitamos obtener el puntero
            //de la pantalla , para poder ubicarnos , el puntero de la pantalla siempre va a tener un origen,begin(), 
            //m_framebuffer
               auto* eptr =   g.getEntitybyID(rc.getEntityID());

                screen = m_framebuffer.get();
                if(eptr){

                    auto* phy = eptr->template getComponent<PhysicsComponent_t>();
                    auto* rend = eptr->template getComponent<RenderComponent_t>();
                    //Other wey auto& e = *ptr;
                    screen = getPosicionScreenXY(phy->x, phy->y);
                    //puntero a la pantalla 
                    //screen += e.y*m_w +e.x; //necesito saltar y veces para colocarme en su sitio, y despues solamente recorrer la X. 
                    //ya estoy colocado en la pantalla, ahora necesito recorrecor mi sprite 
                    //Recorro el alto, y voy rellando el ancho , copiando my entiti al screen. 
                    auto sprite_it = begin(rend->sprite);
                    //  auto sprite_it = e.sprite.data() otra forma igual al hacer. 
                    for(size_t i = 0; i<(rend->h); ++i)
                    {
                    //cuando tenemos un vector y queremos copiar, usamos esta tecnica. 
                    std::copy(sprite_it, (sprite_it + rend->w), screen);
                    //actualizo sprite_it a la siguiente linea 
                    sprite_it += rend->w; 
                    //Salto la pantalla 
                    screen += m_w;
                    }
                }

            };

            auto& rendcomp = g.template getComponents<RenderComponent_t>();
            std::for_each(begin(rendcomp),end(rendcomp),drawEntity);

        //for(auto& e:entities)



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
    template <typename GameCTX_T>
    bool RenderSystem_t<GameCTX_T>::update(const GameCTX_T& g) const 
    {

        auto screen = m_framebuffer.get();
        
        auto size = m_w*m_h;
        //std::cout << size << "el valor medio es :"<<(size/2)<<"   " << (size/3) << "\n";
        std::fill(screen, screen+size,Kg);
        //std::fill(screen+(size/2)+1,screen + size, Kr); //Rellena el ptr desde inicio (screen hsata el final. )

		drawAllEntities(g); 
		ptc_update(screen);

        return !ptc_process_events();

    }//end update const 
    template <typename GameCTX_T>

    RenderSystem_t<GameCTX_T>::~RenderSystem_t<GameCTX_T>()
    {
        ptc_close();
    }



