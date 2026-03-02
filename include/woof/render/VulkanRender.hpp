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
    #include "IRender.hpp"              // woof::IRender
    #include "../object/IObject.hpp"    // woof::IObject
    #include <memory>                   // std::shared_ptr
    #include <string>                   // std::string

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class VulkanRender: public woof::IRender {
    private:
        /* Vulkan function pointers */

    public:
        // ---------- Pre-Function -------- //
        void draw(const std::shared_ptr<woof::IObject>& object) final;

        // ------------ Operator ---------- //
        VulkanRender& operator=(const VulkanRender& object) = delete;
        VulkanRender& operator=(VulkanRender&& object) = delete;

        // ---------- Constructor --------- //
        VulkanRender();
        VulkanRender(const VulkanRender& object) = delete;
        VulkanRender(VulkanRender&& object) = delete;

        // ----------- Destructor --------- //
        ~VulkanRender() = default;
};

} // namespace end
#endif /* VULKANRENDER_H */
