#pragma once 

#include <vector>
#include <cmp/inputcomponent.hpp>
#include <cmp/physics.hpp>
#include <cmp/render.hpp>
#include <util/typealias.hpp>


namespace ECS
{

    //La idea es crear una interfaz que me permita ir accediendo a los diferentes vectores de componentes a traves de un puntero de direccion almacenado en un
    //unordered_map. 
    struct ComponentVectorBase_t{};

    template <typename CMP_T>
    struct ComponentVector_t : ComponentVectorBase_t{
        Vec_t<CMP_T> components;
    };


    struct ComponentStorage_t{
        
        explicit ComponentStorage_t(std::size_t initialize) : m_initialsize(initialize){
            
            //m_physicsComponents.reserve(initialize);
            //m_renderComponents.reserve(initialize);
            //m_inputComponents.reserve(10);
        }
        //Delete all ilegal constructor, because i use only a singletone model to storage all component
        ComponentStorage_t(const ComponentStorage_t& ) = delete;
        ComponentStorage_t(ComponentStorage_t&&) = delete;
        ComponentStorage_t& operator=(const ComponentStorage_t& ) = delete;
        ComponentStorage_t& operator=(ComponentStorage_t&& ) = delete;

        //Create Components. 
        PhysicsComponent_t& createPhysicsComponent(EntityID_t eid);
        RenderComponent_t&  createRenderComponent(EntityID_t eid);
        InputComponent_t&  createInputComponent(EntityID_t eid);


        //Template Components.
        
        template <typename CMP_T>
        CMP_T& createComponent(EntityID_t eid){                                     //Creamos un componente de un tipo , de esta forma 
            auto& v = getComponents<CMP_T>();                                       //Se observa con getComponents<> si tenemos el vector de ese tipo de componente
            auto& cmp = v.emplace_back(eid);                                        //Se devuelve con emplace_back , la referencia y la devolvemos 
            return cmp;
         }
        
        template <typename CMP_T>
        Vec_t<CMP_T>& 
        createComponentVector(){
            auto typeID = CMP_T::getComponentTypeID();
            auto v      = std::make_unique<ComponentVector_t<CMP_T>>();
            v->components.reserve(m_initialsize);
            auto* vcptr = v.get();
            m_componentVectors[typeID] = std::move(v);
            return vcptr->components;
        }

        template <typename CMP_T>
        Vec_t<CMP_T>& 
        getComponents(){

            Vec_t<CMP_T>* vcmp{nullptr};
            auto typeID = CMP_T::getComponentTypeID();
            auto it = (m_componentVectors.find(typeID));
            if(it != m_componentVectors.end()){
                auto* aux = static_cast<ComponentVector_t<CMP_T>*>(it->second.get());
                vcmp = &aux->components;
            }
            else{
                vcmp = &createComponentVector<CMP_T>();
            }
            return *vcmp;
        }

        template <typename CMP_T>
        const Vec_t<CMP_T>& getComponents() const{

            Vec_t<CMP_T>* vcmp{nullptr};
            auto typeID = CMP_T::getComponentTypeID();
            auto it = (m_componentVectors.find(typeID));
            if(it != m_componentVectors.end()){
                auto* aux = static_cast<ComponentVector_t<CMP_T>*>(it->second.get());
                vcmp = &aux->components;
            }
            else{
                //vcmp = &createComponentVector<CMP_T>();
                throw "no run this version this way";
            }
            return *vcmp;
        }



        //Physycs Components Get 
        //const Vec_t<PhysicsComponent_t>& getPhysicsComponents() const  {return m_physicsComponents;}
        //      Vec_t<PhysicsComponent_t>& getPhysicsComponents()        {return m_physicsComponents; }

         const Vec_t<PhysicsComponent_t>& getPhysicsComponents() const  {return getComponents<PhysicsComponent_t>();}
               Vec_t<PhysicsComponent_t>& getPhysicsComponents()        {return getComponents<PhysicsComponent_t>(); }

        //Render Components Get        
        //const Vec_t<RenderComponent_t>& getRenderComponents() const  {return m_renderComponents;}
        //       Vec_t<RenderComponent_t>& getRenderComponents()       {return m_renderComponents;} 
         const Vec_t<RenderComponent_t>& getRenderComponents() const  {return getComponents<RenderComponent_t>();}
               Vec_t<RenderComponent_t>& getRenderComponents()        {return getComponents<RenderComponent_t>();} 

        //Input Components Get        
        //const Vec_t<InputComponent_t>&  getInputComponents() const  {return m_inputComponents;}
        //      Vec_t<InputComponent_t>& getInputComponents()        {return m_inputComponents;} 

         const Vec_t<InputComponent_t>&  getInputComponents() const  {return getComponents<InputComponent_t>();}
               Vec_t<InputComponent_t>&  getInputComponents()        {return getComponents<InputComponent_t>();}       

    private:

       
        mapComponent_t<ComponentTypeID_t,UPtr<ComponentVectorBase_t>> m_componentVectors;

        std::size_t m_initialsize{100};

        //Vec_t<PhysicsComponent_t> m_physicsComponents {};
        //Vec_t<RenderComponent_t>  m_renderComponents  {};
        //Vec_t<InputComponent_t>   m_inputComponents   {};



    };
    
} // namespace ECS

