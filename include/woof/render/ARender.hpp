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
##  @file ARender.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef ARENDER_H
    #define ARENDER_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #define _Attribute
    #include "utils/utils.hpp" // nodiscard
    #include "IRender.hpp" // woof::IRender

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class ARender: public woof::IRender {
    protected:
        void* _lib = nullptr;

    public:
        // ------------ Function ---------- //
        nodiscard bool isloaded() const noexcept final {return this->_lib;};

        // ------------ Operator ---------- //
        ARender& operator=(const ARender& object) = delete;
        ARender& operator=(ARender&& object) = delete;

        // ---------- Constructor --------- //
        ARender() = default;
        ARender(const ARender& object) = delete;
        ARender(ARender&& object) = delete;

        // ----------- Destructor --------- //
        ~ARender() noexcept;
};

} // namespace end
#endif /* ARENDER_H */
