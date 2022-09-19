
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
    bool
    RenderSystem_t<GameCTX_T>::clippingSprite2D(uint32_t& h, uint32_t& w, uint32_t& x, uint32_t& y, uint32_t rh, uint32_t rw,
    uint32_t& left_off, uint32_t& up_off) const {
           //Horizontal clipping rules 
                    

                    if( x > m_w){                   //left cliping
                       left_off = 0 - x;
                     
                       if(left_off >= w)return false;
                            // nothing to draw
                        x = 0;
                        w -= left_off;
                          

                    }else if ( x + rw >=  m_w){      //Right Cliping. 
                        uint32_t right_off = x + w - m_w;
                        if(right_off >= w)     return false;        //Nothing to draw. 
                        w -= right_off;
                         
                    }
                    
                    //Vertical cliping. 
                    if( y >= m_h){                   //up cliping
                       up_off = 0 - y;
                       if(up_off >= h) return false;     // nothing to draw
                        y = 0;
                        h -= up_off;
                         

                    }else if ( y + rh >=  m_h){      //down Cliping. 
                        uint32_t down_off = y + h - m_h;
                        if(down_off >= h)  return false;       //Nothing to draw. 
                        h -= down_off;
                        
                    }
                    return true;

    } 


    template <typename GameCTX_T>
    void 
    RenderSystem_t<GameCTX_T>::drawAllEntities(const GameCTX_T& g) const {

        //Devuelve el vector de entidades que dibujaremos una a una
        
        auto screen = m_framebuffer.get();
        
            //auto getPosicionScreenXY = [&](uint32_t x, uint32_t y){return screen + y*m_w +x;};
            //funcion lambda para simplificar los calculos. usamos & para referencia o = para copia. 
            auto drawEntity = [&](const RenderComponent_t& rc ){
            //Es decir cada vez que queramos dibuajr todas las entidades, neceitamos obtener el puntero
            //de la pantalla , para poder ubicarnos , el puntero de la pantalla siempre va a tener un origen,begin(), 
            //m_framebuffer
               auto* eptr =   g.getEntitybyID(rc.getEntityID());

                
                if(eptr){
                    screen = m_framebuffer.get();    
                    auto* phy = eptr->template getComponent<PhysicsComponent_t>();
                    auto* rend = eptr->template getComponent<RenderComponent_t>();
                    //Other wey auto& e = *ptr;
                    
                    uint32_t h{rend->h};
                    uint32_t w{rend->w};
                    uint32_t x{phy->x};
                    uint32_t y{phy->y};

                    uint32_t left_off{0};
                    uint32_t up_off{0};

                    
                    if(clippingSprite2D(h,w,x,y,rend->h,rend->w,left_off,up_off))
                    {
                    screen = getPosicionScreenXY(x, y);
                    //puntero a la pantalla 
                    //screen += e.y*m_w +e.x; //necesito saltar y veces para colocarme en su sitio, y despues solamente recorrer la X. 
                    //ya estoy colocado en la pantalla, ahora necesito recorrecor mi sprite 
                    //Recorro el alto, y voy rellando el ancho , copiando my entiti al screen. 
                    auto sprite_it = begin(rend->sprite) + up_off*rend->w + left_off;
                    //  auto sprite_it = e.sprite.data() otra forma igual al hacer. 
                    while(h--)
                    {
                       for(uint32_t i = 0; i<w; ++i ){
                            if(*sprite_it & 0xFF000000)
                                *screen = *sprite_it;
                        ++sprite_it;        
                        ++screen;
                       }
                        //cuando tenemos un vector y queremos copiar, usamos esta tecnica. 
                        //std::copy(sprite_it, (sprite_it + rend->w), screen);
                        //actualizo sprite_it a la siguiente linea 
                        sprite_it += rend->w -w ; 
                        //Salto la pantalla 
                        screen += m_w - w;
                        }
                }
            }

            };

            auto& rendcomp = g.template getComponents<RenderComponent_t>();
            std::for_each(begin(rendcomp),end(rendcomp),drawEntity);

        //for(auto& e:entities)



    }

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



