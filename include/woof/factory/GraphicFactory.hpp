/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 27/02/2026 by @author Tsukini

File Name:
##  @file GraphicFactory.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef GRAPHICFACTORY_H
    #define GRAPHICFACTORY_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "../graphic/IGraphic.hpp"  // woof::IGraphic
    #include "AFactory.hpp"             // woof::AFactory

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class GraphicFactory: public woof::AFactory<woof::IGraphic> {
    public:
        // ------------ Operator ---------- //
        GraphicFactory& operator=(const GraphicFactory& object) = delete;
        GraphicFactory& operator=(GraphicFactory&& object) = delete;

        // ---------- Constructor --------- //
        GraphicFactory() noexcept;
        GraphicFactory(const GraphicFactory& object) = delete;
        GraphicFactory(GraphicFactory&& object) = delete;

        // ----------- Destructor --------- //
        ~GraphicFactory() = default;
};

} // namespace end
#endif /* GRAPHICFACTORY_H */
