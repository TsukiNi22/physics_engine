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
#define _Attribute
#include "utils/utils.hpp"
#include "woof/Engine.hpp"
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
}

void woof::Engine::pause(std::size_t ms)
{
    // Check the status before changing it
    if (this->_status.load() != woof::Status::Running)
        return; // Ignore the call is the engine is not running

    // Update the status
    this->_status.store(woof::Status::Paused);

    // If the timer is greater than 0, then launch it in a different thread
    if (ms == 0) return;
    std::thread([this, ms]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms)); // Timer

        // Restart after the timer is the status is still paused
        if (this->_status.load() != woof::Status::Paused)
            this->start();
    }).detach();
}

void woof::Engine::interrupt()
{
    // Check the status before changing it
    if (this->_status.load() != woof::Status::Running)
        return; // Ignore the call is the engine is not running

    // Update the status
    this->_status.store(woof::Status::Interrupted);
}

void woof::Engine::stop()
{
    // Check the status before changing it
    if (this->_status.load() != woof::Status::Running)
        return; // Ignore the call is the engine is not running

    // Update the status
    this->_status.store(woof::Status::Stopped);
}

void woof::Engine::tick()
{
}
