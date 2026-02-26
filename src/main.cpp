/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 31/01/2026 by @author Tsukini

File Name:
##  @file main.cpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#include "object.hpp"
#include "woof.hpp"
#include <thread>
#include <chrono>
#include <vector>
#include <iostream>

int main() {
    Engine engine;

    // setup
    std::vector<vector2> floor_vectors = {
        {engine.area_width / -2.f + 1, engine.area_height / -2.f + 25},
        {engine.area_width / 2.f, engine.area_height / -2.f + 25},
        {engine.area_width / 2.f, engine.area_height / -2.f},
        {engine.area_width / -2.f + 1, engine.area_height / -2.f}
    };
    Prop *floor = create_prop_shape(floor_vectors);
    engine.add_prop(floor);

    Object *circle = create_object_circle(0.f, engine.area_height / 2.f - 25, 25.f);
    engine.add_object(circle);

    if (COMPARE_OBJECT_PTR(circle, floor))
        std::cout << "Yes1" << std::endl;

    // run
    engine.start();
    while (engine.alive)
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    /*
    engine.start();
    std::this_thread::sleep_for(std::chrono::seconds(3)); // Keep the engine alive for x time
    engine.pause();
    std::cout << "Pause" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Wainting
    engine.play();
    std::cout << "Play" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3)); // Keep the engine alive for x time
    */

    // clear
    delete floor;
    delete circle;
    
    return 0;
}
