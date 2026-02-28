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
##  @file VulkanRender.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef VULKANRENDER_H
    #define VULKANRENDER_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "ARender.hpp" // woof::ARender

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class VulkanRender: public woof::ARender {
    private:
        /* Nothing */

    public:
        // ---------- Pre-Function -------- //

        // ------------ Function ---------- //

        // ------------ Operator ---------- //
        VulkanRender& operator=(const VulkanRender& object) = delete;
        VulkanRender& operator=(VulkanRender&& object) = delete;

        // ---------- Constructor --------- //
        VulkanRender() noexcept;
        VulkanRender(const VulkanRender& object) = delete;
        VulkanRender(VulkanRender&& object) = delete;

        // ----------- Destructor --------- //
        ~VulkanRender() = default;
};

} // namespace end
#endif /* VULKANRENDER_H */
