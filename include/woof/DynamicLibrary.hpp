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
##  @file DynamicLibrary.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef DYNAMICLIBRARY_H
    #define DYNAMICLIBRARY_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #define _Exception
    #define _Attribute
    #include "utils/utils.hpp"  // utils::exception::CustomException, utils::exception::Type, utils::exception::Code, cold, nodiscard
    #include <string>           // std::string
    #include <dlfcn.h>          // dlsym, dlerror

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class DynamicLibrary {
    protected:
        void* _lib = nullptr;

        // ------------ Function ---------- //
        template<typename T>
        static cold T loadFunction(void* lib, const char* name)
        {
            T func = reinterpret_cast<T>(dlsym(lib, name));
            if (!func)
                throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::Dlsym, dlerror());
            return func;
        }

    public:
        // ------------ Function ---------- //
        nodiscard bool isloaded() const noexcept {return this->_lib;};

        // ------------ Operator ---------- //
        DynamicLibrary& operator=(const DynamicLibrary& object) = delete;
        DynamicLibrary& operator=(DynamicLibrary&& object) = delete;

        // ---------- Constructor --------- //
        DynamicLibrary(const std::string& lib) noexcept;
        DynamicLibrary(const DynamicLibrary& object) = delete;
        DynamicLibrary(DynamicLibrary&& object) = delete;

        // ----------- Destructor --------- //
        ~DynamicLibrary() noexcept;
};

} // namespace end
#endif /* DYNAMICLIBRARY_H */
