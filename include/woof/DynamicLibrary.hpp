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

#ifndef DYNAMICLIBRARY_H
    #define DYNAMICLIBRARY_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #define _Attribute
    #include "utils/utils.hpp"  // nodiscard
    #include <string>           // std::string

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class DynamicLibrary {
    protected:
        void* _lib = nullptr;

    public:
        // ------------ Function ---------- //
        bool isloaded() const noexcept {return this->_lib;};

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
