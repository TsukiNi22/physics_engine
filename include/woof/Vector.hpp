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
##  @file Vector.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef VECTOR_H
    #define VECTOR_H

namespace woof { // namespace start
//----------------------------------------------------------------//
/* TYPEDEF */

struct vector2 {
    /* data */
    float x = 0.f;
    float y = 0.f;

    // ------------ Operator ---------- //
    vector2 operator-() const {return {-x, -y};};
    vector2 operator*(float f) const {return {x * f, y * f};}
    vector2 operator*(const vector2& v) const {return {x * v.x, y * v.y};}
    vector2 operator/(float f) const {return {x / f, y / f};}
    vector2 operator/(const vector2& v) const {return {x / v.x, y / v.y};}
    vector2 operator+(float f) const {return {x + f, y + f};}
    vector2 operator+(const vector2& v) const {return {x + v.x, y + v.y};}
    vector2& operator+=(const vector2& v) {x += v.x; y += v.y; return *this;}
};

} // namespace end
#endif /* VECTOR_H */
