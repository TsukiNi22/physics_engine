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
##  @file engine.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef ENGINE_INCLUDE_H
    #define ENGINE_INCLUDE_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* global */
    #include "woof/Engine.hpp"
    #include "woof/Vector.hpp"

    /* factory */
    #include "woof/factory/IFactory.hpp"
    #include "woof/factory/AFactory.hpp"
    #include "woof/factory/GraphicFactory.hpp"
    #include "woof/factory/ObjectFactory.hpp"

    /* object */
    #include "woof/object/ShapeDescriptor.hpp"
    #include "woof/object/IObject.hpp"
    #include "woof/object/AObject.hpp"
    #include "woof/object/ActorObject.hpp"
    #include "woof/object/ObjectObject.hpp"
    #include "woof/object/PropObject.hpp"

#endif /* ENGINE_INCLUDE_H */
