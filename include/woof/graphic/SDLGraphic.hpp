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
    #include "IGraphic.hpp" // woof::IGraphic
    #include <string>       // std::string

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class SDLGraphic: public woof::IGraphic {
    private:
        /* Nothing */

    public:
        // ---------- Pre-Function -------- //

        // ------------ Function ---------- //

        // ------------ Operator ---------- //
        SDLGraphic& operator=(const SDLGraphic& object) = delete;
        SDLGraphic& operator=(SDLGraphic&& object) = delete;

        // ---------- Constructor --------- //
        SDLGraphic() noexcept: IGraphic("libSDL2.so") {};
        SDLGraphic(const SDLGraphic& object) = delete;
        SDLGraphic(SDLGraphic&& object) = delete;

        // ----------- Destructor --------- //
        ~SDLGraphic() = default;
};

} // namespace end
#endif /* SDLGRAPHIC_H */
