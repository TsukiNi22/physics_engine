/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 19/01/2026 by @authorTsukini

File Name:
##  @file constructor.cpp

File Description:
##  Constructor of the engine
\**************************************************************/

#include "stack.hpp"
#include "object.hpp"
#include "woof.hpp"
#include <vector>

/* engine */
Engine::Engine() {stack = new Stack(this); init();}
Engine::Engine(bool is_resizable) : resizable(is_resizable) {stack = new Stack(this); init();}
Engine::Engine(size_t default_width, size_t default_height) : width(default_width), height(default_height) {stack = new Stack(this); init();}
Engine::Engine(size_t default_width, size_t default_height, bool is_resizable) : width(default_width), height(default_height), resizable(is_resizable) {stack = new Stack(this); init();}

/* actors */
Actor *create_actor_shape(std::vector<vector2_s> vectors, vector2_s pivot, float angle)
{
    return new Actor(SHAPE, vectors, pivot, angle);
}
Actor *create_actor_shape(std::vector<vector2_s> vectors, float angle)
{
    vector2_s pivot = {0.f, 0.f};
    return new Actor(SHAPE, vectors, pivot, angle);
}
Actor *create_actor_shape(std::vector<vector2_s> vectors)
{
    vector2_s pivot = {0.f, 0.f};
    float angle = 0.f;
    return new Actor(SHAPE, vectors, pivot, angle);
}

Actor *create_actor_circle(float x, float y, float radius)
{
    std::vector<vector2_s> vectors = {
        {x, y},
        {radius, 0},
    };
    return new Actor(CIRCLE, vectors);
}
Actor *create_actor_circle(vector2_s origin, float radius)
{
    std::vector<vector2_s> vectors = {
        origin,
        {radius, 0},
    };
    return new Actor(CIRCLE, vectors);
}
Actor *create_actor_circle(std::vector<vector2_s> vectors)
{
    return new Actor(CIRCLE, vectors);
}

/* objects */
Object *create_object_shape(std::vector<vector2_s> vectors, vector2_s pivot, float angle)
{
    return new Object(SHAPE, vectors, pivot, angle);
}
Object *create_object_shape(std::vector<vector2_s> vectors, float angle)
{
    vector2_s pivot = {0.f, 0.f};
    return new Object(SHAPE, vectors, pivot, angle);
}
Object *create_object_shape(std::vector<vector2_s> vectors)
{
    vector2_s pivot = {0.f, 0.f};
    float angle = 0.f;
    return new Object(SHAPE, vectors, pivot, angle);
}

Object *create_object_circle(float x, float y, float radius)
{
    std::vector<vector2_s> vectors = {
        {x, y},
        {radius, 0},
    };
    return new Object(CIRCLE, vectors);
}
Object *create_object_circle(vector2_s origin, float radius)
{
    std::vector<vector2_s> vectors = {
        origin,
        {radius, 0},
    };
    return new Object(CIRCLE, vectors);
}
Object *create_object_circle(std::vector<vector2_s> vectors)
{
    return new Object(CIRCLE, vectors);
}

/* props */
Prop *create_prop_shape(std::vector<vector2_s> vectors, vector2_s pivot, float angle)
{
    return new Prop(SHAPE, vectors, pivot, angle);
}
Prop *create_prop_shape(std::vector<vector2_s> vectors, float angle)
{
    vector2_s pivot = {0.f, 0.f};
    return new Prop(SHAPE, vectors, pivot, angle);
}
Prop *create_prop_shape(std::vector<vector2_s> vectors)
{
    vector2_s pivot = {0.f, 0.f};
    float angle = 0.f;
    return new Prop(SHAPE, vectors, pivot, angle);
}

Prop *create_prop_circle(float x, float y, float radius)
{
    std::vector<vector2_s> vectors = {
        {x, y},
        {radius, 0},
    };
    return new Prop(CIRCLE, vectors);
}
Prop *create_prop_circle(vector2_s origin, float radius)
{
    std::vector<vector2_s> vectors = {
        origin,
        {radius, 0},
    };
    return new Prop(CIRCLE, vectors);
}
Prop *create_prop_circle(std::vector<vector2_s> vectors)
{
    return new Prop(CIRCLE, vectors);
}
