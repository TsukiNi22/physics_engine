/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 27/02/2026 by @author Tsukini

File Name:
##  @file Engine.cpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#define _Exception
#define _Attribute
#include "utils/Utils.hpp"
#include "woof/Engine.hpp"
#include "woof/factory/GraphicFactory.hpp"
#include <iterator>
#include <cstddef>
#include <memory>
#include <string>

// Dynamic library to try in priority order
static constexpr const char* libs[] = {
    "vulkan",
    "opengl",
    nullptr // sentinel
};

// Check at the compile time the sentinel existance
static_assert(libs[std::size(libs) - 1] == nullptr, "libs must be nullptr terminated");

cold woof::Engine::Engine()
{
    woof::GraphicFactory factory;

    // Try to load the graphic lib and continue will it's failed
    for (std::size_t i = 0; libs[i]; i++) {
        this->_graphic = factory.create(libs[i]);
        if (this->_graphic->isloaded())
            return;
    }

    // No graphic was succefully loaded
    throw utils::exception::ErrorException(utils::exception::Code::NoLoadedGraphic);
}

cold woof::Engine::Engine(std::string graphic_lib)
{
    woof::GraphicFactory factory;
    this->_graphic = factory.create(graphic_lib);

    // Check if the graphic was loaded
    if (!(this->_graphic->isloaded()))
        throw utils::exception::ErrorException(utils::exception::Code::NoLoadedGraphic);
}
