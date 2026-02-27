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
##  @file AFactory.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef AFACTORY_H
    #define AFACTORY_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #define _Exception
    #define _Attribute
    #include "utils/Utils.hpp"  // utils::exception::CustomException, utils::exception::Type, utils::exception::Code, nodiscard
    #include "IFactory.hpp"     // woof::IFactory
    #include <unordered_map>    // std::unordered_map
    #include <functional>       // std::functional
    #include <memory>           // std::shared_ptr
    #include <string>           // std::string

namespace woof { // namespace start
//----------------------------------------------------------------//
/* CLASS */

template<typename T>
class AFactory: public woof::IFactory<T> {
    protected:
        std::unordered_map<std::string, std::function<std::shared_ptr<T>()>> _registry;

    public:
        // ------------ Function ---------- //
        nodiscard std::shared_ptr<T> create(const std::string& type) final
        {
            // Try to find a valid creation function for the type
            auto it = this->_registry.find(type);
            if (it != this->_registry.end())
                return it->second();

            // Unknow type, not in the map
            throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::UnknowClassFactory, type);
        }

        // ------------ Operator ---------- //
        AFactory& operator=(const AFactory& object) = delete;
        AFactory& operator=(AFactory&& object) = delete;

        // ---------- Constructor --------- //
        AFactory() = default;
        AFactory(const AFactory& object) = delete;
        AFactory(AFactory&& object) = delete;

        // ----------- Destructor --------- //
        ~AFactory() = default;
};

} // namespace end
#endif /* AFACTORY_H */
