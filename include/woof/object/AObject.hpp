/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 27/02/2026 by @author Tsukini

File Name:
##  @file AObject.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef AOBJECT_H
    #define AOBJECT_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "IObject.hpp" // woof::IObject

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class AObject: public woof::IObject {
    private:
        /* physics */
        float mass = 1.f; // kg
        vector2 velocity{0.f, 0.f};
        vector2 acceleration{0.f, 0.f};

        /* style */
        float r = 0.f;
        float g = 0.f;
        float b = 0.f;
        bool fill = true;

    public:
        // ---------- Pre-Function -------- //

        // ------------ Function ---------- //

        // ------------ Operator ---------- //
        AObject& operator=(const AObject& object) = delete;
        AObject& operator=(AObject&& object) = delete;

        // ---------- Constructor --------- //
        AObject() = default;
        AObject(const AObject& object) = delete;
        AObject(AObject&& object) = delete;

        // ----------- Destructor --------- //
        ~AObject() = default;
};

} // namespace end
#endif /* AOBJECT_H */
