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
##  @file SDLGraphic.cpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#define _Exception
#define _Attribute
#include "utils/utils.hpp"
#include "woof/graphic/SDLGraphic.hpp"
#include <cstddef>
#include <dlfcn.h>

cold woof::SDLGraphic::SDLGraphic()
: AGraphic("libSDL2.so")
{
    // Check if the library was loaded
    if (!this->isloaded())
        return;

    // Load function pointers
    if (!(this->_SDL_Init = reinterpret_cast<int(*)(unsigned int)>(dlsym(this->_lib, "SDL_Init"))))
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::Dlsym, dlerror());
    if (!(this->_SDL_Quit = reinterpret_cast<void(*)()>(dlsym(this->_lib, "SDL_Quit"))))
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::Dlsym, dlerror());
    if (!(this->_SDL_CreateWindow = reinterpret_cast<SDL_Window*(*)(const char*, int, int, int, int, unsigned int)>(dlsym(this->_lib, "SDL_CreateWindow"))))
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::Dlsym, dlerror());
    if (!(this->_SDL_DestroyWindow = reinterpret_cast<void(*)(SDL_Window*)>(dlsym(this->_lib, "SDL_DestroyWindow"))))
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::Dlsym, dlerror());
    if (!(this->_SDL_GetError = reinterpret_cast<const char* (*)()>(dlsym(this->_lib, "SDL_GetError"))))
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::Dlsym, dlerror());
}

cold void woof::SDLGraphic::openWindow(std::size_t width, std::size_t height)
{
    // Check if the library was loaded & not already open
    if (!this->isloaded())
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::InvalidAction, "Can't open a window without the dynamic library loaded");
    else if (this->_isopen)
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::InvalidAction, "Can't reopen a window on the same class");

    // Check the used pointers
    if (!(this->_SDL_Init) || !(this->_SDL_CreateWindow) || !(this->_SDL_GetError))
        throw utils::exception::ErrorException(utils::exception::Code::InvalidPtr);

    // Create the window
    if (this->_SDL_Init(SDL_INIT_VIDEO) != 0)
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::FailOpenWindow, this->_SDL_GetError());
    this->_window = this->_SDL_CreateWindow(
        "Woof Engine",
        100, 100,
        width, height,
        SDL_WINDOW_SHOWN
    );

    // Check the window status
    if (!(this->_window))
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::FailOpenWindow, this->_SDL_GetError());
    this->_isopen = true;
}

cold void woof::SDLGraphic::closeWindow()
{
    // Check if the library was loaded & open
    if (!this->isloaded())
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::InvalidAction, "Can't close a window without the dynamic library loaded");
    else if (!(this->_isopen))
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::InvalidAction, "Can't close a window that dosen't exist");

    // Check the used pointers
    if (!(this->_window) || !(this->_SDL_DestroyWindow) || !(this->_SDL_Quit))
        throw utils::exception::ErrorException(utils::exception::Code::InvalidPtr);

    // Close the window
    this->_SDL_DestroyWindow(_window);
    this->_SDL_Quit();
    this->_window = nullptr;
    this->_isopen = false;
}

woof::SDLGraphic::~SDLGraphic()
{
    // Check if the library was loaded
    if (!this->isloaded())
        return;

    if (this->_isopen) this->closeWindow();
}
