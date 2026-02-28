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
##  @file PropObject.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef PROPOBJECT_H
    #define PROPOBJECT_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "ShapeDescriptor.hpp"  // woof::ShapeDescriptor
    #include "AObject.hpp"          // woof::AObject

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class PropObject: public woof::AObject {
    private:
        /* Nothing */

    public:
        /* status */
        bool hitbox = true;     // can be hit?
        bool rendered = true;   // is displayed?

        // ---------- Pre-Function -------- //

        // ------------ Function ---------- //

        // ------------ Operator ---------- //
        PropObject& operator=(const PropObject& object) = default;
        PropObject& operator=(PropObject&& object) = default;

        // ---------- Constructor --------- //
        PropObject(const woof::ShapeDescriptor& sd) noexcept: woof::AObject(sd) {};
        PropObject(const PropObject& object) = default;
        PropObject(PropObject&& object) = default;

        // ----------- Destructor --------- //
        ~PropObject() = default;
};

} // namespace end
#endif /* PROPOBJECT_H */
