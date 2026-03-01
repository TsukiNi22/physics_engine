/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 01/03/2026 by @author Tsukini

File Name:
##  @file SDLGraphic.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef SDLGRAPHIC_H
    #define SDLGRAPHIC_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "AGraphic.hpp" // woof::AGraphic
    #include <cstddef>      // std::size_t
    #include <string>       // std::string

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class SDLGraphic: public woof::AGraphic {
    private:
        /* SDL values */
        struct SDL_Window;
        struct SDL_Renderer;
        SDL_Window*   _window   = nullptr;
        SDL_Renderer* _renderer = nullptr;

        /* SDL function pointers */
        int  (*_SDL_Init)(unsigned int) = nullptr;
        void (*_SDL_Quit)(void) = nullptr;
        SDL_Window* (*_SDL_CreateWindow)(const char*, int, int, int, int, unsigned int) = nullptr;
        void (*_SDL_DestroyWindow)(SDL_Window*) = nullptr;
        const char* (*_SDL_GetError)(void) = nullptr;

    public:
        // ---------- Pre-Function -------- //
        void openWindow(std::size_t width = 800, std::size_t height = 600) final;
        void closeWindow() final;

        // ------------ Function ---------- //

        // ------------ Operator ---------- //
        SDLGraphic& operator=(const SDLGraphic& object) = delete;
        SDLGraphic& operator=(SDLGraphic&& object) = delete;

        // ---------- Constructor --------- //
        SDLGraphic();
        SDLGraphic(const SDLGraphic& object) = delete;
        SDLGraphic(SDLGraphic&& object) = delete;

        // ----------- Destructor --------- //
        ~SDLGraphic();
};

} // namespace end
#endif /* SDLGRAPHIC_H */
