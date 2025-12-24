/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 24/12/2025 by @authorTsukini

File Name:
##  @file woof.hpp

File Description:
##  Main header file of the engine
\**************************************************************/

#ifndef WOOF_H
    #define WOOF_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include <stddef.h>     // size_t
    #include <stdbool.h>    // boolean
    #include <vector>       // vector
    
    /* function/class */
    #include "stack.hpp"    // Stack, resolve
    class Stack;
    #include "object.hpp"   // Actor, Object, Prop
    class Actor; class Object; class Prop;
    #include <algorithm>    // remove
    #include <atomic>       // atomic

    //----------------------------------------------------------------//
    /* DEFINE */
    #include "error.hpp"    // KO, OK
    
    /* window */
    #define DEFAULT_WIDTH 800
    #define DEFAULT_HEIGHT 600
    
    /* simulation */
    #define DEFAULT_FPS 30 // max: 1000
    #define FPS_UPDATE_MILLISECONDS 100
    #define INTERRUPT_WAITING_MILLISECONDS 10

//----------------------------------------------------------------//
/* TYPEDEF */

/* engine */
class Engine {
    private:
        // Content to simulate
        std::vector<Actor*> actors;
        std::vector<Object*> objects;
        std::vector<Prop*> props;

        // Simulation
        Stack *stack = nullptr;
        std::atomic<bool> running{false}; // Thread status
        std::atomic<bool> interrupted{true}; // Thread aimed status
        size_t frame = 0; // Actual frame

        // --------- Pre-Function --------- //
        void update();
        void loop();

    public:
        // Window
        size_t width = DEFAULT_WIDTH;
        size_t height = DEFAULT_HEIGHT;
        bool resizable = false;

        // Simulation
        std::atomic<size_t> fps = DEFAULT_FPS;
        std::atomic<float> real_fps = -1.f;
       
        // --------- Pre-Function --------- //
        void start();
        void interrupt();

        // ----------- Function ----------- //
        void resolve_stack();

        /* add */
        // Can only be done when the engine is interrupted
        int add_actor(Actor * const actor)     {if (running || actor->has_engine()) return KO; actor->set_engine(this); actors.push_back(actor); return OK;}
        int add_object(Object * const object)  {if (running || object->has_engine()) return KO; object->set_engine(this); objects.push_back(object); return OK;}
        int add_prop(Prop * const prop)        {if (running || prop->has_engine()) return KO; prop->set_engine(this); props.push_back(prop); return OK;}
        
        /* remove */
        // Can only be done when the engine is interrupted
        int remove_actor(Actor * const actor)      {if (running) return KO; actors.erase(std::remove(actors.begin(), actors.end(), actor), actors.end()); return OK;}
        int remove_object(Object * const object)   {if (running) return KO; objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end()); return OK;}
        int remove_prop(Prop * const prop)         {if (running) return KO; props.erase(std::remove(props.begin(), props.end(), prop), props.end()); return OK;}

        // ---------- Constructor --------- //
        Engine(); // Default
        Engine(bool is_resizable); // Screen status
        Engine(size_t default_width, size_t default_height); // Screen dimension
        Engine(size_t default_width, size_t default_height, bool is_resizable); // Screen dimension + Screen status

        // ----------- Destructor --------- //
        ~Engine(); // Default
};

#endif /* WOOF_H */
