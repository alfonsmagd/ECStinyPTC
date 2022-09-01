#pragma once

#include "cstdint"
#include <ecs/cmp/component.hpp>
#include <X11/X.h>
#include <X11/keysym.h>




struct InputComponent_t  : public ECS::ComponentBase_t<InputComponent_t>{

   explicit InputComponent_t (ECS::EntityID_t eid) : ComponentBase_t(eid) {};

   //static ECS::ComponentTypeID_t getComponentTypeID() noexcept{
   // return static_cast<ECS::ComponentTypeID_t>(1);
   //}
    
    //Declarate differntes inputs components 

    KeySym key_LEFT         {XK_o};
    KeySym key_RIGHT        {XK_p};
    KeySym key_UP           {XK_q};
    KeySym key_DOWN         {XK_a};
        

    };
