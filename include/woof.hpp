/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 05/01/2026 by @authorTsukini

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
    #define DEFAULT_WORLD_WIDTH DEFAULT_WIDTH
    #define DEFAULT_WORLD_HEIGHT DEFAULT_HEIGHT
    
    /* simulation */
    #define DEFAULT_FPS 30 // max: 1000
    #define FPS_UPDATE_MILLISECONDS 100
    #define INTERRUPT_WAITING_MILLISECONDS 10

    /* render */
    #define CIRCLE_RESOLUTION 32

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
        std::atomic<bool> closing{false};
        SDL_Window *window = nullptr;
        SDL_GLContext glContext;
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
        void debug_draw();
        int draw_text(const char * const text, float scale, float x, float y);
    
        /* simulate */
        void physics_actor(const Actor * const actor);
        void physics_object(const Object * const object);
    
    public:
        bool alive = false;
        
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
        /* window */
        int destroy(bool failsafe); // Error: KO
        int start(); // Error: KO
        void interrupt();
        void pause();
        void play();
        
        /* stack */
        void resolve_stack();

        /* add */
        // Can only be done when the engine is interrupted
        int add_actor(Actor * const actor); // Error: KO
        int add_object(Object * const object); // Error: KO
        int add_prop(Prop * const prop); // Error: KO
        
        /* remove */
        // Can only be done when the engine is interrupted
        int remove_actor(Actor * const actor); // Error: KO
        int remove_object(Object * const object); // Error: KO
        int remove_prop(Prop * const prop); // Error: KO

        // ---------- Constructor --------- //
        Engine(); // Default
        Engine(bool is_resizable); // Screen status
        Engine(size_t default_width, size_t default_height); // Screen dimension
        Engine(size_t default_width, size_t default_height, bool is_resizable); // Screen dimension + Screen status

        // ----------- Destructor --------- //
        ~Engine(); // Default
};

#endif /* WOOF_H */
