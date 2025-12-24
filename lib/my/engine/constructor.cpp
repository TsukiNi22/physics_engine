/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 24/12/2025 by @authorTsukini

File Name:
##  @file constructor.cpp

File Description:
##  Constructor of the engine
\**************************************************************/

#include "stack.hpp"
#include "woof.hpp"

/* engine */
Engine::Engine() {stack = new Stack(this); init();}
Engine::Engine(bool is_resizable) : resizable(is_resizable) {stack = new Stack(this); init();}
Engine::Engine(size_t default_width, size_t default_height) : width(default_width), height(default_height) {stack = new Stack(this); init();}
Engine::Engine(size_t default_width, size_t default_height, bool is_resizable) : width(default_width), height(default_height), resizable(is_resizable) {stack = new Stack(this); init();}
