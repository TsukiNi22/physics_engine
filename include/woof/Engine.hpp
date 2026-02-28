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
    #define _Attribute
    #include "utils/utils.hpp"      // nodiscard
    #include "graphic/IGraphic.hpp" // woof::IGraphic
    #include "render/IRender.hpp"   // woof::IRender
    #include "object/IObject.hpp"   // woof::IObject
    #include <cstddef>              // std::size_t
    #include <chrono>               // std::chrono::milliseconds
    #include <atomic>               // std::atomic
    #include <memory>               // std::shared_ptr
    #include <vector>               // std::vector
    #include <string>               // std::string

    //----------------------------------------------------------------//
    /* DEFINE */

    #define TARGET_FPS 30

namespace woof { // namespace start
//----------------------------------------------------------------//
/* TYPDEF */

/* engine status */
enum Status {
    Running,
    Paused,
    Interrupted,
    Stopped,
};

/* frame duration */
constexpr auto frame_duration = std::chrono::milliseconds(1000 / TARGET_FPS);

//----------------------------------------------------------------//
/* CLASS */

class Engine {
    private:
        // ---------- Verbose -------- //
        std::atomic<std::size_t> _verbose{0};
        // Each new level take the property of the lower ones (except 0)
        // 0 -> Nothing is displayed
        // 1 -> Only basic loading such as the graphic selected
        // 2 -> Initialisation information (new object linked, status, ...)
        // 3 -> Running information (fps, loop time, ...)
        // 4 -> Sub running information (object drawing, ...)
        // ---------- Verbose -------- //

        /* global */
        std::atomic<woof::Status> _status{woof::Status::Paused};
        std::shared_ptr<woof::IGraphic> _graphic = nullptr;
        std::shared_ptr<woof::IRender> _render = nullptr;

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
        void start(); // Start the engine (open the display)
        void pause(std::size_t ms = 0); // Pause the engine with or without a timer before restarting (let the display open)
        void interrupt() noexcept; // Interrupt the engine (close the display)
        void stop() noexcept; // Stop the engine (can't be restarted)

        /* in the same process */
        void tick(); // Simulate one tick

        // ------------ Function ---------- //
        nodiscard bool isRunning() const noexcept {return (this->_status.load() == woof::Status::Running);};
        void setVerbose(std::size_t verbose = 0) {this->_verbose = verbose;};

        // ------------ Operator ---------- //
        Engine& operator=(const Engine& object) = delete;
        Engine& operator=(Engine&& object) = delete;

        // ---------- Constructor --------- //
        Engine(std::size_t verbose = 0); // Automatic selection of the graphic lib
        Engine(std::string render_lib, std::size_t verbose = 0); // Manual selection for the render lib 
        Engine(const Engine& object) = delete;
        Engine(Engine&& object) = delete;

        // ----------- Destructor --------- //
        ~Engine() = default;
};

} // namespace end
#endif /* ENGINE_H */
