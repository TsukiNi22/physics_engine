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
##  @file ObjectObject.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef OBJECTOBJECT_H
    #define OBJECTOBJECT_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "ShapeDescriptor.hpp"  // woof::ShapeDescriptor
    #include "AObject.hpp"          // woof::AObject

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class ObjectObject: public woof::AObject {
    private:
        /* Nothing */

    public:
        /* status */
        bool hitbox = true;     // can be hit?
        bool simulated = true;  // physic simulated?
        bool rendered = true;   // is displayed?

        // ---------- Pre-Function -------- //

        // ------------ Function ---------- //

        // ------------ Operator ---------- //
        ObjectObject& operator=(const ObjectObject& object) = default;
        ObjectObject& operator=(ObjectObject&& object) = default;

        // ---------- Constructor --------- //
        ObjectObject(const woof::ShapeDescriptor& sd) noexcept: woof::AObject(sd) {};
        ObjectObject(const ObjectObject& object) = default;
        ObjectObject(ObjectObject&& object) = default;

        // ----------- Destructor --------- //
        ~ObjectObject() = default;
};

} // namespace end
#endif /* OBJECTOBJECT_H */
