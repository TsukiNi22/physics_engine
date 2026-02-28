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
##  @file OpenGLRender.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef OPENGLRENDER_H
    #define OPENGLRENDER_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "ARender.hpp" // woof::ARender

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class OpenGLRender: public woof::ARender {
    private:
        /* Nothing */

    public:
        // ---------- Pre-Function -------- //

        // ------------ Function ---------- //

        // ------------ Operator ---------- //
        OpenGLRender& operator=(const OpenGLRender& object) = delete;
        OpenGLRender& operator=(OpenGLRender&& object) = delete;

        // ---------- Constructor --------- //
        OpenGLRender() noexcept;
        OpenGLRender(const OpenGLRender& object) = delete;
        OpenGLRender(OpenGLRender&& object) = delete;

        // ----------- Destructor --------- //
        ~OpenGLRender() = default;
};

} // namespace end
#endif /* OPENGLRENDER_H */
