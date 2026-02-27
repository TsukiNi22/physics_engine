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
##  @file GraphicFactory.cpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#include "woof/factory/GraphicFactory.hpp"
#include "woof/graphic/OpenGLGraphic.hpp"
#include "woof/graphic/VulkanGraphic.hpp"

woof::GraphicFactory::GraphicFactory() noexcept
{
    this->_registry = {
        {"opengl",  [](){return std::make_shared<woof::OpenGLGraphic>();}},
        {"vulkan",  [](){return std::make_shared<woof::VulkanGraphic>();}},
    };
}
