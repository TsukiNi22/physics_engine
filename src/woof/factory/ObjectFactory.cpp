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
##  @file ObjectFactory.cpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#include "woof/factory/ObjectFactory.hpp"
#include "woof/object/ShapeDescriptor.hpp"
#include "woof/object/IObject.hpp"
#include "woof/object/ActorObject.hpp"
#include "woof/object/ObjectObject.hpp"
#include "woof/object/PropObject.hpp"

woof::ObjectFactory::ObjectFactory() noexcept
{
    this->_registry = {
        {"actor",   [](const woof::ShapeDescriptor& od){return std::make_shared<woof::ActorObject>(od);}},
        {"object",  [](const woof::ShapeDescriptor& od){return std::make_shared<woof::ObjectObject>(od);}},
        {"prop",    [](const woof::ShapeDescriptor& od){return std::make_shared<woof::PropObject>(od);}},
    };
}
