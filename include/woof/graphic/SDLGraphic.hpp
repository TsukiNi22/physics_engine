/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 02/03/2026 by @author Tsukini

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
    #define _Attribute
    #include "utils/utils.hpp"  // nodiscard
    #include "AGraphic.hpp"     // woof::AGraphic
    #include <cstddef>          // std::size_t
    #include <string>           // std::string

    //----------------------------------------------------------------//
    /* DEFINE */

    /* SDL values (ins't loaded with dlsym) */
    #define SDL_INIT_VIDEO      0x00000020u
    #define SDL_WINDOW_SHOWN    0x00000004u
    #define SDL_WINDOW_OPENGL   0x00000002u
    #define SDL_WINDOW_VULKAN   0x10000000u

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
        void (*_SDL_GL_SwapWindow)(void*) = nullptr;

    public:
        // ---------- Pre-Function -------- //
        void openWindow(std::string renderLib, std::size_t width, std::size_t height) final;
        void closeWindow() final;
        void update() const final;

        // ------------ Function ---------- //
        nodiscard void *getWindow() const noexcept final {return this->_window;};

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
