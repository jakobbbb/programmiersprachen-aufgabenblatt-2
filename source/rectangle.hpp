#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "vec2.hpp"

class Rectangle {
  public:
    Rectangle(Vec2 const& min, Vec2 const& max);
  private:
    Vec2 min_;
    Vec2 max_;
};

#endif // RECTANGLE_HPP
