/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 05/01/2026 by @authorTsukini

File Name:
##  @file physics.cpp

File Description:
##  Simulate the movement/physics
\**************************************************************/

#include "object.hpp"

void Actor::physics(const float delta_time)
{
    if (!simulated) return;
    compute_velocity(delta_time, compute_drag_coef(id, vectors));
    compute_acceleration(id, vectors, velocity);
}

void Object::physics(const float delta_time)
{
    if (!simulated) return;
    compute_velocity(delta_time, compute_drag_coef(id, vectors));
    compute_acceleration(id, vectors, velocity);
}
