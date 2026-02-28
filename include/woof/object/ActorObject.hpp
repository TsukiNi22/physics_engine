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
##  @file ActorObject.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef ACTOROBJECT_H
    #define ACTOROBJECT_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "ShapeDescriptor.hpp"  // woof::ShapeDescriptor
    #include "AObject.hpp"          // woof::AObject

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class ActorObject: public woof::AObject {
    private:
        /* Nothing */

    public:
        /* status */
        bool hitbox = true;     // can be hit?
        bool input = true;      // take input?
        bool simulated = true;  // physic simulated?
        bool rendered = true;   // is displayed?

        // ---------- Pre-Function -------- //

        // ------------ Function ---------- //

        // ------------ Operator ---------- //
        ActorObject& operator=(const ActorObject& object) = default;
        ActorObject& operator=(ActorObject&& object) = default;

        // ---------- Constructor --------- //
        ActorObject(const woof::ShapeDescriptor& sd) noexcept: woof::AObject(sd) {};
        ActorObject(const ActorObject& object) = default;
        ActorObject(ActorObject&& object) = default;

        // ----------- Destructor --------- //
        ~ActorObject() = default;
};

} // namespace end
#endif /* ACTOROBJECT_H */
