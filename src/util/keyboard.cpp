#include "keyboard.hpp"

namespace ECS {


     //This function returns is Key is pressed. 
    bool KeyBoard_t::isKeyPressed(KeySym key) const noexcept{

        auto it = m_pressedkey.find(key);

        if(it != m_pressedkey.end())
            return it->second;

        return false;
            
    }
    //Key is pressed. 
    void KeyBoard_t::keyPressedOn(KeySym key)   noexcept{

        //dangerous!!!!!! operator[] if key not exist, [] create a new key. 
        m_pressedkey[key] = true;

    }


    //Key is realeased. 
    void KeyBoard_t::keyReleased (KeySym key)   noexcept{
        //dangerous!!!!!! operator[] if key not exist, [] create a new key. 
        m_pressedkey[key] = false;
    }


}//END 