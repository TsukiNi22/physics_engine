/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 26/02/2026 by @author Tsukini

File Name:
##  @file Engine.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef ENGINE_H
    #define ENGINE_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "graphic/IGraphic.hpp" // woof::IGraphic
    #include <memory>               // std::unique_ptr
    #include <string>               // std::string

    //----------------------------------------------------------------//
    /* DEFINE */

    /* default values */
    #define DEFAULT_GRAPHIC_LIB "opengl"

namespace woof { // namespace start
//----------------------------------------------------------------//
/* TYPDEF */
enum Status {
    Running,
    Paused,
    Stopped,
};

//----------------------------------------------------------------//
/* CLASS */

class Engine {
    private:
        /* global */
        woof::Status _status = woof::Status::Paused;
        std::unique_ptr<woof::IGraphic> _graphic = nullptr;

    public:
        // ---------- Pre-Function -------- //
        /* status edition */
        void start(); // Start the engine
        void interrupt(); // Interrupt the engine (can be restarted with start)
        void stop(); // Stop the engine

        // ------------ Function ---------- //

        // ------------ Operator ---------- //
        Engine& operator=(const Engine& object) = delete;
        Engine& operator=(Engine&& object) = delete;

        // ---------- Constructor --------- //
        Engine() noexcept;
        Engine(std::string graphic_lib) noexcept;
        Engine(const Engine& object) = delete;
        Engine(Engine&& object) = delete;

        // ----------- Destructor --------- //
        ~Engine() = default;
};

} // namespace end
#endif /* ENGINE_H */
