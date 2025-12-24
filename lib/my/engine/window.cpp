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
##  @file window.cpp

File Description:
##  Handle the window creation & destruction
\**************************************************************/

#include "woof.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdbool.h>

int Engine::init() {
    // Context OpenGL 2.1
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    // Create the window
    window = SDL_CreateWindow(
        "Woof Engine", // Title
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // Position
        width, height, // Size
        SDL_WINDOW_OPENGL // Context
    );
    if (!window) return err_custom("Error during the creation of the window", KO, ERR_INFO);

    // Init the text texturer
    if (TTF_Init() != OK) return err_custom(TTF_GetError(), KO, ERR_INFO);
    
    // Load the default font
    font = TTF_OpenFont(FONT_ARIAL, 12);
    if (!font) return err_custom(TTF_GetError(), KO, ERR_INFO);
    
    return OK;
}

int Engine::destroy(bool failsafe) {
    if (!window) {
        if (failsafe) return KO;
        else return err_custom("No valid existing window, can't destroy it", KO, ERR_INFO);
    }
    if (running) interrupt();
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();
    window = nullptr;
    return OK;
}

int Engine::setup_window_context() {
    if (!window) return err_custom("Can't create a context without a created window", KO, ERR_INFO);
    
    // Create the window Context
    glContext = SDL_GL_CreateContext(window);

    // Setup the rendering area
    glViewport(
        0, 0, // Position
        width, height // Size
    );

    // Setup the 2D projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D( // Visible area
        area_width / -2.f, area_width / 2.f, // x
        area_height / -2.f, area_height / 2.f // y
    );
    glMatrixMode(GL_MODELVIEW);

    return OK;
}
    
void Engine::destroy_window_context() {
    SDL_GL_DeleteContext(glContext);
}
