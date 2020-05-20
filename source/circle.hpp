#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle {
  public:
    Circle(Vec2 const& center, float radius, Color const& color);
    float circumference() const;
    void draw(Window const& win) const;
    void draw(Window const& win, float thickness) const;
  private:
    Vec2 center_;
    float radius_;
    Color color_;
};

#endif // CIRCLE_HPP
