/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 02/03/2026 by @author Tsukini

File Name:
##  @file SDLRender.cpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#define _Exception
#define _Attribute
#include "utils/utils.hpp"
#include "woof/render/SDLRender.hpp"
#include "woof/object/IObject.hpp"
#include <memory>
#include <dlfcn.h>

cold woof::SDLRender::SDLRender()
: IRender("libSDL2.so")
{
    // Check if the library was loaded
    if (!this->isloaded())
        return;

    // Load function pointers
}

hot void woof::SDLRender::draw(const std::shared_ptr<woof::IObject>& object)
{
    // Check if the library was loaded & open
    if (!this->isloaded())
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::InvalidAction, "Can't close a window without the dynamic library loaded");

    // Check the used pointers
    if (false) unlikely {
        throw utils::exception::ErrorException(utils::exception::Code::InvalidPtr);
    } else if (!(object.get())) unlikely {
        throw utils::exception::ErrorException(utils::exception::Code::InvalidPtr);
    }

    // Draw

}
