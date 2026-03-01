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
##  @file SDLRender.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef SDLRENDER_H
    #define SDLRENDER_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "IRender.hpp"  // woof::IRender
    #include <string>       // std::string

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class SDLRender: public woof::IRender {
    private:
        /* Nothing */

    public:
        // ---------- Pre-Function -------- //

        // ------------ Function ---------- //

        // ------------ Operator ---------- //
        SDLRender& operator=(const SDLRender& object) = delete;
        SDLRender& operator=(SDLRender&& object) = delete;

        // ---------- Constructor --------- //
        SDLRender() noexcept: IRender("libSDL2.so") {};
        SDLRender(const SDLRender& object) = delete;
        SDLRender(SDLRender&& object) = delete;

        // ----------- Destructor --------- //
        ~SDLRender() = default;
};

} // namespace end
#endif /* SDLRENDER_H */
