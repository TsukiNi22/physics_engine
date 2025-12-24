/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 24/12/2025 by @authorTsukini

File Name:
##  @file thread.cpp

File Description:
##  Handle the thread of the engine
\**************************************************************/

#include "woof.hpp"
#include "error.hpp"
#include <thread>
#include <chrono>

void Engine::loop() {
    using namespace std::chrono;
    
    // Setup the context for the window
    if (setup_window_context() != OK) {
        err_custom_v("Error during the loop initialisation", ERR_INFO);
        return;
    }

    // Update the thread status
    paused = false;
    running = true;
    interrupted = false;
    
    // Used to calcul the real fps
    auto real_fps_timer = steady_clock::now();
    size_t real_frame = 0;
    
    // Loop
    while (!interrupted) {
        auto frame_duration = milliseconds(1000 / fps);
        if (paused) {
            running = false;
            std::this_thread::sleep_for(frame_duration);
            continue;
        }
        running = true;
        auto start = steady_clock::now();

        // Update engine
        stack->resolve();
        update();

        auto end = steady_clock::now();
        auto elapsed = duration_cast<milliseconds>(end - start);

        // Update the frame or wait the remaining time
        if (elapsed < frame_duration) {
            std::this_thread::sleep_for(frame_duration - elapsed);
            frame++;
        } else {
            frame += elapsed.count() / frame_duration.count();
        }
        frame %= fps; // Limitation of the frame
        real_frame++;

        // Update of the real fps every FPS_UPDATE_MILLISECONDS
        auto now = steady_clock::now();
        auto duration = now - real_fps_timer;
        auto duration_milliseconds = duration_cast<milliseconds>(duration).count();
        auto duration_seconds = duration_cast<std::chrono::duration<float>>(duration).count();
        if (duration_milliseconds >= FPS_UPDATE_MILLISECONDS) {
            real_fps = real_frame / duration_seconds;
            real_frame = 0;
            real_fps_timer = now;
        }
    }

    // Update the thread status
    destroy_window_context();
    paused = true;
    running = false;

    // Closing status
    if (closing) destroy(true);
}

int Engine::start() {
    if (!window) return err_custom("Can't start without a valid window", KO, ERR_INFO);
    std::thread([this]() {loop();}).detach();
    return OK;
}

void Engine::interrupt() {
    interrupted = true;
    while (running)
        std::this_thread::sleep_for(std::chrono::milliseconds(INTERRUPT_WAITING_MILLISECONDS));
}

void Engine::pause() {
    if (!(running && !interrupted && !paused)) return;
    paused = true;
    while (running)
        std::this_thread::sleep_for(std::chrono::milliseconds(INTERRUPT_WAITING_MILLISECONDS));
}

void Engine::play() {
    if (!(!running && !interrupted && paused)) return;
    paused = false;
    while (!running)
        std::this_thread::sleep_for(std::chrono::milliseconds(INTERRUPT_WAITING_MILLISECONDS));
}
