#pragma once 
#include <cstdint>
#include <ecs/util/typealias.hpp>

// This class its like abstrac class, all components will inherit from this class to build unique components which 
//are identificate by ID. This solution , can help avoid components not be part of entities. 
namespace ECS{


struct Component_t {
    
    explicit Component_t(EntityID_t eid) : entityID{eid}
    {}


    constexpr EntityID_t getEntityID() const noexcept{ return entityID;}

    
    
private:

    EntityID_t  entityID{0};
    inline static ComponentTypeID_t nextTypeID {0};
};

//CRTP Pattern. 
template <typename T>
struct ComponentBase_t : Component_t{

    explicit ComponentBase_t(EntityID_t eid) : Component_t(eid){};


      //Dado un componente, sacamos su entidad, y si existe un componente del tipo desado de la entidad. 
    template <typename GameCTX_T,typename TypeCMP_T, typename DesireTypeCMP_T>
    DesireTypeCMP_T* getRequieredOtherTypeComponent(GameCTX_T& g, const TypeCMP_T& icmp) const {

            auto* e = g.getEntitybyID(icmp.template getEntityID());
        if(e)
            return e->template getComponent<DesireTypeCMP_T>();
        return nullptr;

    }

  
    static ComponentTypeID_t getComponentTypeID() noexcept {
        static ComponentTypeID_t typeID {++nextTypeID};
        return typeID;
    }

};

}//Namespace ECS 