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
    #include <memory>               // std::shared_ptr
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
        /* global */
        woof::Status _status = woof::Status::Paused;
        std::shared_ptr<woof::IGraphic> _graphic = nullptr;

        // ---------- Pre-Function -------- //
        //void draw(const std::shared_ptr<woof::IObject>& object); // draw a given object

    public:
        // ---------- Pre-Function -------- //
        /* in a separated thread */
        void start(); // Start the engine
        void interrupt(); // Interrupt the engine (let the display open)
        void stop(); // Stop the engine (close the display)

        /* in the same process */
        void tick(); // Simulate one tick

        // ------------ Function ---------- //

        // ------------ Operator ---------- //
        Engine& operator=(const Engine& object) = delete;
        Engine& operator=(Engine&& object) = delete;

        // ---------- Constructor --------- //
        Engine(); // Automatic selection of the graphic lib
        Engine(std::string graphic_lib); // Manual selection for the graphic lib 
        Engine(const Engine& object) = delete;
        Engine(Engine&& object) = delete;

        // ----------- Destructor --------- //
        ~Engine() = default;
};

} // namespace end
#endif /* ENGINE_H */
