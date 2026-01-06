/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 06/01/2026 by @authorTsukini

File Name:
##  @file collisions.cpp

File Description:
##  Check for any potential collisions between 2 objects
\**************************************************************/

#include "object.hpp"
#include <stdbool.h>
#include <vector>

static bool basic_check(
    // First
    type_t id1, const std::vector<vector2>& vectors1,
    const vector2& pivot1, float rotation1,
    const vector2& acceleration1,
    // Second
    type_t id2, const std::vector<vector2>& vectors2,
    const vector2& pivot2, float rotation2,
    const vector2& acceleration2
)
{
    float x_max1 = 0.f, x_min1 = 0.f, y_min1 = 0.f, y_max1 = 0.f;
    float x_max2 = 0.f, x_min2 = 0.f, y_min2 = 0.f, y_max2 = 0.f;
    bool first = true;

    // get the min and max for x and y of the first object
    first = true;
    if (id1 == SHAPE) {
        // Basic point
        for (const auto& orig : vectors1) {
            vector2 v = orig;
            v = rotate_point(v, pivot1, rotation1);
            if (v.x > x_max1 || first) x_max1 = v.x;
            if (v.x < x_min1 || first) x_max1 = v.x;
            if (v.y > y_max1 || first) y_max1 = v.y;
            if (v.y < y_min1 || first) y_min1 = v.y;
            first = false;
        }

        // Acceleration point
        for (const auto& orig : vectors1) {
            vector2 v = orig;
            v = rotate_point(v + acceleration1, pivot1, rotation1);
            if (v.x > x_max1 || first) x_max1 = v.x;
            if (v.x < x_min1 || first) x_max1 = v.x;
            if (v.y > y_max1 || first) y_max1 = v.y;
            if (v.y < y_min1 || first) y_min1 = v.y;
        }
    } else if (id1 == CIRCLE) {
        vector2 origin = vectors1[0];
        vector2 origin_acc = vectors1[0];
        float radius = vectors1[1].x;
        
        // Basic point
        origin = rotate_point(origin, pivot1, rotation1);
        x_max1 = origin.x + radius;
        x_min1 = origin.x - radius;
        y_max1 = origin.y + radius;
        y_min1 = origin.y - radius;

        // Acceleration point
        origin_acc = rotate_point(origin_acc + acceleration1, pivot1, rotation1);
        if (origin_acc.x + radius > x_max1) x_max1 = origin_acc.x + radius;
        if (origin_acc.x - radius < x_min1) x_max1 = origin_acc.x - radius;
        if (origin_acc.y + radius > y_max1) y_max1 = origin_acc.y + radius;
        if (origin_acc.y - radius < y_min1) y_min1 = origin_acc.y - radius;
    }

    // get the min and max for x and y of the second object
    first = true;
    if (id2 == SHAPE) {
        // Basic point
        for (const auto& orig : vectors2) {
            vector2 v = orig;
            v = rotate_point(v, pivot2, rotation2);
            if (v.x > x_max2 || first) x_max2 = v.x;
            if (v.x < x_min2 || first) x_max2 = v.x;
            if (v.y > y_max2 || first) y_max2 = v.y;
            if (v.y < y_min2 || first) y_min2 = v.y;
            first = false;
        }

        // Acceleration point
        for (const auto& orig : vectors2) {
            vector2 v = orig;
            v = rotate_point(v + acceleration2, pivot2, rotation2);
            if (v.x > x_max2 || first) x_max2 = v.x;
            if (v.x < x_min2 || first) x_max2 = v.x;
            if (v.y > y_max2 || first) y_max2 = v.y;
            if (v.y < y_min2 || first) y_min2 = v.y;
        }
    } else if (id2 == CIRCLE) {
        vector2 origin = vectors2[0];
        vector2 origin_acc = vectors2[0];
        float radius = vectors2[1].x;
        
        // Basic point
        origin = rotate_point(origin, pivot2, rotation2);
        x_max2 = origin.x + radius;
        x_min2 = origin.x - radius;
        y_max2 = origin.y + radius;
        y_min2 = origin.y - radius;

        // Acceleration point
        origin_acc = rotate_point(origin_acc + acceleration2, pivot2, rotation2);
        if (origin_acc.x + radius > x_max2) x_max2 = origin_acc.x + radius;
        if (origin_acc.x - radius < x_min2) x_max2 = origin_acc.x - radius;
        if (origin_acc.y + radius > y_max2) y_max2 = origin_acc.y + radius;
        if (origin_acc.y - radius < y_min2) y_min2 = origin_acc.y - radius;
    }

    // Check for low details collisions
    if (((x_max2 <= x_max1 && x_max2 >= x_min1) || (x_min2 <= x_max1 && x_min2 >= x_min1))
        && ((y_max2 <= y_max1 && y_max2 >= y_min1) || (y_min2 <= y_max1 && y_min2 >= y_min1)))
        return true;
    return false;
}

// Uniformize & Compare the input
bool compare_objects(
    // First
    type_t id1, const std::vector<vector2>& vectors1,
    const vector2& pivot1, float rotation1,
    const vector2& acceleration1,
    // Second
    type_t id2, const std::vector<vector2>& vectors2,
    const vector2& pivot2, float rotation2,
    const vector2& acceleration2
)
{
    if (basic_check(id1, vectors1, pivot1, rotation1, acceleration1, id2, vectors2, pivot2, rotation2, acceleration2))
        if (true)
            return true;
    return false;
}

/*
Uniformize the the input into:
(id1, vectors1, pivot1, rotation1, acceleration1
id2, vectors2, pivot2, rotation2, acceleration2)

First: compare with max&min x and y to get a first aproxmative check
Second: if the first is true check with the real border of the object

if the second is true then return true in other case no collisions between the tow given object
*/
