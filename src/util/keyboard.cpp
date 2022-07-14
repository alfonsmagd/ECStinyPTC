#include "keyboard.hpp"
#include <iostream>
namespace ECS {


     //This function returns is Key is pressed. 
    bool 
    KeyBoard_t::isKeyPressed(KeySym key)  noexcept{

        
        if(auto it = getMapIterator(key))
            return (*it)->second;
        return false;
        
    }

    //This function help us get iteratorMap. 
    KeyBoard_t::OptionalIteratorUMap 
    KeyBoard_t::getMapIterator(KeySym key) noexcept{

      auto it = m_pressedkey.find(key);
      if(it != m_pressedkey.end())
            return it;
        return{};
    }

    //Key is pressed. 
    void 
    KeyBoard_t::keyPressedOn(KeySym key)   noexcept{

       
        if(auto it = getMapIterator(key))
           (*it)->second = true;

    }

    //Key is realeased. 
    void 
    KeyBoard_t::keyReleased (KeySym key)   noexcept{

       if(auto it = getMapIterator(key))
           (*it)->second = false;
    }


}//END ECS