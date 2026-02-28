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
##  @file IRender.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef IRENDER_H
    #define IRENDER_H

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class IRender {
    public:
        // ---------- Pre-Function -------- //
        virtual bool isloaded() const noexcept = 0;

        // ------------ Operator ---------- //
        IRender& operator=(const IRender& object) = delete;
        IRender& operator=(IRender&& object) = delete;

        // ---------- Constructor --------- //
        IRender() = default;
        IRender(const IRender& object) = delete;
        IRender(IRender&& object) = delete;

        // ----------- Destructor --------- //
        virtual ~IRender() = default;
};

} // namespace end
#endif /* IRENDER_H */
