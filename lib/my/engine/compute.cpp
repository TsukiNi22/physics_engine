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
##  @file compute.cpp

File Description:
##  Do the computing for the physics and other
\**************************************************************/

#include "object.hpp"

// Defnition of the gravity
vector2 gravity{0.f, -GRAVITY};

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

static void compute_acceleration_shape(std::vector<vector2>& vectors, const vector2 movement)
{
    for (vector2& p : vectors) p += movement;
}

static void compute_acceleration_circle(std::vector<vector2>& vectors, const vector2 movement)
{
    vector2& p = vectors[0];
    p += movement;
}

void compute_acceleration(type_t id, std::vector<vector2>& vectors, const vector2 movement)
{
    switch (id) {
        case SPRITE: break; // Ignore SPRITE for now
        case SHAPE:     compute_acceleration_shape(vectors, movement); break;
        case CIRCLE:    compute_acceleration_circle(vectors, movement); break;
        default: break;
    }
}

float compute_drag_coef(type_t id, std::vector<vector2>& vectors)
{
    switch (id) {
        case SPRITE: break; // Ignore SPRITE for now
        case SHAPE:     return 0.f;
        case CIRCLE:    return 0.f;
        default: break;
    }
    return 0.f;
}

void Actor::compute_velocity(const float delta_time, const float drag_coef)
{
    vector2 drag_force = velocity * drag_coef * -1;
    acceleration = (gravity * mass + drag_force) / mass;
    velocity += acceleration * delta_time;
}

void Object::compute_velocity(const float delta_time, const float drag_coef)
{
    vector2 drag_force = velocity * drag_coef * -1;
    acceleration = (gravity * mass + drag_force) / mass;
    velocity += acceleration * delta_time;
}
