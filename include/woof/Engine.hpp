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
    #include "object/IObject.hpp"   // woof::IObject
    #include <cstddef>              // std::size_t
    #include <memory>               // std::shared_ptr
    #include <vector>               // std::vector
    #include <string>               // std::string

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
        // ---------- Verbose -------- //
        std::size_t _verbose = 0;
        // Each new level take the property of the lower ones (except 0)
        // 0 -> Nothing is displayed
        // 1 -> Only basic loading such as the graphic selected
        // 2 -> Initialisation information (new object linked, status, ...)
        // 3 -> Running information (fps, loop time, ...)
        // 4 -> Sub running information (object drawing, ...)
        // ---------- Verbose -------- //

        /* global */
        woof::Status _status = woof::Status::Paused;
        std::shared_ptr<woof::IGraphic> _graphic = nullptr;

        /* objects */
        std::vector<std::shared_ptr<woof::IObject>> _global; // Store a copy of all object of any type accepted
        std::vector<std::shared_ptr<woof::IObject>> _actors;
        std::vector<std::shared_ptr<woof::IObject>> _objects;
        std::vector<std::shared_ptr<woof::IObject>> _prop;

    public:
        // ---------- Pre-Function -------- //
        void link(const std::shared_ptr<woof::IObject>& object); // Link an object to the engine
        void unlink(const std::shared_ptr<woof::IObject>& object); // Remove the link of an object from the engine

        /* in a separated thread */
        void start(); // Start the engine
        void interrupt(); // Interrupt the engine (let the display open)
        void stop(); // Stop the engine (close the display)

        /* in the same process */
        void tick(); // Simulate one tick

        // ------------ Function ---------- //
        void setVerbose(std::size_t verbose = 0) {this->_verbose = verbose;};

        // ------------ Operator ---------- //
        Engine& operator=(const Engine& object) = delete;
        Engine& operator=(Engine&& object) = delete;

        // ---------- Constructor --------- //
        Engine(std::size_t verbose = 0); // Automatic selection of the graphic lib
        Engine(std::string graphic_lib, std::size_t verbose = 0); // Manual selection for the graphic lib 
        Engine(const Engine& object) = delete;
        Engine(Engine&& object) = delete;

        // ----------- Destructor --------- //
        ~Engine() = default;
};

} // namespace end
#endif /* ENGINE_H */
