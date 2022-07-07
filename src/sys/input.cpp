#include <sys/input.hpp>

extern "C" {
    #include <tinyPTC/src/tinyptc.h>
}

namespace ECS
{
    //Static Functions 
    void
    InputSystem_t::onkeypress(KeySym key){

        ms_keyboard.keyPressedOn(key);
    }

    void
    InputSystem_t::onkeyrelease(KeySym key){

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

        return true;
        
    }


        


  



} // namespace EC
