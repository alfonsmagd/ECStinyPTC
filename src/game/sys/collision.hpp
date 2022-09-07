#pragma once 

#include "cstdint"
#include <ecs/util/gamecontext.hpp>

//Fordward declaration. 
struct ColliderComponent_t;


    template<typename GameCTX_T>
    
    struct CollisionSystem_t {

        explicit CollisionSystem_t(uint32_t h, uint32_t w);
        
        
        //se actualiza el update de nuestro colissionsystem_t
        bool update( GameCTX_T& g) const ;
        PhysicsComponent_t* getRequieredPhyComponent(GameCTX_T& g, const ColliderComponent_t& cll) const;

        private:

        const uint32_t m_h{0}, m_w{0};

    };





