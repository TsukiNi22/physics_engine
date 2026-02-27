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
##  @file IFactory.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef IFACTORY_H
    #define IFACTORY_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include <memory>           // std::shared_ptr
    #include <string>           // std::string

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

template<typename T>
class IFactory {
    public:
        // ---------- Pre-Function -------- //
        virtual std::shared_ptr<T> create(const std::string& type) = 0;

        // ------------ Operator ---------- //
        IFactory& operator=(const IFactory& object) = delete;
        IFactory& operator=(IFactory&& object) = delete;

        // ---------- Constructor --------- //
        IFactory() = default;
        IFactory(const IFactory& object) = delete;
        IFactory(IFactory&& object) = delete;

        // ----------- Destructor --------- //
        ~IFactory() = default;
};

} // namespace end
#endif /* IFACTORY_H */
