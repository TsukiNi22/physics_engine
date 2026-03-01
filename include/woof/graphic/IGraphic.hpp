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
##  @file IGraphic.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef IGRAPHIC_H
    #define IGRAPHIC_H
    
    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "../DynamicLibrary.hpp"    // woof::DynamicLibrary
    #include <string>                   // std::string

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class IGraphic: public woof::DynamicLibrary {
    public:
        // ---------- Pre-Function -------- //

        // ------------ Operator ---------- //
        IGraphic& operator=(const IGraphic& object) = delete;
        IGraphic& operator=(IGraphic&& object) = delete;

        // ---------- Constructor --------- //
        IGraphic(const std::string& lib) noexcept: DynamicLibrary(lib) {};
        IGraphic(const IGraphic& object) = delete;
        IGraphic(IGraphic&& object) = delete;

        // ----------- Destructor --------- //
        virtual ~IGraphic() = default;
};

} // namespace end
#endif /* IGRAPHIC_H */
