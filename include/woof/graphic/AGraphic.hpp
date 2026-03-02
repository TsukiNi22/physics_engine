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
    #include "utils/utils.hpp"  // nodiscard
    #include "IGraphic.hpp"     // woof::IGraphic
    #include <string>           // std::string

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class AGraphic: public woof::IGraphic {
    protected:
        bool _isopen = false;

    public:
        // ---------- Pre-Function -------- //

        // ------------ Function ---------- //
        nodiscard bool isOpen() const noexcept final {return this->_isopen;};

        // ------------ Operator ---------- //
        AGraphic& operator=(const AGraphic& object) = delete;
        AGraphic& operator=(AGraphic&& object) = delete;

        // ---------- Constructor --------- //
        AGraphic(const std::string& lib) noexcept: IGraphic(lib) {};
        AGraphic(const AGraphic& object) = delete;
        AGraphic(AGraphic&& object) = delete;

        // ----------- Destructor --------- //
        ~AGraphic() = default;
};

} // namespace end
#endif /* AGRAPHIC_H */
