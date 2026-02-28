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
##  @file Engine.cpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#define _Exception
#define _Write
#define _Attribute
#include "woof/Engine.hpp" // Need to be loaded before, due to 'reset'
#include "utils/Utils.hpp"
#include "woof/factory/GraphicFactory.hpp"
#include "woof/object/IObject.hpp"
#include "woof/object/ActorObject.hpp"
#include "woof/object/ObjectObject.hpp"
#include "woof/object/PropObject.hpp"
#include <functional>
#include <iostream>
#include <iterator>
#include <cstddef>
#include <memory>
#include <vector>
#include <string>

// Dynamic library to try in priority order
static constexpr const char* libs[] = {
    "vulkan",
    "opengl",
    nullptr // sentinel
};

// Check at the compile time the sentinel existance
static_assert(libs[std::size(libs) - 1] == nullptr, "libs must be nullptr terminated");

cold woof::Engine::Engine(std::size_t verbose)
{
    this->_verbose = verbose; // Init the verbose level
    woof::GraphicFactory factory;

    // Try to load the graphic lib and continue will it's failed
    for (std::size_t i = 0; libs[i]; i++) {
        this->_graphic = factory.create(libs[i]);
        if (this->_graphic->isloaded()) {
            if (this->_verbose >= 1) std::cout << strong << libs[i] << reset << ": dynamic library loaded with success" << std::endl;
            return;
        }
    }

    // No graphic was succefully loaded
    throw utils::exception::ErrorException(utils::exception::Code::NoLoadedGraphic);
}

cold woof::Engine::Engine(std::string graphic_lib, std::size_t verbose)
{
    this->_verbose = verbose; // Init the verbose level
    woof::GraphicFactory factory;
    this->_graphic = factory.create(graphic_lib);

    // Check if the graphic was loaded
    if (!(this->_graphic->isloaded()))
        throw utils::exception::ErrorException(utils::exception::Code::NoLoadedGraphic);
}

void woof::Engine::link(const std::shared_ptr<woof::IObject>& object)
{
    // Invalid pointer given
    if (!object)
        throw utils::exception::ErrorException(utils::exception::Code::InvalidPtr);

    // Try to cast dynamicly the pointer & add it to the vector
    if (std::dynamic_pointer_cast<woof::ActorObject>(object))         _actors.push_back(object);
    else if (std::dynamic_pointer_cast<woof::ObjectObject>(object))   _objects.push_back(object);
    else if (std::dynamic_pointer_cast<woof::PropObject>(object))     _prop.push_back(object);
    
    // Invalid object given
    else
        throw utils::exception::ErrorException(utils::exception::Code::InvalidObject);
}

void woof::Engine::unlink(const std::shared_ptr<woof::IObject>& object)
{
    // Invalid pointer given
    if (!object)
        throw utils::exception::ErrorException(utils::exception::Code::InvalidPtr);

    // Create the lambda to remove the shared pointer
    std::function<void(std::vector<std::shared_ptr<woof::IObject>>&)> removeObject =
    [&](std::vector<std::shared_ptr<woof::IObject>>& container) {
        container.erase(std::remove(container.begin(), container.end(), object), container.end());
    };

    // Try to cast dynamicly the pointer & remove it from the vector
    if (std::dynamic_pointer_cast<woof::ActorObject>(object))         removeObject(_actors);
    else if (std::dynamic_pointer_cast<woof::ObjectObject>(object))   removeObject(_objects);
    else if (std::dynamic_pointer_cast<woof::PropObject>(object))     removeObject(_prop);

    // Invalid object given
    else
        throw utils::exception::ErrorException(utils::exception::Code::InvalidObject);
}
