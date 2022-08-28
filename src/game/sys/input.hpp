#pragma once 

#include <ecs/util/typealias.hpp>
#include <ecs/util/keyboard.hpp>


    
   template <typename GameCTX_T>
    
    struct InputSystem_t {

        explicit InputSystem_t();
        
        
        bool update( GameCTX_T& g) const ;

        private:
        
        //Functions 
        static void onkeypress(KeySym key);
        static void onkeyrelease(KeySym key);
        //Get my keyboard. 
        //This build before the main is executed and destroy when main is finished. BUild and declare space. 
        
        inline static ECS::KeyBoard_t ms_keyboard {};  

    };










