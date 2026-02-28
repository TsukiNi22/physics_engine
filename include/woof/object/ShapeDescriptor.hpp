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
##  @file ShapeDescriptor.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef SHAPEDESCRIPTOR_H
    #define SHAPEDESCRIPTOR_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "../Vector.hpp"    // woof::vector2
    #include <vector>           // std::vector

namespace woof { // namespace start
//----------------------------------------------------------------//
/* TYPEDEF */

enum class ShapeId {
    Sprite, // Not handle for now
    Square,
    Rectangle,
    Triangle,
    Circle,
    Polygon,
    None, // Just an empty object
};

/* used to differency the square & the circle for the constructor */
struct SquareTag {};
struct CircleTag {};
inline constexpr SquareTag Square{};
inline constexpr CircleTag Circle{};

//----------------------------------------------------------------//
/* CLASS */

class ShapeDescriptor {
    public:
        /* type */
        woof::ShapeId id = woof::ShapeId::None;

        /* rotation */
        woof::vector2 pivot{0.f, 0.f}; // Not link to any point/origin emplacement
        float angle = 0.f;

        /* dimension & points */
        float width  = 0.f; // used by: Square, Rectangle
        float height = 0.f; // used by: Rectangle
        float radius = 0.f; // used by: Circle

        woof::vector2 origin{0.f, 0.f}; // used by: Square, Rectangle, Triangle, Circle
        woof::vector2 p2{0.f, 0.f}; // used by: Triangle
        woof::vector2 p3{0.f, 0.f}; // used by: Triangle

        std::vector<woof::vector2> points; // used by: Polygon

        // ---------- Pre-Function -------- //
        void clear() noexcept {*this = {};}; // Reset the object descriptor values
        //static ShapeDescriptor sprite(...) noexcept; // Sprite
        static ShapeDescriptor square(woof::vector2 origin, float width,                       woof::vector2 pivot = {0.f, 0.f}, float angle = 0.f) noexcept;
        static ShapeDescriptor rectangle(woof::vector2 origin, float width, float height,      woof::vector2 pivot = {0.f, 0.f}, float angle = 0.f) noexcept;
        static ShapeDescriptor triangle(woof::vector2 p1, woof::vector2 p2, woof::vector2 p3,  woof::vector2 pivot = {0.f, 0.f}, float angle = 0.f) noexcept;
        static ShapeDescriptor circle(woof::vector2 origin, float radius,                      woof::vector2 pivot = {0.f, 0.f}, float angle = 0.f) noexcept;
        static ShapeDescriptor polygon(std::vector<woof::vector2> points,                      woof::vector2 pivot = {0.f, 0.f}, float angle = 0.f);

        // ------------ Operator ---------- //
        ShapeDescriptor& operator=(const ShapeDescriptor& object) = default;
        ShapeDescriptor& operator=(ShapeDescriptor&& object) = default;

        // ---------- Constructor --------- //
        ShapeDescriptor() = default;
        ShapeDescriptor(const ShapeDescriptor& object) = default;
        ShapeDescriptor(ShapeDescriptor&& object) = default;
        //ShapeDescriptor(...) noexcept; // Sprite
        ShapeDescriptor(SquareTag, woof::vector2 origin, float width,           woof::vector2 pivot = {0.f, 0.f}, float angle = 0.f) noexcept; // Square
        ShapeDescriptor(woof::vector2 origin, float width, float height,        woof::vector2 pivot = {0.f, 0.f}, float angle = 0.f) noexcept; // Rectangle
        ShapeDescriptor(woof::vector2 p1, woof::vector2 p2, woof::vector2 p3,   woof::vector2 pivot = {0.f, 0.f}, float angle = 0.f) noexcept; // Triangle
        ShapeDescriptor(CircleTag, woof::vector2 origin, float radius,          woof::vector2 pivot = {0.f, 0.f}, float angle = 0.f) noexcept; // Circle
        ShapeDescriptor(std::vector<woof::vector2> points,                      woof::vector2 pivot = {0.f, 0.f}, float angle = 0.f); // Polygon

        // ----------- Destructor --------- //
        ~ShapeDescriptor() = default;
};

/* independant shape descriptor setter */
//woof::ShapeDescriptor& setSprite(woof::ShapeDescriptor&, ...) noexcept;
woof::ShapeDescriptor& setSquare(woof::ShapeDescriptor& sd, woof::vector2 origin, float width,                        woof::vector2 pivot = {0.f, 0.f}, float angle = 0.f) noexcept;
woof::ShapeDescriptor& setRectangle(woof::ShapeDescriptor& sd, woof::vector2 origin, float width, float height,       woof::vector2 pivot = {0.f, 0.f}, float angle = 0.f) noexcept;
woof::ShapeDescriptor& setTriangle(woof::ShapeDescriptor& sd, woof::vector2 p1, woof::vector2 p2, woof::vector2 p3,   woof::vector2 pivot = {0.f, 0.f}, float angle = 0.f) noexcept;
woof::ShapeDescriptor& setCircle(woof::ShapeDescriptor& sd, woof::vector2 origin, float radius,                       woof::vector2 pivot = {0.f, 0.f}, float angle = 0.f) noexcept;
woof::ShapeDescriptor& setPolygon(woof::ShapeDescriptor& sd, std::vector<woof::vector2> points,                       woof::vector2 pivot = {0.f, 0.f}, float angle = 0.f);

} // namespace end
#endif /* SHAPEDESCRIPTOR_H */
