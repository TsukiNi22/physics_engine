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
##  @file IObject.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef IOBJECT_H
    #define IOBJECT_H

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class IObject {
    public:
        // ---------- Pre-Function -------- //

        // ------------ Operator ---------- //
        IObject& operator=(const IObject& object) = default;
        IObject& operator=(IObject&& object) = default;

        // ---------- Constructor --------- //
        IObject() = default;
        IObject(const IObject& object) = default;
        IObject(IObject&& object) = default;

        // ----------- Destructor --------- //
        virtual ~IObject() = default;
};

} // namespace end
#endif /* IOBJECT_H */
