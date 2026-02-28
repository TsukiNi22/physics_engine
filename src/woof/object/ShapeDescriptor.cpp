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
##  @file ShapeDescriptor.cpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#include "woof/object/ShapeDescriptor.hpp"
#include <vector>

woof::ShapeDescriptor::ShapeDescriptor(SquareTag, woof::vector2 origin, float width, woof::vector2 pivot, float angle) noexcept
: id{woof::ShapeId::Square},
    pivot{pivot}, angle{angle},
    width{width},
    origin{origin}
{}

woof::ShapeDescriptor::ShapeDescriptor(woof::vector2 origin, float width, float height, woof::vector2 pivot, float angle) noexcept
: id{woof::ShapeId::Rectangle},
    pivot{pivot}, angle{angle},
    width{width}, height{height},
    origin{origin}
{}

woof::ShapeDescriptor::ShapeDescriptor(woof::vector2 p1, woof::vector2 p2, woof::vector2 p3, woof::vector2 pivot, float angle) noexcept
: id{woof::ShapeId::Triangle},
    pivot{pivot}, angle{angle},
    origin{p1}, p2{p2}, p3{p3}
{}

woof::ShapeDescriptor::ShapeDescriptor(CircleTag, woof::vector2 origin, float radius, woof::vector2 pivot, float angle) noexcept
: id{woof::ShapeId::Circle},
    pivot{pivot}, angle{angle},
    radius{radius},
    origin{origin}
{}

woof::ShapeDescriptor::ShapeDescriptor(std::vector<woof::vector2> points, woof::vector2 pivot, float angle)
: id{woof::ShapeId::Polygon},
    pivot{pivot}, angle{angle},
    points{std::move(points)}
{}

woof::ShapeDescriptor woof::ShapeDescriptor::square(woof::vector2 origin, float width, woof::vector2 pivot, float angle) noexcept
{
    woof::ShapeDescriptor sd(woof::Square, origin, width, pivot, angle);
    return sd;
}

woof::ShapeDescriptor woof::ShapeDescriptor::rectangle(woof::vector2 origin, float width, float height, woof::vector2 pivot, float angle) noexcept
{
    woof::ShapeDescriptor sd(origin, width, height, pivot, angle);
    return sd;
}

woof::ShapeDescriptor woof::ShapeDescriptor::triangle(woof::vector2 p1, woof::vector2 p2, woof::vector2 p3, woof::vector2 pivot, float angle) noexcept
{
    woof::ShapeDescriptor sd(p1, p2, p3, pivot, angle);
    return sd;
}

woof::ShapeDescriptor woof::ShapeDescriptor::circle(woof::vector2 origin, float radius, woof::vector2 pivot, float angle) noexcept
{
    woof::ShapeDescriptor sd(woof::Circle, origin, radius, pivot, angle);
    return sd;
}

woof::ShapeDescriptor woof::ShapeDescriptor::polygon(std::vector<woof::vector2> points, woof::vector2 pivot, float angle)
{
    woof::ShapeDescriptor sd(points, pivot, angle);
    return sd;
}

woof::ShapeDescriptor& setSquare(woof::ShapeDescriptor& sd, woof::vector2 origin, float width, woof::vector2 pivot, float angle) noexcept
{
    sd.clear();
    sd.id = woof::ShapeId::Square;
    sd.origin = origin;
    sd.width = width;
    sd.pivot = pivot;
    sd.angle = angle;
    return sd;
}

woof::ShapeDescriptor& setRectangle(woof::ShapeDescriptor& sd, woof::vector2 origin, float width, float height, woof::vector2 pivot, float angle) noexcept
{
    sd.clear();
    sd.id = woof::ShapeId::Rectangle;
    sd.origin = origin;
    sd.width = width;
    sd.height = height;
    sd.pivot = pivot;
    sd.angle = angle;
    return sd;
}

woof::ShapeDescriptor& setTriangle(woof::ShapeDescriptor& sd, woof::vector2 p1, woof::vector2 p2, woof::vector2 p3, woof::vector2 pivot, float angle) noexcept
{
    sd.clear();
    sd.id = woof::ShapeId::Triangle;
    sd.origin = p1;
    sd.p2 = p2;
    sd.p3 = p3;
    sd.pivot = pivot;
    sd.angle = angle;
    return sd;
}

woof::ShapeDescriptor& setCircle(woof::ShapeDescriptor& sd, woof::vector2 origin, float radius, woof::vector2 pivot, float angle) noexcept
{
    sd.clear();
    sd.id = woof::ShapeId::Circle;
    sd.origin = origin;
    sd.radius = radius;
    sd.pivot = pivot;
    sd.angle = angle;
    return sd;
}

woof::ShapeDescriptor& setPolygon(woof::ShapeDescriptor& sd, std::vector<woof::vector2> points, woof::vector2 pivot, float angle)
{
    sd.clear();
    sd.id = woof::ShapeId::Polygon;
    sd.points = std::move(points);
    sd.pivot = pivot;
    sd.angle = angle;
    return sd;
}
