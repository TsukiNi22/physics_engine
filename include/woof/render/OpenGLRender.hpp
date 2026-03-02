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
    #include "IRender.hpp"              // woof::IRender
    #include "../object/IObject.hpp"    // woof::IObject
    #include <memory>                   // std::shared_ptr
    #include <string>                   // std::string

    //----------------------------------------------------------------//
    /* DEFINE */

    /* OpenGL values (ins't loaded with dlsym) */
    #define GL_COLOR_BUFFER_BIT 0x00004000u

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class OpenGLRender: public woof::IRender {
    private:
        /* OpenGL function pointers */
        void (*_glClearColor)(float, float, float, float) = nullptr;
        void (*_glClear)(unsigned int) = nullptr;

    public:
        // ---------- Pre-Function -------- //
        void draw(const std::shared_ptr<woof::IObject>& object) final;

        // ------------ Operator ---------- //
        OpenGLRender& operator=(const OpenGLRender& object) = delete;
        OpenGLRender& operator=(OpenGLRender&& object) = delete;

        // ---------- Constructor --------- //
        OpenGLRender();
        OpenGLRender(const OpenGLRender& object) = delete;
        OpenGLRender(OpenGLRender&& object) = delete;

        // ----------- Destructor --------- //
        ~OpenGLRender() = default;
};

} // namespace end
#endif /* OPENGLRENDER_H */
