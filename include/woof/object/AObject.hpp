/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 28/02/2026 by @author Tsukini

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
    #include "ShapeDescriptor.hpp"  // woof::ShapeDescriptor, woof::ShapeId
    #include "IObject.hpp"          // woof::IObject
    #include <vector>               // std::vector

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class AObject: public woof::IObject {
    protected:
        /* shape data */
        woof::ShapeDescriptor _sd;

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
        /* status */
        //bool hitbox = true;     // limited to: Actor, Object, Prop
        //bool input = true;      // limited to: Actor
        //bool simulated = true;  // limited to: Actor, Object
        //bool rendered = true;   // limited to: Actor, Object, Prop
        int layout = 0; // display order

        // ---------- Pre-Function -------- //

        // ------------ Function ---------- //

        // ------------ Operator ---------- //
        AObject& operator=(const AObject& object) = default;
        AObject& operator=(AObject&& object) = default;

        // ---------- Constructor --------- //
        AObject(const woof::ShapeDescriptor& sd) noexcept: _sd{sd} {};
        AObject(const AObject& object) = default;
        AObject(AObject&& object) = default;

        // ----------- Destructor --------- //
        ~AObject() = default;
};

} // namespace end
#endif /* AOBJECT_H */
