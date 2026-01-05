/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 05/01/2026 by @authorTsukini

File Name:
##  @file stack.cpp

File Description:
##  Handle the resovle of the stack
\**************************************************************/

#include "stack.hpp"
#include "woof.hpp"
#include <stdbool.h>

void Stack::resolve() {
    // Execute each task
    for (const task_t * task: stack) {
        // Nothing
    }

    clear(); // clear the stack
}

void Engine::resolve_stack() {
    bool status = false;
    
    // Interrupt if it's running
    if (!paused) {
        pause();
        status = true;
    }

    // Resolve the stack
    stack->resolve();

    // Restart if tha twas interrupted
    if (status) play();
}
