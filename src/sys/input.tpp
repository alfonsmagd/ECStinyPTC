#include <sys/input.hpp>
#include <X11/X.h>
#include <X11/keysym.h>
#include <util/gamecontext.hpp>
#include <iostream>

extern "C" {
    #include <tinyPTC/src/tinyptc.h>
}

namespace ECS
{
    //Static Functions 
    template <typename GameCTX_T>
    void
    InputSystem_t<GameCTX_T>::onkeypress(KeySym key){

        std::cout<<"Se ha presionado una tecla\n";
        ms_keyboard.keyPressedOn(key);
    }

    template <typename GameCTX_T>
    void
    InputSystem_t<GameCTX_T>::onkeyrelease(KeySym key){

        std::cout<<"Se ha soltado una tecla\n";
        ms_keyboard.keyReleased(key);
    }

    //Constructor
    template <typename GameCTX_T>
     InputSystem_t<GameCTX_T>::InputSystem_t(){

        ptc_set_on_keypress(onkeypress);
        ptc_set_on_keyrelease(onkeyrelease);
     }   
        
    //Functions 
    template <typename GameCTX_T>
    bool 
    InputSystem_t<GameCTX_T>::update(GameCTX_T& g) const {

        //This process events when windows its running. 
        ptc_process_events();

        for(auto& inp : g.template getComponents<InputComponent_t>()){

            //std::cout<<"Tenemos componentes de input\n";
            //Get pointer to entity that we want to modify
            auto* eptr = g.getEntitybyID(inp.getEntityID());
            if(eptr){
                //std::cout<<"Acedemos a componentes phys\n";
                //Now we can modify because phycomponent exists inside entity. 
                auto* phy = eptr->template getComponent<PhysicsComponent_t>();
                //auto& phy = *(eptr->phy);
                phy->vx = phy->vy = 0;
                if(ms_keyboard.isKeyPressed(inp.key_LEFT))      phy->vx = -1; 
                if(ms_keyboard.isKeyPressed(inp.key_RIGHT))     phy->vx =  1;   
                if(ms_keyboard.isKeyPressed(inp.key_DOWN))      phy->vy =  1; 
                if(ms_keyboard.isKeyPressed(inp.key_UP))        phy->vy = -1; 

            }

        }
        return true;
        
    }


        


  



} // namespace EC
