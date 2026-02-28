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
##  @file VulkanGraphic.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef VULKANGRAPHIC_H
    #define VULKANGRAPHIC_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "AGraphic.hpp" // woof::AGraphic

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class VulkanGraphic: public woof::AGraphic {
    private:
        /* Nothing */

    public:
        // ---------- Pre-Function -------- //

        // ------------ Function ---------- //

        // ------------ Operator ---------- //
        VulkanGraphic& operator=(const VulkanGraphic& object) = delete;
        VulkanGraphic& operator=(VulkanGraphic&& object) = delete;

        // ---------- Constructor --------- //
        VulkanGraphic() noexcept;
        VulkanGraphic(const VulkanGraphic& object) = delete;
        VulkanGraphic(VulkanGraphic&& object) = delete;

        // ----------- Destructor --------- //
        ~VulkanGraphic() = default;
};

} // namespace end
#endif /* VULKANGRAPHIC_H */
