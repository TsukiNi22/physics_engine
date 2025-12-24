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
##  @file update.cpp

File Description:
##  Update of the engine
\**************************************************************/

#include "object.hpp"
#include "woof.hpp"
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <algorithm>

void Engine::event() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            interrupted = true;
            closing = true;
        } else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_F1) {
            debug_display = !debug_display;
        }
    }
}

void Engine::update() {
    // Do the event
    event();

    // Clear the display
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Sort layout
    std::sort(actors.begin(), actors.end(), [](const Actor *a, const Actor *b) {return a->layout < b->layout;});
    std::sort(objects.begin(), objects.end(), [](const Object *a, const Object *b) {return a->layout < b->layout;});
    std::sort(props.begin(), props.end(), [](const Prop *a, const Prop *b) {return a->layout < b->layout;});

    // Draw item
    for (Actor *actor: actors) actor->draw();
    for (Object *object: objects) object->draw();
    for (Prop *prop: props) prop->draw();

    // Apply physics
    for (Actor *actor: actors) actor->physics();
    for (Object *object: objects) object->physics();
    
    // Debug drawing
    if (debug_display) debug_draw();

    // Invert the drawing buffer & the display buffer
    SDL_GL_SwapWindow(window);
}
