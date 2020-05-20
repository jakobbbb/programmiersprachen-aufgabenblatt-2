#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rectangle {
  public:
    Rectangle(Vec2 const& min, Vec2 const& max, Color const& color);
    float circumference() const;
    void draw(Window const& win) const;
  private:
    Vec2 min_;
    Vec2 max_;
    Color color_;
};

#endif // RECTANGLE_HPP
