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
##  @file IGraphic.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef IGRAPHIC_H
    #define IGRAPHIC_H

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class IGraphic {
    public:
        // ---------- Pre-Function -------- //
        virtual bool isloaded() const noexcept = 0;

        // ------------ Operator ---------- //
        IGraphic& operator=(const IGraphic& object) = delete;
        IGraphic& operator=(IGraphic&& object) = delete;

        // ---------- Constructor --------- //
        IGraphic() = default;
        IGraphic(const IGraphic& object) = delete;
        IGraphic(IGraphic&& object) = delete;

        // ----------- Destructor --------- //
        virtual ~IGraphic() = 0;
};

} // namespace end
#endif /* IGRAPHIC_H */
