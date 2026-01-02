/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 02/01/2026 by @authorTsukini

File Name:
##  @file physics.cpp

File Description:
##  Simulate the movement/physics
\**************************************************************/

#include "object.hpp"

// Default gravity vector
static vector2 gravity{0.f, -GRAVITY};

vector2 rotate_point(const vector2& point, const vector2& pivot, const float deg)
{
    vector2 p = point;

    float rad = deg * (M_PI / 180.0f);
    float s = sin(rad);
    float c = cos(rad);

    // Translate to pivot
    p.x -= pivot.x;
    p.y -= pivot.y;

    // Rotate
    float xnew = p.x * c - p.y * s;
    float ynew = p.x * s + p.y * c;

    // Translate back
    p.x = xnew + pivot.x;
    p.y = ynew + pivot.y;

    return p;
}

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

static float compute_drag_coef()
{
    return 0.f;
}

void Actor::compute_velocity(const float delta_time, const float drag_coef)
{
    vector2 drag_force = velocity * drag_coef * -1;
    acceleration = (gravity * mass + drag_force) / mass;
    velocity += acceleration * delta_time;
}

void Actor::physics(const float delta_time)
{
    if (!simulated) return;
    compute_velocity(delta_time, compute_drag_coef());
    compute_movement_dispatch(id, vectors, velocity);
}

void Object::compute_velocity(const float delta_time, const float drag_coef)
{
    vector2 drag_force = velocity * drag_coef * -1;
    acceleration = (gravity * mass + drag_force) / mass;
    velocity += acceleration * delta_time;
}

void Object::physics(const float delta_time)
{
    if (!simulated) return;
    compute_velocity(delta_time, compute_drag_coef());
    compute_movement_dispatch(id, vectors, velocity);
}
