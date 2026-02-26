/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 26/02/2026 by @author Tsukini

File Name:
##  @file OpenGLGraphic.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef OPENGLGRAPHIC_H
    #define OPENGLGRAPHIC_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "AGraphic.hpp" // woof::AGraphic

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class OpenGLGraphic: virtual public woof::AGraphic {
    private:
        /* Nothing */

    public:
        // ---------- Pre-Function -------- //

        // ------------ Function ---------- //

        // ------------ Operator ---------- //
        OpenGLGraphic& operator=(const OpenGLGraphic& object) = delete;
        OpenGLGraphic& operator=(OpenGLGraphic&& object) = delete;

        // ---------- Constructor --------- //
        OpenGLGraphic() noexcept;
        OpenGLGraphic(const OpenGLGraphic& object) = delete;
        OpenGLGraphic(OpenGLGraphic&& object) = delete;

        // ----------- Destructor --------- //
        ~OpenGLGraphic() = default;
};

} // namespace end
#endif /* OPENGLGRAPHIC_H */
