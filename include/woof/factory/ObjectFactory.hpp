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
##  @file ObjectFactory.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef OBJECTFACTORY_H
    #define OBJECTFACTORY_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "../object/ShapeDescriptor.hpp"    // woof::ShapeDescriptor
    #include "../object/IObject.hpp"            // woof::IObject
    #include "AFactory.hpp"                     // woof::AFactory

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class ObjectFactory: public woof::AFactory<woof::IObject, const woof::ShapeDescriptor&> {
    public:
        // ------------ Operator ---------- //
        ObjectFactory& operator=(const ObjectFactory& object) = delete;
        ObjectFactory& operator=(ObjectFactory&& object) = delete;

        // ---------- Constructor --------- //
        ObjectFactory() noexcept;
        ObjectFactory(const ObjectFactory& object) = delete;
        ObjectFactory(ObjectFactory&& object) = delete;

        // ----------- Destructor --------- //
        ~ObjectFactory() = default;
};

} // namespace end
#endif /* OBJECTFACTORY_H */
