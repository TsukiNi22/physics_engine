/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 01/03/2026 by @author Tsukini

File Name:
##  @file Engine.cpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#define _Exception
#define _Write
#define _Attribute
#include "utils/utils.hpp"
#include "woof/Engine.hpp"
#include "woof/factory/GraphicFactory.hpp"
#include "woof/factory/RenderFactory.hpp"
#include "woof/object/IObject.hpp"
#include "woof/object/ActorObject.hpp"
#include "woof/object/ObjectObject.hpp"
#include "woof/object/PropObject.hpp"
#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <cstddef>
#include <memory>
#include <vector>
#include <string>

// Dynamic library to try in priority order
static constexpr const char* graphic_libs[] = {
    "sdl",
    nullptr // sentinel
};
static constexpr const char* render_libs[] = {
    "sdl",
    "opengl",
    "vulkan",
    nullptr // sentinel
};

// Check at the compile time the sentinel existance
static_assert(graphic_libs[std::size(graphic_libs) - 1] == nullptr, "graphic_libs must be nullptr terminated");
static_assert(render_libs[std::size(render_libs) - 1] == nullptr, "render_libs must be nullptr terminated");

cold woof::Engine::Engine(std::size_t verbose)
: _verbose{verbose}
{
    woof::GraphicFactory graphicFactory;
    woof::RenderFactory renderFactory;

    // Try to load the graphic lib and continue will it's failed
    for (std::size_t i = 0; graphic_libs[i]; i++) {
        this->_graphic = graphicFactory.create(graphic_libs[i]);
        if (this->_graphic->isloaded()) {
            if (this->_verbose.load() >= 1) std::cout << utils::write::strong() << graphic_libs[i] << utils::write::reset() << ": graphic dynamic library loaded with success" << std::endl;
            break;
        }
    }
    // No graphic was succefully loaded
    if (!(this->_graphic) || !(this->_graphic->isloaded()))
        throw utils::exception::ErrorException(utils::exception::Code::NoLoadedGraphic);

    // Try to load the render lib and continue will it's failed
    for (std::size_t i = 0; render_libs[i]; i++) {
        this->_render = renderFactory.create(render_libs[i]);
        if (this->_render->isloaded()) {
            if (this->_verbose.load() >= 1) std::cout << utils::write::strong() << render_libs[i] << utils::write::reset() << ": render dynamic library loaded with success" << std::endl;
            break;
        }
    }
    // Check if the render was loaded
    if (!(this->_render) || !(this->_render->isloaded()))
        throw utils::exception::ErrorException(utils::exception::Code::NoLoadedRender);

}

cold woof::Engine::Engine(std::string render_lib, std::size_t verbose)
: _verbose{verbose}
{
    woof::GraphicFactory graphicFactory;
    woof::RenderFactory renderFactory;

    // Try to load the graphic lib and continue will it's failed
    for (std::size_t i = 0; graphic_libs[i]; i++) {
        this->_graphic = graphicFactory.create(graphic_libs[i]);
        if (this->_graphic->isloaded()) {
            if (this->_verbose.load() >= 1) std::cout << utils::write::strong() << graphic_libs[i] << utils::write::reset() << ": graphic dynamic library loaded with success" << std::endl;
            break;
        }
    }
    // Check if the graphic was loaded
    if (!(this->_graphic) || !(this->_graphic->isloaded()))
        throw utils::exception::ErrorException(utils::exception::Code::NoLoadedGraphic);

    // Try to load the render lib selected
    this->_render = renderFactory.create(render_lib);
    // Check if the render was loaded
    if (!(this->_render) || this->_render->isloaded())
        throw utils::exception::ErrorException(utils::exception::Code::NoLoadedRender);

    if (this->_verbose.load() >= 1) std::cout << utils::write::strong() << render_lib << utils::write::reset() << ": dynamic library loaded with success" << std::endl;
}

void woof::Engine::link(const std::shared_ptr<woof::IObject>& object)
{
    // Invalid pointer given
    if (!object)
        throw utils::exception::ErrorException(utils::exception::Code::InvalidPtr);

    // Check if the object is already linked to the engine
    auto it = std::find(this->_global.begin(), this->_global.end(), object);
    if (it != this->_global.end())
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::InvalidObject, "This object is already linked to the engine");

    // Try to cast dynamicly the pointer & add it to the vector
    if (std::dynamic_pointer_cast<woof::ActorObject>(object))         this->_actors.push_back(object);
    else if (std::dynamic_pointer_cast<woof::ObjectObject>(object))   this->_objects.push_back(object);
    else if (std::dynamic_pointer_cast<woof::PropObject>(object))     this->_prop.push_back(object);

    // Invalid object given
    else unlikely {
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::InvalidObject, "Can't identify the category of the object");
    }

    this->_global.push_back(object);
    if (this->_verbose.load() >= 2) std::cout << utils::write::strong() << object.get() << utils::write::reset() << ": object linked to (" << utils::write::strong() << this << utils::write::reset() << ")" << std::endl;
}

void woof::Engine::unlink(const std::shared_ptr<woof::IObject>& object)
{
    // Invalid pointer given
    if (!object)
        throw utils::exception::ErrorException(utils::exception::Code::InvalidPtr);

    // Check if the object is linked to the engine
    auto it = std::find(this->_global.begin(), this->_global.end(), object);
    if (it == this->_global.end())
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::InvalidObject, "This object isn't linked to the object");

    // Create the lambda to remove the shared pointer
    std::function<void(std::vector<std::shared_ptr<woof::IObject>>&)> removeObject =
    [&](std::vector<std::shared_ptr<woof::IObject>>& container) {
        container.erase(std::remove(container.begin(), container.end(), object), container.end());
    };

    // Try to cast dynamicly the pointer & remove it from the vector
    if (std::dynamic_pointer_cast<woof::ActorObject>(object))         removeObject(this->_actors);
    else if (std::dynamic_pointer_cast<woof::ObjectObject>(object))   removeObject(this->_objects);
    else if (std::dynamic_pointer_cast<woof::PropObject>(object))     removeObject(this->_prop);

    // Invalid object given
    else unlikely {
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::InvalidObject, "Can't identify the category of the object");
    }

    removeObject(this->_global);
    if (this->_verbose.load() >= 2) std::cout << utils::write::strong() << object.get() << utils::write::reset() << ": object unlinked from (" << utils::write::strong() << this << utils::write::reset() << ")" << std::endl;
}
