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
##  @file run.cpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#define _Exception
#define _Write
#define _Attribute
#include "utils/utils.hpp"
#include "woof/Engine.hpp"
#include <iostream>
#include <cstddef>
#include <thread>
#include <chrono>

void woof::Engine::start()
{
    // Check the status before changing it
    if (this->_status.load() == woof::Status::Stopped)
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::InvalidAction, "Can't be restarted when 'Stopped'");
    else if (this->_status.load() == woof::Status::Running)
        return; // Ignore the call is the engine is already running

    // Update the status
    this->_status.store(woof::Status::Running);
    if (this->_verbose.load() >= 2) std::cout << "engine: " << utils::write::strong() << "Running" << utils::write::reset() << std::endl;

    // Launch the engine loop
    std::thread([this]() {
        // Init
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end, fps_start, now;
        std::chrono::milliseconds elapsed;
        std::size_t frame_count = 0;
        double fps =0.f;

        // Loop
        fps_start = std::chrono::high_resolution_clock::now();
        while (this->_status.load() == woof::Status::Running) {
            // Update of the engine
            start = std::chrono::high_resolution_clock::now();
            this->tick();
            ++frame_count;
            end = std::chrono::high_resolution_clock::now();

            // Compute the time of the frame
            elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            if (this->_verbose.load() >= 3) std::cout << "tick duration: " << utils::write::strong() << elapsed << utils::write::reset() << std::endl;
            if (elapsed < woof::frame_duration)
                std::this_thread::sleep_for(woof::frame_duration - elapsed);

            // Compute the fps each .1 second
            now = std::chrono::high_resolution_clock::now();
            if (std::chrono::duration_cast<std::chrono::seconds>(now - fps_start).count() >= 1) {
                fps = static_cast<double>(frame_count) / std::chrono::duration_cast<std::chrono::duration<double>>(now - fps_start).count();
                if (this->_verbose.load() >= 3) std::cout << "fps: " << utils::write::strong() << fps << utils::write::reset() << std::endl;

                // Reset
                frame_count = 0;
                fps_start = now;
            }
        }
    }).detach();
}

void woof::Engine::pause(std::size_t ms)
{
    // Check the status before changing it
    if (this->_status.load() != woof::Status::Running)
        return; // Ignore the call is the engine is not running

    // Update the status
    this->_status.store(woof::Status::Paused);
    if (this->_verbose.load() >= 2) {
        if (ms == 0) std::cout << "engine: " << utils::write::strong() << "Paused" << utils::write::reset() << std::endl;
        else std::cout << "engine: " << utils::write::strong() << "Paused" << utils::write::reset() << " for (" << utils::write::strong() << ms << "ms" << utils::write::reset() << ")" << std::endl;
    }

    // If the timer is greater than 0, then launch it in a different thread
    if (ms == 0) return;
    std::thread([this, ms]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms)); // Timer

        // Restart after the timer is the status is still paused
        if (this->_verbose.load() >= 2) std::cout << "engine: restart auto (try)" << std::endl;
        if (this->_status.load() == woof::Status::Paused)
            this->start();
    }).detach();
}

void woof::Engine::interrupt() noexcept
{
    // Check the status before changing it
    if (this->_status.load() != woof::Status::Running)
        return; // Ignore the call is the engine is not running

    // Update the status
    this->_status.store(woof::Status::Interrupted);
    if (this->_verbose.load() >= 2) std::cout << "engine: " << utils::write::strong() << "Interrupted" << utils::write::reset() << std::endl;
}

void woof::Engine::stop() noexcept
{
    // Check the status before changing it
    if (this->_status.load() != woof::Status::Running)
        return; // Ignore the call is the engine is not running

    // Update the status
    this->_status.store(woof::Status::Stopped);
    if (this->_verbose.load() >= 2) std::cout << "engine: " << utils::write::strong() << "Stopped" << utils::write::reset() << std::endl;
}

hot void woof::Engine::tick()
{
    // 1 - object physic computing
    // 2 - handling input from actor
    // 3 - updating object
    // 4 - rendering object
}
