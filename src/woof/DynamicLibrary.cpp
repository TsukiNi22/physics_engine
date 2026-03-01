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
##  @file DynamicLibrary.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#define _Exception
#define _Attribute
#include "utils/utils.hpp"
#include "woof/DynamicLibrary.hpp"
#include <iostream>
#include <string>
#include <dlfcn.h>

cold woof::DynamicLibrary::DynamicLibrary(const std::string& lib) noexcept
{
    this->_lib = dlopen(lib.c_str(), RTLD_NOW);
    if (!(this->_lib)) unlikely {
        utils::exception::CustomException e(utils::exception::Type::Error, utils::exception::Code::Dlopen, dlerror());
        std::cout << e.formated() << std::endl;
    }
}

cold woof::DynamicLibrary::~DynamicLibrary() noexcept
{
    if (this->_lib && OK != dlclose(this->_lib)) unlikely {
        utils::exception::CustomException e(utils::exception::Type::Error, utils::exception::Code::Dlclose, dlerror());
        std::cout << e.formated() << std::endl;
    }
}
