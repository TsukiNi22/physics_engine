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
    #include "IRender.hpp"              // woof::IRender
    #include "../object/IObject.hpp"    // woof::IObject
    #include <memory>                   // std::shared_ptr
    #include <string>                   // std::string

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class SDLRender: public woof::IRender {
    private:
        /* SDL function pointers */

    public:
        // ---------- Pre-Function -------- //
        void draw(const std::shared_ptr<woof::IObject>& object) final;

        // ------------ Operator ---------- //
        SDLRender& operator=(const SDLRender& object) = delete;
        SDLRender& operator=(SDLRender&& object) = delete;

        // ---------- Constructor --------- //
        SDLRender();
        SDLRender(const SDLRender& object) = delete;
        SDLRender(SDLRender&& object) = delete;

        // ----------- Destructor --------- //
        ~SDLRender() = default;
};

} // namespace end
#endif /* SDLRENDER_H */
