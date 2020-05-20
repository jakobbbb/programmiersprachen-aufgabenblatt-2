#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"

class Circle {
  public:
    Circle(Vec2 const& center, float radius);
  private:
    Vec2 center_;
    float radius_;
};

#endif // CIRCLE_HPP
