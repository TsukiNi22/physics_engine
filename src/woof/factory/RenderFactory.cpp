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
##  @file RenderFactory.cpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#include "woof/factory/RenderFactory.hpp"
#include "woof/render/SDLRender.hpp"
#include "woof/render/OpenGLRender.hpp"
#include "woof/render/VulkanRender.hpp"
#include <memory>

woof::RenderFactory::RenderFactory() noexcept
{
    this->_registry = {
        {"sdl",  [](){return std::make_shared<woof::SDLRender>();}},
        {"opengl",  [](){return std::make_shared<woof::OpenGLRender>();}},
        {"vulkan",  [](){return std::make_shared<woof::VulkanRender>();}},
    };
}
