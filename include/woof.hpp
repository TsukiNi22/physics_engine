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
    #include <stddef.h>         // size_t
    #include <stdbool.h>        // boolean
    #include <vector>           // vector
    #include <SDL2/SDL.h>       // SDL_Window
    #include <SDL2/SDL_ttf.h>   // TTF_Font

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
    #define DEFAULT_WORLD_WIDTH 800
    #define DEFAULT_WORLD_HEIGHT 600
    
    /* simulation */
    #define DEFAULT_FPS 30 // max: 1000
    #define FPS_UPDATE_MILLISECONDS 100
    #define INTERRUPT_WAITING_MILLISECONDS 10

    /* assets */
    #define FONT_ARIAL "assets/font/Arial.ttf"

//----------------------------------------------------------------//
/* TYPEDEF */

/* engine */
class Engine {
    private:
        // Content to simulate
        std::vector<Actor*> actors;
        std::vector<Object*> objects;
        std::vector<Prop*> props;

        // window
        SDL_Window *window = nullptr;
        SDL_GLContext glContext;
        std::atomic<bool> closing{false};
        TTF_Font* font = nullptr;
        bool debug_display = false;

        // Simulation
        Stack *stack = nullptr;
        std::atomic<bool> paused{true}; // Thread running status
        std::atomic<bool> running{false}; // Thread status
        std::atomic<bool> interrupted{true}; // Thread aimed status
        size_t frame = 0; // Actual frame

        // --------- Pre-Function --------- //
        void update();
        void loop();
        
        /* window */
        int init(); // Error: KO
        int setup_window_context();
        void destroy_window_context();
        void event();

        /* drawing */
        int draw_text(const char * const text, float scale, float x, float y);
        void debug_draw();
    public:
        // Window
        size_t width = DEFAULT_WIDTH;
        size_t height = DEFAULT_HEIGHT;
        float area_width = DEFAULT_WORLD_WIDTH;
        float area_height = DEFAULT_WORLD_HEIGHT;
        bool resizable = false;

        // Simulation
        std::atomic<size_t> fps = DEFAULT_FPS;
        std::atomic<float> real_fps = -1.f;
       
        // --------- Pre-Function --------- //
        int destroy(bool failsafe);
        int start(); // Error: KO
        void interrupt();
        void pause();
        void play();

        // ----------- Function ----------- //
        void resolve_stack();

        /* add */
        // Can only be done when the engine is interrupted
        int add_actor(Actor * const actor)     {if (running || actor->has_engine()) return KO; actor->set_engine(this); actors.push_back(actor); return OK;} // Error: KO
        int add_object(Object * const object)  {if (running || object->has_engine()) return KO; object->set_engine(this); objects.push_back(object); return OK;} // Error: KO
        int add_prop(Prop * const prop)        {if (running || prop->has_engine()) return KO; prop->set_engine(this); props.push_back(prop); return OK;} // Error: KO
        
        /* remove */
        // Can only be done when the engine is interrupted
        int remove_actor(Actor * const actor)      {if (running) return KO; actors.erase(std::remove(actors.begin(), actors.end(), actor), actors.end()); return OK;} // Error: KO
        int remove_object(Object * const object)   {if (running) return KO; objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end()); return OK;} // Error: KO
        int remove_prop(Prop * const prop)         {if (running) return KO; props.erase(std::remove(props.begin(), props.end(), prop), props.end()); return OK;} // Error: KO

        // ---------- Constructor --------- //
        Engine(); // Default
        Engine(bool is_resizable); // Screen status
        Engine(size_t default_width, size_t default_height); // Screen dimension
        Engine(size_t default_width, size_t default_height, bool is_resizable); // Screen dimension + Screen status

        // ----------- Destructor --------- //
        ~Engine(); // Default
};

#endif /* WOOF_H */
