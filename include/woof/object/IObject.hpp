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
##  @file IObject.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef IOBJECT_H
    #define IOBJECT_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include <iostream>

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class IObject {
    public:
        // ---------- Pre-Function -------- //

        // ------------ Function ---------- //

        // ------------ Operator ---------- //
        IObject& operator=(const IObject& object) = delete;
        IObject& operator=(IObject&& object) = delete;

        // ---------- Constructor --------- //
        IObject() = default;
        IObject(const IObject& object) = delete;
        IObject(IObject&& object) = delete;

        // ----------- Destructor --------- //
        virtual ~IObject() = 0;
};

} // namespace end
#endif /* IOBJECT_H */
