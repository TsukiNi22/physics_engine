/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 28/02/2026 by @author Tsukini

File Name:
##  @file AGraphic.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef AGRAPHIC_H
    #define AGRAPHIC_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #define _Attribute
    #include "utils/Utils.hpp" // nodiscard
    #include "IGraphic.hpp" // woof::IGraphic

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class AGraphic: public woof::IGraphic {
    protected:
        void* _lib = nullptr;

    public:
        // ------------ Function ---------- //
        nodiscard bool isloaded() const noexcept final {return this->_lib;};

        // ------------ Operator ---------- //
        AGraphic& operator=(const AGraphic& object) = delete;
        AGraphic& operator=(AGraphic&& object) = delete;

        // ---------- Constructor --------- //
        AGraphic() = default;
        AGraphic(const AGraphic& object) = delete;
        AGraphic(AGraphic&& object) = delete;

        // ----------- Destructor --------- //
        ~AGraphic() noexcept;
};

} // namespace end
#endif /* AGRAPHIC_H */
