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
    void
    InputSystem_t::onkeypress(KeySym key){

        std::cout<<"Se ha presionado una tecla\n";
        ms_keyboard.keyPressedOn(key);
    }

    void
    InputSystem_t::onkeyrelease(KeySym key){

        std::cout<<"Se ha soltado una tecla\n";
        ms_keyboard.keyReleased(key);
    }

    //Constructor
     InputSystem_t::InputSystem_t(){

        ptc_set_on_keypress(onkeypress);
        ptc_set_on_keyrelease(onkeyrelease);
     }   
        



    //Functions 

    


    bool 
    InputSystem_t::update(GameContext_t& g) const {

        //This process events when windows its running. 
        ptc_process_events();

        for(auto& inp : g.getInputComponents()){

            //std::cout<<"Tenemos componentes de input\n";
            //Get pointer to entity that we want to modify
            auto* eptr = g.getEntitybyID(inp.getEntityID());
            if(eptr && eptr->phy){

                //std::cout<<"Acedemos a componentes phys\n";
                //Now we can modify because phycomponent exists inside entity. 
                auto& phy = *(eptr->phy);
                if(ms_keyboard.isKeyPressed(inp.key_LEFT))      phy.vx = -1;
                if(ms_keyboard.isKeyPressed(inp.key_RIGHT))     phy.vx =  1;
                if(ms_keyboard.isKeyPressed(inp.key_DOWN))      phy.vy =  1;
                if(ms_keyboard.isKeyPressed(inp.key_UP))        phy.vy = -1;
            

            }

        }
        return true;
        
    }


        


  



} // namespace EC
