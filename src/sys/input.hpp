#pragma once 

#include <util/typealias.hpp>
#include <util/keyboard.hpp>

namespace ECS
{
    
    struct  GameContext_t ;
    
    struct InputSystem_t {

        explicit InputSystem_t();
        
        
        bool update( GameContext_t& g) const ;

        private:
        
        //Functions 
        static void onkeypress(KeySym key);
        static void onkeyrelease(KeySym key);
        //Get my keyboard. 
        //This build before the main is executed and destroy when main is finished. BUild and declare space. 
        
        inline static KeyBoard_t ms_keyboard {};  

    };



} // namespace EC






