/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 25/12/2025 by @authorTsukini

File Name:
##  @file main.cpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#include "object.hpp"
#include "woof.hpp"
#include <thread>
#include <vector>
#include <iostream>

int main() {
    Engine engine;
    
    // setup
    std::vector<vector2> floor_vectors = {
        {engine.area_width / -2.f, engine.area_height / -2.f + 25},
        {engine.area_width / 2.f, engine.area_height / -2.f + 25},
        {engine.area_width / 2.f, engine.area_height / -2.f},
        {engine.area_width / -2.f, engine.area_height / -2.f}
    };
    vector2 floor_pivot = {0.f, 0.f};
    Prop *floor = new Prop(RECTANGLE, floor_vectors, floor_pivot, 0.f);
    engine.add_prop(floor);

    std::vector<vector2> circle_vectors = {
        {0.f, 0.f},
        {25, 0},
    };
    Object *circle = new Object(CIRCLE, circle_vectors);
    engine.add_object(circle);

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
