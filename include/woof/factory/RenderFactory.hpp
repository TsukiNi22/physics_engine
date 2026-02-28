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
##  @file RenderFactory.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef RENDERFACTORY_H
    #define RENDERFACTORY_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "../render/IRender.hpp"  // woof::IRender
    #include "AFactory.hpp"             // woof::AFactory

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class RenderFactory: public woof::AFactory<woof::IRender> {
    public:
        // ------------ Operator ---------- //
        RenderFactory& operator=(const RenderFactory& object) = delete;
        RenderFactory& operator=(RenderFactory&& object) = delete;

        // ---------- Constructor --------- //
        RenderFactory() noexcept;
        RenderFactory(const RenderFactory& object) = delete;
        RenderFactory(RenderFactory&& object) = delete;

        // ----------- Destructor --------- //
        ~RenderFactory() = default;
};

} // namespace end
#endif /* RENDERFACTORY_H */
