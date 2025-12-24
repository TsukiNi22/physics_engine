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
##  @file physics.cpp

File Description:
##  Simulate the movement/physics
\**************************************************************/

#include "object.hpp"

// Default gravity vector
static vector2 gravity{0.f, -GRAVITY};

static void compute_movement(std::vector<vector2>& vectors, const vector2 movement)
{
    for (vector2& p : vectors) p += movement;
}

static void compute_movement_circle(std::vector<vector2>& vectors, const vector2 movement)
{
    vector2& p = vectors[0];
    p += movement;
}

static void compute_movement_dispatch(type_t id, std::vector<vector2>& vectors, const vector2 movement)
{
    switch (id) {
        case POINT:     
        case LINE:      
        case TRIANGLE:  
        case RECTANGLE: 
        case SHAPE:     compute_movement(vectors, movement);        break;
        case CIRCLE:    compute_movement_circle(vectors, movement); break;
        default: break; // Ignore SPRITE for now
    }
}

void Actor::physics(float coef)
{
    if (!simulated) return;
    movement_vector += gravity * coef;
    compute_movement_dispatch(id, vectors, movement_vector);
}

void Object::physics(float coef)
{
    if (!simulated) return;
    movement_vector += gravity * coef;
    compute_movement_dispatch(id, vectors, movement_vector);
}
