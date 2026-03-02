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
    #include <cstddef>                  // std::size_t
    #include <string>                   // std::string

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class IGraphic: public woof::DynamicLibrary {
    public:
        // ---------- Pre-Function -------- //
        virtual void openWindow(std::string renderLib, std::size_t width = 800, std::size_t height = 600) = 0;
        virtual void closeWindow() = 0;
        virtual void update() const = 0;
        virtual bool isOpen() const noexcept = 0;
        virtual void *getWindow() const noexcept = 0;

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
